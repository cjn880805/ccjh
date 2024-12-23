// liumai_shenjian.h ������

SKILL_BEGIN(CSliumai_shenjian);

virtual void create()
{
	set_name( "������");
	
	Magic_t * magic;
	
	magic = add_magic("ci", do_ci);
	magic->name = "���־�";
	magic->mp = 200;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
	
	magic = add_magic("feng", do_feng);
	magic->name = "���־�";
	magic->mp = 150;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
	
	magic = add_magic("tan", do_tan);
	magic->name = "���־�";
	magic->mp = 250;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
	
	magic = add_magic("guiyi", do_guiyi);
	magic->name = "������һ";
	magic->mp = 1100;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "kurong_changong") || EQUALSTR(arg, "kurong_shengong") || EQUALSTR(arg, "tianlong_shengong"))
		return 1;
	
	return notify_fail("�����񽣱������������ڹ����ʹ�á�");
}

CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int force, dodge, damage ,lvl;
		char damage_type[5];
	}action[11] = {
		{"$N����������˫��Ĵָͬʱ����������������죬�����̽�������ʯ���쾪���������֮�ƣ���ָ$n���к�$l",
		350, 50, 250, 0, "����",},
		{"$Nʳָ����������԰ת������������һ����һ���Ĵ̳�������Ѹ�٣����ɻ��ã������ݺᣬ$n�����޷�������·",
		400, 100, 200, 10, "����",},
		{"$N������ָһ�������г彣����ǰ�̳��������ĵ�����Ȼ���죬���ν���ֱָ$n��$l",
		350, 40, 250, 20, "����",},
		{"$N��������ָ��������س彣����·׾�͹��ӣ�һ���ۻ�������ĵ�����������ɽ��������$nӿȥ",
		350, 60, 250, 30, "����",},
		{"$N����Сָһ�죬һ���������ٳ�Ѩ�м�������������󽣡�������磬ָ��$n��$l",
		350, 50, 250, 40, "����",},
		{"$N���ַ�ָ��Сָ������������ٳ�Ѩ�������������ٳ彣��������䣬��$n���벻���ķ������$n��$l",
		350, 40, 250, 50, "����",},
		{"$N����΢�࣬��Ȼ���о�����֣�����ʳָ������Ĵָ������һ��˲��һ������ν�������$n��$l", 
		510, 220, 200 , 60, "����",},
		{"$N�����䣬�����������벻���ķ�λ�������Ī��Ľ���������̻����ع���$n��$l",
		570 , 225, 250, 75, "����",},
		{"$N�Ķ�ȫ�����������������������������λͬʱ��������$n���ۿ�$n������·����", 
		600, 250, 300, 100 , "����",},
		{"$N����Ȼ�ӿ죬ֱ�Ƶ�$n����ǰ����ָ�Ѿ�����$nС����������������Ȼ�������", 
		750, 350, 400, 160, "����",},
	};
	
	int level;

	if( ! (level = me->query_temp("pfm_lmsj")) )
	{
		for(int i=10; i>0; i--)
		{
			if(action[i - 1].lvl < me->query_skill("liumai_shenjian", 1))
			{
				level = random(i);				
				break;
			}
		}
	}
	else
		level--;
	
	if (DIFFERSTR(me->querystr("family/family_name"), "����μ�"))
	{
		m_actions.set("action", "$N����ŤŤ�ĳ�$n�����ָ�������������һ�����ۡ���");
		m_actions.set("force", 0l);
		m_actions.set("dodge", 0l);
		m_actions.set("damage", 0l);
	}
	else
	{
		m_actions.set("action", action[level].action);

		if(! me->query_temp("pfm_lmsj"))
			m_actions.set("force", action[level].force);
		else
			m_actions.set("force", 0l);

		m_actions.set("dodge", action[level].dodge);
		if(me->query_temp("apply/��_����"))
			m_actions.set("damage", (me->query_temp("apply/��_����")+100) * action[level].damage/100);
		else
			m_actions.set("damage", action[level].damage);
	}
	
	return & m_actions;
};

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }

int valid_learn(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("�������񽣱�����֡�");
	
	if(me->query_skill("liumai_shenjian",1)<=0)
		return notify_fail("�����ѧ��ÿһ���Ľ������ſ���ѧ.");
	
	if (me->query("max_mp") < 2000)
		return notify_fail("�������̫�����޷��������񽣡�");
	
	if (me->query_skill("kurong_changong", 1) < 80 
		||me->query_skill("tianlong_shengong", 1) < 80)
		return notify_fail("��ı����ڹ���򲻹����޷�ѧһ��ָ��");
	
	return 1;
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 100)
		return notify_fail("�������̫���ˡ�");
	
	if (me->query("mp") < 100)
		return notify_fail("�������������������");
	me->receive_damage("hp", 80);
	me->add("mp", -80);
	
	return 1;
}
/*
virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if (random(me->query_skill("liumai_shenjian",1)) > 200 
		&& me->query_skill("kurong_changong",1) > 200 
		&& me->query("mp") > 1000)

		me->add("mp", -200);
		
		m_actions.set("action", "\n$N��Ȼ���ý����е���·����һһӿ����ͷ��ʮָ�׵�����ȥ�����������޾���\n\n�����ݺᣬ����������·������ת��ʹ��$n��ʱ������ң�����ȫ������ʹ��������Ѫ�����ϱ����\n\n��ʹ̧ͷһ����һ������ӭ���ֵ���\n");
		m_actions.set("force", 1000);
		m_actions.set("dodge", 0l);
		m_actions.set("damage", 1000);
		m_actions.set("damage_type", "����");
	}
	
	if( damage < 100 )
	{
		damage = 0;
		return 0;
	}
	if( random( damage / 2) > victim->query_str() )
	{
		victim->receive_wound("hp", (damage - 100) / 2 );
		return "$HIR��������������һ�����죬���Ͼ�����һЩѪ�Σ�$COM";
	}
	return 0;
}
*/

static int do_ci(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;
	int lvl;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	if( !target	||	!me->is_fighting(target) )
		return notify_fail("���̡��־�����ֻ�ܶ�ս���еĶ���ʹ�á�");
	
	if ( me->query_weapon())
		return notify_fail("�㲻��ʹ��������");
	
	if( (lvl = me->query_skill("liumai_shenjian", 1)) < 100 )
		return notify_fail("���������̫���裬����ʹ�á��̡��־���");
	
	if ( me->query("mp") < 200)
		return notify_fail("������������������޷�ʹ�á��̡��־���");
	
	if (DIFFERSTR(me->querystr("family/family_name"), "����μ�"))
		return notify_fail("���˼ڤ�룬�����벻����ô����");
	
	me->add("mp", -40);
	
	msg =  "$Nʹ�������񽣡��̡�ʽ��ָ������ʱ�佣���ݺᣬ��$n��Χ���ڡ�\n";
	
	me->start_busy(2);
	if( random( me->query("mp") + me->query_skill("liumai_shenjian",1) * 10 ) > random( target->query_skill("dodge",1) * 10 + 1)
		&& random(me->query("combat_exp")) > target->query("combat_exp")/4) 
	{
		msg +=  "���$pһ���ƺߣ�����������" ;
		target->receive_damage("hp", random(lvl*10) + lvl);
		target->receive_wound("hp", random(lvl*5));
	} 
	else 
	{
		msg += "����$p�����мܣ�������ס��$P���ơ�" ;
	}
	message_vision(msg.c_str(), me, target);
	
	return 1;
}

static int do_feng(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	if( !target	||	!me->is_fighting(target) )
		return notify_fail("���⡹�־�ָ��ֻ�ܶ�ս���еĶ���ʹ�á�");
	
	if ( me->query_weapon())
		return notify_fail("�㲻��ʹ��������");
	
	if (DIFFERSTR(me->querystr("family/family_name"), "����μ�"))
		return notify_fail("���˼ڤ�룬�����벻����ô����");
	
	if( me->query_skill("liumai_shenjian", 1) < 90 )
		return notify_fail("���������̫���裬����ʹ�á��⡹�־���");
	
	if ( me->query("mp") < 150)
		return notify_fail("������������������޷�ʹ�á��⡹�־���");
	me->add("mp", -30);
	
	if( target->is_busy() )
		return notify_fail( "%sĿǰ���Թ˲�Ͼ���ŵ������ɣ�",target->name() );
	
	msg =  "$HIR$N����һ������ʹ�������񽣡��⡹ʽ��ָָ��㣬�����糱������\n";
	
	me->start_busy(1);
	if( (random( me->query("mp")) + me->query_skill("dodge",1) * 10 + 1) >random( target->query_skill("dodge",1) * 10) + 1
		&& random(me->query("combat_exp")) > target->query("combat_exp")/5
		&& !(target->query_temp("apply/no_���־�") && target->query("bigboss"))) 
	{
		msg +=  "$HIR$pǿ�����������ҵ����޷����֣�" ;
		target->start_busy( me->query_skill("liumai_shenjian", 1) / 40 );
	} 
	else 
	{
		msg += "����$p����һ����ƮȻ����$P�Ĺ�����" ;
	}
	message_vision(msg.c_str(), me, target);
	
	return 1;
}

static int do_tan(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	string msg,msg1;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	if( !target ||	!me->is_fighting(target) )
		return notify_fail("�������־�ָ��ֻ�ܶ�ս���еĶ���ʹ�á�");
	
	if ( me->query_weapon())
		return notify_fail("�㲻��ʹ��������");
	
	if (DIFFERSTR(me->querystr("family/family_name"), "����μ�"))
		return notify_fail("���˼ڤ�룬�����벻����ô����");
	
	if (! (weapon = target->query_weapon()) )
		return notify_fail("�Է���û���������㲻�õ��ģ�");
	
	if( me->query_skill("liumai_shenjian", 1) < 190 )
		return notify_fail("���������̫���裬����ʹ�á������־���");
	
	if ( me->query("mp") < 250)
		return notify_fail("������������������޷�ʹ�á������־���");
	
	me->add("mp", -50);
	
	msg =  "$N����һ������ʹ�������񽣡�����ʽ��һ��Ϭ���ޱȵĽ���ֱ��$n��ȥ��\n";
	
	me->start_busy(2);
	if( random( me->query_skill("force") ) > random( target->query_skill("force") + 1) )
	{
		if(weapon->query("no_duo") && !random(3))
			msg += "����$n������$N����ͼ����û���ϵ���\n";
		else if (ob->querystr("owner")[0])
		{
			msg +=  " $pæ��";
			msg += weapon->name();
			msg += "�мܣ�ֻ���û��ھ������ұ����������" ;
			target->start_busy(2);
		} 
		else
		{
			msg +=  " $p��æ�мܣ�ֻ������ž����һ����$p���е�";
			msg += weapon->name();
			if(weapon->query("no_duo") )
			{
				msg += "��Ȼ���׶��ɣ�\n";
				char msg1[40];
				target->command(snprintf(msg1, 40, "unwield %ld", weapon->object_id()));
			}
			else
			{
				msg += "�Ѿ���Ϊ���أ��������죡" ;
				
				//ob->unequip();
				weapon->move(target->environment());
				
				msg1 = "�ϵ���";
				msg1 += weapon->querystr("name");
				weapon->set_name(msg1.c_str());
				weapon->set("value", 0l);
				weapon->del("apply");
				target->start_busy(2);
			}
		}
	} 
	else
	{
		msg += "$p������ע";
		msg += weapon->name();
		msg += "����$P�����ཻ��ð������⡣" ;
	}
	message_vision(msg.c_str(), me, target);
	return 1;
}

static int do_guiyi(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	int extra = me->query_skill("liumai_shenjian", 1) / 3;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	if( !target	||	!me->is_fighting(target) )
		return notify_fail("��������һ��ֻ����ս����ʹ�á�");
	
	if ( me->query_weapon())
		return notify_fail("��������һ��ֻ�ܿ���ʹ�á�");		
	
	if (DIFFERSTR(me->querystr("family/family_name"), "����μ�"))
		return notify_fail("���˼ڤ�룬�����벻����ô����");

	if ( me->query("mp") < 1100)
		return notify_fail("�������������");
	
	if( me->query_skill("liumai_shenjian", 1) < 199 )
		return notify_fail("��������񽣻�򲻹����޷�ʹ�á�������һ����");
	
	if( me->query_skill("force", 1) < 110 )
		return notify_fail("����ڹ���Ϊ�������޷�ʹ�á�������һ����");

	if (me->query_skill("finger", 1)
		&& !EQUALSTR(me->query_skill_prepared("finger"), "liumai_shenjian"))
		return notify_fail("��������һ��ֻ����ϵ�����ָ���ϲ���ʹ�á�");

	if(DIFFERSTR(me->querystr("family/family_name"), "����μ�") && me->querymap_temp("biwu"))
		return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");

	if(!me->query_temp("apply/������һ"))
		return notify_fail("����˼���ң�����ңָ�˼��£����ȴû���κη�ӳ��");

	me->add("mp", -1100);

	me->add_temp("apply/attack", +extra);
	me->add_temp("apply/damage", +extra);
	
	message_vision("$CYN$N��˼���ң���$n����ңָ�˼��£�����ȴʹ�������������ľ���$HIY[������һ]$CYN��$COM\n", me, target);

	message_vision("\n$HIR-------------------------------���̽���$COM", me, target);
	me->set_temp("pfm_lmsj", 1);
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK); 

	message_vision("\n$HIG-------------------------------��������$COM", me, target);
	me->set_temp("pfm_lmsj", 2);
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK); 

	message_vision("\n$HIM-------------------------------�г彣��$COM", me, target);
	me->set_temp("pfm_lmsj", 3);
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK); 

	message_vision("\n$HIY-------------------------------�س彣��$COM", me, target);
	me->set_temp("pfm_lmsj", 4);
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK); 

	message_vision("\n$HIW-------------------------------���󽣣�$COM", me, target);
	me->set_temp("pfm_lmsj", 5);
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK); 

	message_vision("\n$HIB-------------------------------�ٳ彣��$COM", me, target);
	me->set_temp("pfm_lmsj", 6);
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK); 

	me->delete_temp("pfm_lmsj");
	
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	
	me->start_busy(6);
		
	return 1;
}

SKILL_END;





