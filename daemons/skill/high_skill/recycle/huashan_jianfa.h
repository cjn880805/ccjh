// huashan_jianfa.h ��ɽ����
//code by Fisho
//date : 2000-12-06
SKILL_BEGIN(CShuashan_jianfa);

virtual void create()
{
	set_name( "��ɽ����");

	Magic_t * magic;

	magic = add_magic("jianzhang", do_jianzhang);
	magic->name = "����������";
	magic->mp = 100;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

/*	magic = add_magic("wushuang", do_wushuang);
	magic->name = "��˫�޶�";
	magic->mp = 300;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;*/
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$Nһ�С����Ƴ�ᶡ�������$w����$n��$l", 20, 0,"����",},
		{"$Nʹ�����з����ǡ���$w��˸����������$n��$l", 25, 10,"����",},
		{"$Nһ�С�����������$w���϶��»���һ���󻡣���$n������ȥ", 30, 20,"����",},
		{"$N��ǰ����һ��������$wʹ�����׺���ա�ֱ��$n��$l", 35, 30,"����",},
		{"$N���е�$wһ�Σ�ʹ��������ӭ�͡�ֱ��$n��$l", 50, 40,"����",},
	};
	
	int level = 0;
	
	for(int i=5; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("huashan_jianfa", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}
	
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "sword") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 100)
		return notify_fail("�������������");
	if (me->query_skill("zixia_shengong", 1) < 20)
		return notify_fail("��Ļ�ɽ�ڹ����̫ǳ��");
	return 1;
	
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;
	
	if (!(weapon = me->query_weapon())
        || DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��ʹ�õ��������ԡ�");
	if (me->query("hp") < 50)
		return notify_fail("���������������ɽ������");
	me->receive_damage("hp", 30);
	return 1;
	
}

//perform 
static int do_jianzhang(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	char msg[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

 	if( !target || !me->is_fighting(target) )
		return notify_fail("��������������ֻ����ս����ʹ�á�");
	
	if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("����������������ʼʱ��������һ�ѽ���");
	
	if( me->query("mp") < 100 )
		return notify_fail("�������������");
	
	if( me->query_skill("sword") < 50 ||
		DIFFERSTR(me->query_skill_mapped("sword"), "huashan_jianfa"))
		return notify_fail("��Ļ�ɽ�����������ң��޷�ʹ�ý�����������");
	
	snprintf(msg ,255,"$Nʹ����ɽ�ɾ�����������������������Ȼ�ӿ죡"  );
	message_vision(msg, me);
	
	
	Do_Attack(me, target,  TYPE_QUICK);
	Do_Attack(me, target,  TYPE_QUICK);
	Do_Attack(me, target,  TYPE_QUICK);
	Do_Attack(me, target,  TYPE_QUICK);
	Do_Attack(me, target,  TYPE_QUICK);
	
	me->add("mp", -100);
	me->start_busy(random(5));
	
	return 1;
	
}
/*
static int do_wushuang(CChar * me, CContainer * ob)
{
	int skill;
	CChar * target = NULL;
	CContainer * weapon;
	char msg[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

	
	if( !target	||	!me->is_fighting(target) )
		return notify_fail("ǣ�ƹ���ֻ�ܶ�ս���еĶ���ʹ�á�");
	
	if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��ʹ�õ��������ԡ�");
	
	if( me->query_skill("huashan_jianfa", 1) < 40 )
		return notify_fail("��Ļ�ɽ����������죬����ʹ�á���˫�޶ԡ���");
	
	
	if( me->query("mp") < 300  ) 
		return notify_fail("�������������");
	
	if(  me->query_temp("hsj_wu") ) 
		return notify_fail("���Ѿ����˹����ˡ�");
	
	snprintf(msg ,255,"$N˫������%s����â������һʽ����˫�޶ԡ���Ԧ�����Ҿ��׵���$P��̣�" ,weapon->name() );
	message_vision(msg, me, target);
	
	skill =  me->query_skill("huashan_jianfa",1);
	me->add_temp("apply/attack", skill/3);
	me->add_temp("apply/dodge", -skill/4);
	me->set_temp("hsj_wu", 1);
	
	me->call_out( remove_effect, 2, skill/3, skill/4);
	
	me->add("mp", -100);
 	return 1;
}

static void remove_effect(CContainer *ob, LONG a_amount, LONG d_amount)
{
	CChar *me = (CChar *)ob;
	me->add_temp("apply/attack", - a_amount);
	me->add_temp("apply/dodge", d_amount);
	me->delete_temp("hsj_wu");

	me->SendState(me);
	me->start_busy(4);
}
*/
SKILL_END;
