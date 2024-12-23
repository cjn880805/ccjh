//missblade.h ��˼����

SKILL_BEGIN(CSmissblade);

virtual void create()
{
	set_name( "��˼����");

	Magic_t * magic;

	magic = add_magic("xiangsi", do_xiangsi);
	magic->name = "��˼��";
	magic->mp = 250;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int  damage, force,  parry, lvl;
	}action[7] = {
		{"$Nʹһ�С����������������$w��ƮƮ����$n��$lնȥ��",
		30, 10, 10, 0,},
		{"$N�������磬$w����һ�С�Զɽ���˳ա����¶�������$n��$l",
		60,15,20,20,},
		{"$N����һת��һ�С��ɻ������㡹$w���ⲻ����ն��$n��$l",
		80,30,30,40,},
		{"$N�趯$w��һ�С���Ҷ����Ц��Ѹ�����׵�����$n��$l",
		120,45,	40, 60,},
		{"$N����$wһ�Σ�һ�С�ٻӰ����������$n��$lбб����һ��",
		160,60,50,80,},
		{"$N�ᵶ���磬�������һ�С�«ѩ����Ӱ��ֱ��$n$l",
		200,75,60,100,},
		{"$N�Ʋ�����ʹһ�С��ʵ������¡��������ն��$n��$l",
		240,90,70,120,},
	};
 
  	int level = me->query_skill("missblade", 1);
	for(int i = 7; i > 0; i--)
		if( action[i - 1].lvl < level)
		{
			level = random(i);
	
			m_actions.set("action", action[level].action);
			m_actions.set("damage", action[level].damage);
			m_actions.set("force", action[level].force);
			m_actions.set("parry", action[level].parry);
			break;
		}
			
	return & m_actions;
};

const char * query_parry_msg(CContainer *weapon)
{
	static char parry_msg[][255] ={
		"$nʹһ�С����������������$w��ƮƮ����$N��$lնȥ��",	
		"$n�������磬$w����һ�С�Զɽ���˳ա����¶�������$N��$l",
		"$n����һת��һ�С��ɻ������㡹$w���ⲻ����ն��$N��$l",
		"$n�趯$w��һ�С���Ҷ����Ц��Ѹ�����׵�����$N��$l",
		"$n����$wһ�Σ�һ�С�ٻӰ����������$N��$lбб����һ��",
		"$n�ᵶ���磬�������һ�С�«ѩ����Ӱ��ֱ��$N$l",
		"$n�Ʋ�����ʹһ�С��ʵ������¡��������ն��$N��$l",
	};

	if(! weapon) return 0;
	return parry_msg[random(7)];
}

virtual int valid_enable(string usage) { return (usage == "blade") || (usage == "parry"); }

virtual int valid_learn(CChar * me)
{
	if( DIFFERSTR(me->querystr("gender"), "Ů��") )
		return notify_fail("��˼����ֻ��Ů�Ӳ�������");

	if(me->query("max_mp") < 50)
		return notify_fail("�������������û�а취����˼������");

	if(DIFFERSTR(me->query_skill_mapped("force"), "bingxin_jue"))
		return notify_fail("��˼����������ϱ��ľ���������");
	
	CContainer * weapon;

	if( !(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "blade") )
		return notify_fail("���������һ�ѵ�������������");

	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if( DIFFERSTR(me->query_skill_mapped("force"), "bingxin_jue"))
		return notify_fail("��˼����������ϱ��ľ���������");

	if( !(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "blade") )
		return notify_fail("���������һ�ѵ�������������");

	if( me->query("hp") < 30
		||	me->query("mp") < 5 )
		return notify_fail("�����������������û�а취��ϰ��˼������");

	me->receive_damage("hp", 25);
	me->add("mp", -5);
	message_vision("$HIG$N����˼֮������һ����˼������", me);
	return 1;
}

static int do_xiangsi(CChar * me, CContainer * ob)
{
	CContainer * weapon = me->query_weapon();
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	string msg;

	if( !target || !me->is_fighting(target) )
		return notify_fail("����˼�᡹ֻ�ܶ�ս���еĶ���ʹ�á�");

	if (me->query_skill("blade") < 100)		
		return notify_fail("�����˼�������������죡");

	if (! weapon || DIFFERSTR(weapon->querystr("skill_type"), "blade"))
		return notify_fail("��ʹ�õ��������ԡ�");

	if (me->query("mp") < 250)
		return notify_fail("�����������!");

	if(me->query_temp("using") == 1)
		return notify_fail("������ʹ�á���˼�᡹��");
		
	message_vision("$HIC$N�յ�����,�����峪��������\n\n", me);
	me->start_busy(1);
	me->set_temp("using",1);
	target->start_busy(1);
	
	me->call_out(yearn2, 1, target->object_id());
	return 1;	
}			

static void remove_effect(CChar * me)
{
	if (me->query_temp("missblade/add1"))
	{
		me->add_temp("apply/attack", -me->query_skill("blade")/4);
		me->delete_temp("missblade/add1");
	}

	if (me->query_temp("missblade/add2"))
	{
		me->add_temp("apply/damage", -me->query_skill("blade")/4);
		me->delete_temp("missblade/add2");
	}
}

static void yearn2(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * target = (CChar *)(me->environment())->Present(param1);

	if(!target || ! me->is_fighting(target)) return;

	message_vision("$YELֻ������˼,��˼������,\n", me);
	
	//if (random(target->query_skill("music",1))<random(me->query_skill("music",1)))
	//target->receive_damage("sen", 10);

	target->start_busy(1);
	me->start_busy(1);
	me->call_out(yearn3, 1, param1);
}

static void yearn3(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * target = (CChar *)(me->environment())->Present(param1);

	if(!target || ! me->is_fighting(target)) return;

	message_vision("$YEL������˼��,������˼��......\n", me);
	//if (random(target->query_skill("perception",1))<random(me->query_skill("music",1)))
	//target->receive_damage("sen", 10);

	target->start_busy(1);
	me->start_busy(1);
	me->call_out(yearn4, 1, param1);
}

static void yearn4(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * target = (CChar *)(me->environment())->Present(param1);

	if(!target || ! me->is_fighting(target)) return;
	
	message_vision("$HIWȻ��$n�ͼ���һ�����⣡\n$WHT���⵭��,����ȽȽ����һ����......\n$HIY��һ������δ��......\n$YEL��ɫ����,��Զɽ����ü,Ϧ��������\n$YEL�������,�ƻ�ȫϨ,˭Ҳ������˭\n$CYNֻ��һֻ��������\n$HIC������������,��һֻ�������ں�Ҷ��,������һ��¶�顣\n$HIC����ӳ�����,���ӳ��$N���������,�����������\n$HIC$N���ڵ�������У���ӯ��ʫ���������Ρ�\n$HIW�������һƬ����һ�����Ʈ�������˾�Ȼ----���������ˡ�!\n", me, target);
	
	if (random(target->query_skill("force")) < random(me->query_skill("force")) )
	{
		me->add_temp("apply/attack", me->query_skill("blade")/4);
		me->set_temp("missblade/add1", 1);		
	}
	
	if (random(target->query_skill("dodge")) < random(me->query_skill("missblade",1)))
	{
		me->add_temp("apply/damage", me->query_skill("blade")/4);
		me->set_temp("missblade/add2", 1);
	}

	target->start_busy(1);
	me->start_busy(1);
	
	if (random(2)==1) 
	{
		me->delete_temp("using");
	}
	
	me->call_out(yearn5, 1, param1);
}

static void yearn5(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * target = (CChar *)(me->environment())->Present(param1);

	if(!target || ! me->is_fighting(target)) 
	{
		remove_effect(me);
		return;
	}

			
	message_vision("$HIC$N̾Ϣ����,\n$HIY������һ�׶��˵�ʫ,\n$RED�����Ρ�\n$BLU���ﻨ�䡣\n$HIR���ﻨ��֪���٣�\n$HIW----�����ﻨ�䡹������һ��!\n", me, target);
	
	Do_Attack(me, target, TYPE_REGULAR);
	
	remove_effect(me);

	me->call_out(yearn6, 1, param1);	
}

static void yearn6(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * target = (CChar *)(me->environment())->Present(param1);

	if(!target || ! me->is_fighting(target)) 
	{
		remove_effect(me);
		return;
	}

	me->delete_temp("using");
	
	message_vision("$HIB$Nһ���ӳ�����һ�����µ��κۡ�\n$HIC�����㵶��������ۣ������ü��\n$HIY�����ĵ�Ӱ�������˵�ٻӰ�������𣬴���΢΢������������,\n$HIY���䴦���ӵ���磬����ʱ������Щ������绪��\n$HIC----�����ޡ�\n----һ���������Ӱ��\n----һ�Ѿ��޵ĵ���\n$HIMһʽ���仨��Ӱ����",me,target);
	
	LONG ap = me->query("combat_exp")/2000 + me->query_skill("missblade",1);
	LONG dp = target->query("combat_exp") / 4000  ;
	
	if( dp < 1 )
		dp = 1;
		
	if( random(ap) > dp )
	{
		message_vision("$HIR$n�Բ����񣬱�����ɨ��һ�¡�������ӳһƬѪ�졣\n",me,target);
		target->receive_damage("hp", random(ap * 2 - dp));
		target->receive_wound("hp", random(ap));
		me->add("mp", -200);
	}
	else 
	{
		message_vision("$HIR$n��֮�£�һ����¿���������һ�ԣ���Ȼ��ͷ���������������ˡ�\n",me,target);
		
		remove_effect(me);

		me->start_busy(random(2)+1);
		return;
	}

	me->call_out(yearn7, 1, param1);
}

static void yearn7(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * target = (CChar *)(me->environment())->Present(param1);

	if(!target || ! me->is_fighting(target)) 
	{
		remove_effect(me);
		return;
	}

	LONG damage = me->query_skill("dodge") - target->query_skill("dodge") + me->query_skill("blade") - target->query_skill("force");		
	
	if (damage<1)damage=1;
	
	message_vision("$HIR$Nһ�����������Ƕ��ġ�\n$HIR$N��պ�糣��ܺ죬���ޣ���ƽ�����룬��㼣������ˡ�\n$HIB����ٿû��\n$HIW��������̫�죬������̫���ᡣ\n$HIG��ľ���һ��΢�磬��ľ���һĨ��ɫ:�������ޱߡ�!\n$MAG$n������ô����ô����ô����ĵ���,һʱҲ��ֻ����ε�����\n",me,target);
	
	if( random(me->query("combat_exp")/250) > target->query("combat_exp")/400)
	{
		target->receive_damage("hp", damage );
		target->receive_wound("hp", random(damage));
		me->add("mp",-150);
		message_vision("$HIY���$n������˼����������,�����԰Ρ�\n", me, target);
	}
	else 
	{
		message_vision("$HIY����$n�����ϵ�,�鼱֮��,���ִ����Լ�һ�£������������ɱ����\n",me,target);
		target->receive_damage("hp", 10);
	}
	
	me->call_out(yearn8, 1, param1);	
}

static void yearn8(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * target = (CChar *)(me->environment())->Present(param1);

	if(!target || ! me->is_fighting(target)) 
	{
		remove_effect(me);
		return;
	}
	
	message_vision("$HIY�����������£������ջأ�\n$HIW������$N���У�\n", me, target);
	remove_effect(me);
	me->start_busy(random(3)+2);
}

SKILL_END;

