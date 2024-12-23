//lingxu_bu.h 凌虚步

SKILL_BEGIN(CSlingxu_bu);

virtual void create()
{
	set_name( "凌虚步");
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[][80]={	
		{"$n一式「雪地莲花」，身子掣忽一转，$N只觉的眼前一花，失去了目标。",},
		{ "$n一式「一狐冲天」，双脚点地，身子突然拔高了丈许，缓缓飘落在$N身后。",},
		{"$n一式「移行幻影」，身行一晃，顿时无数条身影一下子出现在$N的面前。",},
		{"$n一式「狡兔三窟」，飘然向后一退，躲开$N的凌厉攻势。",},
		{"$n一式「烟雨飘渺」，身体急转，化为一道白光，虚幻不定的出现在$N的周围。",},
		};

	return dodge_msg[random(5)];
}

virtual int valid_enable(string usage) { return usage == "dodge" || usage == "move"; }

virtual int valid_learn(CChar * me)
{
    return 1;
}

SKILL_END;

