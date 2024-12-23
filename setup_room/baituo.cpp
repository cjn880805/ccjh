#include "stdafx.h"
#include "../std/RField.h"

//白驼山
#include "../d/baituoshan/baituoshancity.h"
#include "../d/baituoshan/baituoshan_houmen.h"
#include "../d/baituoshan/baituoshan_houyuan.h"
#include "../d/baituoshan/baituoshan_huayuan.h"
#include "../d/baituoshan/baituoshan_jiudian.h"
#include "../d/baituoshan/baituoshan_liangong.h"
#include "../d/baituoshan/baituoshan_menlang.h"
#include "../d/baituoshan/baituoshan_neishi.h"
#include "../d/baituoshan/baituoshan_nongshe.h"
#include "../d/baituoshan/baituoshan_restroom.h"
#include "../d/baituoshan/baituoshan_shanlu.h"
#include "../d/baituoshan/baituoshan_shanlu1.h"
#include "../d/baituoshan/baituoshan_sheyuan.h"
#include "../d/baituoshan/baituoshan_shijie.h"
#include "../d/baituoshan/baituoshan_shoushe.h"
#include "../d/baituoshan/baituoshan_shulin.h"
#include "../d/baituoshan/baituoshan_shulin1.h"
#include "../d/baituoshan/baituoshan_storeroom.h"
#include "../d/baituoshan/baituoshan_tuyuan.h"
#include "../d/baituoshan/baituoshan_wuqiku.h"
#include "../d/baituoshan/baituoshan_xiaolu1.h"
#include "../d/baituoshan/baituoshan_xiaolu2.h"
#include "../d/baituoshan/baituoshan_xiaolu3.h"
#include "../d/baituoshan/baituoshan_xiaolu4.h"
#include "../d/baituoshan/baituoshan_xijie.h"
#include "../d/baituoshan/baituoshan_ximen.h"
#include "../d/baituoshan/baituoshan_yaofang.h"
#include "../d/baituoshan/baituoshan_yuanzi.h"
#include "../d/baituoshan/baituoshan_zhulin.h"
#include "../d/baituoshan/baituoshan_zhuyuan.h"
#include "../d/baituoshan/baituoshan_bridge.h"
#include "../d/baituoshan/baituoshan_caifang.h"
#include "../d/baituoshan/baituoshan_cao1.h"
#include "../d/baituoshan/baituoshan_cao2.h"
#include "../d/baituoshan/baituoshan_caomeide.h"
#include "../d/baituoshan/baituoshan_caoping.h"
#include "../d/baituoshan/baituoshan_cave.h"
#include "../d/baituoshan/baituoshan_changlang.h"
#include "../d/baituoshan/baituoshan_chufang.h"
#include "../d/baituoshan/baituoshan_damen.h"
#include "../d/baituoshan/baituoshan_datiepu.h"
#include "../d/baituoshan/baituoshan_dating.h"
#include "../d/baituoshan/baituoshan_dongjie.h"
#include "../d/baituoshan/baituoshan_dongkou.h"
#include "../d/baituoshan/baituoshan_dongnei.h"
#include "../d/baituoshan/baituoshan_fang.h"
#include "../d/baituoshan/baituoshan_fende.h"
#include "../d/baituoshan/baituoshan_gebi.h"
#include "../d/baituoshan/baituoshan_guangchang.h"

CRoom * Load_BaiTuo(string room_name)
{
	CRoom * r = NULL;

	//白驼山
	if(room_name == "白驼山")
		r = new CRBaiTuoShancity();
	else if(room_name == "白驼山竹园")
		r = new CRBaiTuoShan_zhuyuan();
	else if(room_name == "白驼山竹林")
		r = new CRBaiTuoShan_zhulin();
	else if(room_name == "白驼山院子")
		r = new CRBaiTuoShan_yuanzi();
	else if(room_name == "白驼山药房")
		r = new CRBaiTuoShan_yaofang();
	else if(room_name == "白驼山西门")
		r = new CRBaiTuoShan_ximen();
	else if(room_name == "白驼山西街")
		r = new CRBaiTuoShan_xijie();
	else if(room_name == "白驼山武器库")
		r = new CRBaiTuoShan_wuqiku();
	else if(room_name == "白驼山兔苑")
		r = new CRBaiTuoShan_tuyuan();
	else if(room_name == "白驼山储藏室")
		r = new CRBaiTuoShan_storeroom();
	else if(room_name == "白驼山树林1")
		r = new CRBaiTuoShan_shulin1();
	else if(room_name == "白驼山树林")
		r = new CRBaiTuoShan_shulin();
	else if(room_name == "白驼山兽舍")
		r = new CRBaiTuoShan_shoushe();
	else if(room_name == "白驼山石阶")
		r = new CRBaiTuoShan_shijie();
	else if(room_name == "白驼山蛇园")
		r = new CRBaiTuoShan_sheyuan();
	else if(room_name == "白驼山山路1")
		r = new CRBaiTuoShan_shanlu1();
	else if(room_name == "白驼山山路")
		r = new CRBaiTuoShan_shanlu();
	else if(room_name == "白驼山休息室")
		r = new CRBaiTuoShan_restroom();
	else if(room_name == "白驼山农舍")
		r = new CRBaiTuoShan_nongshe();
	else if(room_name == "白驼山内室")
		r = new CRBaiTuoShan_neishi();
	else if(room_name == "白驼山门廊")
		r = new CRBaiTuoShan_menlang();
	else if(room_name == "白驼山练功场")
		r = new CRBaiTuoShan_liangong();
	else if(room_name == "白驼山酒店")
		r = new CRBaiTuoShan_jiudian();
	else if(room_name == "白驼山花园")
		r = new CRBaiTuoShan_huayuan();
	else if(room_name == "白驼山后院")
		r = new CRBaiTuoShan_houyuan();
	else if(room_name == "白驼山广场")
		r = new CRBaiTuoShan_guangchang();
	else if(room_name == "白驼山练功房")
		r = new CRBaiTuoShan_fang();
	else if(room_name == "白驼山东街")
		r = new CRBaiTuoShan_dongjie();
	else if(room_name == "白驼山大厅")
		r = new CRBaiTuoShan_dating();
	else if(room_name == "白驼山大门")
		r = new CRBaiTuoShan_damen();
	else if(room_name == "白驼山厨房")
		r = new CRBaiTuoShan_chufang();
	else if(room_name == "白驼山长廊")
		r = new CRBaiTuoShan_changlang();
	else if(room_name == "白驼山岩洞")
		r = new CRBaiTuoShan_cave();
	else if(room_name == "白驼山草坪")
		r = new CRBaiTuoShan_caoping();
	else if(room_name == "白驼山草莓地")
		r = new CRBaiTuoShan_caomeide();
	else if(room_name == "白驼山草丛2")
		r = new CRBaiTuoShan_cao2();
	else if(room_name == "白驼山草丛1")
		r = new CRBaiTuoShan_cao1();
	else if(room_name == "白驼山柴房")
		r = new CRBaiTuoShan_caifang();
	else if(room_name == "白驼山小桥")
		r = new CRBaiTuoShan_bridge();
	else if(room_name == "白驼山打铁铺")
		r = new CRBaiTuoShan_datiepu();
	else if(room_name == "白驼山小路3")
		r = new CRBaiTuoShan_xiaolu3();
	else if(room_name == "白驼山小路2")
		r = new CRBaiTuoShan_xiaolu2();
	else if(room_name == "白驼山小路1")
		r = new CRBaiTuoShan_xiaolu1();
	else if(room_name == "白驼山后门")
		r = new CRBaiTuoShan_houmen();
	else if(room_name == "白驼山戈壁")
		r = new CRBaiTuoShan_gebi();
	else if(room_name == "白驼山坟地")
		r = new CRBaiTuoShan_fende();
	else if(room_name == "白驼山洞内")
		r = new CRBaiTuoShan_dongnei();
	else if(room_name == "白驼山洞口")
		r = new CRBaiTuoShan_dongkou();
	else if(room_name == "白驼山小路4")
		r = new CRBaiTuoShan_xiaolu4();

	return r;
}