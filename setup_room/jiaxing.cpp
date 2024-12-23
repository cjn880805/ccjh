#include "stdafx.h"
#include "../server/Room.h"
#include "../std/resident.h"

//   嘉兴城
#include "../d/jiaxing/jiaxing_nanhu.h"
#include "../d/jiaxing/jiaxing_nanmen.h"
#include "../d/jiaxing/jiaxing_tieqiang.h"
#include "../d/jiaxing/jiaxing_yanyu.h"
#include "../d/jiaxing/jiaxingcity.h" 

CRoom * Load_JiaXing(string room_name)
{
	CRoom * r = NULL;

	//   嘉兴城
	if(room_name == "嘉兴城")
		r = new CRjiaxingcity();
	else if(room_name == "嘉兴铁枪庙")
		r = new CRJiaXing_tieqiang();
	else if(room_name == "嘉兴烟雨楼")
		r = new CRJiaXing_yanyu();
	else if(room_name == "嘉兴南湖")
		r = new CRJiaXing_nanhu();
	else if(room_name == "嘉兴南门")
		r = new CRJiaXing_nanmen();

	return r;
}