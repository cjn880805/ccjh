// SUnarmed.cpp: implementation of the CSUnarmed class.
//
//////////////////////////////////////////////////////////////////////

//unarmed.h -- 基本拳脚

SKILL_BEGIN(CSUnarmed);

virtual void create()
{
	set_name( "基本拳脚");
}

virtual CMapping * query_action(CChar * me)
{
	static char action[][80]=
	{
		"$N冲上去狠狠的打了$n一巴掌。",
		"$N挥起板砖，拍在了$n的破脑袋上。",
		"$N大喝一声，揪住$n的衣领往死里揍。",
		"$N不由分说，扬起一脚，踢在$n的小腹上。",
		"$N举起拳头，将$n的鼻子打开了花。",
		"$N扬起手指，痛苦的戳在了$n的嘴巴上。",
		"$N冲上去狠狠的踢了$n一脚。",
		"$N操起铁锹，狠狠的砸在$n的脑袋上。",
	};
	
	m_actions.set("action", action[random(8)]);
	return & m_actions;
}

protected:
	CMapping m_actions;

SKILL_END;