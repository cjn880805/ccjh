#include "stdafx.h"
#include "../server/Room.h"
#include "../std/Money.h"
#include "../std/Vendor.h"
#include "../std/BankOwner.h"
#include "../std/Corpse.h"
#include "../server/User.h"
#include "../std/FightRoom.h"
#include "../server/Channel.h"
#include "../std/zushi.h"
//-----------------------------------------------------------------
//
//	门派NPC
//	author:	Lanwood		
//	date:	2001-01-05
//
//-----------------------------------------------------------------

//姑母
#include "../npc/class/gumu/gumu_liqingzhao.h"
#include "../npc/class/gumu/gumu_longnv.h"
#include "../npc/class/gumu/gumu_yangguo.h"
#include "../npc/class/gumu/gumu_hong.h"
#include "../npc/class/gumu/gumu_sun.h"

//quanzhen
#include "../npc/class/quanzhen/quanzhen.h"
#include "../npc/class/quanzhen/cheng.h"
#include "../npc/class/quanzhen/cui.h"
#include "../npc/class/quanzhen/daotong.h"
#include "../npc/class/quanzhen/daotong1.h"
#include "../npc/class/quanzhen/fang.h"
#include "../npc/class/quanzhen/hao.h"
#include "../npc/class/quanzhen/ji.h"
#include "../npc/class/quanzhen/li.h"
#include "../npc/class/quanzhen/liu.h"
#include "../npc/class/quanzhen/ma.h"
#include "../npc/class/quanzhen/pi.h"
#include "../npc/class/quanzhen/qi.h"
#include "../npc/class/quanzhen/qiu.h"
#include "../npc/class/quanzhen/shen.h"
#include "../npc/class/quanzhen/sun.h"
#include "../npc/class/quanzhen/tan.h"
#include "../npc/class/quanzhen/wang.h"
#include "../npc/class/quanzhen/wangchuyi.h"
#include "../npc/class/quanzhen/wangzhi.h"
#include "../npc/class/quanzhen/wanyankang.h"
#include "../npc/class/quanzhen/yelvqi.h"
#include "../npc/class/quanzhen/yin.h"
#include "../npc/class/quanzhen/youfang.h"
#include "../npc/class/quanzhen/zhang.h"
#include "../npc/class/quanzhen/zhangjing.h"
#include "../npc/class/quanzhen/zhangli.h"
#include "../npc/class/quanzhen/zhangyao.h"
#include "../npc/class/quanzhen/zhangyuan.h"
#include "../npc/class/quanzhen/zhao.h"
#include "../npc/class/quanzhen/zhike.h"
#include "../npc/class/quanzhen/zhou.h"

//xiaoyao
#include "../npc/class/xiaoyao/xiaoyao_fengas.h"
#include "../npc/class/xiaoyao/xiaoyao_goudu.h"
#include "../npc/class/xiaoyao/xiaoyao_kanggl.h"
#include "../npc/class/xiaoyao/xiaoyao_mengmianr.h"
#include "../npc/class/xiaoyao/xiaoyao_suxingh.h"
#include "../npc/class/xiaoyao/xiaoyao_xiaoyaozi.h"
#include "../npc/class/xiaoyao/xiaoyao_xuemuh.h"

//btshan
#include "../npc/class/btshan/li.h"
#include "../npc/class/btshan/ouyangfeng.h"
#include "../npc/class/btshan/ouyangke.h"
#include "../npc/class/btshan/tongzi.h"

//dali
#include "../npc/class/dali/weishi.h"
#include "../npc/class/dali/batianshi.h"
#include "../npc/class/dali/daobaifeng.h"
#include "../npc/class/dali/duanzc.h"
#include "../npc/class/dali/duanwuwei.h"
#include "../npc/class/dali/fanye.h"
#include "../npc/class/dali/fusigui.h"
#include "../npc/class/dali/gaoshengtai.h"
#include "../npc/class/dali/guducheng.h"
#include "../npc/class/dali/huahegen.h"
#include "../npc/class/dali/jiading.h"
#include "../npc/class/dali/zhudanchen.h"
#include "../npc/class/dali/zhuwanli.h"

//emei
#include "../npc/class/emei/tobebonze.h"
#include "../npc/class/emei/bei.h"
#include "../npc/class/emei/dao.h"
#include "../npc/class/emei/daoming.h"
#include "../npc/class/emei/fang.h"
#include "../npc/class/emei/feng.h"
#include "../npc/class/emei/he.h"
#include "../npc/class/emei/hui.h"
#include "../npc/class/emei/jia.h"
#include "../npc/class/emei/kong.h"
#include "../npc/class/emei/li.h"
#include "../npc/class/emei/ling.h"
#include "../npc/class/emei/miejue.h"
#include "../npc/class/emei/su.h"
#include "../npc/class/emei/wenfang.h"
#include "../npc/class/emei/wenhui.h"
#include "../npc/class/emei/wenqing.h"
#include "../npc/class/emei/wenyin.h"
#include "../npc/class/emei/xian.h"
#include "../npc/class/emei/xin.h"
#include "../npc/class/emei/xu.h"
#include "../npc/class/emei/xuan.h"
#include "../npc/class/emei/zhao.h"
#include "../npc/class/emei/zhen.h"
#include "../npc/class/emei/zhou.h"

//gaibang
#include "../npc/class/gaibang/gaibang.h"
#include "../npc/class/gaibang/he_bj.h"
#include "../npc/class/gaibang/hong.h"
#include "../npc/class/gaibang/jian.h"
#include "../npc/class/gaibang/jiang_sy.h"
#include "../npc/class/gaibang/kongkong.h"
#include "../npc/class/gaibang/kuai_huosan.h"
#include "../npc/class/gaibang/li_futou.h"
#include "../npc/class/gaibang/li_sh.h"
#include "../npc/class/gaibang/liang.h"
#include "../npc/class/gaibang/lu.h"
#include "../npc/class/gaibang/mo_bu.h"
#include "../npc/class/gaibang/peng.h"
#include "../npc/class/gaibang/qiu_wanjia.h"
#include "../npc/class/gaibang/quan_gq.h"
#include "../npc/class/gaibang/yu_hx.h"
#include "../npc/class/gaibang/zhao_gouer.h"
#include "../npc/class/gaibang/zuo_qu.h"

//huashan
#include "../npc/class/huashan/ai_laozhe.h"
#include "../npc/class/huashan/cheng_buyou.h"
#include "../npc/class/huashan/cong_buqi.h"
#include "../npc/class/huashan/feng.h"
#include "../npc/class/huashan/feng_buping.h"
#include "../npc/class/huashan/gao_laozhe.h"
#include "../npc/class/huashan/yue_buqun.h"
#include "../npc/class/huashan/yue_wife.h"

//lingjiu
#include "../npc/class/lingjiu/meijian.h"
#include "../npc/class/lingjiu/tonglao.h"
#include "../npc/class/lingjiu/xuzhu.h"
#include "../npc/class/lingjiu/lanjian.h"
#include "../npc/class/lingjiu/zhujian.h"
#include "../npc/class/lingjiu/jujian.h"
#include "../npc/class/lingjiu/shi.h"
#include "../npc/class/lingjiu/liu.h"
#include "../npc/class/lingjiu/fu.h"
#include "../npc/class/lingjiu/feng.h"
#include "../npc/class/lingjiu/zhou.h"
#include "../npc/class/lingjiu/cheng.h"
#include "../npc/class/lingjiu/yu.h"
#include "../npc/class/lingjiu/qiu.h"
#include "../npc/class/lingjiu/lu.h"

//mingjiao
#include "../npc/class/mingjiao/fanyao.h"
#include "../npc/class/mingjiao/weiyixiao.h"
#include "../npc/class/mingjiao/xiaozhao.h"
#include "../npc/class/mingjiao/xiexun.h"
#include "../npc/class/mingjiao/yangxiao.h"
#include "../npc/class/mingjiao/yintianzheng.h"
#include "../npc/class/mingjiao/zhangwuji.h"
#include "../npc/class/mingjiao/diana.h"
#include "../npc/class/mingjiao/yangdingtian.h"
//补充d
#include "../npc/class/mingjiao/mingjiao.h"
#include "../npc/class/mingjiao/menzhu.h"
#include "../npc/class/mingjiao/tangzhu.h"
#include "../npc/class/mingjiao/tanzhu.h"
#include "../npc/class/mingjiao/zhangqishi.h"
//四门门主
#include "../npc/class/mingjiao/tuoba.h"
#include "../npc/class/mingjiao/tianmen.h"
#include "../npc/class/mingjiao/dimen.h"
#include "../npc/class/mingjiao/leimen.h"

#include "../npc/class/mingjiao/litianyuan.h"
#include "../npc/class/mingjiao/yinyewang.h"
#include "../npc/class/mingjiao/baiguishou.h"
#include "../npc/class/mingjiao/changjinpeng.h"
#include "../npc/class/mingjiao/chengchaofeng.h"
#include "../npc/class/mingjiao/fenggongying.h"
#include "../npc/class/mingjiao/gaoshanwang.h"
#include "../npc/class/mingjiao/tangyang.h"
#include "../npc/class/mingjiao/wensong.h"
#include "../npc/class/mingjiao/xinran.h"
#include "../npc/class/mingjiao/yanyuan.h"
#include "../npc/class/mingjiao/zhuangzheng.h"
#include "../npc/class/mingjiao/jieyinshi.h"
#include "../npc/class/mingjiao/yinwufu.h"
#include "../npc/class/mingjiao/yinwulu.h"
#include "../npc/class/mingjiao/yinwushou.h"
#include "../npc/class/mingjiao/hu.h"
//明教五散人
#include "../npc/class/mingjiao/lengqian.h"
#include "../npc/class/mingjiao/pengyingyu.h"
#include "../npc/class/mingjiao/shuobude.h"
#include "../npc/class/mingjiao/zhangzhong.h"
#include "../npc/class/mingjiao/zhoudian.h"

//少林
#include "../npc/class/shaolin/cheng.h"
#include "../npc/class/shaolin/cheng_zhi2.h"
#include "../npc/class/shaolin/cheng_he.h"
#include "../npc/class/shaolin/cheng_ji.h"
#include "../npc/class/shaolin/cheng_jian.h"
#include "../npc/class/shaolin/cheng_jing.h"
#include "../npc/class/shaolin/cheng_ling.h"
#include "../npc/class/shaolin/cheng_mie.h"
#include "../npc/class/shaolin/cheng_ming.h"
#include "../npc/class/shaolin/cheng_shang.h"
#include "../npc/class/shaolin/cheng_shi.h"
#include "../npc/class/shaolin/cheng_si.h"
#include "../npc/class/shaolin/cheng_xin.h"
#include "../npc/class/shaolin/cheng_xin2.h"
#include "../npc/class/shaolin/cheng_xing.h"
#include "../npc/class/shaolin/cheng_yi.h"
#include "../npc/class/shaolin/cheng_yu.h"
#include "../npc/class/shaolin/cheng_zhi.h"
#include "../npc/class/shaolin/cheng_guan.h"

#include "../npc/class/shaolin/dao.h"
#include "../npc/class/shaolin/dao_chen.h"
#include "../npc/class/shaolin/dao_cheng.h"
#include "../npc/class/shaolin/dao_guo.h"
#include "../npc/class/shaolin/dao_jue.h"
#include "../npc/class/shaolin/dao_pin.h"
#include "../npc/class/shaolin/dao_xiang.h"
#include "../npc/class/shaolin/dao_xiang2.h"
#include "../npc/class/shaolin/dao_yi.h"
#include "../npc/class/shaolin/dao_zheng.h"

#include "../npc/class/shaolin/hui.h"
#include "../npc/class/shaolin/hui_he.h"
#include "../npc/class/shaolin/hui_jie.h"
#include "../npc/class/shaolin/hui_kong.h"
#include "../npc/class/shaolin/hui_ming.h"
#include "../npc/class/shaolin/hui_ru.h"
#include "../npc/class/shaolin/hui_se.h"
#include "../npc/class/shaolin/hui_xiu.h"
#include "../npc/class/shaolin/hui_xu.h"
#include "../npc/class/shaolin/hui_zhen.h"

#include "../npc/class/shaolin/qing.h"
#include "../npc/class/shaolin/qing_fa.h"
#include "../npc/class/shaolin/qing_guan.h"
#include "../npc/class/shaolin/qing_le.h"
#include "../npc/class/shaolin/qing_shan.h"
#include "../npc/class/shaolin/qing_wei.h"
#include "../npc/class/shaolin/qing_wen.h"
#include "../npc/class/shaolin/qing_wu.h"
#include "../npc/class/shaolin/qing_xiao.h"
#include "../npc/class/shaolin/qing_yuan.h"

#include "../npc/class/shaolin/wuying.h"

#include "../npc/class/shaolin/xuan_bei.h"
#include "../npc/class/shaolin/xuan_ci.h"
#include "../npc/class/shaolin/xuan_ku.h"
#include "../npc/class/shaolin/xuan_nan.h"
#include "../npc/class/shaolin/xuan_tong.h"

#include "../npc/class/shaolin/xu_tong.h"
#include "../npc/class/shaolin/xu_ming.h"

#include "../npc/class/shaolin/du.h"
#include "../npc/class/shaolin/du_e.h"
#include "../npc/class/shaolin/du_jie.h"
#include "../npc/class/shaolin/du_nan.h"

#include "../npc/class/shaolin/da_mo.h"
#include "../npc/class/shaolin/tuoboseng.h"
#include "../npc/class/shaolin/xingzhe.h"

//taohua
#include "../npc/class/taohua/feng.h"
#include "../npc/class/taohua/lu.h"
#include "../npc/class/taohua/qu.h"
#include "../npc/class/taohua/rong.h"
#include "../npc/class/taohua/huang.h"

//神龙
#include "../npc/class/shenlong/shenlong.h"
#include "../npc/class/shenlong/wugeng.h"
#include "../npc/class/shenlong/lu.h"
#include "../npc/class/shenlong/su.h"
#include "../npc/class/shenlong/hong.h"
#include "../npc/class/shenlong/pang.h"
#include "../npc/class/shenlong/shou.h"
#include "../npc/class/shenlong/xu.h"
#include "../npc/class/shenlong/yin.h"
#include "../npc/class/shenlong/zhang.h"
//武当
#include "../npc/class/wudang/bagua.h"
#include "../npc/class/wudang/daotong.h"
#include "../npc/class/wudang/famu.h"
#include "../npc/class/wudang/guxu.h"
#include "../npc/class/wudang/mingyue.h"
#include "../npc/class/wudang/mo.h"
#include "../npc/class/wudang/qingfeng.h"
#include "../npc/class/wudang/qingxu.h"
#include "../npc/class/wudang/shan.h"
#include "../npc/class/wudang/shouyuan.h"
#include "../npc/class/wudang/song.h"
#include "../npc/class/wudang/wuxing.h"
#include "../npc/class/wudang/xi.h"
#include "../npc/class/wudang/xiaosong.h"
#include "../npc/class/wudang/yin.h"
#include "../npc/class/wudang/yu.h"
#include "../npc/class/wudang/yan.h"
#include "../npc/class/wudang/zhang.h"
#include "../npc/class/wudang/zhike.h"
#include "../npc/class/wudang/zhixiang.h"
//侠客岛
#include "../npc/class/xiake/xiake.h"
#include "../npc/class/xiake/mu.h"
#include "../npc/class/xiake/long.h"
//#include "../npc/class/xiake/yanruoshui.h"
//星宿
#include "../npc/class/xingxiu/zhaixing.h"
#include "../npc/class/xingxiu/chuchen.h"
#include "../npc/class/xingxiu/ding.h"
#include "../npc/class/xingxiu/azi.h"
#include "../npc/class/xingxiu/tianlang.h"
#include "../npc/class/xingxiu/shihou.h"

//雪山
#include "../npc/class/xueshan/baoxiang.h"
#include "../npc/class/xueshan/daerba.h"
#include "../npc/class/xueshan/fawang.h"
#include "../npc/class/xueshan/gelunbu.h"
#include "../npc/class/xueshan/guoshi.h"
#include "../npc/class/xueshan/jiamu.h"
#include "../npc/class/xueshan/jiumozhi.h"
#include "../npc/class/xueshan/lazhang.h"
#include "../npc/class/xueshan/lingzhi.h"
#include "../npc/class/xueshan/samu.h"
#include "../npc/class/xueshan/shanyong.h"
#include "../npc/class/xueshan/shengdi.h"
#include "../npc/class/xueshan/xuedao.h"
//云龙
#include "../npc/class/yunlong/xuanzhen.h"
#include "../npc/class/yunlong/ma.h"
#include "../npc/class/yunlong/chen.h"

CNpc * LoadNPC_class(string npc_name)
{
	CNpc * t = NULL;

	if(npc_name == "gumu_longnv")
		t = new CNGuMu_longnv();
	else if(npc_name == "gumu_liqingzhao")
		t = new CNGuMu_liqingzhao();
	else if(npc_name == "gumu_yangguo")
		t = new CNGuMu_yangguo();
	else if(npc_name == "gumu_hong")
		t = new CNGuMu_hong();
	else if(npc_name == "gumu_sun")
		t = new CNGuMu_sun();

	//xiaoyao
	else if(npc_name == "xiaoyao_fengas")
		t = new CNxiaoyao_fengas();
	else if(npc_name == "xiaoyao_goudu")
		t = new CNxiaoyao_goudu();
	else if(npc_name == "xiaoyao_kanggl")
		t = new CNxiaoyao_kanggl();
	else if(npc_name == "xiaoyao_mengmianr")
		t = new CNxiaoyao_mengmianr();
	else if(npc_name == "xiaoyao_suxingh")
		t = new CNxiaoyao_suxingh();
	else if(npc_name == "xiaoyao_xiaoyaozi")
		t = new CNxiaoyao_xiaoyaozi();
	else if(npc_name == "xiaoyao_xuemuh")
		t = new CNxiaoyao_xuemuh();

	//quanzhen
	else if(npc_name == "quanzhen_cheng")
		t = new CNquanzhen_cheng();
	else if(npc_name == "quanzhen_cui")
		t = new CNquanzhen_cui();
	else if(npc_name == "quanzhen_daotong")
		t = new CNquanzhen_daotong();
	else if(npc_name == "quanzhen_daotong1")
		t = new CNquanzhen_daotong1();
	else if(npc_name == "quanzhen_fang")
		t = new CNquanzhen_fang();
	else if(npc_name == "quanzhen_hao")
		t = new CNquanzhen_hao();
	else if(npc_name == "quanzhen_ji")
		t = new CNquanzhen_ji();
	else if(npc_name == "quanzhen_li")
		t = new CNquanzhen_li();
	else if(npc_name == "quanzhen_liu")
		t = new CNquanzhen_liu();
	else if(npc_name == "quanzhen_ma")
		t = new CNquanzhen_ma();
 	else if(npc_name == "quanzhen_pi")
		t = new CNquanzhen_pi();
	else if(npc_name == "quanzhen_qi")
		t = new CNquanzhen_qi();
	else if(npc_name == "quanzhen_qiu")
		t = new CNquanzhen_qiu();
	else if(npc_name == "quanzhen_shen")
		t = new CNquanzhen_shen();
	else if(npc_name == "quanzhen_sun")
		t = new CNquanzhen_sun();
	else if(npc_name == "quanzhen_tan")
		t = new CNquanzhen_tan();
	else if(npc_name == "quanzhen_wang")
		t = new CNquanzhen_wang();
	else if(npc_name == "quanzhen_wangchuyi")
		t = new CNquanzhen_wangchuyi();
	else if(npc_name == "quanzhen_wangzhi")
		t = new CNquanzhen_wangzhi();
	else if(npc_name == "quanzhen_wanyankang")
		t = new CNquanzhen_wanyankang();
	else if(npc_name == "quanzhen_yelvqi")
		t = new CNquanzhen_yelvqi();
 	else if(npc_name == "quanzhen_yin")
		t = new CNquanzhen_yin();
	else if(npc_name == "quanzhen_youfang")
		t = new CNquanzhen_youfang();
	else if(npc_name == "quanzhen_zhang")
		t = new CNquanzhen_zhang();
	else if(npc_name == "quanzhen_zhangjing")
		t = new CNquanzhen_zhangjing();
 	else if(npc_name == "quanzhen_zhangli")
		t = new CNquanzhen_zhangli();
	else if(npc_name == "quanzhen_zhangyao")
		t = new CNquanzhen_zhangyao();
	else if(npc_name == "quanzhen_zhangyuan")
		t = new CNquanzhen_zhangyuan();
	else if(npc_name == "quanzhen_zhao")
		t = new CNquanzhen_zhao();
	else if(npc_name == "quanzhen_zhike")
		t = new CNquanzhen_zhike();
	else if(npc_name == "quanzhen_zhou")
		t = new CNquanzhen_zhou();

	//btshan
	else if(npc_name == "btshan_li")
		t = new CNbtshan_li();
	else if(npc_name == "btshan_ouyangfeng")
		t = new CNbtshan_ouyangfeng();
	else if(npc_name == "btshan_ouyangke")
		t = new CNbtshan_ouyangke();
	else if(npc_name == "btshan_tongzi")
		t = new CNbtshan_tongzi();

	//dali
	else if(npc_name == "dali_batianshi")
		t = new CNdali_batianshi();
	else if(npc_name == "dali_daobaifeng")
		t = new CNdali_daobaifeng();
	else if(npc_name == "dali_duanzc")
		t = new CNdali_duanzc();
	else if(npc_name == "dali_duanwuwei")
		t = new CNdali_duanwuwei();
	else if(npc_name == "dali_fanye")
		t = new CNdali_fanye();
	else if(npc_name == "dali_fusigui")
		t = new CNdali_fusigui();
	else if(npc_name == "dali_gaoshengtai")
		t = new CNdali_gaoshengtai();
	else if(npc_name == "dali_guducheng")
		t = new CNdali_guducheng();
	else if(npc_name == "dali_huahegen")
		t = new CNdali_huahegen();
	else if(npc_name == "dali_jiading")
		t = new CNdali_jiading();
	else if(npc_name == "dali_zhudanchen")
		t = new CNdali_zhudanchen();
	else if(npc_name == "dali_zhuwanli")
		t = new CNdali_zhuwanli();

	//emei
	else if(npc_name == "emei_bei")
		t = new CNemei_bei();
	else if(npc_name == "emei_dao")
		t = new CNemei_dao();
	else if(npc_name == "emei_daoming")
		t = new CNemei_daoming();
	else if(npc_name == "emei_fang")
		t = new CNemei_fang();
	else if(npc_name == "emei_feng")
		t = new CNemei_feng();
	else if(npc_name == "emei_he")
		t = new CNemei_he();
	else if(npc_name == "emei_hui")
		t = new CNemei_hui();
	else if(npc_name == "emei_jia")
		t = new CNemei_jia();
	else if(npc_name == "emei_kong")
		t = new CNemei_kong();
	else if(npc_name == "emei_li")
		t = new CNemei_li();
	else if(npc_name == "emei_ling")
		t = new CNemei_ling();
	else if(npc_name == "emei_miejue")
		t = new CNemei_miejue();
	else if(npc_name == "emei_su")
		t = new CNemei_su();
	else if(npc_name == "emei_wenfang")
		t = new CNemei_wenfang();
	else if(npc_name == "emei_wenhui")
		t = new CNemei_wenhui();
	else if(npc_name == "emei_wenqing")
		t = new CNemei_wenqing();
	else if(npc_name == "emei_wenyin")
		t = new CNemei_wenyin();
	else if(npc_name == "emei_xian")
		t = new CNemei_xian();
	else if(npc_name == "emei_xin")
		t = new CNemei_xin();
	else if(npc_name == "emei_xu")
		t = new CNemei_xu();
	else if(npc_name == "emei_xuan")
		t = new CNemei_xuan();
	else if(npc_name == "emei_zhao")
		t = new CNemei_zhao();
	else if(npc_name == "emei_zhen")
		t = new CNemei_zhen();
	else if(npc_name == "emei_zhou")
		t = new CNemei_zhou();
	
	//gaibang
	else if(npc_name == "gaibang_he_bj")
		t = new CNgaibang_he_bj();
	else if(npc_name == "gaibang_hong")
		t = new CNgaibang_hong();
	else if(npc_name == "gaibang_jian")
		t = new CNgaibang_jian();
	else if(npc_name == "gaibang_jiang_sy")
		t = new CNgaibang_jiang_sy();
	else if(npc_name == "gaibang_kongkong")
		t = new CNgaibang_kongkong();
	else if(npc_name == "gaibang_kuai_huosan")
		t = new CNgaibang_kuai_huosan();
	else if(npc_name == "gaibang_li_futou")
		t = new CNgaibang_li_futou();
	else if(npc_name == "gaibang_li_sh")
		t = new CNgaibang_li_sh();
	else if(npc_name == "gaibang_liang")
		t = new CNgaibang_liang();
	else if(npc_name == "gaibang_lu")
		t = new CNgaibang_lu();
	else if(npc_name == "gaibang_mo_bu")
		t = new CNgaibang_mo_bu();
	else if(npc_name == "gaibang_peng")
		t = new CNgaibang_peng();
	else if(npc_name == "gaibang_qiu_wanjia")
		t = new CNgaibang_qiu_wanjia();
	else if(npc_name == "gaibang_quan_gq")
		t = new CNgaibang_quan_gq();
	else if(npc_name == "gaibang_yu_hx")
		t = new CNgaibang_yu_hx();
	else if(npc_name == "gaibang_zhao_gouer")
		t = new CNgaibang_zhao_gouer();
	else if(npc_name == "gaibang_zuo_qu")
		t = new CNgaibang_zuo_qu();

	//huashan
	else if(npc_name == "huashan_ai_laozhe")
		t = new CNhuashan_ai_laozhe();
	else if(npc_name == "huashan_cheng_buyou")
		t = new CNhuashan_cheng_buyou();
	else if(npc_name == "huashan_cong_buqi")
		t = new CNhuashan_cong_buqi();
	else if(npc_name == "huashan_feng")
		t = new CNhuashan_feng();
	else if(npc_name == "huashan_feng_buping")
		t = new CNhuashan_feng_buping();
	else if(npc_name == "huashan_gao_laozhe")
		t = new CNhuashan_gao_laozhe();
	else if(npc_name == "huashan_yue_buqun")
		t = new CNhuashan_yue_buqun();
	else if(npc_name == "huashan_yue_wife")
		t = new CNhuashan_yue_wife();

	//lingjiu
	else if(npc_name == "lingjiu_meijian")
		t = new CNlingjiu_meijian();
	else if(npc_name == "lingjiu_tonglao")
		t = new CNlingjiu_tonglao();
	else if(npc_name == "lingjiu_xuzhu")
		t = new CNlingjiu_xuzhu();
	else if(npc_name == "lingjiu_lanjian")
		t = new CNlingjiu_lanjian();
	else if(npc_name == "lingjiu_zhujian")
		t = new CNlingjiu_zhujian();
	else if(npc_name == "lingjiu_jujian")
		t = new CNlingjiu_jujian();
	else if(npc_name == "lingjiu_lu")
		t = new CNlingjiu_lu();
	else if(npc_name == "lingjiu_qiu")
		t = new CNlingjiu_qiu();
	else if(npc_name == "lingjiu_yu")
		t = new CNlingjiu_yu();
	else if(npc_name == "lingjiu_cheng")
		t = new CNlingjiu_cheng();
	else if(npc_name == "lingjiu_zhou")
		t = new CNlingjiu_zhou();
	else if(npc_name == "lingjiu_feng")
		t = new CNlingjiu_feng();
	else if(npc_name == "lingjiu_fu")
		t = new CNlingjiu_fu();
	else if(npc_name == "lingjiu_liu")
		t = new CNlingjiu_liu();
	else if(npc_name == "lingjiu_shi")
		t = new CNlingjiu_shi();

	//mingjiao
	if(npc_name == "mingjiao_fanyao")
		t = new CNmingjiao_fanyao();
	else if(npc_name == "mingjiao_weiyixiao")
		t = new CNmingjiao_weiyixiao();
	else if(npc_name == "mingjiao_xiaozhao")
		t = new CNmingjiao_xiaozhao();
	else if(npc_name == "mingjiao_xiexun")
		t = new CNmingjiao_xiexun();
	else if(npc_name == "mingjiao_yangxiao")
		t = new CNmingjiao_yangxiao();
	else if(npc_name == "mingjiao_yintianzheng")
		t = new CNmingjiao_yintianzheng();
	else if(npc_name == "mingjiao_zhangwuji")
		t = new CNmingjiao_zhangwuji();

	else if(npc_name == "mingjiao_tuoba")
		t = new CNmingjiao_tuoba();
	else if(npc_name == "mingjiao_litianyuan")
		t = new CNmingjiao_litianyuan();
	else if(npc_name == "mingjiao_yinyewang")
		t = new CNmingjiao_yinyewang();
	else if(npc_name == "mingjiao_baiguishou")
		t = new CNmingjiao_baiguishou();
	else if(npc_name == "mingjiao_changjinpeng")
		t = new CNmingjiao_changjinpeng();
	else if(npc_name == "mingjiao_chengchaofeng")
		t = new CNmingjiao_chengchaofeng();
	else if(npc_name == "mingjiao_fenggongying")
		t = new CNmingjiao_fenggongying();
	else if(npc_name == "mingjiao_gaoshanwang")
		t = new CNmingjiao_gaoshanwang();
	else if(npc_name == "mingjiao_tangyang")
		t = new CNmingjiao_tangyang();
	else if(npc_name == "mingjiao_wensong")
		t = new CNmingjiao_wensong();
	else if(npc_name == "mingjiao_xinran")
		t = new CNmingjiao_xinran();
	else if(npc_name == "mingjiao_yanyuan")
		t = new CNmingjiao_yanyuan();
	else if(npc_name == "mingjiao_zhuangzheng")
		t = new CNmingjiao_zhuangzheng();
	else if(npc_name == "mingjiao_jieyinshi")
		t = new CNmingjiao_jieyinshi();
	else if(npc_name == "mingjiao_yinwufu")
		t = new CNmingjiao_yinwufu();
	else if(npc_name == "mingjiao_yinwulu")
		t = new CNmingjiao_yinwulu();
	else if(npc_name == "mingjiao_yinwushou")
		t = new CNmingjiao_yinwushou();
	else if(npc_name == "mingjiao_hu")
		t = new CNmingjiao_hu();

	else if(npc_name == "mingjiao_lengqian")
		t = new CNmingjiao_lengqian();
	else if(npc_name == "mingjiao_pengyingyu")
		t = new CNmingjiao_pengyingyu();
	else if(npc_name == "mingjiao_shuobude")
		t = new CNmingjiao_shuobude();
	else if(npc_name == "mingjiao_zhangzhong")
		t = new CNmingjiao_zhangzhong();
	else if(npc_name == "mingjiao_zhoudian")
		t = new CNmingjiao_zhoudian();
	else if(npc_name == "mingjiao_diana")
		t = new CNmingjiao_diana();
	else if(npc_name == "mingjiao_dimen")
		t = new CNmingjiao_dimen();
	else if(npc_name == "mingjiao_tianmen")
		t = new CNmingjiao_tianmen();
	else if(npc_name == "mingjiao_leimen")
		t = new CNmingjiao_leimen();
	else if(npc_name == "mingjiao_yangdingtian")
		t = new CNmingjiao_yangdingtian();
	
	//shaolin
	else if(npc_name == "shaolin_cheng_zhi2")
		t = new CNshaolin_cheng_zhi2();
	else if(npc_name == "shaolin_cheng_he")
		t = new CNshaolin_cheng_he();
	else if(npc_name == "shaolin_cheng_ji")
		t = new CNshaolin_cheng_ji();
	else if(npc_name == "shaolin_cheng_jian")
		t = new CNshaolin_cheng_jian();
	else if(npc_name == "shaolin_cheng_jing")
		t = new CNshaolin_cheng_jing();
	else if(npc_name == "shaolin_cheng_ling")
		t = new CNshaolin_cheng_ling();
	else if(npc_name == "shaolin_cheng_mie")
		t = new CNshaolin_cheng_mie();
	else if(npc_name == "shaolin_cheng_ming")
		t = new CNshaolin_cheng_ming();
	else if(npc_name == "shaolin_cheng_shang")
		t = new CNshaolin_cheng_shang();
	else if(npc_name == "shaolin_cheng_shi")
		t = new CNshaolin_cheng_shi();
	else if(npc_name == "shaolin_cheng_si")
		t = new CNshaolin_cheng_si();
	else if(npc_name == "shaolin_cheng_xin")
		t = new CNshaolin_cheng_xin();
	else if(npc_name == "shaolin_cheng_xin2")
		t = new CNshaolin_cheng_xin2();
	else if(npc_name == "shaolin_cheng_xing")
		t = new CNshaolin_cheng_xing();
	else if(npc_name == "shaolin_cheng_yi")
		t = new CNshaolin_cheng_yi();
	else if(npc_name == "shaolin_cheng_yu")
		t = new CNshaolin_cheng_yu();
	else if(npc_name == "shaolin_cheng_zhi")
		t = new CNshaolin_cheng_zhi();
	else if(npc_name == "shaolin_cheng_guan")
		t = new CNshaolin_cheng_guan();

	else if(npc_name == "shaolin_dao_chen")
		t = new CNshaolin_dao_chen();
	else if(npc_name == "shaolin_dao_cheng")
		t = new CNshaolin_dao_cheng();
	else if(npc_name == "shaolin_dao_guo")
		t = new CNshaolin_dao_guo();
	else if(npc_name == "shaolin_dao_jue")
		t = new CNshaolin_dao_jue();
	else if(npc_name == "shaolin_dao_pin")
		t = new CNshaolin_dao_pin();
	else if(npc_name == "shaolin_dao_xiang")
		t = new CNshaolin_dao_xiang();
	else if(npc_name == "shaolin_dao_xiang2")
		t = new CNshaolin_dao_xiang2();
	else if(npc_name == "shaolin_dao_yi")
		t = new CNshaolin_dao_yi();
	else if(npc_name == "shaolin_dao_zheng")
		t = new CNshaolin_dao_zheng();

	else if(npc_name == "shaolin_hui_he")
		t = new CNshaolin_hui_he();
	else if(npc_name == "shaolin_hui_jie")
		t = new CNshaolin_hui_jie();
	else if(npc_name == "shaolin_hui_kong")
		t = new CNshaolin_hui_kong();
	else if(npc_name == "shaolin_hui_ming")
		t = new CNshaolin_hui_ming();
	else if(npc_name == "shaolin_hui_ru")
		t = new CNshaolin_hui_ru();
	else if(npc_name == "shaolin_hui_se")
		t = new CNshaolin_hui_se();
	else if(npc_name == "shaolin_hui_xiu")
		t = new CNshaolin_hui_xiu();
	else if(npc_name == "shaolin_hui_xu")
		t = new CNshaolin_hui_xu();
	else if(npc_name == "shaolin_hui_zhen")
		t = new CNshaolin_hui_zhen();

	else if(npc_name == "shaolin_qing_fa")
		t = new CNshaolin_qing_fa();
	else if(npc_name == "shaolin_qing_guan")
		t = new CNshaolin_qing_guan();
	else if(npc_name == "shaolin_qing_le")
		t = new CNshaolin_qing_le();
	else if(npc_name == "shaolin_qing_shan")
		t = new CNshaolin_qing_shan();
	else if(npc_name == "shaolin_qing_wei")
		t = new CNshaolin_qing_wei();
	else if(npc_name == "shaolin_qing_wen")
		t = new CNshaolin_qing_wen();
	else if(npc_name == "shaolin_qing_wu")
		t = new CNshaolin_qing_wu();
	else if(npc_name == "shaolin_qing_xiao")
		t = new CNshaolin_qing_xiao();
	else if(npc_name == "shaolin_qing_yuan")
		t = new CNshaolin_qing_yuan();

	else if(npc_name == "shaolin_xuan_bei")
		t = new CNshaolin_xuan_bei();
	else if(npc_name == "shaolin_xuan_ci")
		t = new CNshaolin_xuan_ci();
	else if(npc_name == "shaolin_xuan_ku")
		t = new CNshaolin_xuan_ku();
	else if(npc_name == "shaolin_xuan_nan")
		t = new CNshaolin_xuan_nan();
	else if(npc_name == "shaolin_xuan_tong")
		t = new CNshaolin_xuan_tong();

	else if(npc_name == "shaolin_xu_tong")
		t = new CNshaolin_xu_tong();
	else if(npc_name == "shaolin_xu_ming")
		t = new CNshaolin_xu_ming();

	else if(npc_name == "shaolin_du_e")
		t = new CNshaolin_du_e();
	else if(npc_name == "shaolin_du_jie")
		t = new CNshaolin_du_jie();
	else if(npc_name == "shaolin_du_nan")
		t = new CNshaolin_du_nan();

	else if(npc_name == "shaolin_wuying")
		t = new CNshaolin_wuying();

	else if(npc_name == "shaolin_da_mo")
		t = new CNshaolin_da_mo();
	else if(npc_name == "shaolin_tuoboseng")
		t = new CNshaolin_tuoboseng();
	else if(npc_name == "shaolin_xingzhe")
		t = new CNshaolin_xingzhe();

	//taohua
	else if(npc_name == "taohua_feng")
		t = new CNtaohua_feng();
	else if(npc_name == "taohua_lu")
		t = new CNtaohua_lu();
	else if(npc_name == "taohua_qu")
		t = new CNtaohua_qu();
	else if(npc_name == "taohua_rong")
		t = new CNtaohua_rong();
	else if(npc_name == "taohua_huang")
		t = new CNtaohua_huang();

	//神龙
	if(npc_name == "shenlong_zhang")
		t = new CNshenlong_zhang();
	else if(npc_name == "shenlong_yin")
		t = new CNshenlong_yin();
	else if(npc_name == "shenlong_xu")
		t = new CNshenlong_xu();
	else if(npc_name == "shenlong_hong")
		t = new CNshenlong_hong();
	else if(npc_name == "shenlong_pang")
		t = new CNshenlong_pang();
	else if(npc_name == "shenlong_shou")
		t = new CNshenlong_shou();
	else if(npc_name == "shenlong_su")
		t = new CNshenlong_su();
	else if(npc_name == "shenlong_lu")
		t = new CNshenlong_lu();
	else if(npc_name == "shenlong_wugeng")
		t = new CNshenlong_wugeng();
	//武当
	else if(npc_name == "wudang_zhixiang")
		t = new CNwudang_zhixiang();
	else if(npc_name == "wudang_zhike")
		t = new CNwudang_zhike();
	else if(npc_name == "wudang_zhang")
		t = new CNwudang_zhang();
	else if(npc_name == "wudang_yu")
		t = new CNwudang_yu();
	else if(npc_name == "wudang_yin")
		t = new CNwudang_yin();
	else if(npc_name == "wudang_xiaosong")
		t = new CNwudang_xiaosong();
	else if(npc_name == "wudang_xi")
		t = new CNwudang_xi();
	else if(npc_name == "wudang_wuxing")
		t = new CNwudang_wuxing();
	else if(npc_name == "wudang_song")
		t = new CNwudang_song();
	else if(npc_name == "wudang_shouyuan")
		t = new CNwudang_shouyuan();
	else if(npc_name == "wudang_shan")
		t = new CNwudang_shan();
	else if(npc_name == "wudang_qingxu")
		t = new CNwudang_qingxu();
	else if(npc_name == "wudang_qingfeng")
		t = new CNwudang_qingfeng();
	else if(npc_name == "wudang_mo")
		t = new CNwudang_mo();
	else if(npc_name == "wudang_mingyue")
		t = new CNwudang_mingyue();
	else if(npc_name == "wudang_guxu")
		t = new CNwudang_guxu();
	else if(npc_name == "wudang_bagua")
		t = new CNwudang_bagua();
	else if(npc_name == "wudang_famu")
		t = new CNwudang_famu();
	else if(npc_name == "wudang_daotong")
		t = new CNwudang_daotong();
	else if(npc_name == "wudang_yan")
		t = new CNwudang_yan();

	//侠客岛
	if(npc_name == "xiake_mu")
		t = new CNxiake_mu();
	else if(npc_name == "xiake_long")
		t = new CNxiake_long();
/*	else if(npc_name == "xiake_yanruoshui")
		t = new CNxiake_yanruoshui();*/
	//星宿
	else if(npc_name == "xingxiu_zhaixing")
		t = new CNxingxiu_zhaixing();
	else if(npc_name == "xingxiu_chuchen")
		t = new CNxingxiu_chuchen();
	else if(npc_name == "xingxiu_ding")
		t = new CNxingxiu_ding();
	else if(npc_name == "xingxiu_tianlang")
		t = new CNxingxiu_tianlang();
	else if(npc_name == "xingxiu_azi")
		t = new CNxingxiu_azi();
	else if(npc_name == "xingxiu_shihou")
		t = new CNxingxiu_shihou();
	//雪山
	else if(npc_name == "xueshan_xuedao")
		t = new CNxueshan_xuedao();
	else if(npc_name == "xueshan_shengdi")
		t = new CNxueshan_shengdi();
	else if(npc_name == "xueshan_shanyong")
		t = new CNxueshan_shanyong();
	else if(npc_name == "xueshan_samu")
		t = new CNxueshan_samu();
	else if(npc_name == "xueshan_lingzhi")
		t = new CNxueshan_lingzhi();
	else if(npc_name == "xueshan_lazhang")
		t = new CNxueshan_lazhang();
	else if(npc_name == "xueshan_jiumozhi")
		t = new CNxueshan_jiumozhi();
	else if(npc_name == "xueshan_jiamu")
		t = new CNxueshan_jiamu();
	else if(npc_name == "xueshan_baoxiang")
		t = new CNxueshan_baoxiang();
	else if(npc_name == "xueshan_gelunbu")
		t = new CNxueshan_gelunbu();
	else if(npc_name == "xueshan_fawang")
		t = new CNxueshan_fawang();
	else if(npc_name == "xueshan_daerba")
		t = new CNxueshan_daerba();
	else if(npc_name == "xueshan_guoshi")
		t = new CNxueshan_guoshi();
	//云龙
	else if(npc_name == "yunlong_chen")
		t = new CNyunlong_chen();
	else if(npc_name == "yunlong_ma")
		t = new CNyunlong_ma();
	else if(npc_name == "yunlong_xuanzhen")
		t = new CNyunlong_xuanzhen();

	return t;
}
