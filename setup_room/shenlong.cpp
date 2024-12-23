#include "stdafx.h"
#include "../server/Room.h"

//神龙
#include "../d/shenlong/shenlong_caoping.h"
#include "../d/shenlong/shenlong_damen.h"
#include "../d/shenlong/shenlong_dating.h"
#include "../d/shenlong/shenlong_haitan.h"
#include "../d/shenlong/shenlong_huanghai.h"
#include "../d/shenlong/shenlong_kongdi.h"
#include "../d/shenlong/shenlong_lin.h"
#include "../d/shenlong/shenlong_road.h"
#include "../d/shenlong/shenlong_xiaowu.h"

CRoom * Load_ShenLong(string room_name)
{
	CRoom * r = NULL;

	//神龙
	if(room_name == "神龙教小屋")
		r = new CRShenLong_xiaowu();
	else if(room_name == "神龙教大道")
		r = new CRShenLong_road();
	else if(room_name == "神龙教灌木林")
		r = new CRShenLong_lin();
	else if(room_name == "神龙教空地")
		r = new CRShenLong_kongdi();
	else if(room_name == "神龙黄海")
		r = new CRShenLong_huanghai();
	else if(room_name == "神龙教海滩")
		r = new CRShenLong_haitan();
	else if(room_name == "神龙教草坪")
		r = new CRShenLong_caoping();
	else if(room_name == "神龙教大门")
		r = new CRShenLong_damen();
	else if(room_name == "神龙教大厅")
		r = new CRShenLong_dating();


	return r;
}