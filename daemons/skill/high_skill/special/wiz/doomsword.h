// doomsword.h ���ǽ���
//code by Teapot
//date : 2001-02-07

SKILL_BEGIN(CSdoomsword);

virtual void create()
{
	set_name( "���ǽ���");

	Magic_t * magic;

	magic = add_magic("zhuang", do_zhuang);
	magic->name = "���°˽�";
	magic->mp = 500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  force,dodge,lvl;		
	}action[5] = {
		{"$Nʹ�����ǽ����о�ɱһʽ�����г���һ������ֱ�̳���",500 , 5, 0},
		{"$N��һ����һ�С�ѩ�����ǡ��ó�һƬ��Ӱɢ����", 500, 10, 10},
		{"$N�����ת��һ�С���ɲ���ǡ������������",500 , 15, 20,},
		{"$N��Ӱ�ζ�����Ӱ������ң�һ�С��������ǡ�����·ֱ��������", 500, 20, 30},
		{"$N˫�ŵ�أ����е�ת�������ĳ����������ǽ�������֮�ܡ��ϼ���", 500,25 , 40},
	};

		struct {
		char action[255];
		int  force,dodge,lvl;		
	}action2[8] = {
		{"$HIG$N˫������$w����â������һʽ����˫�޶ԡ���Ԧ�����Ҿ��׵���$n��̣�", 300, -25, 40},
		{"$HIB$Nʹ�������ؽ�ʽ�С����������������������������$w��������������������$n��", 300, -25, 40},
		{"$HIR$N��֦�Ͱڣ�$n��ǰ�·�ͻȻ�������߰˸�$N���߰�ֻ$wһ�����$n��", 300, -25, 40},
		{"$HIW$N�ٽ�������ĬǱ���¾Ž�֮���ƽ�ʽ�������ལ�⣬�����̵�Ϯ��$n��", 300, -25, 40},
		{"$HIC$Nʹ���������������������Х���������������$n��", 300, -25, 40},
		{"$CYN$Nʹ��ȫ���ɾ�����һ�������塹������Ȼ�ӿ�,���ս����γ�������������$n��", 300, -25, 40},
		{"$HIY$Nʹ����Ħ���ľ�������Ħ��������������Ȼ�ӿ죬����������", 300, -25, 40},
		{"$YEL$N����һ����һʽ���ƺ����롹���������佣����������$n��", 300, -25, 40},
	};

	int level = 0;
	
	for(int i=5; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("doomsword", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			break;
		}
	}

	int j;
	j=me->query_temp("teapot/perform_tianxiabajian");
	if (j)
	{
			m_actions.set("action", action2[j-1].action);
			m_actions.set("force", action2[j-1].force);
			m_actions.set("dodge", action2[j-1].dodge);
			me->add_temp("teapot/perform_tianxiabajian",1);
	}


	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "sword") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
	return 0;
	// Disable Learn.
}

virtual int practice_skill(CChar * me)
{
	return 0;
	// Disable Practice.
}

//perform 

static int do_zhuang(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	char msg[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

 	if( !target || !me->is_fighting(target) )
		return notify_fail("���°˽��޷�ʹ�á�");
	
	if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("���°˽��޷�ʹ�á�");
	
	if( me->query("mp") < 5 )
		return notify_fail("�������������");
	
	snprintf(msg ,255,"\n$WHT$N������ͨ�������ǽ������������°˽���һ���ǳɣ�"  );
	message_vision(msg, me);

	me->set_temp("teapot/perform_tianxiabajian",1);

	snprintf(msg ,255,"\n$HIG��Ů����"  );
	message_vision(msg, me);
	g_Combatd.Do_Attack(me, target,  CCombatd::TYPE_QUICK);

	snprintf(msg ,255,"\n$HIB��������"  );
	message_vision(msg, me);
	g_Combatd.Do_Attack(me, target,  CCombatd::TYPE_QUICK);

	snprintf(msg ,255,"\n$HIR��а����"  );
	message_vision(msg, me);
	g_Combatd.Do_Attack(me, target,  CCombatd::TYPE_QUICK);

	snprintf(msg ,255,"\n$HIW���½���"  );
	message_vision(msg, me);
	g_Combatd.Do_Attack(me, target,  CCombatd::TYPE_QUICK);

	snprintf(msg ,255,"\n$HIC���Ͻ���"  );
	message_vision(msg, me);
	g_Combatd.Do_Attack(me, target,  CCombatd::TYPE_QUICK);

	snprintf(msg ,255,"\n$CYNȫ�潣��"  );
	message_vision(msg, me);
	g_Combatd.Do_Attack(me, target,  CCombatd::TYPE_QUICK);

	snprintf(msg ,255,"\n$HIY��Ħ����"  );
	message_vision(msg, me);
	g_Combatd.Do_Attack(me, target,  CCombatd::TYPE_QUICK);

	snprintf(msg ,255,"\n$YEL���｣��"  );
	message_vision(msg, me);
	g_Combatd.Do_Attack(me, target,  CCombatd::TYPE_QUICK);

	
	me->delete_temp("teapot/perform_tianxiabajian");
	
	me->add("mp", -5);
	me->start_busy(random(3));	// 8 Hits and busy r.d.3,the best multi-strike perform.
	
	return 1;
	
}

SKILL_END;
