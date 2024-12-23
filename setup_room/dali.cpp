#include "stdafx.h"
#include "../server/Room.h"
#include "../std/resident.h"
#include "../std/FightRoom.h"

//大理城
#include "../d/dali/dali_bingqiku.h"
#include "../d/dali/dalicity.h"
#include "../d/dali/dali_bingying.h" 
#include "../d/dali/dali_chengyipu.h"
#include "../d/dali/dali_chufang.h"
#include "../d/dali/dali_gongmen.h"
#include "../d/dali/dali_majiu.h"
#include "../d/dali/dali_neiting.h"
#include "../d/dali/dali_piandian.h"
#include "../d/dali/dali_qiandian.h"
#include "../d/dali/dali_shufang.h"
#include "../d/dali/dali_sikong.h"
#include "../d/dali/dali_sima.h"
#include "../d/dali/dali_situ.h"
#include "../d/dali/dali_stoneshop.h"
#include "../d/dali/dali_taiheju.h" 
#include "../d/dali/dali_taiheju2.h" 
#include "../d/dali/dali_tusifu.h" 
#include "../d/dali/dali_tusiyishi.h"
#include "../d/dali/dali_wangfugate.h"
#include "../d/dali/dali_wfdating.h"
#include "../d/dali/dali_xiuxishi.h"
#include "../d/dali/dali_yaopu.h"
#include "../d/dali/dali_yushanfang.h"
#include "../d/dali/dali_zhangfang.h"
#include "../d/dali/dali_zhengdian.h"
#include "../d/dali/dali_zonglichu.h"
#include "../d/dali/dali_road5.h"
#include "../d/dali/dalidong.h"
#include "../d/dali/dalixi.h"
//大理城东
#include "../d/dalieast/dalieast_yangcanfang.h"
#include "../d/dalieast/dalieast_bijishan.h"
#include "../d/dalieast/dalieast_banshan.h"
#include "../d/dalieast/dalieast_buxiongbu.h"
#include "../d/dalieast/dalieast_chahuashan1.h"
#include "../d/dalieast/dalieast_chahuashan2.h"
#include "../d/dalieast/dalieast_chahuashan3.h"
#include "../d/dalieast/dalieast_chahuashan4.h"
#include "../d/dalieast/dalieast_chahuashan5.h"
#include "../d/dalieast/dalieast_chahuashan6.h"
#include "../d/dalieast/dalieast_dadieshui.h"
#include "../d/dalieast/dalieast_dalangan1.h"
#include "../d/dalieast/dalieast_dianchi.h"
#include "../d/dalieast/dalieast_heilongling.h"
#include "../d/dalieast/dalieast_hudiequan.h"
#include "../d/dalieast/dalieast_jingzhuang1.h"
#include "../d/dalieast/dalieast_jingzhuang2.h"
#include "../d/dalieast/dalieast_jingzhuang3.h"
#include "../d/dalieast/dalieast_jingzhuang4.h"
#include "../d/dalieast/dalieast_jingzhuang5.h"
#include "../d/dalieast/dalieast_jingzhuang6.h"
#include "../d/dalieast/dalieast_jingzhuang7.h"
#include "../d/dalieast/dalieast_jinzhihe.h"
#include "../d/dalieast/dalieast_langan1.h"
#include "../d/dalieast/dalieast_langan3.h"
#include "../d/dalieast/dalieast_langan4.h"
#include "../d/dalieast/dalieast_luojiadian.h"
#include "../d/dalieast/dalieast_milin.h"
#include "../d/dalieast/dalieast_nongtian2.h"
#include "../d/dalieast/dalieast_nongtian3.h"
#include "../d/dalieast/dalieast_nongtian4.h"
#include "../d/dalieast/dalieast_nongtian5.h"
#include "../d/dalieast/dalieast_northgate.h"
#include "../d/dalieast/dalieast_qingxi.h"
#include "../d/dalieast/dalieast_sanglin.h"
#include "../d/dalieast/dalieast_shanjian.h"
#include "../d/dalieast/dalieast_shanlu7.h"
#include "../d/dalieast/dalieast_shanlu8.h"
#include "../d/dalieast/dalieast_shulinwai.h"
#include "../d/dalieast/dalieast_southgate.h"
#include "../d/dalieast/dalieast_xiaodao1.h"
#include "../d/dalieast/dalieast_xiaodao2.h"
#include "../d/dalieast/dalieast_xiaojing.h"
#include "../d/dalieast/dalieast_xingyunhu.h"
#include "../d/dalieast/dalieast_yanan1.h"
#include "../d/dalieast/dalieast_yanan2.h"
#include "../d/dalieast/dalieast_yanchi1.h"
#include "../d/dalieast/dalieast_yanchi2.h"
#include "../d/dalieast/dalieast_yanchi3.h"
#include "../d/dalieast/dalieast_yangzong.h"
#include "../d/dalieast/dalieast_yuxiashan.h"
#include "../d/dalieast/dalieast_yuxuguan.h"
#include "../d/dalieast/dalieast_yuxuguanqian.h"
//大理城南
#include "../d/dalisouth/dalisouth_dazhulou.h"
#include "../d/dalisouth/dalisouth_feilihu.h"
#include "../d/dalisouth/dalisouth_feilihueast.h"
#include "../d/dalisouth/dalisouth_feilihusouth.h"
#include "../d/dalisouth/dalisouth_gudao.h"
#include "../d/dalisouth/dalisouth_hexi.h"
#include "../d/dalisouth/dalisouth_jisi.h"
#include "../d/dalisouth/dalisouth_kedian.h"
#include "../d/dalisouth/dalisouth_longkou.h"
#include "../d/dalisouth/dalisouth_luwang.h"
#include "../d/dalisouth/dalisouth_luyuxi.h"
#include "../d/dalisouth/dalisouth_nongtian.h"
#include "../d/dalisouth/dalisouth_qingzhulin.h"
#include "../d/dalisouth/dalisouth_road4.h"
#include "../d/dalisouth/dalisouth_shanlu2.h"
#include "../d/dalisouth/dalisouth_shanlu4.h"
#include "../d/dalisouth/dalisouth_shanlu5.h"
#include "../d/dalisouth/dalisouth_shanlu6.h"
#include "../d/dalisouth/dalisouth_shuangheqiao.h"
#include "../d/dalisouth/dalisouth_shuitian.h"
#include "../d/dalisouth/dalisouth_tianweijing.h"
#include "../d/dalisouth/dalisouth_wuding.h"
#include "../d/dalisouth/dalisouth_wuhalou.h"
#include "../d/dalisouth/dalisouth_wuhalou2.h"
#include "../d/dalisouth/dalisouth_xizhou.h"
#include "../d/dalisouth/dalisouth_yishitang.h"
#include "../d/dalisouth/dalisouth_yujia.h"
#include "../d/dalisouth/dalisouth_yulin.h"
#include "../d/dalisouth/dalisouth_zhulin.h"
#include "../d/dalisouth/dalisouth_zhulin2.h"
#include "../d/dalisouth/dalisouth_zhulou.h"
#include "../d/dalisouth/dalisouth_zhulou1.h"
#include "../d/dalisouth/dalisouth_zhulou3.h"
//大理城西
#include "../d/daliwest/daliwest_atoubu.h"
#include "../d/daliwest/daliwest_badidian.h"
#include "../d/daliwest/daliwest_biluoshan.h"
#include "../d/daliwest/daliwest_biluoxueshan.h"
#include "../d/daliwest/daliwest_gaolishan1.h"
#include "../d/daliwest/daliwest_gaolishan2.h"
#include "../d/daliwest/daliwest_gelucheng.h"
#include "../d/daliwest/daliwest_hebian.h"
#include "../d/daliwest/daliwest_heshang.h"
#include "../d/daliwest/daliwest_jisidawu.h"
#include "../d/daliwest/daliwest_jisidawu1.h"
#include "../d/daliwest/daliwest_lushui.h"
#include "../d/daliwest/daliwest_lushuieast.h"
#include "../d/daliwest/daliwest_minadian.h"
#include "../d/daliwest/daliwest_nianhuasi.h"
#include "../d/daliwest/daliwest_shanlin.h"
#include "../d/daliwest/daliwest_shanlu3.h"
#include "../d/daliwest/daliwest_titian1.h"
#include "../d/daliwest/daliwest_wuyiminju3.h"
#include "../d/daliwest/daliwest_wuyiminju4.h"
#include "../d/daliwest/daliwest_yixibu.h"
#include "../d/daliwest/daliwest_zhenxiong.h"
//大理城北
#include "../d/dalinorth/dalinorth_cangshanzhong.h"
#include "../d/dalinorth/dalinorth_cangshanlu1.h"
#include "../d/dalinorth/dalinorth_cangshan.h"
#include "../d/dalinorth/dalinorth_caopo.h"
#include "../d/dalinorth/dalinorth_changhu.h"
#include "../d/dalinorth/dalinorth_daduhe.h"
#include "../d/dalinorth/dalinorth_dalinorth.h"
#include "../d/dalinorth/dalinorth_dehuabei.h"
#include "../d/dalinorth/dalinorth_ershuiqiao.h"
#include "../d/dalinorth/dalinorth_hole.h"
#include "../d/dalinorth/dalinorth_hongsheng.h"
#include "../d/dalinorth/dalinorth_jianchuan.h"
#include "../d/dalinorth/dalinorth_jianchuankou.h"
#include "../d/dalinorth/dalinorth_road1.h"
#include "../d/dalinorth/dalinorth_road2.h"
#include "../d/dalinorth/dalinorth_road3.h"
#include "../d/dalinorth/dalinorth_shanlu1.h"
#include "../d/dalinorth/dalinorth_shilin.h"
#include "../d/dalinorth/dalinorth_shilin1.h"
#include "../d/dalinorth/dalinorth_shilin2.h"
#include "../d/dalinorth/dalinorth_taihecheng.h"
#include "../d/dalinorth/dalinorth_tianlongsi.h"
#include "../d/dalinorth/dalinorth_wumeng.h"
#include "../d/dalinorth/dalinorth_wunong.h"
#include "../d/dalinorth/dalinorth_wuyiminju1.h"
#include "../d/dalinorth/dalinorth_wuyiminju2.h"
#include "../d/dalinorth/dalinorth_xiaguan.h"
#include "../d/dalinorth/dalinorth_zhiyundong.h"
#include "../d/dalinorth/dalinorthcity.h"

#include "../d/dali/dali_chongshengtading.h"	//大理城崇圣塔顶--明教牢房

CRoom * Load_DaLi(string room_name)
{	
	CRoom * r = NULL;

	//大理城
	if(room_name == "大理城药铺")
		r = new CRDali_yaopu();
	else if(room_name == "大理城")
		r = new CRDaLicity();
	else if(room_name == "大理城王府大门")
		r = new CRDali_wangfugate();
	else if(room_name == "大理城土司府")
		r = new CRDali_tusifu();
	else if(room_name == "大理城太和居二楼")
		r = new CRDali_taiheju2();
	else if(room_name == "大理城太和居")
		r = new CRDali_taiheju();
	else if(room_name == "大理城石铺")
		r = new CRDali_stoneshop();
	else if(room_name == "大理城马厩")
		r = new CRDali_majiu();
	else if(room_name == "大理城皇宫宫门")
		r = new CRDali_gongmen();
	else if(room_name == "大理城兵营")
		r = new CRDali_bingying();
	else if(room_name == "大理城薛记成衣铺")
		r = new CRDali_chengyipu();
	else if(room_name == "大理城王府总理处")
		r = new CRDali_zonglichu();
	else if(room_name == "大理城王府兵器房")
		r = new CRDali_bingqiku();
	else if(room_name == "大理城王府内厅")
		r = new CRDali_neiting();
	else if(room_name == "大理城王府大厅")
		r = new CRDali_wfdating();
	else if(room_name == "大理城王府下人居室")
		r = new CRDali_xiuxishi();
	else if(room_name == "大理城王府司徒堂")
		r = new CRDali_situ();
	else if(room_name == "大理城王府司马堂")
		r = new CRDali_sima();
	else if(room_name == "大理城王府司空堂")
		r = new CRDali_sikong();
	else if(room_name == "大理城王府书房")
		r = new CRDali_shufang();
	else if(room_name == "大理城王府厨房")
		r = new CRDali_chufang();
	else if(room_name == "大理城王府帐房")
		r = new CRDali_zhangfang();
	else if(room_name == "大理城皇宫正殿")
		r = new CRDali_zhengdian();
	else if(room_name == "大理城皇宫偏殿")
		r = new CRDali_piandian();
	else if(room_name == "大理城土司府议事厅")
		r = new CRDali_tusiyishi();
	else if(room_name == "大理城皇宫前殿")
		r = new CRDali_qiandian();
	else if(room_name == "大理城皇宫御膳坊")
		r = new CRDali_yushanfang();
	else if(room_name == "大理城黄土路")
		r = new CRDali_road5();
	
	//大理城东
	if(room_name == "大理城养蚕房")
		r = new CRDaliEast_yangcanfang();
	else if(room_name == "大理城玉虚观")
		r = new CRDaliEast_yuxuguan();
	else if(room_name == "大理城玉虚观前")
		r = new CRDaliEast_yuxuguanqian();
	else if(room_name == "大理城玉霞山")
		r = new CRDaliEast_yuxiashan();
	else if(room_name == "大理城阳宗镇")
		r = new CRDaliEast_yangzong();
	else if(room_name == "大理城沿池堤岸3")
		r = new CRDaliEast_yanchi3();
	else if(room_name == "大理城沿池堤岸2")
		r = new CRDaliEast_yanchi2();
	else if(room_name == "大理城沿池堤岸1")
		r = new CRDaliEast_yanchi1();
	else if(room_name == "大理城沿池小路2")
		r = new CRDaliEast_yanan2();
	else if(room_name == "大理城滇池沿岸1")
		r = new CRDaliEast_yanan1();
	else if(room_name == "大理城星云湖畔")
		r = new CRDaliEast_xingyunhu();
	else if(room_name == "大理城山区小径")
		r = new CRDaliEast_xiaojing();
	else if(room_name == "大理城林间小道2")
		r = new CRDaliEast_xiaodao2();
	else if(room_name == "大理城林间小道1")
		r = new CRDaliEast_xiaodao1();
	else if(room_name == "大理城南门")
		r = new CRDaliEast_southgate();
	else if(room_name == "大理城树林外")
		r = new CRDaliEast_shulinwai();
	else if(room_name == "大理城山路8")
		r = new CRDaliEast_shanlu8();
	else if(room_name == "大理城山路7")
		r = new CRDaliEast_shanlu7();
	else if(room_name == "大理城林中山涧")
		r = new CRDaliEast_shanjian();
	else if(room_name == "大理城桑林")
		r = new CRDaliEast_sanglin();
	else if(room_name == "大理城清溪三潭")
		r = new CRDaliEast_qingxi();
	else if(room_name == "大理城农田5")
		r = new CRDaliEast_nongtian5();
	else if(room_name == "大理城农田4")
		r = new CRDaliEast_nongtian4();
	else if(room_name == "大理城农田3")
		r = new CRDaliEast_nongtian3();
	else if(room_name == "大理城农田2")
		r = new CRDaliEast_nongtian2();
	else if(room_name == "大理城密林")
		r = new CRDaliEast_milin();
	else if(room_name == "大理城罗伽甸")
		r = new CRDaliEast_luojiadian();
	else if(room_name == "大理城杆栏4")
		r = new CRDaliEast_langan4();
	else if(room_name == "大理城杆栏3")
		r = new CRDaliEast_langan3();
	else if(room_name == "大理城杆栏")
		r = new CRDaliEast_langan1();
	else if(room_name == "大理城金汁河畔")
		r = new CRDaliEast_jinzhihe();
	else if(room_name == "大理城经幢7")
		r = new CRDaliEast_jingzhuang7();
	else if(room_name == "大理城经幢6")
		r = new CRDaliEast_jingzhuang6();
	else if(room_name == "大理城经幢5")
		r = new CRDaliEast_jingzhuang5();
	else if(room_name == "大理城经幢4")
		r = new CRDaliEast_jingzhuang4();
	else if(room_name == "大理城经幢3")
		r = new CRDaliEast_jingzhuang3();
	else if(room_name == "大理城经幢2")
		r = new CRDaliEast_jingzhuang2();
	else if(room_name == "大理城经幢1")
		r = new CRDaliEast_jingzhuang1();
	else if(room_name == "大理城蝴蝶泉")
		r = new CRDaliEast_hudiequan();
	else if(room_name == "大理城黑龙岭")
		r = new CRDaliEast_heilongling();
	else if(room_name == "大理城滇池")
		r = new CRDaliEast_dianchi();
	else if(room_name == "大理城大杆栏")
		r = new CRDaliEast_dalangan1();
	else if(room_name == "大理城大叠水瀑布")
		r = new CRDaliEast_dadieshui();
	else if(room_name == "大理城半山竹林")
		r = new CRDaliEast_banshan();
	else if(room_name == "大理城茶花山5")
		r = new CRDaliEast_chahuashan5();
	else if(room_name == "大理城茶花山4")
		r = new CRDaliEast_chahuashan4();
	else if(room_name == "大理城茶花山3")
		r = new CRDaliEast_chahuashan3();
	else if(room_name == "大理城茶花山2")
		r = new CRDaliEast_chahuashan2();
	else if(room_name == "大理城茶花山1")
		r = new CRDaliEast_chahuashan1();
	else if(room_name == "大理城步雄部")
		r = new CRDaliEast_buxiongbu();
	else if(room_name == "大理城碧鸡山顶")
		r = new CRDaliEast_bijishan();
	else if(room_name == "大理城茶花山南")
		r = new CRDaliEast_chahuashan6();
	
	//大理城南
	else if(room_name == "大理城大竹楼")
		r = new CRDaLisouth_zhulou3();
	else if(room_name == "大理城竹楼下")
		r = new CRDaLisouth_zhulou1();
	else if(room_name == "大理城竹楼")
		r = new CRDaLisouth_zhulou();
	else if(room_name == "大理城竹林深处")
		r = new CRDaLisouth_zhulin2();
	else if(room_name == "大理城竹林小路")
		r = new CRDaLisouth_zhulin();
	else if(room_name == "大理城榕树雨林")
		r = new CRDaLisouth_yulin();
	else if(room_name == "大理城渔家")
		r = new CRDaLisouth_yujia();
	else if(room_name == "大理城喜州城")
		r = new CRDaLisouth_xizhou();
	else if(room_name == "大理城南五华楼")
		r = new CRDaLisouth_wuhalou();
	else if(room_name == "大理城武定镇")
		r = new CRDaLisouth_wuding();
	else if(room_name == "大理城天威径")
		r = new CRDaLisouth_tianweijing();
	else if(room_name == "大理城水田")
		r = new CRDaLisouth_shuitian();
	else if(room_name == "大理城双鹤桥")
		r = new CRDaLisouth_shuangheqiao();
	else if(room_name == "大理城山路6")
		r = new CRDaLisouth_shanlu6();
	else if(room_name == "大理城山路5")
		r = new CRDaLisouth_shanlu5();
	else if(room_name == "大理城山路4")
		r = new CRDaLisouth_shanlu4();
	else if(room_name == "大理城山路2")
		r = new CRDaLisouth_shanlu2();
	else if(room_name == "大理城大路4")
		r = new CRDaLisouth_road4();
	else if(room_name == "大理城青竹林")
		r = new CRDaLisouth_qingzhulin();
	else if(room_name == "大理城农田")
		r = new CRDaLisouth_nongtian();
	else if(room_name == "大理城绿玉溪沿岸")
		r = new CRDaLisouth_luyuxi();
	else if(room_name == "大理城鲁望镇")
		r = new CRDaLisouth_luwang();
	else if(room_name == "大理城龙口城")
		r = new CRDaLisouth_longkou();
	else if(room_name == "大理城客店")
		r = new CRDaLisouth_kedian();
	else if(room_name == "大理城古道")
		r = new CRDaLisouth_gudao();
	else if(room_name == "大理城妃丽湖南岸")
		r = new CRDaLisouth_feilihusouth();
	else if(room_name == "大理城妃丽湖东")
		r = new CRDaLisouth_feilihueast();
	else if(room_name == "大理城妃丽湖畔")
		r = new CRDaLisouth_feilihu();
	else if(room_name == "大理城南大竹楼")
		r = new CRDaLisouth_dazhulou();
	else if(room_name == "大理城河西镇")
		r = new CRDaLisouth_hexi();
	else if(room_name == "大理城南五华楼二楼")
		r = new CRDaLisouth_wuhalou2();		
	
	//大理城西
	if(room_name == "大理城镇雄")
		r = new CRDaLiWest_zhenxiong();
	else if(room_name == "大理城易溪部")
		r = new CRDaLiWest_yixibu();
	else if(room_name == "大理城乌夷民居4")
		r = new CRDaLiWest_wuyiminju4();
	else if(room_name == "大理城乌夷民居")
		r = new CRDaLiWest_wuyiminju3();
	else if(room_name == "大理城梯田")
		r = new CRDaLiWest_titian1();
	else if(room_name == "大理城山路3")
		r = new CRDaLiWest_shanlu3();
	else if(room_name == "大理城山林")
		r = new CRDaLiWest_shanlin();
	else if(room_name == "大理城拈花寺")
		r = new CRDaLiWest_nianhuasi();
	else if(room_name == "大理城蜜纳甸")
		r = new CRDaLiWest_minadian();
	else if(room_name == "大理城东泸水河谷")
		r = new CRDaLiWest_lushuieast();
	else if(room_name == "大理城泸水沿岸")
		r = new CRDaLiWest_lushui();
	else if(room_name == "大理城祭祀大屋")
		r = new CRDaLiWest_jisidawu1();
	else if(room_name == "大理城河上")
		r = new CRDaLiWest_heshang();
	else if(room_name == "大理城河边")
		r = new CRDaLiWest_hebian();
	else if(room_name == "大理城葛鲁城")
		r = new CRDaLiWest_gelucheng();
	else if(room_name == "大理城阿头部")
		r = new CRDaLiWest_atoubu();
	else if(room_name == "大理城高黎山东坡")
		r = new CRDaLiWest_gaolishan1();
	else if(room_name == "大理城碧罗雪山")
		r = new CRDaLiWest_biluoxueshan();
	else if(room_name == "大理城高黎山密林")
		r = new CRDaLiWest_gaolishan2();
	else if(room_name == "大理城碧罗山下")
		r = new CRDaLiWest_biluoshan();
	else if(room_name == "大理城巴的甸")
		r = new CRDaLiWest_badidian();
	
	//大理城北
	if(room_name == "大理城北门")
		r = new CRDaLiNorthcity();
	else if(room_name == "大理城芝云洞")
		r = new CRDaLiNorth_zhiyundong();
	else if(room_name == "大理城下关城")
		r = new CRDaLiNorth_xiaguan();
	else if(room_name == "大理城乌夷民居2")
		r = new CRDaLiNorth_wuyiminju2();
	else if(room_name == "大理城乌夷民居1")
		r = new CRDaLiNorth_wuyiminju1();
	else if(room_name == "大理城乌弄城")
		r = new CRDaLiNorth_wunong();
	else if(room_name == "大理城乌蒙村落")
		r = new CRDaLiNorth_wumeng();
	else if(room_name == "大理城北天龙寺")
		r = new CRDaLiNorth_tianlongsi();
	else if(room_name == "大理城太和城")
		r = new CRDaLiNorth_taihecheng();
	else if(room_name == "大理城和摩赛石林")
		r = new CRDaLiNorth_shilin2();
	else if(room_name == "大理城李子箐石林")
		r = new CRDaLiNorth_shilin1();
	else if(room_name == "大理城路南石林")
		r = new CRDaLiNorth_shilin();
	else if(room_name == "大理城川西山路")
		r = new CRDaLiNorth_shanlu1();
	else if(room_name == "大理城官道3")
		r = new CRDaLiNorth_road3();
	else if(room_name == "大理城官道2")
		r = new CRDaLiNorth_road2();
	else if(room_name == "大理城官道1")
		r = new CRDaLiNorth_road1();
	else if(room_name == "大理城剑川山口")
		r = new CRDaLiNorth_jianchuankou();
	else if(room_name == "大理城剑川镇")
		r = new CRDaLiNorth_jianchuan();
	else if(room_name == "大理城宏圣寺塔")
		r = new CRDaLiNorth_hongsheng();
	else if(room_name == "大理城洱水桥")
		r = new CRDaLiNorth_ershuiqiao();
	else if(room_name == "大理城苍山")
		r = new CRDaLiNorth_cangshan();
	else if(room_name == "大理城南诏德化碑")
		r = new CRDaLiNorth_dehuabei();
	else if(room_name == "大理城苍山山路")
		r = new CRDaLiNorth_cangshanlu1();
	else if(room_name == "大理城大渡河边")
		r = new CRDaLiNorth_daduhe();
	else if(room_name == "大理城长湖")
		r = new CRDaLiNorth_changhu();
	else if(room_name == "大理城村外草坡")
		r = new CRDaLiNorth_caopo();
	else if(room_name == "大理城苍山中部")
		r = new CRDaLiNorth_cangshanzhong();
	else if(room_name == "大理城北")
		r = new CRDaLiNorth_dalinorth();
	else if(room_name == "大理城东")
		r = new CRDaLidong();
	else if(room_name == "大理城西")
		r = new CRDaLixi();
	else if(room_name == "大理城崇圣塔顶")
		r = new CRDali_chongshengtading();
	return r;
}



