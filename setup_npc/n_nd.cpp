#include "stdafx.h"
#include "../server/Room.h"
#include "../std/Money.h"
#include "../std/Vendor.h"
#include "../std/BankOwner.h"
#include "../std/Corpse.h"
#include "../server/User.h"
#include "../std/FightRoom.h"
#include "../server/Channel.h"
#include "../server/Skill.h"
//-----------------------------------------------------------------
//
//	高级NPC
//	by sound	
//	date: 2001-07-20	
//
//-----------------------------------------------------------------

//大理的补充
#include "../npc/nd/dali/dali_biaotou.h"
#include "../npc/nd/dali/dali_bing.h"
#include "../npc/nd/dali/dali_duanyanqing.h"
#include "../npc/nd/dali/dali_duanyu.h"
#include "../npc/nd/dali/dali_enu.h"
#include "../npc/nd/dali/dali_fangshanu.h"
#include "../npc/nd/dali/dali_guigongzi.h"
#include "../npc/nd/dali/dali_huanu.h"
#include "../npc/nd/dali/dali_jianghuyiren.h"
#include "../npc/nd/dali/dali_kanzhuren.h"
#include "../npc/nd/dali/dali_keshang.h"
#include "../npc/nd/dali/dali_pochen.h"
#include "../npc/nd/dali/dali_poyi.h"
#include "../npc/nd/dali/dali_shennongdizi.h"
#include "../npc/nd/dali/dali_shouling.h"
#include "../npc/nd/dali/dali_wuliangdizi.h"

//峨嵋的补充
#include "../npc/nd/emei/emei_girldizi.h"
#include "../npc/nd/emei/emei_puren.h"
#include "../npc/nd/emei/emei_xiaosong.h"
#include "../npc/nd/emei/emei_youngwoman.h"

//福州的补充
#include "../npc/nd/fuzhou/fuzhou_cui.h"
#include "../npc/nd/fuzhou/fuzhou_linzhennan.h"
#include "../npc/nd/fuzhou/fuzhou_shi.h"
#include "../npc/nd/fuzhou/fuzhou_wang.h"
#include "../npc/nd/fuzhou/fuzhou_zheng.h"

//高昌的补充
#include "../npc/nd/gaochang/gaochang_ghost.h"
#include "../npc/nd/gaochang/gaochang_liwenxiu.h"
#include "../npc/nd/gaochang/gaochang_wuaer.h"

//关外的补充

#include "../npc/nd/guanwai/guanwai_diyun.h"
#include "../npc/nd/guanwai/guanwai_fengxifan.h"
#include "../npc/nd/guanwai/guanwai_heersu.h"
#include "../npc/nd/guanwai/guanwai_hufei.h"
#include "../npc/nd/guanwai/guanwai_jiaowenqi.h"
#include "../npc/nd/guanwai/guanwai_tengyilei.h"
#include "../npc/nd/guanwai/guanwai_wan.h"
#include "../npc/nd/guanwai/guanwai_xiaoyuanshan.h"
#include "../npc/nd/guanwai/guanwai_yanji.h"
#include "../npc/nd/guanwai/guanwai_yuzhenzi.h"

//归云山庄的补充
#include "../npc/nd/guiyun/guiyun_dabei.h"
#include "../npc/nd/guiyun/guiyun_duantiande.h"
#include "../npc/nd/guiyun/guiyun_fanyifei.h"
#include "../npc/nd/guiyun/guiyun_fengliang.h"
#include "../npc/nd/guiyun/guiyun_gaosan.h"
#include "../npc/nd/guiyun/guiyun_hanbaoju.h"
#include "../npc/nd/guiyun/guiyun_hanxiaoyin.h"
#include "../npc/nd/guiyun/guiyun_haojie.h"
#include "../npc/nd/guiyun/guiyun_jinbing.h"
#include "../npc/nd/guiyun/guiyun_kezhene.h"
#include "../npc/nd/guiyun/guiyun_luzhengping.h"
#include "../npc/nd/guiyun/guiyun_nanxiren.h"
#include "../npc/nd/guiyun/guiyun_qiuqianzhang.h"
#include "../npc/nd/guiyun/guiyun_quanjinfa.h"
#include "../npc/nd/guiyun/guiyun_shutong.h"
#include "../npc/nd/guiyun/guiyun_wanyanhonglie.h"
#include "../npc/nd/guiyun/guiyun_wanyankang.h"
#include "../npc/nd/guiyun/guiyun_xiaoju.h"
#include "../npc/nd/guiyun/guiyun_xiaolan.h"
#include "../npc/nd/guiyun/guiyun_xiaolu.h"
#include "../npc/nd/guiyun/guiyun_zhangasheng.h"
#include "../npc/nd/guiyun/guiyun_zhucong.h"

//古墓的补充
#include "../npc/nd/gumu/gumu_lin.h"

//黑木崖的补充
#include "../npc/nd/heimuya/heimuya_laozhe.h"
#include "../npc/nd/heimuya/heimuya_renyingying.h"
#include "../npc/nd/heimuya/heimuya_shang.h"
#include "../npc/nd/heimuya/heimuya_shanggy.h"
#include "../npc/nd/heimuya/heimuya_tongbx.h"
#include "../npc/nd/heimuya/heimuya_wangcheng.h"
#include "../npc/nd/heimuya/heimuya_xiang.h"
#include "../npc/nd/heimuya/heimuya_yang.h"
#include "../npc/nd/heimuya/heimuya_zhang1.h"
#include "../npc/nd/heimuya/heimuya_zhang2.h"
#include "../npc/nd/heimuya/heimuya_zhaohe.h"
#include "../npc/nd/heimuya/heimuya_zishan.h"
#include "../npc/nd/heimuya/heimuya_renwoxing.h"

//恒山派的补充（缺不戒和尚）
#include "../npc/nd/hengshan/hengshan_tian.h"
#include "../npc/nd/hengshan/hengshan_xian.h"
#include "../npc/nd/hengshan/hengshan_yafu.h"

//衡山的补充
#include "../npc/nd/henshan/henshan_chaboshi.h"
#include "../npc/nd/henshan/henshan_liuzf.h"
#include "../npc/nd/henshan/henshan_qu.h"
#include "../npc/nd/henshan/henshan_xiaoqu.h"

//黄河
#include "../npc/nd/huanghe/huanghe_bangzong.h"
#include "../npc/nd/huanghe/huanghe_liang.h"
#include "../npc/nd/huanghe/huanghe_peng.h"
#include "../npc/nd/huanghe/huanghe_sha.h"
#include "../npc/nd/huanghe/huanghe_shen.h"
#include "../npc/nd/huanghe/huanghe_zu.h"

//华山
#include "../npc/nd/huashan/huashan_doctor.h"
#include "../npc/nd/huashan/huashan_gaogenming.h"
#include "../npc/nd/huashan/huashan_girldizi.h"
#include "../npc/nd/huashan/huashan_linghu.h"
#include "../npc/nd/huashan/huashan_laodenuo.h"
#include "../npc/nd/huashan/huashan_liangfa.h"
#include "../npc/nd/huashan/huashan_ludayou.h"
#include "../npc/nd/huashan/huashan_shidaizi.h"
#include "../npc/nd/huashan/huashan_teller.h"
#include "../npc/nd/huashan/huashan_yuelingshan.h"

//昆仑
#include "../npc/nd/kunlun/kunlun_banshuxian.h"
#include "../npc/nd/kunlun/kunlun_gaozecheng.h"
#include "../npc/nd/kunlun/kunlun_hetaichong.h"
#include "../npc/nd/kunlun/kunlun_hezudao.h"
#include "../npc/nd/kunlun/kunlun_jiangtao.h"
#include "../npc/nd/kunlun/kunlun_xihuazi.h"
#include "../npc/nd/kunlun/kunlun_yulingzi.h"
#include "../npc/nd/kunlun/kunlun_zhanchun.h"

//灵州
#include "../npc/nd/lingzhou/lingzhou_gongweishi.h"
#include "../npc/nd/lingzhou/lingzhou_helian.h"
#include "../npc/nd/lingzhou/lingzhou_helianchunshui.h"
#include "../npc/nd/lingzhou/lingzhou_nan.h"
#include "../npc/nd/lingzhou/lingzhou_nuerhai.h"
#include "../npc/nd/lingzhou/lingzhou_ye.h"
#include "../npc/nd/lingzhou/lingzhou_yun.h"
#include "../npc/nd/lingzhou/lingzhou_yunying.h"
#include "../npc/nd/lingzhou/lingzhou_zhangfang.h"

//慕容
#include "../npc/nd/murong/murong_abi.h"
#include "../npc/nd/murong/murong_azhu.h"
#include "../npc/nd/murong/murong_bao.h"
#include "../npc/nd/murong/murong_bo.h"
#include "../npc/nd/murong/murong_deng.h"
#include "../npc/nd/murong/murong_feng.h"
#include "../npc/nd/murong/murong_fu.h"
#include "../npc/nd/murong/murong_gongsun.h"
#include "../npc/nd/murong/murong_tang.h"
#include "../npc/nd/murong/murong_wang.h"
#include "../npc/nd/murong/murong_wyy.h"
#include "../npc/nd/murong/murong_xiansheng.h"
#include "../npc/nd/murong/murong_yan.h"
#include "../npc/nd/murong/murong_youcao.h"

//青城
#include "../npc/nd/qingcheng/qingcheng_fang.h"
#include "../npc/nd/qingcheng/qingcheng_hai.h"
#include "../npc/nd/qingcheng/qingcheng_hong.h"
#include "../npc/nd/qingcheng/qingcheng_hou.h"
#include "../npc/nd/qingcheng/qingcheng_ji.h"
#include "../npc/nd/qingcheng/qingcheng_jia.h"
#include "../npc/nd/qingcheng/qingcheng_luo.h"
#include "../npc/nd/qingcheng/qingcheng_shen.h"
#include "../npc/nd/qingcheng/qingcheng_yu.h"
#include "../npc/nd/qingcheng/qingcheng_yuyan.h"

//少林
#include "../npc/nd/shaolin/shaolin_datieseng.h"
#include "../npc/nd/shaolin/shaolin_laoqiao.h"
#include "../npc/nd/shaolin/shaolin_sengbing1.h"
#include "../npc/nd/shaolin/shaolin_sengbing2.h"
#include "../npc/nd/shaolin/shaolin_sengbing3.h"

//神龙
#include "../npc/nd/shenlong/shenlong_boy.h"
//#include "../npc/nd/shenlong/shenlong_chuanfu.h"
#include "../npc/nd/shenlong/shenlong_girl.h"
#include "../npc/nd/shenlong/shenlong_old.h"

//嵩山
#include "../npc/nd/songshan/songshan_bu.h"
#include "../npc/nd/songshan/songshan_deng.h"
#include "../npc/nd/songshan/songshan_di.h"
#include "../npc/nd/songshan/songshan_ding.h"
#include "../npc/nd/songshan/songshan_fei.h"
#include "../npc/nd/songshan/songshan_gao.h"
#include "../npc/nd/songshan/songshan_lu.h"
#include "../npc/nd/songshan/songshan_sha.h"
#include "../npc/nd/songshan/songshan_tang.h"
#include "../npc/nd/songshan/songshan_wan.h"
#include "../npc/nd/songshan/songshan_zuo.h"

//泰山
#include "../npc/nd/taishan/taishan_chi.h"
#include "../npc/nd/taishan/taishan_jianchu.h"
#include "../npc/nd/taishan/taishan_tianbai.h"
#include "../npc/nd/taishan/taishan_tianmen.h"
#include "../npc/nd/taishan/taishan_tiansong.h"
#include "../npc/nd/taishan/taishan_tianyi.h"
#include "../npc/nd/taishan/taishan_yujizi.h"
#include "../npc/nd/taishan/taishan_yuqingzi.h"
#include "../npc/nd/taishan/taishan_yuyinzi.h"

//桃花岛
#include "../npc/nd/taohua/taohua_binv.h"
#include "../npc/nd/taohua/taohua_jiguan.h"
#include "../npc/nd/taohua/taohua_shagu.h"
#include "../npc/nd/taohua/taohua_shitong.h"
#include "../npc/nd/taohua/taohua_shoumu.h"
#include "../npc/nd/taohua/taohua_yan.h"

//铁掌
#include "../npc/nd/tiezhang/tiezhang_gu.h"
#include "../npc/nd/tiezhang/tiezhang_heiyi.h"
#include "../npc/nd/tiezhang/tiezhang_huiyi.h"
#include "../npc/nd/tiezhang/tiezhang_mayi.h"
#include "../npc/nd/tiezhang/tiezhang_qqren.h"
#include "../npc/nd/tiezhang/tiezhang_qqzhang.h"
#include "../npc/nd/tiezhang/tiezhang_sgjn.h"

//万劫谷
#include "../npc/nd/wanjie/shaolin_monk.h"
#include "../npc/nd/wanjie/wanjie_duanyanqing.h"
#include "../npc/nd/wanjie/wanjie_fuer.h"
#include "../npc/nd/wanjie/wanjie_gan.h"
#include "../npc/nd/wanjie/wanjie_mu.h"
#include "../npc/nd/wanjie/wanjie_zhong.h"
#include "../npc/nd/wanjie/wanjie_zhongling.h"

//侠客岛
#include "../npc/nd/xiakedao/xiakedao_daoseng.h"
#include "../npc/nd/xiakedao/xiakedao_dingdang.h"
#include "../npc/nd/xiakedao/xiakedao_dizi.h"
#include "../npc/nd/xiakedao/xiakedao_dizi1.h"
#include "../npc/nd/xiakedao/xiakedao_dizi2.h"
#include "../npc/nd/xiakedao/xiakedao_dizi3.h"
#include "../npc/nd/xiakedao/xiakedao_lisi.h"
#include "../npc/nd/xiakedao/xiakedao_long.h"
#include "../npc/nd/xiakedao/xiakedao_maliu.h"
#include "../npc/nd/xiakedao/xiakedao_mu.h"
#include "../npc/nd/xiakedao/xiakedao_shitianjing.h"
#include "../npc/nd/xiakedao/xiakedao_shizhongyu.h"
#include "../npc/nd/xiakedao/xiakedao_shizhe.h"
#include "../npc/nd/xiakedao/xiakedao_shizhe1.h"
#include "../npc/nd/xiakedao/xiakedao_shizhe3.h"
#include "../npc/nd/xiakedao/xiakedao_tongzi.h"
#include "../npc/nd/xiakedao/xiakedao_wangwu.h"
#include "../npc/nd/xiakedao/xiakedao_xieyan.h"
#include "../npc/nd/xiakedao/xiakedao_yufu.h"
#include "../npc/nd/xiakedao/xiakedao_zhangsan.h"

//襄阳
#include "../npc/nd/xiangyang/xiangyang_guofu.h"
#include "../npc/nd/xiangyang/xiangyang_guojing.h"
#include "../npc/nd/xiangyang/xiangyang_menggubing.h"
#include "../npc/nd/xiangyang/xiangyang_pi.h"
#include "../npc/nd/xiangyang/xiangyang_qiuhang.h"
#include "../npc/nd/xiangyang/xiangyang_shaofanshifu.h"
#include "../npc/nd/xiangyang/xiangyang_tuolei.h"
#include "../npc/nd/xiangyang/xiangyang_wang.h"
#include "../npc/nd/xiangyang/xiangyang_wusantong.h"
#include "../npc/nd/xiangyang/xiangyang_ya.h"

//血刀门
#include "../npc/nd/xuedao/xuedao_huatiegan.h"
#include "../npc/nd/xuedao/xuedao_liuchengfeng.h"
#include "../npc/nd/xuedao/xuedao_lutianshu.h"
#include "../npc/nd/xuedao/xuedao_shuidai.h"
#include "../npc/nd/xuedao/xuedao_yangzong.h"
#include "../npc/nd/xuedao/xuedao_zhuoma.h"

//其他
#include "../npc/nd/other/xiaxueyi.h"

//-----------------------------------------------------------------
//
//	高级NPC
//	by zdn	
//	date: 2001-07-20	
//
//-----------------------------------------------------------------

//baituo
#include"../npc/nd/baituo/laocai.h"
//binghuodao
#include"../npc/nd/binghuodao/susu.h"
//city
#include"../npc/nd/city/libanxian.h"
#include"../npc/nd/city/linpingzhi.h"
#include"../npc/nd/city/linzhennan.h"
#include"../npc/nd/city/man.h"
#include"../npc/nd/city/shi.h"
#include"../npc/nd/city/shiye.h"
#include"../npc/nd/city/xiangling.h"
#include"../npc/nd/city/zeng.h"
#include"../npc/nd/city/zhaojunrong.h"
//city2
#include"../npc/nd/city2/dubi.h"
#include"../npc/nd/city2/gaoyanch.h"
#include"../npc/nd/city2/guanfuzi.h"
#include"../npc/nd/city2/jia.h"
#include"../npc/nd/city2/lilishi.h"
#include"../npc/nd/city2/mao18.h"
#include"../npc/nd/city2/qi.h"
#include"../npc/nd/city2/shenzhao.h"
#include"../npc/nd/city2/wuliuqi.h"
#include"../npc/nd/city2/wuzhirong.h"
#include"../npc/nd/city2/zhuangyu.h"
#include"../npc/nd/city2/zhuge.h"
//hangzhou
#include"../npc/nd/hangzhou/baizhen.h"
#include"../npc/nd/hangzhou/honghua1.h"
#include"../npc/nd/hangzhou/likexiu.h"
#include"../npc/nd/hangzhou/zhang.h"
//yangzhou
#include"../npc/nd/yangzhou/chen.h"

//帮助
#include "../npc/nd/help/helpnpc_jhlz.h"
#include "../npc/nd/help/helpnpc001.h"
#include "../npc/nd/help/helpnpc002.h"
#include "../npc/nd/help/helpnpc003.h"
#include "../npc/nd/help/helpnpc004.h"
#include "../npc/nd/help/helpnpc005.h"
#include "../npc/nd/help/helpnpc006.h"
#include "../npc/nd/help/helpnpc007.h"
#include "../npc/nd/help/helpnpc008.h"
#include "../npc/nd/help/helpnpc009.h"
#include "../npc/nd/help/helpnpc010.h"
#include "../npc/nd/help/helpnpc011.h"
#include "../npc/nd/help/helpnpc012.h"
#include "../npc/nd/help/helpnpc013.h"
#include "../npc/nd/help/helpnpc014.h"
#include "../npc/nd/help/helpnpc015.h"
#include "../npc/nd/help/helpnpc016.h"
#include "../npc/nd/help/helpnpc017.h"
#include "../npc/nd/help/helpnpc018.h"
#include "../npc/nd/help/helpnpc019.h"
#include "../npc/nd/help/helpnpc020.h"
#include "../npc/nd/help/helpnpc021.h"
#include "../npc/nd/help/helpnpc022.h"

CNpc * LoadNPC_nd(string npc_name)
{
	CNpc * t = NULL;

	//大理
	if(npc_name == "dali_biaotou")
		t = new CNdali_biaotou();
	else if(npc_name == "dali_bing")
		t = new CNdali_bing();
	else if(npc_name == "dali_duanyanqing")
		t = new CNdali_duanyanqing();
	else if(npc_name == "dali_duanyu")
		t = new CNdali_duanyu();
	else if(npc_name == "dali_enu")
		t = new CNdali_enu();
	else if(npc_name == "dali_fangshanu")
		t = new CNdali_fangshanu();
	else if(npc_name == "dali_guigongzi")
		t = new CNdali_guigongzi();
	else if(npc_name == "dali_huanu")
		t = new CNdali_huanu();
	else if(npc_name == "dali_jianghuyiren")
		t = new CNdali_jianghuyiren();
	else if(npc_name == "dali_kanzhuren")
		t = new CNdali_kanzhuren();
	else if(npc_name == "dali_keshang")
		t = new CNdali_keshang();
	else if(npc_name == "dali_pochen")
		t = new CNdali_pochen();
	else if(npc_name == "dali_poyi")
		t = new CNdali_poyi();
	else if(npc_name == "dali_shennongdizi")
		t = new CNdali_shennongdizi();
	else if(npc_name == "dali_shouling")
		t = new CNdali_shouling();
	else if(npc_name == "dali_wuliangdizi")
		t = new CNdali_wuliangdizi();

	//峨嵋
	else if(npc_name == "emei_girldizi")
		t = new CNemei_girldizi();
	else if(npc_name == "emei_puren")
		t = new CNemei_puren();
	else if(npc_name == "emei_xiaosong")
		t = new CNemei_xiaosong();
//	else if(npc_name == "emei_yanziyi")
//		t = new CNemei_yanziyi();
	else if(npc_name == "emei_youngwoman")
		t = new CNemei_youngwoman();

	//福州
	else if(npc_name == "fuzhou_cui")
		t = new CNfuzhou_cui();
	else if(npc_name == "fuzhou_linzhennan")
		t = new CNfuzhou_linzhennan();
	else if(npc_name == "fuzhou_shi")
		t = new CNfuzhou_shi();
	else if(npc_name == "fuzhou_wang")
		t = new CNfuzhou_wang();
	else if(npc_name == "fuzhou_zheng")
		t = new CNfuzhou_zheng();

	//高昌
	else if(npc_name == "gaochang_ghost")
		t = new CNgaochang_ghost();
	else if(npc_name == "gaochang_liwenxiu")
		t = new CNgaochang_liwenxiu();
	else if(npc_name == "gaochang_wuaer")
		t = new CNgaochang_wuaer();

	//关外
	else if(npc_name == "guanwai_diyun")
		t = new CNguanwai_diyun();
	else if(npc_name == "guanwai_fengxifan")
		t = new CNguanwai_fengxifan();
	else if(npc_name == "guanwai_heersu")
		t = new CNguanwai_heersu();
	else if(npc_name == "guanwai_hufei")
		t = new CNguanwai_hufei();
	else if(npc_name == "guanwai_jiaowenqi")
		t = new CNguanwai_jiaowenqi();
	else if(npc_name == "guanwai_tengyilei")
		t = new CNguanwai_tengyilei();
	else if(npc_name == "guanwai_wan")
		t = new CNguanwai_wan();
	else if(npc_name == "guanwai_xiaoyuanshan")
		t = new CNguanwai_xiaoyuanshan();
	else if(npc_name == "guanwai_yanji")
		t = new CNguanwai_yanji();
	else if(npc_name == "guanwai_yuzhenzi")
		t = new CNguanwai_yuzhenzi();

	//归云山庄
	else if(npc_name == "guiyun_dabei")
		t = new CNguiyun_dabei();
	else if(npc_name == "guiyun_duantiande")
		t = new CNguiyun_duantiande();
	else if(npc_name == "guiyun_fanyifei")
		t = new CNguiyun_fanyifei();
	else if(npc_name == "guiyun_fengliang")
		t = new CNguiyun_fengliang();
	else if(npc_name == "guiyun_gaosan")
		t = new CNguiyun_gaosan();
	else if(npc_name == "guiyun_hanbaoju")
		t = new CNguiyun_hanbaoju();
	else if(npc_name == "guiyun_hanxiaoyin")
		t = new CNguiyun_hanxiaoyin();
	else if(npc_name == "guiyun_haojie")
		t = new CNguiyun_haojie();
	else if(npc_name == "guiyun_jinbing")
		t = new CNguiyun_jinbing();
	else if(npc_name == "guiyun_kezhene")
		t = new CNguiyun_kezhene();
	else if(npc_name == "guiyun_luzhengping")
		t = new CNguiyun_luzhengping();
	else if(npc_name == "guiyun_nanxiren")
		t = new CNguiyun_nanxiren();
	else if(npc_name == "guiyun_qiuqianzhang")
		t = new CNguiyun_qiuqianzhang();
	else if(npc_name == "guiyun_quanjinfa")
		t = new CNguiyun_quanjinfa();
	else if(npc_name == "guiyun_shutong")
		t = new CNguiyun_shutong();
	else if(npc_name == "guiyun_wanyanhonglie")
		t = new CNguiyun_wanyanhonglie();
	else if(npc_name == "guiyun_wanyankang")
		t = new CNguiyun_wanyankang();
	else if(npc_name == "guiyun_xiaoju")
		t = new CNguiyun_xiaoju();
	else if(npc_name == "guiyun_xiaolan")
		t = new CNguiyun_xiaolan();
	else if(npc_name == "guiyun_xiaolu")
		t = new CNguiyun_xiaolu();
	else if(npc_name == "guiyun_zhangasheng")
		t = new CNguiyun_zhangasheng();
	else if(npc_name == "guiyun_zhucong")
		t = new CNguiyun_zhucong();

	//古墓
	else if(npc_name == "gumu_lin")
		t = new CNgumu_lin();

	//黑木崖
	else if(npc_name == "heimuya_laozhe")
		t = new CNheimuya_laozhe();
	else if(npc_name == "heimuya_renyingying")
		t = new CNheimuya_renyingying();
	else if(npc_name == "heimuya_shang")
		t = new CNheimuya_shang();
	else if(npc_name == "heimuya_shanggy")
		t = new CNheimuya_shanggy();
	else if(npc_name == "heimuya_tongbx")
		t = new CNheimuya_tongbx();
	else if(npc_name == "heimuya_wangcheng")
		t = new CNheimuya_wangcheng();
	else if(npc_name == "heimuya_xiang")
		t = new CNheimuya_xiang();
	else if(npc_name == "heimuya_yang")
		t = new CNheimuya_yang();
	else if(npc_name == "heimuya_zhang1")
		t = new CNheimuya_zhang1();
	else if(npc_name == "heimuya_zhang2")
		t = new CNheimuya_zhang2();
	else if(npc_name == "heimuya_zhaohe")
		t = new CNheimuya_zhaohe();
	else if(npc_name == "heimuya_zishan")
		t = new CNheimuya_zishan();
	else if(npc_name == "heimuya_renwoxing")
		t = new CNHeiMUYa_renwoxing();

	//恒山派
	else if(npc_name == "hengshan_tian")
		t = new CNhengshan_tian();
	else if(npc_name == "hengshan_xian")
		t = new CNhengshan_xian();
	else if(npc_name == "hengshan_yafu")
		t = new CNhengshan_yafu();

	//衡山
	else if(npc_name == "henshan_chaboshi")
		t = new CNhenshan_chaboshi();
	else if(npc_name == "henshan_liuzf")
		t = new CNhenshan_liuzf();
	else if(npc_name == "henshan_qu")
		t = new CNhenshan_qu();
	else if(npc_name == "henshan_xiaoqu")
		t = new CNhenshan_xiaoqu();

	//黄河
	else if(npc_name == "huanghe_bangzong")
		t = new CNhuanghe_bangzong();
	else if(npc_name == "huanghe_liang")
		t = new CNhuanghe_liang();
	else if(npc_name == "huanghe_peng")
		t = new CNhuanghe_peng();
	else if(npc_name == "huanghe_sha")
		t = new CNhuanghe_sha();
	else if(npc_name == "huanghe_shen")
		t = new CNhuanghe_shen();
	else if(npc_name == "huanghe_zu")
		t = new CNhuanghe_zu();

	//华山
	else if(npc_name == "huashan_doctor")
		t = new CNhuashan_doctor();
	else if(npc_name == "huashan_gaogenming")
		t = new CNhuashan_gaogenming();
	else if(npc_name == "huashan_girldizi")
		t = new CNhuashan_girldizi();
	else if(npc_name == "huashan_linghu")
		t = new CNhuashan_linghu();
	else if(npc_name == "huashan_laodenuo")
		t = new CNhuashan_laodenuo();
	else if(npc_name == "huashan_liangfa")
		t = new CNhuashan_liangfa();
	else if(npc_name == "huashan_ludayou")
		t = new CNhuashan_ludayou();
	else if(npc_name == "huashan_shidaizi")
		t = new CNhuashan_shidaizi();
	else if(npc_name == "huashan_teller")
		t = new CNhuashan_teller();
	else if(npc_name == "huashan_yuelingshan")
		t = new CNhuashan_yuelingshan();

	//昆仑
	else if(npc_name == "kunlun_banshuxian")
		t = new CNkunlun_banshuxian();
	else if(npc_name == "kunlun_gaozecheng")
		t = new CNkunlun_gaozecheng();
	else if(npc_name == "kunlun_hetaichong")
		t = new CNkunlun_hetaichong();
	else if(npc_name == "kunlun_hezudao")
		t = new CNkunlun_hezudao();
	else if(npc_name == "kunlun_jiangtao")
		t = new CNkunlun_jiangtao();
	else if(npc_name == "kunlun_xihuazi")
		t = new CNkunlun_xihuazi();
	else if(npc_name == "kunlun_yulingzi")
		t = new CNkunlun_yulingzi();
	else if(npc_name == "kunlun_zhanchun")
		t = new CNkunlun_zhanchun();

	//灵州
	else if(npc_name == "lingzhou_gongweishi")
		t = new CNlingzhou_gongweishi();
	else if(npc_name == "lingzhou_helian")
		t = new CNlingzhou_helian();
	else if(npc_name == "lingzhou_helianchunshui")
		t = new CNlingzhou_helianchunshui();
	else if(npc_name == "lingzhou_nan")
		t = new CNlingzhou_nan();
	else if(npc_name == "lingzhou_nuerhai")
		t = new CNlingzhou_nuerhai();
	else if(npc_name == "lingzhou_ye")
		t = new CNlingzhou_ye();
	else if(npc_name == "lingzhou_yun")
		t = new CNlingzhou_yun();
	else if(npc_name == "lingzhou_yunying")
		t = new CNlingzhou_yunying();
	else if(npc_name == "lingzhou_zhangfang")
		t = new CNlingzhou_zhangfang();

	//慕容
	if(npc_name == "murong_abi")
		t = new CNmurong_abi();
	else if(npc_name == "murong_azhu")
		t = new CNmurong_azhu();
	else if(npc_name == "murong_bao")
		t = new CNmurong_bao();
	else if(npc_name == "murong_bo")
		t = new CNmurong_bo();
	else if(npc_name == "murong_deng")
		t = new CNmurong_deng();
	else if(npc_name == "murong_feng")
		t = new CNmurong_feng();
	else if(npc_name == "murong_fu")
		t = new CNmurong_fu();
	else if(npc_name == "murong_gongsun")
		t = new CNmurong_gongsun();
	else if(npc_name == "murong_tang")
		t = new CNmurong_tang();
	else if(npc_name == "murong_wang")
		t = new CNmurong_wang();
	else if(npc_name == "murong_wyy")
		t = new CNmurong_wyy();
	else if(npc_name == "murong_xiansheng")
		t = new CNmurong_xiansheng();
	else if(npc_name == "murong_yan")
		t = new CNmurong_yan();
	else if(npc_name == "murong_youcao")
		t = new CNmurong_youcao();

	//青城
	else if(npc_name == "qingcheng_fang")
		t = new CNqingcheng_fang();
	else if(npc_name == "qingcheng_hai")
		t = new CNqingcheng_hai();
	else if(npc_name == "qingcheng_hong")
		t = new CNqingcheng_hong();
	else if(npc_name == "qingcheng_hou")
		t = new CNqingcheng_hou();
	else if(npc_name == "qingcheng_ji")
		t = new CNqingcheng_ji();
	else if(npc_name == "qingcheng_jia")
		t = new CNqingcheng_jia();
	else if(npc_name == "qingcheng_luo")
		t = new CNqingcheng_luo();
	else if(npc_name == "qingcheng_shen")
		t = new CNqingcheng_shen();
	else if(npc_name == "qingcheng_yu")
		t = new CNqingcheng_yu();
	else if(npc_name == "qingcheng_yuyan")
		t = new CNqingcheng_yuyan();

	//少林
	else if(npc_name == "shaolin_datieseng")
		t = new CNshaolin_datieseng();
	else if(npc_name == "shaolin_laoqiao")
		t = new CNshaolin_laoqiao();
	else if(npc_name == "shaolin_sengbing1")
		t = new CNshaolin_sengbing1();
	else if(npc_name == "shaolin_sengbing2")
		t = new CNshaolin_sengbing2();
	else if(npc_name == "shaolin_sengbing3")
		t = new CNshaolin_sengbing3();

	//神龙
	else if(npc_name == "shenlong_boy")
		t = new CNshenlong_boy();
//	else if(npc_name == "shenlong_chuanfu")
//		t = new CNshenlong_chuanfu();
	else if(npc_name == "shenlong_girl")
		t = new CNshenlong_girl();
	else if(npc_name == "shenlong_old")
		t = new CNshenlong_old();

	//嵩山
	else if(npc_name == "songshan_bu")
		t = new CNsongshan_bu();
	else if(npc_name == "songshan_deng")
		t = new CNsongshan_deng();
	else if(npc_name == "songshan_di")
		t = new CNsongshan_di();
	else if(npc_name == "songshan_ding")
		t = new CNsongshan_ding();
	else if(npc_name == "songshan_fei")
		t = new CNsongshan_fei();
	else if(npc_name == "songshan_gao")
		t = new CNsongshan_gao();
	else if(npc_name == "songshan_lu")
		t = new CNsongshan_lu();
	else if(npc_name == "songshan_sha")
		t = new CNsongshan_sha();
	else if(npc_name == "songshan_tang")
		t = new CNsongshan_tang();
	else if(npc_name == "songshan_wan")
		t = new CNsongshan_wan();
	else if(npc_name == "songshan_zuo")
		t = new CNsongshan_zuo();

	//泰山
	else if(npc_name == "taishan_chi")
		t = new CNtaishan_chi();
	else if(npc_name == "taishan_jianchu")
		t = new CNtaishan_jianchu();
	else if(npc_name == "taishan_tianbai")
		t = new CNtaishan_tianbai();
	else if(npc_name == "taishan_tianmen")
		t = new CNtaishan_tianmen();
	else if(npc_name == "taishan_tiansong")
		t = new CNtaishan_tiansong();
	else if(npc_name == "taishan_tianyi")
		t = new CNtaishan_tianyi();
	else if(npc_name == "taishan_yujizi")
		t = new CNtaishan_yujizi();
	else if(npc_name == "taishan_yuqingzi")
		t = new CNtaishan_yuqingzi();
	else if(npc_name == "taishan_yuyinzi")
		t = new CNtaishan_yuyinzi();

	//桃花
	else if(npc_name == "taohua_binv")
		t = new CNtaohua_binv();
	else if(npc_name == "taohua_jiguan")
		t = new CNtaohua_jiguan();
	else if(npc_name == "taohua_shagu")
		t = new CNtaohua_shagu();
	else if(npc_name == "taohua_shitong")
		t = new CNtaohua_shitong();
	else if(npc_name == "taohua_shoumu")
		t = new CNtaohua_shoumu();
	else if(npc_name == "taohua_yan")
		t = new CNtaohua_yan();

	//铁掌
	else if(npc_name == "tiezhang_gu")
		t = new CNtiezhang_gu();
	else if(npc_name == "tiezhang_heiyi")
		t = new CNtiezhang_heiyi();
	else if(npc_name == "tiezhang_huiyi")
		t = new CNtiezhang_huiyi();
	else if(npc_name == "tiezhang_mayi")
		t = new CNtiezhang_mayi();
	else if(npc_name == "tiezhang_qqren")
		t = new CNtiezhang_qqren();
	else if(npc_name == "tiezhang_qqzhang")
		t = new CNtiezhang_qqzhang();
	else if(npc_name == "tiezhang_sgjn")
		t = new CNtiezhang_sgjn();

	//万劫
	else if(npc_name == "shaolin_monk")
		t = new CNshaolin_monk();
	else if(npc_name == "wanjie_duanyanqing")
		t = new CNwanjie_duanyanqing();
	else if(npc_name == "wanjie_fuer")
		t = new CNwanjie_fuer();
	else if(npc_name == "wanjie_gan")
		t = new CNwanjie_gan();
	else if(npc_name == "wanjie_mu")
		t = new CNwanjie_mu();
	else if(npc_name == "wanjie_zhong")
		t = new CNwanjie_zhong();
	else if(npc_name == "wanjie_zhongling")
		t = new CNwanjie_zhongling();

	//侠客岛
	else if(npc_name == "xiakedao_daoseng")
		t = new CNxiakedao_daoseng();
	else if(npc_name == "xiakedao_dingdang")
		t = new CNxiakedao_dingdang();
	else if(npc_name == "xiakedao_dizi")
		t = new CNxiakedao_dizi();
	else if(npc_name == "xiakedao_dizi1")
		t = new CNxiakedao_dizi1();
	else if(npc_name == "xiakedao_dizi2")
		t = new CNxiakedao_dizi2();
	else if(npc_name == "xiakedao_dizi3")
		t = new CNxiakedao_dizi3();
	else if(npc_name == "xiakedao_lisi")
		t = new CNxiakedao_lisi();
	else if(npc_name == "xiakedao_long")
		t = new CNxiakedao_long();
	else if(npc_name == "xiakedao_maliu")
		t = new CNxiakedao_maliu();
	else if(npc_name == "xiakedao_mu")
		t = new CNxiakedao_mu();
	else if(npc_name == "xiakedao_shitianjing")
		t = new CNxiakedao_shitianjing();
	else if(npc_name == "xiakedao_shizhongyu")
		t = new CNxiakedao_shizhongyu();
	else if(npc_name == "xiakedao_shizhe")
		t = new CNxiakedao_shizhe();
	else if(npc_name == "xiakedao_shizhe1")
		t = new CNxiakedao_shizhe1();
	else if(npc_name == "xiakedao_shizhe3")
		t = new CNxiakedao_shizhe3();
	else if(npc_name == "xiakedao_tongzi")
		t = new CNxiakedao_tongzi();
	else if(npc_name == "xiakedao_wangwu")
		t = new CNxiakedao_wangwu();
	else if(npc_name == "xiakedao_xieyan")
		t = new CNxiakedao_xieyan();
	else if(npc_name == "xiakedao_yufu")
		t = new CNxiakedao_yufu();
	else if(npc_name == "xiakedao_zhangsan")
		t = new CNxiakedao_zhangsan();

	//襄阳
	else if(npc_name == "xiangyang_guofu")
		t = new CNxiangyang_guofu();
	else if(npc_name == "xiangyang_guojing")
		t = new CNxiangyang_guojing();
	else if(npc_name == "xiangyang_menggubing")
		t = new CNxiangyang_menggubing();
	else if(npc_name == "xiangyang_pi")
		t = new CNxiangyang_pi();
	else if(npc_name == "xiangyang_qiuhang")
		t = new CNxiangyang_qiuhang();
	else if(npc_name == "xiangyang_shaofanshifu")
		t = new CNxiangyang_shaofanshifu();
	else if(npc_name == "xiangyang_tuolei")
		t = new CNxiangyang_tuolei();
	else if(npc_name == "xiangyang_wang")
		t = new CNxiangyang_wang();
	else if(npc_name == "xiangyang_wusantong")
		t = new CNxiangyang_wusantong();
	else if(npc_name == "xiangyang_ya")
		t = new CNxiangyang_ya();

	//血刀
	else if(npc_name == "xuedao_huatiegan")
		t = new CNxuedao_huatiegan();
	else if(npc_name == "xuedao_liuchengfeng")
		t = new CNxuedao_liuchengfeng();
	else if(npc_name == "xuedao_lutianshu")
		t = new CNxuedao_lutianshu();
	else if(npc_name == "xuedao_shuidai")
		t = new CNxuedao_shuidai();
	else if(npc_name == "xuedao_yangzong")
		t = new CNxuedao_yangzong();
	else if(npc_name == "xuedao_zhuoma")
		t = new CNxuedao_zhuoma();

	//其他
	else if(npc_name == "xiaxueyi")
		t = new CNxiaxueyi();

//-----------------------------------------------------------------
//
//	高级NPC
//	by zdn	
//	date: 2001-07-20	
//
//-----------------------------------------------------------------
    
	//baituo
	if(npc_name == "biatuo_laocai")
		t = new CNbiatuo_laocai();

    //binghuodao
	else if(npc_name == "binghuodao_susu")
		t= new CNbinghuodao_susu();

    //city
	else if(npc_name == "city_zhaocaifeng")
		t = new CNcity_zhaocaifeng();
	else if(npc_name == "city_zeng")
		t = new CNcity_zeng();
	else if(npc_name == "city_xiangling")
		t = new CNcity_xiangling();
	else if(npc_name == "city_tanyouji")
		t = new CNcity_tanyouji();
    else if(npc_name == "city_shi")
		t = new CNcity_shi();
	else if(npc_name == "city_noname")
		t = new CNcity_noname();
	else if(npc_name == "city_linzhennan")
		t = new CNcity_linzhennan();
	else if(npc_name == "city_linpingzhi")
		t = new CNcity_linpingzhi();
	else if(npc_name == "city_banxian")
		t = new CNcity_banxian();


    //city2
	else if(npc_name == "city2_zhuge")
		t = new CNcity2_zhuge();
	else if(npc_name == "city2_zhuangyu")
		t = new CNcity2_zhuangyu();
	else if(npc_name == "city2_wuzhirong")
	   t = new CNcity2_wuzhirong();
    else if(npc_name == "city2_wuliuqi")
		t = new CNcity2_wuliuqi();
	else if(npc_name == "city2_shenzhao")
		t = new CNcity2_shenzhao();
    else if(npc_name == "city2_qi")
		t = new CNcity2_qi();
	else if(npc_name == "city2_mao18")
		t = new CNcity2_mao18();
	else if(npc_name == "city2_lilishi")
		t = new CNcity2_lilishi();     
	else if(npc_name == "city2_jialaoliu")
		t = new CNcity2_jialaoliu();  
	else if(npc_name == "city2_guanfuzi")  
		t = new CNcity2_guanfuzi();    
    else if(npc_name == "city2_gaoyanchao")
		t = new CNcity2_gaoyanchao();  
    else if(npc_name == "city2_dubi")
		t = new CNcity2_dubi();

  //hongzhou
	else if(npc_name == "hangzhou_zhangzz")
		t = new CNhangzhou_zhangzz();
    else if(npc_name == "hangzhou_likexiu")
		t = new CNhangzhou_likexiu();
	else if(npc_name == "hangzhou_honghua1")
		t = new CNhangzhou_honghua1();
	else if(npc_name == "hangzhou_baizhen")
		t = new CNhangzhou_baizhen();

    //yangzhou
 	else if(npc_name == "yangzhou_chen")
		t = new CNyangzhou_chen();
		
    //yangzhou
 	else if(npc_name == "helpnpc_jhlz")
		t = new CNhelpnpc_jhlz();
 	else if(npc_name == "helpnpc001")
		t = new CNhelpnpc001();
 	else if(npc_name == "helpnpc002")
		t = new CNhelpnpc002();
 	else if(npc_name == "helpnpc003")
		t = new CNhelpnpc003();
  	else if(npc_name == "helpnpc004")
		t = new CNhelpnpc004();
   	else if(npc_name == "helpnpc005")
		t = new CNhelpnpc005();
 	else if(npc_name == "helpnpc006")
		t = new CNhelpnpc006();
  	else if(npc_name == "helpnpc007")
		t = new CNhelpnpc007();
 	else if(npc_name == "helpnpc008")
		t = new CNhelpnpc008();
 	else if(npc_name == "helpnpc009")
		t = new CNhelpnpc009();
 	else if(npc_name == "helpnpc010")
		t = new CNhelpnpc010();
 	else if(npc_name == "helpnpc011")
		t = new CNhelpnpc011();
 	else if(npc_name == "helpnpc012")
		t = new CNhelpnpc012();
 	else if(npc_name == "helpnpc013")
		t = new CNhelpnpc013();
 	else if(npc_name == "helpnpc014")
		t = new CNhelpnpc014();
 	else if(npc_name == "helpnpc015")
		t = new CNhelpnpc015();
 	else if(npc_name == "helpnpc016")
		t = new CNhelpnpc016();
 	else if(npc_name == "helpnpc017")
		t = new CNhelpnpc017();
 	else if(npc_name == "helpnpc018")
		t = new CNhelpnpc018();
 	else if(npc_name == "helpnpc019")
		t = new CNhelpnpc019();
 	else if(npc_name == "helpnpc020")
		t = new CNhelpnpc020();
 	else if(npc_name == "helpnpc021")
		t = new CNhelpnpc021();  
 	else if(npc_name == "helpnpc022")
		t = new CNhelpnpc022();

	return t;
}




