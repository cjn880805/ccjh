// qiankun_danuoyi.h Ǭ����Ų��
//code by sound
//date : 2001-7-1

SKILL_BEGIN(CSqiankun_danuoyi);

virtual void create()
{
	set_name( "Ǭ����Ų��");
/*	
	Magic_t * magic;
	
	magic = add_magic("yi", do_yi);
	magic->name = "���־�";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
*/
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "xuantian_shengong") || EQUALSTR(arg, "jiuyang_shengong"))
		return 1;
	
	return notify_fail("Ǭ����Ų�Ʊ���������񹦻����������ʹ�á�");
}

virtual const char * query_parry_msg(CContainer *weapon)
{
	static char parry_msg[][80] = {
		{"$Nһ�л���$n���ϣ�ȴ��$n����Ǭ����Ų�ƣ�����������������¡�"},
		{"$n����һ����$N�����Լ������ػ��������ŵ������˼�����"},
		{"$n�ֱۻ�ת����$N����������һ�ƣ�$N������ա�"},
		{"$n�����������$N����������һ����$N���Ʋ�ס��ֱ��ǰ��ȥ��"},
		{"$n���β�����$Nһ�л��£�����ʯ���󺣣�������ס�ˡ�"},
		{"$n��ǣ������$N��������������ת�˺ü���Ȧ��"},
		{"$n˫�ֻ�Ȧ��$Nֻ����ǰ�������һ��ǽ����Ҳ������ȥ��"},
		{"$n����һת��$Nһ�л��ڵ��ϣ�ֻ��ó������"},
	};
    return parry_msg[random(8)];
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[][80] = {
		{"$Nһ�л���$n���ϣ�ȴ��$n����Ǭ����Ų�ƣ�����������������¡�"},
		{"$n����һ����$N�����Լ������ػ��������ŵ������˼�����"},
		{"$n�ֱۻ�ת����$N����������һ�ƣ�$N������ա�"},
		{"$n�����������$N����������һ����$N���Ʋ�ס��ֱ��ǰ��ȥ��"},
		{"$n���β�����$Nһ�л��£�����ʯ���󺣣�������ס�ˡ�"},
		{"$n��ǣ������$N��������������ת�˺ü���Ȧ��"},
		{"$n˫�ֻ�Ȧ��$Nֻ����ǰ�������һ��ǽ����Ҳ������ȥ��"},
		{"$n����һת��$Nһ�л��ڵ��ϣ�ֻ��ó������"},
	};
	return dodge_msg[random(8)];
}

virtual int valid_enable(string usage) 
{ 
	return (usage == "dodge") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
	int lvl = me->query_skill("qiankun_danuoyi", 1);
	
	if (EQUALSTR(me->querystr("gender"), "����") && lvl > 99)
		return notify_fail("�����첻�㣬��ѧ��ȥ�����߻���ħ��");
	
	if (me->query_skill("force", 1) < 100)
		return notify_fail("����ô������ڹ�����ѧǬ����Ų�ƣ�");
	
	if (lvl > 150)
		return notify_fail("Ǭ����Ų��ֻ��ͨ����<<Ǭ����Ų��>>�ķ���ߡ�");
	
	if (me->query("max_mp") < 1500)
		return notify_fail("����ô����������ѧǬ����Ų�ƣ�");
	
	if (me->query_skill("force", 1) < lvl)
		return notify_fail("��Ļ����ڹ���򻹲�����С���߻���ħ��");
	
	if (me->query_skill("jiuyang_shengong", 1) < lvl && lvl <330 )
		return notify_fail("��ľ����񹦻�򻹲�����С���߻���ħ��");
	
	if ((me->query("max_mp")/15) < lvl)
		return notify_fail("���������򻹲�����С���߻���ħ��");
	
	return 1;
}

void skill_improved(CChar *me)
{
	int skill, lit, med;
	skill = me->query_skill("qiankun_danuoyi", 1);
	lit = me->query_skill("literate", 1);
	med = me->query_skill("medicine", 1);
	
	if(skill == 50 && !me->query("qkdny") && lit > 50)
	{
		tell_object(me, "$HIY�㰴����Ƥ�����飬�������С��ƹ�ʹ�������Ǻ��������ı������ˡ�$COM\n");
		me->add("max_mp", 10+random(30));
		me->add("qkdny", 1);
	}
	if(skill == 80 && me->query("qkdny") == 1 && lit > 80)
	{
		tell_object(me, "$HIM�������ڶ����ķ�������ʩΪ��Ƭ��������ͨ��ֻ��ʮ����ָ֮�У��ƺ���˿˿���������$COM\n");
		me->add("max_mp", 10+random(30));
		me->add("qkdny", 1);
	}
	if(skill == 100 && me->query("qkdny") == 2 && lit > 100)
	{
		tell_object(me, "$CYN�㰴����Ƥ�����飬�߶�����������Ϊ֮����$COM\n");
		me->add("max_mp", 10+random(30));
		me->add("qkdny", 1);
	}
	if(skill == 130 && me->query("qkdny") == 3 && lit > 120)
	{
		message_vision("$RED$N��������͵�Ѫ�죬�������ȴ�����࣬���������㣬˫�۾��⾼���������ް���$COM\n", me);
		me->add("max_mp", 10+random(30));
		me->add("qkdny", 1);
	}
	if(skill == 150 && me->query("qkdny") == 4 && lit > 140)
	{
		message_vision("$HIW$N���Ϻ�����죬������ʱ����΢������麮�������Ϻ�ʱ��ͷ�������¡�$COM\n", me);
		me->add("max_mp", 10+random(30));
		me->add("qkdny", 1);
	}
	if(skill == 170 && me->query("qkdny") == 5 && lit > 160)
	{
		tell_object(me, "$MAG���������Ǳ������ɽ��ͻ������ȻĪ֮������ԭ����Ǭ����Ų���ķ��������㱾�������е�Ǳ����$COM\n");
		me->add("max_mp", 20+random(30));
		me->add("qkdny", 1);
	}
	if(skill == 190 && me->query("qkdny") == 6 && lit > 180)
	{
		tell_object(me, "$MAG���͵�����Ѫ��ӿ�������ӿ죬����������Ǭ����Ų���񹦣�$COM\n");      
		me->add("max_mp", 50+random(30));
		me->add("qkdny", 1);
	}
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("Ǭ����Ų��ֻ��ͨ����<<Ǭ����Ų��>>�ķ���ߡ�");
	
}

/*
char * hit_ob(CChar *ob, CChar *me, LONG & damage)
{
	CContainer * weapon, * weapon2;
	char msg[255];
	string str;
	int p,j,skill, mp, mp1, exp, exp1;
	weapon = me->query_weapon();	
	weapon2 = ob->query_weapon();
	skill = me->query_skill("qiankun_danuoyi", 1);
	mp = me->query("mp");
	mp1 = ob->query("mp");
	exp = me->query("combat_exp");
	exp1 = ob->query("combat_exp");
	
	static char msg_weapon[10][255] = {
		"$YEL$N����һ�ӣ�����б$w$YEL���ƣ����ϵ���ô����һ��֮�����ػ�����������˴�����Ѱ����$COM",
			"$RED��֪$N��$W$RED΢ת��ƽƽ�Ĵ���$w$RED֮�ϣ�һ����͵ľ����ͳ�����$w$REDֱ���˿�ȥ��$COM",
			"$HIY$N����̤������������$W$HIY�ӳ���һ�ɾ�������$n�ĺ��ģ���λʱ�������ǡ���ô���$COM",
			"$HIC$n��������һ�У�ԭ�Ǽ�����������������$N��ָһ����������ббж�˿�ȥ��$COM",
			"$BLU$N��$n��$w$BLU��Ҫ�����Ŀ�ʱ������ͻȻ�߳���ѹ��$w$BLU��һ����˳��̤�䣡$COM",
			"$HIB$N˫��ͬʱʩչŲ��Ǭ���ķ���һ����Х����������ڰ��������һ��ת�ۣ�ƮȻ����$n���ԣ�$COM",
			"$HIW$n�书��ߣ�����$N��������Ϯ�����������$w$HIW��Ҳ���Բ��$N��$W$HIW��ʽ��$COM",
			"$YEL$N������ָ���縧�ٹ�ɪ�������������������������㲻����Ƭ�̼佫$n����������ж�ˣ�$COM",
			"$GRN$N�Ҵ��һ��̩ɽ������������Ȫ��������ȴ��ʹ��Ǭ����Ų�Ƶ��ַ�������$n����$w$GRN��$COM",
			"$CYN$N����$W$CYN������$n$w$CYN���ϣ�����������Ǭ����Ų���ķ���΢һ�˾����㽫$n�ľ��������ƿ��ˣ�$COM",
	};
	
	static char msg_unarmed[14][255] = {
		"$HICһɲ�Ǽ�$N����Ϊ��ļ���ת�ۣ���ʹ����Ǭ����Ų���ķ��ĵ��߲��񹦣�$COM",
			"$HIW$N��Ҳ����������������ǰ��Ǭ����Ų������б������������Ų����ж�˿�ȥ��$COM",
			"$GRN��֪�ո��ഥ��ͻȻһ����Ͷ����صľ�����$N���Ϸ�������ס��$n�ľ�����ͬʱ��$N������ָҲ�Ѱ���$n�ؿ�����Ѩ�����⣡$COM",
			"$RED���$Nʹ��Ǭ����Ų���ķ������Ű��Է�λ��������$n���е�ȥ�ơ�$COM",
			"$CYN$N��ʹǬ����Ų�ƣ�Խ��Խ�죬�����������Ƶ磬���������ǰ������̽��ץ��$n��$COM",
			"$BLU$N��ʱ����������ת��һ����������Ȼ��Ȼ������������֮$n�����������ִ�ö��ˣ�$COM",
			"$BLU$n����һָ����$N��ͷ��ȴ��֪��α�����һ�����۵�һ�죬���������Լ��ֱۣ�ֻʹ����ǰ����ֱð��$COM",
			"$YEL���������Ա���һ��������������$n������һ������$N����бб������$COM",
			"$YEL$N����Ǳ��Ǭ����Ų���ķ���ʹ$n����$N��һ��Ī��������ﻬ��һ�ԡ�$COM",
			"$HIR$N��ʹŲ��Ǭ���ķ���һǣһ�����е�һ�죬��$n��������ƫ��$COM",
			"$YEL$N������ָ���縧�ٹ�ɪ�����������������Σ������㲻������$n���л������Σ�$COM",
			"$WHT$N����Ǭ����Ų���ķ���ʹ$n����Ī�����������;ת�˷��������������Σ�$COM",
			"$CYNǬ����Ų���񹦱�ã��εȰ�����$N��ָ�������ѵ�����$n˫��Ѩ����$COM",
			"$GRN$Nʹ��Ų�ƴ�Ǭ����$n����Ī�����������;ת�˷��򣬴�����������Լ����˻�����$COM",
	};
	
	if(me->query_temp("yi_ob") && living(me))
	{
		CChar * me = (CChar *)ob;
		CChar * target = (CChar *)(me->environment())->Present(me->query_temp("yi_ob"));
		me->delete_temp("yi_ob");
		if(!target)
		{
			tell_object(me, "$HIY�㷢������Ų�Ƶ�Ŀ������Ѿ����������ˡ�$COM\n");
			damage += damage;
			return 0;
//			return damage;
		}
		if(!living(target))
		{
			tell_object(me, "$HIY�㷢������Ų�Ƶ�Ŀ������Ѿ����Բ����ˡ�$COM\n");
			damage += damage;
			return 0;
//			return damage;
		}
		if(mp < 800)
		{
			tell_object(me, "$HIY����ҪŲ�ƣ�ȴ�����Լ������������ˣ�$COM\n");
			damage += damage;
			return 0;
//			return damage;
		}
		message_vision("$WHT$NͻȻ˫�ֻζ�������������������Ҵ�Ҫ��$n���������Ա�����ǣ����$COM\n",me, ob);
		if(exp < exp1/2 || random(mp) < random(mp1))
		{
			me->add("mp", -125);
			message_vision("$HIY���$n��û���ܵ����ţ�����˳������$N�Ĳ��棬����ǿ����һ����$COM\n",me, ob);
			damage += random(damage);
			return 0;
//			return random(damage);
		}
		me->add("mp", -250);
//		tell_room(environment(me), "�������"+ob->name()+"������ֱ��"+target->name()+"�����ȥ��\n",({ target,ob }));
		tell_room(me->environment(), snprintf(msg, 255, "�������%s������ֱ��%s�����ȥ��\n", ob->name(), target->name()));
		tell_object(target, snprintf(msg,255,"$HIR����㷢��%s������ֱ���Լ����������$COM\n", ob->name()));
		tell_object(me, snprintf(msg,255,"$HIR����㷢���Լ�������ֱ��%s�����ȥ��$COM\n", target->name()));
		
		if(target->query_skill("dodge", 1)>=damage)
			snprintf(msg, 255, "%s", "$HIY���$nû���ܵ��κ��˺���$COM\n");
		else
		{
			target->receive_damage("hp", damage-(target->query_skill("dodge", 1)), ob);
			p = target->query("hp")*100/target->query("max_hp");
			snprintf(msg, 255, "%s", g_Combatd.damage_msg(damage/2, "�˺�"));
//			msg += "( $n"+eff_status_msg(p)+" )\n";
		}
		if( target->query("repute") < -1000 && !target->is_killing(ob) )
		{
			if( random(target->query_int()) < 20 )
				target->kill_ob(ob);
			
			else if(random(target->query_int()) > 30)
				target->fight_ob(me);
		}
		if(target->query("repute") > -1000 
			&& !target->is_killing(ob))
		{
			if(random(target->query("int")) < 20)
				target->fight_ob(ob);
			
			else if(random(target->query("int")) > 30)
				target->fight_ob(me);
		}
		message_vision(msg, me, target);
		damage -= 5000;
		return 0;
//		return -5000;
	}
	if(me->query_temp("fanzhen"))
	{
		me->delete_temp("fanzhen");
		damage += 1;
		return 0;
//		return 1;
	}
	if(me->query("mp_factor") 
		&& living(me) 
		&& random(skill)+20 > random(me->query_skill("parry", 1)) 
		&& exp > exp1/2 
		&& skill > 50 
		&& mp > 500 
		&& living(ob)
		&& !ob->query("env/invisibility"))
	{
		CChar * target = (CChar *)(me->environment())->Present(me->query_temp("yi_ob"));
		if(random(2)==1) me->add_temp("fanzhen", 1); 
		me->add("mp", -(random(10)));
		if(weapon && weapon2)
		{
			snprintf(msg, 255, "%s", msg_weapon[random(10)]);
			replace_string(msg, "$W", weapon->name(), 255);
			replace_string(msg, "$w", weapon2->name(), 255);
			str = msg;
			if(mp >= mp1*2+damage)
			{
				if(random(me->query("str")) > ob->query("str")/2 
					&& skill > 150)
				{

					str += snprintf(msg, 255, "$HIW���$nһ���ֵ���ס������$COM%s$HIW���ַɳ���$COM", weapon2->name());
					me->add("mp", -50);
					weapon2->move(ob->environment());
					if (weapon2->query("ownmake")==1)
					{
						weapon2->move(ob);
						str += "�ǿ���$n������һ$n��һ�콫���������" ;
					}
					j = -5000;
				}
				else
				{
					ob->receive_damage("hp", damage/2?damage/2:10, me);
					ob->receive_wound("hp", damage/10 > 0?damage/10:2, me);
					p = ob->query("hp")*100/ob->query("max_hp");
					str += g_Combatd.damage_msg(damage/2, "����");
//					msg += "( $n"+eff_status_msg(p)+" )\n";
					j = -5000;
				}
			}
			else if(mp >= random(mp1)*2+damage)
			{
				str += "���������ж����$n��������\n";  
				j = -5000;
			}
			else
			{
				j = damage/2+random(damage/2);
				if(j<damage/2) str += "���ж����һЩ$n��������\n";
				else str += "���ж����$n����������\n";
				j = -j;
			}   
			message_vision(str.c_str(), me, target);
			damage += j;
			return 0;
//			return j;
		}  
		else
		{
			str = msg_unarmed[random(14)];
			if(mp >= mp1*2+damage)
			{
				if (damage>50)
				{
					ob->receive_damage("hp", damage/2?damage/2:10, me);
					ob->receive_wound("hp", damage/10 > 0?damage/10:2, me);
				}
				p = ob->query("hp")*100/ob->query("max_hp");
				str += g_Combatd.damage_msg(damage, "����");
//				msg += "( $n"+eff_status_msg(p)+" )\n";
				j = -5000;
			}
			else if(mp >= random(mp1)*2+damage)
			{
				str += "���������ж����$n��������\n";  
				j = -5000;
			}
			else
			{
				j = damage/2+random(damage/2); 
				if(j<damage/2) str += "���ж����һЩ$n��������\n";
				else str += "���ж����$nһ���������\n";
				j = -j;
			}   
			message_vision(str.c_str(), me, target);
			damage += j;
			return 0;
//			return j;
		}
	}

	return 0;
}

// yi.c Ǭ����Ų�ơ��ơ��־�
static int do_yi(CChar * me, CContainer * ob)
{	
	CChar * target = NULL;
	char msg[255];
	const char * str;
	
	if( ob && ob->is_character())
		target = (CChar * )ob;
	
	if(!target)
		return notify_fail("����ѶԷ��ľ���Ų����˭��");
	
//	if(!objectp(ob = present(target, environment(me))))
//		return notify_fail("����û������Ų�Ƶ�Ŀ������ˡ�");
	
	if(!me->is_fighting())
		return notify_fail("��û�ڴ�ܣ���ʲô�ƣ�");
	
	
	if(me->query_skill("jiuyang_shengong", 1) < 100)
		return notify_fail("��ľ����񹦻�򻹲�����С���߻���ħ��\n");
	
//	if(!ob->is_character()) 
//		return notify_fail("�����һ�㣬�ǲ��������");
	
//	if(userp(ob)) 
//		return notify_fail("�㲻���Ƶ���ͨ�������ȥ!");
	
	if(!living(target))
		return notify_fail("%�Ѿ��޷�ս���ˡ�", ob->name());
	
//	if(ob==me) return notify_fail("�㲻�ܹ����Լ���");
	
	if( !target	||	!me->is_fighting(target)	
		||	!target->is_fighting(me) )	
		return notify_fail("��û�к�������ء�");
	
	if(me->query_skill("qiankun_danuoyi", 1) < 120 )
		return notify_fail("���Ǭ����Ų�ƻ�������죬����ʹ�á��ơ��־���");
	
	if(me->query_skill_mapped("parry") != "qiankun_danuoyi")
		return notify_fail("��û��ʹ��Ǭ����Ų����Ϊ�н����޷�ʹ�á��ơ��־���"); 
	
	if(me->query("mp") < 800 )
		return notify_fail("�������������");
	
	if(me->query_skill("force") < 200 )
		return notify_fail("���ơ��־���Ҫ�����ڹ�����������������󻹲�����");

	if(DIFFERSTR(me->querystr("family/family_name"), "����") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	me->add("mp", -50);
	tell_object(me, snprintf(msg, 255, "$BLU�㰵��Ǭ����Ų�ơ��ơ��־�����ͼҪ�ѶԷ���һ�е�����ת�Ƶ�%s���ϣ�$COM\n��", ob->name()));
	me->set_temp("yi_ob", ob->query("id"));     
//	msg = me->name()
	str = "$n$HIBһɲ�Ǽ仯��Ϊ��ļ���ת�ۣ���ʹ����Ǭ����Ų���ķ��ĵ��߲��񹦣�$COM\n";
	me->start_busy(1);
	message_vision(str, me, target);
	
	return 1;
}
*/
SKILL_END;
