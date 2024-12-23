#include "stdafx.h"
#include "../std/Equip.h"
#include "../server/Container.h"
#include "../server/Char.h"
#include "../std/FightRoom.h"
//秦波 2002-03-25


// 衣服 cloth
#include "../item/cloth/pixue.h"
#include "../item/cloth/cloth.h"
#include "../item/cloth/dao_xie.h"
#include "../item/cloth/daopaocyan_cloth.h"
#include "../item/cloth/daogu_cloth.h"
#include "../item/cloth/female_shoe.h"
#include "../item/cloth/female1_cloth.h"
#include "../item/cloth/female2_cloth.h"
#include "../item/cloth/female3_cloth.h"
#include "../item/cloth/female4_cloth.h"
#include "../item/cloth/female5_cloth.h"
#include "../item/cloth/female6_cloth.h"
#include "../item/cloth/female7_cloth.h"
#include "../item/cloth/female8_cloth.h"
#include "../item/cloth/green_cloth.h" 
#include "../item/cloth/greenrobe.h" 
#include "../item/cloth/greyrobe.h"
#include "../item/cloth/gunny_shoes.h"
#include "../item/cloth/heiyi.h" 
#include "../item/cloth/hongchou.h" 
#include "../item/cloth/hongchouxiaoshan.h" 
#include "../item/cloth/huangshan.h" 
#include "../item/cloth/hui_cloth.h" 
#include "../item/cloth/huwan.h" 
#include "../item/cloth/huyao.h" 
#include "../item/cloth/hushenfu.h" 
#include "../item/cloth/jiasha.h"
#include "../item/cloth/jin.h" 
#include "../item/cloth/jindai.h" 
#include "../item/cloth/jinduan.h" 
#include "../item/cloth/jingang_zhao.h"
#include "../item/cloth/junfu.h" 
#include "../item/cloth/majia.h"
#include "../item/cloth/male_shoe.h"
#include "../item/cloth/male1_cloth.h"
#include "../item/cloth/male2_cloth.h"
#include "../item/cloth/male3_cloth.h"
#include "../item/cloth/male4_cloth.h"
#include "../item/cloth/male5_cloth.h"
#include "../item/cloth/male6_cloth.h"
#include "../item/cloth/male7_cloth.h"
#include "../item/cloth/male8_cloth.h"
#include "../item/cloth/necklace.h"
#include "../item/cloth/ni_cloth.h"
#include "../item/cloth/ni_xie.h"
#include "../item/cloth/p_jiasha.h" 
#include "../item/cloth/pink_cloth.h" 
#include "../item/cloth/piqiu.h"
#include "../item/cloth/qing_cloth.h"
#include "../item/cloth/qingpao.h" 
#include "../item/cloth/qingyi.h" 
#include "../item/cloth/r_jiasha.h" 
#include "../item/cloth/ring.h"
#include "../item/cloth/rose.h"
#include "../item/cloth/rover.h"
#include "../item/cloth/seng_cloth.h"
#include "../item/cloth/seng_xie.h"
#include "../item/cloth/sengmao.h" 
#include "../item/cloth/sengxie.h" 
#include "../item/cloth/shepi.h" 
#include "../item/cloth/shoe.h" 
#include "../item/cloth/shoutao.h" 
#include "../item/cloth/shuikao.h" 
#include "../item/cloth/shouzhuo.h"
#include "../item/cloth/tiejia.h"
#include "../item/cloth/surcoat.h" 
#include "../item/cloth/test.h"  
#include "../item/cloth/toukui.h" 
#include "../item/cloth/weibo.h" 
#include "../item/cloth/white_robe.h" 
#include "../item/cloth/wuxingfu.h" 
#include "../item/cloth/xu_cloth.h" 
#include "../item/cloth/xuan_cloth.h"
#include "../item/cloth/y_jiasha.h" 
#include "../item/cloth/yaodai.h" 
#include "../item/cloth/yayi_cloth.h"
#include "../item/cloth/ycloth.h" 
#include "../item/cloth/yupei.h"
#include "../item/cloth/zhaohong.h"
#include "../item/cloth/zhanyi.h"
#include "../item/cloth/zhenzhu.h" 
#include "../item/cloth/tiezhitao.h"
#include "../item/cloth/zichoushan.h" 

#include "../item/cloth/b_jiasha.h" 
#include "../item/cloth/baguafu.h" 
#include "../item/cloth/baichou.h" 
#include "../item/cloth/baipao.h" 
#include "../item/cloth/baiyi.h" 
#include "../item/cloth/baojia.h" 
#include "../item/cloth/bduanqun.h" 
#include "../item/cloth/beixin.h" 
#include "../item/cloth/belt.h" 
#include "../item/cloth/blackcloth.h" 
#include "../item/cloth/bluecloth.h" 
#include "../item/cloth/boots.h" 
#include "../item/cloth/bu_shoes.h" 
#include "../item/cloth/bupao.h" 
#include "../item/cloth/c_jiasha.h" 
#include "../item/cloth/caoxie.h" 
#include "../item/cloth/changpao.h" 
#include "../item/cloth/changpao2.h" 
#include "../item/cloth/cheng_cloth.h" 
#include "../item/cloth/choupao.h" 
#include "../item/cloth/cloth2.h" 
#include "../item/cloth/color_dress.h" 
#include "../item/cloth/connie.h" 
#include "../item/cloth/cuiyu.h" 
#include "../item/cloth/cycle.h" 
#include "../item/cloth/cynrobe.h" 
#include "../item/cloth/dachang.h" 
#include "../item/cloth/dao_cloth.h" 
#include "../item/cloth/diaopi.h" 
#include "../item/cloth/doupeng.h" 
#include "../item/cloth/doupeng2.h" 
#include "../item/cloth/dress.h" 
#include "../item/cloth/feather.h" 
#include "../item/cloth/fu_cloth.h" 
#include "../item/cloth/flower_shoe.h" 
#include "../item/cloth/goldring.h" 
#include "../item/cloth/goupi.h" 
#include "../item/cloth/guazi.h" 
#include "../item/cloth/gui_dress.h" 
#include "../item/cloth/hat.h"   
#include "../item/cloth/hupi.h" 
#include "../item/cloth/jade_belt.h"    
#include "../item/cloth/jinsijia.h" 
#include "../item/cloth/jjunfu.h" 
#include "../item/cloth/kenao.h" 
#include "../item/cloth/lace.h" 
#include "../item/cloth/linen.h" 
#include "../item/cloth/liu_dress.h" 
#include "../item/cloth/luo_cloth.h" 
#include "../item/cloth/magcloth.h" 
#include "../item/cloth/magua.h"  
#include "../item/cloth/maotan.h" 
#include "../item/cloth/marry_dress.h" 
#include "../item/cloth/mini_dress.h" 
#include "../item/cloth/moon_dress.h" 
#include "../item/cloth/pink_dress.h" 
#include "../item/cloth/qi_dress.h" 
#include "../item/cloth/qingyi2.h" 
#include "../item/cloth/qun.h" 
#include "../item/cloth/red_cloth.h" 
#include "../item/cloth/red_dress.h"  
#include "../item/cloth/ruanwei.h"  
#include "../item/cloth/scarf.h"   
#include "../item/cloth/sha_dress.h"  
#include "../item/cloth/shoes.h" 
#include "../item/cloth/shoupa.h" 
#include "../item/cloth/skirt.h" 
#include "../item/cloth/shudai.h" 
#include "../item/cloth/tduanqun.h" 
#include "../item/cloth/tiebeixin.h" 
#include "../item/cloth/tiehuwan.h" 
#include "../item/cloth/tiehuyao.h" 
#include "../item/cloth/tieshou.h" 
#include "../item/cloth/tongqun.h" 
#include "../item/cloth/ttoujin.h" 
#include "../item/cloth/wchangqun.h" 
#include "../item/cloth/wcloth.h" 
#include "../item/cloth/wdahui.h"  
#include "../item/cloth/whitecloth.h" 
#include "../item/cloth/whitecloth1.h" 
#include "../item/cloth/xian_cloth.h" 
#include "../item/cloth/xiaoao.h" 
#include "../item/cloth/xiu_cloth.h" 
#include "../item/cloth/xiu_scarf.h" 
#include "../item/cloth/yan_dress.h"  
#include "../item/cloth/zi_dress.h" 
#include "../item/cloth/bandage.h" 
#include "../item/cloth/mask.h" 

#include "../item/cloth/armor_1.h" 
#include "../item/cloth/marry_1.h" 
#include "../item/cloth/newyear.h" 
#include "../item/cloth/newyear1.h" 
#include "../item/cloth/century_war.h"

#include "../item/cloth/a_tiancanbaojia.h"	// 天蚕宝甲		小宝三件套
#include "../item/cloth/b_fannaomao.h"		// 烦恼全无帽	郭师太5件套装
#include "../item/cloth/b_liaochengpao.h"	// 了却尘缘袍	郭师太5件套装
#include "../item/cloth/b_yinguozhu.h"		// 因果念珠		郭师太5件套装
#include "../item/cloth/b_bolanxie.h"		// 波澜不惊鞋	郭师太5件套装
#include "../item/cloth/b_zhangmenhuan.h"	// 掌门铁指环	郭师太5件套装

#include "../item/cloth/c_jinhuantoushi.h"	// 金环头饰		黄帮主5件套装
#include "../item/cloth/c_ruanweijia.h"		// 帮主软猬甲	黄帮主5件套装
#include "../item/cloth/c_shajiezhi.h"		// 傻哥哥戒指	黄帮主5件套装
#include "../item/cloth/c_zidiaopifeng.h"	// 紫貂披风		黄帮主5件套装

#include "../item/cloth/d_dulonglian.h"		// 毒龙胆项链	欧阳公子4件套装
#include "../item/cloth/d_yinmopao.h"		// 银魔袍		欧阳公子4件套装

#include "../item/cloth/e_diaojiandai.h"	// 小可爱吊肩带 不败7件套装
#include "../item/cloth/e_poliquan.h"		// 玻璃项链		不败7件套装
#include "../item/cloth/e_yanshuhua.h"		// 艳俗大红花	不败7件套装
#include "../item/cloth/e_fengyizhen.h"		// 缝衣顶针	不败7件套装
#include "../item/cloth/e_jinlianxie.h"		// 八寸金莲鞋	不败7件套装
#include "../item/cloth/e_kuihuaao.h"		// 葵花小袄	不败7件套装

#include "../item/cloth/f_xiantianyu.h"		// 先天紫蕴精玉 真武7件套装
#include "../item/cloth/f_xuanwupao.h"		// 玄武道袍 真武7件套装
#include "../item/cloth/f_yunshenglv.h"		// 云生履 真武7件套装
#include "../item/cloth/f_qinjianhun.h"		// 玄武道袍 真武7件套装
#include "../item/cloth/f_zijianhun.h"		// 云生履 真武7件套装

#include "../item/cloth/g_luoshenjin.h"		// 洛神方巾 段公子3件套装
#include "../item/cloth/g_linboxie.h"		// 凌波鞋 段公子3件套装
#include "../item/cloth/g_zueiyupao.h"		// 缀玉华袍 段公子3件套装
#include "../item/cloth/g_hanyuzhi.h"		// 汉玉扳指 段公子3件套装
#include "../item/cloth/g_lantiandai.h"		// 蓝田玉带	段公子3件套装

#include "../item/cloth/h_cangzuihu.h"		// 长醉不愿醒酒壶	令狐少侠5件套装
#include "../item/cloth/h_rumengdai.h"		// 旧欢如梦发带		令狐少侠5件套装


CContainer * Load_Cloth(string item_name)
{
	CContainer * t = NULL;

	//  穿在身上的东西 cloth
	if(item_name == "cloth")
		t = new CICloth();
	else if(item_name == "pixue")
		t = new CIpixue();
	else if(item_name == "dao_xie")
		t = new CIDaoXie();
	else if(item_name == "daopaocyan_cloth")
		t = new CIDaoPaoCyanCloth();
	else if(item_name == "daogu_cloth")
		t = new CIdaogu_cloth();
	else if(item_name == "female1_cloth")
		t = new CIFemale1Cloth();
	else if(item_name == "female2_cloth")
		t = new CIFemale2Cloth();
	else if(item_name == "female3_cloth")
		t = new CIFemale3Cloth();
	else if(item_name == "female4_cloth")
		t = new CIFemale4Cloth();
	else if(item_name == "female5_cloth")
		t = new CIFemale5Cloth();
	else if(item_name == "female6_cloth")
		t = new CIFemale6Cloth();
	else if(item_name == "female7_cloth")
		t = new CIFemale7Cloth();
	else if(item_name == "female8_cloth")
		t = new CIFemale8Cloth();
	else if(item_name == "female_shoe")
		t = new CIFemaleShoe();
	else if(item_name == "flower_shoe")			//绣花小鞋 lanwood 2000-12-30
		t = new CIflower_shoe();		
	else if(item_name == "green_cloth")
		t = new CIgreen_cloth();
	else if(item_name == "greenrobe")
		t = new CIgreenrobe();
	else if(item_name == "greyrobe")
		t = new CIgreyrobe();
	else if(item_name == "gunny_shoes")
		t = new CIgunny_shoes();
	else if(item_name == "heiyi")
		t = new CIheiyi();
	else if(item_name == "hongchou")
		t = new CIhongchou();
	else if(item_name == "hongchouxiaoshan")
		t = new CIhongchouxiaoshan();
	else if(item_name == "huangshan")
		t = new CIhuangshan();
	else if(item_name == "hui_cloth")
		t = new CIhui_cloth();
	else if(item_name == "huwan")
		t = new CIhuwan();
	else if(item_name == "huyao")
		t = new CIhuyao();
	else if(item_name == "jiasha")
		t = new CIjiasha();
	else if(item_name == "jin")
		t = new CIjin();
	else if(item_name == "jindai")
		t = new CIjindai();
	else if(item_name == "jinduan")
		t = new CIjinduan();
	else if(item_name == "jingang_zhao")
		t = new CIjingang_zhao();
	else if(item_name == "junfu")
		t = new CIjunfu();
	else if(item_name == "majia")
		t = new CImajia();
	else if(item_name == "male1_cloth")
		t = new CIMale1Cloth();
	else if(item_name == "male2_cloth")
		t = new CIMale2Cloth();
	else if(item_name == "male3_cloth")
		t = new CIMale3Cloth();
	else if(item_name == "male4_cloth")
		t = new CIMale4Cloth();
	else if(item_name == "male5_cloth")
		t = new CIMale5Cloth();
	else if(item_name == "male6_cloth")
		t = new CIMale6Cloth();
	else if(item_name == "male7_cloth")
		t = new CIMale7Cloth();
	else if(item_name == "male8_cloth")
		t = new CIMale8Cloth();
	else if(item_name == "male_shoe")
		t = new CIMaleShoe();
	else if(item_name == "necklace")
		t = new CInecklace();
	else if(item_name == "ni_cloth")
		t = new CINiCloth();
	else if(item_name == "ni_xie")
		t = new CINiXie();
	else if(item_name == "p_jiasha")
		t = new CIp_jiasha();
	else if(item_name == "pink_cloth")
		t = new CIpink_cloth();
	else if(item_name == "piqiu")
		t = new CIpiqiu();
	else if(item_name == "qing_cloth")
		t = new CIqing_cloth();
	else if(item_name == "qingpao")
		t = new CIqingpao();
	else if(item_name == "qingyi")
		t = new CIqingyi();
	else if(item_name == "r_jiasha")
		t = new CIr_jiasha();
	else if(item_name == "ring")
		t = new CIring();
	else if(item_name == "rose")
		t = new CIrose();
	else if(item_name == "rover")
		t = new CIrover();
	else if(item_name == "seng_cloth")
		t = new CISengCloth();
	else if(item_name == "seng_xie")
		t = new CISengXie();
	else if(item_name == "sengmao")
		t = new CIsengmao();
	else if(item_name == "sengxie")
		t = new CIsengxie();
	else if(item_name == "shepi")
		t = new CIshepi();
	else if(item_name == "shoe")
		t = new CIshoe();
	else if(item_name == "shoutao")
		t = new CIshoutao();
	else if(item_name == "shuikao")
		t = new CIshuikao();
	else if(item_name == "shouzhuo")
		t = new CIshouzhuo();
	else if(item_name == "tiejia")
		t = new CITieJia();
	else if(item_name == "surcoat")
		t = new CIsurcoat();
	else if(item_name == "test")
		t = new CItest();
	else if(item_name == "toukui")
		t = new CItoukui();
	else if(item_name == "weibo")
		t = new CIweibo();
	else if(item_name == "white_robe")
		t = new CIwhite_robe();
	else if(item_name == "wuxingfu")
		t = new CIwuxingfu();
	else if(item_name == "xu_cloth")
		t = new CIxu_cloth();
	else if(item_name == "xuan_cloth")
		t = new CIxuan_cloth();
	else if(item_name == "y_jiasha")
		t = new CIy_jiasha();
	else if(item_name == "yaodai")
		t = new CIyaodai();
	else if(item_name == "yayi_cloth")
		t = new CIyayi_cloth();
	else if(item_name == "ycloth")
		t = new CIycloth();
	else if(item_name == "yupei")
		t = new CIyupei();
	else if(item_name == "zhaohong")
		t = new CIzhaohong();
	else if(item_name == "zhanyi")
		t = new CIzhanyi();
	else if(item_name == "zhenzhu")
		t = new CIzhenzhu();

	// too long
	if(t) return t;

	if(item_name == "tiezhitao")
		t = new CItiezhitao();
	else if(item_name == "zichoushan")
		t = new CIzichoushan();
	else if(item_name == "b_jiasha")
		t = new CIb_jiasha();
	else if(item_name == "baguafu")
		t = new CIbaguafu();
	else if(item_name == "baichou")
		t = new CIbaichou();
	else if(item_name == "baipao")
		t = new CIbaipao();
	else if(item_name == "baiyi")
		t = new CIbaiyi();
	else if(item_name == "baojia")
		t = new CIbaojia();
	else if(item_name == "bduanqun")
		t = new CIbduanqun();
	else if(item_name == "beixin")
		t = new CIbeixin();
	else if(item_name == "belt")
		t = new CIbelt();
	else if(item_name == "blackcloth")
		t = new CIblackcloth();
	else if(item_name == "bluecloth")
		t = new CIbluecloth();
	else if(item_name == "boots")
		t = new CIboots();
	else if(item_name == "bu_shoes")
		t = new CIbu_shoes();
	else if(item_name == "bupao")
		t = new CIbupao();
	else if(item_name == "c_jiasha")
		t = new CIc_jiasha();
	else if(item_name == "caoxie")
		t = new CIcaoxie();
	else if(item_name == "changpao")
		t = new CIchangpao();
	else if(item_name == "changpao2")
		t = new CIchangpao2();
	else if(item_name == "cheng_cloth")
		t = new CIcheng_cloth();
	else if(item_name == "choupao")
		t = new CIchoupao();
	else if(item_name == "cloth2")
		t = new CIcloth2();
	else if(item_name == "color_dress")
		t = new CIcolor_dress();
	else if(item_name == "connie")
		t = new CIconnie();
	else if(item_name == "cuiyu")
		t = new CIcuiyu();
	else if(item_name == "cycle")
		t = new CIcycle();
	else if(item_name == "cynrobe")
		t = new CIcynrobe();
	else if(item_name == "dachang")
		t = new CIdachang();
	else if(item_name == "dao_cloth")
		t = new CIdao_cloth();
	else if(item_name == "diaopi")
		t = new CIdiaopi();
	else if(item_name == "doupeng")
		t = new CIdoupeng();
	else if(item_name == "doupeng2")
		t = new CIdoupeng2();
	else if(item_name == "dress")
		t = new CIdress();
	else if(item_name == "feather")
		t = new CIfeather();
	else if(item_name == "fu_cloth")
		t = new CIfu_cloth();
	else if(item_name == "goldring")
		t = new CIgoldring();
	else if(item_name == "goupi")
		t = new CIgoupi();
	else if(item_name == "guazi")
		t = new CIguazi();
	else if(item_name == "gui_dress")
		t = new CIgui_dress();
	else if(item_name == "hat")
		t = new CIhat();
	else if(item_name == "hupi")
		t = new CIhupi();
	else if(item_name == "hushenfu")
		t = new CIhushenfu();
	else if(item_name == "jade_belt")
		t = new CIjade_belt();
	else if(item_name == "jinsijia")
		t = new CIjinsijia();
	else if(item_name == "jjunfu")
		t = new CIjjunfu();
	else if(item_name == "kenao")
		t = new CIkenao();
	else if(item_name == "lace")
		t = new CIlace();
	else if(item_name == "linen")
		t = new CIlinen();
	else if(item_name == "liu_dress")
		t = new CIliu_dress();
	else if(item_name == "luo_cloth")
		t = new CIluo_cloth();
	else if(item_name == "magcloth")
		t = new CImagcloth();
	else if(item_name == "magua")
		t = new CImagua();
	else if(item_name == "maotan")
		t = new CImaotan();
	else if(item_name == "marry_dress")
		t = new CImarry_dress();
	else if(item_name == "mini_dress")
		t = new CImini_dress();
	else if(item_name == "moon_dress")
		t = new CImoon_dress();
	else if(item_name == "pink_dress")
		t = new CIpink_dress();
	else if(item_name == "qi_dress")
		t = new CIqi_dress();
	else if(item_name == "qingyi2")
		t = new CIqingyi2();
	else if(item_name == "qun")
		t = new CIqun();
	else if(item_name == "red_cloth")
		t = new CIred_cloth();
	else if(item_name == "red_dress")
		t = new CIred_dress();
	else if(item_name == "ruanwei")			//桃花岛 软猬甲 lanwood 2000-12-29
		t = new CIruanwei();
	else if(item_name == "scarf")
		t = new CIscarf();
	else if(item_name == "sha_dress")
		t = new CIsha_dress();
	else if(item_name == "shoes")
		t = new CIshoes();
	else if(item_name == "shoupa")
		t = new CIshoupa();
	else if(item_name == "skirt")
		t = new CIskirt();
	else if(item_name == "shudai")			//桃花岛 束法金带 lanwood 2000-12-29
		t = new CIshudai();
	else if(item_name == "tduanqun")
		t = new CItduanqun();
	else if(item_name == "tiebeixin")
		t = new CItiebeixin();
	else if(item_name == "tiehuwan")
		t = new CItiehuwan();
	else if(item_name == "tiehuyao")
		t = new CItiehuyao();
	else if(item_name == "tieshou")
		t = new CItieshou();
	else if(item_name == "tongqun")
		t = new CItongqun();
	else if(item_name == "ttoujin")
		t = new CIttoujin();
	else if(item_name == "wchangqun")
		t = new CIwchangqun();
	else if(item_name == "wcloth")
		t = new CIwcloth();
	else if(item_name == "wdahui")
		t = new CIwdahui();
	else if(item_name == "whitecloth")
		t = new CIwhitecloth();
	else if(item_name == "whitecloth1")
		t = new CIwhitecloth1();
	else if(item_name == "xian_cloth")
		t = new CIxian_cloth();
	else if(item_name == "xiaoao")
		t = new CIxiaoao();
	else if(item_name == "xiu_cloth")
		t = new CIxiu_cloth();
	else if(item_name == "xiu_scarf")
		t = new CIxiu_scarf();
	else if(item_name == "yan_dress")
		t = new CIyan_dress();
	else if(item_name == "zi_dress")
		t = new CIzi_dress();
	else if(item_name == "bandage")
		t = new CIbandage();
	else if(item_name == "mask")
		t = new CImask();

	else if(item_name == "armor_1")
		t = new CIarmor_1();
	else if(item_name == "marry_1")
		t = new CImarry_1();
	else if(item_name == "newyear")
		t = new CInewyear();
	else if(item_name == "newyear1")
		t = new CInewyear1();
	else if(item_name == "century_war")
		t = new CIcentury_war();
	else if(item_name == "tiancanbaojia")
		t = new CItiancanbaojia();
	else if(item_name == "fannaomao")
		t = new CIfannaomao();
	else if(item_name == "liaochengpao")
		t = new CIliaochengpao();
	else if(item_name == "yinguozhu")
		t = new CIyinguozhu();
	else if(item_name == "bolanxie")
		t = new CIbolanxie();
	else if(item_name == "zhangmenhuan")
		t = new CIzhangmenhuan();
	else if(item_name == "jinhuantoushi")
		t = new CIjinhuantoushi();
	else if(item_name == "ruanweijia")
		t = new CIruanweijia();
	else if(item_name == "shajiezhi")
		t = new CIshajiezhi();
	else if(item_name == "zidiaopifeng")
		t = new CIzidiaopifeng();
	else if(item_name == "dulonglian")
		t = new CIdulonglian();
	else if(item_name == "yinmopao")
		t = new CIyinmopao();
	else if(item_name == "diaojiandai")
		t = new CIdiaojiandai();
	else if(item_name == "xiantianyu")
		t = new CIxiantianyu();
	else if(item_name == "poliquan")
		t = new CIpoliquan();
	else if(item_name == "yanshuhua")
		t = new CIyanshuhua();
	else if(item_name == "fengyizhen")
		t = new CIfengyizhen();
	else if(item_name == "jinlianxie")
		t = new CIjinlianxie();
	else if(item_name == "kuihuaao")
		t = new CIkuihuaao();

	else if(item_name == "xuanwupao")
		t = new CIxuanwupao();
	else if(item_name == "yunshenglv")
		t = new CIyunshenglv();
	else if(item_name == "zijianhun")
		t = new CIzijianhun();
	else if(item_name == "qinjianhun")
		t = new CIqinjianhun();
	else if(item_name == "luoshenjin")
		t = new CIluoshenjin();
	else if(item_name == "linboxie")
		t = new CIlinboxie();
	else if(item_name == "zueiyupao")
		t = new CIzueiyupao();
	else if(item_name == "hanyuzhi")
		t = new CIhanyuzhi();
	else if(item_name == "lantiandai")
		t = new CIlantiandai();

	else if(item_name == "cangzuihu")
		t = new CIcangzuihu();
	else if(item_name == "rumengdai")
		t = new CIrumengdai();

	return t;
}



