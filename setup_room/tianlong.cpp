#include "stdafx.h"
#include "../server/Room.h"


//天龙寺
#include "../d/tianlongsi/tianlongsi_banruotai.h"
#include "../d/tianlongsi/tianlongsi_baodian.h"
#include "../d/tianlongsi/tianlongsi_cibeiyuan.h"
#include "../d/tianlongsi/tianlongsi_damen.h"
#include "../d/tianlongsi/tianlongsi_doumugong.h"
#include "../d/tianlongsi/tianlongsi_doushuai.h"
#include "../d/tianlongsi/tianlongsi_huangtianmen.h"
#include "../d/tianlongsi/tianlongsi_munitang.h"
#include "../d/tianlongsi/tianlongsi_qingxinge.h"
#include "../d/tianlongsi/tianlongsi_ruihemen.h"
#include "../d/tianlongsi/tianlongsi_sangwugong.h"
#include "../d/tianlongsi/tianlongsi_ta1.h"
#include "../d/tianlongsi/tianlongsi_ta2.h"
#include "../d/tianlongsi/tianlongsi_talin.h"
#include "../d/tianlongsi/tianlongsi_ta3.h"
#include "../d/tianlongsi/tianlongsi_wujingge.h"
#include "../d/tianlongsi/tianlongsi_wulege.h"
#include "../d/tianlongsi/tianlongsi_wuwoge.h"
#include "../d/tianlongsi/tianlongsi_wuwujing.h"
#include "../d/tianlongsi/tianlongsi_xianghemen.h"
#include "../d/tianlongsi/tianlongsi_yaotai.h"
#include "../d/tianlongsi/tianlongsi_yuhuayuan.h"
#include "../d/tianlongsi/tianlongsi_wuchangge.h"
#include "../d/tianlongsi/tianlongsi_tading.h"

CRoom * Load_TianLong(string room_name)
{
	CRoom * r = NULL;

	//天龙寺
	if(room_name == "天龙寺雨花院")
		r = new CRTianLongSi_yuhuayuan();
	else if(room_name == "天龙寺清都瑶台")
		r = new CRTianLongSi_yaotai();
	else if(room_name == "天龙寺翔鹤门")
		r = new CRTianLongSi_xianghemen();
	else if(room_name == "天龙寺无无境")
		r = new CRTianLongSi_wuwujing();
	else if(room_name == "天龙寺无我阁")
		r = new CRTianLongSi_wuwoge();
	else if(room_name == "天龙寺无乐阁")
		r = new CRTianLongSi_wulege();
	else if(room_name == "天龙寺无净阁")
		r = new CRTianLongSi_wujingge();
	else if(room_name == "天龙寺无常阁")
		r = new CRTianLongSi_wuchangge();
	else if(room_name == "天龙寺塔林")
		r = new CRTianLongSi_talin();
	else if(room_name == "天龙寺舍利塔3")
		r = new CRTianLongSi_ta3();
	else if(room_name == "天龙寺舍利塔2")
		r = new CRTianLongSi_ta2();
	else if(room_name == "天龙寺舍利塔1")
		r = new CRTianLongSi_ta1();
	else if(room_name == "天龙寺三无宫")
		r = new CRTianLongSi_sangwugong();
	else if(room_name == "天龙寺瑞鹤门")
		r = new CRTianLongSi_ruihemen();
	else if(room_name == "天龙寺清心阁")
		r = new CRTianLongSi_qingxinge();
	else if(room_name == "天龙寺牟尼堂")
		r = new CRTianLongSi_munitang();
	else if(room_name == "天龙寺晃天门")
		r = new CRTianLongSi_huangtianmen();
	else if(room_name == "天龙寺般若台")
		r = new CRTianLongSi_banruotai();
	else if(room_name == "天龙寺斗母宫")
		r = new CRTianLongSi_doumugong();
	else if(room_name == "天龙寺大门")
		r = new CRTianLongSi_damen();
	else if(room_name == "天龙寺慈悲院")
		r = new CRTianLongSi_cibeiyuan();
	else if(room_name == "天龙寺崇圣宝殿")
		r = new CRTianLongSi_baodian();
	else if(room_name == "天龙寺兜率大士院")
		r = new CRTianLongSi_doushuai();
	else if(room_name == "天龙寺塔顶")
		r = new CRTianLongSi_tading();

	return r;
}