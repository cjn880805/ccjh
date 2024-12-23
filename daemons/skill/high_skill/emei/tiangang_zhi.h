
// tiangang_zhi.h ���ָѨ��
//code by Fisho
//date : 2000-12-02

SKILL_BEGIN(CStiangang_zhi);

virtual void create()
{
	set_name( "���ָѨ��");
	set("valid_force", "linji_zhuang");

	Magic_t * magic;

	magic = add_magic("lingkong", do_lingkong);
	magic->name = "���ָѨ";
	magic->mp = 300;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  force,dodge;
		char damage_type[5];
		int  lvl;
	}action[] = {
		{"$N�������Ღ����������ָ���쵯������һʽ��������ġ�������$n��$l", 150, 5, "����", 0, },
		{"$N˫���������䣬��������$n��һʽ��������̶�������ֻ��Ƴ�ָ����ӿϮ��$n��$l", 200, 5, "����", 12, },
		{"$N������ȭ���ƣ�����Ť�������ߣ�һʽ�����߾��ɡ������Ҳ��ã�����$n��$l", 250, 15, "����", 24, },
		{"$Nһʽ��������ɽ�������ֳ�أ�����ǰ̽���ָ����$n��$l", 300, -5, "����", 36, },
		{"$Nʹһʽ����������������Ӱ��ò���������$n����͵�����$n��$l", 350, 10, "����", 48, },
		{"$N���۴󿪴��أ���һ������һʽ���ض�ɽҡ��������͸����˫�ֿ���һ��������������������$n��$l",400 , 5, "����", 60, },
		{"$N������������Ʈ����˫�������Ķ���һʽ��ˮ�����¡����Ӹ����£����಻������$n��$l", 450, 20, "����", 72, },
		{"$N�ڿն���˫�ƺ�һ��ʮָ�繳��һ�С�̩ɽѹ����������$n�Ļ��䣬�Ƶ������Ѽ�", 500, 25, "����", 84, },
	};
	
	int level = 0;
	
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("tiangang_zhi", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			break;
		}
	}
	
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "finger") || (usage == "parry");
}

virtual int valid_combine(string combo) { return combo=="jinding_zhang"; }

virtual int valid_learn(CChar * me)
{
	CChar * who = (CChar *)(me->environment())->present(me->querystr("family/master_id"));
	if(who && who->query("add_skill/count"))
		return notify_fail("���ʦ����ʱû��ָ�����书����");

	CChar * who1 = (CChar *)(me->environment())->present(me->querystr("couple/id"));
	if(who1 && who1->query("add_skill/count"))
		return notify_fail("����ʱ�޷�ָ������µ��书����");

    if (me->query_weapon())
		return notify_fail("�����ָѨ��������֡�");
    if (me->query_skill("linji_zhuang", 1) < 20)
		return notify_fail("����ټ�ʮ��ׯ��򲻹����޷�ѧ���ָѨ����");
    if (me->query("max_mp") < 100)
		return notify_fail("�������̫�����޷������ָѨ����");
    return 1;
}

virtual int practice_skill(CChar * me)
{
    if (me->query("hp") < 30)
		return notify_fail("�������̫���ˣ��޷������ָѨ����");
    me->receive_damage("hp", 20);
    return 1;
}

static int do_lingkong(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if(! target || ! me->is_fighting(target))
		return notify_fail("ֻ�ܶ�ս���еĶ���ʹ�ã�");

	if(me->query_str() < 25)
		return notify_fail("���������,����ʹ����һ����!");
	
	if(me->query_skill("linji_zhuang",1) < 100)
		return notify_fail("���ټ�ʮ��ׯ�Ĺ�����������ʹ�����ָѨ!");
	
	if(me->query_skill("finger") < 100)
		return notify_fail("���ָ����Ϊ����,Ŀǰ������ʹ�����ָѨ����!");
	
	if(me->query("mp") < 300)
		return notify_fail("���������ڲ���, ����ʹ�����ָѨ! ");

	if(DIFFERSTR(me->querystr("family/family_name"), "������") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if( target->is_busy() )
		return notify_fail( "%sĿǰ���Թ˲�Ͼ���ŵ������� ",target->name());
	
	msg = "$Nʹ�����ָѨ�����������ָѨ�����ع������������������۾�һ�㣬����ʳ�ж�ָ��$n������ȥ��һ����ָ��ȫ�Ƕ���$n��ͷ����ǰ����Ѩ��$n�������У�ƴ�����$Nָ����ʱ�������ҡ�\n";
	if( random(me->query_combat_exp() + 1) > target->query_combat_exp() / 4 )
	{
		msg +=   "���$n��$Nָ�����м���Ѩ��! " ;
		target->start_busy( me->query_skill("tiangang_zhi",1) / 20 + 2);
		me->add("mp", -100);
	}
	else
	{
		msg +=  "$n�鼱����������һԾ���˳���Զ��" ;
		me->start_busy(4);
	}
	message_vision(msg.c_str(), me, target);
	
	return 1;
	
}

SKILL_END;




