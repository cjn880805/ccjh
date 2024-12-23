#include "stdafx.h"
#include "../server/Room.h"
#include "../std/resident.h"

//   南阳
#include "../d/nanyang/nanyangcity.h"
#include "../d/nanyang/nanyang_jiulou1.h"
#include "../d/nanyang/nanyang_kedian.h"

CRoom * Load_NanYang(string room_name)
{
	CRoom * r = NULL;

	//     南阳
	if(room_name == "南阳城")
		r = new CRnanyangcity();
	else if(room_name == "南阳迎宾楼")
		r = new CRNanYang_jiulou1();
	else if(room_name == "南阳悦来客栈")
		r = new CRNanYang_kedian();

	return r;
}