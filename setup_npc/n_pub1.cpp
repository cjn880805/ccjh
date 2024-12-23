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

//-----------------------------------------------------------------
//
//	公共NPC之一
//	author:		Zou Wen Bin
//	date:		2000-12-26
//
//-----------------------------------------------------------------


#include "../npc/pub/pub_huangyu.h"
#include "../npc/pub/pub_manxiangke.h"

#include "../npc/pub/banker.h"
#include "../npc/pub/pub_habagou.h"
#include "../npc/pub/pub_biaotou.h"
#include "../npc/pub/pub_bing.h"
#include "../npc/pub/pub_bshangfan.h"
#include "../npc/pub/pub_girl.h"
#include "../npc/pub/pub_jiading.h"
#include "../npc/pub/pub_kid.h"
#include "../npc/pub/pub_mafu.h"
#include "../npc/pub/pub_menggubing.h"
#include "../npc/pub/pub_mujiang.h"

#include "../npc/pub/pub_clothboss.h"///////////老板娘
//1214
#include "../npc/pub/pub_baier.h"
#include "../npc/pub/pub_bangzong.h"
#include "../npc/pub/pub_basic.h"
#include "../npc/pub/pub_bayi.h"
#include "../npc/pub/pub_boy.h"
#include "../npc/pub/pub_boydizi.h"
#include "../npc/pub/pub_caichanu.h"
#include "../npc/pub/pub_caisangnu.h"
#include "../npc/pub/pub_caishiren.h"
#include "../npc/pub/pub_caisunren.h"
#include "../npc/pub/pub_caisunren1.h"
#include "../npc/pub/pub_caiyaoren.h"
#include "../npc/pub/pub_chaofeng.h"
#include "../npc/pub/pub_chengqi.h"
#include "../npc/pub/pub_cuihua.h"
#include "../npc/pub/pub_cunfu.h"
#include "../npc/pub/pub_cungu.h"
#include "../npc/pub/pub_cunmin.h"
#include "../npc/pub/pub_dahu.h"
#include "../npc/pub/pub_daoke.h"
#include "../npc/pub/pub_diaoyu.h"
#include "../npc/pub/pub_dibao.h"
#include "../npc/pub/pub_dipi.h"
#include "../npc/pub/pub_dizi.h"
#include "../npc/pub/pub_duantiande.h"
#include "../npc/pub/pub_enu.h"
#include "../npc/pub/pub_erhu.h"
#include "../npc/pub/pub_fangshanu.h"
#include "../npc/pub/pub_fengzaiming.h"
#include "../npc/pub/pub_flowerg.h"
#include "../npc/pub/pub_fuer.h"
#include "../npc/pub/pub_funu.h"
//
#include "../npc/pub/pub_genu.h"
#include "../npc/pub/pub_geshiha.h"
#include "../npc/pub/pub_girl1.h"
#include "../npc/pub/pub_girldizi.h"
#include "../npc/pub/pub_gongnu.h"
#include "../npc/pub/pub_gongnv.h"
#include "../npc/pub/pub_weishi.h"
#include "../npc/pub/pub_guafu.h"
#include "../npc/pub/pub_guanjia.h"
#include "../npc/pub/pub_guanzho.h"
#include "../npc/pub/pub_guanzho2.h"
#include "../npc/pub/pub_guest.h"
#include "../npc/pub/pub_guigong.h"
#include "../npc/pub/pub_guigongzi.h"
#include "../npc/pub/pub_guniang.h"
#include "../npc/pub/pub_hehongyao.h"
#include "../npc/pub/pub_hongmao.h"
#include "../npc/pub/pub_houxiahai.h"
#include "../npc/pub/pub_huanu.h"
#include "../npc/pub/pub_huoji.h"
#include "../npc/pub/pub_huyuan.h"
#include "../npc/pub/pub_jianghuyiren.h"
#include "../npc/pub/pub_jianke.h"
#include "../npc/pub/pub_jinbing.h"
#include "../npc/pub/pub_jisi.h"
#include "../npc/pub/pub_kanzhuren.h"
#include "../npc/pub/pub_laojisi.h"

//
#include "../npc/pub/pub_liesho.h"
#include "../npc/pub/pub_lady1.h"
#include "../npc/pub/pub_lady2.h"
#include "../npc/pub/pub_laocai.h"
#include "../npc/pub/pub_lieren.h"
#include "../npc/pub/pub_keshang.h"
#include "../npc/pub/pub_liufuren.h"
#include "../npc/pub/pub_liumang.h"
#include "../npc/pub/pub_liumangtou.h"
#include "../npc/pub/pub_man.h"
#include "../npc/pub/pub_menmian.h"
#include "../npc/pub/pub_menwei1.h"
#include "../npc/pub/pub_laojisi1.h"
#include "../npc/pub/pub_muyangnu.h"
#include "../npc/pub/pub_muyangren.h"
#include "../npc/pub/pub_nanpu.h"
#include "../npc/pub/pub_nigu1.h"
#include "../npc/pub/pub_nigu2.h"
#include "../npc/pub/pub_nongfu.h"
#include "../npc/pub/pub_nongfu1.h"
#include "../npc/pub/pub_nongfu2.h"
#include "../npc/pub/pub_oldman.h"
#include "../npc/pub/pub_oscar.h"

//新增高级NPC
#include "../npc/pub/pub_caodongyun.h"
#include "../npc/pub/pub_mowentian.h"
#include "../npc/pub/pub_baiyulang.h"
#include "../npc/pub/pub_gaoming.h"
#include "../npc/pub/pub_shuiyunyan.h"
#include "../npc/pub/pub_weiziyi.h"
#include "../npc/pub/pub_fanghenxiao.h"
#include "../npc/pub/pub_liushengshibingwei.h"
#include "../npc/pub/pub_xiaoqiang.h"
#include "../npc/pub/pub_zhongbuliang.h"
#include "../npc/pub/pub_liufeiyan.h"
#include "../npc/pub/pub_wuxing.h"
#include "../npc/pub/pub_ningfeng.h"
#include "../npc/pub/pub_zhuoyihang.h"
#include "../npc/pub/pub_duguqiu.h"
#include "../npc/pub/pub_liujue.h"
#include "../npc/pub/pub_liqiuhen.h"
#include "../npc/pub/pub_duguo.h"
#include "../npc/pub/pub_guoda.h"
#include "../npc/pub/pub_liuquan.h"
#include "../npc/pub/pub_maxiaotian.h"
#include "../npc/pub/pub_wanghu.h"
#include "../npc/pub/pub_wuan.h"
#include "../npc/pub/pub_zhuzhao.h"

#include "../npc/pub6/pub_sangyuan.h"
#include "../npc/pub6/pub_feiying.h"
#include "../npc/pub6/pub_guochou.h"
#include "../npc/pub6/pub_henmantian.h"
#include "../npc/pub6/pub_huanhai.h"
#include "../npc/pub6/pub_wangmu.h"
#include "../npc/pub6/pub_xuecai.h"
#include "../npc/pub6/pub_youzhu.h"
#include "../npc/pub6/pub_zangma.h"
#include "../npc/pub6/pub_zhaoba.h"
//140级以后
#include "../npc/pub7/pub_bixuan.h"
#include "../npc/pub7/zcoya/pub_holysworder.h"
#include "../npc/pub7/zcoya/pub_beggarking.h"
#include "../npc/pub7/zcoya/pub_swordmaster.h"
#include "../npc/pub7/zcoya/pub_sword_master.h"
#include "../npc/pub7/pub_tiezhan.h"
#include "../npc/pub7/pub_ouyangbu.h"
#include "../npc/pub7/pub_ouyangzhan.h"
#include "../npc/pub7/pub_likuozui.h"
#include "../npc/pub7/pub_jinshezunzhe.h"
#include "../npc/pub7/pub_yuanziyi.h"
#include "../npc/pub7/pub_hahazi.h"
#include "../npc/pub7/pub_zhaojunzhu.h"
#include "../npc/pub7/pub_yinjiuyou.h"
#include "../npc/pub7/pub_xiaomimi.h"
#include "../npc/pub7/pub_tuguaiguai.h"
#include "../npc/pub7/pub_dusha.h"
#include "../npc/pub7/pub_chenlingsu.h"
#include "../npc/pub7/pub_baihuanxi.h"
//jj
#include "../npc/pub7/pub_baixin.h"
#include "../npc/pub7/pub_longyun.h"
#include "../npc/pub7/pub_shenmike.h"
#include "../npc/pub7/pub_chezhongnv.h"
#include "../npc/pub7/pub_jinshisanniang.h"
#include "../npc/pub7/pub_jinxilaoren.h"
#include "../npc/pub7/pub_kunlunnu.h"
#include "../npc/pub7/pub_lanlinlaoren.h"
#include "../npc/pub7/pub_lushen.h"
#include "../npc/pub7/pub_nieyinnang.h"
#include "../npc/pub7/pub_ruzhousen.h"
#include "../npc/pub7/pub_shenjiqiu.h"
#include "../npc/pub7/pub_wangjinhongpu.h"
#include "../npc/pub7/pub_zaochunv.h"
#include "../npc/pub7/pub_liguishou.h"
#include "../npc/pub7/pub_hongxian.h"
#include "../npc/pub7/pub_renzhennv.h"
#include "../npc/pub7/pub_dinxiucai.h"
#include "../npc/pub7/pub_simingtoutuo.h"
#include "../npc/pub7/pub_jiarenqi.h"
#include "../npc/pub7/pub_yicimengzi.h"
#include "../npc/pub7/pub_weiyangyu.h"
#include "../npc/pub7/pub_sixinzhe.h"
#include "../npc/pub7/pub_lisheng.h"
#include "../npc/pub7/pub_xiuzhoucike.h"
#include "../npc/pub7/pub_zhangxunqi.h"
#include "../npc/pub7/pub_panjianke.h"
#include "../npc/pub7/pub_hongzhoushushen.h"
#include "../npc/pub7/pub_yixia.h"
#include "../npc/pub7/pub_qinjinzhe.h"
#include "../npc/pub7/pub_zhangzhongding.h"
#include "../npc/pub7/pub_zichuandaoshi.h"
#include "../npc/pub7/pub_xiafuren.h"
#include "../npc/pub7/pub_xiexunfu.h"
#include "../npc/pub7/pub_jiaojindaoren.h"
#include "../npc/pub7/pub_laocunzhang.h"
#include "../npc/pub7/pub_jieshouyuan.h"
#include "../npc/pub7/pub_baoguanyuan.h"
#include "../npc/pub7/pub_xuemingfeng.h"
#include "../npc/pub7/pub_buchanshi.h"
#include "../npc/pub7/pub_lijin.h"
#include "../npc/pub7/pub_hongfunv.h"
#include "../npc/pub7/pub_qiuranke.h"
/*
//天罡北斗阵NPC
#include "../npc/pub5/zheng_hao.h"
#include "../npc/pub5/zheng_liu.h"
#include "../npc/pub5/zheng_ma.h"
#include "../npc/pub5/zheng_qiu.h"
#include "../npc/pub5/zheng_sun.h"
#include "../npc/pub5/zheng_tan.h"
#include "../npc/pub5/zheng_wangchuyi.h"
*/
#include "../npc/nd/chengdu/pub_baixiaosheng.h"	//百晓生
#include "../npc/pub/pub_gongsunzhi.h"	//公孙指
#include "../npc/pub/pub_jueqingdizi.h"	//绝情谷弟子
#include "../npc/pub/pub_xuanyuanguang.h"	//轩辕光（赌博）
#include "../npc/pub/pub_mjdizi.h"	//明教弟子（围攻光明顶）
#include "../npc/pub/pub_mjkill1.h"	//少林弟子（围攻光明顶）
#include "../npc/pub/pub_mjkill2.h"	//武当弟子（围攻光明顶）
#include "../npc/pub/pub_mjkill3.h"	//娥眉弟子（围攻光明顶）
#include "../npc/pub/pub_mjkill4.h"	//崆峒弟子（围攻光明顶）
#include "../npc/pub/pub_mjkill5.h"	//华山弟子（围攻光明顶）
#include "../npc/pub/pub_mjkill6.h"	//昆仑弟子（围攻光明顶）
#include "../npc/pub/pub_fengshanshi.h"	//封山使者（围攻光明顶）
#include "../npc/pub/pub_mjkillboss.h"	//灭绝师太（围攻光明顶）
#include "../npc/pub/pub_chuanlinshi.h"	//传令结束战斗使者（围攻光明顶）
#include "../npc/pub/pub_zueijiaoshi.h"	//明教任务失败追剿使（围攻光明顶）

#include "../npc/pub/pub_tangzishou.h"	//福威镖局趟子手（清除大米捣乱）
#include "../npc/pub/pub_guard.h"	//金牌捕快
#include "../npc/pub/pub_umpire.h"	//裁判
#include "../npc/pub/pub_compere.h"	//比武收费人
#include "../npc/pub/pub_binv.h"	//婢女
#include "../npc/pub/pub_maochenglong.h"	//毛成龙
#include "../npc/pub/pub_mao_huyuan.h"	//毛府护院
#include "../npc/pub/pub_mao_huyuan2.h"	//毛府护院
#include "../npc/pub/pub_mao_huyuan3.h"	//毛府护院
#include "../npc/pub/pub_maochenglongzi.h"	//毛成龙子
#include "../npc/pub/pub_zaochongzha.h"	//户部尚书赵崇祚
#include "../npc/pub/pub_sunchengxian.h"	//礼部侍郎孙承宪
#include "../npc/pub/pub_yuguangqi.h"	//襄阳安抚使余光启
#include "../npc/pub/pub_xyqinbing.h"	//襄阳安抚使衙门亲兵

CNpc * LoadNPC_pub1(string npc_name)
{
	CNpc * t = 0;

	if(npc_name == "pub_pochen")
		t = new CNpub_guest();

	else if(npc_name == "pub_bshangfan")
		t = new CNPub_bshangfan();
	else if(npc_name == "pub_fengzaiming")
		t = new CNPub_fengzaiming();
	else if(npc_name == "pub_fangshanu")
		t = new CNPub_fangshanu();
	else if(npc_name == "pub_erhu")
		t = new CNPub_erhu();
	else if(npc_name == "pub_enu")
		t = new CNPub_enu();
	else if(npc_name == "pub_duantiande")
		t = new CNPub_duantiande();
	else if(npc_name == "pub_dizi")
		t = new CNPub_dizi();
	else if(npc_name == "pub_dipi")
		t = new CNPub_dipi();
	else if(npc_name == "pub_dibao")
		t = new CNPub_dibao();
	else if(npc_name == "pub_diaoyu")
		t = new CNPub_diaoyu();
	else if(npc_name == "pub_daoke")
		t = new CNPub_daoke();
	else if(npc_name == "pub_dahu")
		t = new CNPub_dahu();
	else if(npc_name == "pub_cunmin")
		t = new CNPub_cunmin();
	else if(npc_name == "pub_cungu")
		t = new CNPub_cungu();
	else if(npc_name == "pub_cunfu")
		t = new CNPub_cunfu();
	else if(npc_name == "pub_cuihua")
		t = new CNPub_cuihua();
	else if(npc_name == "pub_clothboss")
		t = new CNpub_clothboss();
	else if(npc_name == "pub_chengqi")
		t = new CNPub_chengqi();
	else if(npc_name == "pub_chaofeng")
		t = new CNPub_chaofeng();

	else if(npc_name == "pub_caiyaoren")
		t = new CNPub_caiyaoren();
	else if(npc_name == "pub_caisunren1")
		t = new CNPub_caisunren1();
	else if(npc_name == "pub_caisunren")
		t = new CNPub_caisunren();
	else if(npc_name == "pub_caishiren")
		t = new CNPub_caishiren();
	else if(npc_name == "pub_caisangnu")
		t = new CNPub_caisangnu();
	else if(npc_name == "pub_caichanu")
		t = new CNPub_caichanu();
	else if(npc_name == "pub_banker")
		t = new CNBanker();
	else if(npc_name == "pub_boydizi")
		t = new CNPub_boydizi();
	else if(npc_name == "pub_boy")
		t = new CNPub_boy();
	else if(npc_name == "pub_bing")
		t = new CNPub_bing();
	else if(npc_name == "pub_biaotou")
		t = new CNpub_biaotou();
	else if(npc_name == "pub_bayi")
		t = new CNPub_bayi();
	else if(npc_name == "pub_basic")
		t = new CNPub_basic();
	else if(npc_name == "pub_bangzong")
		t = new CNPub_bangzong();
	else if(npc_name == "pub_baier")
		t = new CNPub_baier();
	else if(npc_name == "pub_kid")
		t = new CNPub_kid();
	else if(npc_name == "pub_keshang")
		t = new CNPub_keshang();
	else if(npc_name == "pub_kanzhuren")
		t = new CNpub_kanzhuren();
	else if(npc_name == "pub_jisi")
		t = new CNpub_jisi();
	else if(npc_name == "pub_jinbing")
		t = new CNpub_jinbing();
	else if(npc_name == "pub_jianke")
		t = new CNpub_jianke();
	else if(npc_name == "pub_jianghuyiren")
		t = new CNpub_jianghuyiren();
	else if(npc_name == "pub_jiading")
		t = new CNPub_jiading();
	else if(npc_name == "pub_huyuan")
		t = new CNpub_huyuan();
	else if(npc_name == "pub_huoji")
		t = new CNpub_huoji();
	else if(npc_name == "pub_huanu")
		t = new CNpub_huanu();
	else if(npc_name == "pub_huangyu")
		t = new CNPub_huangyu();
	else if(npc_name == "pub_houxiahai")
		t = new CNpub_houxiahai();
	else if(npc_name == "pub_hongmao")
		t = new CNpub_hongmao();
	else if(npc_name == "pub_hehongyao")
		t = new CNpub_hehongyao();
	else if(npc_name == "pub_habagou")
		t = new CNPub_habagou();
	else if(npc_name == "pub_guniang")
		t = new CNpub_guniang();

	//
	else if(npc_name == "pub_guigongzi")
		t = new CNpub_guigongzi();
	else if(npc_name == "pub_guigong")
		t = new CNpub_guigong();
	else if(npc_name == "pub_flowerg")
		t = new CNPub_flowerg();
	else if(npc_name == "pub_guanzho2")
		t = new CNpub_guanzho2();
	else if(npc_name == "pub_guanzho")
		t = new CNpub_guanzho();
	else if(npc_name == "pub_guanjia")
		t = new CNpub_guanjia();
	else if(npc_name == "pub_guafu")
		t = new CNpub_guafu();
	else if(npc_name == "pub_weishi")
		t = new CNPub_weishi();
	else if(npc_name == "pub_gongnv")
		t = new CNpub_gongnv();
	else if(npc_name == "pub_gongnu")
		t = new CNpub_gongnu();
	else if(npc_name == "pub_girldizi")
		t = new CNpub_girldizi();
	else if(npc_name == "pub_girl1")
		t = new CNpub_girl1();
	else if(npc_name == "pub_girl")
		t = new CNPub_girl();
	else if(npc_name == "pub_geshiha")
		t = new CNpub_geshiha();
	else if(npc_name == "pub_genu")
		t = new CNpub_genu();
	else if(npc_name == "pub_funu")
		t = new CNPub_funu();
	else if(npc_name == "pub_fuer")
		t = new CNPub_fuer();
	else if(npc_name == "pub_guest")
		t = new CNpub_guest();
	else if(npc_name == "pub_oscar")
		t = new CNPub_oscar();
	else if(npc_name == "pub_oldman")
		t = new CNPub_oldman();
	else if(npc_name == "pub_nongfu2")
		t = new CNPub_nongfu2();
	else if(npc_name == "pub_nongfu1")
		t = new CNPub_nongfu1();
	//
	else if(npc_name == "pub_nongfu")
		t = new CNPub_nongfu();
	else if(npc_name == "pub_nigu2")
		t = new CNPub_nigu2();
	else if(npc_name == "pub_nigu1")
		t = new CNPub_nigu1();
	else if(npc_name == "pub_nanpu")
		t = new CNPub_nanpu();
	else if(npc_name == "pub_muyangren")
		t = new CNPub_muyangren();
	else if(npc_name == "pub_muyangnu")
		t = new CNPub_muyangnu();
	else if(npc_name == "pub_mujiang")
		t = new CNPub_mujiang();
	else if(npc_name == "pub_menwei1")
		t = new CNPub_menwei1();
	else if(npc_name == "pub_menmian")
		t = new CNPub_menmian();
	else if(npc_name == "pub_menggubing")
		t = new CNPub_menggubing();
	else if(npc_name == "pub_manxiangke")
		t = new CNPub_manxiangke();
	else if(npc_name == "pub_man")
		t = new CNPub_man();
	else if(npc_name == "pub_mafu")
		t = new CNPub_mafu();
	else if(npc_name == "pub_liumangtou")
		t = new CNPub_liumangtou();
	else if(npc_name == "pub_liumang")
		t = new CNPub_liumang();
	else if(npc_name == "pub_liufuren")
		t = new CNPub_liufuren();
	else if(npc_name == "pub_lady1")
		t = new CNPub_lady1();
	else if(npc_name == "pub_lieren")
		t = new CNPub_lieren();
	else if(npc_name == "pub_laojisi1")
		t = new CNPub_laojisi1();
	else if(npc_name == "pub_laojisi")
		t = new CNpub_laojisi();
	else if(npc_name == "pub_laocai")
		t = new CNPub_laocai();
	else if(npc_name == "pub_lady2")
		t = new CNPub_lady2();
	else if(npc_name == "pub_liesho")
		t = new CNPub_liesho();
//新增60级以上杀经验用NPC
	else if(npc_name == "pub_caodongyun")
		t = new CNpub_caodongyun();
	else if(npc_name == "pub_mowentian")
		t = new CNpub_mowentian();
	else if(npc_name == "pub_baiyulang")
		t = new CNpub_baiyulang();
	else if(npc_name == "pub_gaoming")
		t = new CNpub_gaoming();
	else if(npc_name == "pub_shuiyunyan")
		t = new CNpub_shuiyunyan();
	else if(npc_name == "pub_weiziyi")
		t = new CNpub_weiziyi();
	else if(npc_name == "pub_fanghenxiao")
		t = new CNpub_fanghenxiao();
	else if(npc_name == "pub_liushengshibingwei")
		t = new CNpub_liushengshibingwei();
	else if(npc_name == "pub_xiaoqiang")
		t = new CNpub_xiaoqiang();
	else if(npc_name == "pub_zhongbuliang")
		t = new CNpub_zhongbuliang();
	else if(npc_name == "pub_liufeiyan")
		t = new CNpub_liufeiyan();
	else if(npc_name == "pub_wuxing")
		t = new CNpub_wuxing();
	else if(npc_name == "pub_ningfeng")
		t = new CNpub_ningfeng();
	else if(npc_name == "pub_zhuoyihang")
		t = new CNpub_zhuoyihang();
	else if(npc_name == "pub_duguqiu")
		t = new CNpub_duguqiu();
	else if(npc_name == "pub_liujue")
		t = new CNpub_liujue();
	else if(npc_name == "pub_liqiuhen")
		t = new CNpub_liqiuhen();
	else if(npc_name == "pub_duguo")
		t = new CNpub_duguo();
	else if(npc_name == "pub_guoda")
		t = new CNpub_guoda();
	else if(npc_name == "pub_liuquan")
		t = new CNpub_liuquan();
	else if(npc_name == "pub_maxiaotian")
		t = new CNpub_maxiaotian();
	else if(npc_name == "pub_wanghu")
		t = new CNpub_wanghu();
	else if(npc_name == "pub_wuan")
		t = new CNpub_wuan();
	else if(npc_name == "pub_zhuzhao")
		t = new CNpub_zhuzhao();
//60-80级NPC
	else if(npc_name == "pub_sangyuan")
		t = new CNpub_sangyuan();
	else if(npc_name == "pub_feiying")
		t = new CNpub_feiying();
	else if(npc_name == "pub_guochou")
		t = new CNpub_guochou();
	else if(npc_name == "pub_henmantian")
		t = new CNpub_henmantian();
	else if(npc_name == "pub_huanhai")
		t = new CNpub_huanhai();
	else if(npc_name == "pub_wangmu")
		t = new CNpub_wangmu();
	else if(npc_name == "pub_xuecai")
		t = new CNpub_xuecai();
	else if(npc_name == "pub_youzhu")
		t = new CNpub_youzhu();
	else if(npc_name == "pub_zangma")
		t = new CNpub_zangma();
	else if(npc_name == "pub_zhaoba")
		t = new CNpub_zhaoba();
/*
//天罡北斗阵NPC
	else if(npc_name == "zheng_hao")
		t=new CNzheng_hao();
	else if(npc_name == "zheng_liu")
		t=new CNzheng_liu();
	else if(npc_name == "zheng_ma")
		t=new CNzheng_ma();
	else if(npc_name == "zheng_qiu")
		t=new CNzheng_qiu();
	else if(npc_name == "zheng_sun")
		t=new CNzheng_sun();
	else if(npc_name == "zheng_tan")
		t=new CNzheng_tan();
	else if(npc_name == "zheng_wangchuyi")
		t=new CNzheng_wangchuyi();
*/	else if(npc_name == "pub_baixiaosheng")	//百晓生
		t = new CNpub_baixiaosheng();
	else if(npc_name == "pub_gongsunzhi")	//公孙指
		t = new CNpub_gongsunzhi();
	else if(npc_name == "pub_jueqingdizi")	//绝情谷弟子
		t = new CNpub_jueqingdizi();
	else if(npc_name == "pub_xuanyuanguang")	//轩辕光
		t = new CNpub_xuanyuanguang();
	else if(npc_name == "pub_mjdizi")	
		t = new CNpub_mjdizi();
	else if(npc_name == "pub_mjkill1")	
		t = new CNpub_mjkill1();
	else if(npc_name == "pub_mjkill2")	
		t = new CNpub_mjkill2();
	else if(npc_name == "pub_mjkill3")	
		t = new CNpub_mjkill3();
	else if(npc_name == "pub_mjkill4")	
		t = new CNpub_mjkill4();
	else if(npc_name == "pub_mjkill5")	
		t = new CNpub_mjkill5();
	else if(npc_name == "pub_mjkill6")	
		t = new CNpub_mjkill6();
	else if(npc_name == "pub_mjkillboss")	
		t = new CNpub_mjkillboss();
	else if(npc_name == "pub_fengshanshi")	
		t = new CNpub_fengshanshi();
	else if(npc_name == "pub_chuanlinshi")	
		t = new CNpub_chuanlinshi();
	else if(npc_name == "pub_zueijiaoshi")	
		t = new CNpub_zueijiaoshi();
	else if(npc_name == "pub_tangzishou")	
		t = new CNpub_tangzishou();
	else if(npc_name == "pub_guard")	
		t = new CNPub_guard();
	else if(npc_name == "pub_umpire")	
		t = new CNpub_umpire();
	else if(npc_name == "pub_compere")	
		t = new CNpub_compere();
//140级以后NPC
	else if(npc_name == "pub_bixuan")	
		t = new CNpub_bixuan();
	else if(npc_name == "pub_holysworder")	
		t = new CNpub_holysworder();
	else if(npc_name == "pub_beggarking")	
		t = new CNpub_beggarking();
	else if(npc_name == "pub_swordmaster")	
		t = new CNpub_swordmaster();
	else if(npc_name == "pub_sword_master")	
		t = new CNpub_sword_master();
	else if(npc_name == "pub_tiezhan")	
		t = new CNpub_tiezhan();
	else if(npc_name == "pub_ouyangbu")	
		t = new CNpub_ouyangbu();
	else if(npc_name == "pub_ouyangzhan")	
		t = new CNpub_ouyangzhan();
	else if(npc_name == "pub_likuozui")	
		t = new CNpub_likuozui();
	else if(npc_name == "pub_jinshezunzhe")	
		t = new CNpub_jinshezunzhe();
	else if(npc_name == "pub_yuanziyi")	
		t = new CNpub_yuanziyi();
	else if(npc_name == "pub_hahazi")	
		t = new CNpub_hahazi();
	else if(npc_name == "pub_zhaojunzhu")	
		t = new CNpub_zhaojunzhu();
	else if(npc_name == "pub_yinjiuyou")	
		t = new CNpub_yinjiuyou();
	else if(npc_name == "pub_xiaomimi")	
		t = new CNpub_xiaomimi();
	else if(npc_name == "pub_tuguaiguai")	
		t = new CNpub_tuguaiguai();
	else if(npc_name == "pub_dusha")	
		t = new CNpub_dusha();
//jj
	else if(npc_name == "pub_baixin")
		t = new CNpub_baixin();
	else if(npc_name == "pub_longyun")
		t = new CNpub_longyun();
	else if(npc_name == "pub_shenmike")
		t = new CNpub_shenmike();
	else if(npc_name == "pub_chezhongnv")
		t = new CNpub_chezhongnv();
	else if(npc_name == "pub_jinshisanniang")
		t = new CNpub_jinshisanniang();
	else if(npc_name == "pub_jinxilaoren")
		t = new CNpub_jinxilaoren();
	else if(npc_name == "pub_kunlunnu")
		t = new CNpub_kunlunnu();
	else if(npc_name == "pub_lanlinlaoren")
		t = new CNpub_lanlinlaoren();
	else if(npc_name == "pub_lushen")
		t = new CNpub_lushen();
	else if(npc_name == "pub_nieyinnang")
		t = new CNpub_nieyinnang();
	else if(npc_name == "pub_ruzhousen")
		t = new CNpub_ruzhousen();
	else if(npc_name == "pub_shenjiqiu")
		t = new CNpub_shenjiqiu();
	else if(npc_name == "pub_wangjinhongpu")
		t = new CNpub_wangjinhongpu();
	else if(npc_name == "pub_zaochunv")
		t = new CNpub_zaochunv();
	else if(npc_name == "pub_liguishou")
		t = new CNpub_liguishou();
	else if(npc_name == "pub_hongxian")
		t = new CNpub_hongxian();
	else if(npc_name == "pub_renzhennv")
		t = new CNpub_renzhennv();
	else if(npc_name == "pub_dinxiucai")
		t = new CNpub_dinxiucai();
	else if(npc_name == "pub_simingtoutuo")
		t = new CNpub_simingtoutuo();
	else if(npc_name == "pub_jiarenqi")
		t = new CNpub_jiarenqi();
	else if(npc_name == "pub_yicimengzi")
		t = new CNpub_yicimengzi();
	else if(npc_name == "pub_weiyangyu")
		t = new CNpub_weiyangyu();
	else if(npc_name == "pub_sixinzhe")
		t = new CNpub_sixinzhe();
	else if(npc_name == "pub_lisheng")
		t = new CNpub_lisheng();
	else if(npc_name == "pub_xiuzhoucike")
		t = new CNpub_xiuzhoucike();
	else if(npc_name == "pub_zhangxunqi")
		t = new CNpub_zhangxunqi();
	else if(npc_name == "pub_panjianke")
		t = new CNpub_panjianke();
	else if(npc_name == "pub_hongzhoushushen")
		t = new CNpub_hongzhoushushen();
	else if(npc_name == "pub_yixia")
		t = new CNpub_yixia();
	else if(npc_name == "pub_qinjinzhe")
		t = new CNpub_qinjinzhe();
	else if(npc_name == "pub_zhangzhongding")
		t = new CNpub_zhangzhongding();
	else if(npc_name == "pub_zichuandaoshi")
		t = new CNpub_zichuandaoshi();
	else if(npc_name == "pub_xiafuren")
		t = new CNpub_xiafuren();
	else if(npc_name == "pub_xiexunfu")
		t = new CNpub_xiexunfu();
	else if(npc_name == "pub_jiaojindaoren")
		t = new CNpub_jiaojindaoren();
	else if(npc_name == "pub_laocunzhang")
		t = new CNpub_laocunzhang();
	else if(npc_name == "pub_jieshouyuan")
		t = new CNpub_jieshouyuan();
	else if(npc_name == "pub_baoguanyuan")
		t = new CNpub_baoguanyuan();
	else if(npc_name == "pub_xuemingfeng")
		t = new CNpub_xuemingfeng();
	else if(npc_name == "pub_buchanshi")
		t = new CNpub_buchanshi();	
	else if(npc_name == "pub_binv")
		t = new CNpub_binv();	
	else if(npc_name == "pub_chenlingsu")	
		t = new CNpub_chenlingsu();
	else if(npc_name == "pub_baihuanxi")
		t = new CNpub_baihuanxi();
	else if(npc_name == "pub_maochenglong")
		t = new CNpub_maochenglong();
	else if(npc_name == "pub_mao_huyuan")
		t = new CNpub_mao_huyuan();
	else if(npc_name == "pub_mao_huyuan2")
		t = new CNpub_mao_huyuan2();
	else if(npc_name == "pub_mao_huyuan3")
		t = new CNpub_mao_huyuan3();
	else if(npc_name == "pub_maochenglongzi")
		t = new CNpub_maochenglongzi();
	else if(npc_name == "pub_zaochongzha")
		t = new CNpub_zaochongzha();
	else if(npc_name == "pub_sunchengxian")
		t = new CNpub_sunchengxian();
	else if(npc_name == "pub_yuguangqi")
		t = new CNpub_yuguangqi();
	else if(npc_name == "pub_xyqinbing")
		t = new CNpub_xyqinbing();
	else if(npc_name == "pub_lijin")
		t = new CNpub_lijin();
	else if(npc_name == "pub_hongfunv")
		t = new CNpub_hongfunv();
	else if(npc_name == "pub_qiuranke")
		t = new CNpub_qiuranke();
	return t;
}


