//fight.cpp
//���ս����ָ��ͺ���
#include "stdafx.h"
#include "Combatd.h"
#include "../server/CmdHandle.h"
#include "../server/Skill.h"
#include "../server/Channel.h"
#include "../std/FightRoom.h"
#include "../std/Money.h"
#include "../server/Room.h"

#define RESULT_DODGE	-1
#define RESULT_PARRY	-2

CCombatd::CCombatd()
{	
	set("ip_limit", 10);
	set("login_limit", 2500);
	set("kick_idle", 1);
	set("no_check_house", 1);
}

unsigned long CCombatd::Skill_Power(CChar * ob, const char * skill, int usage)
{
   int level;
   unsigned long power;

   if( ! ob->Query(CChar::IS_LIVING) ) return 0;

   level = ob->query_skill(skill);
   switch(usage) {
     case SKILL_USAGE_ATTACK:
        level += ob->query_temp("apply/attack");
        break;
     case SKILL_USAGE_DEFENSE:
        level += ob->query_temp("apply/defense");
		//if (ob->is_fighting())
		//		level = level * (100 + ob->query_temp("fight/dodge")) / 100;
        break;
	}

    LONG combat_exp = ob->query("combat_exp");

	if(userp(ob) && combat_exp > 10000)
		combat_exp = 6000 + combat_exp / 2;	//��ҵľ���ֵֻ��1/2����Ч�ġ�		

	if(! level) return combat_exp / 2;

	power = level * level * level / 3;

	if (usage == SKILL_USAGE_ATTACK)
		return (power + combat_exp) / 30 * ob->query_str();
	else
		return (power + combat_exp) / 30 * ob->query_dex();
}

void CCombatd::Announce(CChar * me, char * event)
{
	char msg[255];
	if(strcmp(event, "dead") == 0)
	{
		snprintf(msg, 255, "%s���ˡ�", me->name());
	}
    else if(strcmp(event, "unconcious") == 0)
	{
        snprintf(msg, 255, "%s����һ�����ȣ����ڵ���һ��Ҳ�����ˡ�", me->name());
    }
    else if(strcmp(event, "revive") == 0)
	{
		snprintf(msg, 255, "%s���������۾��������˹�����", me->name());
	}

	MessageVision(me, "chat", msg);
}

void CCombatd::bash_weapon(CChar * me, CChar * victim, CContainer * weapon, LONG damage)
{
	LONG wap, wdp;
	char msg[255];
	CContainer * ob = victim->query_weapon();

	if( weapon && damage == RESULT_PARRY &&	ob && !ob->query("no_duo") ) 
	{
		wap = weapon->weight() / 500
			+ weapon->query("rigidity")
			+ me->query("str");
		wdp = ob->weight() / 500
			+ ob->query("rigidity")
			+ victim->query("str");
		wap = random(wap);
		if( wap > 2 * wdp ) 
		{
			message_vision(snprintf(msg, 255, "$Nֻ��������%s�ѳֲ��������ַɳ���", ob->name()), victim);
			ob->move(victim->environment());
		} 
		else if( wap > wdp ) 
		{
			message_vision(snprintf(msg, 255, "$Nֻ��������%sһ����Щ���֣�", ob->name()), victim);
		} 
		else if( wap > wdp / 2 ) 
		{
			message_vision(snprintf(msg, 255, "ֻ������ž����һ����$N���е�%s�Ѿ���Ϊ���أ�", ob->name()), victim );
			ob->move(victim->environment());
			ob->set_name(snprintf(msg, 255, "�ϵ���%s", ob->name(1)));
			ob->set("value", 0l);
			ob->del("apply");
		}
	}
}

void CCombatd::throw_weapon(CChar * me, CChar * victim, CContainer * weapon, LONG damage)
{
	char msg[255];

	if(weapon) 
	{
		if( weapon->Query_Amount()==1 ) 
		{
			tell_object(me, snprintf(msg, 255, "���%s�����ˣ�", weapon->name(1)) );
		}

		((CItem *)weapon)->add_amount(-1);
	}
}

//ս��֮����
void CCombatd::Do_Attack(CChar * me, CChar * victim, int flag)
{
	CContainer * weapon;
	const char * ptr = 0, * dodge_ptr = 0;
	char msg[512], str[512];
	CMapping * action = 0, * prepare = 0, * victim_action = 0;
	CSkill * skill;
	const char * attack_skill = "unarmed", * attack_type = "unarmed", * dodge_skill = "dodge", * parry_skill = "parry", * force_skill = "force";
	string result("\n");
	double dp, ap, pp = 0;
	LONG mod_val, damage = 0, damage_bonus = 0;
	CVector v;
	int add_exp_me = 0, add_exp_victim = 0;
	int damage_ratio = 0, force_ratio = 0, dodge_ratio = 0, parry_ratio = 0;
	
	prepare = me->query_skill_prepare();
	prepare->keys(v);
		
	//1, ѡ�����ֶ��������������ļ��ܡ�
	if((weapon = me->query_weapon()))
		attack_type = weapon->querystr("skill_type");
	else if ( v.count() == 0)	attack_type = "unarmed";
	else if ( v.count() == 1)	attack_type = v[0];
	else if ( v.count() == 2)	attack_type = v[me->query_temp("action_flag")];

	if( ! (attack_skill = me->query_skill_mapped(attack_type))[0] )
		attack_skill = attack_type;
	
	skill = load_skill(attack_skill);
	
	if(attack_skill == "unarmed")	//���ּ�����ѯ�����ﱾ����
	{
		action = me->query_action();
	}
	else if(! (action =  skill->query_action(me)) ) 
	{
//		output_error("����%s��Actions��", skill->name(1));
		//�����ҽ��Ѿ���ϵļ���ɾ������������ϵļ��ܶ���ȫ��ȡ��
		//�ز� 2004��10��9
		prepare->clear();
		return;
	}
   	
	damage_ratio = action->query("damage");
	parry_ratio = action->query("parry");
	dodge_ratio = action->query("dodge");
	force_ratio = action->query("force");

	//attack_skill ��������ص��ڹ���ϣ����ܷ����������
	if( ! skill->valid_force(me->query_skill_mapped("force")) )
	{
		damage_ratio /= 2;
		force_ratio = 0;
	}

	if (me->query_temp("action_flag"))
		result += "������";

	result += action->querystr("action");
	result += "\n";

	//2, ��������
	ap = Skill_Power(me, attack_type, SKILL_USAGE_ATTACK);
	if( ap < 1) ap = 1;
	
	//if (userp(me)) && action->query("dodge"))
	//	me->set_temp("fight/dodge", action->query("dodge"));

	dp = Skill_Power(victim, "dodge", SKILL_USAGE_DEFENSE);
	
	mod_val = 0;

	if(living(victim))
	{
		dodge_skill = victim->query_skill_mapped("dodge");
	}

	if(dodge_skill && dodge_skill[0])
	{
		skill = load_skill(dodge_skill);
		dodge_ptr = skill->query_dodge_msg(victim);
		
		if( ! dodge_ptr || ! dodge_ptr[0])
		{
			victim_action = skill->query_action(victim);
			if(victim_action )
			{
				mod_val = victim_action->query("dodge");
				dodge_ptr = victim_action->querystr("action");
			}
		}
	}
			
   if( victim->is_busy() ) dp /= 3;
   
   if( dodge_ratio )  mod_val += dodge_ratio;

   if( dp > 1000000 )
       dp = dp / 100 * (100 + mod_val);
   else 
       dp = (100 + mod_val) * dp / 100;

   if( dp < 1 ) dp = 1;
      
	//�������� AP/(AP+DP) �Ļ�����жԷ���
    if(urandom(ap + dp) < dp)
	{
		if(dodge_ptr && dodge_ptr[0])
			result += dodge_ptr;
		else
			result += "�����$n���˹�ȥ��";
	
		//����ܷ�����ֵ��
		if( dp < ap && (! me->Query(CChar::IS_USER) || ! victim->Query(CChar::IS_USER) )
			&& random(50) < victim->query_int() )
		{
			add_exp_victim = 1 + random(me->learn_bonus() / 20 + 1);

			victim->add("combat_exp", add_exp_victim);
			victim->improve_skill("dodge", 1);			
		}

		if( ap <= dp &&  !userp(me) ) 
		{
			//�����������npc�����ʱnpc��ս�������һ���������ʹ�õļ���
			add_exp_me = 1 + random(me->query("level") / 5 + 1);
			if( random(me->query_int()) > 15 ) 
				me->add("combat_exp", add_exp_me);
			me->improve_skill(attack_type, random(me->query("int")));
		}

		damage = RESULT_DODGE;
	}
	else	//3, �Ƿ��мܹ�ȥ
	{
		if( victim->query_weapon() )	//�ֵ���������
		{
			pp = Skill_Power(victim, "parry", SKILL_USAGE_DEFENSE);
			if( !weapon ) pp *= 2;
			
			parry_skill = victim->query_skill_mapped("parry");
		} 
		else 
		{
			if( weapon ) pp = 0;
			else pp = Skill_Power(victim, "unarmed", SKILL_USAGE_DEFENSE);

			parry_skill = victim->query_skill_mapped("unarmed");
		}

		if( ! parry_skill[0] ) parry_skill = "parry";

		if( victim->is_busy() ) pp /= 3;
		if( pp < 1 ) pp = 1;
		        
		mod_val = parry_ratio;

		if( pp > 1000000 )
			pp = pp / 100 * (100 + mod_val);
		else
			pp = (100 + mod_val) * pp / 100;

		if(pp < 1)  pp = 1;
		
		if( urandom(ap + pp) < pp)
		{
			ptr = load_skill(parry_skill)->query_parry_msg(weapon);
			if(ptr && ptr[0])
				result += ptr;
			else
				result += "�����$n���ˡ�";

			//����ܷ�����ֵ��
			if( pp < ap && (! me->Query(CChar::IS_USER) || ! victim->Query(CChar::IS_USER) )
				&& random(50) < victim->query_int() )
			{				
				add_exp_victim = 1 + random(me->learn_bonus() / 20 + 1);

				victim->add("combat_exp", add_exp_victim);
				victim->improve_skill("parry", 1);
			}

			damage = RESULT_PARRY;

		}else		//4, ���жԷ��������˺�
		{
			//damage = me->query_temp("apply/damage") + me->query_skill(attack_type) / 4;
			int damage_temp=me->query_temp("apply/damage");
			if(damage_temp<0)
				damage_temp=0;
			damage = damage_temp + me->query_skill(attack_type) / 4;
			if(damage) damage = (damage + random(damage)) / 2;

			damage = damage * (100 + damage_ratio) / 100;

			//�õȼ���DAMAGE��Ŵ�����
			damage = damage * (100 + me->query("level")) / 100;
					
			damage_bonus = me->query_str();

			// Let force skill take effect.
			if( me->query("mp_factor") && (me->query("mp") >= me->query("mp_factor")) ) 
			{
				force_skill = me->query_skill_mapped("force");
				if(force_skill[0])
				{
					ptr = load_skill(force_skill)->hit_ob(me, victim, damage_bonus);
					if(ptr && ptr[0])	//�ٴ��ж� lanwood 2001-01-03
					{
						result += ptr;
						result += "\n";
					}
				}
			}

			damage_bonus = damage_bonus * (100 + force_ratio) / 100;

			//�õȼ���DAMAGE_BONUS��Ŵ�����
			//damage_bonus = damage_bonus * (100 + me->query("level") * query("level_force")) / 100;

			ptr = load_skill(attack_skill)->hit_ob(me, victim, damage_bonus);
			if(ptr && ptr[0])	//�жϿ�ָ�뷵�أ�lanwood 2000-01-03
			{
				result += ptr;
				result += "\n";
			}

			// Let weapon or monster have their special damage.
			if( weapon ) 
			{
				ptr = weapon->hit_ob(me, victim, damage_bonus);
				if(ptr && ptr[0]) //�жϿ�ָ�뷵�أ�lanwood 2000-01-03
				{
					result += ptr;
					result += "\n";
				}				
			} 
			else 
			{
				ptr = me->hit_ob(me, victim, damage_bonus);
				if(ptr && ptr[0]) //�жϿ�ָ�뷵�أ�lanwood 2000-01-03
				{
					result += ptr;
					result += "\n";
				}
			}

			if( damage_bonus > 0 )
				damage = damage + (damage_bonus + random(damage_bonus)) / 2;

			if( damage <= 0 ) damage = 0;
						
	        // Let combat exp take effect
			int defense_factor = CChar::Level2Exp(victim->query("level")) + 1;
			int my_exp = CChar::Level2Exp(me->query("level"));

			while( RANDOM(defense_factor, "combatd") > my_exp) 
			{
				damage -= damage / 3;
				defense_factor /= 2;

				if(defense_factor <= 0) 
					defense_factor = 1;
			}
			
			damage = victim->receive_damage("hp", damage, me );
			
			//�������
			if( damage && RANDOM(damage, "combatd") > victim->query_temp("apply/armor") 
				&& ( ( me->is_killing(victim) )
				&& ( (!weapon) && !random(4) || weapon && !random(2) )
				|| ( (!weapon) && !random(7) || weapon && !random(4) ) )  )
			{
				victim->receive_wound("hp", damage - victim->query_temp("apply/armor"), me);
			}

			result += "��������$d����˺���";

			//������
			if( ! me->Query(CChar::IS_USER) || ! victim->Query(CChar::IS_USER) ) 
			{
				if(ap < dp && random(100 + me->query_int()) > 30) 
				{
					add_exp_me = 1 + random(2 + me->learn_bonus() / 15);

					me->add("combat_exp", add_exp_me);
			//		me->add("potential", 1);

					me->improve_skill(attack_type, 1);
          		}
			
				if( RANDOM( victim->query("max_hp") + victim->query("hp"), "combatd" ) < damage )
				{
					add_exp_victim = 1;
					victim->add("combat_exp", add_exp_victim);
//					victim->add("potential", 1);
				}
			}
		} 
	}

	strncpy(str, result.c_str(), 512);
	
	replace_string(str, "$l", "����", 512);
	if(weapon) replace_string(str, "$w", weapon->name(), 512);

	CContainer * weapon2;
	if( (weapon2 = victim->query_weapon()) )
		replace_string(str, "$W", weapon2->name(), 512);

	char vs[10];
	snprintf(vs, 10, "%ld", damage);
	replace_string(str, "$d", vs, 255);
	replace_string(str, "$N", me->name(), 255);
	replace_string(str, "$n", victim->name(), 255);
	replace_string(str, "$P", gender_pronoun(me->querystr("gender")), 255);
	replace_string(str, "$p", gender_pronoun(victim->querystr("gender")), 255);

	//message_vision(str, me, victim);

	//actionӦ������ͨ�����Ķ�����ţ��ɿͻ��˸�����͡�������ʱΪ����������ֱ�ӷ����ͻ��ˡ�
	//����victim�Ļ���%
	int max_hp = victim->query("max_hp");
	int hp = 0;
	if(max_hp > 0)
		hp = victim->query("hp") * 100 / max_hp;
	
	if(flag == TYPE_REGULAR)
	{		
		snprintf(msg, 512, "&C=%d&A=%ld&V=%ld&S=%d&m=%d&D=%ld&ap=%d&T=%s&M=%s&", COMMON_ATTACK, me->object_id(), victim->object_id(), 
			hp,
			me->query("mp"),
			damage,
			me->query_temp("fight/ap"),
			attack_type,
			str);	

		CContainer * env = me->environment();
		MAP2USER ulist;
		iterator_user pos;
		env->GetUsers("combat", &ulist);

		int havesend = 0;
		for(pos = ulist.begin(); pos != ulist.end(); pos++)
		{
			CUser * obj = pos->second;
			obj->SendCommand(msg, 2);
			if(obj == victim)
				havesend = 1;
		}

		if(! havesend)	//���ܺ��ߴ����Լ����˺���Ϣ
		{
			victim->SendState(victim);
		}
		
		//��Ϣ���͸�����
		const char * ch = env->querystr("channel_cast");	//�����ڵ�Ƶ��ת��
		if(ch[0])
		{
			g_Channel.do_channel(env, NULL, ch, str);
		}
	}
	else	//���������У�����ֻ������������	
		message_channel("combat", str, me);

	if(add_exp_me)
		tell_object(me, snprintf(msg, 512, "(exp + %ld)", add_exp_me));
	if(add_exp_victim)
		tell_object(victim, snprintf(msg, 512, "(exp + %ld)", add_exp_victim));

	//snprintf(msg, 255, "#STATUS %ld", me->object_id());
	//MessageVision(me, "execute", msg);		//��ս��״̬��Ϣ��

	
	if( wizardp(me) && EQUALSTR(me->querystr("env/combat"), "verbose" ) )
	{
		if( damage > 0 )
		{
			snprintf(msg, 255, "AP��%ld��DP��%ld��PP��%ld��Mod��%ld���˺�����%ld",
				ap, dp, pp, mod_val, damage);
		}
		else
		{
			snprintf(msg, 255, "AP��%ld��DP��%ld��PP��%ld��Mod��%ld",
				ap, dp, pp, mod_val);
		}

		MessageVision(me, "tell", msg);
   }

   if( wizardp(victim) && EQUALSTR(victim->querystr("env/combat"), "verbose" ))
   {
		if( damage > 0 )
		{
			snprintf(msg, 255, "AP��%ld��DP��%ld��PP��%ld��Mod��%ld���˺�����%ld",
				ap, dp, pp, mod_val, damage);
		}
		else
		{
			snprintf(msg, 255, "AP��%ld��DP��%ld��PP��%ld��Mod��%ld",
				ap, dp, pp, mod_val);
		}

		MessageVision(victim, "tell", msg);
   }


   if(EQUALSTR(attack_type, "hammer") || EQUALSTR(attack_type, "club")
	   || EQUALSTR(attack_type, "staff"))
		bash_weapon(me, victim, weapon, damage);

   if(EQUALSTR(attack_type, "throwing"))
	   throw_weapon(me, victim, weapon, damage);

	// See if the victim can make a riposte.
	//�жϱ��������Ƿ��ܷ���
   /*
	if( flag == TYPE_REGULAR
		&&	damage < 1
		&&	victim->query_temp("guarding") )
	{
		victim->set_temp("guarding", 0);
		if( random(me->query("dex")) < 5 )
		{
			message_vision("\n$Nһ�����У�¶����������\n", me);
			Do_Attack(victim, me, TYPE_QUICK);
		} else 
		{
			message_vision("\n$N��$n����ʧ�󣬳û�����������\n", victim, me);
			Do_Attack(victim, me, TYPE_RIPOSTE);
		}
	}
	*/
}

int CCombatd::Victim_Lose(CChar * killer, CChar * victim) 
{
	LONG lose, exp_k, exp_v;

	if( ( wizardp(victim) && ! wizardp(killer) )
           || (! wizardp(victim) && wizardp(killer)) )
		return 0;

	//�ÿ�
	if( ( killer->query("guest") && ! victim->query("guest") )
			|| (! killer->query("guest") && victim->query("guest")) )
		return 0;

	//PK�����ڼ䣬������������
	//�ز� 2003��5��19
	CContainer * env = load_room("pk");
	if(env->query("PK����"))
		return 0;

    exp_k = killer->query("combat_exp");
    exp_v = victim->query("combat_exp");

	LONG valid_lose = exp_v - victim->query("sk_exp");

    if (exp_k > exp_v) 
	{
		//lose = 10 * exp_v / (exp_k + 1) * (4000 + exp_v) / 500;
		//�������齵������
		lose = 10 * exp_v / (exp_k + 1) * (4000 + exp_v) / 1500;
    } 
	else
	{
		//lose = (4000 + exp_v) / 50;  // about 2% lose for victim.
		//�������齵������
		lose = (4000 + exp_v) / 150;  
    }

	if(lose > valid_lose) lose = valid_lose;
    if(lose < 0) lose = 0;
    
    return lose;
}

void CCombatd::Victim_Penalty(CChar * victim)
{
	int combat_exp_loss = (victim->query("combat_exp") - victim->query("sk_exp")) / 40;
	//���������Ϊԭ����1/3
	//int combat_exp_loss = (victim->query("combat_exp") - victim->query("sk_exp")) / 99;

	if(combat_exp_loss < 0) combat_exp_loss = 0;	//��ֹ������ lanwood 2001-02-28

	victim->set("death/mud_age", victim->query("mud_age"));
    victim->set("death/combat_exp_loss", combat_exp_loss);
	
	victim->add("combat_exp", - combat_exp_loss);
	victim->reset_level();

	victim->add("mds", 1);

	output_error("%s���ˣ���ʧ%ld�㾭�顣", victim->name(), combat_exp_loss);

	victim->set("death/skill_loss", 1);
    victim->skill_death_penalty();
	
    //victim->Save();
}

int CCombatd::NK_Gain(CChar * killer, CChar * victim)
{
	LONG eff_dx, reward, nkgain;
	char msg[255];
	CUser * player1;
	CUser * player2;
	CUser * player3;
	//��ֹ�ε���NPC�������˵þ��顣
	if( DIFFERSTR(victim->querystr_temp("last_fainted_from"), killer->querystr("id")) &&
		!killer->querymap_temp("pary")) 
		return 0;

	if(DIFFERSTR(victim->querystr_temp("last_fainted_from"), killer->querystr("id")) && 
		killer->querymap_temp("pary"))
	{
		if(killer->query_temp("pary/number"))
		{
			CUser * pary_client=find_online(victim->querystr_temp("last_fainted_from"));
			if(!pary_client ||
				!killer->query_temp(snprintf(msg, 255,"pary/friend_%s",victim->querystr_temp("last_fainted_from"))))
				return 0;

			if(	pary_client->query_temp("fight/fight_team")!=killer->query_temp("fight/fight_team") ||
				!pary_client->query_temp("fight/is_fighting") || !killer->query_temp("fight/is_fighting") ||
				DIFFERSTR((pary_client->environment())->querystr("name"),(killer->environment())->querystr("name")))
				return 0;
		}
		else if(killer->querystr_temp("pary/master")[0])
		{
			CUser * pary_master=find_online(victim->querystr_temp("last_fainted_from"));
			if(!pary_master ||
				DIFFERSTR(killer->querystr_temp("pary/master"),victim->querystr_temp("last_fainted_from")))
				return 0;

			if(	pary_master->query_temp("fight/fight_team")!=killer->query_temp("fight/fight_team") ||
				!pary_master->query_temp("fight/is_fighting") || !killer->query_temp("fight/is_fighting") ||
				DIFFERSTR((pary_master->environment())->querystr("name"),(killer->environment())->querystr("name")))
				return 0;
		}
	}

	//��NPC������
	if ( killer->query("level") < victim->query("level")) 
			killer->add("repute", - victim->query("repute") / 10);

    eff_dx = victim->query("eff_dx");
    nkgain=victim->query("nkgain");

    //����ɱͬ���ɵ�NPC�þ��顣
    if(killer->querymap("family") 
		&& EQUALSTR(killer->querystr("family/family_name"), victim->querystr("family/family_name")))
         return 0;
  
    eff_dx=victim->query("combat_exp");      
    
    if(!nkgain) 
	{
		LONG effdx = eff_dx;

		if(effdx>667000) 
		   nkgain=300;
		else if(effdx>333000)
		   nkgain=255;
		else if(effdx>100000)
		   nkgain=195;
		else if(effdx>33000)
		   nkgain=150;
		else if(effdx>17000)
		   nkgain=99;
		else if(effdx>5000)
		   nkgain=75;
		else if(effdx>2000)
		   nkgain=50;
		else 
			nkgain = 35;//if(effdx>500)
		   //nkgain=25;
		//else nkgain=effdx / 20;
     }

     LONG dx = killer->query("combat_exp") * 2 / 3;
	 LONG cx = killer->query("combat_exp") ;
	 //������Ҵ������״̬
	 if(killer->query_temp("pary/number"))
	 {
//		 message_vision(snprintf(msg, 255,"%s���ڴ������״̬�������ѻ�þ������",killer->name(1)), killer);
		 CContainer * env1 = killer->environment();
		 DTItemList * list = env1->Get_ItemList();  
		 POSITION p = list->GetHeadPosition(); 
		 while(p) 
		 { 
			 CContainer * obj1 = list->GetNext(p);
			 if(! obj1->is_character()) continue; 
			 CChar * target = (CChar *)obj1;  
			 if(!userp(target))	continue;
			 if(target->query_temp("fight/fight_team")!=killer->query_temp("fight/fight_team")||!target->query_temp("fight/is_fighting"))
				 continue;

//			 message_vision(snprintf(msg, 255,"���ڷ���%s����������",target->name(1)), killer);

			 if(killer->query_temp(snprintf(msg, 255,"pary/friend_%s",target->querystr("id"))))
			 {
//	 			 message_vision(snprintf(msg, 255,"        %s���Ի�þ��顣",target->name(1)), killer);
				 dx+=target->query("combat_exp")*2/3;
				 cx+=target->query("combat_exp");
				 killer->add_temp("pary/battle_count",1);
				 killer->set_temp(snprintf(msg, 255,"pary/battle_count_%d",killer->query_temp("pary/battle_count")),target->querystr("id"));
			 }
		 }
		 if(killer->query_temp("pary/battle_count"))
		 {
			 dx=dx/(1+killer->query_temp("pary/battle_count"));
			 cx=cx/(1+killer->query_temp("pary/battle_count"));
		 }
	 }
	 //
	 if(killer->query("combat_exp")>70000000)
	 {
		 int imv_dx=(killer->query("combat_exp")-70000000)/1000000;
		 eff_dx=eff_dx*(120+random(80+imv_dx))/100;
	 }
	 double times = (double)(eff_dx - dx / 2) / (double)(dx + 1);
	 LONG exp;
	 double bili;
	 int nk_limit;
	 if(times > 2) times = 2;
	 if(times < 0) times = 0;
	 reward = (LONG)(nkgain * times);
	 CContainer * env = load_room("pk");


//	 message_vision(snprintf(msg, 255,"NPCԭʼ���齱����%ld,�ܹ���%d���˿��Ի�÷���,���ƽ���ܾ�����%d��"  ,reward,killer->query_temp("pary/battle_count")+1,cx), killer);

	 //������Ҵ������״̬,��ʼ������Ӷ�Ա�ľ��齱��
	 switch(killer->query_temp("pary/battle_count"))
	 {
	 case 0:
		 return reward; 
	 case 1:
		 reward=reward*12/10; 
//		 message_vision(snprintf(msg, 255,"�ӳɺ��ƽ�����齱����Ϊ%ld��",reward),killer);
		 bili = (double)(killer->query("combat_exp")+1) / (double)(cx + 1);
		 exp= (LONG)(reward*bili);
		 nk_limit = killer->query("level") * 4 + 100;
		 if(exp > nk_limit) exp = nk_limit;
		 //����ӳ�
		 if(env->query("exp")>0)
			 exp=exp*env->query("exp");

		 killer->add("combat_exp",exp);
		 killer->add("kill/nkgain",exp);
		 tell_object(killer, snprintf(msg, 255, "��ɱ��%s���%ld��NK���飡", victim->name(1), exp));

		 player1=find_online(killer->querystr_temp("pary/battle_count_1"));
		 if(player1)
		 {
			 bili = (double)(player1->query("combat_exp")+1) / (double)(cx + 1);
			 exp= (LONG)(reward*bili);
			 nk_limit = player1->query("level") * 4 + 100;
			 if(exp > nk_limit) exp = nk_limit;
			 //����ӳ�
			 if(env->query("exp")>0)
				 exp=exp*env->query("exp");
			 player1->add("combat_exp",exp);
			 player1->add("kill/nkgain",exp);
			 tell_object(player1, snprintf(msg, 255, "��ɱ��%s���%ld��NK���飡", victim->name(1), exp));
		 }
		 killer->delete_temp("pary/battle_count");
		 killer->delete_temp("pary/battle_count_1");
		 return 0;
	 case 2:
		 reward=reward*15/10;
//		 message_vision(snprintf(msg, 255,"�ӳɺ��ƽ�����齱����Ϊ%ld��",reward),killer);
		 bili = (double)(killer->query("combat_exp")+1) / (double)(cx + 1);
		 exp= (LONG)(reward*bili);
		 nk_limit = killer->query("level") * 4 + 100;
		 if(exp > nk_limit) exp = nk_limit;
		 //����ӳ�
		 if(env->query("exp")>0)
			 exp=exp*env->query("exp");

		 killer->add("combat_exp",exp);
		 killer->add("kill/nkgain",exp);
		 tell_object(killer, snprintf(msg, 255, "��ɱ��%s���%ld��NK���飡", victim->name(1), exp));

		 player1=find_online(killer->querystr_temp("pary/battle_count_1"));
		 if(player1)
		 {
			 bili = (double)(player1->query("combat_exp")+1) / (double)(cx + 1);
			 exp= (LONG)(reward*bili);
			 nk_limit = player1->query("level") * 4 + 100;
			 if(exp > nk_limit) exp = nk_limit;
			 //����ӳ�
			 if(env->query("exp")>0)
				 exp=exp*env->query("exp");
			 player1->add("combat_exp",exp);
			 player1->add("kill/nkgain",exp);
			 tell_object(player1, snprintf(msg, 255, "��ɱ��%s���%ld��NK���飡", victim->name(1), exp));
		 }

		 player2=find_online(killer->querystr_temp("pary/battle_count_2"));
		 if(player2)
		 {
			 bili = (double)(player2->query("combat_exp")+1) / (double)(cx + 1);
			 exp= (LONG)(reward*bili);
			 nk_limit = player2->query("level") * 4 + 100;
			 if(exp > nk_limit) exp = nk_limit;
			 //����ӳ�
			 if(env->query("exp")>0)
				 exp=exp*env->query("exp");
			 player2->add("combat_exp",exp);
			 player2->add("kill/nkgain",exp);
			 tell_object(player2, snprintf(msg, 255, "��ɱ��%s���%ld��NK���飡", victim->name(1), exp));
		 }
		 killer->delete_temp("pary/battle_count");
		 killer->delete_temp("pary/battle_count_1");
		 killer->delete_temp("pary/battle_count_2");
		 return 0;
	 case 3:
		 reward=reward*2; 
//		 message_vision(snprintf(msg, 255,"�ӳɺ��ƽ�����齱����Ϊ%ld��",reward),killer);
		 bili = (double)(killer->query("combat_exp")+1) / (double)(cx + 1);
		 exp= (LONG)(reward*bili);
		 nk_limit = killer->query("level") * 4 + 100;
		 if(exp > nk_limit) exp = nk_limit;
		 //����ӳ�
		 if(env->query("exp")>0)
			 exp=exp*env->query("exp");
		 killer->add("combat_exp",exp);
		 killer->add("kill/nkgain",exp);
		 tell_object(killer, snprintf(msg, 255, "��ɱ��%s���%ld��NK���飡", victim->name(1), exp));

		 player1=find_online(killer->querystr_temp("pary/battle_count_1"));
		 if(player1)
		 {
			 bili = (double)(player1->query("combat_exp")+1) / (double)(cx + 1);
			 exp= (LONG)(reward*bili);
			 nk_limit = player1->query("level") * 4 + 100;
			 if(exp > nk_limit) exp = nk_limit;
			 //����ӳ�
			 if(env->query("exp")>0)
				 exp=exp*env->query("exp");
			 player1->add("combat_exp",exp);
			 player1->add("kill/nkgain",exp);
			 tell_object(player1, snprintf(msg, 255, "��ɱ��%s���%ld��NK���飡", victim->name(1), exp));
		 }

		 player2=find_online(killer->querystr_temp("pary/battle_count_2"));
		 if(player2)
		 {
			 bili = (double)(player2->query("combat_exp")+1) / (double)(cx + 1);
			 exp= (LONG)(reward*bili);
			 nk_limit = player2->query("level") * 4 + 100;
			 if(exp > nk_limit) exp = nk_limit;
			 //����ӳ�
			 if(env->query("exp")>0)
				 exp=exp*env->query("exp");
			 player2->add("combat_exp",exp);
			 player2->add("kill/nkgain",exp);
			 tell_object(player2, snprintf(msg, 255, "��ɱ��%s���%ld��NK���飡", victim->name(1), exp));
		 }

		 player3=find_online(killer->querystr_temp("pary/battle_count_3"));
		 if(player3)
		 {
			 bili = (double)(player3->query("combat_exp")+1) / (double)(cx + 1);
			 exp= (LONG)(reward*bili);
			 nk_limit = player3->query("level") * 4 + 100;
			 if(exp > nk_limit) exp = nk_limit;
			 //����ӳ�
			 if(env->query("exp")>0)
				 exp=exp*env->query("exp");
			 player3->add("combat_exp",exp);
			 player3->add("kill/nkgain",exp);
			 tell_object(player3, snprintf(msg, 255, "��ɱ��%s���%ld��NK���飡", victim->name(1), exp));
		 }
		 killer->delete_temp("pary/battle_count");
		 killer->delete_temp("pary/battle_count_1");
		 killer->delete_temp("pary/battle_count_2");
		 killer->delete_temp("pary/battle_count_3");
		 return 0;
	 }
	 //
	 return reward; 
}

//PK�ͷ�
void CCombatd::PK_reward(CChar * killer, CChar * victim)
{
	char msg[255];
	LONG ki, vi;
		
	//��������¼
	time_t t;

	time(&t);

	if(t > killer->query("kill/free"))	
	{
		killer->del("kill/guilt");
	}

	killer->set("kill/free", t + 86400);	//һ������������
	
	//2��PK����������������
	ki = killer->query("kill/guilt");
	vi = killer->query("kill/guilt");

	//1�����VICTIM������<=KILLER��������PK��
	//KILLER��������10�㡣�ڳ�������������50�㣬�����½�(KILLER - VICTIM) * 10��
	//VICTIM��������20�㡣
	const char * city = killer->querystr_temp("pending/PK_city");
	if(vi <= ki)
	{
		if(city[0])	//�ڳ�����PK
			killer->add("kill/guilt", 50);
		else
			killer->add("kill/guilt", 10);		
	}
	else
	{
		if(city[0])	
			killer->add("kill/guilt", 10);
		else
			killer->add("kill/guilt", 5);	
	}

	//���ܺ��߼���
	victim->add("kill/guilt", -20);
		
	if(victim->query("kill/guilt") < 0)
		victim->del("kill/guilt");		

	//��ɱ��������
	killer->add("repute", (vi - ki) * 10);
	tell_object(killer, snprintf(msg, 255, "$HIY��PK���%s�������%ld����������ǰ����%ld��", victim->name(1), (vi - ki) * 10, killer->query("kill/guilt")));

	g_Channel.do_channel(&g_Channel, NULL, "sys", 
		snprintf(msg, 255, "%s��%s����ɱ��%s�����У�%ld��", killer->name(1), city[0] ? city : "Ұ��", victim->name(1), killer->query("kill/guilt")) );

	//g_Channel.do_channel(&g_Channel, NULL, "rumor", 
	//	snprintf(msg, 255, "%s��%s����ɱ��%s��", killer->name(), city.length() ? city : "Ұ��", victim->name()) );
	
	int guilt = killer->query("kill/guilt");
	int crime = 0;
	if(guilt < 250) 
		crime = 0;
	else if(guilt < 400)
		crime = 1;
	else if(guilt < 800)
		crime = 2;
	else if(guilt < 1200)
		crime = 3;
	else if(guilt < 2000)
		crime = 4;
	else if(guilt < 3000)
		crime = 5;
	else 
		crime = 6;

	killer->apply_condition("xunbu_catching", crime);
}

//Ϊme����Ѳ��
void getout_xunbu(CChar * me)
{
	
}

void CCombatd::Killer_Reward(CChar * killer, CChar * victim)
{
	LONG lose, gain;
	char msg[255];
   // ��Killerɱ��victimʱ������killed_enemy��ʽ��
   //killer->killed_enemy(victim);

	if( victim->Query(CChar::IS_USER) )
	{				   
        if(killer->Query(CChar::IS_USER))
		{
			if(load_room("pk")->query("PK����"))
			{
				killer->add_temp("pk����/count",1);
				victim->delete_temp("pk����/count");
				snprintf(msg, 255, "%s(%s)�ڱ���PK�����в���%s(%s)����ܶ��飬%s(%s)�Ѿ�������ʤ%d����", victim->name(1), victim->id(1), killer->name(1), killer->id(1), killer->name(1), killer->id(1),killer->query_temp("pk����/count"));
				g_Channel.do_channel(&g_Channel, 0, "rumor", msg);
			}
			else
			{
				int pk_chang = 0;
				CContainer * env = killer;
				while(env->environment())
					env = env->environment();
				
				if(env->query("PK"))
					pk_chang = 1;
				
				if(! pk_chang)
					killer->add("pks", 1);
				
				int pkreward = 0;
				
				//���ɼ���˳�ɱ������Pker����
				if(victim->querymap("freedom"))
					pkreward++;
				
				const char * corps_id = killer->querystr("corps/id");
				if(corps_id[0])
				{
					CRoom * r = load_room(corps_id);
					
					if(r->LockData(1))
					{
						r->Load();
						
						CMapping * enemy = r->querymap("enemy");
						
						if(enemy)
						{
							LONG times = enemy->query(victim->id(1));
							if(times)
							{
								if(times == 1)
									enemy->del(victim->id(1));
								else
									enemy->set(victim->id(1), times - 1);
								
								r->Save();
								pkreward ++;	//PK�����ӱ���
							}
						}
						
						r->LockData(0);
					}
				}
				
				const char * killerid = killer->querystr("id");
				
				lose = Victim_Lose(killer, victim);
				
				if(pkreward) lose = lose * 2;
				
				gain = lose * 8 / 10;
				if(gain < 0) gain=0;
				victim->delete_temp("last_fainted_from");
				
				//������ɱͬһ����
				if(killerid == victim->querystr("kill/last_killer"))
					gain = victim->query("kill/last_lose") / 2;
				
				//����������pkһ��ID�þ���
				//if(!pkreward && ! query("PK") && ! pk_chang )
				gain = 0;			
				
				//if(lose > 100)
				//	killer->del("kill/last_killer");
				
				if(gain < 0) gain = 0;		//��ֹ������
				
				killer->add("kill/pkgain",gain);
				killer->add("combat_exp", gain);
				
				victim->set("kill/kill_time", current_time);
				victim->set("kill/last_killer", killerid);
				victim->set("kill/last_lose", gain);
				victim->add("kill/pklose",lose);
				
				victim->add("combat_exp", -lose);
				victim->reset_level();
				
				//Ϊ�����ָ�
				victim->set("death/mud_age", victim->query("mud_age"));
				victim->set("death/combat_exp_loss", lose);
				
				victim->set("death/skill_loss", 1);
				victim->skill_death_penalty();
				//victim->set("death/skill_loss", 0l);
				
				victim->add("pds", 1);
				
				snprintf(msg, 255, "%s(%s)��%s(%s)ɱ�ˣ���ʧ%ld�㾭�顣", victim->name(1), victim->id(1), killer->name(1), killer->id(1), lose);
				g_Channel.do_channel(&g_Channel, NULL, "sys", msg);
				output_error(msg);
				
				//����ҵ�����
				/*
				if ( killer->query("level") < victim->query("level")) 
					killer->add("repute", - victim->query("repute") / 50);
				*/
				//PK�ͷ�
				//1������Ƿ�����PK��
				LONG ki, vi;
				int pk = 1;
				
				if(killer->querymap("freedom"))	pk = 0;
				
				if(! (ki = killer->query_temp("pending/PK")) ) 
					pk = 0;
				else
				{
					killer->delete_temp("pending/PK");
					if( ( vi = victim->query_temp("pending/PK")) )	//���˶���PK��ǣ��ж�˭�ȷ���ָ��
					{
						victim->delete_temp("pending/PK");				
						if(vi < ki) pk = 0;		//�ǶԷ��ȳ��ֵģ����˻�ã�
					}			
				}
				
				//2, PK������
				if(!pkreward && pk) 
					PK_reward(killer, victim);
				
				char ti1[20], ti2[20];
				
				if(killer->querymap("family"))
					strncpy(ti1, killer->querystr("family/family_name"), 20);
				else
					strncpy(ti1, "����", 20);
				
				if(victim->querymap("family"))
					strncpy(ti2, victim->querystr("family/family_name"), 20);
				else
					strncpy(ti2, "����", 20);
				
				if(pkreward)
					snprintf(msg, 255, "%s%s��%sɱ�����%s%s���þ���%ld�㡣", 
					ti1, killer->name(), env->name(), ti2, victim->name(), gain);
				else
					snprintf(msg, 255, "%s%s��%sɱ��%s%s���þ���%ld�㡣", 
					ti1, killer->name(), env->name(), ti2, victim->name(), gain);
				
				if(! pk_chang)
					g_Channel.do_channel(&g_Channel, 0, "rumor", msg);			
				else
					tell_room(env, msg);
				//	bls=10;
			}
		}
		else
		{   
            Victim_Penalty(victim);			
			g_Channel.do_channel(&g_Channel, 0, "rumor", snprintf(msg, 255, "%s��%sɱ���ˡ�", victim->name(), killer->name()));
	//	    bls = 10;
        }
	}
	else
	{  //NPC is the victim.
		if( killer->Query(CChar::IS_USER))
		{
            int reward;
			if(killer->querystr_temp("pary/master")[0])
			{
				CUser * pary_master=find_online(killer->querystr_temp("pary/master"));
				if(pary_master && 
					pary_master->query_temp("fight/fight_team")==killer->query_temp("fight/fight_team") &&
					pary_master->query_temp("fight/is_fighting") && killer->query_temp("fight/is_fighting") &&
					EQUALSTR((pary_master->environment())->querystr("name"),(killer->environment())->querystr("name")))
				{
//					tell_object(killer,snprintf(msg, 255,"1_%s",pary_master->name(1)));
					reward=NK_Gain(pary_master, victim);
				}
				else
				{
//					tell_object(killer,"2");
					reward=NK_Gain(killer, victim);
				}
			}
			else
			{
//				tell_object(killer,"3");
				reward=NK_Gain(killer, victim);
			}

			if(reward > 0)
			{
				//���ò�Ʊ��������Ƿ�����
				CContainer * biaozhi = load_room("pk");
				if(biaozhi->query("cp/random") && DIFFERSTR(victim->querystr("start_city"),""))
				{
					if(random(biaozhi->query("cp/random"))==0)
					{
						CContainer * cp=load_item("caipiao");
						biaozhi->add("cp/number",1);
						cp->set("number",biaozhi->query("cp/number"));//���ò�Ʊ����
						cp->set("index",biaozhi->query("cp/index"));//���ò�Ʊ����
						cp->set("long",snprintf(msg, 255,  "�������ݾ۱�ի������һ�Ų�Ʊ�����Ϊ:�� %d �� %d��",
							biaozhi->query("cp/index"),biaozhi->query("cp/number"),biaozhi->query("cp/number")));
						cp->move(killer);
						g_Channel.do_channel(this, NULL, "news", snprintf(msg, 255,"$HIW%s(%s)�����õ� $HIR%d$HIW �ڱ��Ϊ $HIR%d$HIW �Ĳ�Ʊһ�š�"
							,killer->name(),killer->id(),cp->query("index"),cp->query("number")));
						
					}
				}
				
				//����NK����
				int nk_limit = killer->query("level") * 4 + 100;

				if(reward > nk_limit) reward = nk_limit;
				
				//���齱���ӳ�
				CContainer * env = load_room("pk");
				if(env->query("exp")>0)
				{
					reward=reward*env->query("exp");
				}

				killer->add("kill/nkgain",reward);
				killer->add("combat_exp", reward);
				if(biaozhi->query("����")<3)
				{
					if(!random(1000-killer->query("int")*18))
					{
						CContainer * sacred_fruit=load_item("sacred_fruit");
						int max=random(killer->query("con")+30)+5;
						if(max>64)
							max=64;
						sacred_fruit->set("max",max);
						sacred_fruit->move(killer->environment());
						biaozhi->add("����",1);
					}
				}
				
				tell_object(killer, snprintf(msg, 255, "��ɱ��%s���%ld��NK���飡", victim->name(1), reward));
				//���ɳ�Ա����õľ���1%���׸��ػ�ʹ��
				if(killer->querymap("corps"))
				{
					CContainer * env = load_room(killer->querystr("corps/id"));
					switch(env->query("index"))
					{
					case 1:
						env=load_room(snprintf(msg, 255,"g1_���´��_%s",killer->querystr("corps/id")));
						break;
					}
					CNpc * sh = find_npc(env->query_temp("shizhe"));
					if(sh) 
					{
						((CChar *)sh)->add("combat_exp",reward/100);
						tell_object(killer, snprintf(msg, 255, "ͬʱ������%s������%d����ػ����飡", env->querystr("area"), reward/100));
					}
				}
			}

			//����
			if( current_time < killer->query_temp("lu32/overtime")
				&& EQUALSTR(killer->querystr_temp("lu32/name"), victim->querystr("name"))
				&& EQUALSTR(killer->querystr_temp("lu32/id"), victim->querystr("id")))
			{
				tell_object(killer, "��ϲ�㣡���������һ������");
				LONG exp = killer->query_temp("lu32/exp");
				
				killer->delete_temp("lu32/id");
				killer->delete_temp("lu32/name");
				killer->delete_temp("lu32/exp");
				killer->delete_temp("lu32/overtime");
				if(killer->query_temp("lu32/finish")>200)
					killer->delete_temp("lu32/finish");
				
				killer->add("combat_exp", exp);
				tell_object(killer, snprintf(msg, 255, "$HIW�㱻�����ˣ�%ld��ʵս���飡", exp));
				g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%s���ɱ��%s�����񣬻��%ld�㾭�飡", killer->name(1), victim->name(1), exp));
			}
			if( current_time < killer->query("tradepro/quest_time")
				&& killer->query("tradepro/index")==3
				&& EQUALSTR(killer->querystr("tradepro/quest_killnpc_id"), victim->querystr("id")))
			{
				tell_object(killer,snprintf(msg, 255,  "\n$HIW��ϲ�������%sί���������\n",killer->querystr("tradepro/quest_npc_name")));
				killer->set("tradepro/quest_killnpc_ok",1);
			}
			if(killer->query("tradepro/index")==13 && victim->query("combat_exp") >= killer->query("combat_exp")/15
				&& random(2) )
//				&& random(2) && killer->query("tradepro/quest_item_numer")> killer->query("tradepro/cs_item_numer"))
			{
				CContainer * tradepro_item=load_item("tradepro_item");
				tradepro_item->set_name(killer->querystr("tradepro/quest_item_name"),"cai liao");
				tradepro_item->move(killer->environment());
//				killer->add("tradepro/cs_item_numer",1);
			}
			else if(killer->query("tradepro/index")==1 && victim->query("combat_exp") >= killer->query("combat_exp")/15 
				&& !random(300) && !killer->query("tradepro/cs_item"))
			{
				CContainer * tradepro_item=load_item("tradepro_item1");
				tradepro_item->set_name(killer->querystr("tradepro/quest_item_name"),killer->querystr("tradepro/quest_item_id"));
				tradepro_item->move(killer->environment());
				killer->set("tradepro/cs_item",1);
			}
		}
		
		killer->add("mks", 1);	
	//	bls = 1;
   }
}

void CCombatd::fight(CChar * me, CChar * victim)
{
	int prepare_count = (me->query_skill_prepare())->GetCount();

	/*
	static char guard_msg[][80] = {
		{"\n$N��������������Ķ���$n�����$n�����С�",},
        {"\n$Nע����$n���ж�����ͼѰ�һ�����֡�",},
        {"\n$N������$n��һ��һ������ʱ׼���������ơ�",},
        {"\n$N�������ƶ��Ų�����Ҫ�ҳ�$n��������",},
        {"\n$NĿ��ת���ض���$n�Ķ�����Ѱ�ҽ��������ʱ����",},
        {"\n$N�������ƶ����Ų����Ż����֡�",},
	};
	*/

	if( ! me->Query(CChar::IS_LIVING) ) return;

	// If victim is busy or unconcious, always take the chance to make an attack.
//	if( victim->is_busy() || ! victim->Query(CChar::IS_LIVING) ) 
//	{
	//	me->set_temp("guarding", 0);

	//������
	Do_Attack(me, victim, TYPE_REGULAR);

	//��仰����Do_Attack���棬��ֹ�����Ѿ���������ù����
	CContainer * weapon = me->query_weapon();
	//�Ƿ�������
	if( (! weapon && prepare_count > 1)
		||  ( weapon && EQUALSTR(weapon->querystr("skill_type"), "sword")
			&& me->query_skill("pixie_jian", 1) >= 60
			&& !DIFFERSTR(me->query_skill_mapped("sword"), "pixie_jian")) )
	{
	   me->set_temp("action_flag",1);
	   Do_Attack(me, victim, TYPE_QUICK);
	   me->set_temp("action_flag",0l);
	}
	 else if( (! weapon && prepare_count > 1)
		||  ( weapon && EQUALSTR(weapon->querystr("skill_type"), "sword")
			&& me->query_skill("yunv_jian", 1) >= 100
			&& ! DIFFERSTR(me->query_skill_mapped("sword"), "yunv_jian") ))
	{
	   me->set_temp("action_flag",1);
	   Do_Attack(me, victim, TYPE_QUICK);
	   me->set_temp("action_flag",0l);
	}
	 /*
	// Else, see if we are brave enough to make an aggressive action.
	} 
	else if( random( victim->query_dex() * 3 ) > me->query_str()) 
	{ 
	//	me->set_temp("guarding", 0);
		//if( ! victim->is_fighting(me) ) victim->fight_ob(me);  
		Do_Attack(me, victim, TYPE_REGULAR);
		
		if( (! weapon && prepare_count > 1)
			||  ( weapon  && weapon->querystr("skill_type") == "sword"
				&& me->query_skill("pixie-jian", 1) >= 60
				&& me->query_skill_mapped("sword") == "pixie-jian") )
		{
			me->set_temp("action_flag",1);
			Do_Attack(me, victim, TYPE_REGULAR);
			me->set_temp("action_flag",0);
	    }
		else if( (! weapon && prepare_count > 1)
		||  (weapon && weapon->querystr("skill_type") == "sword"
		   && me->query_skill("yunu-jianfa", 1) >= 100
		   && me->query_skill_mapped("sword") == "yunu-jianfa") )
		{
		   me->set_temp("action_flag",1);
		   Do_Attack(me, victim, TYPE_REGULAR);
		   me->set_temp("action_flag",0);
	    }
	// Else, we just start guarding.
	} else if( !me->query_temp("guarding") ) 
	{
		me->set_temp("guarding", 1);
		message_vision( guard_msg[random(6)], me, victim);
		return;
	} else return;
	*/
}

void CCombatd::start_berserk(CContainer * ob, LONG target, LONG param2)
{
	char msg[255];
	CChar * me = (CChar *)ob;
	CChar * obj = (CChar *)(me->environment())->Present(target);
	int shen;

	if( !obj ) return;

	me->set_temp("looking_for_trouble", 0l);

	if(	me->is_fighting(obj)
		||	! me->Query(CChar::IS_LIVING)
		||	(me->environment())->query("no_fight") 	// Are we in a peace room?
		)	return;

	shen = 0 - me->query("repute");
	message_vision("$N��һ������������ɨ�����ڳ���ÿһ���ˡ�", me);

	if( !userp(me) || me->query("mp") > (random(shen) + shen) / 10 ) return;
	//�����npc������������shen��һ������仯��Χ����10��Ҳ����˵shen��Ƚ���������̫����
	//����ѹ��סɱ����
	if( shen > me->query("score") && ! wizardp(obj) ) 
	{
		message_vision(snprintf(msg, 255, "$N����$n�ȵ���%s����ʵ�ںܲ�˳�ۣ�ȥ���ɡ�", query_self_rude(me)), me, obj);
		me->kill_ob(obj);
	} 
	else 
	{
		message_vision(snprintf(msg, 255, "$N����$n�ȵ���ι��%s%s�������˴�ܣ����������ְɣ�", query_rude(obj), query_self_rude(me)), me, obj);
		me->fight_ob(obj);
	}
}

void CCombatd::start_hatred(CContainer * ob, LONG target, LONG param2)
{
	static char catch_hunt_msg[][80] = {
        {"$N��$n������������ۺ죬���̴���������",},
        {"$N����$n��ȣ����ɶ������㣡��",},
        {"$N��$nһ���棬������˵�ʹ���������",},
        {"$Nһ��Ƴ��$n�����ߡ���һ�����˹�����",},
        {"$Nһ����$n�����һ㶣���У����������㣡��",},
        {"$N�ȵ�����$n�����ǵ��ʻ�û���꣬���У���",},
        {"$N�ȵ�����$n�����У���"},};

	CChar * me = (CChar *)ob;
	CChar * obj = (CChar *)(me->environment())->Present(target);
	if( !obj ) return;				// Are we still exist( not becoming a corpse )?

	me->set_temp("looking_for_trouble", 0l);

	if(	me->is_fighting(obj)
		||	! me->Query(CChar::IS_LIVING)							// Are we capable for a fight?
		||	(me->environment())->query("no_fight") 	// Are we in a peace room?
	)	return;

	// We found our hatred! Charge!
	message_vision( catch_hunt_msg[random(7)], me, obj);
	me->kill_ob(obj);
}

void CCombatd::start_vendetta(CContainer * ob, LONG target, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * obj = (CChar *)(me->environment())->Present(target);

	if( !obj ) return;				// Are we still exist( not becoming a corpse )?

	me->set_temp("looking_for_trouble", 0l);

	if(	me->is_fighting(obj)				// Are we busy fighting?
		||	! me->Query(CChar::IS_LIVING)							// Are we capable for a fight?
		||	(me->environment())->query("no_fight") 	// Are we in a peace room?
	)	return;

	// We found our vendetta opponent! Charge!
	me->kill_ob(obj);
}

void CCombatd::start_aggressive(CContainer * ob, LONG target, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * obj = (CChar *)(me->environment())->Present(target);

	if( !obj ) return;				// Are we still exist( not becoming a corpse )?

	me->set_temp("looking_for_trouble", 0l);

	if(	me->is_fighting(obj)				// Are we busy fighting?
		||	! me->Query(CChar::IS_LIVING)							// Are we capable for a fight?
		||	(me->environment())->query("no_fight") 	// Are we in a peace room?
	)	return;

	// We got a nice victim! Kill him/her/it!!!
	me->kill_ob(obj);
}

void CCombatd::auto_fight(CChar * me, CChar * obj, string type)
{
	CALLOUTFUNC pFunc;

	if(type == "berserk") pFunc = start_berserk;
	else if(type == "hatred") pFunc = start_hatred;
	else if(type == "vendetta") pFunc = start_vendetta;
	else pFunc = start_aggressive;

	// Don't let NPC autofight NPC.
	if( !userp(me) && !userp(obj) ) return;

	if( me->query_temp("looking_for_trouble") ) return;
	me->set_temp("looking_for_trouble", 1);

	// This call_out gives victim a chance to slip trough the fierce guys.
	me->call_out( pFunc, 5 + random(5), obj->object_id());
}

const char * CCombatd::eff_status_msg(int ratio)
{
        if( ratio==100 ) return "��������Ѫ��ӯ����û�����ˡ�";
        if( ratio > 95 ) return "�ƺ����˵����ˣ��������������������";
        if( ratio > 90 ) return "�������������˵����ˡ�";
        if( ratio > 80 ) return "���˼����ˣ������ƺ��������¡�";
        if( ratio > 60 ) return "���˲��ᣬ������״������̫�á�";
        if( ratio > 40 ) return "��Ϣ���أ�������ʼɢ�ң��������ܵ�����ʵ���ᡣ";
        if( ratio > 30 ) return "�Ѿ��˺����ۣ���������֧����������ȥ��";
        if( ratio > 20 ) return "�����൱�ص��ˣ�ֻ�»�������Σ�ա�";
        if( ratio > 10 ) return "����֮���Ѿ�����֧�ţ��ۿ���Ҫ���ڵ��ϡ�";
        if( ratio > 5  ) return "���˹��أ��Ѿ�����һϢ�����ڵ�Ϧ�ˡ�";
        return "���˹��أ��Ѿ�������в�����ʱ�����ܶ�����";
}

const char * CCombatd::damage_msg(int damage, string type)
{
        if( damage == 0 ) return "���û������κ��˺���\n";

        if( type == "����")
		{
			if( damage < 10) return "���ֻ������$p���½š�\n";
			else if ( damage < 20) return "���ֻ�����������$p��Ƥ�⡣\n";
			else if ( damage < 40) return "������͡���һ��ն��һ�����ӡ�\n";
			else if ( damage < 80) return "���ֻ�����꡹��һ������ն��$pƤ�����֡�\n";
			else if ( damage < 160) return " ������꡹��һ������ն����$p�Ĺ�ͷ����Ѫֱ����\n";
			else return "���ֻ����$nһ���Һ���$w����$p$lն��һ��Ѫ��ģ���������˿ڣ���\n";
		}
		else if( type == "����")
		{
            if( damage < 10 ) return "���ֻ������ػ���$p��Ƥ�⡣\n";
            else if( damage < 20 ) return "�����$p$l����һ��ϸ����Ѫ�ۡ�\n";
            else if( damage < 40 ) return "������͡���һ������һ���˿ڣ�\n";
            else if( damage < 80 ) return "������͡���һ������һ��Ѫ���ܵ��˿ڣ�\n";
            else if( damage < 160 ) return "������͡���һ������һ���ֳ�������˿ڣ�����$N������Ѫ��\n";
            else return "���ֻ����$nһ���Һ���$w����$p$l����һ������ǵĿ����˿ڣ���\n";
		}
		else if( type == "����")
		{
            if( damage < 10 ) return "���ֻ������ش���$p��Ƥ�⡣\n";
            else if( damage < 20 ) return "�����$p$l�̳�һ�����ڡ�\n";
            else if( damage < 40 ) return "������ۡ���һ��������$n$l����\n";
            else if( damage < 80 ) return "������ۡ���һ���̽�$n��$l��ʹ$p�������������˼�����\n";
            else if( damage < 160 ) return "��������͡���һ����$w����$p$l�̳�һ��Ѫ��ģ����Ѫ������\n";
            else return "���ֻ����$nһ���Һ���$w����$p��$l�Դ���������Ѫ�������أ���\n";
		}
		else if( type == "����")
		{
            if( damage < 10 ) return "���ֻ����������������Ĳ�Ӭ��΢���˵㡣\n";
            else if( damage < 20 ) return "�����$p��$l���һ�����ࡣ\n";
            else if( damage < 40 ) return "���һ�����У�$n��$l��ʱ����һ���ϸߣ�\n";
            else if( damage < 80 ) return "���һ�����У�$n�ƺ���һ����Ȼ���˲�С�Ŀ���\n";
            else if( damage < 120 ) return "������项��һ����$n����������\n";
            else if( damage < 160 ) return "�����һ�¡��项��һ�����$n�����˺ü�������һ��ˤ����\n";
            else if( damage < 240 ) return "������صػ��У�$n���ۡ���һ���³�һ����Ѫ��\n";
            else return "���ֻ�������项��һ�����죬$n��һ�����ݰ���˳�ȥ����\n";
		}
		else if( type == "����")
		{
            if( damage < 10 ) return "���ֻ�ǰ�$n������˰벽����������\n";
            else if( damage < 20 ) return "���$nʹ��һ������$p��$l���һ�����ˡ�\n";
            else if( damage < 40 ) return "���һ�����У���$n���ʹ��������ȥ��\n";
            else if( damage < 80 ) return "���$n�ƺ���һ��������һ����һ��ף���Ȼ���˵����ˣ�\n";
            else if( damage < 120 ) return "���$n��ɫһ�±�òҰף��������������˺ü�����\n";
            else if( damage < 160 ) return "������صػ��У�$n���ۡ���һ���³�һ����Ѫ��\n";
            else if( damage < 240 ) return "������䡹��һ����$nȫ����Ѫ������������Ѫ���������\n";
            else return "���ֻ���������������죬$nһ���ҽУ���̲�����������ȥ����\n";
		}
		else if( type == "��Ѩ")
		{
        	if( damage < 10 ) return "���ֻ�����������$n��$l����û�е㵽Ѩ����\n";
            else if( damage < 20 ) return "���$nʹ��һ������$p��$l���һ�����ࡣ\n";
            else if( damage < 40 ) return "���һ�����У�$w������$n$l�ϵ�Ѩ��,$nֻ��һ����ľ��\n";
            else if( damage < 80 ) return "���$n�ƺ���һ��������һ����һ��ף���ʱ$l��ľ��\n";
            else if( damage < 160 ) return "���$n��ɫһ�±�òҰף�$w����$n$l��Ѩ��,һ����ʹ�鲼����$l��\n";
            else if( damage < 240 ) return "���$nһ�����,$l��Ѩ��������,��ʹֱ���ķΣ�\n";
            else return "���ֻ����$nһ���ҽ�,һ���ʹ�����������α�ȫ��,����ֱͦͦ�ĵ�����ȥ.\n";
		}
		else
		{
			const char * str;
			static char msg[255];

            if( !type.length() ) type = "�˺�";
            if( damage < 10 ) str =  "���ֻ����ǿ���һ����΢";
            else if( damage < 20 ) str = "��������΢��";
            else if( damage < 30 ) str = "������һ��";
            else if( damage < 50 ) str = "������һ������";
            else if( damage < 80 ) str = "��������Ϊ���ص�";
            else if( damage < 120 ) str = "�������൱���ص�";
            else if( damage < 170 ) str = "������ʮ�����ص�";
            else if( damage < 230 ) str = "�����ɼ������ص�";
            else str =  "�����ɷǳ����µ�����";
		   
			return snprintf(msg, 255, "%s%s��\n", str, type.c_str());		   
        }

		return "";
}

//�����ȼ�����
void CCombatd::Reward_Level_Exp(CChar *me, int level)
{
	char msg[255];
	LONG exp = CChar::Level2Exp(level + 1) - CChar::Level2Exp(level);

	me->add("combat_exp", exp);	
	me->add_temp("reward_exp", exp);
	tell_object(me, snprintf(msg, 255, "$YEL�㱻ϵͳ������%ld����%ld�㾭��!", level + 1, exp));
	g_Channel.do_channel(&g_Channel, NULL, "sys", snprintf(msg, 255, "%s��ϵͳ������%ld�㾭�飡", me->name(1), exp));
}

//�����ȼ�Ǯ
void CCombatd::Reward_Money(CChar *me, LONG money)
{
	char msg[255];
	LONG sum = 10000 * me->query("level") + money;

	CMoney::Pay_Player(me, sum);
	tell_object(me, snprintf(msg, 255, "$HIY�㱻ϵͳ������%ld��ҡ�", sum));
	g_Channel.do_channel(&g_Channel, NULL, "sys", snprintf(msg, 255, "%s��ϵͳ������%ld��ҡ�", me->name(1), sum));
}
