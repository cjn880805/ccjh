#include "stdafx.h"
#include "../server/Room.h"
#include "../std/resident.h"

//   ����
#include "../d/nanyang/nanyangcity.h"
#include "../d/nanyang/nanyang_jiulou1.h"
#include "../d/nanyang/nanyang_kedian.h"

CRoom * Load_NanYang(string room_name)
{
	CRoom * r = NULL;

	//     ����
	if(room_name == "������")
		r = new CRnanyangcity();
	else if(room_name == "����ӭ��¥")
		r = new CRNanYang_jiulou1();
	else if(room_name == "����������ջ")
		r = new CRNanYang_kedian();

	return r;
}