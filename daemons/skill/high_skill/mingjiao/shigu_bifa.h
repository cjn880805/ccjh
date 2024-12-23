//shigu_bifa.h ʯ�Ĵ�Ѩ�ʷ�

SKILL_BEGIN(CSshigu_bifa);

virtual void create()
{
	set_name( "ʯ�Ĵ�Ѩ�ʷ�");
	set("valid_force", "wuzheng_xinfa");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int  force, dodge,  damage, lvl;
	}action[8] = {
	       {"$Nһ�С�ָ�㽭ɽ��������$w������$n������Ѩ!",
			   120, 20, 50, 0,},
		   {"$N��������һ�С�������������$w���������£���$n�׺�Ѩ��ȥ!",
		   170, 15, 60, 9,},
		   {"$N��ǰ����һ�����������ս�⣬����$wʹ������ƿէ�ơ�������$n�ĵز�Ѩ!",
		   190, 10, 70, 19,},
		   {"$N���е�$w������ҵ�һ�Σ�ʹ��������ͻ�������ź����������$n������Ѩ!",
		   240, 10, 80, 29,},
		   {"$N����Ծ��һʽ����ҫ�����������������Ӱ��$w��$n�����ȥ",
		   280, 5, 90, 39,},
		   {"$N�������У�$w�Ƴ�����ѩ���ʷ棬�ӳ�����̨�۾�����һ�ʿ���һ�ʵع���$n",
		   300, 5, 100, 59,},
		   {"$Nʹ��һ�С�ң�����项ͦ���й�ֱ�����ʼ��������;��Ȼת�����ϱ���޷�",
		   330, -5, 120, 79,},
		   {"$N����б��һ�ʣ�һ�С�������ɷ������ź����ʷ磬��$n��Χ����",
		   330, -5, 150, 99,},
	};

  	int level = me->query_skill("shigu_bifa", 1);
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

virtual int valid_enable(string usage) { return (usage == "dagger") || (usage == "parry"); }

virtual int valid_learn(CChar * me)
{
        if( me->query("max_mp") < 100 )
                return notify_fail("�������������û�а취��ʯ�Ĵ�Ѩ�ʷ���");
        if( DIFFERSTR(me->query_skill_mapped("force"), "shenghuo_shengong"))
                return notify_fail("ʯ�Ĵ�Ѩ�ʷ������ʥ���񹦡�");
        if( me->query_skill("shenghuo_shengong",1) < 20 )
                return notify_fail("���ʥ���񹦻�򲻹���������ѧϰʯ�Ĵ�Ѩ�ʷ�!");
         return 1;
}


virtual int practice_skill(CChar * me)
{
		CContainer * ob;
        if( !(ob = me->query_weapon())
			|| DIFFERSTR(ob->querystr("skill_type"), "dagger") )
                return notify_fail("���������һ���йٱʲ���ѧϰʯ�Ĵ�Ѩ�ʷ���");

        if( me->query("hp") < 30
			|| me->query("mp") < 3 )
                return notify_fail("�����������������û�а취��ϰʯ�Ĵ�Ѩ�ʷ���");

        me->receive_damage("hp", 20);
        me->add("mp", -10);
        
        return 1;
}

SKILL_END;

