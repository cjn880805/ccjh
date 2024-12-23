//duanhun_qiang.h �ϻ�ǹ

SKILL_BEGIN(CSduanhun_qiang);

virtual void create()
{
	set_name( "�ϻ�ǹ��");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct{
			char action[100];
			int force,dodge, damage ;
			char damage_type[5];
	}action[]={
		{"$Nʹһ�С�������Ρ�������$wһ������������ǹͷ��ֱ��$n��$l��",100,-100,200,"����"},
		{"$Nʹ���ϻ�ǹ�еġ�ִ��Ϊ�桹������$w�ζ��������ǹ��ͻȻ��Ӱ�з���һǹ������$n��$l��",140,-120,220,"����"},
		{"$Nһ�С���Գ��Ρ�����ǰ�ʹܣ�����$w����һǹ��ֱ��$n��$l��",180,-130,180,"����"},
		{"$N����$wһʽ������֪�Ρ�������$wǹͷ�Ҷ�������ǵ�ɱ����ǹǹ����$n��$l��",220,-120,160,"����"},
        {"$N��$w��㣬��ؽ�������һ�С������ۡ�����$n��$l��",300,-110,150,"����"},
       	{"$N����$wһ�ݣ�ǹ������°���ת��һ�С�һ��ع⡹���ֶ�׼$n$lһǹ��ȥ��",330,-100,140,"����"},
	};
		
	int level = random(6);

	m_actions.set("action", action[level].action);
	m_actions.set("force", action[level].force);
	m_actions.set("dodge", action[level].dodge);
	m_actions.set("damage", action[level].damage);
		
	return & m_actions;
}

virtual const char * query_parry_msg(CContainer * weapon)
{
	static char parry_msg[][255] = {
		{"$nʹ��һ�С��������ơ������е�$W������$N��$w��"},
		{"$nʹ��������˵�Ρ�����$N��$w�������⡣"},
		{"$nʹ��һ�С�̤�����ġ������е�$W����������գ�������$N��$w��"},
		{"$n���е�$lһ����һ�С�������;������$N��$w�������ȥ��"},
		{"$n�����е�$W����ܲ�͸�磬һ�С���黴��С���ס��$N�Ĺ��ơ�"},
		{"$n����һ�С��Ƹ����ࡹ����������ʧ��һ�Ž���֮�С�"},
		{"$nʹ��һ�С������С���$Wֱ��$N��˫�֡�"},
		{"$n�����е�$Wһ����һ�С����Ŀճۡ����ȵ�$N�������ˡ�"},
	}; 
	if( weapon )
		return parry_msg[random(4)];
	else
		return parry_msg[random(4)+4];
}

virtual int valid_enable(string usage) 
{ 
	return usage=="club" ||  usage=="parry"; 
}


virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 70)
		return notify_fail("�������������");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;
	
	if (!(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "club"))
		return notify_fail("��ʹ�õ��������ԡ�");
	if (me->query("hp") < 50)
		return notify_fail("��������������ϻ�ǹ����");
	me->receive_damage("hp", 20);
	return 1;
}

SKILL_END;