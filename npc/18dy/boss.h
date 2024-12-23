#define BOSS_BEGIN(npc_name)	class npc_name : public CNbossnpc	{	public:	npc_name(){};	virtual ~npc_name(){};
#define BOSS_END               };	

NPC_BEGIN(CNbossnpc);

LONG Query(int nAttr)
{	
	if(nAttr == IS_MONSTER)
		return 1;
	
	return CNpc::Query(nAttr);
}

virtual char * chat_msg()
{		
	DTItemList search;
	POSITION p;
	CContainer * obj;
	CChar * who = NULL;
	
	CopyList(&search, (environment())->Get_ItemList());
	
	p = search.GetHeadPosition();
	while(p)
	{
		obj = search.GetNext(p);
		if( ! obj->Query(IS_LIVING) || obj==this )
			continue;
		who=(CChar *)obj;
		if ( userp(who) )
		{
			message_vision("$RED$N纵声狂笑：能走到这里也不容易，当你这次死定了！",this);
			kill_ob(who);			
			break;
		}
	}
	return "";
}

CContainer * generate_baowu()
{
	CContainer * baowu = NULL;
	int level = query("level");
	
	//产生随机宝物
	switch(random(30))
	{
	case 0:
		if(random(2))
		{
			static char item[20][20] =
			{				
				"yuchi","egg","caomei","baozi","tanghulu","rice3","qingshui_hulu",
					"peanut","jiudai","jitui","gouroutang","fish","zhutou","hulu2",
					"hu","hdjiudai","caidao","duanjian","yaopin_2","yaopin_1",
			};
			baowu = load_item(item[random(20)]);
		}
		break;
	case 1:
		if(random(2))
		{
			static char item[25][20] =
			{				
				"flower_leaf","gancheng","kandao","mudao","mugun","mujian","muyu",
					"muyuchui","shikuai","shitou","shuzhi","shuzhi2","tea_leaf","tieqiao",
					"walkingstick","blade_1","blade_2","yangbian","yaoqin","yaopin_2","yaopin_1",
					"shenghuo_ling","zijin_staff","plumsword","yuchandan",
			};
			baowu = load_item(item[random(25)]);
		}
		break;
	case 2:
		if(random(2))
		{
			static char item[29][20] =
			{				
				"zhitao","zhujian","baichou","baipao","baiyi","bduanqun","beixin","belt",
					"blackcloth","bluecloth","boots","bupao","bu_shoes","cloth","cloth2","connie",
					"cynrobe","doupeng","goupi","greenrobe","green_cloth","greyrobe","guazi",
					"gunny_shoes","heiyi","hongchouxiaoshan","yaopin_2","yaopin_1","fushi",
			};
			baowu = load_item((item[random(29)]));
		}
		break;
	case 3:
		if(random(2))
		{
			static char item[52][20] =
			{				
				"huwan","huyao","jinduan","kenao","linen","luo_cloth","magcloth","magua","male1_cloth",
					"male2_cloth","male3_cloth","male4_cloth","male6_cloth","male7_cloth","male8_cloth","maotan",
					"mask","qingyi","qing_cloth","shoutao","tduanqun","test","tiehuwan","tiehuyao","tieshou",
					"tiezhitao","tongqun","wcloth","wdahui","weibo","whitecloth","whitecloth1","white_robe",
					"xiaoao","xu_cloth","yaodai","yayi_cloth","ycloth","zhitao","soup2","soup","shrimp","sherou",
					"mian","marz","chicken","bocai_fentiao","yaopin_2","yaopin_1","readingbot","practicebot",
			};
			baowu = load_item((item[random(52)]));
		}
		break;
	case 4:
		baowu = load_item("coin");
		baowu->set_amount(50 + random(100));
		break;
	case 5:
		//随机物品
		if(! random(20) && level >= 90)
		{
			static char item[18][20] = {				
				"dodgebook","strike_book","quanpu","book_silk","zhangfapu","musicbook1","musicbook2",
					"parry_book","hand_book","sword_book1","sword_book2","force_book","book2","staff_book",
					//"kao_book",
					"wumu_book1","club_book","kill_hammer_book","hammer_book",
			};
			baowu = load_item(item[random(18)]);
		}
		break;
	case 6:
		if(random(2))
		{
			static char item[89][20] =
			{				
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
					"xueli","suya","yaopin_2","yaopin_1",
			};
			baowu = load_item((item[random(89)]));
		}
		break;
	case 7:
		//随机书本
		if(! random(20) && level >= 80 )	//80 级以上的怪物才有书
		{
			static char book[166][20] = {
				"zixia_book","18niou", "zhangfapu", "zhangfapu", 
					"zhangfapu", "zhangfapu", "zhangfapu", "zhangfapu", 				
					"zhangfapu","yunvjing1","yunvjing2","yunv_swordb",
					"yijinjing","yijing3","yijing2","yijing1",
					"yijing0","xuanfeng_book","xisuijing","musicbook1",
					"musicbook2","wuji3","wuji2","wuji1",
					"wuji3","wuji2","wuji1","wuji3",
					"wuji2","wuji1","wuji3","wuji2",
					"wuji1","wuji3","wuji2","wuji1",
					"wuji3","wuji2","wuji1","throw_book",
					"sword_book2","sword_book1","sword_book1","sword_book1",
					"sword_book1","sword_book1","sword_book1","sun_book",
					"strike_book","strike_book",
					"strike_book","strike_book",
					"strike_book","strike_book",
					"staff_book","shoufa",
					"quanpu","quanpu",
					"quanpu","qinpu",
					"qijianpu","skin",
					"parry_book","parry_book",
					"parry_book","parry_book",
					"parry_book","parry_book",
					"parry_book","mizong_book",
					"liuyang_book2","liuyang_book1",
					"six_book","literateb4",
					"lbook3",
					"lbook2",
					"lbook1",
					"laozi8",
					"laozi2",
					"laozi18",
					"laozi16",
					"laozi13",
					"laozi1",
					"kuihua",
					"jiuyin1",
					"jiuyin2",
					"jiuyang4",
					"jiuyang3",
					"jiuyang2",
					"jiuyang1",
					"jinyantu",
					"jinshe3",
					"jinshe2",
					"jinshe1",
					"hand_book",
					"hand_book",
					"hand_book",
					"hand_book",
					"hand_book",
					"hand_book",
					"force_book",
					"force_book",
					"force_book",
					"force_book",
					"force_book",
					"dujing_2",
					"dujing_1",
					"dodgebook",
					"daodejing_ii",
					"daodejing_i",
					"daodejing",
					"book2",
					"book_stone",
					"book_silk",
					"book_paper",
					"book_iron",
					"book2",
					"book_stone",
					"book_silk",
					"book_paper",
					"book_iron",
					"book2",
					"book_stone",
					"book_silk",
					"book_paper",
					"book_iron",
					"book2",
					"book_stone",
					"book_silk",
					"book_paper",
					"book_iron",
					"book2",
					"book_stone",
					"book_silk",
					"book_paper",
					"book_iron",
					"book2",
					"book_stone",
					"book_silk",
					"book_paper",
					"book_iron",
					"bojuan",
					"blade_book",
					"bagua",
					"bagua0",
					"zhifapu",
					"bufa",
					"chanhe_book1",
					"chanhe_book2",
					"chanhe_book3",
					"chanhe_book4",
					"jixiao_book1",
					"jixiao_book2",
					"jixiao_book3",
					"jixiao_book4",
					"hejianjing",
					"tangshoumichuan",
					"miaoshou",
					"miaoshou",
					"miaoshou",
					"miaoshou",
					"miaoshou",
					"miaoshou",
					"miaoshou",
					"buildcorps1",
					"tianmen_map",
			};
			int num;
			if(! random(20) && level >= 100 && sys_server_id==1)	
				num=166;
			else
				num=144;
			baowu = load_item(book[random(num)]);
		}
		break;
	case 8:
		if(random(2))
		{
			static char item[36][20] =
			{				
				"suji","mangguo","huotui2","gao","gaoyao","gao3","ping","dadao","gangbiao","heilongbian",
					"jiedao","panguanbi","qimeigun","qin","shezhang","shortsword","shutonggun","tielianzi",
					"tiepipa","tie_gan","tongren","tudao","zijinchui","changpao2","cheng_cloth",
					"daopaocyan_cloth","jindai","jjunfu","ni_cloth","ni_xie","pink_cloth","p_jiasha",
					"yaopin_2","yaopin_1","transfer_tie","zhuguo",
			};
			baowu = load_item((item[random(36)]));
		}
		break;
	case 9:
		if(level > 80 && ! random(15))
		{
			level = random(level) + 1;
			baowu = load_item("hushenfu");
			baowu->create(level);
		}
		break;
	case 10:
		if(! random(8))
			baowu = load_item("xiangsi_miji");
		break;
	case 11:
		if(! random(8))
			baowu = load_item("xiaohun_miji");
		break;
	case 12:
		if(random(2))
		{
			static char item[12][20] =
			{				
				"zhanyi","bilinzhen","cuiyu","xuelian","jiuping2","jiuping",
					"baihongjian","sword_2","junzijian","yaopin_2","yaopin_1","zhuguo",
			};
			baowu = load_item((item[random(12)]));
		}
		break;
	case 13:
		if(level > 100 && ! random(15))
		{
			static char item[3][20] = {
				"redqin","greenxiao","zhuguo",
			};
			baowu = load_item(item[random(3)]);
		}
		break;
	case 14:
		if(random(2))
		{
			static char item[13][20] =
			{				
				"lace","liu_dress","mini_dress","moon_dress","necklace","pink_dress","qi_dress",
					"red_dress","scarf","sha_dress","shouzhuo","yaopin_2","yaopin_1",
			};
			baowu = load_item((item[random(13)]));
		}
		break;
	case 15:
		if(random(2))
		{
			static char item[17][20] =
			{				
				"xiu_cloth","xiu_scarf","yan_dress","zi_dress","yangxin","mitao","yuchandan",
					"xxqingxin_san","jingxin_san","caoxie","cycle","dao_xie","female1_cloth","female2_cloth",
					"female3_cloth","yaopin_2","yaopin_1",
			};
			baowu = load_item((item[random(17)]));
		}
		break;
	case 16:
		if(random(2))
		{
			static char item[20][20] =
			{				
				"female4_cloth","female5_cloth","female6_cloth","female7_cloth","female8_cloth",
					"female_shoe","flower_shoe","marry_1","marry_dress","yupei","yaopin_1","huoqiang",
					"jiujiebian","qingzugang","rose","shedangao","nverhong","honey","yaopin_2","yaopin_1",
			};
			baowu = load_item((item[random(20)]));
		}
		break;
	case 17:
		if(random(2))
		{
			static char item[43][20] =
			{				
				"diaopi","jin","r_jiasha","shudai","pork","fotiaoqiang","tiebian","male5_cloth","qingpao",
					"qun","tiejia","xuelian2","fengmi","axe","biandan","dafu","dagger","huaji","ruanjian",
					"yaochu","male_shoe","pixue","sengxie","seng_xie","surcoat","ttoujin","zhenzhu","menghan_yao",
					"xionghuang","chaidao","mandao","putongbishou","snowsword","xiao","zhuyebiao","color_dress",
					"dress","fu_cloth","goldring","gui_dress","jade_belt","yaopin_2","yaopin_1",
			};
			baowu = load_item((item[random(43)]));
		}
		break;
	case 18:
		baowu = load_item("yueping");
		break;
	case 19:
		baowu = load_item("fengyin");
		break;
	}
	return baowu;
}

void die()
{
	CChar *	ob = (CChar *)find_object(query_temp("last_damage_from"), 1);

	if(ob)
	{
		CContainer * baowu = generate_baowu();
		if(baowu) baowu->move(environment());
		for(int i=0;i<random(10)+1;i++)
		{
			baowu=load_item("coin");
			baowu->set_amount(random(10000)+100);
			if(baowu) baowu->move(environment());
		}

		int exp=random(50)+query("level")*2;
		ob->add("combat_exp",exp);
		ob->add("repute",exp);
		ob->UpdateMe();
		if (ob->query("18dy/level") != ob->query("18dy/task") 
			&& ob->query("18dy/task") > 0)
		{
			ob->del("18dy/num");
			ob->set("18dy/boss",1);
			ob->add("18dy/task",1);
		}
		char msg[255];
		tell_object(ob,snprintf(msg,255,"你历练成功，额外获得%d点经验，江湖声望提高%d点！",exp,exp));
	}

	CNpc::die();
}
NPC_END;