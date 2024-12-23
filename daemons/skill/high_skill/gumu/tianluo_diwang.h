
// tianluo_diwang.h 天罗地网势
//code by Fisho
//date : 2000-12-05

SKILL_BEGIN(CStianluo_diwang);

void create()
{
	set_name( "天罗地网势");
}

const char * type() { return "knowledge"; }

int valid_learn(CChar * me)
{
	
	if( me->query_dex() < 20 )
		return notify_fail("你的身法太差不能学习古墓派的武功。");
	
	if( me->query_int() < 26 )
		return notify_fail("你的悟性太差不适合学习古墓派的武功。");
	
	return 1;
}

int practice_skill(CChar * me)
{
	return notify_fail("天罗地网势只能通过练习来增加熟练度。");
}

SKILL_END;
