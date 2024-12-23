#include "stdafx.h"
#include "../server/Room.h"
#include "../std/resident.h"

//     苏州城
#include "../d/suzhou/suzhoucity.h" 
#include "../d/suzhou/suzhou_baodaiqiao.h" 
#include "../d/suzhou/suzhou_bingying.h" 
#include "../d/suzhou/suzhou_canlangting.h" 
#include "../d/suzhou/suzhou_chaguan.h" 
#include "../d/suzhou/suzhou_dangpu.h" 
#include "../d/suzhou/suzhou_datiepu.h" 
#include "../d/suzhou/suzhou_jiudai.h" 
#include "../d/suzhou/suzhou_jubaozhai.h" 
#include "../d/suzhou/suzhou_kedian.h" 
#include "../d/suzhou/suzhou_leitai.h" 
#include "../d/suzhou/suzhou_liuyuan.h" 
#include "../d/suzhou/suzhou_majiu.h" 
#include "../d/suzhou/suzhou_shizilin.h" 
#include "../d/suzhou/suzhou_shuchang.h" 
#include "../d/suzhou/suzhou_shuyuan.h" 
#include "../d/suzhou/suzhou_tingyu.h" 
#include "../d/suzhou/suzhou_wanjing.h" 
#include "../d/suzhou/suzhou_xiyuan.h" 
#include "../d/suzhou/suzhou_xuanmiao.h" 
#include "../d/suzhou/suzhou_yamen.h" 
#include "../d/suzhou/suzhou_yaopu.h" 
#include "../d/suzhou/suzhou_yunhematou.h" 
#include "../d/suzhou/suzhou_zijinan.h"
#include "../d/suzhou/suzhou_dongmen.h"
//添加
#include "../d/suzhou/suzhou_bailianchi.h"
#include "../d/suzhou/suzhou_yanyutang.h"
#include "../d/suzhou/suzhou_fengqiao.h"
#include "../d/suzhou/suzhou_zhenshi.h"
#include "../d/suzhou/suzhou_zhishuang.h"
#include "../d/suzhou/suzhou_zhipoxuan.h"
#include "../d/suzhou/suzhou_zhenquting.h"
#include "../d/suzhou/suzhou_zhenniang.h"
#include "../d/suzhou/suzhou_wenmeige.h"
#include "../d/suzhou/suzhou_toumenshan.h"
#include "../d/suzhou/suzhou_tielingguan.h"
#include "../d/suzhou/suzhou_sunwuting.h"
#include "../d/suzhou/suzhou_shijianshi.h"
#include "../d/suzhou/suzhou_road2.h"
#include "../d/suzhou/suzhou_road1.h"
#include "../d/suzhou/suzhou_qianrenshi.h"
#include "../d/suzhou/suzhou_lixuetang.h"
#include "../d/suzhou/suzhou_huqiu.h"
#include "../d/suzhou/suzhou_hehuating.h"
#include "../d/suzhou/suzhou_hanshansi.h"
#include "../d/suzhou/suzhou_hanhanquan.h"
#include "../d/suzhou/suzhou_erxianting.h"
#include "../d/suzhou/suzhou_gumujiaohe.h"
#include "../d/suzhou/suzhou_nanmen.h"

#include "../d/suzhou/suzhounan.h"
#include "../d/suzhou/suzhouzhong.h"
#include "../d/suzhou/suzhoubei.h"

CRoom * Load_SuZhou(string room_name)
{
	CRoom * r = NULL;

	//     苏州城
	if(room_name == "苏州")
		r = new CRsuzhoucity();
	else if(room_name == "苏州戏园子")
		r = new CRSuZhou_xiyuan();
	else if(room_name == "苏州马厩")
		r = new CRSuZhou_majiu();
	else if(room_name == "苏州府衙")
		r = new CRSuZhou_yamen();
	else if(room_name == "苏州宝带桥")
		r = new CRSuZhou_baodaiqiao();
	else if(room_name == "苏州兵营")
		r = new CRSuZhou_bingying();
	else if(room_name == "苏州沧浪亭")
		r = new CRSuZhou_canlangting();
	else if(room_name == "苏州茶馆")
		r = new CRSuZhou_chaguan();
	else if(room_name == "苏州宝和记")
		r = new CRSuZhou_dangpu();
	else if(room_name == "苏州打铁铺")
		r = new CRSuZhou_datiepu();
	else if(room_name == "苏州春在楼")
		r = new CRSuZhou_jiudain();
	else if(room_name == "苏州聚宝斋")
		r = new CRSuZhou_jubaozhai();
	else if(room_name == "苏州客店")
		r = new CRSuZhou_kedian();
	else if(room_name == "苏州擂台前广场")
		r = new CRSuZhou_leitai();
	else if(room_name == "苏州留园")
		r = new CRSuZhou_liuyuan();
	else if(room_name == "苏州狮子林")
		r = new CRSuZhou_shizilin();
	else if(room_name == "苏州书场")
		r = new CRSuZhou_shuchang();
	else if(room_name == "苏州书院")
		r = new CRSuZhou_shuyuan();
	else if(room_name == "苏州听雨轩")
		r = new CRSuZhou_tingyu();
	else if(room_name == "苏州万景山庄")
		r = new CRSuZhou_wanjing();
	else if(room_name == "苏州玄妙观")
		r = new CRSuZhou_xuanmiao();
	else if(room_name == "苏州立春堂")
		r = new CRSuZhou_yaopu();
	else if(room_name == "苏州运河码头")
		r = new CRSuZhou_yunhematou();
	else if(room_name == "苏州紫金庵")
		r = new CRSuZhou_zijinan();
	else if(room_name == "苏州东门")
		r = new CRSuZhou_dongmen();
	//添加
	else if(room_name == "苏州致爽阁")
		r = new CRSuZhou_zhishuang();
	else if(room_name == "苏州揖峰指柏轩")
		r = new CRSuZhou_zhipoxuan();
	else if(room_name == "苏州枕石")
		r = new CRSuZhou_zhenshi();
	else if(room_name == "苏州真趣亭")
		r = new CRSuZhou_zhenquting();
	else if(room_name == "苏州白莲池")
		r = new CRSuZhou_bailianchi();
	else if(room_name == "苏州问梅阁")
		r = new CRSuZhou_wenmeige();
	else if(room_name == "苏州头门山")
		r = new CRSuZhou_toumenshan();
	else if(room_name == "苏州铁岭关")
		r = new CRSuZhou_tielingguan();
	else if(room_name == "苏州孙武亭")
		r = new CRSuZhou_sunwuting();
	else if(room_name == "苏州试剑石")
		r = new CRSuZhou_shijianshi();
	else if(room_name == "苏州青石官道2")
		r = new CRSuZhou_road2();
	else if(room_name == "苏州青石官道1")
		r = new CRSuZhou_road1();
	else if(room_name == "苏州千人石")
		r = new CRSuZhou_qianrenshi();
	else if(room_name == "苏州立雪堂")
		r = new CRSuZhou_lixuetang();
	else if(room_name == "苏州虎丘山")
		r = new CRSuZhou_huqiu();
	else if(room_name == "苏州荷花厅")
		r = new CRSuZhou_hehuating();
	else if(room_name == "苏州寒山寺")
		r = new CRSuZhou_hanshansi();
	else if(room_name == "苏州憨憨泉")
		r = new CRSuZhou_hanhanquan();
	else if(room_name == "苏州古木交诃")
		r = new CRSuZhou_gumujiaohe();
	else if(room_name == "苏州枫桥")
		r = new CRSuZhou_fengqiao();
	else if(room_name == "苏州二仙亭")
		r = new CRSuZhou_erxianting();
	else if(room_name == "苏州燕誉堂")
		r = new CRSuZhou_yanyutang();
	else if(room_name == "苏州真娘墓")
		r = new CRSuZhou_zhenniang();
	else if(room_name == "苏州南门")
		r = new CRSuZhou_nanmen();
	else if(room_name == "苏州南")
		r = new CRsuzhounan();
	else if(room_name == "苏州中")
		r = new CRsuzhouzhong();
	else if(room_name == "苏州北")
		r = new CRsuzhoubei();

	return r;
}