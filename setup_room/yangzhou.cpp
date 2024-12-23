#include "stdafx.h"
#include "../server/Room.h"
#include "../std/resident.h"
#include "../std/FightRoom.h"

//   扬州城
#include "../d/yangzhou/yangzhoucity.h"
#include "../d/yangzhou/yangzhou_bingying.h"
#include "../d/yangzhou/yangzhou_caizhu.h"
#include "../d/yangzhou/yangzhou_chaguan.h"
#include "../d/yangzhou/yangzhou_dangpu.h"
#include "../d/yangzhou/yangzhou_datiepu.h"
#include "../d/yangzhou/yangzhou_duchang.h"
#include "../d/yangzhou/yangzhou_kedian.h"
#include "../d/yangzhou/yangzhou_lichunyuan.h"
#include "../d/yangzhou/yangzhou_lichunyuan2.h"
#include "../d/yangzhou/yangzhou_majiu.h"
#include "../d/yangzhou/yangzhou_qianzhuang.h"
#include "../d/yangzhou/yangzhou_shuyuan.h"
#include "../d/yangzhou/yangzhou_wuguan.h"
#include "../d/yangzhou/yangzhou_wumiao.h"
#include "../d/yangzhou/yangzhou_yamen.h"
#include "../d/yangzhou/yangzhou_yaopu.h"
#include "../d/yangzhou/yangzhou_zahuopu.h"
#include "../d/yangzhou/yangzhou_zuixianlou.h"
#include "../d/yangzhou/yangzhou_taohua5.h"
#include "../d/yangzhou/yangzhou_taohua4.h"
#include "../d/yangzhou/yangzhou_taohua3.h"
#include "../d/yangzhou/yangzhou_taohua2.h"
#include "../d/yangzhou/yangzhou_taohua1.h"

#include "../d/yangzhou/yangzhou_dongbei.h"
#include "../d/yangzhou/yangzhou_dongnan.h"
#include "../d/yangzhou/yangzhou_xibei.h"
#include "../d/yangzhou/yangzhou_xinan.h"

//扬州郊外
#include "../d/yzjiaowai/yzjw_beimen.h"
#include "../d/yzjiaowai/yzjw_beiyidao.h"
#include "../d/yzjiaowai/yzjw_dadao.h"
#include "../d/yzjiaowai/yzjw_dongmen.h"
#include "../d/yzjiaowai/yzjw_dongyidao.h"
#include "../d/yzjiaowai/yzjw_jiaowai1.h"
#include "../d/yzjiaowai/yzjw_jiaowai10.h"
#include "../d/yzjiaowai/yzjw_jiaowai11.h"
#include "../d/yzjiaowai/yzjw_jiaowai12.h"
#include "../d/yzjiaowai/yzjw_jiaowai2.h"
#include "../d/yzjiaowai/yzjw_jiaowai3.h"
#include "../d/yzjiaowai/yzjw_jiaowai4.h"
#include "../d/yzjiaowai/yzjw_jiaowai5.h"
#include "../d/yzjiaowai/yzjw_jiaowai6.h"
#include "../d/yzjiaowai/yzjw_jiaowai7.h"
#include "../d/yzjiaowai/yzjw_jiaowai8.h"
#include "../d/yzjiaowai/yzjw_jiaowai9.h"
#include "../d/yzjiaowai/yzjw_milin1.h"
#include "../d/yzjiaowai/yzjw_milin2.h"
#include "../d/yzjiaowai/yzjw_milin3.h"
#include "../d/yzjiaowai/yzjw_milin4.h"
#include "../d/yzjiaowai/yzjw_milin5.h"
#include "../d/yzjiaowai/yzjw_milin6.h"
#include "../d/yzjiaowai/yzjw_milin7.h"
#include "../d/yzjiaowai/yzjw_nanmen.h"
#include "../d/yzjiaowai/yzjw_nanxun.h"
#include "../d/yzjiaowai/yzjw_pomiao.h"
#include "../d/yzjiaowai/yzjw_shanlu1.h"
#include "../d/yzjiaowai/yzjw_shanlu2.h"
#include "../d/yzjiaowai/yzjw_shulin.h"
#include "../d/yzjiaowai/yzjw_tiandi.h"
#include "../d/yzjiaowai/yzjw_wudao.h"
#include "../d/yzjiaowai/yzjw_ximen.h"
#include "../d/yzjiaowai/yzjw_ximenroad.h"
#include "../d/yzjiaowai/yzjw_yixing.h"

CRoom * Load_YangZhou(string room_name)
{
	CRoom * r = NULL;

	//   扬州城
	if(room_name == "扬州城")
		r = new CRyangzhoucity();
	else if(room_name == "扬州兵营")
		r = new CRYangZhou_bingying();
	else if(room_name == "扬州财主大门")
		r = new CRYangZhou_caizhu();
	else if(room_name == "扬州春来茶馆")
		r = new CRYangZhou_chaguan();
	else if(room_name == "扬州当铺")
		r = new CRYangZhou_dangpu();
	else if(room_name == "扬州打铁铺")
		r = new CRYangZhou_datiepu();
	else if(room_name == "扬州赌场")
		r = new CRYangZhou_duchang();
	else if(room_name == "扬州客店")
		r = new CRYangZhou_kedian();
	else if(room_name == "扬州丽春院")
		r = new CRYangZhou_lichunyuan();
	else if(room_name == "扬州丽春院二楼")
		r = new CRYangZhou_lichunyuan2();
	else if(room_name == "扬州马厩")
		r = new CRYangZhou_majiu();
	else if(room_name == "扬州钱庄")
		r = new CRYangZhou_qianzhuang();
	else if(room_name == "扬州书院")
		r = new CRYangZhou_shuyuan();
	else if(room_name == "扬州武馆")
		r = new CRYangZhou_wuguan();
	else if(room_name == "扬州武庙")
		r = new CRYangZhou_wumiao();
	else if(room_name == "扬州衙门大门")
		r = new CRYangZhou_yamen();
	else if(room_name == "扬州药铺")
		r = new CRYangZhou_yaopu();
	else if(room_name == "扬州杂货铺")
		r = new CRYangZhou_zahuopu();
	else if(room_name == "扬州醉仙楼")
		r = new CRYangZhou_zuixianlou();
	else if(room_name == "扬州桃花坪")
		r = new CRYangZhou_taohua5();
	else if(room_name == "扬州桃花村")
		r = new CRYangZhou_taohua4();
	else if(room_name == "扬州桃花谷")
		r = new CRYangZhou_taohua3();
	else if(room_name == "扬州桃花溪")
		r = new CRYangZhou_taohua2();
	else if(room_name == "扬州桃花林")
		r = new CRYangZhou_taohua1();
		
	else if(room_name == "扬州东北")
		r = new CRyangzhou_dongbei();
	else if(room_name == "扬州东南")
		r = new CRyangzhou_dongnan();
	else if(room_name == "扬州西北")
		r = new CRyangzhou_xibei();
	else if(room_name == "扬州西南")
		r = new CRyangzhou_xinan();

	//扬州郊外
	if(room_name == "扬州宜兴")
		r = new CRYZJW_yixing();
	else if(room_name == "扬州西门大道")
		r = new CRYZJW_ximenroad();
	else if(room_name == "扬州西门")
		r = new CRYZJW_ximen();
	else if(room_name == "扬州武道场")
		r = new CRYZJW_wudao();
	else if(room_name == "扬州田地")
		r = new CRYZJW_tiandi();
	else if(room_name == "扬州树林")
		r = new CRYZJW_shulin();
	else if(room_name == "扬州山路2")
		r = new CRYZJW_shanlu2();
	else if(room_name == "扬州山路1")
		r = new CRYZJW_shanlu1();
	else if(room_name == "扬州土地庙")
		r = new CRYZJW_pomiao();
	else if(room_name == "扬州南浔")
		r = new CRYZJW_nanxun();
	else if(room_name == "扬州南门")
		r = new CRYZJW_nanmen();
	else if(room_name == "扬州青竹林7")
		r = new CRYZJW_milin7();
	else if(room_name == "扬州青竹林6")
		r = new CRYZJW_milin6();
	else if(room_name == "扬州青竹林5")
		r = new CRYZJW_milin5();
	else if(room_name == "扬州北门")
		r = new CRYZJW_beimen();
	else if(room_name == "扬州青竹林3")
		r = new CRYZJW_milin3();
	else if(room_name == "扬州青竹林2")
		r = new CRYZJW_milin2();
	else if(room_name == "扬州青竹林1")
		r = new CRYZJW_milin1();
	else if(room_name == "扬州密林9")
		r = new CRYZJW_jiaowai9();
	else if(room_name == "扬州草地8")
		r = new CRYZJW_jiaowai8();
	else if(room_name == "扬州草地7")
		r = new CRYZJW_jiaowai7();
	else if(room_name == "扬州树林6")
		r = new CRYZJW_jiaowai6();
	else if(room_name == "扬州密林5")
		r = new CRYZJW_jiaowai5();
	else if(room_name == "扬州密林4")
		r = new CRYZJW_jiaowai4();
	else if(room_name == "扬州树林3")
		r = new CRYZJW_jiaowai3();
	else if(room_name == "扬州树林2")
		r = new CRYZJW_jiaowai2();
	else if(room_name == "扬州密林12")
		r = new CRYZJW_jiaowai12();
	else if(room_name == "扬州密林11")
		r = new CRYZJW_jiaowai11();
	else if(room_name == "扬州密林10")
		r = new CRYZJW_jiaowai10();
	else if(room_name == "扬州草地1")
		r = new CRYZJW_jiaowai1();
	else if(room_name == "扬州东驿道")
		r = new CRYZJW_dongyidao();
	else if(room_name == "扬州东门")
		r = new CRYZJW_dongmen();
	else if(room_name == "扬州青石大道")
		r = new CRYZJW_dadao();
	else if(room_name == "扬州北驿道")
		r = new CRYZJW_beiyidao();
	else if(room_name == "扬州青竹林4")
		r = new CRYZJW_milin4();

	return r;
}