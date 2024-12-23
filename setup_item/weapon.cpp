#include "stdafx.h"
#include "../server/Room.h"
#include "../server/User.h"
#include "../std/Equip.h"
#include "../std/Food.h"
#include "../item/goods/autocombine.h"
#include "../std/FightRoom.h"

// 兵器 weapon
#include "../item/weapon/zhujian.h"
#include "../item/weapon/bishou.h"
#include "../item/weapon/changbian.h"
#include "../item/weapon/changjian.h"
#include "../item/weapon/changqiang.h"
#include "../item/weapon/dagger.h"
#include "../item/weapon/feihuangshi.h"
#include "../item/weapon/flower_leaf.h"
#include "../item/weapon/gangdao.h"
#include "../item/weapon/gangjian.h"
#include "../item/weapon/gangzhang.h"
#include "../item/weapon/hammer.h"
#include "../item/weapon/hugesword.h"
#include "../item/weapon/hanzhu.h" 
#include "../item/weapon/heilongbian.h" 
#include "../item/weapon/hothammer.h" 
#include "../item/weapon/jiedao.h"  
#include "../item/weapon/jinlun.h" 
#include "../item/weapon/jinmu.h"  
#include "../item/weapon/jinshe_jian.h" 
#include "../item/weapon/jinshe_zhui.h"
#include "../item/weapon/jili.h"
#include "../item/weapon/kuihuazhen.h"  
#include "../item/weapon/langyabang.h" 
#include "../item/weapon/leizhendang.h"  
#include "../item/weapon/longquansword.h" 
#include "../item/weapon/lengyue_baodao.h"
#include "../item/weapon/mudao.h"
#include "../item/weapon/mugun.h"
#include "../item/weapon/mujian.h"
#include "../item/weapon/mutang.h"
#include "../item/weapon/muyuchui.h" 
#include "../item/weapon/panguanbi.h" 
#include "../item/weapon/qimeigun.h"
#include "../item/weapon/ruanjian.h" 
#include "../item/weapon/sea_wood.h" 
#include "../item/weapon/senggun.h" 
#include "../item/weapon/shebian.h" 
#include "../item/weapon/shenghuo_ling.h"
#include "../item/weapon/shezhang.h" 
#include "../item/weapon/shield.h" 
#include "../item/weapon/shigu.h" 
#include "../item/weapon/shikuai.h" 
#include "../item/weapon/shitou.h" 
#include "../item/weapon/shortsword.h" 
#include "../item/weapon/shutonggun.h" 
#include "../item/weapon/shuzhi.h" 
#include "../item/weapon/taomujian.h"  
#include "../item/weapon/tiebian.h"  
#include "../item/weapon/tiedan.h"  
#include "../item/weapon/tiejiang.h" 
#include "../item/weapon/tiepipa.h" 
#include "../item/weapon/tieqiao.h" 
#include "../item/weapon/tongren.h" 
#include "../item/weapon/tudao.h"
#include "../item/weapon/tea_leaf.h"
#include "../item/weapon/tiegun.h"
#include "../item/weapon/tielianzi.h"
#include "../item/weapon/walkingstick.h" 
#include "../item/weapon/xiao.h" 
#include "../item/weapon/xiuhua.h" 
#include "../item/weapon/xuedao.h" 
#include "../item/weapon/yinlun.h" 
#include "../item/weapon/youlongsword.h" 
#include "../item/weapon/ytjian.h" 
#include "../item/weapon/yuxiao.h"  
#include "../item/weapon/zijinchui.h" 
#include "../item/weapon/zhubang.h"

#include "../item/weapon/zimuzhen.h"
#include "../item/weapon/zhuyebiao.h"
#include "../item/weapon/zhitao.h"
#include "../item/weapon/zheshan.h"
#include "../item/weapon/yaoqin.h"
#include "../item/weapon/yaochu.h"
#include "../item/weapon/yangbian.h"
#include "../item/weapon/buzhenxiang.h"
#include "../item/weapon/xem_sword.h"
#include "../item/weapon/wuxiang_sword.h"
#include "../item/weapon/wuqing_sword.h"
#include "../item/weapon/wodao.h"
#include "../item/weapon/wandao.h"
#include "../item/weapon/abab_sword.h"
#include "../item/weapon/arrow.h"
#include "../item/weapon/arrow1.h"
#include "../item/weapon/axe.h"
#include "../item/weapon/baihongjian.h"
#include "../item/weapon/biandan.h"
#include "../item/weapon/bilinzhen.h"
#include "../item/weapon/caidao.h"
#include "../item/weapon/chaidao.h"
#include "../item/weapon/chanzhang.h"
#include "../item/weapon/cleansword.h"
#include "../item/weapon/cwbdao.h"
#include "../item/weapon/dadao.h"
#include "../item/weapon/dadao2.h"
#include "../item/weapon/dafu.h"
#include "../item/weapon/putongbishou.h"
#include "../item/weapon/duanjian.h"
#include "../item/weapon/eluanshi.h"
#include "../item/weapon/falun.h"
#include "../item/weapon/fandog_sword.h"
#include "../item/weapon/fengjiang.h"
#include "../item/weapon/fenshuici.h"
#include "../item/weapon/fork.h"
#include "../item/weapon/fuchen.h"
#include "../item/weapon/fumo_dao.h"
#include "../item/weapon/futou.h"
#include "../item/weapon/gancheng.h"
#include "../item/weapon/gangbiao.h"
#include "../item/weapon/green_sword.h"
#include "../item/weapon/green_water_sword.h"
#include "../item/weapon/huoqiang.h"
#include "../item/weapon/jiandao.h"
#include "../item/weapon/jiujiebian.h"
#include "../item/weapon/junzijian.h"
#include "../item/weapon/kandao.h"
#include "../item/weapon/lianxindan.h"
#include "../item/weapon/mandao.h"
#include "../item/weapon/muyu.h"
#include "../item/weapon/qin.h"
#include "../item/weapon/qinqin_sword.h"
#include "../item/weapon/shortblade.h"
#include "../item/weapon/shunvjian.h"
#include "../item/weapon/shuzhi2.h"
#include "../item/weapon/snowsword.h"
#include "../item/weapon/tie_gan.h"
#include "../item/weapon/yuzhu_zhang.h"
#include "../item/weapon/xblade.h"

#include "../item/weapon/sword_1.h"
#include "../item/weapon/sword_2.h"
#include "../item/weapon/sword_3.h"

#include "../item/weapon/blade_1.h"
#include "../item/weapon/blade_2.h"

#include "../item/weapon/icesword.h"
#include "../item/weapon/frostblade.h"
#include "../item/weapon/jinhua.h"

#include "../item/weapon/bt_zhen.h"//冰魄银针
#include "../item/weapon/yufeng_zhen.h"//玉蜂针
#include "../item/weapon/ring_whip.h"//金铃索
#include "../item/weapon/xuantiesword.h"//金铃索

#include "../item/weapon/monsterblade.h"
#include "../item/weapon/monstersword.h"
#include "../item/weapon/huaji.h"
#include "../item/weapon/qingsi.h"

#include "../item/weapon/zijin_staff.h"		//紫金天蛇杖

//Add by wolfman with 竹子
#include "../item/weapon/qingzugang.h"		//竹子
#include "../item/weapon/qingzuzang.h"				//青竹杖

//秦波 2002、3、14
#include "../item/weapon/cyjian.h"				// 重阳剑
#include "../item/weapon/a_38huoqiang.h"		// 点三八火枪
#include "../item/weapon/a_xuantiebishou.h"		// 玄铁匕首
#include "../item/weapon/c_dagoubang.h"			// 帮主打狗棒	黄帮主5件套装
#include "../item/weapon/d_shenshe_staff.h"		// 老豆神蛇杖	欧阳公子4件套装
#include "../item/weapon/d_haoseshan.h"			// 君子好色折扇	欧阳公子4件套装
#include "../item/weapon/e_btzheng.h"			// bt绣花针		不败7件套装
#include "../item/weapon/f_taibaizao.h"			// 太白帚		真武7件套装
#include "../item/weapon/f_zwsword.h"			// 真武剑		真武7件套装
#include "../item/weapon/h_lvzhuxiao.h"			// 绿竹箫		令狐少侠5件套装
#include "../item/weapon/h_conglinjian.h"		//冲灵剑		令狐少侠5件套装

#include "../item/weapon/shenghuo_lingpro.h"	// 增强圣火令
#include "../item/weapon/tulong_dao.h"	// 屠龙刀
#include "../item/weapon/mingwang_jian.h"	// 明王剑

#include "../item/goods/chunjie/chunjie_ts.h"	// 不消失唐诗三百首
#include "../item/goods/chunjie/chunjie_ts1.h"	// 唐诗三百首

CContainer * Load_Weapon(string item_name)
{
	CContainer * t = NULL;

	//  兵器 weapon
	if(item_name == "zhujian")
		t = new CIzhujian();
	else if(item_name == "bishou")
		t = new CIBiShou();
	else if(item_name == "dagger")			//普通匕首 lanwood 2000-12-29
		t = new CIdagger();
	else if(item_name == "changbian")
		t = new CIChangBian();
	else if(item_name == "changjian")
		t = new CIChangJian();
	else if(item_name == "changqiang")
		t = new CIChangQiang();
	else if(item_name == "feihuangshi")
		t = new CIFeiHuangShi();
	else if(item_name == "flower_leaf")
		t = new CIFlowerLeaf();
	else if(item_name == "gangdao")
		t = new CIGangDao();
	else if(item_name == "gangjian")
		t = new CIGangJian();
	else if(item_name == "gangzhang")
		t = new CIGangZhang();
	else if(item_name == "hammer")
		t = new CIHammer();
	else if(item_name == "hugesword")
		t = new CIXiangYang_HugeSword();
	else if(item_name == "hanzhu")
		t = new CIhanzhu();
	else if(item_name == "heilongbian")
		t = new CIheilongbian();
	else if(item_name == "hothammer")
		t = new CIhothammer();
	else if(item_name == "jiedao")
		t = new CIjiedao();
	else if(item_name == "jinlun")
		t = new CIjinlun();
	else if(item_name == "jinmu")
		t = new CIjinmu();
	else if(item_name == "jinshe_jian")
		t = new CIjinshe_jian();
	else if(item_name == "jinshe_zhui")
		t = new CIjinshe_zhui();
	else if(item_name == "jili")
		t = new CIJiLi();
	else if(item_name == "kuihuazhen")
		t = new CIkuihuazhen();
	else if(item_name == "langyabang")
		t = new CIlangyabang();
	else if(item_name == "leizhendang")
		t = new CIleizhendang();
	else if(item_name == "longquansword")
		t = new CIlongquansword();
	else if(item_name == "lengyue_baodao")
		t = new CILengYueBaoDao();
	else if(item_name == "mudao")
		t = new CImudao();
	else if(item_name == "mugun")
		t = new CImugun();
	else if(item_name == "mujian")
		t = new CImujian();
	else if(item_name == "mutang")
		t = new CImutang();
	else if(item_name == "muyuchui")
		t = new CImuyuchui();
	else if(item_name == "panguanbi")
		t = new CIpanguanbi();
	else if(item_name == "qimeigun")
		t = new CIQiMeiGun();
 	else if(item_name == "ruanjian")
		t = new CIruanjian();
	else if(item_name == "sea_wood")
		t = new CIsea_wood();
	else if(item_name == "senggun")
		t = new CIsenggun();
	else if(item_name == "shebian")
		t = new CIshebian();
	else if(item_name == "shenghuo_ling")
		t = new CIshenghuo_ling();
	else if(item_name == "shezhang")
		t = new CIshezhang();
	else if(item_name == "shield")
		t = new CIshield();
	else if(item_name == "shigu")
		t = new CIshigu();
	else if(item_name == "shikuai")
		t = new CIshikuai();
	else if(item_name == "shitou")
		t = new CIshitou();
	else if(item_name == "shortsword")
		t = new CIshortsword();
	else if(item_name == "shutonggun")
		t = new CIshutonggun();
	else if(item_name == "shuzhi")
		t = new CIshuzhi();
	else if(item_name == "taomujian")
		t = new CItaomujian();
	else if(item_name == "tiebian")
		t = new CItiebian();
	else if(item_name == "tiedan")
		t = new CItiedan();
	else if(item_name == "tiejiang")
		t = new CItiejiang();
	else if(item_name == "tiepipa")
		t = new CItiepipa();
	else if(item_name == "tieqiao")
		t = new CItieqiao();
	else if(item_name == "tongren")
		t = new CItongren();
	else if(item_name == "tudao")
		t = new CItudao();
	else if(item_name == "tea_leaf")
		t = new CITeaLeaf();
	else if(item_name == "tiegun")
		t = new CITieGun();
	else if(item_name == "tielianzi")
		t = new CITieLianZi();
 	else if(item_name == "walkingstick")
		t = new CIwalkingstick();
	else if(item_name == "xiao")
		t = new CIxiao();
	else if(item_name == "xiuhua")
		t = new CIxiuhua();
	else if(item_name == "xuedao")
		t = new CIxuedao();
	else if(item_name == "yinlun")
		t = new CIyinlun();
	else if(item_name == "youlongsword")
		t = new CIyoulongsword();
	else if(item_name == "ytjian")
		t = new CIytjian();
	else if(item_name == "yuxiao")
		t = new CIyuxiao();
	else if(item_name == "zijinchui")
		t = new CIzijinchui();
	else if(item_name == "zhubang")
		t = new CIZhuBang();

	else if(item_name == "zimuzhen")
		t = new CIzimuzhen();
	else if(item_name == "zhuyebiao")
		t = new CIzhuyebiao();
	else if(item_name == "zhitao")
		t = new CIzhitao();
	else if(item_name == "zheshan")
		t = new CIzheshan();

	//太长了
	if(t) return t;		

	if(item_name == "yaoqin")
		t = new CIyaoqin();
	else if(item_name == "yaochu")
		t = new CIyaochu();
	else if(item_name == "yangbian")
		t = new CIyangbian();
	else if(item_name == "buzhenxiang")
		t = new CIbuzhenxiang();
	else if(item_name == "xem_sword")
		t = new CIxem_sword();
	else if(item_name == "wuxiang_sword")
		t = new CIwuxiang_sword();
	else if(item_name == "wuqing_sword")
		t = new CIwuqing_sword();
	else if(item_name == "wodao")
		t = new CIwodao();
	else if(item_name == "wandao")
		t = new CIwandao();
	else if(item_name == "abab_sword")
		t = new CIabab_sword();
	else if(item_name == "arrow")
		t = new CIarrow();
	else if(item_name == "arrow1")
		t = new CIarrow1();
	else if(item_name == "axe")
		t = new CIaxe();
	else if(item_name == "baihongjian")
		t = new CIbaihongjian();
	else if(item_name == "biandan")
		t = new CIbiandan();
	else if(item_name == "bilinzhen")
		t = new CIbilinzhen();
	else if(item_name == "caidao")
		t = new CIcaidao();
	else if(item_name == "chaidao")
		t = new CIchaidao();
	else if(item_name == "chanzhang")
		t = new CIchanzhang();
	else if(item_name == "cleansword")
		t = new CIcleansword();
	else if(item_name == "cwbdao")
		t = new CIcwbdao();
	else if(item_name == "dadao")
		t = new CIdadao();
	else if(item_name == "dadao2")
		t = new CIdadao2();
	else if(item_name == "dafu")
		t = new CIdafu();
	else if(item_name == "putongbishou")
		t = new CIputongbishou();
	else if(item_name == "duanjian")
		t = new CIduanjian();
	else if(item_name == "eluanshi")
		t = new CIeluanshi();
	else if(item_name == "falun")
		t = new CIfalun();
	else if(item_name == "fandog_sword")
		t = new CIfandog_sword();
	else if(item_name == "fengjiang")
		t = new CIfengjiang();
	else if(item_name == "fenshuici")
		t = new CIfenshuici();
	else if(item_name == "fork")
		t = new CIfork();
	else if(item_name == "fuchen")
		t = new CIfuchen();
	else if(item_name == "fumo_dao")
		t = new CIfumo_dao();
	else if(item_name == "futou")
		t = new CIfutou();
	else if(item_name == "gancheng")
		t = new CIgancheng();
	else if(item_name == "gangbiao")
		t = new CIgangbiao();
	else if(item_name == "green_sword")
		t = new CIgreen_sword();
	else if(item_name == "green_water_sword")
		t = new CIgreen_water_sword();
	else if(item_name == "huoqiang")
		t = new CIhuoqiang();
	else if(item_name == "jiandao")
		t = new CIjiandao();
	else if(item_name == "jiujiebian")
		t = new CIjiujiebian();
	else if(item_name == "junzijian")
		t = new CIjunzijian();
	else if(item_name == "kandao")
		t = new CIkandao();
	else if(item_name == "lianxindan")
		t = new CIlianxindan();
	else if(item_name == "mandao")
		t = new CImandao();
	else if(item_name == "muyu")
		t = new CImuyu();
	else if(item_name == "qin")
		t = new CIqin();
	else if(item_name == "qinqin_sword")
		t = new CIqinqin_sword();
	else if(item_name == "shortblade")
		t = new CIshortblade();
	else if(item_name == "shunvjian")
		t = new CIshunvjian();
	else if(item_name == "shuzhi2")
		t = new CIshuzhi2();
	else if(item_name == "snowsword")
		t = new CIsnowsword();
	else if(item_name == "tie_gan")
		t = new CItie_gan();
	else if(item_name == "yuzhu_zhang")
		t = new CIyuzhu_zhang();
	else if(item_name == "xblade")
		t = new CIxblade();

	else if(item_name == "sword_1")
		t = new CIsword_1();
	else if(item_name == "sword_2")
		t = new CIsword_2();
	else if(item_name == "sword_3")
		t = new CIsword_3();

	else if(item_name == "blade_1")
		t = new CIblade_1();
	else if(item_name == "blade_2")
		t = new CIblade_2();

	else if(item_name == "icesword")
		t = new CIicesword();
	else if(item_name == "frostblade")
		t = new CIfrostblade();
	else if(item_name == "jinhua")
		t = new CIjinhua();

	else if(item_name == "bt_zhen")
		t = new CIbt_zhen();
	else if(item_name == "yufeng_zhen")
		t = new CIyufeng_zhen();
	else if(item_name == "ring_whip")
		t = new CIring_whip();
	else if(item_name == "xuantiesword")
		t = new CIxuantiesword();

	else if(item_name == "monsterblade")
		t = new CImonsterblade();
	else if(item_name == "monstersword")
		t = new CImonstersword();

	else if(item_name == "huaji")
		t = new CIhuaji();
	else if(item_name == "qingsi")
		t = new CIqingsi();

	else if(item_name == "zijin_staff")
		t = new CIzijin_staff();

	else if(item_name == "qingzugang")
		t = new CIqingzugang();
	else if(item_name == "qingzuzang")
		t = new CIqingzuzang();
	else if(item_name == "cyjian")
		t = new CIcyjian();
	else if(item_name == "38huoqiang")
		t = new CI38huoqiang();
	else if(item_name == "xuantiebishou")
		t = new CIxuantiebishou();
	else if(item_name == "dagoubang")
		t = new CIdagoubang();
	else if(item_name == "shenshe_staff")
		t = new CIshenshe_staff();
	else if(item_name == "haoseshan")
		t = new CIhaoseshan();
	else if(item_name == "shenghuo_lingpro")
		t = new CIshenghuo_lingpro();
	else if(item_name == "tulong_dao")
		t = new CItulong_dao();
	else if(item_name == "mingwang_jian")
		t = new CImingwang_jian();
	else if(item_name == "btzheng")
		t = new CIbtzheng();
	else if(item_name == "taibaizao")
		t = new CItaibaizao();
	else if(item_name == "zwsword")
		t = new CIzwsword();
	else if(item_name == "lvzhuxiao")
		t = new CIlvzhuxiao();
	else if(item_name == "conglinjian")
		t = new CIconglinjian();

	else if(item_name == "chunjie_ts")
		t = new CIchunjie_ts();
	else if(item_name == "chunjie_ts1")
		t = new CIchunjie_ts1();

	return t;
}



