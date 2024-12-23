#include "stdafx.h"
#include "../server/Room.h"
#include "../std/Money.h"
#include "../std/Vendor.h"
#include "../std/BankOwner.h"
#include "../std/Corpse.h"
#include "../server/User.h"
#include "../std/FightRoom.h"
#include "../server/Channel.h"
#include "../std/resident.h"

#include "../npc/pub7/jaja60_80/lev1.h"
#include "../npc/pub7/jaja60_80/pub_baifangxiao.h"
#include "../npc/pub7/jaja60_80/pub_baiyuer.h"
#include "../npc/pub7/jaja60_80/pub_baoqinguang.h"
#include "../npc/pub7/jaja60_80/pub_beibeibei.h"
#include "../npc/pub7/jaja60_80/pub_changhentian.h"
#include "../npc/pub7/jaja60_80/pub_chenfeng.h"
#include "../npc/pub7/jaja60_80/pub_chenmin.h"
#include "../npc/pub7/jaja60_80/pub_diaoer.h"
#include "../npc/pub7/jaja60_80/pub_dingqi.h"
#include "../npc/pub7/jaja60_80/pub_dinli.h"
#include "../npc/pub7/jaja60_80/pub_dinping.h"
#include "../npc/pub7/jaja60_80/pub_dinyi.h"
#include "../npc/pub7/jaja60_80/pub_dongmengqin.h"
#include "../npc/pub7/jaja60_80/pub_dongyuyu.h"
#include "../npc/pub7/jaja60_80/pub_duzongqi.h"
#include "../npc/pub7/jaja60_80/pub_fengwanzhan.h"
#include "../npc/pub7/jaja60_80/pub_fengwuchang.h"
#include "../npc/pub7/jaja60_80/pub_gongtianlai.h"
#include "../npc/pub7/jaja60_80/pub_gongzijun.h"
#include "../npc/pub7/jaja60_80/pub_gousan.h"
#include "../npc/pub7/jaja60_80/pub_guyi.h"
#include "../npc/pub7/jaja60_80/pub_haoren.h"
#include "../npc/pub7/jaja60_80/pub_huiyue.h"
#include "../npc/pub7/jaja60_80/pub_huxiurong.h"
#include "../npc/pub7/jaja60_80/pub_jiangbiehe.h"
#include "../npc/pub7/jaja60_80/pub_jiaoqi.h"
#include "../npc/pub7/jaja60_80/pub_jinjiu.h"
#include "../npc/pub7/jaja60_80/pub_kangzhongming.h"
#include "../npc/pub7/jaja60_80/pub_kongchan.h"
#include "../npc/pub7/jaja60_80/pub_kunzong.h"
#include "../npc/pub7/jaja60_80/pub_lanlanglang.h"
#include "../npc/pub7/jaja60_80/pub_leimeng.h"
#include "../npc/pub7/jaja60_80/pub_lianjin.h"
#include "../npc/pub7/jaja60_80/pub_lincong.h"
#include "../npc/pub7/jaja60_80/pub_linguohong.h"
#include "../npc/pub7/jaja60_80/pub_linhongyin.h"
#include "../npc/pub7/jaja60_80/pub_linjinzhi.h"
#include "../npc/pub7/jaja60_80/pub_linlin.h"
#include "../npc/pub7/jaja60_80/pub_lishenping.h"
#include "../npc/pub7/jaja60_80/pub_liudingguo.h"
#include "../npc/pub7/jaja60_80/pub_liufuming.h"
#include "../npc/pub7/jaja60_80/pub_liurusong.h"
#include "../npc/pub7/jaja60_80/pub_liuyun.h"
#include "../npc/pub7/jaja60_80/pub_luidekuai.h"
#include "../npc/pub7/jaja60_80/pub_lundarong.h"
#include "../npc/pub7/jaja60_80/pub_luxiuwen.h"
#include "../npc/pub7/jaja60_80/pub_luying.h"
#include "../npc/pub7/jaja60_80/pub_marulong.h"
#include "../npc/pub7/jaja60_80/pub_maxiaofeng.h"
#include "../npc/pub7/jaja60_80/pub_miaofeng.h"
#include "../npc/pub7/jaja60_80/pub_murenjin.h"
#include "../npc/pub7/jaja60_80/pub_niefeiqong.h"
#include "../npc/pub7/jaja60_80/pub_nieming.h"
#include "../npc/pub7/jaja60_80/pub_puchen.h"
#include "../npc/pub7/jaja60_80/pub_qianwanguan.h"
#include "../npc/pub7/jaja60_80/pub_qihu.h"
#include "../npc/pub7/jaja60_80/pub_qinpeier.h"
#include "../npc/pub7/jaja60_80/pub_qiufengcheng.h"
#include "../npc/pub7/jaja60_80/pub_qixianglian.h"
#include "../npc/pub7/jaja60_80/pub_rongwu.h"
#include "../npc/pub7/jaja60_80/pub_ruanjiao.h"
#include "../npc/pub7/jaja60_80/pub_ruhua.h"
#include "../npc/pub7/jaja60_80/pub_sasannang.h"
#include "../npc/pub7/jaja60_80/pub_shangguannanyan.h"
#include "../npc/pub7/jaja60_80/pub_shenjia.h"
#include "../npc/pub7/jaja60_80/pub_shentinkang.h"
#include "../npc/pub7/jaja60_80/pub_situshashou.h"
#include "../npc/pub7/jaja60_80/pub_songlingong.h"
#include "../npc/pub7/jaja60_80/pub_tumengping.h"
#include "../npc/pub7/jaja60_80/pub_wangyiming.h"
#include "../npc/pub7/jaja60_80/pub_wangyipeng.h"
#include "../npc/pub7/jaja60_80/pub_wufa.h"
#include "../npc/pub7/jaja60_80/pub_wuque.h"
#include "../npc/pub7/jaja60_80/pub_wutian.h"
#include "../npc/pub7/jaja60_80/pub_wuweiyang.h"
#include "../npc/pub7/jaja60_80/pub_wuyikun.h"
#include "../npc/pub7/jaja60_80/pub_xianfeitian.h"
#include "../npc/pub7/jaja60_80/pub_xiaowuyu.h"
#include "../npc/pub7/jaja60_80/pub_xieqiufeng.h"
#include "../npc/pub7/jaja60_80/pub_xieyulun.h"
#include "../npc/pub7/jaja60_80/pub_xixuxi.h"
#include "../npc/pub7/jaja60_80/pub_xuaniu.h"
#include "../npc/pub7/jaja60_80/pub_xucong.h"
#include "../npc/pub7/jaja60_80/pub_yanqiansui.h"
#include "../npc/pub7/jaja60_80/pub_yantingyan.h"
#include "../npc/pub7/jaja60_80/pub_yaoyue.h"
#include "../npc/pub7/jaja60_80/pub_yejun.h"
#include "../npc/pub7/jaja60_80/pub_youwuyan.h"
#include "../npc/pub7/jaja60_80/pub_yuanyanggang.h"
#include "../npc/pub7/jaja60_80/pub_yumu.h"
#include "../npc/pub7/jaja60_80/pub_yunwuxiang.h"
#include "../npc/pub7/jaja60_80/pub_yutianxiang.h"
#include "../npc/pub7/jaja60_80/pub_yuzhuzi.h"
#include "../npc/pub7/jaja60_80/pub_zhanglaoshi.h"
#include "../npc/pub7/jaja60_80/pub_zhenfang.h"
#include "../npc/pub7/jaja60_80/pub_zhenwanjian.h"
#include "../npc/pub7/jaja60_80/pub_zongjinquan.h"

#include "../npc/pub7/jaja80_110/lev2.h"
#include "../npc/pub7/jaja80_110/pub_gongsundanang.h"
#include "../npc/pub7/jaja80_110/pub_yujiaofeng.h"
#include "../npc/pub7/jaja80_110/pub_yuzhuzi.h"
#include "../npc/pub7/jaja80_110/pub_zhenfang.h"

#include "../npc/pub7/yuandan/baxian_cao.h"
#include "../npc/pub7/yuandan/baxian_han.h"
#include "../npc/pub7/yuandan/baxian_lv.h"
#include "../npc/pub7/yuandan/baxian_he.h"
#include "../npc/pub7/yuandan/baxian_lan.h"
#include "../npc/pub7/yuandan/baxian_han1.h"
#include "../npc/pub7/yuandan/baxian_zhang.h"
#include "../npc/pub7/yuandan/baxian_li.h"


#include "../npc/pub7/chunjie/wiz_109.h"
#include "../npc/pub7/chunjie/wiz_104.h"
#include "../npc/pub7/chunjie/pub_qiangdao.h"
#include "../npc/pub7/chunjie/wiz_101.h"
#include "../npc/pub7/chunjie/wiz_203.h"
//#include "../npc/pub7/chunjie/wiz_106.h"
//#include "../npc/pub7/chunjie/wiz_103.h"


CNpc * LoadNPC_pub7(string npc_name)
{
	CNpc * t = 0;
	
	if(npc_name == "pub_baifangxiao")
		t = new CNlev1_baifangxiao();
	else if(npc_name == "pub_baiyuer")
		t = new CNlev1_baiyuer();
	else if(npc_name == "pub_baoqinguang")
		t = new CNlev1_baoqinguang();
	else if(npc_name == "pub_beibeibei")
		t = new CNlev1_beibeibei();
	else if(npc_name == "pub_changhentian")
		t = new CNlev1_changhentian();
	else if(npc_name == "pub_chenfeng")
		t = new CNlev1_chenfeng();
	else if(npc_name == "pub_chenmin")
		t = new CNlev1_chenmin();
	else if(npc_name == "pub_diaoer")
		t = new CNlev1_diaoer();
	else if(npc_name == "pub_dingqi")
		t = new CNlev1_dingqi();
	else if(npc_name == "pub_dinli")
		t = new CNlev1_dinli();
	else if(npc_name == "pub_dinping")
		t = new CNlev1_dinping();
	else if(npc_name == "pub_dinyi")
		t = new CNlev1_dinyi();
	else if(npc_name == "pub_dongmengqin")
		t = new CNlev1_dongmengqin();
	else if(npc_name == "pub_dongyuyu")
		t = new CNlev1_dongyuyu();
	else if(npc_name == "pub_duzongqi")
		t = new CNlev1_duzongqi();
	else if(npc_name == "pub_fengwanzhan")
		t = new CNlev1_fengwanzhan();
	else if(npc_name == "pub_fengwuchang")
		t = new CNlev1_fengwuchang();
	else if(npc_name == "pub_gongtianlai")
		t = new CNlev1_gongtianlai();
	else if(npc_name == "pub_gongzijun")
		t = new CNlev1_gongzijun();
	else if(npc_name == "pub_gousan")
		t = new CNlev1_gousan();
	else if(npc_name == "pub_guyi")
		t = new CNlev1_guyi();
	else if(npc_name == "pub_haoren")
		t = new CNlev1_haoren();
	else if(npc_name == "pub_huiyue")
		t = new CNlev1_huiyue();
	else if(npc_name == "pub_huxiurong")
		t = new CNlev1_huxiurong();
	else if(npc_name == "pub_jiangbiehe")
		t = new CNlev1_jiangbiehe();
	else if(npc_name == "pub_jiaoqi")
		t = new CNlev1_jiaoqi();
	else if(npc_name == "pub_jinjiu")
		t = new CNlev1_jinjiu();
	else if(npc_name == "pub_kangzhongming")
		t = new CNlev1_kangzhongming();
	else if(npc_name == "pub_kongchan")
		t = new CNlev1_kongchan();
	else if(npc_name == "pub_kunzong")
		t = new CNlev1_kunzong();
	else if(npc_name == "pub_lanlanglang")
		t = new CNlev1_lanlanglang();
	else if(npc_name == "pub_leimeng")
		t = new CNlev1_leimeng();
	else if(npc_name == "pub_lianjin")
		t = new CNlev1_lianjin();
	else if(npc_name == "pub_lincong")
		t = new CNlev1_lincong();
	else if(npc_name == "pub_linguohong")
		t = new CNlev1_linguohong();
	else if(npc_name == "pub_linhongyin")
		t = new CNlev1_linhongyin();
	else if(npc_name == "pub_linjinzhi")
		t = new CNlev1_linjinzhi();
	else if(npc_name == "pub_linlin")
		t = new CNlev1_linlin();
	else if(npc_name == "pub_lishenping")
		t = new CNlev1_lishenping();
	else if(npc_name == "pub_liudingguo")
		t = new CNlev1_liudingguo();
	else if(npc_name == "pub_liufuming")
		t = new CNlev1_liufuming();
	else if(npc_name == "pub_liurusong")
		t = new CNlev1_liurusong();
	else if(npc_name == "pub_liuyun")
		t = new CNlev1_liuyun();
	else if(npc_name == "pub_luidekuai")
		t = new CNlev1_luidekuai();
	else if(npc_name == "pub_lundarong")
		t = new CNlev1_luidekuai();
	else if(npc_name == "pub_luxiuwen")
		t = new CNlev1_luxiuwen();
	else if(npc_name == "pub_luying")
		t = new CNlev1_luying();
	else if(npc_name == "pub_marulong")
		t = new CNlev1_marulong();
	else if(npc_name == "pub_maxiaofeng")
		t = new CNlev1_maxiaofeng();
	else if(npc_name == "pub_miaofeng")
		t = new CNlev1_miaofeng();
	else if(npc_name == "pub_murenjin")
		t = new CNlev1_murenjin();
	else if(npc_name == "pub_niefeiqong")
		t = new CNlev1_niefeiqong();
	else if(npc_name == "pub_nieming")
		t = new CNlev1_nieming();
	else if(npc_name == "pub_puchen")
		t = new CNlev1_puchen();
	else if(npc_name == "pub_qianwanguan")
		t = new CNlev1_qianwanguan();
	else if(npc_name == "pub_qihu")
		t = new CNlev1_qihu();
	else if(npc_name == "pub_qinpeier")
		t = new CNlev1_qinpeier();
	else if(npc_name == "pub_qiufengcheng")
		t = new CNlev1_qiufengcheng();
	else if(npc_name == "pub_qixianglian")
		t = new CNlev1_qixianglian();
	else if(npc_name == "pub_rongwu")
		t = new CNlev1_rongwu();
	else if(npc_name == "pub_ruanjiao")
		t = new CNlev1_ruanjiao();
	else if(npc_name == "pub_ruhua")
		t = new CNlev1_ruhua();
	else if(npc_name == "pub_sasannang")
		t = new CNlev1_sasannang();
	else if(npc_name == "pub_shangguannanyan")
		t = new CNlev1_shangguannanyan();
	else if(npc_name == "pub_shenjia")
		t = new CNlev1_shenjia();
	else if(npc_name == "pub_shentinkang")
		t = new CNlev1_shentinkang();
	else if(npc_name == "pub_situshashou")
		t = new CNlev1_situshashou();
	else if(npc_name == "pub_songlingong")
		t = new CNlev1_songlingong();
	else if(npc_name == "pub_tumengping")
		t = new CNlev1_tumengping();
	else if(npc_name == "pub_wangyiming")
		t = new CNlev1_wangyiming();
	else if(npc_name == "pub_wangyipeng")
		t = new CNlev1_wangyipeng();
	else if(npc_name == "pub_wufa")
		t = new CNlev1_wufa();
	else if(npc_name == "pub_wuque")
		t = new CNlev1_wuque();
	else if(npc_name == "pub_wutian")
		t = new CNlev1_wutian();
	else if(npc_name == "pub_wuweiyang")
		t = new CNlev1_wuweiyang();
	else if(npc_name == "pub_wuyikun")
		t = new CNlev1_wuyikun();
	else if(npc_name == "pub_xianfeitian")
		t = new CNlev1_xianfeitian();
	else if(npc_name == "pub_xiaowuyu")
		t = new CNlev1_xiaowuyu();
	else if(npc_name == "pub_xieqiufeng")
		t = new CNlev1_xieqiufeng();
	else if(npc_name == "pub_xieyulun")
		t = new CNlev1_xieyulun();
	else if(npc_name == "pub_xixuxi")
		t = new CNlev1_xixuxi();
	else if(npc_name == "pub_xuaniu")	
		t = new CNlev1_xuaniu();
	else if(npc_name == "pub_xucong")
		t = new CNlev1_xucong();
	else if(npc_name == "pub_yanqiansui")
		t = new CNlev1_yanqiansui();
	else if(npc_name == "pub_yantingyan")	
		t = new CNlev1_yantingyan();
	else if(npc_name == "pub_yaoyue")
		t = new CNlev1_yaoyue();
	else if(npc_name == "pub_yejun")
		t = new CNlev1_yejun();
	else if(npc_name == "pub_youwuyan")
		t = new CNlev1_youwuyan();
	else if(npc_name == "pub_yuanyanggang")
		t = new CNlev1_yuanyanggang();
	else if(npc_name == "pub_yumu")
		t = new CNlev1_yumu();
	else if(npc_name == "pub_yunwuxiang")
		t = new CNlev1_yunwuxiang();
	else if(npc_name == "pub_yutianxiang")
		t = new CNlev1_yutianxiang();
	else if(npc_name == "pub_yuzhuzi")
		t = new CNlev1_yuzhuzi();
	else if(npc_name == "pub_zhanglaoshi")
		t = new CNlev1_zhanglaoshi();
	else if(npc_name == "pub_zhenfang")
		t = new CNlev1_zhenfang();
	else if(npc_name == "pub_zhenwanjian")
		t = new CNlev1_zhenwanjian();
	else if(npc_name == "pub_zongjinquan")
		t = new CNlev1_zongjinquan();

	else if(npc_name == "pub_gongsundanang")
		t = new CNlev2_gongsundanang();
	else if(npc_name == "pub_yujiaofeng")
		t = new CNlev2_yujiaofeng();
	else if(npc_name == "pub_zhenfang")
		t = new CNlev2_zhenfang();
	else if(npc_name == "pub_yuzhuzi")
		t = new CNlev2_yuzhuzi();

	else if(npc_name == "pub_caoguojiou")
		t = new CNpub_caoguojiou();
	else if(npc_name == "pub_hanzhongli")
		t = new CNpub_hanzhongli();
	else if(npc_name == "pub_lvdongbing")
		t = new CNpub_lvdongbing();
	else if(npc_name == "pub_hexiangu")
		t = new CNpub_hexiangu();
	else if(npc_name == "pub_lancaihe")
		t = new CNpub_lancaihe();
	else if(npc_name == "pub_hanxiangzi")
		t = new CNpub_hanxiangzi();
	else if(npc_name == "pub_zhangguolao")
		t = new CNpub_zhangguolao();
	else if(npc_name == "pub_tieguaili")
		t = new CNpub_tieguaili();

	else if(npc_name == "wiz_109")
		t = new CNwiz_109();
	else if(npc_name == "wiz_104")
		t = new CNwiz_104();
	else if(npc_name == "wiz_101")
		t = new CNwiz_101();
	else if(npc_name == "wiz_203")
		t = new CNwiz_203();
	else if(npc_name == "pub_qiangdao")
		t = new CNpub_qiangdao();
/*	else if(npc_name == "wiz_106")
		t = new CNwiz_106();
	else if(npc_name == "wiz_103")
		t = new CNwiz_103();
*/
	return t;
}


