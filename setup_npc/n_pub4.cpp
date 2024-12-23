#include "stdafx.h"
#include "../server/Room.h"
#include "../std/Money.h"
#include "../std/Vendor.h"
#include "../std/BankOwner.h"
#include "../std/Corpse.h"
#include "../server/User.h"
#include "../server/Channel.h"
#include "../std/FightRoom.h"

//-----------------------------------------------------------------
//
//	公共NPC之四
//	author:		Fisho
//	date:		2000-12-26
//
//-----------------------------------------------------------------

//new8
#include "../npc/pub/pub_huqingyu.h"
//#include "../npc/pub/pub_jiguan.h"
#include "../npc/pub/pub_long.h"
#include "../npc/pub/pub_mu.h"
#include "../npc/pub/pub_muren.h"
#include "../npc/pub/pub_tongren.h"
//#include "../npc/pub/pub_tieren.h"
#include "../npc/pub/pub_wei.h"
//#include "../npc/pub/pub_xiangpiren.h"
#include "../npc/pub/pub_xiaocui.h"
#include "../npc/pub/pub_xiaoheshang.h"
#include "../npc/pub/pub_xiaoqing.h"
#include "../npc/pub/pub_yuzu.h"
#include "../npc/pub/pub_zhu.h"
//new7
#include "../npc/pub/pub_huangzhen.h"
#include "../npc/pub/pub_hufei.h"
#include "../npc/pub/pub_kang.h"
#include "../npc/pub/pub_qianlong.h"
#include "../npc/pub/pub_qigai.h"
#include "../npc/pub/pub_shizhe3.h"
#include "../npc/pub/pub_snaker.h"
#include "../npc/pub/pub_xiaozei.h"
#include "../npc/pub/pub_zhuangyu.h"
//new6
#include "../npc/pub/pub_huo.h"
#include "../npc/pub/pub_jinhua.h"
#include "../npc/pub/pub_laobaopo.h"
#include "../npc/pub/pub_laozhe.h"
#include "../npc/pub/pub_mazei.h"
#include "../npc/pub/pub_puyi.h"
#include "../npc/pub/pub_qiaofu.h"
#include "../npc/pub/pub_smith.h"
#include "../npc/pub/pub_susu.h"
#include "../npc/pub/pub_wgargoyle.h"
//new5
#include "../npc/pub/pub_laoban.h"
#include "../npc/pub/pub_mafu.h"
#include "../npc/pub/pub_menwei.h"
#include "../npc/pub/pub_nanxiren.h"
#include "../npc/pub/pub_punk.h"
#include "../npc/pub/pub_qingyun.h"
#include "../npc/pub/pub_sun.h"
#include "../npc/pub/pub_trainer.h"
#include "../npc/pub/pub_xiaoer3.h"
#include "../npc/pub/pub_zhangfang.h"
#include "../npc/pub/pub_feifei.h"
#include "../npc/pub/pub_fengqi.h"
#include "../npc/pub/pub_fengxifan.h"
#include "../npc/pub/pub_furen.h"
#include "../npc/pub/pub_guanzho1.h"
#include "../npc/pub/pub_guanzho4.h"
#include "../npc/pub/pub_guidao.h"
#include "../npc/pub/pub_hai.h"
#include "../npc/pub/pub_haojie.h"
#include "../npc/pub/pub_heersu.h"
#include "../npc/pub/pub_huangmei.h"
#include "../npc/pub/pub_jiaoxi.h"
#include "../npc/pub/pub_lady3.h"
#include "../npc/pub/pub_laoxiansheng.h"
#include "../npc/pub/pub_mengmian.h"
#include "../npc/pub/pub_ping.h"
#include "../npc/pub/pub_xiaoer.h"
#include "../npc/pub/pub_xiaoer1.h"
#include "../npc/pub/pub_zeng.h"
#include "../npc/pub/pub_zhangma.h"
#include "../npc/pub/pub_gu.h"
#include "../npc/pub/pub_guanzho3.h"
#include "../npc/pub/pub_guanzho5.h"
#include "../npc/pub/pub_qinbing.h"
#include "../npc/pub/pub_shiwei.h"
#include "../npc/pub/pub_shiwei2.h"
#include "../npc/pub/pub_yahuan.h"
#include "../npc/pub/pub_yangzong.h"
#include "../npc/pub/pub_zhong.h"
#include "../npc/pub/pub_zhongsisao.h"
#include "../npc/pub/pub_fengliang.h"
#include "../npc/pub/pub_gaoli.h"
#include "../npc/pub/pub_gongzi.h"
#include "../npc/pub/pub_herdsman.h"
#include "../npc/pub/pub_old.h"
#include "../npc/pub/pub_oldwoman.h"
#include "../npc/pub/pub_shi.h"
#include "../npc/pub/pub_whitelady.h"
#include "../npc/pub/pub_xizi.h"
#include "../npc/pub/pub_zhuoma.h"
//new0
#include "../npc/pub/pub_aqingsao.h"
#include "../npc/pub/pub_baibian.h"
#include "../npc/pub/pub_guanbing1.h"
#include "../npc/pub/pub_chaboshi.h"
#include "../npc/pub/pub_chen.h"
#include "../npc/pub/pub_chuanfu.h"
#include "../npc/pub/pub_chuanfu1.h"
#include "../npc/pub/pub_chuanfu2.h"
#include "../npc/pub/pub_chushi.h"
#include "../npc/pub/pub_cunzhang.h"
#include "../npc/pub/pub_daodianhuoji.h"
#include "../npc/pub/pub_dizi1.h"
#include "../npc/pub/pub_dizi2.h"
#include "../npc/pub/pub_dizi3.h"
#include "../npc/pub/pub_gargoyle.h"

CNpc * LoadNPC_pub4(string npc_name)
{
	CNpc * t = 0;

	//new8
	if(npc_name == "pub_huqingyu")
		t = new CNpub_huqingyu();
//	else if(npc_name == "pub_jiguan")
//		t = new CNpub_jiguan();
	else if(npc_name == "pub_long")
		t = new CNpub_long();
	else if(npc_name == "pub_mu")
		t = new CNpub_mu();
	else if(npc_name == "pub_muren")
		t = new CNpub_muren();
	else if(npc_name == "pub_tongren")
		t = new CNpub_tongren();
//	else if(npc_name == "pub_tieren")
//		t = new CNpub_tieren();
	else if(npc_name == "pub_wei")
		t = new CNpub_wei();
//	else if(npc_name == "pub_xiangpiren")
//		t = new CNpub_xiangpiren();
	else if(npc_name == "pub_xiaocui")
		t = new CNpub_xiaocui();
	else if(npc_name == "pub_xiaoheshang")
		t = new CNpub_xiaoheshang();
	else if(npc_name == "pub_xiaoqing")
		t = new CNpub_xiaoqing();
	else if(npc_name == "pub_yuzu")
		t = new CNpub_yuzu();
	else if(npc_name == "pub_zhu")
		t = new CNpub_zhu();
//new7
	else if(npc_name == "pub_huangzhen")
		t = new CNpub_huangzhen();
	else if(npc_name == "pub_hufei")
		t = new CNpub_hufei();
	else if(npc_name == "pub_kang")
		t = new CNpub_kang();
	else if(npc_name == "pub_qianlong")
		t = new CNpub_qianlong();
	else if(npc_name == "pub_qigai")
		t = new CNpub_qigai();
	else if(npc_name == "pub_shizhe3")
		t = new CNpub_shizhe3();
	else if(npc_name == "pub_snaker")
		t = new CNpub_snaker();
	else if(npc_name == "pub_xiaozei")
		t = new CNpub_xiaozei();
	else if(npc_name == "pub_zhuangyu")
		t = new CNpub_zhuangyu();
//new6
	else if(npc_name == "pub_huo")
		t = new CNpub_huo();
	else if(npc_name == "pub_jinhua")
		t = new CNpub_jinhua();
	else if(npc_name == "pub_laobaopo")
		t = new CNpub_laobaopo();
	else if(npc_name == "pub_laozhe")
		t = new CNpub_laozhe();
	else if(npc_name == "pub_mazei")
		t = new CNpub_mazei();
	else if(npc_name == "pub_puyi")
		t = new CNpub_puyi();
	else if(npc_name == "pub_qiaofu")
		t = new CNpub_qiaofu();
	else if(npc_name == "pub_smith")
		t = new CNpub_smith();
	else if(npc_name == "pub_susu")
		t = new CNpub_susu();
	else if(npc_name == "pub_wgargoyle")
		t = new CNpub_wgargoyle();
//new5
	else if(npc_name == "pub_laoban")
		t = new CNpub_laoban();
	else if(npc_name == "pub_mafu")
		t = new CNPub_mafu();
	else if(npc_name == "pub_menwei")
		t = new CNpub_menwei();
	else if(npc_name == "pub_nanxiren")
		t = new CNpub_nanxiren();
	else if(npc_name == "pub_punk")
		t = new CNpub_punk();
	else if(npc_name == "pub_qingyun")
		t = new CNpub_qingyun();
	else if(npc_name == "pub_sun")
		t = new CNpub_sun();
	else if(npc_name == "pub_trainer")
		t = new CNpub_trainer();
	else if(npc_name == "pub_xiaoer3")
		t = new CNpub_xiaoer3();
	else if(npc_name == "pub_zhangfang")
		t = new CNpub_zhangfang();
	else if(npc_name == "pub_feifei")
		t = new CNpub_feifei();
	else if(npc_name == "pub_fengqi")
		t = new CNpub_fengqi();
	else if(npc_name == "pub_fengxifan")
		t = new CNpub_fengxifan();
	else if(npc_name == "pub_furen")
		t = new CNpub_furen();
	else if(npc_name == "pub_guanzho1")
		t = new CNpub_guanzho1();
	else if(npc_name == "pub_guanzho4")
		t = new CNpub_guanzho4();
	else if(npc_name == "pub_guidao")
		t = new CNpub_guidao();
	else if(npc_name == "pub_hai")
		t = new CNpub_hai();
	else if(npc_name == "pub_haojie")
		t = new CNpub_haojie();
	else if(npc_name == "pub_heersu")
		t = new CNpub_heersu();
	else if(npc_name == "pub_huangmei")
		t = new CNpub_huangmei();
	else if(npc_name == "pub_jiaoxi")
		t = new CNpub_jiaoxi();
	else if(npc_name == "pub_lady3")
		t = new CNpub_lady3();
	else if(npc_name == "pub_laoxiansheng")
		t = new CNpub_laoxiansheng();
	else if(npc_name == "pub_mengmian")
		t = new CNpub_mengmian();
	else if(npc_name == "pub_ping")
		t = new CNpub_ping();
	else if(npc_name == "pub_xiaoer")
		t = new CNpub_xiaoer();
	else if(npc_name == "pub_xiaoer1")
		t = new CNpub_xiaoer1();
	else if(npc_name == "pub_zeng")
		t = new CNpub_zeng();
	else if(npc_name == "pub_zhangma")
		t = new CNpub_zhangma();
	else if(npc_name == "pub_gu")
		t = new CNpub_gu();
	else if(npc_name == "pub_guanzho3")
		t = new CNpub_guanzho3();
	else if(npc_name == "pub_guanzho5")
		t = new CNpub_guanzho5();
	else if(npc_name == "pub_qinbing")
		t = new CNpub_qinbing();
	else if(npc_name == "pub_shiwei")
		t = new CNpub_shiwei();
	else if(npc_name == "pub_shiwei2")
		t = new CNpub_shiwei2();
	else if(npc_name == "pub_yahuan")
		t = new CNpub_yahuan();
	else if(npc_name == "pub_yangzong")
		t = new CNpub_yangzong();
	else if(npc_name == "pub_zhong")
		t = new CNpub_zhong();
	else if(npc_name == "pub_zhongsisao")
		t = new CNpub_zhongsisao();
	else if(npc_name == "pub_fengliang")
		t = new CNpub_fengliang();
	else if(npc_name == "pub_gaoli")
		t = new CNpub_gaoli();
	else if(npc_name == "pub_gongzi")
		t = new CNpub_gongzi();
	else if(npc_name == "pub_herdsman")
		t = new CNpub_herdsman();
	else if(npc_name == "pub_old")
		t = new CNpub_old();
	else if(npc_name == "pub_oldwoman")
		t = new CNpub_oldwoman();
	else if(npc_name == "pub_shi")
		t = new CNpub_shi();
	else if(npc_name == "pub_whitelady")
		t = new CNpub_whitelady();
	else if(npc_name == "pub_xizi")
		t = new CNpub_xizi();
	else if(npc_name == "pub_zhuoma")
		t = new CNpub_zhuoma();
//new0
	else if(npc_name == "pub_aqingsao")
		t = new CNpub_aqingsao();
	else if(npc_name == "pub_baibian")
		t = new CNpub_baibian();
	else if(npc_name == "pub_guanbing1")
		t = new CNpub_guanbing1();
	else if(npc_name == "pub_chaboshi")
		t = new CNpub_chaboshi();
	else if(npc_name == "pub_chen")
		t = new CNpub_chen();
	else if(npc_name == "pub_chuanfu")
		t = new CNpub_chuanfu();
	else if(npc_name == "pub_chuanfu1")
		t = new CNpub_chuanfu1();
	else if(npc_name == "pub_chuanfu2")
		t = new CNpub_chuanfu2();
	else if(npc_name == "pub_chushi")
		t = new CNpub_chushi();
	else if(npc_name == "pub_cunzhang")
		t = new CNpub_cunzhang();
	else if(npc_name == "pub_daodianhuoji")
		t = new CNpub_daodianhuoji();
	else if(npc_name == "pub_dizi1")
		t = new CNpub_dizi1();
	else if(npc_name == "pub_dizi2")
		t = new CNpub_dizi2();
	else if(npc_name == "pub_dizi3")
		t = new CNpub_dizi3();
	else if(npc_name == "pub_gargoyle")
		t = new CNpub_gargoyle();

	return t;
}