
// jinshe_jian.h ���߽���
//code by Fisho
//date : 2000-12-05

SKILL_BEGIN(CSjinshe_jian);

virtual void create()
{
	set_name( "���߽���");

	Magic_t * magic;

	magic = add_magic("suo", do_suo);
	magic->name = "������";
	magic->mp = 300;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

const char * query_parry_msg(CContainer * weapon)
{
	static char parry_msg[][80] = {
		{"$n���˷������������죬���е�$W�ݺݿĿ���$N��$w��"},
		{"$n�ؽ����أ���ס��$N��$w��"},
		{"$n���е�$W����ǧ�ٰѣ���ס��ȫ��"},
		{"$n���е�$W�������£�������$N��$w�������Ρ�"},
	};

	static char unarmed_parry_msg[][80] = {
		{"$nʹ��$W������ǰ������һ��ͭǽ���ڣ���ס��$N�Ĺ��ơ�"},
		{"$nһ�����е�$W����ס��ȫ��"},
		{"$n��$W������һ�̣�$W�����������պ�ֱ��$N��˫�ۡ�"},
		{"$n�ٽ�������һ�������ӽ���͸�����ƿ���$N��"},
	};
	if( weapon )
		return parry_msg[random(4)];
	else
		return unarmed_parry_msg[random(4)];
}

CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  dodge,parry,force,damage;
		char damage_type[5];
	}action[] = {
		{"$Nʹһ�С������Ӱ�������е�$w��һ��ָ������$n��$l��������", 50, 100, 170, 50, "����",},
		{"$Nʹһ�С���Ӱ�����������$w�����������$n��$l��������", 100, 200, 200, 70, "����",},
		{"$N����һת����������Ծ������$w�鶯زԾ��һ�С�ѩ�ط��ߡ�����$n��$l", 100, 200, 170, 50, "����",},
		{"$N����һת��һ�С��������š������е�$w����������$n��$l���˹�ȥ", 100,200 , 200, 120, "����",},
		{"$N����һ����һ�С����߿��衹��$wЮ���������⣬����޷�����$n��$l", 100, 200, 300, 150, "����",},
		{"$N������������񴦣�һ�С����ߵ�������$w���޷����ݵ��ٶ�ֱ��$n��$l", 100, 200, 250, 200, "����",},
		{"$N����һ����һ�С�������ǡ������е�$w�������ϴ���$n��$l", 100, 200, 300,300 , "����",},
		{"$N����$w���Ⱪ����һ�С����߻���������ǧ����Ы��$n$lҧȥ", 100, 200, 300, 400, "����",},
	};
 		
	int level = 0;
	
	for(int i=8; i>0; i--)
	{
		if( (i - 1) * 10 < me->query_skill("jinshe_jian", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("force", action[level].force);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}
	return & m_actions;
};

int valid_enable(string usage) 
{ 
	return (usage == "sword") || (usage == "parry");
}

int valid_learn(CChar * me)
{
	if(me->query_skill("jinshe_jian", 1) < 200)
		return notify_fail("�����Ϊ̫ǳ,�޷�������а���!");

	CContainer * ob;
	
	if(  me->query("max_mp") < 500 )
		return notify_fail("�������������û�а취�����߽�����");
	
	if( !(ob = me->query_weapon())
		||	 DIFFERSTR(ob->querystr("skill_type"), "sword") )
		return notify_fail("���������һ�ѽ�������������");
	
	return notify_fail("���߽���û�����ڡ�");
	
}

int practice_skill(CChar * me)
{
	if(me->query_skill("jinshe_jian", 1) < 200)
		return notify_fail("�����Ϊ̫ǳ,�޷�������а���!");

	if(  me->query("hp") < 30
		||	 me->query("mp") < 15 )
		return notify_fail("�����������������û�а취��ϰ���߽�����");
	me->receive_damage("hp", 30);
	me->add("mp", -15);
	tell_object(me,"�㰴����ѧ����һ����߽�����", "practice");
	return 1;
}

//perform 
static int do_suo(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon, * weapon2;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if(!target || !me->is_fighting(target))
        return notify_fail("����������ֻ�ܶ�ս���еĶ���ʹ�á�");

    if (! (weapon = me->query_weapon())
        ||  DIFFERSTR(weapon->querystr("id"), "jinshe_jian"))
		return notify_fail("��û�ý��߽�������ʹ�þ��У�");
	
    if( me->query("dex") < 20 || me->query("str") < 20 )
        return notify_fail("�����������������, ����ʹ�á�����������");
	
    int skill = me->query_skill("jinshe_jian",1);
	
    if (! (weapon2 = target->query_weapon()))
        return notify_fail("�Է�û��ʹ�ñ��������ò��ˡ�����������");
	
    if( skill < 150)
        return notify_fail("��Ľ��߽����ȼ�����, ����ʹ�á�����������");
	
    if( me->query("mp") < 300 )
        return notify_fail("��������������޷����á�����������");
	
    msg = "$N����" "���߽�����һ����⣬б��һ�������������������߽����⵹�����ù���$n��";
	msg += weapon2->name();
	msg += "�ϡ�";

	int damage = 10 + random(skill / 2);
    int ap = me->query_skill("sword")/3 + skill;
    int dp = target->query_skill("dodge")/2;
    if( dp < 1 )
        dp = 1;
    if( random(ap) > random(dp) )
    {
        me->add("mp",-50);
        msg += "$n��ʱ������ǰ���һ��������һ������";
        msg += weapon2->name();
        msg += "���ַɳ���";
        me->start_busy(random(2));
        target->receive_damage("hp", damage);
        target->start_busy(2);
        weapon2->move(me->environment());
    }
    else
    {
        me->add("mp",-30);
        msg += "$n����������������";
		msg += weapon2->name();
		msg += "бб˳��һ��һ����˻�����";
        me->start_busy(4);
    }

    message_vision(msg.c_str(), me, target);
    return 1;
}

SKILL_END;
