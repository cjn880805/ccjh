
// dagou_bang.h �򹷰�
//code by Fisho
//date : 2000-12-05

SKILL_BEGIN(CSdagou_bang);

virtual void create()
{
	set_name( "�򹷰�");
	set("valid_force", "huntian_qigong");
	
	set("diff",150);
	
	Magic_t * magic;
	
	magic = add_magic("zhuang", do_zhuang);
	magic->name = "ǧ���׹�";
	magic->mp = 500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
	
	magic = add_magic("linglong", do_linglong);
	magic->name = "�������";
	magic->mp = 800;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$Nʹ��һ�С�����˫Ȯ��������$w���������������$n��$l", 50, -20,30 ,1 , "����",},
		{"$N����$w���һζ���һ�С�����Ѱ�ߡ���$n��$l��ȥ", 100, -30, 55, 33, "����",},
		{"$N����$w���Ӹ�����ʹһ�С���ݾ��ߡ�����$n��$l", 180, -40, 80, 66, "����",},
		{"$Nʩ�����������졹��$w����������$n��ȥ", 250, -30, 100, 100, "����",},
		{"$HIY$N�������һ����â������������ʹ���������޹���������ǵذ㹥��$n$COM", 300, -40, 500, 0, "����",},
	};
	
	int level = 0;
	
	if (random(me->query_skill("staff")) > 100 &&
		me->query_skill("force") > 60 &&
		me->query("mp") > 100 &&
		EQUALSTR((me->query_weapon())->querystr("base_name"), "yuzhu_zhang") ) 
	{
		me->add("mp", -100);
		level = 4;
	}
	else
		level = random(4);
	
	m_actions.set("action", action[level].action);
	m_actions.set("force", (me->query("skill_pro/ؤ��/�򹷰�/force")+100) * action[level].force/100);
	m_actions.set("dodge", (me->query("skill_pro/ؤ��/�򹷰�/dodge")+100) * action[level].dodge/100);
	m_actions.set("damage", (me->query("skill_pro/ؤ��/�򹷰�/damage")+100) * action[level].damage/100);
	
	if (me->query_temp("teapot/dagou"))
	{
		int lv = me->query_skill("begging", 1)/2;
		if(lv>200)lv=200+(lv-200)/2;
		int damage1;
		m_actions.set("action", "$HIR$N����$w����һ��ȦȦ������$n$COM");
		m_actions.set("force",  100);
		int dodge=int(me->query("level")/3)+10;
		m_actions.set("dodge",  -dodge);
		if(me->query_temp("dagou/target")==1)
		{
			damage1=500 * (100 + lv) / 200;
			if(me->query("kill/guilt")>=100)
			{
				damage1 = damage1 - me->query("kill/guilt")*10;
				if(damage1<0) damage1=50;
			}
			if(me->query("kill/guilt")< me->query_temp("dagou/target_kill") && me->query_temp("dagou/target_kill")>100)
				damage1 = damage1 +me->query_temp("dagou/target_kill")*5;
			m_actions.set("damage", damage1 );
		}
		else
			m_actions.set("damage",  500 * (100 + lv) / 125 );
	}
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "staff") || (usage == "parry");
}

virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if(!random(10)||wizardp(me))
	{
		int level_point;
		if(victim->query("force")) 
		{
			me->add("skill_pro/ؤ��/�򹷰�/force_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/ؤ��/�򹷰�/force"));
			if(me->query("skill_pro/ؤ��/�򹷰�/force_point")>=level_point)
			{
				me->add("skill_pro/ؤ��/�򹷰�/force",1);
				me->set("skill_pro/ؤ��/�򹷰�/force_point",1);
				tell_object(me,"\n$HIR��Ĵ򹷰�����ڹ������ڻ��ͨ�ˡ�\n");
			}
		}
		else if(victim->query("parry")) 
		{
			me->add("skill_pro/ؤ��/�򹷰�/parry_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/ؤ��/�򹷰�/parry"));
			if(me->query("skill_pro/ؤ��/�򹷰�/parry_point")>=level_point)
			{
				me->add("skill_pro/ؤ��/�򹷰�/parry",1);
				me->set("skill_pro/ؤ��/�򹷰�/parry_point",1);
				tell_object(me,"\n$HIR��������ʹ�ô򹷰�������������һ����ǿ�ˡ�\n");
			}
		}
		else if(victim->query("damage")) 
		{
			me->add("skill_pro/ؤ��/�򹷰�/damage_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/ؤ��/�򹷰�/damage"));
			if(me->query("skill_pro/ؤ��/�򹷰�/damage_point")>=level_point)
			{
				me->add("skill_pro/ؤ��/�򹷰�/damage",1);
				me->set("skill_pro/ؤ��/�򹷰�/damage_point",1);
				tell_object(me,"\n$HIR��Ĵ򹷰����������ˡ�\n");
			}
		}
	}
	char msg[255];
	CContainer * weapon;
	CContainer * weapon1;
	static char xue_name[5][20]={"ǿ��Ѩ","�縮Ѩ","����Ѩ","��̨Ѩ","����Ѩ"};
	
	weapon = me->query_weapon();
	weapon1 = victim->query_weapon();
	int i = me->query_skill("huntian_qigong", 1);
	int j = me->query_skill("dagou_bang", 1);
	int damage1;
	int damage2=damage;
	if( damage < 800 ) return "";
	
	if((random(100)>70 &&
		EQUALSTR(me->querystr("family/family_name"), "ؤ��") &&
		!victim->is_busy() && i > 100 &&
		victim->query("mp") && j > 100 &&
		EQUALSTR(me->query_skill_mapped("parry") , "dagou_bang") &&
		me->query("mp") > 400 && me->query("max_mp") > 1200 )||wizardp(me))
	{
		if (random(40)>13)
		{
			switch(random(4))
			{
			case 0 :
				message_vision(snprintf(msg, 255,
					"\n$GRN$N%s�ӳ����ԡ����־��ŵ�ɨȥ��һ���У������������������̣������������",weapon->name()),me, victim);
				victim->start_busy(3);
				if (!random(2))
				{
					message_vision(snprintf(msg, 255,
						"$HIR$n������������%s��������һ����������һ�����˵ص��ˡ�\n",weapon->name()),me, victim); 
					damage1 = damage2*j/10;
					victim->receive_wound("hp",damage1);
				}
				break;
			case 1 :
				message_vision(snprintf(msg, 255,
					"\n$GRN$Nʹ���������־�������������%s���籩���Ĵ�ȥ��\n",weapon->name()),me, victim);
				damage1 = damage2/10 + random(damage2)/5*j/20;
				victim->receive_damage("hp",damage1/5);
				victim->receive_wound("hp", damage1/5);
				me->add("mp", -50);
				break;
			case 2 :
				message_vision(snprintf(msg, 255,
					"\n$GRN$Nʹ���������־�������%sֱ��ֱ�£��㶫������������$n��Ҫ����ȥ��\n",weapon->name()),me, victim);
				damage1 = damage/5*j/20 + random(damage)/10;
				victim->receive_wound("hp", damage1/2);
				me->add("mp", -damage/5);
				break;
			case 3 :
				message_vision(snprintf(msg, 255,
					"\n$GRN$N�����ٱ䣬ʹ���ˡ�ת���־�������%s������һ�ű�Ӱ���͵�$n���ĸ���ҪѨ��\n",weapon->name()),me, victim);
				if(!random(2))
				{
					victim->start_busy(5);
					me->add("mp",-40);
					victim->receive_wound("hp", me->query_skill("dagou_bang",1)/10+damage/5*j/20);       
					message_vision(snprintf(msg, 255,
						"$HIR$n��%s����$RED%s$HIR�����˵��ˣ�" ,weapon->name(),xue_name[random(5)]),me, victim);
					message_vision(snprintf(msg, 255,
						"$HIR$n��δ��أ���%s����һ��һ��$n���㲻ס������һ��ˤ����\n",weapon->name()),me, victim);   
				}                 
				break;
			}
		} 
		else if (weapon1 && random(35)<7) 
		{
			switch(random(2))
			{
			case 0 :
				if (random(2))
				{ 
					message_vision(snprintf(msg, 255,
						"\n$GRN$N%s����������%s����֮�������������־���˳������ǣ��! \n",weapon->name(),weapon1->name()),me, victim);
				} 
				else 
				{
					message_vision(snprintf(msg, 255,
						"\nGRN$N%s���أ�ʹ�������־�����ס%s����˦������$n��������������%s��! \n",weapon->name(),weapon1->name(),weapon1->name()),me, victim);
				}
				victim->start_busy(j/20);
				if (!random(3))
				{
					message_vision(snprintf(msg, 255,
						"$HIR$nֻ��%s�������ַɳ���һ�����ղ�ס�����б������Է����˹�ȥ��\n",weapon1->name()),me, victim);            
					
					if(weapon1->query("no_duo") || weapon1->querystr("owner")[0])
					{
						char msg1[40];
						victim->command(snprintf(msg1, 40, "unwield %ld", weapon1->object_id()));
					}
					else
					{
						weapon1->move(victim->environment());
					}
				}
				else 
					victim->start_busy(3); 
				break;
			case 1 :
				message_vision(snprintf(msg, 255,
					"\n$GRN$Nʹ���������־�,%s�ӵ�����%s����%s������%s�浽������Ӱ���Σ������ƵС�\n"
					,weapon1->name(),weapon->name(),weapon1->name(),weapon->name()),me, victim);
				damage1 = damage/10 + random(damage)/5*j/20;
				if (victim->query("mp")<=damage) 
				{ 
					victim->set("mp",0l); 
				}
				else 
				{
					victim->add("mp", -damage1); 
				}
				victim->start_busy(3);  
				me->add("mp", -damage1/3); 
				if(me->query("mp")<0)
					me->set("mp",0l);
				break;
			}
		}
	}
	
	return "";
}

virtual int valid_learn(CChar * me)
{
	CChar * who = (CChar *)(me->environment())->present(me->querystr("family/master_id"));
	if(who && who->query("add_skill/count"))
		return notify_fail("���ʦ����ʱû��ָ�����书����");
	
	CChar * who1 = (CChar *)(me->environment())->present(me->querystr("couple/id"));
	if(who1 && who1->query("add_skill/count"))
		return notify_fail("����ʱ�޷�ָ������µ��书����");
	
	if (me->query("max_mp") < 100)
		return notify_fail("�������������");
	
	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;
	if (!(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "staff"))
		return notify_fail("��ʹ�õ��������ԡ�");
	if (me->query("hp") < 50)
		return notify_fail("��������������򹷰�����");
	me->receive_damage("hp", 40);
	return 1;
}

static int do_zhuang(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	char msg[255];
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	if( !target || !me->is_fighting(target) )
		return notify_fail("ǧ���׹��޷�ʹ�á�");
	
	if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "staff"))
		return notify_fail("ǧ���׹��޷�ʹ�á�");
	
	if( me->query("mp") < 400 )
		return notify_fail("�������������");
	
	if(DIFFERSTR(me->querystr("family/family_name"), "ؤ��") && me->querymap_temp("biwu"))
		return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if ( random(me->query_combat_exp()) > target->query_combat_exp()/4 )
	{
		me->set("mp_factor",0l);
		me->set_temp("teapot/dagou",1);
		me->set_temp("dagou/target_kill",target->query("kill/guilt"));
		me->set_temp("dagou/target_hp",target->query("hp"));
		if(target->query("kill/guilt")>100 && userp(target))
		{
			me->set_temp("dagou/target",1);
			snprintf(msg ,255,"$YEL$N��Ȼ��ȵ���$n����������ҽ���Ҫ�����е���\n$YEL$N���һ�������ҵ�ǧ���׹���\n"  );
		}
		else
			snprintf(msg ,255,"$YEL$N���һ�������ҵ�ǧ���׹���\n"  );
		message_vision(msg, me,target);
		if(target->query_temp("apply/no_ǧ���׹�")&& (random(2)||target->query("bigboss")))
			message_vision("$YEL����$n������ã����Ų�æ�������$N������һ����", me,target);
		else
			g_Combatd.Do_Attack(me, target,  CCombatd::TYPE_QUICK);
		me->delete_temp("dagou/target_kill");
		me->delete_temp("dagou/target_hp");
		me->delete_temp("teapot/dagou");
		me->set_temp("dagou/target",2);
		
		//	target->add("level",-n);
		//	target->add("combat_exp",-i);
		me->add("mp", -500);
		me->start_busy(random(3));	
	}
	else
	{
		me->start_busy(2);
		message_vision("$YEL$N���һ�������ҵ�ǧ���׹���\n\n����$n������ã����Ų�æ�������$N������һ����", me,target);
		me->add("mp", -200);
	}
	return 1;
}

static int do_linglong(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	
	int ap,dp,damage;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	if( !target || !me->is_fighting(target) )
		return notify_fail("�����������ֻ����ս����ʹ�á�\n");
	
	if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "staff"))
		return notify_fail("�������ް������ʹ�á������������\n");
	
	if(me->query_int() < 25)
		return notify_fail("�����Բ���,����ʹ�á������������\n");
	
	if(me->query_skill("huntian_qigong", 1) < 150 )
		return notify_fail("��Ļ���������Ϊ������ʹ���������������������\n");
	
	if(DIFFERSTR(me->query_skill_mapped("force") , "huntian_qigong"))
		return notify_fail("û�л���������Ϊ���������޷�ʹ������������������ģ�\n"); 
	
	if(me->query_skill("dagou_bang",1) < 180)
		return notify_fail("��Ĵ򹷰�����Ϊ����,Ŀǰ������ʹ�á������������\n");
	
	if(me->query("max_mp") < 2000)
        return notify_fail("��������Ϊ���ڲ���, �����á������������\n");
	
	if (me->query("mp")<800)
        return notify_fail("�������þ�, �����á������������\n");
	
	if(me->query_temp("gaibang/linglong"))
		return notify_fail("������Բ���,�޷�����ʩչ�������������\n");
	
	if(DIFFERSTR(me->querystr("family/family_name"), "ؤ��") )
		return notify_fail("����Ȼ��˵���������������һ�У�������������ʹ�õľ������ڡ�\n");
	
	message_vision("\n$HIY$N����һЦ�������Ѽ���˫Ŀ�������䣬���������дʡ�\n�������ӻ�����һ�ű�Ӱ���͵�$n���ġ�ǿ�䡱�����縮��������׵��������̨���������ࡱ����ҪѨ��ֻҪ�����˵��У��������ˡ�\n", me, target);  
	
	ap=random(me->query("combat_exp"))+me->query_skill("dagou_bang",1)*(1+random(me->query("int")/2));
	dp=target->query("combat_exp");
	
	if(ap>dp ) 
	{
		damage=me->query_skill("huntian_qigong",1)*(1+random(me->query("str")/5))+me->query_skill("dagou_bang",1)*(1+random(me->query("int")/3));
		if (damage>50000)
			damage=50000+random(3000);
		target->receive_damage("hp",damage);
		target->receive_wound("hp",damage);
		me->add("mp", -800);
		me->start_busy(2);
		message_vision("$CYN$n�������ã����ڲ��������мܣ�ֻ����ǰ��Ծ���ܣ���֪$N�ĵ�����಻�ϣ�һ�㲻�У��ֵ�һѨ����Ӱֻ��$n�����Ѩ�ϻ�����ȥ��\n$nһ��������������!" , me, target);
	}
	else if(ap>dp/2)
	{
		message_vision("$HIG$N�����е�����������ǽ��δ� �����������β����\n��֮��$n���̽����������С�\n",me,target); 
		for (int i=0;i<3;i++)
            g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
		me->add("mp", -800);
		me->start_busy(2);
	}
	else if(ap>dp/4)
	{
		message_vision("$HIG$N����������������ӵ�ʩ���� �����˫ȮĪ��ͷ��, ��֮��Ӱ���Ӷ��£�$n�����������м��¡�\n", me, target);
		target->start_busy(4);
		me->add("mp", -800);
	}
	else
	{
		me->start_busy(random(5));
		me->add("mp", -400);
		message_vision("$n��ʶ��ؤ����񼼡����������������,�ϵл���ԶԶ���˿�ȥ��\n", me, target);
	}
	me->set_temp("gaibang/linglong",1);
	int delay=50-me->query("int");
	if(delay<1)
		delay=1;
	me->call_out(remove_effect, delay);
	return 1;
}

static void remove_effect(CContainer * ob, LONG param1, LONG count)
{
	CChar * me = (CChar *)ob;
	if(me->query_temp("gaibang/linglong"))
		me->delete_temp("gaibang/linglong");
}
SKILL_END;




