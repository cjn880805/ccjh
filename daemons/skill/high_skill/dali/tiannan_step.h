//tiannan_step.h天南步法

//code by Fisho
//date:2000-11-29

SKILL_BEGIN(CStiannan_step);

virtual void create()
{
	set_name( "天南步法");
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[][100]=
	{
		"只见$n一招「旱地拔葱」，身体向上笔直地纵起丈余，躲过了$N这一招。",
		"$n一个「雨燕归巢」，向后纵出数丈之远，避开了$N的凌厉攻势。",
		"$n使出「破土而出」，向一旁飘然纵出，轻轻着地。"
		"但是$n身形飘忽，一招「无中生有」轻轻一纵，早已避开。",
		"$n身随意转，一招「乘风而去」倏地往一旁挪开了三尺，避过了这一招。",
		"可是$n侧身一让，一招「鲧化大鹏」$N这一招扑了个空。",
		"却见$n足不点地，一招「青云直上」往旁窜开数尺，躲了开去。",
		"$n身形微晃，一招「凤翔九天」有惊无险地避开了$N这一招。"
	};
	
	return dodge_msg[random(8)];
}

virtual int valid_enable(string usage) { return (usage == "dodge") || (usage == "move");}

virtual int valid_learn(CChar * me) { return 1; }

virtual int practice_skill(CChar * me)
{
    if( me->query("hp") < 40 )
       return notify_fail("你的体力太差了，不能练段氏身法。");
    me->receive_damage("hp", 30);
    return 1;
}

SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp