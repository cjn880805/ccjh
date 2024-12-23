// murong_jianfa.h Ľ�ݽ���

SKILL_BEGIN(CSmurong_jianfa);

virtual void create()
{
	set_name( "Ľ�ݽ���");
	
	Magic_t * magic;
	
	magic = add_magic("qixing", do_qixing);
	magic->name = "��ת����";
	magic->mp = 300;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
	
	magic = add_magic("kuangjian", do_kuangjian);
	magic->name = "�콣";
	magic->mp = 400;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
	
	magic = add_magic("lianhuan", do_lianhuan);
	magic->name = "�߽�����ָ";
	magic->mp = 500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
	
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "shenyuan_gong") || EQUALSTR(arg, "shenyuan_gong"))
		return 1;
	
	return notify_fail("Ľ�ݽ�����������Ԫ�����ʹ�á�");
}

CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int force, dodge, damage, lvl;
	}action[6] = {
		{"$N������ָ��һʽ��ϴ����������˫�ź�������������ֱ��$n�Ȳ�",
		100, 20, 30, 0,},
		{"$N̤ǰ�����������ʵ������ʹһʽ�����������ֱ��$n������",
		100, 15, 60, 20,},
		{"$Nһ�С�������������ⶶ����佣�����ֱ����$n���������Ҷ�",
		140, 5, 80, 40,},
		{"$N�����ڣ�����ָ��$n��������һ�С�����Ī��������������ǧ��һ�㣬��ɨ$n��$l",
		200, 10, 100, 60,},
		{"$N˫����أ�ʹ�����Ϸɣ�����ֱ��$n��һ�С��ﻢ���¡��������й���ƽ��$n��$l",
		260, 5, 120, 80,},
		{"$N��Цһ�����ὣб����һ�С���ש���񡹣��������$n��$l",
		300, -5, 140, 100,},
	};
	
	int level = me->query_skill("murong_jian", 1);
	for(int i = 6; i > 0; i--)
		if(level > action[i-1].lvl)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			
			break;
		}
		
		return & m_actions;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;
	
	if (!(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��ʹ�õ��������ԡ�");
	
	if (me->query("hp") < 50)
		return notify_fail("�������������Ľ�ݽ�����");
	
	me->receive_damage("hp", 25);
	return 1;
}

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 100)
		return notify_fail("�������������");
	
	if (me->query_skill("hunyuan_yihp", 1) < 20)
		return notify_fail("�����Ԫ�����̫ǳ��");
	
	if (me->query_skill("parry", 1) < 20)
		return notify_fail("��Ļ����мܻ��̫ǳ��");
	
	return 1;
}

virtual char * hit_ob(CChar *me, CChar *victim, LONG & damage)
{	
	CContainer * weapon;
	string msg;	
	weapon = me->query_weapon();
	
	if(me->query_temp("lianhuan") && !me->query_temp("lianhuan_hit")
		&& DIFFERSTR(me->query_skill_prepared("finger"), "canhe_zhi")	//�жϲκ�ָ�Ƿ�׼���á�
		&& DIFFERSTR(me->query_skill_mapped("finger"), "canhe_zhi"))
	{
		me->set_temp("lianhuan_hit", 1);
//		weapon->unequip();
		weapon->move(me);
//		COMBAT_D->do_attack(me, victim, me->query_temp("weapon"),1); 
		g_Combatd.Do_Attack(me, victim, CCombatd::TYPE_QUICK);
		weapon->wield();
		me->add("mp", -30);
		me->delete_temp("lianhuan_hit");
		me->add_temp("lianhuan", -1);
	}
	return 0;
}

virtual int valid_enable(string usage) { return usage == "sword" || usage == "parry";}

static int do_qixing(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	string msg;
	int damage;
	weapon = me->query_weapon();
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	if( !target || !me->is_fighting(target) )
		return notify_fail("��ת����ֻ�ܶ�ս���еĶ���ʹ�á�");
	
	if( me->query_skill("murong_jianfa", 1) < 100 )
		return notify_fail("��Ľ�ת���ǻ�δ���ɣ�����ʹ�ã�");
	
	if( me->query_skill("shenyuan_gong", 1)<70)
		return notify_fail("��ı����ڹ����δ������");
	
	if( me->query("mp") < 300 )
		return notify_fail("�������������㣬����ʹ�ý�ת���ǣ�");
	
	if( me->query_skill("sword", 1) < 100 )
		return notify_fail("��Ļ�������������죬����ʹ�ý�ת���ǡ�");

	msg = "\n$HIY$N��Ȼ����һת���������������棬ֻ���߶佣���������ֱ�Ϯ��$n��";
	msg += "�ߴ�ҪѨ��$COM\n";
	
	if ( random(me->query("dex")) > target->query("dex")*2/3 )
	{
		msg += "\n$HIR$pֻ����ȫ���ܵ������𵴣����İ��ʹ��һ����Ѫ��������϶�\n";
		msg += "���߸�Ѫ��ģ����Ѫ������$COM\n";
		message_vision(msg.c_str(), me, target);
		me->add("mp", -100);
	}
	
	else
	{
		msg += "\n$HIG$p�鼱֮��˫�Űϵض��𣬿�������һ�����Ǳ��ض����һ�գ���ɫ��Ĳ԰ס�$COM\n";
		message_vision(msg.c_str(), me, target);
		me->start_busy(2);
	}
	if (random(me->query_skill("parry")) > target->query_skill("parry")/2 )
	{
		me->start_busy(2);
		
		damage = me->query_skill("shenyuan_gong", 1);
		
		damage = damage*5/2 + random(damage);
		target->receive_damage("hp", damage);
		target->receive_wound("hp", damage);
		target->add("mp", -random(damage));
		me->add("mp", -100);
		if( damage < 300 ) msg += "\n$HIC���$n��ɫ��òҰף������������˺ü�����$COM\n";
		else if( damage < 400 ) msg += "\n$HIM������صػ��У�$n���ۡ���һ���³�һ����Ѫ��$COM\n";
		else if( damage < 500 ) msg += "\n$RED������䡹��һ����$nȫ����Ѫ������������Ѫ���������$COM\n";
		else msg += "\n$HIR���ֻ���������������죬$nһ���ҽУ���̲�����������ȥ����$COM\n";
		
	}
	else
	{
		me->start_busy(2);
		msg += "\n$HIG$p�鼱֮��˫�Űϵض��𣬿�������һ�����Ǳ��ض����һ�գ���ɫ��Ĳ԰ס�$COM\n" ;
	}
	if(!me->query_temp("lianhuan"))
	{
		if( me->query_skill("murong_jianfa", 1) > 249 )
		{
			message_vision("\n$HIG$N��Ȼ������ת��ֻ���߶佣���ٴ��������ֱ�Ϯ��$n���ߴ�ҪѨ��$COM\n",me,target);
			msg = "$HIW��תһ����$WHT��$HIY������$WHT��\n\n$HIGֻ��$N����֮����һ������ֱ����$n�����壬$nֻ������һʹ���漴$HIC������Ѩ��$HIG�����޷����ݵľ�����ʹ��$COM\n";
			g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
			msg += "$HIM�Ƕ��ּ���$WHT��$HIY��ѣ��$WHT��\n\n$HIGֻ��$N�����ٶ�����ֱ����$n�ļ�ͷ��$nֻ������һʹ���漴$HIC���羮Ѩ��$HIG����һ����Ҵ�ʹ��$COM\n" ;
			g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
			msg += "$MAGת�Ǽ�����$WHT��$HIY�����$WHT��\n\n$HIGֻ��$N�������ϣ������ֳ�����Ȼ�������ܵĴ���$n����ף�$nֻ����΢һʹ���漴$HIC��ӿȪѨ��$HIG����һ�������ʹ��$COM\n";
			g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
			msg += "$YEL��ת�Ķ���$WHT��$HIY��Ȩ��$WHT��\n\n$HIGֻ��$N�������ǣ���ֱ����$n�����壬$nֻ�����ϱ�һ���Ҵ̣��漴�е�$HIC��������Ѩ��$HIG����һ�������ʹ��$COM\n";
			g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
			msg += "$HIB�������У�$WHT��$HIY�����$WHT��\n\n$HIGֻ��$N����ƫ�棬��ֱ����$n�����࣬$nֻ������һ�����漴$HIC������Ѩ��$HIG��Ȼ���Ѫ����$COM\n";
			g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
			msg += "$RED�Ǿ�������$WHT��$HIY������$WHT��\n\n$HIGֻ��$N�������ϣ����϶��´���$n��ͷ����$nͻȻ����ȫ�������������漴��Ѩ$HIC���ٻ�Ѩ��$HIG��Ȼ��ʹ�ޱȣ�$COM\n";
			g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
			msg += "$HIR��ת���ƣ�$WHT��$HIYҥ����$WHT��\n\n$HIGֻ��$N������������������������$n�������㣬�ཫ$n�ĵ�һ��Ѩ$HIC��̫��Ѩ��$HIG��������Ѫ����$COM\n";
			g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
			message_vision("$WHT\n$N�������ǣ��ս�ͦ�����У�һ�����߷緶��Ȼ�������·��������$n�Ĵ��ڡ�$COM\n",me,target);        
			me->add("mp", -300);
			me->start_busy(5);
			return 1;
		}
	}
	message_vision(msg.c_str(), me, target);
	
	return 1;
}

static int do_kuangjian(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	string msg;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	if( me->query_skill("murong_jianfa",1) < 200) 
		return notify_fail("���Ľ�ݽ������������죡");
	
	if( !target || !me->is_fighting(target) )
		return notify_fail("�ۿ콣��ֻ�ܶ�ս���еĶ���ʹ�á�");
	
	if ( me->query("mp")<150)
		return notify_fail("�������������"); 
	
	me->add("mp",-150);
	weapon = me->query_weapon();
//	message_vision("$HIM$Nʹ��Ľ�ݽ����еľ��Уۿ콣�ݣ�һ���������������е�"+weapon->name()+"�������$n������һ����$COM\n\n" ,me,target);
	message_vision("$HIM$Nʹ��Ľ�ݽ����еľ��Уۿ콣�ݣ�һ�������������������$n������һ����$COM\n\n" ,me, target);
	
	if (random( me->query_skill("dodge", 1)/2)>random( target->query_skill("dodge")/5 ) )
	{
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK); 
		message_vision("$HIW��ɽ----------------������$COM\n" ,me,target);
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
		message_vision("$HIC̩ɽ----------------������$COM\n" ,me,target);
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
		message_vision("$HIR��ɽ----------------���񽣣�$COM\n" ,me,target);
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
		message_vision("$HIY��ɽ----------------������$COM\n" ,me,target);
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
		message_vision("$HIB��ɽ----------------������$COM\n" ,me,target);
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
		
		message_vision("$WHT$N�������������$n�����˸���æ���ң�$COM\n" ,me,target);
		me->start_busy(5);
	} 
	else 
	{ 
		message_vision("$HIC����$n������$N����ʽ,�û�����������$COM\n" ,me,target);
		me->start_busy(2);
	}        
	return 1;
}

static int do_lianhuan(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
    
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	int i=me->query_skill("murong_jianfa",1)/5;
	int j=me->query_skill("canhe_zhi",1)/5;
	int d=me->query_skill("shenyuan_gong",1)/5;
	
	if( !target || !me->is_fighting(target) )
		return notify_fail("�߽�����ָֻ�ܶ�ս���еĶ���ʹ�á�");                
	
	if( me->query_skill("murong_jianfa", 1) < 100 )
		return notify_fail("��Ľ�����δ���ɣ�����ʹ���߽�����ָ��");
	
	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("������û�н����޷�ʹ���߽�����ָ��");
	
	if( me->query_skill("canhe_zhi", 1) < 100 )
		return notify_fail("���ָ����δ���ɣ�����ʹ���߽�����ָ��");
	
	if(DIFFERSTR(me->query_skill_mapped("finger"), "canhe_zhi") )
		return notify_fail("��û����ָ���޷�ʹ���߽�����ָ��");
	
	if( me->query("mp") < 500 )
		return notify_fail("�������������㣬����ʹ���߽�����ָ��");
	
	if( me->query_temp("lianhuan"))
		return notify_fail("������ʹ���߽�����ָ��"); 
	
	if( me->query_skill("sword", 1) < 100 )
		return notify_fail("��Ļ�������������죬�����ڽ�����ʹ���߽�����ָ��");
	
	if( me->query_skill("finger", 1) < 100 )
		return notify_fail("��Ļ���ָ��������죬�����ڽ�����ʹ���߽�����ָ��");
	
	message_vision("\n$MAG$Nʹ���߽�����ָ������һת������ʳָ���ŵ�����ֻ������ָ�������ӳ��ֱϮ$n��$COM\n", me,target);
	me->add("mp", -50); 
	me->set_temp("lianhuan", 2+me->query_skill("murong_jianfa", 1)/40);
	me->add_temp("apply/attack", (i+j)/3*2);
	me->add_temp("apply/damage", d);
	me->call_out(check_fight, 1);
	
	return 1;
}

static void remove_effect(CChar * me)
{
	int i=me->query_skill("murong_jianfa",1)/5;
	int j=me->query_skill("canhe_zhi",1)/5;
	int d=me->query_skill("shenyuan_gong",1)/5;   
	me->add_temp("apply/attack", -(i+j)/3*2);
	me->add_temp("apply/damage", -d);
	me->delete_temp("lianhuan");
}

static void check_fight(CContainer * me, LONG param1, LONG param2)
{
	CChar * ob = (CChar * )me;
	
	if (!ob) return;
	
	if (!ob->is_fighting()||!ob->query_temp("lianhuan"))
	{
		tell_object(ob, "$HIY��ġ��߽�����ָ������������ϣ����ص���,�����չ�$COM");
		remove_effect(ob);
		return;
	}
	
	if (DIFFERSTR(ob->query_skill_mapped("finger"), "canhe_zhi")
		||DIFFERSTR(ob->query_skill_prepared("finger"), "canhe_zhi") )
		
	{
		tell_object(ob, "$COM����ʱ�Ļ��书,��������ʹ�á��߽�����ָ������$COM");
		remove_effect(ob);
		return;
	}
	
	if(DIFFERSTR(ob->query_skill_mapped("parry"), "canhe_zhi") )		
		if(DIFFERSTR(ob->query_skill_mapped("parry"), "murong_jianfa"))
		{
			tell_object(ob, "$HIR����ʱ�Ļ��书,��������ʹ�á��߽�����ָ������$COM");
			remove_effect(ob);
			return;
		}		
		ob->call_out(check_fight, 1);
}

SKILL_END;