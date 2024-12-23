//xiaoyao-dao  ��ң����

SKILL_BEGIN(CSxiaoyao_dao);

virtual void create()
{
	set_name( "��ң����");
	set("valid_force", "beiming_shengong");

	set("diff",140);
	Magic_t * magic;

	magic = add_magic("daoshenxiao", do_daoshenxiao);
	magic->name = "����һЦ";
	magic->mp = 1000;
	magic->ap=100;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int force, dodge, parry, lvl, damage;
	}action[] = {
		{"$N����΢����һ�С��ʺ���졹����$w����һ���׺磬ֱ����$n����ǰ", 220,5,20,0,30,},
		{"$N���μ�ת��һ�С��ط�ת�ơ�������һƬ������$w����$n", 260,0,8,15,40,},
		{"$N���ᵶ�棬$w����һ�������һ�С�������⡹������$n��ͷ��", 320,-10,15,30,50,},
		{"$N���漱ת�����Ī�⣬һ�С������Ϲ项��$w������$n�ĺ���", 340,-10,20,50,50,},
		{"$N���΢Ц�����⻯�������׵㣬һ�С������һ�����������$nȫ��", 370,-20,15,80,60,},
		{"$Nʹ��һ�С����Ƕ��ǡ��������󵶣������󽣣�������$n����Ҫ��", 380,-35,50,100,60,},
		{"$Nʹһʽ�����ں�ë����$w��ͬ����Ʈ��һ�㣬���ϵ�ֱ��$n��ȥ", 390,-10,70,130,100,},
		{"$N�����ڱ���,һ�С��������塹��$w����ǧ��һ�㣬ֱֱ��$n��ȥ", 400,-10,70,150,150,},
	};

	struct {
		char action[255];
	}action1[] = {
		{"$HIG$Nʹһ�С��ԾƵ��衹�����б������Ƶ���$nնȥ��",},
		{"$HIR$N�䵶���£���������һ�С��������Ρ����¶�������$n�� ",},
		{"$HIC$N����һת��һ�С�Ʃ�糯¶�������糯¶��˸��ն��$n ��",},
		{"$HIC$N�趯������һ�С�ȥ�տ�ࡹ��$nбб����һ����",},
		{"$HIY$N���б���һ�Σ�һ�С������Կ���Ѹ�����׵�����$n��",},
		{"$HIG$N�����������էչ��һ�С���˼������ֱ��$n��",},
		{"$HIR$N�Ʋ�����ʹһ�С����Խ��ǡ��������ն��$n��",},
		{"$HIG$Nʹ��һ�С�Ψ�жſ����������еı�������$n����ָ��",},
		{"$HIC$N���̤ǰһ����һ�С��������ơ������еı����Ӳ���Ʈ��$n֮�ؾȣ�",},
		{"$HIM$N���еı���һ�������һƬ������һ�С��������ġ�������$n��ȫ��",},
		{"$HIG$N΢��һ�������еı�������һ���⻡��һ�С���Ϊ���ʡ�����$n��ȫ��Χס�� ",},
		{"$HIW$Nʹ��һ�С��������񡹣������еı�������$n��",},
		{"$HIR$N���̤ǰ̤��һ�С�����¹���������еı�������$n֮�ؾȡ�",},
		{"$HIY$N���еı���һ����һ�С�ɽ����ߡ�������$n��",},
		{"$HIG$N���еı�������һ�С����¹��ġ�����$n��ȫ��Χס��",},
	};
		

	int level = me->query_skill("xiaoyao_dao", 1);
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < level)
		{
			level = random(i);
			if(!me->query_temp("daoshenxiao"))
				m_actions.set("action", action[level].action);
			else
			{
				m_actions.set("action", action1[me->query_temp("daoshenxiao")-1].action);
			}
/*
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("parry", action[level].parry);
			m_actions.set("damage", action[level].damage);
*/
			m_actions.set("force", (me->query("skill_pro/��ң��/��ң����/force")+100) * action[level].force/100);
			m_actions.set("dodge", (me->query("skill_pro/��ң��/��ң����/dodge")+100) * action[level].dodge/100);
			m_actions.set("parry", (me->query("skill_pro/��ң��/��ң����/parry")+100) *action[level].parry);
			m_actions.set("damage", (me->query("skill_pro/��ң��/��ң����/damage")+100) * action[level].damage/100);
			
			break;
		}
	}

	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="blade"; }

virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if(!random(10)||wizardp(me))
	{
		int level_point;
		if(victim->query("force")) 
		{
			me->add("skill_pro/��ң��/��ң����/force_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/��ң��/��ң����/force"));
			if(me->query("skill_pro/��ң��/��ң����/force_point")>=level_point)
			{
				me->add("skill_pro/��ң��/��ң����/force",1);
				me->set("skill_pro/��ң��/��ң����/force_point",1);
				tell_object(me,"\n$HIR�����ң��������ڹ������ڻ��ͨ�ˡ�\n");
			}
		}
		else if(victim->query("dodge")) 
		{
			me->add("skill_pro/��ң��/��ң����/dodge_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/��ң��/��ң����/dodge"));
			if(me->query("skill_pro/��ң��/��ң����/dodge_point")>=level_point)
			{
				me->add("skill_pro/��ң��/��ң����/dodge",1);
				me->set("skill_pro/��ң��/��ң����/dodge_point",1);
				tell_object(me,"\n$HIR�����ң����ʹ�õø��ӵ���Ӧ���ˡ�\n");
			}
		}
		else if(victim->query("parry")) 
		{
			me->add("skill_pro/��ң��/��ң����/parry_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/��ң��/��ң����/parry"));
			if(me->query("skill_pro/��ң��/��ң����/parry_point")>=level_point)
			{
				me->add("skill_pro/��ң��/��ң����/parry",1);
				me->set("skill_pro/��ң��/��ң����/parry_point",1);
				tell_object(me,"\n$HIR��������ʹ����ң����������������һ����ǿ�ˡ�\n");
			}
		}
		else if(victim->query("damage")) 
		{
			me->add("skill_pro/��ң��/��ң����/damage_point",1);

			level_point=(query("diff")+80)*(1+me->query("skill_pro/��ң��/��ң����/damage"));
			if(me->query("skill_pro/��ң��/��ң����/damage_point")>=level_point)
			{
				me->add("skill_pro/��ң��/��ң����/damage",1);
				me->set("skill_pro/��ң��/��ң����/damage_point",1);
				tell_object(me,"\n$HIR�����ң�������������ˡ�\n");
			}
		}
	}
	return "";
}

virtual int valid_learn(CChar * me)
{

	if ( DIFFERSTR(me->querystr("family/family_name"), "��ң��"))
		return	notify_fail("��ң����������ң�ɵ��ӷ�����ѧϰ");

	if (me->query_skill("blade", 1) < 20)
		return notify_fail("��Ļ�������̫������������ң������");

	if (me->query_skill("blade", 1) < me->query_skill("xiaoyao_dao", 1))
		return notify_fail("��Ļ���������򲻹������ܼ���������ң�����ˡ�");

	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if ( DIFFERSTR(me->querystr("family/family_name"), "��ң��"))
		return	notify_fail("��ң����������ң�ɵ��ӷ�������ϰ");

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "blade"))
		return notify_fail("��ʹ�õ��������ԡ�");

	if (me->query_skill("blade", 1) < me->query_skill("xiaoyao_dao", 1))
		return notify_fail("��Ļ���������򲻹������ܼ���������ң�����ˡ�");
	
	if (me->query("hp") < 30)
		return notify_fail("�������������������ң������");

	me->receive_damage("hp", 30);

	return 1;
}

static int do_daoshenxiao(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	int harm;
	string msg;
	CContainer * weapon;
	char cmd[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if(! target || ! me->is_fighting(target))		
		return notify_fail("ֻ�ܶ�ս���еĵ���ʹ�ã�");

	if(me->query_str() < 25)
		return notify_fail("���������,����ʹ����һ����!");

	if ( !wizardp(me) && (DIFFERSTR(me->querystr("family/family_name"), "��ң��")))
		return	notify_fail("�۵���һЦ�ݱ�������ң�ɵ��ӷ�����ʹ��");

	if(me->query_skill("beiming_shengong",1) < 100)
		return notify_fail("��ı�ڤ�񹦹�������������ʹ�ã۵���һЦ��!");
	
	if(me->query_skill("xiaoyao_dao",1) < 180)
		return notify_fail("�����ң������������������ʹ�ã۵���һЦ��!");

	if (! (weapon = me->query_weapon())	|| DIFFERSTR(weapon->querystr("skill_type"), "blade"))
		return notify_fail("�����޵�������ʩչ�������о����۵���һЦ��!");

	if(me->query_skill("blade") < 180)
		return notify_fail("��Ļ���������Ϊ����,Ŀǰ������ʹ�ã۵���һЦ�ݾ���!");

	if(me->query("mp") < 1000)
		return notify_fail("���������ڲ���, ����ʹ�ã۵���һЦ��! ");

	if ( me->query("xiaoyao/���þ���")==1 )
		return notify_fail("���������Ѿ��޷���ʹ�ñ������Ͼ��У۵���һЦ����!"); 

	if ( me->query("xiaoyao/xiaoyaodao") < 1 )
		return notify_fail("δ��ʦ����ɣ��������ñ��Ž��У�");

	if ( me->query("xiaoyao/����")>=1)
		return notify_fail("�ո�ʦ��������������þ����ˣ�");

	if( target->is_busy() )
		return notify_fail("%sĿǰ���Թ˲�Ͼ���ŵ������ɣ�", target->name());

	msg = "\n$HIM$N��������Ȱ�ıƽ�$n,��ʹ��һ����ң������ʧ���ѾõĿ�������$HIR������һЦ����$COM\n";
	msg += "$HIM�������������б���������������������Ӳ�����Ļ���һƬƬ��Ƭ��Ƭ����$n������$COM\n";
	msg += "$HIM���з�����Х�������ŵ�Ƭ�ƿյ��������߳���һ�����̸��С���$COM\n";
	message_vision(msg.c_str(), me, target);

	if( random(me->query_combat_exp()) > target->query_combat_exp() / 10 )
	{
		if(!EQUALSTR(target->query_skill_mapped("finger"), "liumai_shenjian"))
		{		
			if(me->query_temp("apply/����һЦ"))
			{
				me->set_temp("daoshenxiao",1);
				g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);

				me->add_temp("daoshenxiao",1);
				g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);

				me->add_temp("daoshenxiao",1);
				g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);

				me->add_temp("daoshenxiao",1);
				g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);

				me->add_temp("daoshenxiao",1);
				g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);

				me->add_temp("daoshenxiao",1);
				g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);

				me->add_temp("daoshenxiao",1);
				g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);

				me->add_temp("daoshenxiao",1);
				g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);

				me->add_temp("daoshenxiao",1);
				g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);

				me->add_temp("daoshenxiao",1);
				g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);

				me->add_temp("daoshenxiao",1);
				g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);

				me->add_temp("daoshenxiao",1);
				g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);

				me->add_temp("daoshenxiao",1);
				g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);

				me->add_temp("daoshenxiao",1);
				g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);

				me->add_temp("daoshenxiao",1);
				g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);

				msg =  "\n\n$HIR$nȫ�����±�������һƬ������Ӱ֮�У�����ĵ�Ƭ���$n�������ˡ� $COM";
				message_vision(msg.c_str(), me, target);
				
				harm=(random((me->query_str()/4+me->query_combat_exp()/30000)/2)+120)*me->query_skill("xiaoyao_dao", 1)/20;
				target->add("hp", -harm);
				snprintf(cmd ,255,"$HIR��������%d����˺���$COM\n",harm);
				message_vision(cmd,me,target);
				me->add("mp", -me->query("mp"));
				me->delete_temp("daoshenxiao");
				me->start_busy(99);	
				
			}
			else
			{
				msg =  "\n$HIG$Nʹһ�С��ԾƵ��衹�����б������Ƶ���$nնȥ��$COM\n";
				msg +=  "\n$HIR$N�䵶���£���������һ�С��������Ρ����¶�������$n $COM\n";
				msg +=  "\n$HIC$N����һת��һ�С�Ʃ�糯¶�������糯¶��˸��ն��$n $COM\n";
				msg +=  "\n$HIC$N�趯������һ�С�ȥ�տ�ࡹ��$nбб����һ���� $COM\n";
				message_vision(msg.c_str(), me, target);
				msg =  "\n$HIY$N���б���һ�Σ�һ�С������Կ���Ѹ�����׵�����$n�� $COM\n";
				msg +=  "\n$HIG$N�����������էչ��һ�С���˼������ֱ��$n $COM\n";
				msg +=  "\n$HIR$N�Ʋ�����ʹһ�С����Խ��ǡ��������ն��$n $COM\n";
				msg +=  "\n$HIG$Nʹ��һ�С�Ψ�жſ����������еı�������$n����ָ�� $COM\n";
				message_vision(msg.c_str(), me, target);
				msg =  "\n$HIC$N���̤ǰһ����һ�С��������ơ������еı����Ӳ���Ʈ��$n֮�ؾȣ� $COM\n";
				msg +=  "\n$HIM$N���еı���һ�������һƬ������һ�С��������ġ�������$n��ȫ�� $COM\n";
				msg +=  "\n$HIG$N΢��һ�������еı�������һ���⻡��һ�С���Ϊ���ʡ�����$n��ȫ��Χס�� $COM\n";
				message_vision(msg.c_str(), me, target);
				msg =  "\n$HIW$Nʹ��һ�С��������񡹣������еı�������$n�� $COM\n";
				msg +=  "\n$HIR$N���̤ǰ̤��һ�С�����¹���������еı�������$n֮�ؾȡ� $COM\n";
				msg +=  "\n$HIY$N���еı���һ����һ�С�ɽ����ߡ�������$n�� $COM\n";
				message_vision(msg.c_str(), me, target);
				msg =  "\n$HIG$N���еı�������һ�С����¹��ġ�����$n��ȫ��Χס��$COM\n\n";
				msg +=  "\n$HIR$nȫ�����±�������һƬ������Ӱ֮�У�����ĵ�Ƭ���$n�������ˡ� $COM";
				message_vision(msg.c_str(), me, target);
				harm=(random((me->query_str()/4+me->query_combat_exp()/30000)/2)+120)*me->query_skill("xiaoyao_dao", 1)/20;
				target->add("hp", -harm);
				snprintf(cmd ,255,"$HIR��������%d����˺���$COM\n",harm);
				message_vision(cmd,me,target);
				me->add("mp", -1000);
				me->start_busy(5);		
			}
		}
		else
		{
			msg = "$HIR$p����Ȼ�ӿ죬ֱ�Ƶ�$P����ǰ����ָ�Ѿ�����$PС��������������Ȼ�������\n$COM";
			message_vision(msg.c_str(), me, target);
			harm=(random(target->query("age")/4+target->query("per")/3)+1)*(random(target->query_skill("liumai_shenjian", 1)/20)+25)*4;
			snprintf(cmd ,255,"$HIR���$N�ܵ���%d����˺���$COM\n",harm);
			message_vision(cmd,me,target);
			me->add("mp", -500);
			me->start_busy(6);
		}
	}
	else
	{
		msg = "$HIM����$p������$P����ͼ����û���ϵ���\n$COM";
		message_vision(msg.c_str(), me, target);
		me->start_busy(4);
		me->add("mp", -500);
	}
	destruct(weapon);
	msg ="$HIW��������Ƭ����һ���׹⣬��ɢ�����ˡ���$COM\n";
	if(!me->query_temp("apply/����һЦ"))
	{
		msg+="$HIY$N��״����������ڣ������Լ�ֻͼ��һʱ֮�죬������ʦ����ɽǰ���͸��Լ��ı�����$COM\n";
		msg+="$HIY���ɵĵ����������ʦ��ʱ��Ҫ��ʦ�����ֱ�������������Լ�͵�ý��ж��������鷳��$COM\n\n";
		msg+="$HIR��ʦ���棺������Ŀǰ���ڲ��Խ׶Σ���ʽ�Ƴ������ش�Ķ������������������˾��̳֪ͨ��$COM\n";
				
		if ( me->query("xiaoyao/xiaoyaodao") >0 )
		{
			me->add("xiaoyao/xiaoyaodao", -1);
		}
		else
		{
			me->set("xiaoyao/���þ���", 1);
		}
	}
	message_vision(msg.c_str(), me, target);
	return 1;
}

SKILL_END;





