// lovesword.h ������Ӱ��
// Coded by Teapot
// Create @ 2001-02-20
// Last Modify @ 2001-02-20


SKILL_BEGIN(CSlovesword);

virtual void create()
{
	set_name( "������Ӱ��");

	Magic_t * magic;

	magic = add_magic("crazy", do_crazy);
	magic->name = "����ն";
	magic->mp = 500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("suicidal", do_suicidal);
	magic->name = "����";
	magic->mp = 0;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("suicidalb", do_suicidalb);
	magic->name = "����";
	magic->mp = 0;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int force, dodge, parry, damage, lvl;
	}action[3] = {
		{"$N΢΢һЦ��Ц����˵��������٬������$wһ�ӣ�������$n��һƬ�½ǡ�", -1000,-100,-100,-3000,0,},
		{"$N΢΢һЦ��Ц����˵��������٬������$wһ�ӣ�������$n��һ��ͷ����", -1000,-100,-100,-3000,0,},
		{"$N΢΢һЦ��Ц����˵��������٬������$wһ�ӣ���$n�Ǽ��ӹ���", -1000,-100,-100,-3000,0,},
	};
	int level;
	level=random(3);
	m_actions.set("action", action[level].action);
	m_actions.set("force", action[level].force);
	m_actions.set("dodge", action[level].dodge);
	m_actions.set("parry", action[level].parry);
	m_actions.set("damage", action[level].damage);

	return & m_actions;
};

const char * query_parry_msg(CContainer *weapon)
{
	static char parry_msg[6][255] ={
		"$n����ͻȻ���ֳ�һƬ����������$N���������֡�",
		"$n��ͷ��̾һ�����������ܣ�$Nһ㶣�ĬĬͣ�֡�",
		"$n������$N���е�ȥ��$Nֻ��ͣ�����ӡ�",
		"$n�����ã��ã��㡭�����۸��ң���˵������Ȧ�Ѿ����ˣ�$Nһ㶣�ͣ�ֲ�����",
		"$n����������һҹ���ް��ն�����ҹ���޺������$N��������һ���˸У�����ͣ����ʽ��",
		"$nʲôҲ��˵�������峺��ˮ��Ŀ�⿴��$N��$N����ǧ�ذ�ת������$n��ȥ�ĺ�����",
	};

	return parry_msg[random(6)];
}

virtual int valid_enable(string usage) { return usage=="sword" || usage=="parry" ; }

virtual int valid_learn(CChar * me)
{
	return 0;
}

virtual int practice_skill(CChar * me)
{
	return 0;
}


static int do_crazy(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target ||! me->is_fighting(target) )
		return notify_fail("����նֻ�ܶ�ս���еĶ���ʹ�á�");

	if( !target->Query(IS_LIVING))
		return notify_fail("����û�б�Ҫʹ������ն������Ҳ��������");

	 if (me->is_busy() || me->query_temp("pending/exercising"))
	   return notify_fail("��������æ���ء�");

	if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��ʹ�õ��������ԡ�");	// frost blade cast only.


	if( me->query("mp") < 500)	
		return notify_fail("�������������ʹ������ն��");

	int i;
	i=me->query("mp")/2;
	me->add("mp",-i);
	
	message_vision("$N΢΢һЦ�����н�ͻȻ�ӳ������д�������֮������ʱ$n����˷���������������Ҳ���������ݺ��ǳ������$n��Ȼ��������",me,target);

	return 1;
}

static int do_suicidal(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target ||! me->is_fighting(target) )
		return notify_fail("����ֻ�ܶ�ս���еĶ���ʹ�á�");

	if( !target->Query(IS_LIVING))
		return notify_fail("����û�б�Ҫʹ�����С���");

	 if (me->is_busy() || me->query_temp("pending/exercising"))
	   return notify_fail("��������æ���ء�");

	if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��ʹ�õ��������ԡ�");	// frost blade cast only.


	if( me->query("max_mp") < 5000 && !me->query("env/yesiknow") )
		return notify_fail("�������������ʹ�����С�");

//	int i;
//	i=me->query("mp")/2;
	if( !me->query("env/yesiknow") )
		me->add("max_mp",-5000);

	//Modified by Lanwood 2001-03-10
	//Begin----
	me->start_busy(3);
	target->start_busy(3);
	me->call_out(do_suicide, 2, target->object_id(), 0);
	return 1;
}

static void do_suicide(CContainer * ob, LONG param1, LONG step)
{
	static struct
	{
		char msg[255];
		int delay;
	} describe[20] =
	{
		//����
		{"���������С�", 4,},
		{"���˼���ͬʱ�����֣�$n���ٶȺÿ죬��$N��$N��$N�㿪�ˡ�", 4,},
		{"��$N����������ȥ�ˣ�$N�����������ˣ�$N����ʹ�������С�\n$n��һֻ�ֵ����˵أ���ɫ��û�б䣬�ú��ӣ�", 4,},
		{"$N�����ֳ���һ����������$n�Ľ��ϡ�\n���⴩��$n�Ľš�", 4,},
		{"�ú��ӣ�$n��Ȼ��$N����һ�У�\n$n�·����ˣ�", 4,},
		{"$N�ٴο�����$n��һֻ�š�\n$n��Ȼ���˹���һ����", 4,},
		{"$Nû��ʱ���ٱ���$n�Ǻú��ӡ�\n$N�����˰�ʮһ����ÿһ������ʣ�µ�$n�ֳ����飡", 2,},
		{"...", 8,},
		{"$Nת���뿪���紵��$N��ͷ����$N��������$n��ͷ��", 1,},
		{"��Ȼ�䣬$N����$N��ͷ�뿪�����壬$N����л�ͷ����һ�£�ԭ�������$nʣ�µ�һֻ�ֻ����ŵ�������\n������������������������ ",	1, },
		
		//����
		{"���������С�", 4,},
		{"���˼���ͬʱ�����֣�$n���ٶȺÿ죬��$N��$N��$N�㿪�ˡ�", 4,},
		{"��$N����������ȥ�ˣ�$N�����������ˣ�$N����ʹ�������С�\n$n��һֻ�ֵ����˵أ���ɫ��û�б䣬�ú��ӣ�", 4},
		{"$N�����ֳ���һ�У�������$n�Ľ��ϡ����⴩��$n�Ľš�", 4,},
		{"�ú��ӣ�$n��Ȼ��$N����һ�У�\n$n�·����ˣ�", 4},
		{"$N�ٴδ����$n��һֻ�š�\n$n��Ȼ���˹���һ����", 4},
		{"$Nû��ʱ���ٱ���$n�Ǻú��ӡ�\n$Nʹ���˰�ʮһ�С�ÿһ�ж���$n�ֳ����룡", 2},
		{"...", 8,},
		{"$Nת���뿪���紵��$N��ͷ����$N��������$n��ͷ��", 1,},
		{"��Ȼ�䣬$N����$N��ͷ�뿪�����壬$N����л�ͷ����һ�£�ԭ�������$nʣ�µ�һֻ�ֻ�����һ�ѵ�������\n������������������������ ", 1,},
	};
	
	CChar * me = (CChar *)ob;
	CChar * target = (CChar *)(me->environment())->Present(param1);

	if(! target) return;

	me->start_busy(describe[step].delay + 1);
	target->start_busy(describe[step].delay + 1);

	message_vision(describe[step].msg, me, target);
	
	if(step == 9 || step == 19)
	{
		me->receive_damage("hp", 1, target);
		target->receive_damage("hp", 1, me);
		target->die();
		me->die();
		return;
	}
	
	me->call_out(do_suicide, describe[step].delay, param1, step + 1);
}

static int do_suicidalb(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target ||! me->is_fighting(target) )
		return notify_fail("����ֻ�ܶ�ս���еĶ���ʹ�á�");

	if( !target->Query(IS_LIVING))
		return notify_fail("����û�б�Ҫʹ�����С���");

	 if (me->is_busy() || me->query_temp("pending/exercising"))
	   return notify_fail("��������æ���ء�");

	if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��ʹ�õ��������ԡ�");	// frost blade cast only.


	if( me->query("max_mp") < 5000)
		return notify_fail("�������������ʹ�����С�");

//	int i;
//	i=me->query("mp")/2;
	me->add("max_mp",-5000);

	me->start_busy(3);
	target->start_busy(3);
	me->call_out(do_suicide, 2, target->object_id(), 12);
	
	return 1;
}



SKILL_END;
