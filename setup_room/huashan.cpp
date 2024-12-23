#include "stdafx.h"
#include "../server/Room.h"
#include "../server/Char.h"
#include "../std/resident.h"

//华山
#include "../d/huashan/huashan_bingqifang.h"
#include "../d/huashan/huashan_baichi.h"
#include "../d/huashan/huashan_buwei1.h"
#include "../d/huashan/huashan_buwei3.h"
#include "../d/huashan/huashan_canglong.h"
#include "../d/huashan/huashan_changlang.h"
#include "../d/huashan/huashan_chaopath2.h"
#include "../d/huashan/huashan_chaoyang.h"
#include "../d/huashan/huashan_chaoyangpath1.h"
#include "../d/huashan/huashan_chengxiang.h"
#include "../d/huashan/huashan_chufang.h"
#include "../d/huashan/huashan_garden.h"
#include "../d/huashan/huashan_houyuan.h"
#include "../d/huashan/huashan_huixinshi.h"
#include "../d/huashan/huashan_husun.h"
#include "../d/huashan/huashan_jiashan.h"
#include "../d/huashan/huashan_jinsuo.h"
#include "../d/huashan/huashan_jushi.h"
#include "../d/huashan/huashan_laojun.h"
#include "../d/huashan/huashan_lianhua.h"
#include "../d/huashan/huashan_lianpath1.h"
#include "../d/huashan/huashan_luoyan.h"
#include "../d/huashan/huashan_path1.h"
#include "../d/huashan/huashan_pingxinshi.h"
#include "../d/huashan/huashan_qianchi.h"
#include "../d/huashan/huashan_qingke.h"
#include "../d/huashan/huashan_qinshi.h"
#include "../d/huashan/huashan_qunxianguan.h"
#include "../d/huashan/huashan_sgyhole.h"
#include "../d/huashan/huashan_shaluo.h"
#include "../d/huashan/huashan_shangtianti.h"
#include "../d/huashan/huashan_shanhongpb.h"
#include "../d/huashan/huashan_sheshenya.h"
#include "../d/huashan/huashan_shop.h"
#include "../d/huashan/huashan_shufang.h"
#include "../d/huashan/huashan_siguoya.h"
#include "../d/huashan/huashan_songlin.h"
#include "../d/huashan/huashan_square.h"
#include "../d/huashan/huashan_xiaolu1.h"
#include "../d/huashan/huashan_xiuxishi.h"
#include "../d/huashan/huashan_yunmen.h"
#include "../d/huashan/huashan_yuntai.h"
#include "../d/huashan/huashan_yunu.h"
#include "../d/huashan/huashan_yunuci.h"
#include "../d/huashan/huashan_yunupath1.h"
#include "../d/huashan/huashan_yuquan.h"
#include "../d/huashan/huashan_zhandao.h"
#include "../d/huashan/huashan_zhenyue.h"
#include "../d/huashan/huashan_ziqitai.h"
#include "../d/huashan/huashan_zongsuo.h"
#include "../d/huashan/huashancity.h"

//华山村
#include "../d/huashancuen/huashancuen.h"
#include "../d/huashancuen/huashancuen_bighouse1.h"
#include "../d/huashancuen/huashancuen_bighouse2.h"
#include "../d/huashancuen/huashancuen_ehouse1.h"
#include "../d/huashancuen/huashancuen_nwhouse.h"
#include "../d/huashancuen/huashancuen_shack.h"
#include "../d/huashancuen/huashancuen_shop.h"
#include "../d/huashancuen/huashancuen_smithy.h"
#include "../d/huashancuen/huashancuen_temple1.h"
#include "../d/huashancuen/huashancuen_hsroad1.h"

//万安寺六派任务新增场景
#include "../d/huashan/huashan_pbhoushandong.h"

CRoom * Load_HuaShan(string room_name)
{
	CRoom * r = NULL;

	//华山
    if(room_name == "华山")
		r = new CRHuaShancity();
    else if(room_name == "华山紫气台")
		r = new CRHuaShan_ziqitai();
    else if(room_name == "华山镇岳宫")
		r = new CRHuaShan_zhenyue();
    else if(room_name == "华山长空栈道")
		r = new CRHuaShan_zhandao();
    else if(room_name == "华山玉泉院")
		r = new CRHuaShan_yuquan();
    else if(room_name == "华山玉女峰山路")
		r = new CRHuaShan_yunupath1();
    else if(room_name == "华山玉女祠")
		r = new CRHuaShan_yunuci();
    else if(room_name == "华山玉女峰")
		r = new CRHuaShan_yunu();
    else if(room_name == "华山云台峰")
		r = new CRHuaShan_yuntai();
    else if(room_name == "华山云门")
		r = new CRHuaShan_yunmen();
    else if(room_name == "华山小筑")
		r = new CRHuaShan_xiuxishi();
    else if(room_name == "华山小山路")
		r = new CRHuaShan_xiaolu1();
    else if(room_name == "华山练武场")
		r = new CRHuaShan_square();
    else if(room_name == "华山松树林")
		r = new CRHuaShan_songlin();
    else if(room_name == "华山思过崖")
		r = new CRHuaShan_siguoya();
    else if(room_name == "华山书房")
		r = new CRHuaShan_shufang();
    else if(room_name == "华山山顶小店")
		r = new CRHuaShan_shop();
    else if(room_name == "华山舍身崖")
		r = new CRHuaShan_sheshenya();
    else if(room_name == "华山山洪瀑布")
		r = new CRHuaShan_shanhongpb();
    else if(room_name == "华山上天梯")
		r = new CRHuaShan_shangtianti();
    else if(room_name == "华山莎萝坪")
		r = new CRHuaShan_shaluo();
    else if(room_name == "华山山洞")
		r = new CRHuaShan_sgyhole();
    else if(room_name == "华山群仙观")
		r = new CRHuaShan_qunxianguan();
    else if(room_name == "华山寝室")
		r = new CRHuaShan_qinshi();
    else if(room_name == "华山青柯坪")
		r = new CRHuaShan_qingke();
    else if(room_name == "华山千尺幢")
		r = new CRHuaShan_qianchi();
    else if(room_name == "华山平心石")
		r = new CRHuaShan_pingxinshi();
    else if(room_name == "华山脚下")
		r = new CRHuaShan_path1();
    else if(room_name == "华山落雁峰")
		r = new CRHuaShan_luoyan();
    else if(room_name == "华山莲花峰小路")
		r = new CRHuaShan_lianpath1();
    else if(room_name == "华山莲花峰")
		r = new CRHuaShan_lianhua();		
    else if(room_name == "华山老君沟")
		r = new CRHuaShan_laojun();
    else if(room_name == "华山居室")
		r = new CRHuaShan_jushi();
    else if(room_name == "华山金锁关")
		r = new CRHuaShan_jinsuo();
    else if(room_name == "华山假山小池")
		r = new CRHuaShan_jiashan();
    else if(room_name == "华山猢狲愁")
		r = new CRHuaShan_husun();
    else if(room_name == "华山回心石")
		r = new CRHuaShan_huixinshi();
    else if(room_name == "华山后院")
		r = new CRHuaShan_houyuan();
    else if(room_name == "华山花园")
		r = new CRHuaShan_garden();
    else if(room_name == "华山厨房")
		r = new CRHuaShan_chufang();
    else if(room_name == "华山沉香劈山处")
		r = new CRHuaShan_chengxiang();
    else if(room_name == "华山朝阳峰小路1")
		r = new CRHuaShan_chaoyangpath1();
    else if(room_name == "华山朝阳峰")
		r = new CRHuaShan_chaoyang();
    else if(room_name == "华山朝阳峰小路2")
		r = new CRHuaShan_chaopath2();
    else if(room_name == "华山百尺峡")
		r = new CRHuaShan_baichi();
    else if(room_name == "华山苍龙岭")
		r = new CRHuaShan_canglong();
    else if(room_name == "华山偏厅")
		r = new CRHuaShan_buwei3();
    else if(room_name == "华山有所不为轩")
		r = new CRHuaShan_buwei1();
    else if(room_name == "华山兵器房")
		r = new CRHuaShan_bingqifang();
    else if(room_name == "华山长廊")
		r = new CRHuaShan_changlang();

	//华山村
    if(room_name == "华山村")
		r = new CRHuaShancuen();
    else if(room_name == "华山村玄坛庙")
		r = new CRHuaShanCuen_temple1();
    else if(room_name == "华山村铁匠铺")
		r = new CRHuaShanCuen_smithy();
    else if(room_name == "华山村杂货店")
		r = new CRHuaShanCuen_shop();
    else if(room_name == "华山村财主家前厅")
		r = new CRHuaShanCuen_bighouse1();
    else if(room_name == "华山村民房")
		r = new CRHuaShanCuen_nwhouse();
    else if(room_name == "华山村民宅")
		r = new CRHuaShanCuen_ehouse1();
    else if(room_name == "华山村财主家内室")
		r = new CRHuaShanCuen_bighouse2();
    else if(room_name == "华山村草棚")
		r = new CRHuaShanCuen_shack();
    else if(room_name == "华山村青石大道")
		r = new CRHuaShanCuen_hsroad1();		
	
	//万安寺六派任务新增场景
	else if(room_name == "华山瀑布后山洞")
		r = new CRHuaShan_pbhoushandong();

	return r;
}