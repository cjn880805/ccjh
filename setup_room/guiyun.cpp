#include "stdafx.h"
#include "../server/Room.h"

//¹éÔÆ×¯
#include "../d/gueiyun/gueiyuncity.h"
#include "../d/gueiyun/gueiyun_chufang.h"
#include "../d/gueiyun/gueiyun_liangong.h"
#include "../d/gueiyun/gueiyun_nanxiangfang.h"
#include "../d/gueiyun/gueiyun_nvxiangfang.h"
#include "../d/gueiyun/gueiyun_shufang.h"

CRoom * Load_GuiYun(string room_name)
{
	CRoom * r = NULL;

	//¹éÔÆ×¯
    if(room_name == "¹éÔÆ×¯")
		r = new CRGueiYuncity();
    else if(room_name == "¹éÔÆ×¯Á·¹¦·¿")
		r = new CRGueiYun_liangong();
    else if(room_name == "¹éÔÆ×¯Êé·¿")
		r = new CRGueiYun_shufang();
    else if(room_name == "¹éÔÆ×¯Å®Ïá·¿")
		r = new CRGueiYun_nvxiangfang();
    else if(room_name == "¹éÔÆ×¯³ø·¿")
		r = new CRGueiYun_chufang();
    else if(room_name == "¹éÔÆ×¯ÄĞÏá·¿")
		r = new CRGueiYun_nanxiangfang();

	return r;
}