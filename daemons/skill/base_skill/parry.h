// SUnarmed.cpp: implementation of the CSUnarmed class.
//
//////////////////////////////////////////////////////////////////////

//parry.h -- �����м�

SKILL_BEGIN(CSParry);

void create()
{
	set_name( "�����м�");
}

const char * query_parry_msg(CContainer * weapon)
{
	return "���Ǳ�$n��ס�ˡ�";
}

SKILL_END;