#include "stdafx.h"
#include "../server/Room.h"

//雪山寺
#include "../d/xueshan/xueshanscity.h"
#include "../d/xueshan/xueshans_cangjingge.h"
#include "../d/xueshan/xueshans_cangjingshi.h"
#include "../d/xueshan/xueshans_chanshi.h"
#include "../d/xueshan/xueshans_chufang.h"
#include "../d/xueshan/xueshans_dadian.h"
#include "../d/xueshan/xueshans_dilao.h"
#include "../d/xueshan/xueshans_kufang.h"
#include "../d/xueshan/xueshans_mishi.h"

CRoom * Load_XueShan(string room_name)
{
	CRoom * r = NULL;

	//雪山寺
    if(room_name == "雪山寺")
		r = new CRXueShancity();
    else if(room_name == "雪山寺密室")
		r = new CRXueShan_mishi();
    else if(room_name == "雪山寺库房")
		r = new CRXueShan_kufang();
    else if(room_name == "雪山寺地牢")
		r = new CRXueShan_dilao();
    else if(room_name == "雪山寺大殿")
		r = new CRXueShan_dadian();
    else if(room_name == "雪山寺厨房")
		r = new CRXueShan_chufang();
    else if(room_name == "雪山寺藏经阁")
		r = new CRXueShan_cangjingge();
    else if(room_name == "雪山寺藏经室")
		r = new CRXueShan_cangjingshi();
    else if(room_name == "雪山寺禅室")
		r = new CRXueShan_chanshi();

	return r;
}