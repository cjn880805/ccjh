// poyu_quan.h ��ʯ����ȭ
//code by Fisho
//date : 2000-12-06

SKILL_BEGIN(CSpoyu_quan);

virtual void create()
{
	set_name( "��ʯ����ȭ");
	set("valid_force", "zixia_shengong");

	Magic_t * magic;

	magic = add_magic("leidong", do_leidong);
	magic->name = "�׶�����";
	magic->mp = 500;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  force,dodge,lvl;
		char damage_type[5];
	}action[] = {
		{"$N�ҽ������������㣬һʽ������ʽ����������һ��һ�ͣ�����$n��$l",180 , 5, 0,"����",},
		{"$N�����̤��ȫ����ת��һ�С�ʯ���쾪������ȭ�͵ػ���$n��$l", 200, 10, 10,"����",},
		{"$N˫�ִ󿪴��أ����߾٣�ʹһ�С����ź��š���˫ȭ��$n��$l��ȥ",220 , 15, 20,"����",},
		{"$N����Ȧ���������⵱�أ����ֻ��ڳ��ϣ�һ�С�ǧ��׹�ء�����$n��$l", 260, 20, 30,"����",},
		{"$Nʹһ�С�����������������ǰ̽��˫ȭ���˸���Ȧ������$n��$l", 300,25 , 40,"����",},
		{"$N˫ȭ������һ�ǡ����ֿβ�����Ƴ���磬һ�����е�$n������", 360, 0, 50,"����",},
		{"$Nʩ��������֡���˫ȭȭ����磬ͬʱ����$nͷ���أ�������Ҫ��", 420, 35, 60,"����",},
		{"$N����ڿۣ�����������һʽ����ʯ���񡹣�˫ȭ���봷��$n���ؿ�", 540, 40, 80,"����",},
	};
	int level = 0;
	
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("poyu_quan", 1))
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
	return (usage == "cuff") || (usage == "parry");
}

virtual int valid_combine(string combo) { return combo=="hunyuan_zhang"; }

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon() )
		return notify_fail("������ʯ����ȭ��������֡�");
	if ( me->query_skill("zixia_shengong", 1) < 10)
		return notify_fail("��ġ���ϼ�񹦡���򲻹����޷�ѧ����ʯ����ȭ����");
	if ( me->query("max_mp") < 50)
		return notify_fail("�������̫�����޷�������ʯ����ȭ����");
	return 1;
	
}

virtual int practice_skill(CChar * me)
{
	if ( me->query("hp") < 30)
		return notify_fail("�������̫���ˡ�");
	if ( me->query("mp") < 20)
		return notify_fail("�����������������ʯ����ȭ����");
	me->receive_damage("hp", 25);
	me->add("mp", -5);
	return 1;
}

//perform 
static int do_leidong(CChar * me, CContainer * ob)
{
	int skill, count, count1;
	
	if(  me->query_temp("leidong") ) 
		return notify_fail("���Ѿ����˹����ˡ�");
	if( !me->is_fighting() )
		return notify_fail("�׶�����ֻ����ս����ʹ�á�");
	if(  me->query("mp") < 500  ) 
		return notify_fail("�������������");
	if(DIFFERSTR(me->querystr("family/family_name"), "��ɽ��") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	count = me->query_str();
	skill = me->query_skill("cuff");
	if( skill < 135  ) 
		return notify_fail("�������ȭ��Ϊ��������");
	
	me->add("mp", -400);
	message_vision( "$N��������һ���������϶�ʱ������ʢ������Խ��Խ�أ�" , me);
	
	count = me->query("str") +  (skill/10);
	count1 = me->query("dex") +  (skill/10);
	
	me->add_temp("apply/str", count);
	me->add_temp("apply/dex", count1);
	me->set_temp("leidong", 1);
	me->call_out( remove_effect, skill/3, count, count1);
 	return 1;
}

static void remove_effect(CContainer *ob, LONG amount, LONG amount1)
{
	CChar *me=(CChar *)ob;
	me->add_temp("apply/str", -amount);
	me->add_temp("apply/dex", -amount1);
	me->delete_temp("leidong");

	me->SendState();
	tell_object(me, "����׶�����������ϣ��������ջص��");
	me->start_busy(4);
}

SKILL_END;
