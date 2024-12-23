#define MONSTER_BEGIN(npc_name)	class npc_name : public CNmonsternpc	{	public:	npc_name(){};	virtual ~npc_name(){};
#define MONSTER_END               };	

NPC_BEGIN(CNmonsternpc);

void create()
{
	int i=random(4);
	if(i==1)
	{
		set("title","炼气士");
		set("force",1);
	}
	else if(i==2)
	{
		set("title","刺客");
		set("dodge",1);
	}
	else if(i==3)
	{
		set("title","力士");
		set("damage",1);
	}
	else
	{
		set("title","甲士");
		set("parry",1);
	}

	set_weight(50000000);
	set("no_kill",1);
	if(random(10)==0)
	{
		add("apply/armor", query("apply/armor"));
		add("apply/damage", query("apply/damage"));
		add("hp", query("hp"));
		add("max_hp", query("max_hp"));
		add("eff_hp", query("eff_hp"));
		add("mp", query("mp"));
		add("max_mp", query("max_mp"));

		set("no_缠字决",1);
		set_temp("apply/no_连字诀",1);
		set_temp("apply/no_千环套狗",1);
		set_temp("apply/no_相思无用",1);
		set_temp("apply/no_势合形离",1);
		set_temp("apply/no_点字决",1);
		set_temp("apply/no_天外飞龙",1);
		set_temp("apply/no_拼命",1);
		set_temp("apply/no_祭血神刀",1);
		set_temp("apply/no_封字决",1);
		set("bigboss",1);
	}

	call_out(selfdest, 900);		//15分钟后毁灭。
}

LONG Query(int nAttr)
{	
	if(nAttr == IS_MONSTER)
		return 1;
	
	return CNpc::Query(nAttr);
}
/*
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
			if(query("level") >=who->query_temp("apply/protect"))
			{
				message_vision("$YEL$N大喝道：天堂有路你不走，地狱无门自来投！",this);
				kill_ob(who);			
				break;
			}
		}
	}
	return "";
}
*/

int handle_action(char *comm, CChar *me, char *arg)
{
	if(! is_fighting() &&((strcmp(comm, "kill") == 0 || strcmp(comm, "fight") == 0	|| strcmp(comm, "cast") == 0 )))
	{
		int i1,i2,i3,i4,j1,j2,j3,k,l;
		char msg[255];

		i1=random(10)+1;
		i2=random(10)+1;
		i3=random(10)+1;
		i4=random(10)+1;
		j1=random(2);
		j2=random(2);
		j3=random(2);
		k=0;
		if(j1)
			k=i1+i2;
		else
			k=i1-i2;

		if(j2)
			k=k+i3;
		else
			k=k-i3;

		if(j3)
			k=k+i4;
		else
			k=k-i4;

		say("想和我打，是吧？先帮我算算这个再说。", me);
		say(snprintf(msg,255,"%d %s %d %s %d %s %d = 多少？",i1,j1>0?"+":"-",i2,j2>0?"+":"-",i3,j3>0?"+":"-",i4),me);
		
		l=random(4)+1;
		
		if(l==1)
			AddMenuItem(snprintf(msg,255,"%d",k), "$0a_1 $1", me);
		else
			AddMenuItem(snprintf(msg,255,"%d",random(2)>0?k+random(8)+1:k-random(8)-1), "$0a_1 $1", me);

		if(l==2)
			AddMenuItem(snprintf(msg,255,"%d",k), "$0a_2 $1", me);
		else
			AddMenuItem(snprintf(msg,255,"%d",random(2)>0?k+random(8)+1:k-random(8)-1), "$0a_2 $1", me);

		if(l==3)
			AddMenuItem(snprintf(msg,255,"%d",k), "$0a_3 $1", me);
		else
			AddMenuItem(snprintf(msg,255,"%d",random(2)>0?k+random(8)+1:k-random(8)-1), "$0a_3 $1", me);

		if(l==4)
			AddMenuItem(snprintf(msg,255,"%d",k), "$0a_4 $1", me);
		else
			AddMenuItem(snprintf(msg,255,"%d",random(2)>0?k+random(8)+1:k-random(8)-1), "$0a_4 $1", me);

		me->set_temp("杀人考试",l);
		SendMenu(me);
		return 1;
	}
	else if(me->query_temp("杀人考试"))
	{
		if((!strcmp(comm, "a_1") && me->query_temp("杀人考试")==1)
			||(!strcmp(comm, "a_2") && me->query_temp("杀人考试")==2)
			||(!strcmp(comm, "a_3") && me->query_temp("杀人考试")==3)
			||(!strcmp(comm, "a_4") && me->query_temp("杀人考试")==4))
		{
				message_vision("$YEL$N大喝道：天堂有路你不走，地狱无门自来投！",this);
				kill_ob(me);
				me->delete_temp("杀人考试");
				return 0;
		}
		else
		{
			say("连这个都答不出来，还在这里张牙舞爪什么，一边去！", me);
			SendMenu(me);
			me->delete_temp("杀人考试");
			return 1;
		}
	}
	return CNpc::handle_action(comm, me, arg);
}

static void selfdest(CContainer * ob, LONG param1, LONG param2)
{

	destruct(ob);
	return;
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
			static char item[53][20] =
			{				
				"huwan","huyao","jinduan","kenao","linen","luo_cloth","magcloth","magua","male1_cloth",
					"male2_cloth","male3_cloth","male4_cloth","male6_cloth","male7_cloth","male8_cloth","maotan",
					"mask","qingyi","qing_cloth","shoutao","tduanqun","test","tiehuwan","tiehuyao","tieshou",
					"tiezhitao","tongqun","wcloth","wdahui","weibo","whitecloth","whitecloth1","white_robe",
					"xiaoao","xu_cloth","yaodai","yayi_cloth","ycloth","zhitao","soup2","soup","shrimp","sherou",
					"mian","marz","chicken","bocai_fentiao","yaopin_2","yaopin_1","readingbot","practicebot","taomujian"
			};
			baowu = load_item((item[random(53)]));
		}
		break;
	case 4:
		baowu = load_item("coin");
		baowu->set_amount(50 + random(100));
		break;
	case 5:
		//随机物品
		if(! random(30) && level >= 120)
		{
			static char item[19][20] = {				
				"dodgebook","strike_book","quanpu","book_silk","zhangfapu","musicbook1","musicbook2",
					"parry_book","hand_book","sword_book1","sword_book2","force_book","book2","staff_book",
					//"kao_book",
					"wumu_book1","club_book","kill_hammer_book","hammer_book","heiyue_si",
			};
			baowu = load_item(item[random(19)]);
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
			static char book[167][20] = {
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
					"miaoshou","heiyue_si",
					"buildcorps1",
					"tianmen_map",
			};
			int num;
			if(! random(20) && level >= 100 && sys_server_id==1)	
				num=167;
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
			if(level>100 && random(10))
				level=random(100)+1;
			baowu = load_item("hushenfu");
			baowu->create(level);
		}
		break;
	case 10:
		if(! random(12))
			baowu = load_item("xiangsi_miji");
		break;
	case 11:
		if(! random(12))
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
		char msg[255];
		CContainer * baowu = generate_baowu();
		if(baowu) baowu->move(environment());
		if(query("max_exp") >= ob->query("combat_exp"))
		{
			int index=query("monster_level");
			if(index>7)
				index=index-6;
			else
				index=1;
			int exp=random(query("level")*3/2)+query("level")*index;
			int repute=random(exp);
			ob->add("combat_exp",exp);
			ob->add("repute",repute);
			ob->UpdateMe();
			tell_object(ob,snprintf(msg,255,"你历练成功，额外获得%d点经验，江湖声望提高%d点！",exp,repute));
		}
		else
			tell_object(ob,"这里已经对你失去了磨练的意义，勇敢的继续前进吧！");
		if(EQUALSTR(ob->querystr_temp("18dy/kill"),querystr("id")))
		{
			ob->set_temp("18dy/finish",1);
			tell_object(ob,"恭喜你完成了丝路飘渺的任务！");
		}
	}
	CNpc::die();
}

NPC_END;