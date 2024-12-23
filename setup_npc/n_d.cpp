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
#include "../std/resident.h"
//-----------------------------------------------------------------
//
//	公共NPC之五
//	author:		
//	date:		
//
//-----------------------------------------------------------------
//bingqi
#include "../npc/d/hero_oho.h"
#include "../npc/d/wanjie_foolmaster.h"
#include "../npc/monster/fool/monster1.h"
#include "../npc/monster/fool/monster2.h"
#include "../npc/monster/fool/monster3.h"
#include "../npc/monster/fool/monster4.h"
#include "../npc/monster/fool/monster5.h"
#include "../npc/monster/fool/monster6.h"/*
#include "../npc/monster/fool/monster7.h"*/

#include "../npc/d/bingqi_ouyezi.h"
#include "../npc/d/bingqi_shibian.h"
#include "../npc/d/bingqi_shichui.h"
#include "../npc/d/bingqi_shidao.h"
#include "../npc/d/bingqi_shigun.h"
#include "../npc/d/bingqi_shijian.h"
#include "../npc/d/bingqi_shizhang.h"
#include "../npc/d/bingqi_oldouyezi.h"

//baituo
#include "../npc/d/baituo_ouyangfeng.h"
#include "../npc/d/baituo_ouyangke.h"
#include "../npc/d/baituo_shangguanyun.h"
#include "../npc/d/baituo_xieyan.h"
#include "../npc/d/baituo_zhaohe.h"
//dali

#include "../npc/d/dali_hutaseng1.h"

#include "../npc/d/dali_ben.h"
#include "../npc/d/dali_bencan.h"
#include "../npc/d/dali_benchen.h"
#include "../npc/d/dali_benguan.h"
#include "../npc/d/dali_benxiang.h"
#include "../npc/d/dali_benyin.h"
#include "../npc/d/dali_kurong.h"

#include "../npc/d/dali_datusi.h"
#include "../npc/d/dali_duanerguan.h"
#include "../npc/d/dali_oldduanerguan.h"
#include "../npc/d/dali_laoniansengren.h"
#include "../npc/d/dali_muguniang.h"
#include "../npc/d/dali_saodiseng.h"
#include "../npc/d/dali_wusantong.h"
#include "../npc/d/dali_xiaoshami.h"
#include "../npc/d/dali_zhuziliu.h"

//gaibang
#include "../npc/d/gaibang_shitianjing.h"
#include "../npc/d/gaibang_wudunlu.h"
#include "../npc/d/gaibang_wuliusuo.h"
#include "../npc/d/gaibang_wuxiuwen.h"
#include "../npc/d/gaibang_xiaofeng.h"
#include "../npc/d/gaibang_xiaojindai.h"
//emei
#include "../npc/d/emei_yanziyi.h"

//黑木崖
#include "../std/zushi.h"
#include "../npc/d/heimuya_dongfang.h"
#include "../npc/d/heimuya_fansong.h"
#include "../npc/d/heimuya_heiyiren.h"
#include "../npc/d/heimuya_huangbailiu.h"
#include "../npc/d/heimuya_jiabaoyu.h"
#include "../npc/d/heimuya_jiaotu.h"
#include "../npc/d/heimuya_renwuyue.h"
//恒山
#include "../npc/d/hengshan_dingjingshitai.h"
#include "../npc/d/hengshan_dingyueshitai.h"
#include "../npc/d/hengshan_qinjuan.h"
#include "../npc/d/hengshan_yihe.h"
#include "../npc/d/hengshan_yilin.h"
#include "../npc/d/hengshan_yiqing.h"
#include "../npc/d/hengshan_yiwen.h"
#include "../npc/d/hengshan_yizhi.h"
#include "../npc/d/hengshan_zhengyue.h"
//衡山
#include "../npc/d/hengshan1_liucao.h"
#include "../npc/d/hengshan1_liuhong.h"
#include "../npc/d/hengshan1_luduku.h"
#include "../npc/d/hengshan1_moju.h"
#include "../npc/d/hengshan1_wuweiyi.h"
#include "../npc/d/hengshan1_xiangguonian.h"
//红花
#include "../npc/d/honghua_changsanmei.h"
#include "../npc/d/honghua_changyimei.h"
#include "../npc/d/honghua_chenjuyang.h"
#include "../npc/d/honghua_honghua1.h"
#include "../npc/d/honghua_huahuatong.h"
#include "../npc/d/honghua_huoxindong.h"
#include "../npc/d/honghua_lilishi.h"
#include "../npc/d/honghua_lubinghua.h"
#include "../npc/d/honghua_shitailong.h"
#include "../npc/d/honghua_weihua.h"
#include "../npc/d/honghua_wukueilai.h"
#include "../npc/d/honghua_xinjian.h"
#include "../npc/d/honghua_xudixuan.h"
#include "../npc/d/honghua_yanglihuei.h"
#include "../npc/d/honghua_zhangjin.h"
#include "../npc/d/honghua_zhangshugen.h"
//yinchang
#include "../npc/d/yinchang_ailaozhe.h"
#include "../npc/d/yinchang_ding.h"
#include "../npc/d/yinchang_due.h"
#include "../npc/d/yinchang_dujie.h"
#include "../npc/d/yinchang_dunan.h"
#include "../npc/d/yinchang_feng.h"
#include "../npc/d/yinchang_gaolaozhe.h"
#include "../npc/d/yinchang_hong.h"
#include "../npc/d/yinchang_hongantong.h"
#include "../npc/d/yinchang_huang.h"
#include "../npc/d/yinchang_jiumozhi.h"
#include "../npc/d/yinchang_miejue.h"
#include "../npc/d/yinchang_ouyangfeng.h"
#include "../npc/d/yinchang_suquan.h"
#include "../npc/d/yinchang_xuedao.h"
#include "../npc/d/yinchang_yideng.h"
#include "../npc/d/yinchang_zhang.h"
#include "../npc/d/yinchang_zhou.h"
//shenjian
#include "../npc/d/shenjian_li4.h"
#include "../npc/d/shenjian_qian2.h"
#include "../npc/d/shenjian_sun3.h"
#include "../npc/d/shenjian_wang8.h"
#include "../npc/d/shenjian_wu6.h"
#include "../npc/d/shenjian_zhao1.h"
#include "../npc/d/shenjian_zhaomin.h"
#include "../npc/d/shenjian_zheng7.h"
#include "../npc/d/shenjian_zhou5.h"
//shenlong
#include "../npc/d/shenlong.h"
#include "../npc/d/shenlong_boy2.h"
#include "../npc/d/shenlong_boy3.h"
#include "../npc/d/shenlong_boy4.h"
#include "../npc/d/shenlong_fangyi.h"
//#include "../npc/d/shenlong_hong.h"
#include "../npc/d/shenlong_mujianping.h"
//#include "../npc/d/shenlong_su.h"
#include "../npc/d/shenlong_yunsumei.h"
#include "../npc/d/shenlong_zhang3.h"
//taohuadao
#include "../npc/d/taohuadao_binu.h"
#include "../npc/d/taohuadao_huang.h"
#include "../npc/d/taohuadao_killere.h"
#include "../npc/d/taohuadao_mei.h"
#include "../npc/d/taohuadao_shoumu.h"
#include "../npc/d/taohuadao_yan.h"
//wudang
#include "../npc/d/wudang_dingdang.h"
#include "../npc/d/wudang_killers.h"
#include "../npc/d/wudang_laodaoshi.h"
#include "../npc/d/wudang_lisi.h"
#include "../npc/d/wudang_liyuanzhi.h"
#include "../npc/d/wudang_lu.h"
#include "../npc/d/wudang_maliu.h"
#include "../npc/d/wudang_qu.h"
#include "../npc/d/wudang_shang.h"
#include "../npc/d/wudang_shuanger.h"
#include "../npc/d/wudang_tongbw.h"
#include "../npc/d/wudang_wangcheng.h"
#include "../npc/d/wudang_wangwu.h"
#include "../npc/d/wudang_wuchen.h"
#include "../npc/d/wudang_xiaosong.h"
#include "../npc/d/wudang_xuxuetin.h"
#include "../npc/d/wudang_yuhuan.h"
#include "../npc/d/wudang_zhangsan.h"
#include "../npc/d/wudang_zhao.h"
//wuguan
#include "../npc/d/wuguan_chenhu.h"
#include "../npc/d/wuguan_liuhongying.h"
#include "../npc/d/wuguan_longquan.h"
#include "../npc/d/wuguan_mawude.h"
#include "../npc/d/wuguan_xiaofei.h"

//xingxiu
#include "../npc/d/xingxiu_boshou.h"
#include "../npc/d/xingxiu_caihua.h"
//#include "../npc/d/xingxiu_dujiangshi.h"
#include "../npc/d/xingxiu_gushou.h"
#include "../npc/d/xingxiu_haoshou.h"
#include "../npc/d/xingxiu_killerw.h"
#include "../npc/d/xingxiu_nan.h"
//xueshan
#include "../npc/d/xueshan_baishou.h"
#include "../npc/d/xueshan_jiaowenqi.h"
#include "../npc/d/xueshan_lama.h"
#include "../npc/d/xueshan_sengbing1.h"
#include "../npc/d/xueshan_tengyilei.h"
//yanziwu
#include "../npc/d/yanziwu_abi.h"
#include "../npc/d/yanziwu_azhu.h"
//huashan
#include "../npc/d/huashan_linghu.h"
#include "../npc/d/huashan_shuidai.h"
#include "../npc/d/huashan_wugen.h"
#include "../npc/d/huashan_yuzhenzi.h"
//lingjiu

#include "../npc/d/lingjiu_chengqs.h"
#include "../npc/d/lingjiu_fumy.h"
#include "../npc/d/lingjiu_jiuyi.h"
//#include "../npc/d/lingjiu_jujian.h"
//#include "../npc/d/lingjiu_lanjian.h"
#include "../npc/d/lingjiu_lisao.h"
//#include "../npc/d/lingjiu_lu.h"
#include "../npc/d/lingjiu_nvlang.h"
#include "../npc/d/lingjiu_shisao.h"
#include "../npc/d/lingjiu_songshu.h"
#include "../npc/d/lingjiu_wulaoda.h"
#include "../npc/d/lingjiu_yupopo.h"
#include "../npc/d/lingjiu_zhang.h"
//#include "../npc/d/lingjiu_zhujian.h"

//meizhuang
#include "../npc/d/meizhuang_danqingsheng.h"
#include "../npc/d/meizhuang_ding.h"
#include "../npc/d/meizhuang_heibaizi.h"
#include "../npc/d/meizhuang_huangzhonggong.h"
#include "../npc/d/meizhuang_tubiweng.h"

//shaolin
#include "../npc/d/shaolin_an.h"
#include "../npc/d/shaolin_aobai.h"
#include "../npc/d/shaolin_chuyuan.h"
#include "../npc/d/shaolin_dabei.h"
#include "../npc/d/shaolin_daoseng.h"
#include "../npc/d/shaolin_gaoyanch.h"
#include "../npc/d/shaolin_huogong.h"
#include "../npc/d/shaolin_killern.h"
#include "../npc/d/shaolin_longjun.h"
#include "../npc/d/shaolin_meng.h"
#include "../npc/d/shaolin_monk.h"
#include "../npc/d/shaolin_seng.h"
#include "../npc/d/shaolin_shenzhao.h"
#include "../npc/d/shaolin_shi.h"
#include "../npc/d/shaolin_xiaolu.h"
#include "../npc/d/shaolin_xutianch.h"
#include "../npc/d/shaolin_zhang1.h"
#include "../npc/d/shaolin_zhang2.h"
#include "../npc/d/shaolin_zhou.h"
#include "../npc/d/shaolin_zhouyi.h"

#include "../npc/d/zaixiang_zhang.h"		//张首辅	秦波 2002、5、23
//灵鹫任务中NPC
#include "../npc/d/lj/lj_shangtugong.h"		//商土公	秦波 2002、6、1
#include "../npc/d/lj/lj_honghuangzi.h"		//洪荒子	秦波 2002、6、3
#include "../npc/d/lj/lj_hajuba.h"				//哈巨霸	秦波 2002、6、3
#include "../npc/d/lj/lj_yudafu.h"				//郁达夫	秦波 2002、6、3
#include "../npc/d/lj/lj_xiaoyulaoren.h"		//笑语老人	秦波 2002、6、4
#include "../npc/d/lj/lj_shuxia.h"				//灵鹫宫属下	秦波 2002、6、5
#include "../npc/d/lj/lj_shuxia1.h"				//灵鹫宫属下	秦波 2002、6、5
#include "../npc/d/lj/lj_tielao.h"				//天山铁姥	秦波 2002、6、7

#include "../npc/d/lj/lj_wulaoda.h"		
#include "../npc/d/lj/lj_duanmufang.h"		
#include "../npc/d/lj/lj_ganshuangqing.h"		
#include "../npc/d/lj/lj_hefueren.h"				
#include "../npc/d/lj/lj_hedongzhu.h"				
#include "../npc/d/lj/lj_andongzhu.h"		
#include "../npc/d/lj/lj_qingdaozhu.h"				
#include "../npc/d/lj/lj_qudaozhu.h"		
#include "../npc/d/lj/lj_yundaozhu.h"		
#include "../npc/d/lj/lj_zhuyadaguai.h"
#include "../npc/d/lj/lj_zhuyaerguai.h"
#include "../npc/d/lj/lj_liqiuhen.h"

#include "../npc/d/lj/lj_beixiaofeng.h"
#include "../npc/d/lj/lj_chengjialu.h"
#include "../npc/d/lj/lj_diyun.h"
#include "../npc/d/lj/lj_duaer.h"
#include "../npc/d/lj/lj_gouzhazhong.h"
#include "../npc/d/lj/lj_hufei.h"
#include "../npc/d/lj/lj_linhugongzi.h"
#include "../npc/d/lj/lj_nanmonong.h"
#include "../npc/d/lj/lj_wanerlaqi.h"
#include "../npc/d/lj/lj_zhangsanfeng.h"
#include "../npc/d/lj/lj_zhoubotong.h"

#include "../npc/d/lj/lj_linmuming.h"
#include "../npc/d/lj/lj_ludinggong.h"
#include "../npc/d/lj/lj_miaorenhuang.h"
#include "../npc/d/lj/lj_yuanchenzhi.h"
#include "../npc/d/lj/lj_taijian.h"
#include "../npc/d/lj/lj_gongnv.h"
#include "../npc/d/lj/lj_gongnv1.h"
#include "../npc/d/lj/lj_yinchuan.h"
//逍遥任务中NPC
#include "../npc/d/xy/xy_shiganlu.h"
#include "../npc/d/xy/xy_limuou.h"
#include "../npc/d/xy/xy_fanqiansuei.h"
#include "../npc/d/xy/xy_licanghai.h"
#include "../npc/d/xy/xy_tielao.h"
#include "../npc/d/xy/xy_tielao1.h"
#include "../npc/d/xy/xy_licanghai1.h"
#include "../npc/d/xy/xy_liqiouheng.h"
#include "../npc/d/xy/xy_liqiouheng1.h"
#include "../npc/d/xy/xy_liqiouheng2.h"
#include "../npc/d/xy/xy_liqiouheng3.h"
#include "../npc/d/xy/xy_xiaoyaozi.h"
#include "../npc/d/xy/xy_xiaoyaozi1.h"
#include "../npc/d/xy/xy_xiaoyaozi2.h"
#include "../npc/d/xy/xy_xiaoyaonv.h"
#include "../npc/d/xy/xy_xuanwu1.h"
#include "../npc/d/xy/xy_xuanwu2.h"
#include "../npc/d/xy/xy_xuanwu3.h"
#include "../npc/d/xy/xy_xuanwu4.h"
#include "../npc/d/xy/xy_xuanwu5.h"
#include "../npc/d/xy/xy_xuanwu6.h"
#include "../npc/d/xy/xy_xuanwu7.h"
#include "../npc/d/xy/xy_qinglong1.h"
#include "../npc/d/xy/xy_qinglong2.h"
#include "../npc/d/xy/xy_qinglong3.h"
#include "../npc/d/xy/xy_qinglong4.h"
#include "../npc/d/xy/xy_qinglong5.h"
#include "../npc/d/xy/xy_qinglong6.h"
#include "../npc/d/xy/xy_qinglong7.h"
#include "../npc/d/xy/xy_baihu1.h"
#include "../npc/d/xy/xy_baihu2.h"
#include "../npc/d/xy/xy_baihu3.h"
#include "../npc/d/xy/xy_baihu4.h"
#include "../npc/d/xy/xy_baihu5.h"
#include "../npc/d/xy/xy_baihu6.h"
#include "../npc/d/xy/xy_baihu7.h"
#include "../npc/d/xy/xy_zhuque1.h"
#include "../npc/d/xy/xy_zhuque2.h"
#include "../npc/d/xy/xy_zhuque3.h"
#include "../npc/d/xy/xy_zhuque4.h"
#include "../npc/d/xy/xy_zhuque5.h"
#include "../npc/d/xy/xy_zhuque6.h"
#include "../npc/d/xy/xy_zhuque7.h"
#include "../npc/d/xy/xy_shikong.h"
#include "../npc/d/xy/xy_qingfeng.h"
#include "../npc/d/xy/xy_shiwushi.h"
#include "../npc/d/xy/xy_qiaozhongren.h"
#include "../npc/d/xy/xy_ouyangke.h"

#include "../npc/tdh/tdh_chen.h"	//天地会-陈近南

//小宝任务中NPC
#include "../npc/d/xiaobao/pub_xiaogueizi.h"	//韦小宝
#include "../npc/d/xiaobao/pub_shiwei1.h"		//贴身侍卫
#include "../npc/d/xiaobao/pub_jianning.h"		//建宇公主
#include "../npc/d/xiaobao/baishu.h"			//小白鼠
#include "../npc/d/xiaobao/qishe.h"				//蕲蛇
#include "../npc/d/xiaobao/wei_su.h"			//苏情
#include "../npc/d/xiaobao/pub_shiwei3.h"		//阿可侍卫
#include "../npc/d/xiaobao/wei_canbing.h"		//吴三桂军残余部众
#include "../npc/d/xiaobao/wei_canjiang.h"		//吴三桂军残将
#include "../npc/d/xiaobao/wei_ake.h"			//阿可
#include "../npc/d/xiaobao/wei_jhlz.h"			//江湖郎中
#include "../npc/d/xiaobao/wei_baiyu.h"			//白鱼
#include "../npc/d/xiaobao/wei_mujianping.h"	//沐剑屏
#include "../npc/d/xiaobao/wei_zengrou.h"		//曾雪
#include "../npc/d/xiaobao/wei_nixiang.h"		//泥像
#include "../npc/d/xiaobao/wei_jiguanren.h"		//机关人
#include "../npc/d/xiaobao/wei_yilian.h"		//依恋
#include "../npc/d/xiaobao/wei_fang.h"			//方瑜
#include "../npc/d/xiaobao/wei_mengmian.h"		//蒙面人
#include "../npc/d/xiaobao/wei_shuanger.h"		//霜儿

//日月任务中NPC
#include "../npc/d/ry/heimuya_jiaotu1.h"
#include "../npc/d/ry/heimuya_jiaotu2.h"
#include "../npc/d/ry/heimuya_jiaotu3.h"
#include "../npc/d/ry/heimuya_jiaotu4.h"
#include "../npc/d/ry/heimuya_jiaotu5.h"
#include "../npc/d/ry/heimuya_jiaotu6.h"
#include "../npc/d/ry/ry_dongfang.h"

//北京任务中NPC
#include "../npc/d/bj/pub_songbing1.h"
#include "../npc/d/bj/pub_songjiang1.h"
#include "../npc/d/bj/bj_hunaliangjin.h"
#include "../npc/d/bj/bj_fengziqiang.h"
#include "../npc/d/bj/bj_wangqiuren.h"

#include "../npc/d/bj/bj_hao.h"
#include "../npc/d/bj/bj_liu.h"
#include "../npc/d/bj/bj_ma.h"
#include "../npc/d/bj/bj_qiu.h"
#include "../npc/d/bj/bj_sun.h"
#include "../npc/d/bj/bj_tan.h"
#include "../npc/d/bj/bj_wangchuyi.h"

#include "../npc/d/bj/bj_zhangfang.h"

//新手任务NPC
#include "../npc/d/pub_caozhangguei.h"

CNpc * LoadNPC_pub5(string npc_name)
{
	CNpc * t = NULL;


	//兵器师傅
	if(npc_name == "bingqi_tianjianshi")
		t = new CNBingQi_ouyezi();
	else if(npc_name == "bingqi_shizhang")
		t = new CNBingQi_shizhang();

	else if(npc_name == "wanjie_foolmaster")
		t = new CNwanjie_foolmaster();
	else if(npc_name == "monster1")
			t = new CNmonster1();
	else if(npc_name == "monster2")
			t = new CNmonster2();
	else if(npc_name == "monster3")
			t = new CNmonster3();
	else if(npc_name == "monster4")
			t = new CNmonster4();
	else if(npc_name == "monster5")
			t = new CNmonster5();
	else if(npc_name == "monster6")
			t = new CNmonster6();/*
	else if(npc_name == "monster7")
			t = new CNmonster7();*/
	
	else if(npc_name == "bingqi_shijian")
		t = new CNBingQi_shijian();
	else if(npc_name == "bingqi_shigun")
		t = new CNBingQi_shigun();
	else if(npc_name == "bingqi_shidao")
		t = new CNBingQi_shidao();
	else if(npc_name == "bingqi_oldouyezi")
		t = new CNBingQi_oldouyezi();
	else if(npc_name == "bingqi_shibian")
		t = new CNBingQi_shibian();
	else if(npc_name == "bingqi_shichui")
		t = new CNBingQi_shichui();
	//baituo
	if(npc_name == "baituo_zhaohe")
		t = new CNBaiTuo_zhaohe();
	else if(npc_name == "baituo_xieyan")
		t = new CNBaiTuo_xieyan();
	else if(npc_name == "baituo_shangguanyun")
		t = new CNBaiTuo_shangguanyun();
	else if(npc_name == "baituo_ouyangke")
		t = new CNBaiTuo_ouyangke();
	else if(npc_name == "baituo_ouyangfeng")
		t = new CNBaiTuo_ouyangfeng();
	//大理
	if(npc_name == "dali_zhuziliu")
		t = new CNDaLi_zhuziliu();
	else if(npc_name == "dali_xiaoshami")
		t = new CNDaLi_xiaoshami();
	else if(npc_name == "dali_wusantong")
		t = new CNDaLi_wusantong();
	else if(npc_name == "dali_saodiseng")
		t = new CNDaLi_saodiseng();
	else if(npc_name == "dali_oldduanerguan")
		t = new CNDaLi_oldduanerguan();
	else if(npc_name == "dali_muguniang")
		t = new CNDaLi_muguniang();
	else if(npc_name == "dali_laoniansengren")
		t = new CNDaLi_laoniansengren();
	else if(npc_name == "dali_kurong")
		t = new CNDaLi_kurong();
	else if(npc_name == "dali_hutaseng1")
		t = new CNDaLi_hutaseng1();
	else if(npc_name == "dali_duanerguan")
		t = new CNDaLi_duanerguan();
	else if(npc_name == "dali_bencan")
		t = new CNDaLi_bencan();
	else if(npc_name == "dali_benxiang")
		t = new CNDaLi_benxiang();
	else if(npc_name == "dali_benguan")
		t = new CNDaLi_benguan();
	else if(npc_name == "dali_benchen")
		t = new CNDaLi_benchen();
	else if(npc_name == "dali_benyin")
		t = new CNDaLi_benyin();
	else if(npc_name == "dali_datusi")
		t = new CNDaLi_datusi();

	if(npc_name == "gaibang_wuliusuo")
		t = new CNgaibang_wuliusuo();
	else if(npc_name == "gaibang_wudunlu")
		t = new CNgaibang_wudunlu();
	else if(npc_name == "gaibang_shitianjing")
		t = new CNgaibang_shitianjing();
	else if(npc_name == "gaibang_wuxiuwen")
		t = new CNgaibang_wuxiuwen();
	else if(npc_name == "gaibang_xiaofeng")
		t = new CNgaibang_xiaofeng();
	else if(npc_name == "gaibang_xiaojindai")
		t = new CNgaibang_xiaojindai();

	//蛾眉
	else if(npc_name == "emei_yanziyi")
		t = new CNEMei_yanziyi();
		//黑木崖
	if(npc_name == "heimuya_renwuyue")
		t = new CNHeiMUYa_renwuyue();
	else if(npc_name == "heimuya_jiaotu")
		t = new CNHeiMUYa_jiaotu();
	else if(npc_name == "heimuya_jiabaoyu")
		t = new CNHeiMUYa_jiabaoyu();
	else if(npc_name == "heimuya_huangbailiu")
		t = new CNHeiMUYa_huangbailiu();
	else if(npc_name == "heimuya_dongfang")
		t = new CNHeiMUYa_dongfang();
	else if(npc_name == "heimuya_fansong")
		t = new CNHeiMUYa_fansong();
	else if(npc_name == "heimuya_heiyiren")
		t = new CNHeiMUYa_heiyiren();
//恒山
	else if(npc_name == "hengshan_zhengyue")
		t = new CNHengShan_zhengyue();
	else if(npc_name == "hengshan_yizhi")
		t = new CNHengShan_yizhi();
	else if(npc_name == "hengshan_yiwen")
		t = new CNHengShan_yiwen();
	else if(npc_name == "hengshan_yiqing")
		t = new CNHengShan_yiqing();
	else if(npc_name == "hengshan_yilin")
		t = new CNHengShan_yilin();
	else if(npc_name == "hengshan_dingjingshitai")
		t = new CNHengShan_dingjingshitai();
	else if(npc_name == "hengshan_qinjuan")
		t = new CNHengShan_qinjuan();
	else if(npc_name == "hengshan_dingyueshitai")
		t = new CNHengShan_dingyueshitai();
	else if(npc_name == "hengshan_yihe")
		t = new CNHengShan_yihe();
//衡山
	else if(npc_name == "hengshan1_xiangguonian")
		t = new CNHengShan1_xiangguonian();
	else if(npc_name == "hengshan1_wuweiyi")
		t = new CNHengShan1_wuweiyi();
	else if(npc_name == "hengshan1_moju")
		t = new CNHengShan1_moju();
	else if(npc_name == "hengshan1_luduku")
		t = new CNHengShan1_luduku();
	else if(npc_name == "hengshan1_liucao")
		t = new CNHengShan1_liucao();
	else if(npc_name == "hengshan1_liuhong")
		t = new CNHengShan1_liuhong();
//红花
	else if(npc_name == "honghua_zhangshugen")
		t = new CNHongHua_zhangshugen();
	else if(npc_name == "honghua_zhangjin")
		t = new CNHongHua_zhangjin();
	else if(npc_name == "honghua_yanglihuei")
		t = new CNHongHua_yanglihuei();
	else if(npc_name == "honghua_xudixuan")
		t = new CNHongHua_xudixuan();
	else if(npc_name == "honghua_xinjian")
		t = new CNHongHua_xinjian();
	else if(npc_name == "honghua_changsanmei")
		t = new CNHongHua_changsanmei();
	else if(npc_name == "honghua_weihua")
		t = new CNHongHua_weihua();
	else if(npc_name == "honghua_shitailong")
		t = new CNHongHua_shitailong();
	else if(npc_name == "honghua_lubinghua")
		t = new CNHongHua_lubinghua();
	else if(npc_name == "honghua_lilishi")
		t = new CNHongHua_lilishi();
	else if(npc_name == "honghua_huoxindong")
		t = new CNHongHua_huoxindong();
	else if(npc_name == "honghua_huahuatong")
		t = new CNHongHua_huahuatong();
	else if(npc_name == "honghua_honghua1")
		t = new CNHongHua_honghua1();
	else if(npc_name == "honghua_chenjuyang")
		t = new CNHongHua_chenjuyang();
	else if(npc_name == "honghua_changyimei")
		t = new CNHongHua_changyimei();
	else if(npc_name == "honghua_wukueilai")
		t = new CNHongHua_wukueilai();

	//yinchang
	if(npc_name == "yinchang_ailaozhe")
		t = new CNyinchang_ailaozhe();
	else if(npc_name == "yinchang_ding")
		t = new CNyinchang_ding();
	else if(npc_name == "yinchang_due")
		t = new CNyinchang_due();
	else if(npc_name == "yinchang_dujie")
		t = new CNyinchang_dujie();
	else if(npc_name == "yinchang_dunan")
		t = new CNyinchang_dunan();
	else if(npc_name == "yinchang_feng")
		t = new CNyinchang_feng();
	else if(npc_name == "yinchang_gaolaozhe")
		t = new CNyinchang_gaolaozhe();
	else if(npc_name == "yinchang_hong")
		t = new CNyinchang_hong();
	else if(npc_name == "yinchang_hongantong")
		t = new CNyinchang_hongantong();
	else if(npc_name == "yinchang_huang")
		t = new CNyinchang_huang();
	else if(npc_name == "yinchang_jiumozhi")
		t = new CNyinchang_jiumozhi();
	else if(npc_name == "yinchang_miejue")
		t = new CNyinchang_miejue();
	else if(npc_name == "yinchang_ouyangfeng")
		t = new CNyinchang_ouyangfeng();
	else if(npc_name == "yinchang_suquan")
		t = new CNyinchang_suquan();
	else if(npc_name == "yinchang_xuedao")
		t = new CNyinchang_xuedao();
	else if(npc_name == "yinchang_yideng")
		t = new CNyinchang_yideng();
	else if(npc_name == "yinchang_zhang")
		t = new CNyinchang_zhang();
	else if(npc_name == "yinchang_zhou")
		t = new CNyinchang_zhou();
//shenjian
	else if(npc_name == "shenjian_li4")
		t = new CNshenjian_li4();
	else if(npc_name == "shenjian_qian2")
		t = new CNshenjian_qian2();
	else if(npc_name == "shenjian_sun3")
		t = new CNshenjian_sun3();
	else if(npc_name == "shenjian_wang8")
		t = new CNshenjian_wang8();
	else if(npc_name == "shenjian_wu6")
		t = new CNshenjian_wu6();
	else if(npc_name == "shenjian_zhao1")
		t = new CNshenjian_zhao1();
	else if(npc_name == "shenjian_zhaomin")
		t = new CNshenjian_zhaomin();
	else if(npc_name == "shenjian_zheng7")
		t = new CNshenjian_zheng7();
	else if(npc_name == "shenjian_zhou5")
		t = new CNshenjian_zhou5();
//shenlong
	else if(npc_name == "shenlong_boy2")
		t = new CNshenlong_boy2();
	else if(npc_name == "shenlong_boy3")
		t = new CNshenlong_boy3();
	else if(npc_name == "shenlong_boy4")
		t = new CNshenlong_boy4();
	else if(npc_name == "shenlong_fangyi")
		t = new CNshenlong_fangyi();
//	else if(npc_name == "shenlong_hong")
//		t = new CNshenlong_hong();
	else if(npc_name == "shenlong_mujianping")
		t = new CNshenlong_mujianping();
	else if(npc_name == "shenlong_yunsumei")
		t = new CNshenlong_yunsumei();
	else if(npc_name == "shenlong_zhang3")
		t = new CNshenlong_zhang3();
//taohuadao
	else if(npc_name == "taohuadao_binu")
		t = new CNtaohuadao_binu();
	else if(npc_name == "taohuadao_huang")
		t = new CNtaohuadao_huang();
	else if(npc_name == "taohuadao_killere")
		t = new CNtaohuadao_killere();
	else if(npc_name == "taohuadao_mei")
		t = new CNtaohuadao_mei();
	else if(npc_name == "taohuadao_shoumu")
		t = new CNtaohuadao_shoumu();
	else if(npc_name == "taohuadao_yan")
		t = new CNtaohuadao_yan();
//wudang
	else if(npc_name == "wudang_dingdang")
		t = new CNwudang_dingdang();
	else if(npc_name == "wudang_killers")
		t = new CNwudang_killers();
	else if(npc_name == "wudang_laodaoshi")
		t = new CNwudang_laodaoshi();
	else if(npc_name == "wudang_lisi")
		t = new CNwudang_lisi();
	else if(npc_name == "wudang_liyuanzhi")
		t = new CNwudang_liyuanzhi();
	else if(npc_name == "wudang_lu")
		t = new CNwudang_lu();
	else if(npc_name == "wudang_maliu")
		t = new CNwudang_maliu();
	else if(npc_name == "wudang_qu")
		t = new CNwudang_qu();
	else if(npc_name == "wudang_shang")
		t = new CNwudang_shang();
	else if(npc_name == "wudang_shuanger")
		t = new CNwudang_shuanger();
	else if(npc_name == "wudang_tongbw")
		t = new CNwudang_tongbw();
	else if(npc_name == "wudang_wangcheng")
		t = new CNwudang_wangcheng();
	else if(npc_name == "wudang_wangwu")
		t = new CNwudang_wangwu();
	else if(npc_name == "wudang_wuchen")
		t = new CNwudang_wuchen();
	else if(npc_name == "wudang_xiaosong")
		t = new CNwudang_xiaosong();
 	else if(npc_name == "wudang_xuxuetin")
		t = new CNwudang_xuxuetin();
	else if(npc_name == "wudang_yuhuan")
		t = new CNwudang_yuhuan();
	else if(npc_name == "wudang_zhangsan")
		t = new CNwudang_zhangsan();
	else if(npc_name == "wudang_zhao")
		t = new CNwudang_zhao();
//wuguan
	else if(npc_name == "wuguan_chenhu")
		t = new CNwuguan_chenhu();
	else if(npc_name == "wuguan_liuhongying")
		t = new CNwuguan_liuhongying();
	else if(npc_name == "wuguan_longquan")
		t = new CNwuguan_longquan();
	else if(npc_name == "wuguan_mawude")
		t = new CNwuguan_mawude();
	else if(npc_name == "wuguan_xiaofei")
		t = new CNwuguan_xiaofei();

//xingxiu
	else if(npc_name == "xingxiu_boshou")
		t = new CNxingxiu_boshou();
	else if(npc_name == "xingxiu_caihua")
		t = new CNxingxiu_caihua();
//	else if(npc_name == "xingxiu_dujiangshi")
//		t = new CNxingxiu_dujiangshi();
	else if(npc_name == "xingxiu_gushou")
		t = new CNxingxiu_gushou();
	else if(npc_name == "xingxiu_haoshou")
		t = new CNxingxiu_haoshou();
	else if(npc_name == "xingxiu_killerw")
		t = new CNxingxiu_killerw();
	else if(npc_name == "xingxiu_nan")
		t = new CNxingxiu_nan();
//xueshan
	else if(npc_name == "xueshan_baishou")
		t = new CNxueshan_baishou();
	else if(npc_name == "xueshan_jiaowenqi")
		t = new CNxueshan_jiaowenqi();
	else if(npc_name == "xueshan_lama")
		t = new CNxueshan_lama();
	else if(npc_name == "xueshan_sengbing1")
		t = new CNxueshan_sengbing1();
	else if(npc_name == "xueshan_tengyilei")
		t = new CNxueshan_tengyilei();
//yanziwu
	else if(npc_name == "yanziwu_abi")
		t = new CNyanziwu_abi();
	else if(npc_name == "yanziwu_azhu")
		t = new CNyanziwu_azhu();
//huashan
	else if(npc_name == "huashan_linghu")
		t = new CNhuashan_linghu();
	else if(npc_name == "huashan_shuidai")
		t = new CNhuashan_shuidai();
	else if(npc_name == "huashan_wugen")
		t = new CNhuashan_wugen();
	else if(npc_name == "huashan_yuzhenzi")
		t = new CNhuashan_yuzhenzi();

	//lingjiu
	if(npc_name == "lingjiu_chengqs")
		t = new CNlingjiu_chengqs();
	else if(npc_name == "lingjiu_fumy")
		t = new CNlingjiu_fumy();
	else if(npc_name == "lingjiu_jiuyi")
		t = new CNlingjiu_jiuyi();
/*	else if(npc_name == "lingjiu_jujian")
		t = new CNlingjiu_jujian();
	else if(npc_name == "lingjiu_lanjian")
		t = new CNlingjiu_lanjian();*/
	else if(npc_name == "lingjiu_lisao")
		t = new CNlingjiu_lisao();
/*	else if(npc_name == "lingjiu_lu")
		t = new CNlingjiu_lu();*/
	else if(npc_name == "lingjiu_nvlang")
		t = new CNlingjiu_nvlang();
	else if(npc_name == "lingjiu_shisao")
		t = new CNlingjiu_shisao();
 	else if(npc_name == "lingjiu_songshu")
		t = new CNlingjiu_songshu();
	else if(npc_name == "lingjiu_wulaoda")
		t = new CNlingjiu_wulaoda();
	else if(npc_name == "lingjiu_yupopo")
		t = new CNlingjiu_yupopo();
	else if(npc_name == "lingjiu_zhang")
		t = new CNlingjiu_zhang();
/*	else if(npc_name == "lingjiu_zhujian")
		t = new CNlingjiu_zhujian();*/
//meizhuang
	else if(npc_name == "meizhuang_danqingsheng")
		t = new CNmeizhuang_danqingsheng();
	else if(npc_name == "meizhuang_ding")
		t = new CNmeizhuang_ding();
	else if(npc_name == "meizhuang_heibaizi")
		t = new CNmeizhuang_heibaizi();
	else if(npc_name == "meizhuang_huangzhonggong")
		t = new CNmeizhuang_huangzhonggong();
	else if(npc_name == "meizhuang_tubiweng")
		t = new CNmeizhuang_tubiweng();

//shaolin
	else if(npc_name == "shaolin_an")
		t = new CNshaolin_an();
	else if(npc_name == "shaolin_aobai")
		t = new CNshaolin_aobai();
	else if(npc_name == "shaolin_chuyuan")
		t = new CNshaolin_chuyuan();
	else if(npc_name == "shaolin_dabei")
		t = new CNshaolin_dabei();
	else if(npc_name == "shaolin_daoseng")
		t = new CNshaolin_daoseng();
	else if(npc_name == "shaolin_gaoyanch")
		t = new CNshaolin_gaoyanch();
	else if(npc_name == "shaolin_huogong")
		t = new CNshaolin_huogong();
	else if(npc_name == "shaolin_killern")
		t = new CNshaolin_killern();
	else if(npc_name == "shaolin_longjun")
		t = new CNshaolin_longjun();
 	else if(npc_name == "shaolin_meng")
		t = new CNshaolin_meng();
	else if(npc_name == "shaolin_monk")
		t = new CNshaolin_monk();
	else if(npc_name == "shaolin_seng")
		t = new CNshaolin_seng();
	else if(npc_name == "shaolin_shenzhao")
		t = new CNshaolin_shenzhao();
	else if(npc_name == "shaolin_shi")
		t = new CNshaolin_shi();
	else if(npc_name == "shaolin_xiaolu")
		t = new CNshaolin_xiaolu();
	else if(npc_name == "shaolin_xutianch")
		t = new CNshaolin_xutianch();
	else if(npc_name == "shaolin_zhang1")
		t = new CNshaolin_zhang1();
	else if(npc_name == "shaolin_zhang2")
		t = new CNshaolin_zhang2();
	else if(npc_name == "shaolin_zhou")
		t = new CNshaolin_zhou();
	else if(npc_name == "shaolin_zhouyi")
		t = new CNshaolin_zhouyi();

	else if(npc_name == "hero_oho")
		t = new CNhero_oho();


	else if(npc_name == "zaixiang_zhang")
		t = new CNzaixiang_zhang();
	else if(npc_name == "lj_shangtugong")
		t = new CNlj_shangtugong();
	else if(npc_name == "lj_honghuangzi")
		t = new CNlj_honghuangzi();
	else if(npc_name == "lj_hajuba")
		t = new CNlj_hajuba();
	else if(npc_name == "lj_yudafu")
		t = new CNlj_yudafu();
	else if(npc_name == "lj_xiaoyulaoren")
		t = new CNlj_xiaoyulaoren();
	else if(npc_name == "lj_shuxia")
		t = new CNlj_shuxia();
	else if(npc_name == "lj_shuxia1")
		t = new CNlj_shuxia1();
	else if(npc_name == "lj_wulaoda")
		t = new CNlj_wulaoda();
	else if(npc_name == "lj_duanmufang")
		t = new CNlj_duanmufang();
	else if(npc_name == "lj_ganshuangqing")
		t = new CNlj_ganshuangqing();
	else if(npc_name == "lj_hefueren")
		t = new CNlj_hefueren();
	else if(npc_name == "lj_hedongzhu")
		t = new CNlj_hedongzhu();
	else if(npc_name == "lj_andongzhu")
		t = new CNlj_andongzhu();
	else if(npc_name == "lj_qingdaozhu")
		t = new CNlj_qingdaozhu();
	else if(npc_name == "lj_qudaozhu")
		t = new CNlj_qudaozhu();
	else if(npc_name == "lj_yundaozhu")
		t = new CNlj_yundaozhu();
	else if(npc_name == "lj_zhuyadaguai")
		t = new CNlj_zhuyadaguai();
	else if(npc_name == "lj_zhuyaerguai")
		t = new CNlj_zhuyaerguai();
	else if(npc_name == "lj_tielao")
		t = new CNlj_tielao();
	else if(npc_name == "lj_liqiuhen")
		t = new CNlj_liqiuhen();

	else if(npc_name == "lj_beixiaofeng")
		t = new CNlj_beixiaofeng();
	else if(npc_name == "lj_chengjialu")
		t = new CNlj_chengjialu();
	else if(npc_name == "lj_diyun")
		t = new CNlj_diyun();
	else if(npc_name == "lj_duaer")
		t = new CNlj_duaer();
	else if(npc_name == "lj_gouzhazhong")
		t = new CNlj_gouzhazhong();
	else if(npc_name == "lj_hufei")
		t = new CNlj_hufei();
	else if(npc_name == "lj_linhugongzi")
		t = new CNlj_linhugongzi();
	else if(npc_name == "lj_nanmonong")
		t = new CNlj_nanmonong();
	else if(npc_name == "lj_wanerlaqi")
		t = new CNlj_wanerlaqi();
	else if(npc_name == "lj_zhangsanfeng")
		t = new CNlj_zhangsanfeng();
	else if(npc_name == "lj_zhoubotong")
		t = new CNlj_zhoubotong();
	else if(npc_name == "lj_linmuming")
		t = new CNlj_linmuming();
	else if(npc_name == "lj_ludinggong")
		t = new CNlj_ludinggong();
	else if(npc_name == "lj_miaorenhuang")
		t = new CNlj_miaorenhuang();
	else if(npc_name == "lj_yuanchenzhi")
		t = new CNlj_yuanchenzhi();
	else if(npc_name == "lj_taijian")
		t = new CNlj_taijian();
	else if(npc_name == "lj_gongnv")
		t = new CNlj_gongnv();
	else if(npc_name == "lj_gongnv1")
		t = new CNlj_gongnv1();
	else if(npc_name == "lj_yinchuan")
		t = new CNlj_yinchuan();

	else if(npc_name == "tdh_chen")
		t = new CNtdh_chen();

	//逍遥任务
	else if(npc_name == "xy_shiganlu")
		t = new CNxy_shiganlu();
	else if(npc_name == "xy_limuou")
		t = new CNxy_limuou();
	else if(npc_name == "xy_fanqiansuei")
		t = new CNxy_fanqiansuei();
	else if(npc_name == "xy_licanghai")
		t = new CNxy_licanghai();
	else if(npc_name == "xy_tielao")
		t = new CNxy_tielao();
	else if(npc_name == "xy_tielao1")
		t = new CNxy_tielao1();
	else if(npc_name == "xy_licanghai1")
		t = new CNxy_licanghai1();
	else if(npc_name == "xy_liqiouheng")
		t = new CNxy_liqiouheng();
	else if(npc_name == "xy_liqiouheng1")
		t = new CNxy_liqiouheng1();
	else if(npc_name == "xy_liqiouheng2")
		t = new CNxy_liqiouheng2();
	else if(npc_name == "xy_liqiouheng3")
		t = new CNxy_liqiouheng3();
	else if(npc_name == "xy_xiaoyaozi")
		t = new CNxy_xiaoyaozi();
	else if(npc_name == "xy_xiaoyaozi1")
		t = new CNxy_xiaoyaozi1();
	else if(npc_name == "xy_xiaoyaozi2")
		t = new CNxy_xiaoyaozi2();
	else if(npc_name == "xy_xiaoyaonv")
		t = new CNxy_xiaoyaonv();
	else if(npc_name == "xy_xuanwu1")
		t = new CNxy_xuanwu1();
	else if(npc_name == "xy_xuanwu2")
		t = new CNxy_xuanwu2();
	else if(npc_name == "xy_xuanwu3")
		t = new CNxy_xuanwu3();
	else if(npc_name == "xy_xuanwu4")
		t = new CNxy_xuanwu4();
	else if(npc_name == "xy_xuanwu5")
		t = new CNxy_xuanwu5();
	else if(npc_name == "xy_xuanwu6")
		t = new CNxy_xuanwu6();
	else if(npc_name == "xy_xuanwu7")
		t = new CNxy_xuanwu7();
	else if(npc_name == "xy_qinglong1")
		t = new CNxy_qinglong1();
	else if(npc_name == "xy_qinglong2")
		t = new CNxy_qinglong2();
	else if(npc_name == "xy_qinglong3")
		t = new CNxy_qinglong3();
	else if(npc_name == "xy_qinglong4")
		t = new CNxy_qinglong4();
	else if(npc_name == "xy_qinglong5")
		t = new CNxy_qinglong5();
	else if(npc_name == "xy_qinglong6")
		t = new CNxy_qinglong6();
	else if(npc_name == "xy_qinglong7")
		t = new CNxy_qinglong7();
	else if(npc_name == "xy_baihu1")
		t = new CNxy_baihu1();
	else if(npc_name == "xy_baihu2")
		t = new CNxy_baihu2();
	else if(npc_name == "xy_baihu3")
		t = new CNxy_baihu3();
	else if(npc_name == "xy_baihu4")
		t = new CNxy_baihu4();
	else if(npc_name == "xy_baihu5")
		t = new CNxy_baihu5();
	else if(npc_name == "xy_baihu6")
		t = new CNxy_baihu6();
	else if(npc_name == "xy_baihu7")
		t = new CNxy_baihu7();
	else if(npc_name == "xy_zhuque1")
		t = new CNxy_zhuque1();
	else if(npc_name == "xy_zhuque2")
		t = new CNxy_zhuque2();
	else if(npc_name == "xy_zhuque3")
		t = new CNxy_zhuque3();
	else if(npc_name == "xy_zhuque4")
		t = new CNxy_zhuque4();
	else if(npc_name == "xy_zhuque5")
		t = new CNxy_zhuque5();
	else if(npc_name == "xy_zhuque6")
		t = new CNxy_zhuque6();
	else if(npc_name == "xy_zhuque7")
		t = new CNxy_zhuque7();
	else if(npc_name == "xy_shikong")
		t = new CNxy_shikong();
	else if(npc_name == "xy_qingfeng")
		t = new CNxy_qingfeng();
	else if(npc_name == "xy_shiwushi")
		t = new CNxy_shiwushi();
	else if(npc_name == "xy_qiaozhongren")
		t = new CNxy_qiaozhongren();
	else if(npc_name == "xy_ouyangke")
		t = new CNxy_ouyangke();
	
	//小宝任务
	else if(npc_name == "pub_xiaogueizi")
		t = new CNpub_xiaogueizi();
	else if(npc_name == "pub_shiwei1")
		t = new CNpub_shiwei1();
	else if(npc_name == "pub_jianning")
		t = new CNpub_jianning();
	else if(npc_name == "baishu")
		t = new CNbaishu();
	else if(npc_name == "qishe")
		t = new CNqishe();
	else if(npc_name == "wei_su")
		t = new CNwei_su();
	else if(npc_name == "pub_shiwei3")
		t = new CNpub_shiwei3();
	else if(npc_name == "wei_canbing")
		t = new CNwei_canbing();
	else if(npc_name == "wei_canjiang")
		t = new CNwei_canjiang();
	else if(npc_name == "wei_ake")
		t = new CNwei_ake();
	else if(npc_name == "wei_jhlz")
		t = new CNwei_jhlz();
	else if(npc_name == "wei_baiyu")
		t = new CNwei_baiyu();
	else if(npc_name == "wei_mujianping")
		t = new CNwei_mujianping();
	else if(npc_name == "wei_zengrou")
		t = new CNwei_zengrou();
	else if(npc_name == "wei_nixiang")
		t = new CNwei_nixiang();
	else if(npc_name == "wei_jiguanren")
		t = new CNwei_jiguanren();
	else if(npc_name == "wei_yilian")
		t = new CNwei_yilian();
	else if(npc_name == "wei_fang")
		t = new CNwei_fang();
	else if(npc_name == "wei_mengmian")
		t = new CNwei_mengmian();
	else if(npc_name == "wei_shuanger")
		t = new CNwei_shuanger();

	//北京任务
	else if(npc_name == "pub_songbing1")
		t = new CNpub_songbing1();
	else if(npc_name == "pub_songjiang1")
		t = new CNpub_songjiang1();
	else if(npc_name == "bj_hunaliangjin")
		t = new CNbj_hunaliangjin();
	else if(npc_name == "pub_caozhangguei")
		t = new CNpub_caozhangguei();
	else if(npc_name == "bj_fengziqiang")
		t = new CNbj_fengziqiang();
	else if(npc_name == "bj_hao")
		t=new CNbj_hao();
	else if(npc_name == "bj_liu")
		t=new CNbj_liu();
	else if(npc_name == "bj_ma")
		t=new CNbj_ma();
	else if(npc_name == "bj_qiu")
		t=new CNbj_qiu();
	else if(npc_name == "bj_sun")
		t=new CNbj_sun();
	else if(npc_name == "bj_tan")
		t=new CNbj_tan();
	else if(npc_name == "bj_wangchuyi")
		t=new CNbj_wangchuyi();
	else if(npc_name == "bj_wangqiuren")
		t=new CNbj_wangqiuren();

	else if(npc_name == "bj_zhangfang")
		t=new CNbj_zhangfang();

	//日月任务
	else if(npc_name == "heimuya_jiaotu1")
		t = new CNheimuya_jiaotu1();
	else if(npc_name == "heimuya_jiaotu2")
		t = new CNheimuya_jiaotu2();
	else if(npc_name == "heimuya_jiaotu3")
		t = new CNheimuya_jiaotu3();
	else if(npc_name == "heimuya_jiaotu4")
		t = new CNheimuya_jiaotu4();
	else if(npc_name == "heimuya_jiaotu5")
		t = new CNheimuya_jiaotu5();
	else if(npc_name == "heimuya_jiaotu6")
		t = new CNheimuya_jiaotu6();
	else if(npc_name == "ry_dongfang")
		t = new CNry_dongfang();
	
	return t;
}

