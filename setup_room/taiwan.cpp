#include "stdafx.h"
#include "../server/Room.h"
#include "../std/resident.h"

//台湾
#include "../d/taiwan/taiwan_chiqian.h"
#include "../d/taiwan/taiwan_dagou.h"
#include "../d/taiwan/taiwan_dahai.h"
#include "../d/taiwan/taiwan_huangdi.h"
#include "../d/taiwan/taiwan_jilong.h"
#include "../d/taiwan/taiwan_riyuetan.h"
#include "../d/taiwan/taiwan_fengren.h"
#include "../d/taiwan/taiwan_jinku.h"
#include "../d/taiwan/taiwan_jvmin.h"
#include "../d/taiwan/taiwan_lifa.h"
#include "../d/taiwan/taiwan_sixing.h"
#include "../d/taiwan/taiwan_taohua.h"
#include "../d/taiwan/taiwan_xingzheng.h"
#include "../d/taiwan/taiwan_zongtong.h"

CRoom * Load_TaiWan(string room_name)
{
	CRoom * r = NULL;

	//台湾
	if(room_name == "台湾日月潭")
		r = new CRTaiWan_riyuetan();
	else if(room_name == "台湾鸡笼港")
		r = new CRTaiWan_jilong();
	else if(room_name == "台湾荒地")
		r = new CRTaiWan_huangdi();
	else if(room_name == "台湾大海")
		r = new CRTaiWan_dahai();
	else if(room_name == "台湾赤嵌城")
		r = new CRTaiWan_chiqian();
	else if(room_name == "台湾打狗港")
		r = new CRTaiWan_dagou();
	else if(room_name == "台湾疯人院")
		r = new CRTaiWan_fengren();
	else if(room_name == "台湾形正院金库")
		r = new CRTaiWan_jinku();
	else if(room_name == "台湾正药居民区")
		r = new CRTaiWan_jvmin();
	else if(room_name == "台湾力伐院")
		r = new CRTaiWan_lifa();
	else if(room_name == "台湾力伐院私刑房")
		r = new CRTaiWan_sixing();
	else if(room_name == "台湾桃花院")
		r = new CRTaiWan_taohua();
	else if(room_name == "台湾形正院")
		r = new CRTaiWan_xingzheng();
	else if(room_name == "台湾忠通府")
		r = new CRTaiWan_zongtong();	

	return r;
}