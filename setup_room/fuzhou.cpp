#include "stdafx.h"
#include "../server/Room.h"
#include "../std/resident.h"

//   福州
#include "../d/fuzhou/fuzhoucity.h"
#include "../d/fuzhou/fuzhou_biaoju.h"
#include "../d/fuzhou/fuzhou_jiulou.h"
#include "../d/fuzhou/fuzhou_laozhai.h"
#include "../d/fuzhou/fuzhou_rongcheng.h"
#include "../d/fuzhou/fuzhou_rongcheng2.h"
#include "../d/fuzhou/fuzhou_wuxiang.h"
#include "../d/fuzhou/fuzhou_xiangyang.h"
#include "../d/fuzhou/fuzhou_xiaochang.h"
#include "../d/fuzhou/fuzhou_xichansi.h"
#include "../d/fuzhou/fuzhou_yongquan.h"
#include "../d/fuzhou/fuzhou_zahuopu.h"
#include "../d/fuzhou/fuzhou_houyuan.h"
#include "../d/fuzhou/fuzhou_xiwuchang.h"
#include "../d/fuzhou/fuzhou_neizhai.h"
#include "../d/fuzhou/fuzhou_zhengting.h"
#include "../d/fuzhou/fuzhou_yamen.h"
#include "../d/fuzhou/fuzhou_nanmen.h"
#include "../d/fuzhou/fuzhou_fzroad.h"

#include "../d/fuzhou/fuzhou_xi.h"
#include "../d/fuzhou/fuzhou_dong.h"
#include "../d/fuzhou/fuzhou_nan.h"

CRoom * Load_FuZhou(string room_name)
{
	CRoom * r = NULL;

	//  福州
	if(room_name == "福州")
		r = new CRfuzhoucity();
	else if(room_name == "福州杂货铺")
		r = new CRfuzhou_zahuopu();
	else if(room_name == "福州涌泉寺")
		r = new CRfuzhou_yongquan();
	else if(room_name == "福州提督衙门")
		r = new CRfuzhou_yamen();
	else if(room_name == "福州西禅寺")
		r = new CRfuzhou_xichansi();
	else if(room_name == "福州校场")
		r = new CRfuzhou_xiaochang();
	else if(room_name == "福州向阳巷")
		r = new CRfuzhou_xiangyang();
	else if(room_name == "福州无相庵")
		r = new CRfuzhou_wuxiang();
	else if(room_name == "福州榕城驿")
		r = new CRfuzhou_rongcheng();
	else if(room_name == "福州榕城驿二楼")
		r = new CRfuzhou_rongcheng2();
	else if(room_name == "福州福威镖局")
		r = new CRfuzhou_biaoju();
	else if(room_name == "福州向阳老宅")
		r = new CRfuzhou_laozhai();
	else if(room_name == "福州味中味")
		r = new CRfuzhou_jiulou();
	else if(room_name == "福州福威镖局正厅")
		r = new CRfuzhou_zhengting();
	else if(room_name == "福州福威镖局后院")
		r = new CRfuzhou_houyuan();
	else if(room_name == "福州福威镖局内宅")
		r = new CRfuzhou_neizhai();
	else if(room_name == "福州福威镖局习武场")
		r = new CRfuzhou_xiwuchang();
	else if(room_name == "福州南门")
		r = new CRfuzhou_nanmen();
	else if(room_name == "福州闽中大道")
		r = new CRfuzhou_fzroad();
		
	else if(room_name == "福州西")
		r = new CRfuzhou_xi();
	else if(room_name == "福州东")
		r = new CRfuzhou_dong();
	else if(room_name == "福州南")
		r = new CRfuzhou_nan();

	//设置城市区
	if(r) r->set("city", 1);

	return r;
}