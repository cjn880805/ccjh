#include "stdafx.h"
#include "../server/Room.h"
#include "../std/resident.h"
#include "../server/Channel.h"

//    佛山
#include "../d/foshan/foshan_beidimiao.h" 
#include "../d/foshan/foshan_dangpu.h" 
#include "../d/foshan/foshan_eastgate.h" 
#include "../d/foshan/foshan_huiguan.h" 
#include "../d/foshan/foshan_nanling.h" 
#include "../d/foshan/foshan_northgate.h" 
#include "../d/foshan/foshan_road1.h" 
#include "../d/foshan/foshan_road10.h" 
#include "../d/foshan/foshan_road11.h" 
#include "../d/foshan/foshan_road12.h" 
#include "../d/foshan/foshan_road13.h" 
#include "../d/foshan/foshan_road14.h" 
#include "../d/foshan/foshan_road2.h" 
#include "../d/foshan/foshan_road3.h" 
#include "../d/foshan/foshan_road4.h" 
#include "../d/foshan/foshan_road5.h" 
#include "../d/foshan/foshan_road6.h" 
#include "../d/foshan/foshan_road7.h" 
#include "../d/foshan/foshan_road8.h" 
#include "../d/foshan/foshan_road9.h" 
#include "../d/foshan/foshan_southgate.h" 
#include "../d/foshan/foshan_westgate.h" 
#include "../d/foshan/foshan_yingxionglou.h" 
#include "../d/foshan/foshan_yingxionglou2.h" 
#include "../d/foshan/foshan_youtiaopu.h" 
#include "../d/foshan/foshan_dahai.h" 
#include "../d/foshan/foshancity.h"

CRoom * Load_FoShan(string room_name)
{
	CRoom * r = NULL;

	//    佛山
	if(room_name == "佛山")
		r = new CRfoshancity();
	else if(room_name == "佛山烧饼油条铺")
		r = new CRFoShan_youtiaopu();
	else if(room_name == "佛山英雄楼")
		r = new CRFoShan_yingxionglou();
	else if(room_name == "佛山西门")
		r = new CRFoShan_westgate();
	else if(room_name == "佛山南门")
		r = new CRFoShan_southgate();
	else if(room_name == "佛山林间道9")
		r = new CRFoShan_road9();
	else if(room_name == "佛山林间道8")
		r = new CRFoShan_road8();
	else if(room_name == "佛山林间道7")
		r = new CRFoShan_road7();
	else if(room_name == "佛山林间道6")
		r = new CRFoShan_road6();
	else if(room_name == "佛山林间道5")
		r = new CRFoShan_road5();
	else if(room_name == "佛山林间道4")
		r = new CRFoShan_road4();
	else if(room_name == "佛山林间道3")
		r = new CRFoShan_road3();
	else if(room_name == "佛山林间道2")
		r = new CRFoShan_road2();
	else if(room_name == "佛山林间道14")
		r = new CRFoShan_road14();
	else if(room_name == "佛山林间道13")
		r = new CRFoShan_road13();
	else if(room_name == "佛山林间道12")
		r = new CRFoShan_road12();
	else if(room_name == "佛山林间道11")
		r = new CRFoShan_road11();
	else if(room_name == "佛山林间道10")
		r = new CRFoShan_road10();
	else if(room_name == "佛山林间道1")
		r = new CRFoShan_road1();
	else if(room_name == "佛山北门")
		r = new CRFoShan_northgate();
	else if(room_name == "佛山北帝庙")
		r = new CRFoShan_beidimiao();
	else if(room_name == "佛山英雄会馆")
		r = new CRFoShan_huiguan();
	else if(room_name == "佛山东门")
		r = new CRFoShan_eastgate();
	else if(room_name == "佛山英雄典当")
		r = new CRFoShan_dangpu();
	else if(room_name == "佛山南岭山口")
		r = new CRFoShan_nanling();
	else if(room_name == "佛山英雄楼二楼")
		r = new CRFoShan_yingxionglou2();
	else if(room_name == "佛山大海")
		r = new CRFoShan_dahai();

	return r;
}