//shigu_bifa.h 石鼓打穴笔法

SKILL_BEGIN(CSshigu_bifa);

virtual void create()
{
	set_name( "石鼓打穴笔法");
	set("valid_force", "wuzheng_xinfa");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int  force, dodge,  damage, lvl;
	}action[8] = {
	       {"$N一招「指点江山」，手中$w疾点向$n的期门穴!",
			   120, 20, 50, 0,},
		   {"$N吐气开声一招「银钩铁划」，$w如灵蛇吞吐，向$n白海穴戳去!",
		   170, 15, 60, 9,},
		   {"$N向前跨上一步，混身充满战意，手中$w使出「银瓶乍破」，疾点$n的地仓穴!",
		   190, 10, 70, 19,},
		   {"$N手中的$w自左而右地一晃，使出「铁骑突出」带着呼呼风声横打$n的章门穴!",
		   240, 10, 80, 29,},
		   {"$N飞身跃起，一式「龙耀九霄」，卷起漫天笔影，$w向$n电射而去",
		   280, 5, 90, 39,},
		   {"$N凝气守中，$w逼出尺许雪亮笔锋，挥出「灵台观景」，一笔快似一笔地攻向$n",
		   300, 5, 100, 59,},
		   {"$N使出一招「遥拜玉虚」挺笔中宫直进，笔尖颤动，中途忽然转而向上变幻无方",
		   330, -5, 120, 79,},
		   {"$N侧身斜刺一笔，一招「天音萧煞」卷带着呼呼笔风，将$n包围紧裹",
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
                return notify_fail("你的内力不够，没有办法练石鼓打穴笔法。");
        if( DIFFERSTR(me->query_skill_mapped("force"), "shenghuo_shengong"))
                return notify_fail("石鼓打穴笔法需配合圣火神功。");
        if( me->query_skill("shenghuo_shengong",1) < 20 )
                return notify_fail("你的圣火神功火候不够，还不能学习石鼓打穴笔法!");
         return 1;
}


virtual int practice_skill(CChar * me)
{
		CContainer * ob;
        if( !(ob = me->query_weapon())
			|| DIFFERSTR(ob->querystr("skill_type"), "dagger") )
                return notify_fail("你必须先找一对判官笔才能学习石鼓打穴笔法。");

        if( me->query("hp") < 30
			|| me->query("mp") < 3 )
                return notify_fail("你的内力或气不够，没有办法练习石鼓打穴笔法。");

        me->receive_damage("hp", 20);
        me->add("mp", -10);
        
        return 1;
}

SKILL_END;

