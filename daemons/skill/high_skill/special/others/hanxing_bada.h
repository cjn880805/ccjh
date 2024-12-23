//hanxing_bada.h ���ǰ˴�
//lanwood 2001-01-04

SKILL_BEGIN(CShanxing_bada);

virtual void create()
{
	set_name( "���ǰ˴�");

	Magic_t * magic;

	magic = add_magic("lastrisk", do_lastrisk);
	magic->name = "��עһ��";
	magic->mp = 100;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int  force, dodge,  damage, lvl;
	}action[8] = {
		{"$Nʹһ�С�����է�֡�������$w����$n��$l",
			120, -20,90, 0,},
		{"$Nʹ�����������ա���˫���³�$w�������Ϸɳ�ֱϮ$n��$l",
		125,  -20, 50, 10,},
		{"$Nһ�С�ĺ��������������һ�ӣ�����$w��Ҹ�¼���$n��$l",
		135, -30,40, 20,},
		{"$N����$wһʽ�������ѿա���$w����һ���׹�ֱ��$n��$l",
		140, -40,60, 30,},
		{"$N����һԾ������$wһ�С������뺣������$n��$l",
		150, -40, 70, 40,},
		{"$N�ֿ�$w,ƾ��һָ��һ�С���ɽҹ�꡹����$n��$l",
		160, 20,50, 50,},
		{"$N����һ�Σ�ʹһ�С����Ǻ�ա�$w���ֶ�����Ϯ��$n��$l",
		220, -20,60,60,},
		{"$N����һת����$wʹһ�С��������ա�����һ���⻡Ϯ��$n��$l",
		270, -30,60, 100,},
	};
 
  	int level = me->query_skill("hanxing_bada", 1);
	for(int i = 8; i > 0; i--)
		if( action[i - 1].lvl < level)
		{
			level = random(i);
	
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
			
	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="throwing" || usage=="parry"; }

virtual int valid_learn(CChar * me)
{
	CContainer * weapon;

    if( me->query("max_mp") < 100 )
          return notify_fail("�������������û�а취�����ǰ˴�");
    if( !(weapon = me->query_weapon())
        || DIFFERSTR(weapon->querystr("skill_type"), "throwing") )
          return notify_fail("���������һЩ����֮��Ķ���������������");
    return 1;
}

virtual int practice_skill(CChar * me)
{
	if( me->query("hp") < 30 || me->query("mp") < 3 )
        return notify_fail("�����������������û�а취��ϰ���ǰ˴�");
    me->receive_damage("hp", 30);
    me->add("mp", -3);
    return 1;
}

static int do_lastrisk(CChar * me, CContainer * ob)
{
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	CContainer * weapon;
	string msg;
	int skill;

	if( !target || !me->is_fighting(target) )
		return notify_fail("��עһ��ֻ�ܶ�ս���еĶ���ʹ�á�");

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "throwing"))
		return notify_fail("��������а�����");
		
	skill = me->query_skill("hanxing_bada", 1);
	
	if(skill < 60 )
		return notify_fail("��ĺ��ǰ˴���Ϊ̫ǳ��");
	
	if( me->query("mp") < 100 )
		return notify_fail("����������̫��������ʹ�á���עһ������");

	me->add("mp", -50);
			
	msg = "$N��עһ�����������а�������$n!\n";

    me->start_busy(2);
    if( random(me->query_combat_exp()) > target->query_combat_exp()/2 )
    {
        msg += "���$p��$P���˸����ֲ�����";
        target->receive_wound("hp", random(skill) * 2);
    } 
	else 
        msg += "����$p�����$P�����һ����";
        
    message_vision(msg.c_str(), me, target);

	//�ù���������
    weapon->move(me->environment());
        
    return 1;
}

SKILL_END;

