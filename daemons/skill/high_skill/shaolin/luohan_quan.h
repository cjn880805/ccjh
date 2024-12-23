SKILL_BEGIN(CSluohan_quan);

virtual void create()
{
	set_name( "�޺�ȭ");

	Magic_t * magic;

	magic = add_magic("foxue", do_foxue);
	magic->name = "������ɱֹɱ";
	magic->mp = 300;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "hunyuan_yiqi") || EQUALSTR(arg, "yijinjing"))
		return 1;

	return notify_fail("�޺�ȭ���������ֶ����ڹ����ʹ�á�");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	static struct {
		char action[255];
		int force, dodge, lvl;
	}action[8] = {
		{"$N�����ϲ���һʽ����ݺ��ܡ��������ַֿ�����ȭΪ�ƣ�����$n��$l",
			180, 5, 0,},
		{"$N�����̤��ȫ����ת��һ�С����ﳯ�����������͵ز���$n��$l",
		200, 10, 8,},
		{"$N˫�ִ󿪴��أ����߾٣�ʹһ�С����Ӷ�Ӧ����˫ȭ��$n��$l��ȥ",
		220, 15, 15,},
		{ "$N����Ȧ���������⵱�أ����ڳ��ϣ�һ�С�ƫ�����ǡ�����$n��$l",
		260, 20, 24,},
		{ "$Nʹһ�С��ຣ��ͷ��������ǰ̽��˫�ֻ��˸���Ȧ������$n��$l",
		300, 25, 33,},
		{ "$N˫�ƻ�����һ�ǡ�Юɽ���������Ƴ���磬һ�����е�$n������",
		360, 30, 42,},
		{"$Nʩ��������������˫ȭȭ����磬ͬʱ����$nͷ���أ�������Ҫ��",
		420, 35, 50,},
		{ "$N����ڿۣ�����������һʽ�������������˫�����밴��$n���ؿ�",
		480, 40, 58,},
	};

	int level = me->query_skill("luohan_quan", 1);
	for(int i = 8; i > 0; i--)
		if(level > action[i-1].lvl)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
		
			break;
		}

	if (me->query_temp("teapot/yishazhisha")==1)
		m_actions.set("action","$HIGɱ��");
	if (me->query_temp("teapot/yishazhisha")==2)
		m_actions.set("action","$HIYɱ������");
	if (me->query_temp("teapot/yishazhisha")==3)
		m_actions.set("action","$HIRɱ��������������$GRN");

	return & m_actions;
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 30)
		return notify_fail("�������̫���ˡ�");
	if ((int)me->query("mp") < 20)
		return notify_fail("��������������޺�ȭ��");
	me->receive_damage("hp", 25);
	me->add("mp", -5);
	return 1;
}

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon() )
		return notify_fail("���޺�ȭ������֡�");
	if (me->query_skill("hunyuan_yiqi", 1) < 10)
		return notify_fail("��Ļ�Ԫһ������򲻹����޷�ѧ�޺�ȭ��");
	if (me->query("max_mp") < 50)
		return notify_fail("�������̫�����޷����޺�ȭ��");
	return 1;
}

virtual int valid_enable(string usage) {return usage=="cuff" || usage=="parry"; }


static int do_foxue(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
//	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if(! target || ! me->is_fighting(target))
		return notify_fail("ֻ�ܶ�ս���еĶ���ʹ�á�");

	if(DIFFERSTR(me->query_skill_prepared("cuff"),"luohan_quan"))
		return notify_fail("��׼���޺�ȭ������ʹ����������ɱֹɱ��!");

	if(me->query_skill("hunyuan_yiqi",1) < 200)
		return notify_fail("���Ԫһ�����Ĺ�������ʹ�á�������ɱֹɱ��!");

	if (me->query_weapon())
			return notify_fail("�㲻��ʹ��������");

	if(me->query_skill("luohan_quan",1) < 200)
		return notify_fail("���ȭ����Ϊ����,������ʹ�á�������ɱֹɱ��!");

	if(me->query("mp") < 1350)
		return notify_fail("���������ڲ���, ����ʹ�á�������ɱֹɱ��! ");

	if(DIFFERSTR(me->querystr("family/family_name"), "������") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");

	if(me->query("repute") < 500000)
		return notify_fail("���ɱ������, ����ʹ�á�������ɱֹɱ��! ");


	message_vision("$CYN\n$N������ʮ�����������˴ȱ�Ϊ�����������ƣ�аħ�����������ɱֹɱ��",me);
	message_vision("$HIC˵����һ��ͷ�����һ����",me);

	int i;
	i=me->query_str();

	me->add_temp("apply/str",i/3);
	me->set_temp("teapot/yishazhisha",1);
	g_Combatd.Do_Attack(me,target,CCombatd::TYPE_QUICK);
	me->add_temp("apply/str",-i/3);

	me->add_temp("apply/str",i*2/3);
	me->set_temp("teapot/yishazhisha",2);
	g_Combatd.Do_Attack(me,target,CCombatd::TYPE_QUICK);
	me->add_temp("apply/str",-i*2/3);

	me->add_temp("apply/str",i*4/3);
	me->set_temp("teapot/yishazhisha",3);
	g_Combatd.Do_Attack(me,target,CCombatd::TYPE_QUICK);
	me->add_temp("apply/str",-i*4/3);
	me->delete_temp("teapot/yishazhisha");

	me->add("mp",-1350);
	me->start_busy(6);

	return 1;
}

virtual void skill_improved(CChar * me)
{
	int lvl = me->query_skill("luohan_quan", 1);

	if(lvl == 200)
		tell_object(me,"���书��������ľ��磬�����������ȭ��Ҳ��������Ч��ȭ��������\n���������޺�ȭ����һʽ����������ɱֹɱ����" );
}


SKILL_END;

