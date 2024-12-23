// SUnarmed.cpp: implementation of the CSUnarmed class.
//
//////////////////////////////////////////////////////////////////////

//parry.h -- 基本招架

SKILL_BEGIN(CSParry);

void create()
{
	set_name( "基本招架");
}

const char * query_parry_msg(CContainer * weapon)
{
	return "但是被$n挡住了。";
}

SKILL_END;