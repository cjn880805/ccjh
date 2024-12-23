#include "stdafx.h"
#include "../std/RField.h"

//泰山
#include "../d/taishan/taishancity.h"
#include "../d/taishan/taishan_baihe.h"
#include "../d/taishan/taishan_beitian.h"
#include "../d/taishan/taishan_bixia.h"
#include "../d/taishan/taishan_bozang.h"
#include "../d/taishan/taishan_daizong.h"
#include "../d/taishan/taishan_dongtian.h"
#include "../d/taishan/taishan_doumo.h"
#include "../d/taishan/taishan_ertian.h"
#include "../d/taishan/taishan_fengchan.h"
#include "../d/taishan/taishan_lianhua.h"
#include "../d/taishan/taishan_longmen.h"
#include "../d/taishan/taishan_nantian.h"
#include "../d/taishan/taishan_riguan.h"
#include "../d/taishan/taishan_shengxian.h"
#include "../d/taishan/taishan_shijin.h"
#include "../d/taishan/taishan_shixin.h"
#include "../d/taishan/taishan_tanhai.h"
#include "../d/taishan/taishan_tianjie.h"
#include "../d/taishan/taishan_weipin.h"
#include "../d/taishan/taishan_wudafu.h"
#include "../d/taishan/taishan_xitian.h"
#include "../d/taishan/taishan_yitian.h"
#include "../d/taishan/taishan_yueguan.h"
#include "../d/taishan/taishan_yuhuang.h"
#include "../d/taishan/taishan_zhangren.h"
#include "../d/taishan/taishan_huima.h"
#include "../d/taishan/taishan_shanjiao.h"
#include "../d/taishan/taishan_yidao.h"

CRoom * Load_TaiShan(string room_name)
{
	CRoom * r = NULL;

	//泰山
    if(room_name == "泰山")
		r = new CRTaiShancity();
    else if(room_name == "泰山丈人峰")
		r = new CRTaiShan_zhangren();
    else if(room_name == "泰山玉皇顶")
		r = new CRTaiShan_yuhuang();
    else if(room_name == "泰山月观峰")
		r = new CRTaiShan_yueguan();
    else if(room_name == "泰山一天门")
		r = new CRTaiShan_yitian();
    else if(room_name == "泰山西天门")
		r = new CRTaiShan_xitian();
    else if(room_name == "泰山五大夫松")
		r = new CRTaiShan_wudafu();
    else if(room_name == "泰山围屏山")
		r = new CRTaiShan_weipin();
    else if(room_name == "泰山天街")
		r = new CRTaiShan_tianjie();
    else if(room_name == "泰山探海石")
		r = new CRTaiShan_tanhai();
    else if(room_name == "泰山试心石")
		r = new CRTaiShan_shixin();
    else if(room_name == "泰山石经峪")
		r = new CRTaiShan_shijin();
    else if(room_name == "泰山升仙坊")
		r = new CRTaiShan_shengxian();
    else if(room_name == "泰山日观峰")
		r = new CRTaiShan_riguan();
    else if(room_name == "泰山南天门")
		r = new CRTaiShan_nantian();
    else if(room_name == "泰山龙门")
		r = new CRTaiShan_longmen();
    else if(room_name == "泰山莲花峰")
		r = new CRTaiShan_lianhua();
    else if(room_name == "泰山回马岭")
		r = new CRTaiShan_huima();
    else if(room_name == "泰山封禅台")
		r = new CRTaiShan_fengchan();
    else if(room_name == "泰山二天门")
		r = new CRTaiShan_ertian();
    else if(room_name == "泰山白鹤泉")
		r = new CRTaiShan_baihe();
    else if(room_name == "泰山东天门")
		r = new CRTaiShan_dongtian();
    else if(room_name == "泰山岱宗坊")
		r = new CRTaiShan_daizong();
    else if(room_name == "泰山宝藏岭")
		r = new CRTaiShan_bozang();
    else if(room_name == "泰山碧霞祠")
		r = new CRTaiShan_bixia();
    else if(room_name == "泰山北天门")
		r = new CRTaiShan_beitian();
    else if(room_name == "泰山斗母宫")
		r = new CRTaiShan_doumo();
    else if(room_name == "泰山大驿道")
		r = new CRTaiShan_yidao();
    else if(room_name == "泰山山脚")
		r = new CRTaiShan_shanjiao();

	return r;
}