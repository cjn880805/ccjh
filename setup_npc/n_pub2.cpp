#include "stdafx.h"
#include "../server/Room.h"
#include "../std/Money.h"
#include "../std/Vendor.h"
#include "../std/BankOwner.h"
#include "../std/Corpse.h"
#include "../server/User.h"
#include "../server/Channel.h"
#include "../std/resident.h"

#include "../npc/pub/pub_poorman.h"
#include "../npc/pub/pub_pi.h"
#include "../npc/pub/pub_pian.h"
#include "../npc/pub/pub_pang.h"
#include "../npc/pub/pub_piaoyou.h"
#include "../npc/pub/pub_pihuoshang.h"
#include "../npc/pub/pub_playboy.h"
#include "../npc/pub/pub_pochen.h"
#include "../npc/pub/pub_poyi.h"
#include "../npc/pub/pub_puren.h"
//
#include "../npc/pub/pub_qian.h"
#include "../npc/pub/pub_qingbing.h"
//
#include "../npc/pub/pub_sanhu.h"
#include "../npc/pub/pub_seller.h"
#include "../npc/pub/pub_shami.h"
#include "../npc/pub/pub_shanzei1.h"
#include "../npc/pub/pub_shanzei2.h"
#include "../npc/pub/pub_shanzei3.h"
#include "../npc/pub/pub_shaonu.h"
#include "../npc/pub/pub_shennongdizi.h"
#include "../npc/pub/pub_shicong.h"
#include "../npc/pub/pub_shijiang.h"
#include "../npc/pub/pub_shinu.h"
#include "../npc/pub/pub_shinu1.h"
#include "../npc/pub/pub_shitong.h"
#include "../npc/pub/pub_shiwushi.h"
#include "../npc/pub/pub_shizhe1.h"
#include "../npc/pub/pub_shouling.h"
#include "../npc/pub/pub_shoushangren.h"
#include "../npc/pub/pub_shudianboss.h"
#include "../npc/pub/pub_shutong.h"
#include "../npc/pub/pub_sihu.h"
#include "../npc/pub/pub_seller1.h"
#include "../npc/pub/pub_shaofanshifu.h"
//
#include "../npc/pub/pub_thief.h"
#include "../npc/pub/pub_tuchanghuoji.h"
#include "../npc/pub/pub_taijian.h"
#include "../npc/pub/pub_tanghua.h"
#include "../npc/pub/pub_tanglong.h"
#include "../npc/pub/pub_tangruei.h"
#include "../npc/pub/pub_tiaofu.h"
#include "../npc/pub/pub_tongzi.h"
#include "../npc/pub/pub_trade.h"
#include "../npc/pub/pub_tshangfan.h"
#include "../npc/pub/pub_tufei1.h"
#include "../npc/pub/pub_tufei2.h"
#include "../npc/pub/pub_tufeitou.h"
#include "../npc/pub/pub_tuolei.h"
#include "../npc/pub/pub_tiejiang.h"
//
#include "../npc/pub/pub_weishi.h"
#include "../npc/pub/pub_weishi1.h"
#include "../npc/pub/pub_weishi2.h"
#include "../npc/pub/pub_wokou.h"
#include "../npc/pub/pub_woman.h"
#include "../npc/pub/pub_wujiang.h"
#include "../npc/pub/pub_wuliangdizi.h"
#include "../npc/pub/pub_wutianliang.h"
#include "../npc/pub/pub_wyshangfan.h"
#include "../npc/pub/pub_wushi.h"
//
#include "../npc/pub/pub_xianghuo.h"
#include "../npc/pub/pub_xiangke.h"
#include "../npc/pub/pub_xiaodaogu.h"
#include "../npc/pub/pub_xiaoguizi.h"
#include "../npc/pub/pub_xiaoju.h"
#include "../npc/pub/pub_xiaolama.h"
#include "../npc/pub/pub_xiaolan.h"
#include "../npc/pub/pub_xiaolouluo.h"
#include "../npc/pub/pub_xiaotufei.h"
#include "../npc/pub/pub_xiaowei.h"
#include "../npc/pub/pub_xier.h"
#include "../npc/pub/pub_xian.h"
#include "../npc/pub/pub_xiaoer4.h"
#include "../npc/pub/pub_xiucai.h"
#include "../npc/pub/pub_xixiabing.h"
#include "../npc/pub/pub_xueboss.h"
#include "../npc/pub/pub_xiaoer2.h"
#include "../npc/pub/pub_xianren.h"
#include "../npc/pub/pub_xiaohuoji.h"
//
#include "../npc/pub/pub_yafu.h"
#include "../npc/pub/pub_yangcannu.h"
#include "../npc/pub/pub_yapu.h"
#include "../npc/pub/pub_yayi.h"
#include "../npc/pub/pub_yingying.h"
#include "../npc/pub/pub_yipinwushi.h"
#include "../npc/pub/pub_youke.h"
#include "../npc/pub/pub_youke2.h"
#include "../npc/pub/pub_youngwoman.h"
#include "../npc/pub/pub_yuanwai.h"
#include "../npc/pub/pub_yufu.h"
#include "../npc/pub/pub_ya.h"
//
#include "../npc/pub/pub_zhanggui.h"
#include "../npc/pub/pub_zhangkang.h"
#include "../npc/pub/pub_zhongxiaoer.h"
#include "../npc/pub/pub_zishanshizhe.h"
#include "../npc/pub/pub_zutouren.h"
#include "../npc/pub/pub_zuzhang.h"
#include "../npc/pub/pub_zhenyouqing.h"
#include "../npc/pub/pub_zuo.h"

//-----------------------------------------------------------------
//
//	公共NPC之二
//	author:		Zou Wen Bin
//	date:		2000-12-26
//
//-----------------------------------------------------------------

CNpc * LoadNPC_pub2(string npc_name)
{
	CNpc * t = 0;

	if(npc_name == "pub_poorman")
		t = new CNPub_poorman();
	else if(npc_name == "pub_playboy")
		t = new CNPub_playboy();
	else if(npc_name == "pub_pihuoshang")
		t = new CNPub_pihuoshang();
	else if(npc_name == "pub_piaoyou")
		t = new CNPub_piaoyou();
	else if(npc_name == "pub_pian")
		t = new CNPub_pian();
	else if(npc_name == "pub_pi")
		t = new CNPub_pi();
	else if(npc_name == "pub_pang")
		t = new CNPub_pang();
	else if(npc_name == "pub_poyi")
		t = new CNPub_poyi();
	else if(npc_name == "pub_puren")
		t = new CNPub_puren();
//
	else if(npc_name == "pub_qingbing")
		t = new CNPub_qingbing();
	else if(npc_name == "pub_qian")
		t = new CNPub_qian();
//
	else if(npc_name == "pub_sihu")
		t = new CNPub_sihu();
	else if(npc_name == "pub_shutong")
		t = new CNPub_shutong();
	else if(npc_name == "pub_shudianboss")
		t = new CNPub_shudianboss();
	else if(npc_name == "pub_shoushangren")
		t = new CNPub_shoushangren();
	else if(npc_name == "pub_shouling")
		t = new CNPub_shouling();
	else if(npc_name == "pub_shizhe1")
		t = new CNPub_shizhe1();
	else if(npc_name == "pub_shiwushi")
		t = new CNPub_shiwushi();
	else if(npc_name == "pub_shitong")
		t = new CNPub_shitong();
	else if(npc_name == "pub_shinu1")
		t = new CNPub_shinu1();
	else if(npc_name == "pub_shinu")
		t = new CNPub_shinu();
	else if(npc_name == "pub_shijiang")
		t = new CNPub_shijiang();
	else if(npc_name == "pub_shicong")
		t = new CNPub_shicong();
	else if(npc_name == "pub_shennongdizi")
		t = new CNPub_shennongdizi();
	else if(npc_name == "pub_shaonu")
		t = new CNPub_shaonu();
	else if(npc_name == "pub_shanzei1")
		t = new CNPub_shanzei1();
	else if(npc_name == "pub_shaofanshifu")
		t = new CNPub_shaofanshifu();
	else if(npc_name == "pub_shanzei3")
		t = new CNPub_shanzei3();
	else if(npc_name == "pub_shanzei2")
		t = new CNPub_shanzei2();
	else if(npc_name == "pub_shami")
		t = new CNPub_shami();
	else if(npc_name == "pub_seller1")
		t = new CNPub_seller1();
	else if(npc_name == "pub_seller")
		t = new CNPub_seller();
	else if(npc_name == "pub_sanhu")
		t = new CNPub_sanhu();
//
	else if(npc_name == "pub_tshangfan")
		t = new CNPub_tshangfan();
	else if(npc_name == "pub_tuolei")
		t = new CNPub_tuolei();
	else if(npc_name == "pub_tufeitou")
		t = new CNPub_tufeitou();
	else if(npc_name == "pub_tufei2")
		t = new CNPub_tufei2();
	else if(npc_name == "pub_tufei1")
		t = new CNPub_tufei1();
	else if(npc_name == "pub_tuchanghuoji")
		t = new CNpub_tuchanghuoji();
	else if(npc_name == "pub_trade")
		t = new CNPub_trade();
	else if(npc_name == "pub_tongzi")
		t = new CNPub_tongzi();
	else if(npc_name == "pub_tiejiang")
		t = new CNPub_tiejiang();
	else if(npc_name == "pub_tiaofu")
		t = new CNPub_tiaofu();
	else if(npc_name == "pub_thief")
		t = new CNPub_thief();
	else if(npc_name == "pub_tangruei")
		t = new CNPub_tangruei();
	else if(npc_name == "pub_tanglong")
		t = new CNPub_tanglong();
	else if(npc_name == "pub_tanghua")
		t = new CNPub_tanghua();
	else if(npc_name == "pub_taijian")
		t = new CNPub_taijian();
//
	else if(npc_name == "pub_wyshangfan")
		t = new CNPub_wyshangfan();
	else if(npc_name == "pub_wutianliang")
		t = new CNPub_wutianliang();
	else if(npc_name == "pub_wushi")
		t = new CNPub_wushi();
	else if(npc_name == "pub_wuliangdizi")
		t = new CNPub_wuliangdizi();
	else if(npc_name == "pub_wujiang")
		t = new CNPub_wujiang();
	else if(npc_name == "pub_woman")
		t = new CNPub_woman();
	else if(npc_name == "pub_wokou")
		t = new CNPub_wokou();
	else if(npc_name == "pub_weishi2")
		t = new CNPub_weishi2();
	else if(npc_name == "pub_weishi1")
		t = new CNPub_weishi1();
	else if(npc_name == "pub_weishi")
		t = new CNPub_weishi();
//
	else if(npc_name == "pub_xueboss")
		t = new CNPub_xueboss();
	else if(npc_name == "pub_xixiabing")
		t = new CNPub_xixiabing();
	else if(npc_name == "pub_xiucai")
		t = new CNPub_xiucai();
	else if(npc_name == "pub_xier")
		t = new CNPub_xier();
	else if(npc_name == "pub_xiaowei")
		t = new CNPub_xiaowei();
	else if(npc_name == "pub_xiaotufei")
		t = new CNPub_xiaotufei();
	else if(npc_name == "pub_xiaolouluo")
		t = new CNPub_xiaolouluo();
	else if(npc_name == "pub_xiaolan")
		t = new CNPub_xiaolan();
	else if(npc_name == "pub_xiaolama")
		t = new CNPub_xiaolama();
	else if(npc_name == "pub_xiaoju")
		t = new CNPub_xiaoju();
	else if(npc_name == "pub_xiaohuoji")
		t = new CNpub_xiaohuoji();
	else if(npc_name == "pub_xiaoguizi")
		t = new CNPub_xiaoguizi();
	else if(npc_name == "pub_xiaoer2")
		t = new CNPub_xiaoer2();
	else if(npc_name == "pub_xiaodaogu")
		t = new CNPub_xiaodaogu();
	else if(npc_name == "pub_xianren")
		t = new CNpub_xianren();
	else if(npc_name == "pub_xiangke")
		t = new CNPub_xiangke();
	else if(npc_name == "pub_xianghuo")
		t = new CNPub_xianghuo();
	else if(npc_name == "pub_xian")
		t = new CNPub_xian();
	else if(npc_name == "pub_xiaoer4")
		t = new CNpub_xiaoer4();
//
	else if(npc_name == "pub_yufu")
		t = new CNPub_yufu();
	else if(npc_name == "pub_yuanwai")
		t = new CNPub_yuanwai();
	else if(npc_name == "pub_youngwoman")
		t = new CNPub_youngwoman();
	else if(npc_name == "pub_youke2")
		t = new CNPub_youke2();
	else if(npc_name == "pub_youke")
		t = new CNPub_youke();
	else if(npc_name == "pub_yipinwushi")
		t = new CNPub_yipinwushi();
	else if(npc_name == "pub_yingying")
		t = new CNPub_yingying();
	else if(npc_name == "pub_yafu")
		t = new CNPub_yafu();
	else if(npc_name == "pub_yapu")
		t = new CNPub_yapu();
	else if(npc_name == "pub_yangcannu")
		t = new CNPub_yangcannu();
	else if(npc_name == "pub_yayi")
		t = new CNPub_yayi();
	else if(npc_name == "pub_ya")
		t = new CNPub_ya();
//	
	else if(npc_name == "pub_zuzhang")
		t = new CNPub_zuzhang();
	else if(npc_name == "pub_zutouren")
		t = new CNPub_zutouren();
	else if(npc_name == "pub__zuzhang")
		t = new CNPub_zuzhang();
	else if(npc_name == "pub_zuo")
		t = new CNPub_zuo();
	else if(npc_name == "pub_zishanshizhe")
		t = new CNPub_zishanshizhe();
	else if(npc_name == "pub_zhongxiaoer")
		t = new CNPub_zhongxiaoer();
	else if(npc_name == "pub_zhenyouqing")
		t = new CNPub_zhenyouqing();
	else if(npc_name == "pub_zhangkang")
		t = new CNPub_zhangkang();
	else if(npc_name == "pub_zhanggui")
		t = new CNPub_zhanggui();

	return t;
}

