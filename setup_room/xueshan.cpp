#include "stdafx.h"
#include "../server/Room.h"

//ѩɽ��
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

	//ѩɽ��
    if(room_name == "ѩɽ��")
		r = new CRXueShancity();
    else if(room_name == "ѩɽ������")
		r = new CRXueShan_mishi();
    else if(room_name == "ѩɽ�¿ⷿ")
		r = new CRXueShan_kufang();
    else if(room_name == "ѩɽ�µ���")
		r = new CRXueShan_dilao();
    else if(room_name == "ѩɽ�´��")
		r = new CRXueShan_dadian();
    else if(room_name == "ѩɽ�³���")
		r = new CRXueShan_chufang();
    else if(room_name == "ѩɽ�²ؾ���")
		r = new CRXueShan_cangjingge();
    else if(room_name == "ѩɽ�²ؾ���")
		r = new CRXueShan_cangjingshi();
    else if(room_name == "ѩɽ������")
		r = new CRXueShan_chanshi();

	return r;
}