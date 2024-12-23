//tianyu_qijian.h �����潣

SKILL_BEGIN(CStianyu_qijian);

virtual void create()
{
	set_name( "�����潣");

	set("valid_force", "bahuang_gong");
	
	Magic_t * magic;
	set("diff",150);
	
	magic = add_magic("san", do_san);
	magic->name = "��Ůɢ��";
	magic->mp = 300;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
	
	magic = add_magic("kuangwu", do_kuangwu);
	magic->name = "�������";
	magic->mp = 650;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
	
	magic = add_magic("yushijufen", do_yushijufen);
	magic->name = "��ʯ���";
	magic->mp = 0;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  force, dodge,  damage, lvl;
	}action[9] = {
		{"$Nʹһʽ������һ�ߡ�������$w����΢�񣬻ó�һ���������$n��$l",
			120, 0, 30, 0,},
		{"$N����ǰ��ʹ�������羪�硹������$w����һ����������$n��$l",
		140, 10, 40, 9,},
		{"$N����$wһ����һ�С����ھ��졹��ббһ�������ó�������$n��$l",
		160, 10, 50, 18,},
		{"$N���н����ॳ���һ����һʽ��������ġ���һ���������$n��$l",
		180, 10, 100, 27,},
		{"$Nһʽ��ŭ���񻨡�������$w�������������ʹ$n�Ѷ���ʵ���޿ɶ��",
		220, 15, 100, 36,},
		{"$N����$wбָ���죬��â���£�һʽ���Ż����ա�����׼$n��$lбб����",
		260, 15, 120, 44,},
		{"$Nһʽ�������ѩ�������󼱶�������������⣬����$n��$l",
		320, 15, 125, 52,},
		{"$Nһʽ����ӵ�к����$w��ն�������缲�������$n���ؿ�",
		380, 15, 140, 60,},
		{"$Nһʽ��������ɡ���$wͻȻ���������һƬ���Χ��$nȫ��",
		380, 20, 150, 60,},
	};
	
	int level = me->query_skill("tianyu_qijian", 1);
	for(int i = 9; i > 0; i--)
		if( action[i - 1].lvl < level)
		{
			level = random(i);
			
			m_actions.set("action", action[level].action);
			m_actions.set("force", (me->query("skill_pro/���չ�/�����潣/force")+100) * action[level].force/100);
			m_actions.set("dodge", (me->query("skill_pro/���չ�/�����潣/dodge")+100) * action[level].dodge/100);
			m_actions.set("damage", (me->query("skill_pro/���չ�/�����潣/damage")+100) * action[level].damage/100);
			break;
		}
		
		return & m_actions;
};

virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if(!random(10)||wizardp(me))
	{
		int level_point;
		if(victim->query("force")) 
		{
			me->add("skill_pro/���չ�/�����潣/force_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/���չ�/�����潣/force"));
			if(me->query("skill_pro/���չ�/�����潣/force_point")>=level_point)
			{
				me->add("skill_pro/���չ�/�����潣/force",1);
				me->set("skill_pro/���չ�/�����潣/force_point",1);
				tell_object(me,"\n$HIR��������潣����ڹ������ڻ��ͨ�ˡ�\n");
			}
		}
		else if(victim->query("dodge")) 
		{
			me->add("skill_pro/���չ�/�����潣/dodge_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/���չ�/�����潣/dodge"));
			if(me->query("skill_pro/���չ�/�����潣/dodge_point")>=level_point)
			{
				me->add("skill_pro/���չ�/�����潣/dodge",1);
				me->set("skill_pro/���չ�/�����潣/dodge_point",1);
				tell_object(me,"\n$HIR��������潣ʹ�õø��ӵ���Ӧ���ˡ�\n");
			}
		}
		else if(victim->query("damage")) 
		{
			me->add("skill_pro/���չ�/�����潣/damage_point",1);

			level_point=(query("diff")+80)*(1+me->query("skill_pro/���չ�/�����潣/damage"));
			if(me->query("skill_pro/���չ�/�����潣/damage_point")>=level_point)
			{
				me->add("skill_pro/���չ�/�����潣/damage",1);
				me->set("skill_pro/���չ�/�����潣/damage_point",1);
				tell_object(me,"\n$HIR��������潣���������ˡ�\n");
			}
		}
	}
	return "";
}

virtual int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

virtual int valid_learn(CChar * me)
{
	return 1;
}


virtual int practice_skill(CChar * me)
{
	CContainer * weapon;
	
	if (!(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��ʹ�õ��������ԡ�");
	
	if (me->query("hp") < 50)
		return notify_fail("������������������潣��");
	
	me->receive_damage("hp", 25);
	
    return 1;
}
/*
static int do_san(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	CContainer * weapon;
	string msg;
	
	if( !target || !me->is_fighting(target) )
		return notify_fail("����Ůɢ����ֻ�ܶ�ս���еĶ���ʹ�á�");
	
	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��ʹ�õ��������ԡ�");
	
	if( me->query_skill("tianyu_qijian", 1) < 50 )
		return notify_fail("��������潣������죬����ʹ�á�");

	if(DIFFERSTR(me->querystr("family/family_name"), "���չ�") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if( me->query_skill("bahuang_gong", 1) < 50 )
		return notify_fail("��İ˻�����Ψ�Ҷ��𹦲����ߡ�");
	
	if( me->query("mp") < 300 )
		return notify_fail("����������̫��������ʹ�á���Ůɢ������");
	
	msg = "$CYN$N����Ϣ�������󼲶������ǧ�������������ǵط���$n��$COM\n";
	
	if( !target->is_killing(me) ) target->kill_ob(me);
	
	if (random(me->query_skill("force")) > target->query_skill("force")/2 )
	{
		target->start_busy( me->query_skill("tianyu_qijian") / 20 + 1);
		
		int damage = me->query_skill("bahuang_gong", 1);
		damage = damage +  me->query_skill("tianyu_qijian", 1);
		damage = damage +  me->query_skill("sword", 1);
		
		target->receive_damage("hp", damage);
		target->receive_wound("hp", damage/3);
		me->add("mp", -damage);
		msg += "$HIRֻ��$N������Ϊһ�ߣ�����$n,\n$nֻ��һ���������Ķ�������ͷһ����Ѫ���������$COM";
		me->start_busy(2);
	} 
	else 
	{
		msg += "$CYN����$p�͵���ǰһԾ,������$P�Ĺ�����Χ��$COM";
		me->add("mp", -100);
		me->start_busy(4);
	}
	
	message_vision(msg.c_str(), me, target);
	
	return 1;
}
*/
// san.c  ��Ůɢ��
static int do_san(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	CContainer * weapon;
	string msg;
	
	int extra = me->query_skill("tianyu_qijian",1);
	
	if( !target || !me->is_fighting(target) )
		return notify_fail("����Ůɢ����ֻ�ܶ�ս���еĶ���ʹ�á�");
	
	if( !(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��ʹ�õ��������ԡ�");
	
	if( me->query_skill("tianyu_qijian", 1) < 50 )
		return notify_fail("��������潣������죬����ʹ�á�");

	if(DIFFERSTR(me->querystr("family/family_name"), "���չ�") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if( me->query_skill("bahuang_gong", 1) < 50 )
//	if((me->query_skill("bahuang_gong", 1) < 50 ) 
//		&& (me->query_skill("beiming_shengong", 1) < 50 ))
		return notify_fail("��ı����ڹ�ʵ��̫�û���á���Ůɢ������");
	
	if( me->query("mp") < 300 )
		return notify_fail("����������̫��������ʹ�á���Ůɢ������");
	
//	msg = "$CYN$N����Ϣ�������󼲶������ǧ�������������ǵط���$n��$COM";
	message_vision("$CYN$N����Ϣ�������󼲶������ǧ�������������ǵط���$n��$COM\n" ,me,target); 

	extra = me->query_skill("tianyu_qijian",1) / 20;
	extra += me->query_skill("tianyu_qijian",1) /20;

	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	
	message_vision("\n$HIR��һ�佣����$COM" ,me,target);
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
	message_vision("\n$HIG��һ�佣������$COM" ,me,target);
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
	message_vision("\n$HIY���һ�佣��������$COM" ,me,target);
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);

	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	
	me->add("mp",-150);
	me->start_busy(2);
	return 1;
}

// kuangwu  �������
static int do_kuangwu(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	CContainer * weapon;
	string msg;

	int extra;
	extra = me->query_skill("tianyu_qijian",1);

	if ( !wizardp(me) && (DIFFERSTR(me->querystr("family/family_name"), "���չ�")))
		return	notify_fail("���������ݱ����Ǳ��ŵ��ӷ�����ʹ��");

	if( !target || !me->is_fighting(target) )
		return notify_fail("����������ֻ�ܶ�ս���еĶ���ʹ�á�");

	if(DIFFERSTR(me->querystr("family/family_name"), "���չ�") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");

	//if( ! DIFFERSTR(me->query_skill_mapped("sword"), "tianyu_qijian" ))
	//	return notify_fail("����������ֻ��װ���ڻ��������ϲſ���ʹ�á�");

	if (!(weapon = me->query_weapon())|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��ʹ�õ��������ԡ�");

	if( extra < 200) return notify_fail("��������潣���������죡");

	if( me->query("mp")<650)
		return notify_fail("�������������"); 

	if( me->query("hp")<1500)
		return notify_fail("�����Ѫ������"); 

	if( me->query_skill("bahuang_gong", 1) < 160 )
//	if( (me->query_skill("bahuang_gong", 1) < 160 ) 
//		&& (me->query_skill("beiming_shengong", 1) < 160 ))
		return notify_fail("��ı����ڹ�������졣");
	
	me->add("mp",-650);
	me->add("hp",-1000);
	weapon = me->query_weapon();
//	weapon = me->query_temp("weapon");
//	message_vision("$HIM$Nʹ�������潣�еľ��У��������ݣ�һ���������������е�"+weapon->name()+"�������$n������һ����$COM\n\n" ,me,target); 
	message_vision("$HIM$Nʹ�������潣�еľ��У��������ݣ�һ�������߽����������$n������һ����$COM\n\n" ,me,target); 
	extra = me->query_skill("tianyu_qijian",1) /20;
//	extra += me->query_skill("tianyu_qijian",1) /20;
	if (me->query("combat_exp")> target->query("combat_exp")/3 )
	{
		me->add_temp("apply/attack", extra);	
		me->add_temp("apply/damage", extra);
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
		message_vision("$HIR�ڶ�����$COM\n" ,me,target);
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);

		message_vision("$HIC��������$COM\n" ,me,target);
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);

		message_vision("$HIY���Ľ���$COM\n" ,me,target);
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);

		message_vision("$HIG���彣��$COM\n" ,me,target);
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);

		message_vision("$HIM��������$COM\n" ,me,target);
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);

		message_vision("$HIW���һ����$COM\n" ,me,target);
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
        if (me->query("combat_exp")> target->query("combat_exp")/2 )
        {                
			msg = "$HICһ��������$HIM����$n������,$nֻ�����˿�һ�䣡$COM\n";   
			message_vision(msg.c_str(), me, target);
			target->apply_condition("ss_poison", 5);
			target->start_busy(2);
        }
        if (random(me->query_skill("dodge")) > target->query_skill("dodge") / 2)
        {                
			msg = "$HIYһ��������$HIM����$n������,$nֻ�����˿�һ�䣡$COM\n";   
			message_vision(msg.c_str(), me, target);
			target->apply_condition("ss_poison", 5);
			target->start_busy(2);
        }
        if (random(me->query_skill("force")) > target->query_skill("force") / 2)
        {                
			msg = "$HIRһ��������$HIM����$n������,$nֻ�����˿�һ�䣡$COM\n";   
			message_vision(msg.c_str(), me, target);
			target->apply_condition("ss_poison", 5);
			target->start_busy(2);
        }
		
        message_vision("$WHT$N�����߽������$n�����˸���æ���ң�$COM\n" ,me,target);
        me->start_busy(5);
		me->add_temp("apply/attack", -extra);
		me->add_temp("apply/damage", -extra);
	} 
	else 
	{ 
		message_vision("$HIC����$n������$N����ʽ,�û�����������$COM\n" ,me,target);
		me->start_busy(2);
	}        
	return 1;
}

// yushijufen  ��ʯ���	
static int do_yushijufen(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	CContainer * weapon;
	string msg;

	if ( !wizardp(me) && (DIFFERSTR(me->querystr("family/family_name"), "���չ�")))
		return	notify_fail("����ʯ��٣ݱ����Ǳ��ŵ��ӷ�����ʹ��");

	if( !target || !me->is_fighting(target) )
		return notify_fail("����ʯ��١�ֻ�ܶ�ս���еĶ���ʹ�á�");
	
	if( !(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��ʹ�õ��������ԡ�");
	
	if( me->query_skill("tianyu_qijian", 1) < 180 )
		return notify_fail("��������潣������죬����ʹ�á�");
	
	if( (me->query_skill("bahuang_gong", 1) < 40 ) 
		&& ( me->query_skill("beiming_shengong", 1) < 40 ))
		return notify_fail("��ı����ڹ�������졣");
	
	if( !( me->query("eff_hp")<100||(me->query("max_hp")/me->query("eff_hp"))>=2.5))
		return notify_fail("�㻹û�����ˣ���Ҫʹ����ʯ��١�");

	if(DIFFERSTR(me->querystr("family/family_name"), "���չ�") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");

	if( me->query_skill("bahuang_gong", 1) < 100 )
//	if( (me->query_skill("bahuang_gong", 1) < 100 ) 
//		&& ( me->query_skill("beiming_shengong", 1) < 100 ))
		return notify_fail("��ı����ڹ�ʵ��̫�û���á���ʯ��١���");
	
	if( me->query("max_mp") < 1500 )
		return notify_fail("����������̫��������ʹ�á���ʯ��١���");
	
	msg = "$RED$NԾ�����ɣ���ɫ���أ�һ��[��ʯ���]���$nͬ���ھ���$COM\n";
	
	if( random(me->query("combat_exp")) > target->query("combat_exp")/2 ) 
	{
		if(random(2)==1)
		{
			msg += "���$p��$P���˸����ֲ�����������ȥ��$COM\n" ;
			target->unconcious();
		}
		msg += "$P�Լ������������ȣ�������ȥ��$COM\n" ;
		me->unconcious();
	} 
	else 
	{
		msg += "����$p���Ƕ����$P�����һ�������Լ������������ȣ�������ȥ��$COM\n" ;
		me->unconcious();
	}
	message_vision(msg.c_str(), me, target);
//	me->unconcious();
	return 1;
}


SKILL_END;





