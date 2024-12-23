
// jinshe_zhang.h ����������
//code by Fisho
//date : 2000-12-05

SKILL_BEGIN(CSjinshe_zhang);

virtual void create()
{
	set_name( "����������");

	Magic_t * magic;

	magic = add_magic("fugu", do_fugu);
	magic->name = "���ǲ���";
	magic->mp = 300;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual const char * query_parry_msg(CContainer * weapon)
{
	static char parry_msg [80]= {"$nʹ����ճ���־���˫��һ������ƫ��$N��$w��"};
	
	static char unarmed_parry_msg[80] = {"$nʩչ�����������ƣ����赭д�Ļ�����$N�Ĺ��ơ�"};
	
	if( weapon )
		return parry_msg;
	else
		return unarmed_parry_msg;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  dodge,parry,damage;
		char damage_type[5];
	}action[] = {
		{"$N˫��һ��һ�С�ǧ�߳������ó�������Ӱ£��$n��$l", 30, 10, 50, "����",},
		{"$N����һ����˫�������Ƴ���һ�С��������ߡ�ǿ�����Ʒ�ֱ��$n��$l", 30, 10, 50, "����",},
		{"$N˫�Ʒ׷ɣ�һ�С�˫�����项ֱȡ$n��$l",10 , 30, 30, "����",},
		{"$N�����������ߣ�һ�С�����ʽ����ɭɭ�Ʒ��޿ײ����ػ���$n��$l", 10, 50, 70, "����",},
		{"$N�������˫��ƽ�ƣ����������һ�С�����ʽ������$n��$l", 30, 70, 30, "����",},
		{"$N����������ǰ�������Ƴ���һ�С��������ơ�����$n$l", 30,70 , 30, "����",},
		{"$Nʹ�������߷���ҧ����������շ��𣬴ӿ��е�ͷ��$n��$l���ƹ���", 30, 70, 30, "����",},
		{"$Nʹ��һ�С�������Ӱ�������ƻ���Ϊʵ����$n��$l", 30, 70, 30, "����",},
		{"$N���ƻ��˸�ȦȦ�������Ƴ���һ�С����߲�˿�֡�����$n$l", 30, 70, 30, "����",},
		{"$Nʹ���������ΰ˷���������ɢ���˴�ͬʱ��$n��$l���ƹ���", 30, 70, 30, "����",},
		{"$Nʹ�����������Ʒ�������̽ͷ��������Ȱ�����$n��ǰ��һ������$n��$l", 30, 70, 30, "����",},
		{"$N�������ᣬȫ�����һ�С��������졹��˫��������£�$n��ȫ��������������֮��", 30, 70, 30, "����",},
	};
 		
	int level = 0;
	
	for(int i=12; i>0; i--)
	{
		if( (i - 1) * 10 < me->query_skill("jinshe_zhang", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("parry", action[level].parry);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "strike") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
	if(me->query_skill("jinshe_zhang", 1) < 200)
		return notify_fail("�����Ϊ̫ǳ,�޷�������а���!");

	if( me->query_weapon() )
		return notify_fail("�����������Ʊ�����֡�");
	if(  me->query("max_mp" ) < 500)
		return notify_fail("����������㣬�޷������������ơ�");
	return notify_fail("����������û�����ڡ�");
}

virtual int practice_skill(CChar * me)
{
	if(me->query_skill("jinshe_zhang", 1) < 200)
		return notify_fail("�����Ϊ̫ǳ,�޷�������а���!");

	if(  me->query("hp") < 30 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�");
	if(  me->query("mp") < 5 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�");
	me->receive_damage("hp", 30);
	me->add("force", -5);
	return 1;
}

//perform 
static int do_fugu(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

    if( !target || !me->is_fighting(target) )
		return notify_fail("���ǲ���ֻ�ܶ�ս���еĶ���ʹ�á�");
	
    if( me->query_weapon())
		return notify_fail("�㲻�ǿ��֣�����ʹ�ø��ǲ���");
	
    if(  me->query_skill("jinshe_zhang", 1) < 100 )
		return notify_fail("��Ľ����Ʋ�����죬����ʹ�ø��ǲ���");

	
	
    if(  me->query("mp" ) < 300 )
		return notify_fail("����������̫��������ʹ�ø��ǲ���");
	
    msg = "$N���һ���������������һ̽��ס$n������������ɱ�֣�\n";
    	
    //if( !target->is_fighting(me) ) target->kill_ob(me);
	
    if (random(me->query_skill("strike")) > target->query_skill("dodge")/2 )
    {
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
		
		me->add("mp", -50);
		me->start_busy(random(2));
		msg +=  "���$n��$N���������ƣ��ڡ����ǲ����£���Ȼ�޷����֣�" ;
    }
    else
    {
		me->start_busy(3);
		msg +=  "����$pʶ����$P��һ�У�����һ�ͣ������˶Է����ơ�" ;
    }

    message_vision(msg.c_str(), me, target);
    return 1;
}

SKILL_END;
