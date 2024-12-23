//hengshan_sword.h ��ɽ����

SKILL_BEGIN(CShengshan_sword);

virtual void create()
{
	set_name( "��ɽ����");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int  dodge,  damage;
	}action[8] = {
		{ "$N����$w����ָ����ͻȻ���ڿ���һ������������֮�������ű�����������������$w���Ⱪ������$n��$l��ȥ",
			-50,  170,},
		{"$N����$w������ȣ���Ȼ���Ƶ���$n����$n��æת������ֻ������������",
		-70,  120,},
		{ "$N����$w���ⶸ�������е�$w���͵ط��̣�ֱָ$n�ؿڡ���һ�³��п켫������������ã����ǡ��ٱ�ǧ�ú�ɽ����ʮ��ʽ���еľ���",
        -40,   90,},
		{ "$N�����Է�������·������$wˢ��һ����Ȫ��ܽ�ء�����$nС����ȥ",
        -40,  100,},
		{ "$N�����Է�������·������$wˢ��һ���������ϸǡ�����$n��ͷ��ȥ",
        -40,  100,},
		{ "$N����$wٿ�ش̳������ƴ����ػأ�������ã�����һ�С�ʯ������������$n$l��ȥ",
        -60,  170,},
		{ "$N����$wٿ�ش̳�����������֮���£������޶�������׽��������һ�С�������������ָ��$n$l",
        -60, 180,},
		{ "$N����Ծ�𣬡����ף�ڡ�����$w����һ�������Ӱ��������$n��$l",
        -60, 160,},};
 
  	int level = random(8);
	
	m_actions.set("action", action[level].action);
	m_actions.set("dodge", action[level].dodge);
	m_actions.set("damage", action[level].damage);
	
	return & m_actions;
};

virtual int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

virtual int valid_learn(CChar * me)
{
	 CContainer * ob;

    if( me->query("max_mp") < 50 )
        return notify_fail("�������������û�а취����ɽ������\n");

    if( !(ob = me->query_weapon())
		|| DIFFERSTR(ob->querystr("skill_type"), "sword") )
        return notify_fail("���������һ�ѽ�������������");

    return 1;
}


virtual int practice_skill(CChar * me)
{
	if( me->query("hp") < 30
    ||      me->query("mp") < 5 )
        return notify_fail("�����������������û�а취��ϰ��ɽ������");

    me->receive_damage("hp", 30);
    me->add("mp", -5);

    tell_object(me, "�㰴����ѧ����һ���ɽ������", "practice");
    return 1;
}

SKILL_END;

