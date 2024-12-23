// lingboweibu.h 凌波微步

FORCE_BEGIN(CSlingboweibu);

virtual void create()
{
	set_name( "凌波微步");
}

CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	static struct {
		char action[255];
		int dodge, lvl;
	}action[5] = {
		{"只见$n左一步，右一步，轻而易举的躲过$N这一招。", 5, 0},
		{"但是$n身形一动，从不可思义的角度转过身来，避开了$N的攻击。", 5, 30},
		{"然而$n却不退反进，脚下步点变幻莫测，反使$N的攻势全部落空。", 10, 60},
		{"但是$n身形飘忽，忽前忽后，忽左忽右，让$N无法下手。", 15, 90},
		{"可是$n身随意转，脚步微变，人竟已在三丈之外，闪过了这一招。", 25, 150},
	};

	int level = me->query_skill("lingboweibu", 1);
	for(int i=5; i>0; i--)
	{
		if(action[i - 1].lvl < level)
		{
			level = random(i);
			char msg[255];

			//如果配合北冥神功,加倍
			if(! DIFFERSTR(me->query_skill_mapped("force"), "beiming_shengong") && random(1 + me->query("mp")) > 1000)
			{
				m_actions.set("action", snprintf(msg, 255, "$HIB%s$COM", action[level].action) );
				m_actions.set("dodge", action[level].dodge * 3);			

				if(me->query_temp("apply/sub_mp")>0)	//如果装备中有减少MP消耗的道具
					me->add("mp", -50*(100-me->query_temp("apply/sub_mp"))/100);
				else
					me->add("mp",-50);
				me->SendState(me);
			}
			else
			{
				m_actions.set("action", action[level].action);
				m_actions.set("dodge", action[level].dodge);			
			}

			break;
		}
	}
	
	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="dodge" ||  usage=="move"; }

virtual int valid_learn(CChar * me){return 1;}

virtual int practice_skill(CChar * me)
{
	if( me->query("hp") < 40 )
		return notify_fail("你的体力太差了，不能练凌波微步。");
	me->receive_damage("hp", 30);
	return 1;
}

SKILL_END;
