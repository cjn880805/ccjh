#include "stdafx.h"
#include "../server/User.h"
#include "../server/Channel.h"
#include "../std/Food.h"
#include "../std/Equip.h"
#include "../std/Money.h"
#include "../server/Room.h"

// 食物 food
#include "../item/food/yaopin.h"
#include "../item/food/jingxin_san.h"
#include "../item/food/honey.h"

#include "../item/food/baihe.h" 
#include "../item/food/baixiang.h" 
#include "../item/food/baozi.h" 
#include "../item/food/duanchang.h" 
#include "../item/food/feicui.h" 
#include "../item/food/gourou.h" 
#include "../item/food/gouroutang.h" 
#include "../item/food/guijia.h" 
#include "../item/food/guiyuan.h" 
#include "../item/food/hdjiudai.h"
#include "../item/food/heiyugao.h" 
#include "../item/food/honghua.h" 
#include "../item/food/hulu.h" 
#include "../item/food/jiaohuaji.h" 
#include "../item/food/jiaxin_biji.h" 
#include "../item/food/jinchuang.h"
#include "../item/food/jinchuang_yao.h" 
#include "../item/food/jindan.h"
#include "../item/food/jitui.h" 
#include "../item/food/jiudai.h" 
#include "../item/food/kaoya.h" 
#include "../item/food/liuli_qiezi.h"
#include "../item/food/mala_doufu.h"
#include "../item/food/marz.h"
#include "../item/food/menghan_yao.h"
#include "../item/food/mian.h"
#include "../item/food/mitao.h"
#include "../item/food/mizhitianou.h"
#include "../item/food/moyao.h"
#include "../item/food/niupidai.h"
#include "../item/food/nuerxiang.h"
#include "../item/food/nverhong.h"
#include "../item/food/peanut.h" 
#include "../item/food/putizi.h"
#include "../item/food/qingdan.h"
#include "../item/food/qingke_m.h"
#include "../item/food/qingshui_hulu.h"
#include "../item/food/renshen.h"
#include "../item/food/renshenguo.h"
#include "../item/food/rice.h"
#include "../item/food/shanhu_baicai.h"
#include "../item/food/shanshen.h"
#include "../item/food/shedan.h"
#include "../item/food/shedangao.h"
#include "../item/food/sherou.h"
#include "../item/food/shouwu.h"
#include "../item/food/soup.h"
#include "../item/food/suanmei.h"
#include "../item/food/suji.h"
#include "../item/food/suya.h"
#include "../item/food/tanghulu.h"
#include "../item/food/tianqi.h"
#include "../item/food/tianxiang_gao.h"
#include "../item/food/tofu.h" 
#include "../item/food/turou.h"
#include "../item/food/wuchangdan.h" 
#include "../item/food/wuming.h" 
#include "../item/food/x_drug.h"
#include "../item/food/xiangcha.h"
#include "../item/food/xiaohuan_dan.h"
#include "../item/food/xiongdan.h"
#include "../item/food/xionghuang.h"
#include "../item/food/xuejie.h"
#include "../item/food/xueli.h"
#include "../item/food/xuelian.h"
#include "../item/food/yadan.h"
#include "../item/food/yancao.h"
#include "../item/food/yangxin.h"
#include "../item/food/yaofen.h"
#include "../item/food/yuchandan.h"
#include "../item/food/yuchi.h"
#include "../item/food/zaisheng.h"
#include "../item/food/zhuguo.h"
#include "../item/food/zuguo.h"
#include "../item/food/zuguo5.h"
#include "../item/food/zongzi.h"

#include "../item/food/zhutou.h"
#include "../item/food/zhujingchan.h"
#include "../item/food/yezi.h"
#include "../item/food/yeerba.h"
#include "../item/food/yangrou.h"
#include "../item/food/yangjing.h"
#include "../item/food/xxqingxin_san.h"
#include "../item/food/xuelian2.h"
#include "../item/food/xiaren2.h"
#include "../item/food/xiang.h"
#include "../item/food/backleg.h"
#include "../item/food/soup2.h"
#include "../item/food/shrimp.h"
#include "../item/food/sanxiaosan.h"
#include "../item/food/rice3.h"
#include "../item/food/qingcha.h"
#include "../item/food/qiguoji.h"
#include "../item/food/puercha.h"
#include "../item/food/pork.h"
#include "../item/food/ping.h"
#include "../item/food/paomo.h"
#include "../item/food/nang.h"
#include "../item/food/mixian.h"
#include "../item/food/mangguo.h"
#include "../item/food/labazhou.h"
#include "../item/food/kongquedan.h"
#include "../item/food/kaoyangtui.h"
#include "../item/food/jiuping2.h"
#include "../item/food/jiuping.h"
#include "../item/food/jiuhua.h"
#include "../item/food/jiu.h"
#include "../item/food/huotui2.h"
#include "../item/food/huotui.h"
#include "../item/food/hulu2.h"
#include "../item/food/hulu1.h"
#include "../item/food/hu.h"
#include "../item/food/hedinghong.h"
#include "../item/food/hamigua.h"
#include "../item/food/guiling.h"
#include "../item/food/geng.h"
#include "../item/food/gaoyao.h"
#include "../item/food/gao4.h"
#include "../item/food/gao3.h"
#include "../item/food/gao.h"
#include "../item/food/furong_huagu.h"
#include "../item/food/fuling.h"
#include "../item/food/fotiaoqiang.h"
#include "../item/food/food.h"
#include "../item/food/fish.h"
#include "../item/food/fengmi.h"
#include "../item/food/fen.h"
#include "../item/food/egg.h"
#include "../item/food/doujiang.h"
#include "../item/food/dawancha.h"
#include "../item/food/dan.h"
#include "../item/food/dahuan_dan.h"
#include "../item/food/chicken.h"
#include "../item/food/cha2.h"
#include "../item/food/cha.h"
#include "../item/food/caomei.h"
#include "../item/food/cake.h"
#include "../item/food/bowl.h"
#include "../item/food/bottle.h"
#include "../item/food/bocai_fentiao.h"
#include "../item/food/birddie.h"
#include "../item/food/bing6.h"
#include "../item/food/bing5.h"
#include "../item/food/bing4.h"
#include "../item/food/bing3.h"
#include "../item/food/bing2.h"
#include "../item/food/bing1.h"
#include "../item/food/bicanfeng.h"
#include "../item/food/basi_shanyao.h"
#include "../item/food/baozi2.h"
#include "../item/food/baiyunwan.h"
#include "../item/food/baihua.h"

#include "../item/food/yaopin_1.h"
#include "../item/food/yaopin_2.h"
#include "../item/food/yaopin_3.h"
#include "../item/food/foodpack.h"
#include "../item/food/jiu_mijiu.h"

//chongyanggong
#include "../item/food/luobo.h"
#include "../item/food/caogeng.h"

//特殊道具
#include "../item/wiz/lvxingguo.h"
#include "../item/wiz/fuxingjiou.h"
#include "../item/wiz/shouxingtao.h"

#include "../item/food/baomingdan.h" //保命金丹
#include "../item/food/huanchunwan.h"// 还春丸
#include "../item/food/wangqing_shi.h" //忘情石
//#include "../item/food/dazongzi.h"		//粽子
#include "../item/food/da_zongzi.h"		//粽子
#include "../item/food/jieduwan.h"		//解毒清心丸

//元旦活动道具
#include "../item/goods/yuandan/cai.h"//菜肴
#include "../item/goods/yuandan/tang.h"//汤
#include "../item/goods/yuandan/guo.h"//水果
#include "../item/goods/yuandan/jiu.h"//酒

#include "../item/goods/caiyao.h"

#include "../item/food/sacred_fruit.h"//神圣的朱果

CContainer * Load_Food(string item_name)
{
	CContainer * t = NULL;

	// 食物 food
	if(item_name == "baihe")
		t = new CIbaihe();
	else if(item_name == "baixiang")
		t = new CIbaixiang();
	else if(item_name == "baozi")
		t = new CIbaozi();
	else if(item_name == "duanchang")
		t = new CIduanchang();
	else if(item_name == "feicui")
		t = new CIfeicui();
	else if(item_name == "gourou")
		t = new CIgourou();
	else if(item_name == "gouroutang")
		t = new CIgouroutang();
	else if(item_name == "guijia")
		t = new CIguijia();
	else if(item_name == "guiyuan")
		t = new CIguiyuan();
	else if(item_name == "heiyugao")
		t = new CIheiyugao();
	else if(item_name == "honghua")
		t = new CIhonghua();
	else if(item_name == "hdjiudai")
		t = new CIhdjiudai();
	else if(item_name == "hulu")
		t = new CIhulu();
	else if(item_name == "jiaohuaji")
		t = new CIjiaohuaji();
	else if(item_name == "jiaxin_biji")
		t = new CIjiaxin_biji();
	else if(item_name == "jinchuang")
		t = new CIjinchuang();
	else if(item_name == "jinchuang_yao")
		t = new CIjinchuang_yao();
	else if(item_name == "jitui")
		t = new CIjitui();
	else if(item_name == "jiudai")
		t = new CIjiudai();
	else if(item_name == "jindan")
		t = new CIjindan();
	else if(item_name == "kaoya")
		t = new CIkaoya();
	else if(item_name == "liuli_qiezi")
		t = new CIliuli_qiezi();
	else if(item_name == "mala_doufu")
		t = new CImala_doufu();
	else if(item_name == "marz")
		t = new CImarz();
	else if(item_name == "menghan_yao")
		t = new CImenghan_yao();
	else if(item_name == "mian")
		t = new CImian();
	else if(item_name == "mitao")
		t = new CImitao();
	else if(item_name == "mizhitianou")
		t = new CImizhitianou();
	else if(item_name == "moyao")
		t = new CImoyao();
	else if(item_name == "niupidai")
		t = new CIniupidai();
	else if(item_name == "nuerxiang")
		t = new CInuerxiang();
	else if(item_name == "nverhong")
		t = new CInverhong();
	else if(item_name == "peanut")
		t = new CIpeanut();
 	else if(item_name == "putizi")
		t = new CIputizi();
	else if(item_name == "qingdan")
		t = new CIqingdan();
	else if(item_name == "qingke_m")
		t = new CIqingke_m();
	else if(item_name == "qingshui_hulu")
		t = new CIqingshui_hulu();
	else if(item_name == "renshen")
		t = new CIrenshen();
	else if(item_name == "renshenguo")
		t = new CIrenshenguo();
	else if(item_name == "rice")
		t = new CIrice();
	else if(item_name == "shanhu_baicai")
		t = new CIshanhu_baicai();
	else if(item_name == "shanshen")
		t = new CIshanshen();
	else if(item_name == "shedan")
		t = new CIshedan();
	else if(item_name == "shedangao")
		t = new CIshedangao();
	else if(item_name == "sherou")
		t = new CIsherou();
	else if(item_name == "shouwu")
		t = new CIshouwu();
	else if(item_name == "soup")
		t = new CIsoup();
	else if(item_name == "suanmei")
		t = new CIsuanmei();
	else if(item_name == "suji")
		t = new CIsuji();
	else if(item_name == "suya")
		t = new CIsuya();
	else if(item_name == "tanghulu")
		t = new CItanghulu();
	else if(item_name == "tianqi")
		t = new CItianqi();
	else if(item_name == "tianxiang_gao")
		t = new CItianxiang_gao();
	else if(item_name == "turou")
		t = new CIturou();
	else if(item_name == "tofu")
		t = new CItofu();
	else if(item_name == "wuchangdan")
		t = new CIwuchangdan();
	else if(item_name == "wuming")
		t = new CIwuming();
	else if(item_name == "x_drug")
		t = new CIx_drug();
	else if(item_name == "xiangcha")
		t = new CIxiangcha();
	else if(item_name == "xiaohuan_dan")
		t = new CIxiaohuan_dan();
	else if(item_name == "xiongdan")
		t = new CIxiongdan();
	else if(item_name == "xionghuang")
		t = new CIxionghuang();
	else if(item_name == "xuejie")
		t = new CIxuejie();
	else if(item_name == "xueli")
		t = new CIxueli();
	else if(item_name == "xuelian")
		t = new CIxuelian();
	else if(item_name == "yadan")
		t = new CIyadan();
	else if(item_name == "yancao")
		t = new CIyancao();
	else if(item_name == "yangxin")
		t = new CIyangxin();
	else if(item_name == "yaofen")
		t = new CIyaofen();
	else if(item_name == "yuchandan")
		t = new CIyuchandan();
	else if(item_name == "yuchi")
		t = new CIyuchi();
	else if(item_name == "zaisheng")
		t = new CIzaisheng();
	else if(item_name == "zhuguo")
		t = new CIzhuguo();
	else if(item_name == "zuguo")
		t = new CIzuguo();
	else if(item_name == "zuguo5")
		t = new CIzuguo5();
	else if(item_name == "zongzi")
		t = new CIzongzi();

	//too long, break;
	if(t) return t;

	if(item_name == "zhutou")
		t = new CIzhutou();
	else if(item_name == "zhujingchan")
		t = new CIzhujingchan();
	else if(item_name == "yezi")
		t = new CIyezi();
	else if(item_name == "yeerba")
		t = new CIyeerba();
	else if(item_name == "yangrou")
		t = new CIyangrou();
	else if(item_name == "yangjing")
		t = new CIyangjing();
	else if(item_name == "xxqingxin_san")
		t = new CIxxqingxin_san();
	else if(item_name == "xuelian2")
		t = new CIxuelian2();
	else if(item_name == "xiaren2")
		t = new CIxiaren2();
	else if(item_name == "xiang")
		t = new CIxiang();
	else if(item_name == "backleg")
		t = new CIbackleg();
	else if(item_name == "soup2")
		t = new CIsoup2();
	else if(item_name == "shrimp")
		t = new CIshrimp();
	else if(item_name == "sanxiaosan")
		t = new CIsanxiaosan();
	else if(item_name == "rice3")
		t = new CIrice3();
	else if(item_name == "qingcha")
		t = new CIqingcha();
	else if(item_name == "qiguoji")
		t = new CIqiguoji();
	else if(item_name == "puercha")
		t = new CIpuercha();
	else if(item_name == "pork")
		t = new CIpork();
	else if(item_name == "ping")
		t = new CIping();
	else if(item_name == "paomo")
		t = new CIpaomo();
	else if(item_name == "nang")
		t = new CInang();
	else if(item_name == "mixian")
		t = new CImixian();
	else if(item_name == "mangguo")
		t = new CImangguo();
	else if(item_name == "laba_zhou")
		t = new CIlaba_zhou();
	else if(item_name == "kongquedan")
		t = new CIkongquedan();
	else if(item_name == "kaoyangtui")
		t = new CIkaoyangtui();
	else if(item_name == "jiuping2")
		t = new CIjiuping2();
	else if(item_name == "jiuping")
		t = new CIjiuping();
	else if(item_name == "jiuhua")
		t = new CIjiuhua();
	else if(item_name == "jiu")
		t = new CIjiu();
	else if(item_name == "huotui2")
		t = new CIhuotui2();
	else if(item_name == "huotui")
		t = new CIhuotui();
	else if(item_name == "hulu2")
		t = new CIhulu2();
	else if(item_name == "hulu1")
		t = new CIhulu1();
	else if(item_name == "hu")
		t = new CIhu();
	else if(item_name == "hedinghong")
		t = new CIhedinghong();
	else if(item_name == "hamigua")
		t = new CIhamigua();
	else if(item_name == "guiling")
		t = new CIguiling();
	else if(item_name == "geng")
		t = new CIgeng();
	else if(item_name == "gaoyao")
		t = new CIgaoyao();
	else if(item_name == "gao4")
		t = new CIgao4();
	else if(item_name == "gao3")
		t = new CIgao3();
	else if(item_name == "gao")
		t = new CIgao();
	else if(item_name == "furong_huagu")
		t = new CIfurong_huagu();
	else if(item_name == "fuling")
		t = new CIfuling();
	else if(item_name == "fotiaoqiang")
		t = new CIfotiaoqiang();
	else if(item_name == "food")
		t = new CIfood();
	else if(item_name == "fish")
		t = new CIfish();
	else if(item_name == "fengmi")
		t = new CIfengmi();
	else if(item_name == "fen")
		t = new CIfen();
	else if(item_name == "egg")
		t = new CIegg();
	else if(item_name == "doujiang")
		t = new CIdoujiang();
	else if(item_name == "dawancha")
		t = new CIdawancha();
	else if(item_name == "dan")
		t = new CIdan();
	else if(item_name == "dahuan_dan")
		t = new CIdahuan_dan();
	else if(item_name == "chicken")
		t = new CIchicken();
	else if(item_name == "cha2")
		t = new CIcha2();
	else if(item_name == "cha")
		t = new CIcha();
	else if(item_name == "caomei")
		t = new CIcaomei();
	else if(item_name == "cake")
		t = new CIcake();
	else if(item_name == "bowl")
		t = new CIbowl();
	else if(item_name == "bottle")
		t = new CIbottle();
	else if(item_name == "bocai_fentiao")
		t = new CIbocai_fentiao();
	else if(item_name == "birddie")
		t = new CIbirddie();
	else if(item_name == "bing_6")
		t = new CIbing_6();
	else if(item_name == "bing_5")
		t = new CIbing_5();
	else if(item_name == "bing_4")
		t = new CIbing_4();
	else if(item_name == "bing_3")
		t = new CIbing_3();
	else if(item_name == "bing_2")
		t = new CIbing_2();
	else if(item_name == "bing_1")
		t = new CIbing_1();
	else if(item_name == "bicanfeng")
		t = new CIbicanfeng();
	else if(item_name == "basi_shanyao")
		t = new CIbasi_shanyao();
	else if(item_name == "baozi2")
		t = new CIbaozi2();
	else if(item_name == "baiyunwan")
		t = new CIbaiyunwan();
	else if(item_name == "baihua")
		t = new CIbaihua();

	else if(item_name == "yaopin_1")
		t = new CIyaopin_1();
	else if(item_name == "yaopin_2")
		t = new CIyaopin_2();
	else if(item_name == "yaopin_4")
		t = new CIyaopin_4();
	else if(item_name == "foodpack")
		t = new CIfoodpack();
	else if(item_name == "jiu_mijiu")	//米酒
		t = new CIjiu_mijiu();

	//chongyanggong
	else if(item_name == "luobo")
		t = new CIluobo();
	else if(item_name == "caogeng")
		t = new CIcaogeng();
	else if(item_name == "jingxin_san")
		t = new CIjingxin_san();
	else if(item_name == "honey")
		t = new CIhoney();
	//特殊道具
	else if(item_name == "lvxingguo")
		t = new CIlvxingguo();
	else if(item_name == "fuxingjiou")
		t = new CIfuxingjiou();
	else if(item_name == "shouxingtao")
		t = new CIshouxingtao();
	else if(item_name == "baomingdan")
		t = new CIbaomingdan();
	else if(item_name == "huanchunwan")
		t = new CIhuanchunwan();
	else if(item_name == "wangqing_shi")
		t = new CIwangqing_shi();
//	else if(item_name == "dazongzi")
//		t = new CIdazongzi();
	else if(item_name == "da__zongzi")
		t = new CIda__zongzi();
	else if(item_name == "jieduwan")
		t = new CIjieduwan();

	else if(item_name == "cai")
		t = new CIcai();
	else if(item_name == "tang")
		t = new CItang();
	else if(item_name == "guo")
		t = new CIguo();
	else if(item_name == "jiu1")
		t = new CIjiu1();
	else if(item_name == "caiyao")
		t = new CIcaiyao();

	else if(item_name == "sacred_fruit")
		t = new CIsacred_fruit();

	return t;
}



