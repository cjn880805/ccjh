// Npc.cpp: implementation of the CNpc class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Npc.h"
#include "Globle.h"
#include "../std/FightRoom.h"
#include "Room.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CNpc::~CNpc()
{
	LISTINQUIRY::iterator p;

	for(p = m_listInquiry.begin(); p != m_listInquiry.end(); p++)
		delete p->second;

	m_listInquiry.clear();
}

LONG CNpc::Query(int nAttr)
{
	if( nAttr == IS_NPC )
		return 1;
	
	return CChar::Query(nAttr);
}

//随机行动
int CNpc::Self_Action()
{
	int chance;
	const char * ptr = NULL;

	if( !environment() ) return 0;
	if( ! living(this)) return 0;

	if( ! (chance = is_fighting() ? query("chat_chance_combat") : query("chat_chance")) )
		return 0;

	if( random(100) < chance )
	{
		if(is_fighting())
		{
			//判断一下是否在战斗room
			if(environment()->Query(IS_FIGHTROOM))
				ptr = chat_msg_combat();
			else
				output_error("NPC%s在环境%s中出于战斗状态！", name(), environment()->name());
		}
		else
			ptr = chat_msg();

		if(ptr && ptr[0])
			MessageVision(this, "chat", ptr);

		return 1;
    }

	return 0;
}

char * CNpc::chat_msg()
{
	return 0;
}

char * CNpc::chat_msg_combat()
{
	return 0;
}

//回到该回的地方去
int CNpc::return_home(CContainer *home)
{
	if( !environment() || environment() == home )
		return 1;

	if( ! Query(IS_LIVING) ) return 0;	//no return
	double value = 300;		//超过5分钟战斗的NPC自动回去
	time_t t;
	time(&t);
	t -= (time_t)value;	

	if( is_fighting() && (time_t)query_temp("fight/join_time")>t) return 0;	//is fighting
  
	// Leave for home now.
	message_vision("$N匆匆忙忙离开了。", this);
	move(home);
	return 1;
}

void CNpc::create()
{
	
}

//携带物件
CContainer * CNpc::carry_object(const char * obj_name, LONG nAmount, int idx)
{
	CContainer * item;

	item = load_item(obj_name);
	
	if(idx) item->create(idx);

	if(nAmount > 0)
		item->set_amount(nAmount);
	else
		item->set_amount(1);
	/*
	if(item->Query(UNIQUE)
	*/

	item->move(this);
	return item;
}

CNpc * random_npc();

const char * position_npc(CChar * npc)
{
	CContainer * env = npc->environment();
	if(! env) return 0;	//失败
	if(env->query("no_fight")) return 0;	//非战斗区。
	if(EQUALSTR(env->querystr("area"), "house")) return 0;	//玩家住宅

	while(env->environment())
		env = env->environment();

	return env->name(1);
}

void reward_tradepro(CChar * me)
{
	//先给玩家进行奖励

	char msg[255];
	LONG exp = me->query("level");
	static char GoodItem[45][40] = 
	{
	"38huoqiang","tiancanbaojia",	"xuantiebishou","fannaomao",
	"liaochengpao","yinguozhu",	"bolanxie","zhangmenhuan",
	"jinhuantoushi","dagoubang",	"ruanweijia","shajiezhi",
	"zidiaopifeng","haoseshan",	"dulonglian","shenshe_staff",
	"yinmopao","btzheng",	"diaojiandai","poliquan",
	"yanshuhua","fengyizhen",	"jinlianxie","kuihuaao",
	"taibaizao","xiantianyu",	"zwsword","xuanwupao",
	"yunshenglv","qinjianhun",	"zijianhun","luoshenjin",
	"linboxie","zueiyupao",	"hanyuzhi","lantiandai",
	"lvzhuxiao","conglinjian",	"cangzuihu","rumengdai",
	"chunjie_ts","buildcorps1","tianmen_map","qunxing_tu","conglinjian",
	};
/*
	char tmp[40];
	int base=7;
	if(me->query("int")>60)
		base++;

	exp = exp * base;

	int count=me->query("tradepro/quest_count");
	
	exp = exp*(5000+base*(count%10))/5000;

	exp = (random(exp) + exp) / 2;

	if(exp>100000)
		exp=random(500)+100000;
*/
	//新增加经验计算公式 2005、4、11
	int count=me->query("tradepro/quest_count");
	exp=exp*2;
	exp=exp+(exp+me->query("int")*2)*int(count/10+count%10);
	//
	me->add("combat_exp", exp);

	count++;
/*
	int contribute=count*10+random(count);
	int money=count;

	me->add("corps/contribute",contribute);
	me->add("corps/money",money);
*/
	me->FlushMyInfo();
	tell_object(me, snprintf(msg, 255, "$HIC恭喜你完成了「仗剑江湖」的第%d个任务，获得了%d点经验。", count,exp));
	if(me->query("tradepro/quest_count")%100==0 && me->query("tradepro/quest_count")>99)
	{
		CContainer * good_item=load_item(GoodItem[random(45)]);
		tell_object(me, snprintf(msg, 255, "$HIR同时你获得了%s的奖励。", good_item->name(1)));
		good_item->move(me);
	}
	me->del("tradepro");
//	tell_object(me, snprintf(msg, 255, "$HIC恭喜你完成了「仗剑江湖」的第%d个任务，获得了%s点经验，同时获得了%d点的帮派贡献度、%d点的帮派财富。", count,chinese_number(exp, tmp),contribute,money));
	if(count<=600)
		me->set("tradepro/quest_count",count);
	else
	{
		me->del("tradepro");
		return ;
	}

	static char index1[537][40] = {
		"blade_1","blade_2","cleansword","dadao","zimuzhen",
			"dadao2","dafu","dagger","duanjian","fenshuici","fork","fuchen","futou",
			"hammer","heilongbian",	"hothammer","huaji","huoqiang","jinhua","jinlun",
			"jiujiebian","kandao","kuihuazhen","leizhendang","mandao","panguanbi",
			"putongbishou","qimeigun","qin","qingzugang","qingzuzang","qinqin_sword","ruanjian",
			"senggun","shebian","shenghuo_ling","shezhang","shield","shunvjian","shutonggun","snowsword","sword_1",
			"sword_2","sword_3","tiepipa","tongren","walkingstick","wandao","wodao","xblade",
			"xiao","xiuhua","xuantiesword","yangbian","yaochu","yaoqin","yinlun",
			"yufeng_zhen","yuxiao","yuzhu_zhang","zijin_staff",
			"cloth","pixue","dao_xie","daopaocyan_cloth","female1_cloth","female2_cloth","female3_cloth",
			"female6_cloth","flower_shoe","green_cloth","greenrobe","greyrobe","gunny_shoes","hui_cloth",
			"huwan","huyao","jin","jindai","jinduan","junfu","male1_cloth",
			"male3_cloth","male4_cloth","male6_cloth","male7_cloth","male8_cloth","male_shoe","necklace",
			"ni_cloth","ni_xie","pink_cloth","piqiu","qing_cloth","qingyi","r_jiasha","ring",
			"seng_cloth","seng_xie","sengmao","sengxie","shepi","shoe","shoutao","shuikao","shouzhuo","tiejia",
			"surcoat","test","toukui","white_robe","wuxingfu","xu_cloth","xuan_cloth","y_jiasha","yaodai",
			"yayi_cloth","ycloth","yupei","zhanyi","zhenzhu","tiezhitao","zichoushan","b_jiasha","baguafu",
			"baichou","baipao","bduanqun","beixin","belt","blackcloth","bluecloth","boots","bu_shoes",
			"bupao","c_jiasha","caoxie","changpao","changpao2","cheng_cloth","choupao","cloth2","connie",
			"cuiyu","cycle","cynrobe","dao_cloth","doupeng","dress","feather","fu_cloth",
			"goldring","goupi","guazi","gui_dress","hat","hupi","hushenfu","jade_belt","jinsijia","jjunfu","kenao","lace",
			"linen","liu_dress","magcloth","magua","marry_dress","mini_dress","moon_dress","pink_dress",
			"qi_dress","qun","red_dress","ruanwei","scarf","sha_dress","shoes","shoupa","skirt",
			"shudai","tduanqun","tiebeixin","tiehuwan","tiehuyao","tieshou","tongqun","ttoujin","wchangqun","wcloth","wdahui",
			"whitecloth","whitecloth1","xian_cloth","xiaoao","xiu_cloth","xiu_scarf","yan_dress","zi_dress","mask",
			"baihe","baozi","duanchang","gourou","guijia","guiyuan","heiyugao","honghua",
			"jinchuang","jitui","jiudai","jindan","kaoya","marz","menghan_yao","mizhitianou","moyao",
			"nverhong","peanut","putizi","qingdan","qingke_m","renshen",
			"shedan","shedangao","sherou","turou","x_drug","xionghuang",
			"yadan","yangxin","yuchandan","zongzi","zhutou","zhujingchan","yangjing","xiang","gao","egg","dahuan_dan",
			"cha","caomei","cake","luobo","caogeng","jingxin_san","honey",
			"book_paper","parry_book","hand_book","strike_book","book_stone","dodgebook","force_book","yijing0","book_silk",
			"yijing1","wuji3","wuji2","throw_book","staff_book","staff_book","lbook1","lbook2","yunv_swordb",
			"yunvjing1","lbook3","miaoshou","xuanfeng_book","yijinjing","yunvjing2","lbook3","miaoshou",
			"zhengqi_book","18muou","sword_book1","skin","literateb4","dodgebook","book_iron",
			"cleansword","snowsword","ruanjian","qin","leizhendang","qingzuzang","jinlun",
			"zijin_staff","sword_2","sword_3",
			"zongzi","backleg","yangrou","turou","tofu","puercha","paomo","mizhitianou","mala_doufu",
			"furong_huagu","baozi2","mixian","huotui","hamigua","luobo","geng","gao4","shedan",
			"zaisheng","suanmei","niupidai","changbian","changjian","changqiang","chanzhang",
			"dadao2","feihuangshi","fenshuici","fork","fuchen","futou","gangdao","gangjian",
			"gangzhang","hammer","jiandao","mutang","senggun","shebian","shield","shortblade",
			"wandao","wodao","xiuhua","yuxiao","zheshan","zhubang","b_jiasha","changpao","choupao",
			"dao_cloth","doupeng2","hat","huangshan","hui_cloth","hupi","jiasha","junfu","piqiu",
			"qingyi2","sengmao","seng_cloth","shepi","shoe","shoes","shuikao","tiebeixin","toukui",
			"wchangqun","xian_cloth","map","yadan","xiaren2","shanhu_baicai","rice","nang","liuli_qiezi",
			"kaoyangtui","kaoya","jiaxin_biji","gourou","birddie","basi_shanyao","yezi","yangjing",
			"xueli","suya","yaopin_2","yaopin_1","heiyue_si",
			"suji","mangguo","huotui2","gao","gaoyao","gao3","ping","dadao","gangbiao","heilongbian",
			"jiedao","panguanbi","qimeigun","qin","shezhang","shortsword","shutonggun","tielianzi",
			"tiepipa","tie_gan","tongren","tudao","zijinchui","changpao2","cheng_cloth",
			"daopaocyan_cloth","jindai","jjunfu","ni_cloth","ni_xie","pink_cloth","p_jiasha",
			"yaopin_2","yaopin_1","transfer_tie","zhuguo",
			"baihongjian","bilinzhen","bishou","blade_1","blade_2","cleansword","dadao","zimuzhen",
			"dadao2","dafu","dagger","duanjian","fandog_sword","fenshuici","fork","fuchen","futou","green_sword",
			"green_water_sword","hammer","heilongbian",	"hothammer","huaji","hugesword","huoqiang","jinhua","jinlun",
			"jiujiebian","kandao","kuihuazhen","langyabang","leizhendang","longquansword","mandao","panguanbi",
			"putongbishou","qimeigun","qin","qingzugang","qingzuzang","qinqin_sword","ring_whip","ruanjian","sea_wood",
			"senggun","shebian","shenghuo_ling","shezhang","shield","shunvjian","shutonggun","snowsword","sword_1",
			"sword_2","sword_3","taomujian","tiepipa","tongren","walkingstick","wandao","wodao","wuqing_sword","xblade",
			"xem_sword","xiao","xiuhua","xuantiesword","xuedao","yangbian","yaochu","yaoqin","yinlun","youlongsword",
			"yufeng_zhen","yuxiao","yuzhu_zhang","zijinchui","zijin_staff",
			"38huoqiang","xuantiebishou","dagoubang","shenshe_staff","haoseshan","btzheng","taibaizao","zwsword",
			"lvzhuxiao","conglinjian","newyear","newyear1","century_war","tiancanbaojia","fannaomao","liaochengpao",
			"yinguozhu","bolanxie","zhangmenhuan","jinhuantoushi","ruanweijia","shajiezhi","zidiaopifeng","dulonglian",
			"yinmopao","diaojiandai","xiantianyu","poliquan","yanshuhua","fengyizhen","jinlianxie","kuihuaao","xuanwupao",
			"yunshenglv","zijianhun","qinjianhun","luoshenjin","linboxie","zueiyupao","hanyuzhi","lantiandai","cangzuihu",
			"rumengdai",
	};

	static char index1_1[5][255] =
	{
		"近日$HIW%s$COM由于大意，丢失了$HIW%s$COM，很是懊恼，麻烦你帮忙去找一个送去。",
			"$HIW%s$COM前日到我这里来闲聊，提到$HIW%s$COM，很是喜欢。我因有事在身，还是烦请你多辛苦一趟买去送他。",
			"这几日传言，$HIW%s$COM正在大肆搜集$HIW%s$COM，你有空是否找一个送去看看他意图何为？",
			"$HIW%s$COM正急需一件$HIW%s$COM，如你有空，不妨帮忙给他送去。",
			"此前我曾应承$HIW%s$COM去寻找一件$HIW%s$COM送去，但一直不得空暇，今日还请你多帮忙寻觅，并一并送去。",
	};

	static char index2[5][255] =
	{
		"好久不见$HIW%s$COM了，麻烦你去找到他说我想念他。",
			"$HIW%s$COM前段时间来上门来拜访，我一直都没时间回访,烦请你替我去看看他。",
			"$HIW%s$COM已经失踪很久了,你是否有空替我去找下他，看看最近他怎么样了？",
			"我很想念$HIW%s$COM，你能不能替我送个口信给他，并替我问候他。",
			"前段时间我答应$HIW%s$COM去游山玩水的，但一直忙，请你跟他说声我最近有空，可以一起结伴而行。",
	};

	static char index3[5][255] =
	{
		"不久前$HIW%s$COM的全家被$HIW%s$COM杀了，你能替他报仇吗？",
			"$HIW%s$COM的兄长被最近在江湖上乱杀无辜的$HIW%s$COM杀了，烦劳你去帮他为武林除一大害。",
			"$HIW%s$COM传出消息，$HIW%s$COM是江洋大盗，如果你能杀了他，就可以找他领取一笔花红。",
			"$HIW%s$COM的弟子，在行走江湖时被恶霸$HIW%s$COM打伤了，还请你去杀了他，为他报仇。",	
			"此前我曾答应$HIW%s$COM，为他杀了$HIW%s$COM，送去首级，但如今我功力全失，还请你多帮忙。",
	};

	static char index4[5][255] =
	{
		"前日$HIW%s$COM的日月棍被$HIW%s$COM偷了，你去帮他抓了那个小偷。",
			"$HIW%s$COM正在通缉$HIW%s$COM，烦劳你去抓了他。",
			"$HIW%s$COM撒下武林帖，谁要缉拿$HIW%s$COM归案，重重有赏。",
			"$HIW%s$COM的仇家恶霸$HIW%s$COM又在江湖胡作非为了，还请你帮忙帮他去抓。",	
			"我的朋友$HIW%s$COM前段时间因为散功，被地痞$HIW%s$COM打了一顿，你能抓住那个地痞给他送去吗？",
	};

	static char index5[5][255] =
	{
		"几天前$HIW%s$COM在$HIW%s$COM被打了，你能替他去那里维持治安吗？",
			"有消息传出$HIW%s$COM在重赏整顿$HIW%s$COM的治安，烦劳你去帮他在那里巡逻几天。",
			"$HIW%s$COM所在的$HIW%s$COM最近暴力事件很多，请你在那带帮他负责维持秩序。",
			"$HIW%s$COM想去$HIW%s$COM附近看朋友，可是那里最近不安全，请你帮他去那一带巡逻吧。",	
			"我曾答应$HIW%s$COM，替他负责$HIW%s$COM一带的治安，最近我没有闲暇，还请你帮他这个忙。",
	};

	static char index6[16][20] = 
	{
		"白驼山派",	"大理段家",	"峨嵋派", "丐帮","古墓派", "华山派","灵鹫宫", "明教",
			"全真教","少林派","神龙教","桃花岛","武当派","逍遥派","星宿派","雪山寺",
	};

	static char index6_1[5][255] =
	{
		"最近$HIW%s$COM在悦来客栈被$HIW%s$COM的弟子打了，你能去警告下他们吗？",
			"$HIW%s$COM的妹妹被$HIW%s$COM抢去了，最近他们恶行不断，你出手教训他们下。",
			"此前我曾应承$HIW%s$COM，为他出手教训作恶多端的$HIW%s$COM，但如今我没有时间，还请你多帮忙。",
			"$HIW%s$COM放出风来，$HIW%s$COM最近嚣张之极，干尽坏事。谁能去杀一儆百的话，将有重赏。",
			"这几日$HIW%s$COM的弟弟，路过佛山被$HIW%s$COM伤了，还请你去教训他们下。",	
	};

	static char index7[5][255] =
	{
		"$HIW贵帮使者$COM想去保镖，需要$HIW%s(%s)$COM帮忙，你能替他找来吗？",
			"听说$HIW贵帮使者$COM想去泰山寻宝，他想约$HIW%s(%s)$COM一起去，烦劳你帮忙通知一声。",
			"$HIW贵帮使者$COM要去谈判，要召集$HIW%s(%s)$COM，可是没找到，麻烦你去找一下。",
			"$HIW贵帮使者$COM想要和$HIW%s(%s)$COM一起去做笔大买卖，还请你去通知他。",	
			"此前我曾答应$HIW贵帮使者$COM，帮他找到$HIW%s(%s)$COM，但现在我无暇分身，还请你帮忙。",
	};

	static char index8[5][255] =
	{
		"$HIW%s$COM想要你做他的保镖，但以你目前的状况，必须提高$HIW%s %d$COM点方可，你要去帮忙吗？",
			"听说$HIW%s$COM正在招收勇士，你的条件非常符合，但还差了$HIW%s %d$COM点，你尽快去提高吧。",
			"$HIW%s$COM传出消息，需要找一个合伙人，但你现在必须提高$HIW%s %d$COM点，你想要去吗？",
			"最近$HIW%s$COM想找你帮他上泰山取回宝物，但你的$HIW%s$COM不够，还请你努力提高$HIW%d$COM点。",	
			"$HIW%s$COM想要你为他杀了作恶多端的恶贼，依你目前的情况来看，必须提高$HIW%s %d$COM点，还请你尽快去努力。",
	};

	static char index9[5][255] =
	{
		"最近$HIW%s$COM的镖局生意一直不好，你能去看我的面子上，替我帮帮他？",
			"$HIW%s$COM的兄长在走镖时被强人所杀，麻烦你去帮他兄长完成他未完成的遗愿，护送镖车走完最后一趟？。",
			"$HIW%s$COM传出消息，谁能在今天安全押上一镖，就可以去找他领取一笔花红。",
			"$HIW%s$COM的镖车被截了，但现在急需去找个武功了得的镖师，不知道你可有意否？",	
			"此前我曾答应$HIW%s$COM，帮他去保一次镖，但如今我无法分身，还请你多帮忙。",
	};

	static char index10[5][255] =
	{
		"前几日$HIW%s$COM的全家在山东道上遇险，幸好被$HIW%s$COM的大侠$HIW%s$COM所救，但大侠也此得罪了梅山七凶，你能去保护他吗？",
			"$HIW%s$COM住在$HIW%s$COM的好友$HIW%s$COM孤身闯入金兵大寨，现在形式危机，烦劳你去快去帮忙，确保他安然无恙。",
			"听说$HIW%s$COM传出武林帖，保护住在$HIW%s$COM的民族英雄$HIW%s$COM，如果你能去帮忙，就太好了。",
			"我的好友$HIW%s$COM一位偷跑到$HIW%s$COM的心爱的弟子$HIW%s$COM被梅山七怪困住，还请你保他平安。",	
			"我曾应承我的好友$HIW%s$COM，替他保护现在正在$HIW%s$COM游玩的$HIW%s$COM，但如今我功力全失，还请你多帮忙。",
	};

	static char index11[5][255] =
	{
		"最近$HIW%s$COM的新店开张，你替我送$HIW%d$COM两银子过去，谢谢他这么多年罩着我。至于钱你就先垫着，过个百八十年的我就还你。",
			"$HIW%s$COM最近大倒霉运，全部家当被火一烧而光，看在几十年的情分上，烦劳你替我送$HIW%d$COM两银子过去。至于钱你就先垫着，要不了百八十年的我就还你。",
			"$HIW%s$COM传出绿林令，近期将召开海吃大会，他我可惹不起，你快点帮我送$HIW%d$COM两银子过去给他张罗吧。至于钱你就先垫着，百八十年的我就攒够了就还你。",
			"前些日子$HIW%s$COM传出话来，说他手头很紧，还请你帮忙凑上个$HIW%d$COM两的银子送去。至于钱你就先垫着，过个百八十年的如果我能有的话就还你。",	
			"此前我曾答应$HIW%s$COM，借他$HIW%d$COM两的银子，还请你辛苦跑上一趟送去。至于钱你就先垫着，呆上个百八十年的等我的私房钱攒够了就还你。",
	};

	static char index12[5][255] =
	{
		"不久前$HIW%s$COM救了我的命，麻烦你拿着这个$HIW%s$COM送过去，以表我的谢意。",
			"前些日子$HIW%s$COM的儿子，看中了我的$HIW%s$COM，我可不想得罪他家，还请你帮忙送去。",	
			"$HIW%s$COM传出消息，急需$HIW%s$COM，我手头正好有，还请你替我送去。",
			"最近几年$HIW%s$COM的儿子在秘密研制一种暗器，独缺$HIW%s$COM，还请你送去给他。",	
			"此前我曾答应$HIW%s$COM，把$HIW%s$COM送去的，我这段时间公务繁忙，还请你多帮忙。",
	};

	static char index13[32][20] = 
	{
		"小笼包","茶叶蛋","糖葫芦","芝麻酥","北京果脯",	"杏仁露","烤鹅","茶汤",	
		"二锅头","牛肉羹","归元丹","回神膏","补气丸","百花聚精膏","回血膏","接骨散",
		"天仙玉露","九转回神丹","天香续命膏","大还丹","宫廷秘方","七叶一枝","紫花景天","石南藤", 
		"翻天印","五子连环草","灯心","七结","一叶","丹枫","石苇","九命",
	};

	static char index13_1[5][255] =
	{
		"前不久$HIW%s$COM来我这里，说在收集$HIW%d$COM份的$HIW%s$COM，你能替他找到吗？",
			"$HIW%s$COM要出一味新药，药引里还缺$HIW%d$COM个$HIW%s$COM，烦劳你去找回来送给他。",
			"$HIW%s$COM在研究一种秘方，需要$HIW%d$COM份的$HIW%s$COM，请你去找齐给他。",
			"$HIW%s$COM今日请了很多朋友去他家吃饭里，但缺少了$HIW%d$COM份的$HIW%s$COM，还请你帮他去找来。",	
			"我应承过$HIW%s$COM，为他找齐$HIW%d$COM份的$HIW%s$COM，但如今我无暇分身，还请你多帮忙找齐给他。",
	};

	static char index14[5][255] =
	{
		"前几天$HIW%s$COM来我这里，说在找杀兄仇人$HIW%s$COM的画像，你能替他找到吗？",
			"$HIW%s$COM要写江湖奇侠记，但书里还缺少$HIW%s$COM的画像，烦劳你去找回来。",
			"听说$HIW%s$COM仰慕$HIW%s$COM很久，很想珍藏一份他的画像，请你去找来给他。",
			"$HIW%s$COM的江湖十大恶人像里，唯独缺少了$HIW%s$COM的画像，你能不能替他找到？",	
			"我答应过$HIW%s$COM，为他找到$HIW%s$COM的画像，可是我始终都找不到，还请你多帮忙。",
	};

	//再给玩家安排下一个任务
	CNpc * npc;
	CContainer * env;
	CContainer * item_quest;
	CContainer * tradepro_item;
	CMapping * enemy;
	CRoom * r;
	int i;
	const char * area;
	//随机取一个NPC的场景
//	while()
	for(i=0;i<10000;i++)
	{
		npc = random_npc();
		
		if(! npc ) continue;
		if(! living(npc)) continue;	//这个NPC快不行了。
		if(DIFFERSTR(npc->querystr("race"), "人类") ) continue;	//非人类NPC
		if(npc->query("no_kill")) continue;	//是一般玩家不可能找到的随机怪物
		if(npc->query("mfnpc_lvl")) continue;	//是梦泽山的随机怪物
		if(npc->query("no_talk")) continue;	//这个NPC有特殊设置
		if(npc->query("no_huan")) continue;	//这个NPC有特殊设置
		
		env = npc->environment();
		
		//现在判断NPC大致的方位
		area = position_npc(npc);
		if(! area ) continue;	//这个NPC没有环境
		if(! area[0]) continue;	//这个NPC在玩家房间或者战斗中。
		if(EQUALSTR(env->querystr("area"), "fight") ) continue;	//这个NPC在玩家房间或者战斗中。
		if(EQUALSTR(env->querystr("area"), "野外") ) continue;	//这个NPC在野外。
		if(env->query("renwu") ) continue;	//这个NPC在特殊任务的房间中。
		break;
	}
	
	int index=random(14)+1;
	if(index==5 || index==7)
		index=1;
	me->set("tradepro/quest_npc_id",npc->querystr("id"));
	me->set("tradepro/quest_npc_name",npc->querystr("name"));
	me->set("tradepro/quest_npc_area",env->querystr("name"));
	me->set("tradepro/index",index);

	double value = 1800;		//30分钟
	time_t t;
	time(&t);
	t += (time_t)value;	

	me->set("tradepro/quest_time",t);

	switch(index)
	{
	case 1://买东西
		if(me->query("tradepro/quest_count")>300)
			item_quest=load_item(index1[random(537)]);
		else
			item_quest=load_item(index1[random(300)]);
		me->set("tradepro/quest_item_name",item_quest->querystr("name"));
		me->set("tradepro/quest_item_id",item_quest->querystr("id"));
		tell_object(me, snprintf(msg, 255, index1_1[random(5)], me->querystr("tradepro/quest_npc_name"),me->querystr("tradepro/quest_item_name")));
		break;
	case 2://找人
	case 3://杀人
	case 4://抓俘虏
	case 10://保护某NPC一定时间不被杀
	case 14://绘画NPC画像
		//指定欲操作的NPC
		for(i=0;i<10000;i++)
		{
			npc = random_npc();
			
			if(! npc ) continue;
			if(! living(npc)) continue;	//这个NPC快不行了。
			if(DIFFERSTR(npc->querystr("race"), "人类") ) continue;	//非人类NPC
			if(npc->query("no_kill")) continue;	//是一般玩家不可能找到的随机怪物
			if(npc->query("mfnpc_lvl")) continue;	//是梦泽山的随机怪物
//			if(npc->query("no_talk")) continue;	//这个NPC有特殊设置
			
			env = npc->environment();
			
			//现在判断NPC大致的方位
			area = position_npc(npc);
			if(! area ) continue;	//这个NPC没有环境
			if(! area[0]) continue;	//这个NPC在玩家房间或者战斗中。
			if(EQUALSTR(env->querystr("area"), "fight") ) continue;	//这个NPC在玩家房间或者战斗中。
			if(EQUALSTR(env->querystr("area"), "野外") ) continue;	//这个NPC在野外。
			if(env->query("renwu") ) continue;	//这个NPC在特殊任务的房间中。
			break;
		}
		me->set("tradepro/quest_killnpc_id",npc->querystr("id"));
		me->set("tradepro/quest_killnpc_object_id", npc->object_id());
		me->set("tradepro/quest_killnpc_name",npc->querystr("name"));
		if(index==2)
			tell_object(me, snprintf(msg, 255, index2[random(5)], me->querystr("tradepro/quest_npc_name")));
		else if(index==3)
			tell_object(me, snprintf(msg, 255, index3[random(5)], me->querystr("tradepro/quest_npc_name"),me->querystr("tradepro/quest_killnpc_name")));
		else if(index==4)
			tell_object(me, snprintf(msg, 255, index4[random(5)], me->querystr("tradepro/quest_npc_name"),me->querystr("tradepro/quest_killnpc_name")));
		else if(index==10)
		{
			npc->set("ok",1);
			value = 300;		//5分钟
			time_t clock;
			time(&clock);
			clock += (time_t)value;	
			me->set("tradepro/quest_killnpc_time",clock);
			me->set("tradepro/quest_killnpc_id",npc->object_id());
			me->set("tradepro/quest_killnpc_area",env->querystr("name"));
			tell_object(me, snprintf(msg, 255, index10[random(5)], me->querystr("tradepro/quest_npc_name"), me->querystr("tradepro/quest_killnpc_area"), me->querystr("tradepro/quest_killnpc_name")));
		}
		else
			tell_object(me, snprintf(msg, 255, index14[random(5)], me->querystr("tradepro/quest_npc_name"),me->querystr("tradepro/quest_killnpc_name")));
		break;
	case 5://巡逻(还需要增加巡逻时候的战斗)
		me->set("tradepro/quest_killnpc_mp",env->querystr("area"));
		tell_object(me, snprintf(msg, 255, index5[random(5)], me->querystr("tradepro/quest_npc_name"),me->querystr("tradepro/quest_killnpc_mp")));
		break;
		break;
	case 6://示威
		me->set("tradepro/quest_killnpc_mp",index6[random(16)]);
		tell_object(me, snprintf(msg, 255, index6_1[random(5)], me->querystr("tradepro/quest_npc_name"),me->querystr("tradepro/quest_killnpc_mp")));
		break;
	case 7://聚集帮众
		r = load_room(me->querystr("corps/id"));
		enemy = r->querymap("list");
		if(! enemy) //假如没有会员则改变任务为买东西
		{
			if(me->query("tradepro/quest_count")>300)
				item_quest=load_item(index1[random(537)]);
			else
				item_quest=load_item(index1[random(300)]);
			me->set("tradepro/quest_item_name",item_quest->querystr("name"));
			me->set("tradepro/quest_item_id",item_quest->querystr("id"));
			me->set("tradepro/index",1);
			tell_object(me, snprintf(msg, 255, index1_1[random(5)], me->querystr("tradepro/quest_npc_name"),me->querystr("tradepro/quest_item_name")));
		}
		else
		{
			CVector v;
			enemy->keys(v);
			me->set("tradepro/quest_killnpc_id",v[random(v.count())]);
			me->set("tradepro/quest_killnpc_name",enemy->querystr(v[random(v.count())]));
			if(r->query("index")==1)
			{
				CContainer * CorpsNpc;
				if(r->query("level")<3)
				{
					r=load_room(snprintf(msg, 255, "g1_新月大殿_%s",me->querystr("corps/id")));
					CorpsNpc=r->present("xinshang zhizhe");
				}
				else
				{
					r=load_room(snprintf(msg, 255, "g1_天仙阁_%s",me->querystr("corps/id")));
					CorpsNpc=r->present("qing xia");
				}
				if(!CorpsNpc)
				{
					me->del("tradepro/quest_killnpc_id");
					me->del("tradepro/quest_killnpc_name");
					if(me->query("tradepro/quest_count")>300)
						item_quest=load_item(index1[random(537)]);
					else
						item_quest=load_item(index1[random(300)]);
					me->set("tradepro/quest_item_name",item_quest->querystr("name"));
					me->set("tradepro/quest_item_id",item_quest->querystr("id"));
					me->set("tradepro/index",1);
					tell_object(me, snprintf(msg, 255, index1_1[random(5)], me->querystr("tradepro/quest_npc_name"),me->querystr("tradepro/quest_item_name")));
				}
				else
				{
					CorpsNpc->set(me->querystr("tradepro/quest_killnpc_id"),1);
					me->set("tradepro/quest_npc_id",CorpsNpc->querystr("id"));
					me->set("tradepro/quest_npc_name",CorpsNpc->querystr("name"));
					tell_object(me, snprintf(msg, 255, index7[random(5)], me->querystr("tradepro/quest_killnpc_name"), me->querystr("tradepro/quest_killnpc_id")));
				}
			}
		}
		break;
	case 8://提高自身修为（总经验、声望）
		me->set("tradepro/quest_pro_index",random(3)+1);
		i=me->query("level")*10+random(me->query("level"));
		switch(me->query("tradepro/quest_pro_index"))
		{
		case 1:
			me->set("tradepro/quest_pro_point",me->query("combat_exp")+i);
			tell_object(me, snprintf(msg, 255, index8[random(5)],  me->querystr("tradepro/quest_npc_name"),"总经验",i));
			break;
		case 2:
			me->set("tradepro/quest_pro_point",me->query("repute")+i);
			tell_object(me, snprintf(msg, 255, index8[random(5)],  me->querystr("tradepro/quest_npc_name"),"声望",i));
			break;
		case 3:
			me->set("tradepro/quest_pro_point",me->query("repute")-i);
			tell_object(me, snprintf(msg, 255, index8[random(5)], me->querystr("tradepro/quest_npc_name"),"声望",-i));
			break;
		}
		break;
	case 9://押镖
		tell_object(me, snprintf(msg, 255, index9[random(5)], me->querystr("tradepro/quest_npc_name")));
		break;
	case 11://上贡
		me->set("tradepro/quest_item_numer",random(50000)+10000+me->query("tradepro/quest_count")*10);
		tell_object(me, snprintf(msg, 255, index11[random(5)], me->querystr("tradepro/quest_npc_name"),me->query("tradepro/quest_item_numer")));
		break;
	case 12://送东西
		item_quest=load_item(index1[random(537)]);
		me->set("tradepro/quest_item_name",item_quest->querystr("name"));
		me->set("tradepro/quest_item_id",item_quest->querystr("id"));

		tradepro_item=load_item("tradepro_item");
		tradepro_item->set_name(item_quest->name(),item_quest->id());
		tradepro_item->move(me);
		destruct(item_quest);
		tell_object(me, snprintf(msg, 255, index12[random(5)], me->querystr("tradepro/quest_npc_name"),me->querystr("tradepro/quest_item_name")));
		break;
	case 13://收集材料
		me->set("tradepro/quest_item_name",index13[random(32)]);
		me->set("tradepro/quest_item_numer",random(10)+5);
		tell_object(me, snprintf(msg, 255, index13_1[random(5)], me->querystr("tradepro/quest_npc_name"),me->query("tradepro/quest_item_numer"),me->querystr("tradepro/quest_item_name")));
		break;
	}
}

int CNpc::accept_object(CChar *me, CContainer *item)
{
	if(EQUALSTR(me->querystr("tradepro/quest_npc_id"),querystr("id")) )
	{
		if(current_time < me->query("tradepro/quest_time"))
		{
			char msg[255];
			if(me->query("tradepro/index")==1||me->query("tradepro/index")==12) //买\送东西
			{
				if(EQUALSTR(item->querystr("id"),me->querystr("tradepro/quest_item_id")))
				{
					say("多谢你费心了。",me);
					SendMenu(me);
					reward_tradepro(me);
					destruct(item);
					return 1;
				}
			}
			else if(me->query("tradepro/index")==4)//抓俘虏
			{
				if(EQUALSTR(item->querystr("id"),me->querystr("tradepro/quest_killnpc_id"))
					&& item->Query(CChar::IS_NPC))
				{
					say("多谢你费心了。",me);
					SendMenu(me);
					reward_tradepro(me);
					destruct(item);
					return 1;
				}
			}
			else if(me->query("tradepro/index")==11)//上贡
			{
				if(EQUALSTR(item->querystr("id"),"coin") 
					&& item->query("value")==me->query("tradepro/quest_item_numer"))
				{
					say("多谢你费心了。",me);
					SendMenu(me);
					reward_tradepro(me);
					destruct(item);
					return 1;
				}
			}
			else if(me->query("tradepro/index")==13)//收集材料
			{
				if(EQUALSTR(item->querystr("name"),me->querystr("tradepro/quest_item_name")) )
				{
					say("多谢你费心了。",me);
					SendMenu(me);
					if(item->Query_Amount()>=me->query("tradepro/quest_item_numer"))
						reward_tradepro(me);
					else
					{
						me->add("tradepro/quest_item_numer",-item->Query_Amount());
						say(snprintf(msg, 255,"麻烦你继续帮我再去收集%d个%s，辛苦你了。",
							me->query("tradepro/quest_item_numer"),me->querystr("tradepro/quest_item_name")));
						SendMenu(me);
					}
					destruct(item);
					return 1;
				}
			}
			else if(me->query("tradepro/index")==14)//绘画NPC画像
			{
				if(EQUALSTR(item->querystr("id"),"mian ju") 
					&& EQUALSTR(item->querystr("apply/_id"),me->querystr("tradepro/quest_killnpc_id")))
				{
					say("多谢你费心了。",me);
					SendMenu(me);
					reward_tradepro(me);
					destruct(item);
					return 1;
				}
			}
		}
		else
		{
			say("你来的太迟了，我已经不再需要你的帮助了。",me);
			SendMenu(me);
			me->del("tradepro");
			return 1;
		}
	}
	return 0;
}

//给NPC增加金钱
void CNpc::add_money(LONG amount)
{
	CContainer * money;

	if(! amount) return;
	money = load_item("coin");
	money->set_amount(amount);
	money->move(this);
}

//设置查询问题
void CNpc::set_inquiry(const char * ask, const char * answer, const char * topic)
{
	Inquiry_t * p = new Inquiry_t;

	if(topic) p->topic = topic;
	p->answer = answer;
	p->pFunc = NULL;
	m_listInquiry[ask] = p;
}

void CNpc::set_inquiry(const char * ask, INQUERYFUNC pFunc, const char * topic)
{
	Inquiry_t * p = new Inquiry_t;

	if(topic) p->topic = topic;
	p->pFunc = pFunc;
	m_listInquiry[ask] = p;
}

//打招呼的函式
char * CNpc::greeting(CChar *me)
{
	return "";
}

//learn用到
int CNpc::recognize_apprentice(CChar *me)
{
	return 0;
}

//与NPC谈话
int CNpc::do_talk(CChar *me, char * ask)
{
	string msg;
	Inquiry_t * pInquiry;

	if(!me || !ask) return 0;
	
	//商人任务
	if(me->querymap("tradepro"))
	{
		if(EQUALSTR(me->querystr("tradepro/quest_npc_id"),querystr("id")))
		{
			if(current_time < me->query("tradepro/quest_time"))
			{
				switch(me->query("tradepro/index"))
				{
				case 2://找人
					say("多谢你费心了。",me);
					SendMenu(me);
					reward_tradepro(me);
					break;
				case 3://杀人
					if(me->query("tradepro/quest_killnpc_ok"))
					{
						say("多谢你费心了。",me);
						SendMenu(me);
						reward_tradepro(me);
					}
					break;
				case 5://巡逻
					if(me->query("tradepro/quest_killnpc_ok"))
					{
						say("多谢你费心了。",me);
						SendMenu(me);
						reward_tradepro(me);
					}
					break;
				case 6://示威
					if(me->query("tradepro/quest_killnpc_ok"))
					{
						say("多谢你费心了。",me);
						SendMenu(me);
						reward_tradepro(me);
					}
					break;
				case 7://聚集帮众
					if(query(me->querystr("tradepro/quest_killnpc_id"))==99)
					{
						say("多谢你费心了。",me);
						SendMenu(me);
						reward_tradepro(me);
					}
					break;
				case 8://提高自身修为（总经验、声望）
					if(me->query("tradepro/quest_pro_index")==1 && me->query("combat_exp")>=me->query("tradepro/quest_pro_point"))
					{
						say("多谢你费心了。",me);
						SendMenu(me);
						reward_tradepro(me);
					}
					else if(me->query("tradepro/quest_pro_index")==2 && me->query("repute") >=me->query("tradepro/quest_pro_point"))
					{
						say("多谢你费心了。",me);
						SendMenu(me);
						reward_tradepro(me);
					}
					else if(me->query("tradepro/quest_pro_index")==3 && me->query("repute") <=me->query("tradepro/quest_pro_point"))
					{
						say("多谢你费心了。",me);
						SendMenu(me);
						reward_tradepro(me);
					}
					break;
				case 9://押镖
					if(me->query("tradepro/quest_ok"))
					{
						say("多谢你费心了。",me);
						SendMenu(me);
						reward_tradepro(me);
					}
					break;
				case 10://保护某NPC一定时间不被杀
					CChar * obj = find_npc(me->query("tradepro/quest_killnpc_object_id"));
					if(current_time >=me->query("tradepro/quest_killnpc_time"))
					{
						if(obj && obj->query("ok"))
						{
							obj->del("ok");
							say("多谢你费心了。",me);
							SendMenu(me);
							reward_tradepro(me);
						}
						else
						{
							say("唉，一点小事也做不好，我已经不想再要你帮忙了。",me);
							SendMenu(me);
							me->del("tradepro");
							tell_object(me, "$HIR你的任务失败了。");
							return 1;
						}
					}
					break;
				}
			}
			else
			{
				say("你来的太迟了，我已经不再需要你的帮助了。",me);
				SendMenu(me);
				me->del("tradepro");
				return 1;
			}
		}
	}

	//查询ask
	if(m_listInquiry.find(ask) == m_listInquiry.end())
	{
		//msg = greeting(me);	//先打招呼
		//if(msg.length())
		//	say(msg.c_str(), me);

		if(! m_listInquiry.size())
		{
			return notify_fail("对方并不愿意理你。");
		}

		LISTINQUIRY::iterator p;
		for(p = m_listInquiry.begin(); p!= m_listInquiry.end(); p++)
		{
			pInquiry = p->second;
			if(pInquiry->topic.length())
				AddMenuItem(pInquiry->topic.c_str(), p->first.c_str(), me);
			else
			{
				msg = "向";
				msg += name();
				msg += "请教关于";
				msg += p->first;
				msg += "的问题。";
				AddMenuItem(msg.c_str(), p->first.c_str(), me);
			}
		}
		SendMenu(me);	
		return 1;
	}

	pInquiry = m_listInquiry[ask];
	
	if(pInquiry->pFunc)
	{
		const char * pRtn;

		pRtn = ( * pInquiry->pFunc)(this, me);

		if(pRtn && pRtn[0])
		{
			say(pRtn, me);
			SendMenu(me);
		}
	}
	else
	{
		say(pInquiry->answer.c_str(), me);
		SendMenu(me);
	}
	
	return 1;
}

void CNpc::random_move()
{
	if(! m_pEnvironment->Query(IS_ROOM)) return;

	CRoom * room = (CRoom *)m_pEnvironment;
	DTEXITLIST * list = room->query_exits();
		
	int doors = list->GetCount();
	if(doors)
	{
		char msg[80];
		POSITION p = list->FindIndex(random(doors));
		CDoor * dir = list->GetAt(p); 
		command(snprintf(msg, 80, "go 0 %s", dir->querystr("id")));
	}
}

//使用cast target = 0:自己 1:敌人
int CNpc::perform_action(char *magic, int target)
{
	char msg[255];
	CFightRoom * env;
	CChar * who = this;

	if(target && environment()->Query(IS_FIGHTROOM))
	{
		env = (CFightRoom *)environment();
		who = env->Select_Member(1 - query_team());
		if(! who) return 0;
	}

	return command(snprintf(msg, 255, "cast %ld %s", who->object_id(), magic));
}

int CNpc::accept_fight(CChar *me)
{
	char msg[255];
	string attr = querystr("attitude");
	
	if( query("hp") * 100 / query("max_hp") >= 90 ) 
	{
		if(attr == "friendly")
		{
			say(snprintf(msg, 255, "%s怎么可能是%s的对手？", query_self(this), query_respect(me)), me);
			SendMenu(me);
			return 0;
		}
		else if(attr == "aggressive" || attr == "killer" )
		{
			say("哼！出招吧！");
		}
		else if( ! is_fighting() )
		{
			say(snprintf(msg, 255, "既然%s赐教，%s只好奉陪。", query_respect(me), query_self(this)));
		}
		set("hp", query("max_hp"));
		set("eff_hp", query("max_hp"));
		set("mp", query("max_mp"));
		return 1;
	} 
	
	return 0;
}

void CNpc::wield_weapon(char *weapon)
{
	char msg[80];
	CContainer * obj = present(weapon);
	if(! obj) return;
			
	if(! query_weapon())
		command(snprintf(msg, 80, "wield %ld", obj->object_id()));
}

void CNpc::unwield_weapon(char *weapon)
{
	char msg[80];
	CContainer * obj = present("bishou");
	if(! obj) return;

	if(obj == query_weapon())
		command(snprintf(msg, 80, "unwield %ld", obj->object_id()));
}


