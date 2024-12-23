#include "stdafx.h"
#include "../std/Equip.h"
#include "../server/User.h"
#include "../server/Room.h"
#include "../std/Money.h"
#include "../server/Channel.h"
#include "../server/Skill.h"
#include "../std/npcmirror.h"

#include "../item/goods/autocombine.h"
#include "../std/FightRoom.h"

// 道具 goods
#include "../item/goods/jieyuling.h"

#include "../item/goods/card1.h"
#include "../item/goods/card2.h"
#include "../item/goods/card3.h"
#include "../item/goods/giftbox.h"
#include "../item/goods/heimu_ling.h"
#include "../item/goods/huashan_letter.h"
#include "../item/goods/letter.h"
#include "../item/goods/marry_card.h"
#include "../item/goods/meihualing.h"
#include "../item/goods/meizhuang_yaoshi.h"
#include "../item/goods/pigdie.h"
#include "../item/goods/site.h"
#include "../item/goods/tie.h"
#include "../item/goods/tie_ling.h"
#include "../item/goods/tuijianxin_1.h"
#include "../item/goods/tuijianxin_2.h"
#include "../item/goods/tuijianxin_3.h"
#include "../item/goods/tuijianxin_4.h"
#include "../item/goods/xin.h"
#include "../item/goods/anmenkey.h"
#include "../item/goods/yaoshi.h"
#include "../item/goods/tiedi.h"

#include "../item/goods/huicheng_juanzhou.h"
#include "../item/goods/transfer_tie.h"
#include "../item/goods/fengyin.h"

#include "../item/goods/rubbish_1.h"
#include "../item/goods/rubbish_2.h"

#include "../item/goods/falunblade.h"
#include "../item/goods/poembook.h"
#include "../item/goods/plumsword.h"
#include "../item/goods/qinghong.h"

#include "../item/goods/guyuepai.h"
#include "../item/goods/tongxinyin.h"
#include "../item/goods/detectbox.h"
#include "../item/goods/readingbot.h"
#include "../item/goods/exercisebot.h"
#include "../item/goods/practicebot.h"
#include "../item/goods/killermask.h"
#include "../item/goods/testobj.h"
#include "../item/std/ssword.h"
#include "../item/goods/moonlock.h"
#include "../item/goods/gaitou.h"
#include "../item/goods/wushi.h"
#include "../item/goods/yueping.h"
#include "../item/goods/ji.h"

//gaibang
#include "../item/goods/po_bu.h"
#include "../item/goods/qingzhu_ling.h"
//mingjiao
#include "../item/goods/tieyanling.h"
//shaolin
#include "../item/goods/damo_ling.h"
#include "../item/goods/caishen.h"
#include "../item/goods/jiashan.h"
#include "../item/goods/jiangzhumu.h"
#include "../item/goods/guanyin.h"
#include "../item/goods/lingpai.h"
#include "../item/goods/mofa_shoukao.h"

#include "../item/wiz/kugu_1.h"
#include "../item/wiz/lingao.h"
#include "../item/wiz/nantianzhu.h"
#include "../item/wiz/redqin.h"
#include "../item/wiz/greenxiao.h"
#include "../item/wiz/umbrella.h"
#include "../item/wiz/trade.h"
#include "../item/wiz/buildcorps.h"
#include "../item/wiz/jieyinling.h"
#include "../item/wiz/bangzhuling.h"
#include "../item/wiz/shanrangling.h"
#include "../item/wiz/zhanbao.h"
#include "../item/wiz/redpacket.h"
#include "../item/wiz/amends.h"
//#include "../item/wiz/wiz_fushi.h"
#include "../item/wiz/18qing_tie.h"
#include "../item/wiz/bingfeng_miji.h"
#include "../item/wiz/hanshuang_miji.h"
#include "../item/wiz/fushi.h"
#include "../item/goods/heiyue_si.h"

//2002、2、6 秦波
#include "../item/wiz/hongbao.h"
#include "../item/wiz/biaoqi.h"
#include "../item/goods/anjinmenkey.h"
#include "../item/goods/baoguo.h"
#include "../item/goods/jinggang.h"
#include "../item/goods/gangsi.h"
#include "../item/wiz/leitaizhanbao.h"
#include "../item/wiz/xiangsi_miji.h"
#include "../item/wiz/xiaohun_miji.h"
#include "../item/goods/redrose.h"
#include "../item/goods/yinpiao.h"
#include "../item/goods/xueshujian.h"
#include "../item/goods/killermask1.h"
#include "../item/goods/baiyupi.h"

//逍遥任务道具
#include "../item/goods/d/xy/yingyue_si.h"
#include "../item/goods/d/xy/zhuque_jin.h"
#include "../item/goods/d/xy/xuanwu_huan.h"
#include "../item/goods/d/xy/qinglong_pao.h"
#include "../item/goods/d/xy/baihu_xue.h"
#include "../item/goods/d/xy/mupai.h"
#include "../item/goods/d/xy/mupai1.h"
#include "../item/goods/d/xy/heise_huan.h"
#include "../item/goods/d/xy/shikuei.h"
#include "../item/goods/d/xy/shicheng.h"
#include "../item/goods/d/xy/shizhu.h"
#include "../item/goods/d/xy/shiguei.h"
#include "../item/goods/d/xy/meishu.h"
#include "../item/goods/d/xy/xueduei.h"
#include "../item/goods/d/xy/guanmulin.h"
#include "../item/goods/d/xy/shen.h"
#include "../item/goods/d/xy/xiaoshimo.h"
#include "../item/goods/d/xy/yaochu.h"
#include "../item/goods/d/xy/xy_yaodan.h"
#include "../item/goods/d/xy/ciwan.h"
#include "../item/goods/d/xy/shaguan.h"
#include "../item/goods/d/xy/xiaohuolu.h"
#include "../item/goods/d/xy/chaihe.h"
#include "../item/goods/d/xy/zhutong.h"
#include "../item/goods/d/xy/wugenshuei.h"
#include "../item/goods/d/xy/xueshuei.h"
#include "../item/goods/d/xy/lushuei.h"
#include "../item/goods/d/xy/sanqi.h"
#include "../item/goods/d/xy/baizhi.h"
#include "../item/goods/d/xy/baiwei.h"
#include "../item/goods/d/xy/baifuzi.h"
#include "../item/goods/d/xy/baiji.h"
#include "../item/goods/d/xy/zhen_zhu.h"
#include "../item/goods/d/xy/hehua.h"
#include "../item/goods/d/xy/heye.h"
#include "../item/goods/d/xy/juhua.h"
#include "../item/goods/d/xy/baiguo.h"
#include "../item/goods/d/xy/hongzao.h"
#include "../item/goods/d/xy/daohe.h"
#include "../item/goods/d/xy/daomi.h"
#include "../item/goods/d/xy/xinren.h"
#include "../item/goods/d/xy/mituoseng.h"
#include "../item/goods/d/xy/hufen.h"
#include "../item/goods/d/xy/baihe.h"
#include "../item/goods/d/xy/baixian.h"
#include "../item/goods/d/xy/ganjiang.h"
#include "../item/goods/d/xy/jidan.h"
#include "../item/goods/d/xy/taohua.h"
#include "../item/goods/d/xy/mudan.h"
#include "../item/goods/d/xy/liandao.h"
#include "../item/goods/d/xy/daotian.h"
#include "../item/goods/d/xy/yangshuei.h"

//元旦活动道具
#include "../item/goods/yuandan/yupian.h"//玉片
#include "../item/goods/yuandan/zihulu.h"//小紫葫芦
#include "../item/goods/yuandan/guanfu.h"//官服
#include "../item/goods/yuandan/cunyang_sword.h"//纯阳剑
#include "../item/goods/yuandan/huaban.h"//花瓣
#include "../item/goods/yuandan/yanhua.h"//烟花
#include "../item/goods/yinpiao1.h"

#include "../item/goods/nixiang.h"
#include "../item/goods/baoguo1.h"

//春节活动道具
#include "../item/goods/chunjie/chunjie_ld.h"//礼单碎片
#include "../item/goods/chunjie/chunjie_hb.h"//压岁红包
#include "../item/goods/chunjie/chunjie_yh.h"//烟花
#include "../item/goods/newgift.h"//神秘礼物

//北京任务道具
#include "../item/goods/d/bj/zhanshu.h"

//万安寺六派任务道具
#include "../item/goods/d/was/was_mache.h"
#include "../item/goods/d/was/was_leitinglin.h"

//侠客岛任务道具
#include "../item/goods/d/xkd/shangshan_tie.h"
#include "../item/goods/d/xkd/xkd_baotu.h"

//彩票活动
#include "../item/goods/caipiao.h"//彩票

//帮派道具
#include "../item/goods/corps/buildcorps1.h" //玉清符
#include "../item/wiz/jieyinling1.h"  //接引领
#include "../item/wiz/bangzhuling1.h" //开除令
#include "../item/goods/corps/tianmen_map.h" //玉清符
#include "../item/goods/corps/tradepro_item.h" //任务收集材料
#include "../item/goods/corps/tradepro_item1.h" //任务收集材料
#include "../item/goods/yanshiling.h" //烟雨令

CContainer * Load_Goods(string item_name)
{
	CContainer * t = NULL;

	if(item_name == "card1")
		t = new CIcard1();
	else if(item_name == "card2")
		t = new CIcard2();

	else if(item_name == "jieyuling")
		t = new CIjieyuling();
	
	else if(item_name == "card3")
		t = new CIcard3();
	else if(item_name == "giftbox")
		t = new CIgiftbox();
	else if(item_name == "heimu_ling")
		t = new CIheimu_ling();
	else if(item_name == "huashan_letter")		//令狐冲的情信 lanwood
		t = new CIhuashan_letter();
	else if(item_name == "letter")				
		t = new CIletter();
	else if(item_name == "marry_card")
		t = new CImarry_card();
	else if(item_name == "meihualing")	//lanwood 2000-12-28
		t = new CImeihualing();
	else if(item_name == "meizhuang_yaoshi")	//lanwood 2000-12-28
		t = new CImeizhuang_yaoshi();
	else if(item_name == "site")
		t = new CIsite();
	else if(item_name == "pigdie")			//侠客岛死猪 lanwood 2000-12-29
		t = new CIpigdie();
	else if(item_name == "tie")
		t = new CItie();
	else if(item_name == "tie_ling")	//重阳令 lanwood 2000-12-28
		t = new CItie_ling();

	else if(item_name == "tuijianxin_1")	//推荐信 lanwood 2000-12-29
		t = new CItuijianxin_1();
	else if(item_name == "tuijianxin_2")	//推荐信 lanwood 2000-12-29
		t = new CItuijianxin_2();
	else if(item_name == "tuijianxin_3")	//推荐信 lanwood 2000-12-29
		t = new CItuijianxin_3();
	else if(item_name == "tuijianxin_4")	//推荐信 lanwood 2000-12-29
		t = new CItuijianxin_4();
	else if(item_name == "xin")				//归云书信 lanwood 2000-12-29
		t = new CIxin();
	else if(item_name == "anmenkey")		//熬败钥匙 lanwood 2000-12-29
		t = new CIanmenkey();
	else if(item_name == "yaoshi")			//牢房钥匙 lanwood 2000-12-29
		t = new CIyaoshi();

	else if(item_name == "huicheng_juanzhou")
		t = new CIhuicheng_juanzhou();
	else if(item_name == "transfer_tie")
		t = new CItransfer_tie();
	else if(item_name == "fengyin")
		t = new CIfengyin();

	else if(item_name == "rubbish_1")
		t = new CIrubbish_1();
	else if(item_name == "rubbish_2")
		t = new CIrubbish_2();

	else if(item_name == "falunblade")
		t = new CIfalunblade();
	else if(item_name == "poembook")
		t = new CIpoembook();
	else if(item_name == "plumsword")
		t = new CIplumsword();
	else if(item_name == "caishen")
		t = new CIcaishen();
	else if(item_name == "guanyin")
		t = new CIguanyin();
	else if(item_name == "qinghong")
		t = new CIqinghong();
	
	else if(item_name == "guyuepai")
		t = new CIguyuepai();
	else if(item_name == "tongxinyin")
		t = new CItongxinyin();
	else if(item_name == "detectbox")
		t = new CIdetectbox();
	else if(item_name == "readingbot")
		t = new CIreadingbot();
	else if(item_name == "exercisebot")
		t = new CIexercisebot();
	else if(item_name == "practicebot")
		t = new CIpracticebot();
	else if(item_name == "killermask")
		t = new CIkillermask();
	else if(item_name == "testobj")
		t = new CItestobj();
	else if(item_name == "ssword")
		t = new CIssword();
	else if(item_name == "moonlock")
		t = new CImoonlock();
	else if(item_name == "gaitou")
		t = new CIgaitou();
	else if(item_name == "wushi")
		t = new CIwushi();

	//gaibang
	else if(item_name == "po_bu")
		t = new CIpo_bu();
	else if(item_name == "qingzhu_ling")
		t = new CIqingzhu_ling();

	//mingjiao
	else if(item_name == "tieyanling")
		t = new CItieyanling();

	//shaolin
	else if(item_name == "damo_ling")
		t = new CIdamo_ling();
	else if(item_name == "lingpai")
		t = new CIlingpai();

	//dali
	else if(item_name == "tiedi")
		t = new CItiedi();

	else if(item_name == "kugu_1")
		t = new CIbook_kugu_1();
	else if(item_name == "lingao")
		t = new CIlingao();
	else if(item_name == "nantianzhu")
		t = new CInantianzhu();
	else if(item_name == "yueping")
		t = new CIyueping();
	else if(item_name == "redqin")
		t = new CIredqin();
	else if(item_name == "greenxiao")
		t = new CIgreenxiao();
	else if(item_name == "ji")
		t = new CIJi();
	else if(item_name == "mofa_shoukao")
		t = new CImofa_shoukao();

	else if(item_name == "umbrella")
		t = new CIumbrella();
	else if(item_name == "trade")
		t = new CItrade();
	else if(item_name == "buildcorps")
		t = new CIbuildcorps();
	else if(item_name == "jieyinling")
		t = new CIjieyinling();
	else if(item_name == "bangzhuling")
		t = new CIbangzhuling();
	else if(item_name == "shanrangling")
		t = new CIshanrangling();
	else if(item_name == "wiz_zhanbao")
		t = new CIwiz_zhanbao();
	else if(item_name == "redpacket")
		t = new CIredpacket();
	else if(item_name == "amends")
		t = new CIamends();
//	else if(item_name == "wiz_fushi")
//		t = new CIwiz_fushi();
	else if(item_name == "18qing_tie")
		t = new CI18qing_tie();
	else if(item_name == "bingfeng_miji")
		t = new CIbingfeng_miji();
	else if(item_name == "hanshuang_miji")
		t = new CIhanshuang_miji();
//新增道具 秦波
	else if(item_name == "hongbao")
		t = new CIhongbao();
	else if(item_name == "biaoqi")
		t = new CIbiaoqi();
	else if(item_name == "anjinmenkey")
		t = new CIanjinmenkey();
	else if(item_name == "jiashan")
		t = new CIjiashan();
	else if(item_name == "jiangzhumu")
		t = new CIjiangzhumu();
	else if(item_name == "baoguo")
		t = new CIbaoguo();
	else if(item_name == "jing_gang")
		t = new CIjing_gang();
	else if(item_name == "gangsi")
		t = new CIgangsi();
	else if(item_name == "wiz_leitaizhanbao")//擂台赛专用战报
		t = new CIwiz_leitaizhanbao();
	else if(item_name == "xiangsi_miji")//相思秘籍
		t = new CIxiangsi_miji();
	else if(item_name == "xiaohun_miji")//销魂秘籍
		t = new CIxiaohun_miji();
	else if(item_name == "redrose")
		t = new CIredrose();
	else if(item_name == "fushi")
		t = new CIfushi();
	else if(item_name == "heiyue_si")
		t = new CIheiyue_si();

	//逍遥任务中的道具	
	else if(item_name == "yingyue_si")
		t = new CIyingyue_si();
	else if(item_name == "zhuque_jin")
		t = new CIzhuque_jin();
	else if(item_name == "xuanwu_huan")
		t = new CIxuanwu_huan();
	else if(item_name == "qinglong_pao")
		t = new CIqinglong_pao();
	else if(item_name == "baihu_xue")
		t = new CIbaihu_xue();
	else if(item_name == "mupai")
		t = new CImupai();
	else if(item_name == "mupai1")
		t = new CImupai1();
	else if(item_name == "heise_huan")
		t = new CIheise_huan();
	else if(item_name == "shikuei")
		t = new CIshikuei();
	else if(item_name == "shicheng")
		t = new CIshicheng();
	else if(item_name == "shizhu")
		t = new CIshizhu();
	else if(item_name == "shiguei")
		t = new CIshiguei();
	else if(item_name == "meishu")
		t = new CImeishu();
	else if(item_name == "xueduei")
		t = new CIxueduei();
	else if(item_name == "guanmulin")
		t = new CIguanmulin();
	else if(item_name == "shen")
		t = new CIshen();
	else if(item_name == "xiaoshimo")
		t = new CIxiaoshimo();
	else if(item_name == "yaochu")
		t = new CIyaochu();
	else if(item_name == "xy_yaodan")
		t = new CIxy_yaodan();
	else if(item_name == "ciwan")
		t = new CIciwan();
	else if(item_name == "shaguan")
		t = new CIshaguan();
	else if(item_name == "xiaohuolu")
		t = new CIxiaohuolu();
	else if(item_name == "chaihe")
		t = new CIchaihe();
	else if(item_name == "zhutong")
		t = new CIzhutong();
	else if(item_name == "xueshuei")
		t = new CIxueshuei();
	else if(item_name == "wugenshuei")
		t = new CIwugenshuei();
	else if(item_name == "lushuei")
		t = new CIlushuei();
	else if(item_name == "sanqi")
		t = new CIsanqi();
	else if(item_name == "baizhi")
		t = new CIbaizhi();
	else if(item_name == "baiwei")
		t = new CIbaiwei();
	else if(item_name == "baifuzi")
		t = new CIbaifuzi();
	else if(item_name == "baiji")
		t = new CIbaiji();
	else if(item_name == "zhen_zhu")
		t = new CIzhen_zhu();
	else if(item_name == "hehua")
		t = new CIhehua();
	else if(item_name == "heye")
		t = new CIheye();

	else if(item_name == "juhua")
		t = new CIjuhua();
	else if(item_name == "baiguo")
		t = new CIbaiguo();
	else if(item_name == "hongzao")
		t = new CIhongzao();
	else if(item_name == "daohe")
		t = new CIdaohe();
	else if(item_name == "daomi")
		t = new CIdaomi();
	else if(item_name == "xinren")
		t = new CIxinren();
	else if(item_name == "mituoseng")
		t = new CImituoseng();
	else if(item_name == "hufen")
		t = new CIhufen();
	else if(item_name == "baihe")
		t = new CIbaihe();
	else if(item_name == "baixian")
		t = new CIbaixian();
	else if(item_name == "ganjiang")
		t = new CIganjiang();
	else if(item_name == "jidan")
		t = new CIjidan();
	else if(item_name == "taohua")
		t = new CItaohua();
	else if(item_name == "mudan")
		t = new CImudan();
	else if(item_name == "liandao")
		t = new CIliandao();
	else if(item_name == "daotian")
		t = new CIdaotian();
	else if(item_name == "yangshuei")
		t = new CIyangshuei();

	//小宝任务中的道具
	else if(item_name == "yinpiao")
		t = new CIyinpiao();
	else if(item_name == "xueshujian")
		t = new CIxueshujian();
	else if(item_name == "killermask1")
		t = new CIkillermask1();
	else if(item_name == "baiyupi")
		t = new CIbaiyupi();
	else if(item_name == "nixiang")
		t = new CInixiang();

	//八仙任务中的道具
	else if(item_name == "yupian")
		t = new CIyupian();
	else if(item_name == "zihulu")
		t = new CIzihulu();
	else if(item_name == "guanfu")
		t = new CIguanfu();
	else if(item_name == "cunyang_sword")
		t = new CIcunyang_sword();
	else if(item_name == "huaban")
		t = new CIhuaban();
	else if(item_name == "yanhua")
		t = new CIyanhua();
	else if(item_name == "yinpiao1")
		t = new CIyinpiao1();
	
	else if(item_name == "baoguo1")
		t = new CIbaoguo1();
	else if(item_name == "chunjie_ld")
		t = new CIchunjie_ld();
	else if(item_name == "chunjie_hb")
		t = new CIchunjie_hb();
	else if(item_name == "chunjie_yh")
		t = new CIchunjie_yh();

	else if(item_name == "zhanshu")
		t = new CIzhanshu();
	else if(item_name == "newgift")
		t = new CInewgift();

	//万安寺六派任务道具
	else if(item_name == "was_mache")
		t = new CIwas_mache();
	else if(item_name == "was_leitinglin")
		t = new CIwas_leitinglin();

	//侠客岛任务道具
	else if(item_name == "shangshan_tie")
		t = new CIshangshan_tie();
	else if(item_name == "xkd_baotu")
		t = new CIxkd_baotu();

	//彩票活动道具
	else if(item_name == "caipiao")
		t = new CIcaipiao();
	//帮派道具
	else if(item_name == "buildcorps1")
		t = new CIbuildcorps1();
	else if(item_name == "jieyinling1")
		t = new CIjieyinling1();
	else if(item_name == "bangzhuling1")
		t = new CIbangzhuling1();
	else if(item_name == "tianmen_map")
		t = new CItianmen_map();
	else if(item_name == "tradepro_item")
		t = new CItradepro_item();
	else if(item_name == "tradepro_item1")
		t = new CItradepro_item1();
	else if(item_name == "yanshiling")
		t = new CIyanshiling();
	
	return t;
}


