#include "stdafx.h"
#include "../std/RField.h"
#include "../std/resident.h"

//   成都
#include "../d/chengdu/chengducity.h"
#include "../d/chengdu/chengdu_bingqidian.h"
#include "../d/chengdu/chengdu_wuhoucigate.h"
#include "../d/chengdu/chengdu_wuguan.h"
#include "../d/chengdu/chengdu_wangjianglou.h"
#include "../d/chengdu/chengdu_tidufu.h"
#include "../d/chengdu/chengdu_kedian2.h"
#include "../d/chengdu/chengdu_kedian.h"
#include "../d/chengdu/chengdu_jiudian.h"
#include "../d/chengdu/chengdu_caotang.h"
#include "../d/chengdu/chengdu_yaodian.h"
#include "../d/chengdu/chengdu_nanheqiao.h"
#include "../d/chengdu/chengdu_fuheqiaon.h"
#include "../d/chengdu/chengdu_path.h"
#include "../d/chengdu/chengdu_fuheqiaone.h"

#include "../d/chengdu/chengdu_dong.h"
#include "../d/chengdu/chengdu_xi.h"
#include "../d/chengdu/chengdu_zhong.h"

CRoom * Load_ChengDu(string room_name)
{
	CRoom * r = NULL;

	//成都
	if(room_name == "成都")
		r = new CRchengducity();
	else if(room_name == "成都提督府")
		r = new CRChengDu_tidufu();
	else if(room_name == "成都济世堂药店")
		r = new CRChengDu_yaodian();
	else if(room_name == "成都武侯祠大门")
		r = new CRChengDu_wuhoucigate();
	else if(room_name == "成都金牛武馆")
		r = new CRChengDu_wuguan();
	else if(room_name == "成都望江楼")
		r = new CRChengDu_wangjianglou();
	else if(room_name == "成都锦城驿二楼")
		r = new CRChengDu_kedian2();
	else if(room_name == "成都锦城驿")
		r = new CRChengDu_kedian();
	else if(room_name == "成都蜀都酒楼")
		r = new CRChengDu_jiudian();
	else if(room_name == "成都杜甫草堂")
		r = new CRChengDu_caotang();
	else if(room_name == "成都兵器铺")
		r = new CRChengDu_bingqidian();
	else if(room_name == "成都溪岸小路")
		r = new CRChengDu_path();
	else if(room_name == "成都南河桥")
		r = new CRChengDu_nanheqiao();
	else if(room_name == "成都府河桥")
		r = new CRChengDu_fuheqiaon();
	else if(room_name == "成都东府河桥")
		r = new CRChengDu_fuheqiaone();

	else if(room_name == "成都西")
		r = new CRchengdu_xi();
	else if(room_name == "成都东")
		r = new CRchengdu_dong();
	else if(room_name == "成都中")
		r = new CRchengdu_zhong();

	return r;
}