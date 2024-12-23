//helpnpc010.h
//天癸哥
//George 2001-07-07

NPC_BEGIN(CNhelpnpc010);

void create()
{
	set_name("天癸哥", "tiankuige");
	set("title","兵器爱好者");

	set("icon", young_man5);
	set("gender", "男性" );
	set("age", 28);
	set("long","手中握着一把古剑，嘴里似乎喃喃着什么。。。");
	set("attitude", "friendly");  
	set("env/wimpy", 100); 
	set_weight(50000000);
	set("no_talk",1);
}   
int do_talk(CChar * me, char * ask = NULL)
{

	static char hua1[6][200]=
	{
		"进攻是最好的防守。",
		"一个绝好的兵器可以弥补许多身体的不足。",
		"剑是最古老和最流行的兵器类型之一，无论是铸造还是使用者都十分热爱他们，单兵作战的首选，剑的魂，士的气概，不可分割。 ",
		"刀是在战争中诞生的兵器，江湖中的浪客，公门中的捕快，佛门中的游方，不喜欢剑的风雅的这些人也许会喜欢刀的豪快，斩杀的魅力。 ",
		"暗器也是一种兵器，并非是主流兵器，甚至为一些武林中人不齿，但是暗器依然生存了下来，成为攻击方法中的一种。 ",
		"想要战胜敌人，自己的武器装备是最重要的。"
	};
	static char hua2[2][100]=
	{
		"你想了解什么兵器？",
		"有什么不明明白的吗？"
	};
	static char hua3[38][100]=
	{

		"清平剑",
		"多情剑",
		"无相神光",
		"回风剑",
		"碧血剑",
		"淑女剑",
		"君子剑",
		"风回雪舞剑",
		"情人的眼泪",
		"龙泉剑",														//10

		"巨剑",
		"短剑",
		"游龙剑",
		"白虹剑",
		"碧水剑",
		"凝碧剑",
		"金蛇剑",
		"南海神木",
		"匕首",
		"倚天剑",															//20

		"屠刀",
		"倭刀",
		"阿拉伯弯刀",
		"蛮刀",
		"斩马刀",
		"血刀",
		"闯王宝刀",
		"冷月宝刀",
		"伏魔刀",
		"钝器",															//30

		"熟铁扁担",
		"独脚铜人",
		"白玉瑶琴",
		"雷震挡",
		"银轮",
		"金轮",
		"尸骨",
		"狼牙棒"															//38
	};
	static char hua4[38][200]=
	{

		"太平盛世，从前的皇宫侍卫统一用的兵器也就变成可以对外发售的了，由于是御用兵器，所以价值也不菲。 ",
		"铸剑师傅们放进了所有感情所铸的好剑，符合人体工学原理，据说用起来手感非常好。 ",
		"专门为和尚尼姑们设计的利剑，并且起了这个名字，以免违反佛家六根清静之意。 ",
		"据说每一把都是由张天师后人亲自念咒加护过的宝剑，虽然不能除魔灭怪，但是十分有型。 ",
		"前朝赐给大臣用来自杀的宝剑，据说因为上面有忠臣之血，三年化碧，所以现在很多人都会买一把来收藏",
		"由当代著名铸剑师，现任金牛武馆教头欧豪亲手铸造的雌雄一对剑之一，自然货真价实，，手工精美，它的威力还是其次，更重要的是装备这剑的人会吸引大批喜欢时髦的少男少女的目光，是流行剑中的绝版珍品！",
		"和淑女剑是一对，带在身上当然能大大增加自己的魅力，嫌自己其貌不扬吗？赶快去想办法弄一把吧！ ",
		"已经有很多年历史的名剑，著名的公孙大娘和裴将军在表演剑舞的时候都是使用这把宝剑，剑身轻灵，锋利无比。 ",
		"据说是用美人的眼泪来淬火冶炼而成的剑，在京城一带十分流行，由于是限量版发售，更加增添其纪念价值。 ",
		"由著名宝剑的原产地龙泉的铸剑师精心铸造，千锤百炼，每一把都要由两三个人合作近三年的打造才能出售，和那些打着老字号骗钱的批量兵器绝不相同",

		"野蛮人的首领亚瑟从石头里面拔出来的上古神兵，能使人力量倍增，威力无穷。 ",
		"这把没有名字的短剑不知出自什么人的手，据说其中藏着一个极大秘密，数百年来无数人都参祥不透。 ",
		"很久以前有一个绝世高手，在经历了很多风波后在天山出家为僧，他在后半生的岁月里据说打造了两把宝剑，其中一把就是这游龙剑。 ",
		"明教世代相传的宝剑，也不知道是何时何人所铸。 ",
		"龙泉铸剑师们所供奉的祖师之剑，龙泉剑中的极品。 ",
		"武当派的镇山之剑，削铁如泥。 ",
		"除了锋利外，这把杀人无数的魔剑由于造型怪异巧妙，更有很多特别的用途，据说最高达到 35 种以上，不过只有会用的人才能发挥其长处， ",
		"一柄木剑，但这个木…… ",
		"当年鹿鼎公所用，武功平平的鹿鼎公携此无名匕首横行一方，除了因为鹿鼎公的机智外，其匕首功不可没。 ",
		"一柄充满传奇色彩的神剑，无坚不摧的威力，由三国时代开始就名震天下，近代又经重新冶炼，背后不知道有多少悲欢离合的故事，是武林中人都梦寐以求的东西。 ",

		"最流行的刀之一，灵州进口的钢铁打造，虽不能说削铁如泥，但是砍骨切肉也可以说是应手而开的了，根据广告说保用 10 年。 ",
		"在日本进口的名刀，外表美观，坚韧耐磨，可以用来斩铁，而且广告效应也做的很好，实在是制刀业的楷模，欧阳修也曾经写诗赞美过好几回。 ",
		"也就是著名的圆月弯刀，十分锋利，据说可以将一片薄纱半空掠为两半，并且能将一个钢铁的头盔猛劈为两半。是很多人都希望得到一把的好东西。 ",
		"中国云南的名刀，手工精美，外形上不太吃香，但却十分实用，和日本刀有着异曲同工的结构和造型，是双手刀中的贵族之一。 ",
		"中国的特产，柄和刃几乎一样长，刃薄背厚，威力十足，在战争中往往可以轻易的把敌人装甲骑兵的马头砍下来。马战步兵战都适宜。 ",
		"当年缅甸的皇者之刀，铸成至今也不知道杀了多少人，冤魂的悲痛使它威力倍增，不过刀身极其柔软，没有专门的功夫是几乎不可能使用它的。",
		"我们只知道，闯王用这把刀开始了他的传奇一生，最后差一点就夺得了天下。也许并不一定是这把刀的功劳，但是至少在早期这把恐怖的利刀的事迹使闯王威名远震，人民望风来投。 ",
		"在武林中和倚天剑齐名的传奇兵器，冷浸浸，月溶溶，在这把失踪多年的刀上得到了最好的体现，很难想象一刀挥出去的时候会有什么阻碍。 ",
		"达摩之刀，释迦之刀，千年来，少林历代高僧都反复用内力来加护着它。在伏魔刀的面前，几乎没有不可战胜的东西。 ",
		"没有切削的锋芒，只有重量和威势，带着山的感觉，雷的感觉，风的感觉，逼向你的对手。炫耀你的力量吧。去将对手的兵器打断",

		"用中国秘法将生铁打造成为“熟铁”然后打造成为扁担，十分坚韧耐磨，有棱有角，威力比起一般的铁棒还要强得多。 ",
		"威力最霸道的外门兵器之一，外形为一个巨大的铜人，使用者手握其独脚挥舞，很少有人敢撄其锋芒。 ",
		"古代流传下来的宝物，白玉是很脆弱的东西，但是这把琴却不知道为什么如此坚硬，上面的弦也非同一般，有削铁如泥的效果，想要弹奏它可不是容易的事情。 ",
		"中国重型武器之一，上有铁齿，结构合理，绝非仅仅一个重字，国内的雷震挡一般都是关外铁匠李虹铸造。 ",
		"西藏的转经轮改造成的兵器，白银打造，粗如小柱，使用者握住轮柄，轮身可以转动，很容易滑过对方防守，更加增加防御它的难度。 ",
		"西藏的转经轮改造成的兵器，重量十足的黄金打造，粗如小柱，使用者握住轮柄，轮身可以转动，很容易滑过对方防守，更加增加防御它的难度。 ",
		"神秘的骨头，一般人拿不起的重量。 ",
		"西域的流行兵器，野蛮体魄的人的专利，即使是宝刀宝剑也不敢轻易对抗的巨大沉重，当年金兵凭此在战争上大显神威，有“金兵有狼牙棒，我们有天灵盖”之说。 "
	};
	if(!strlen(ask))
	{
		if(random(2))
			return 0;
		for(int i=0;i<6;i++)
		{
			if(!random(2))
				say(hua1[i],me);
		}
		say(hua2[random(2)],me);
		for(int ii=0;ii<38;ii++)
		{
			if(!random(3))
			AddMenuItem(hua3[ii], zifu(ii), me);
		}
		SendMenu(me);
		return 1;
	}
	say(hua4[shuzi(ask)],me);
	SendMenu(me);
	return 1;
}
char * zifu(int x)
{
   switch(x)
   {
		case 0:return "0";
		case 1:return "1";
		case 2:return "2";
		case 3:return "3";
		case 4:return "4";
		case 5:return "5";
		case 6:return "6";
		case 7:return "7";
		case 8:return "8";
		case 9:return "9";
		case 10:return "10";
		case 11:return "11";
		case 12:return "12";
		case 13:return "13";
		case 14:return "14";
		case 15:return "15";
		case 16:return "16";
		case 17:return "17";
		case 18:return "18";
		case 19:return "19";
		case 20:return "20";
		case 21:return "21";
		case 22:return "22";
		case 23:return "23";
		case 24:return "24";
		case 25:return "25";
		case 26:return "26";
		case 27:return "27";
		case 28:return "28";
		case 29:return "29";
		case 30:return "30";
		case 31:return "31";
		case 32:return "32";
		case 33:return "33";
		case 34:return "34";
		case 35:return "35";
		case 36:return "36";
		case 37:return "37";
		case 38:return "38";
		default:return "00";
   }
}
int shuzi(char * y)
{
   if(strcmp(y,"0")==0)
	   return 0;
   else if(strcmp(y,"1")==0)
	   return 1;
   else if(strcmp(y,"2")==0)
	   return 2;
   else if(strcmp(y,"3")==0)
	   return 3;
   else if(strcmp(y,"4")==0)
	   return 4;
   else if(strcmp(y,"5")==0)
	   return 5;
   else if(strcmp(y,"6")==0)
	   return 6;
   else if(strcmp(y,"7")==0)
	   return 7;
   else if(strcmp(y,"8")==0)
	   return 8;
   else if(strcmp(y,"9")==0)
	   return 9;
   else if(strcmp(y,"10")==0)
	   return 10;
   else if(strcmp(y,"11")==0)
	   return 11;
   else if(strcmp(y,"12")==0)
	   return 12;
   else if(strcmp(y,"13")==0)
	   return 13;
   else if(strcmp(y,"14")==0)
	   return 14;
   else if(strcmp(y,"15")==0)
	   return 15;
   else if(strcmp(y,"16")==0)
	   return 16;
   else if(strcmp(y,"17")==0)
	   return 17;
   else if(strcmp(y,"18")==0)
	   return 18;
   else if(strcmp(y,"19")==0)
	   return 19;
   else if(strcmp(y,"20")==0)
	   return 20;
   else if(strcmp(y,"21")==0)
	   return 21;
   else if(strcmp(y,"22")==0)
	   return 22;
   else if(strcmp(y,"23")==0)
	   return 23;
   else if(strcmp(y,"24")==0)
	   return 24;
   else if(strcmp(y,"25")==0)
	   return 25;
   else if(strcmp(y,"26")==0)
	   return 26;
   else if(strcmp(y,"27")==0)
	   return 27;
   else if(strcmp(y,"28")==0)
	   return 28;
   else if(strcmp(y,"29")==0)
	   return 29;
   else if(strcmp(y,"30")==0)
	   return 30;
   else if(strcmp(y,"31")==0)
	   return 31;
   else if(strcmp(y,"32")==0)
	   return 32;
   else if(strcmp(y,"33")==0)
	   return 33;
   else if(strcmp(y,"34")==0)
	   return 34;
   else if(strcmp(y,"35")==0)
	   return 35;
   else if(strcmp(y,"36")==0)
	   return 36;
   else if(strcmp(y,"37")==0)
	   return 37;
   else if(strcmp(y,"38")==0)
	   return 38;
   else 
	   return 100;
}

virtual int accept_fight(CChar * me)
{
	char msg[255];
	say(snprintf(msg,255," %s我怎么是大侠的对手呢？",query_respect(me) ));
	return 0;
}
/*
virtual void die()
{
	revive(1);
//	message_vision("$N望空中深深的吸了口气。", this);
	set("max_hp",30000);
	set("eff_hp",30000);
	set("hp",30000);

}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if (EQUALSTR(ob->querystr("id"), "coin") && ob->query("value") ==10000  && !query("stop"))
	{
		double value = 3;		//3秒
		time_t t;	
		time(&t);
		char msg[255];
		if(t > me->query_temp("赌博"))
		{
			destruct(ob);
			CContainer * baowu = NULL;
			int diff=5;		//低等级装备的几率控制参数，数值越大，出现的几率也越大。默认为4
			int diff_high=5;	//高等级装备的几率控制参数，数值越小，出现的几率也越大。默认为5
			int level = random(59)+40;	//	掉出宝物等级（30-99为宝物）,等级为level
			int odds=100;		//	掉出宝物几率,几率为odds/100
			int count=1000;	//	珍稀宝物掉出几率（等级70以上为珍稀宝物）,几率为1/count
			int boss=random(3);//检测是否是BOSS； 
			if(random(100)<=odds)
			{
				int mf=random(level)+random(me->query_temp("apply/mf")/20);
				if(mf>level)
					mf=random(level-39)+40;
				if(mf>90 && random(count/100))
					mf=random(46)+40;
				switch(mf)
				{
				case 10:
					if(random(diff))
					{
						static char item[20][20] =
						{				
							"yuchi","egg","caomei","baozi","tanghulu","rice3","qingshui_hulu",
								"peanut","jiudai","jitui","gouroutang","fish","zhutou","hulu2",
								"hu","hdjiudai","caidao","duanjian","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(20)]));
					}
					break;
				case 11:
					if(random(diff))
					{
						static char item[19][20] =
						{				
							"flower_leaf","gancheng","kandao","mudao","mugun","mujian","muyu",
								"muyuchui","shikuai","shitou","shuzhi","shuzhi2","tea_leaf","tieqiao",
								"walkingstick","yangbian","yaoqin","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(19)]));
					}
					break;
				case 12:
					if(random(diff))
					{
						static char item[28][20] =
						{				
							"zhitao","zhujian","baichou","baipao","baiyi","bduanqun","beixin","belt",
								"blackcloth","bluecloth","boots","bupao","bu_shoes","cloth","cloth2","connie",
								"cynrobe","doupeng","goupi","greenrobe","green_cloth","greyrobe","guazi",
								"gunny_shoes","heiyi","hongchouxiaoshan","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(28)]));
					}
					break;
				case 13:
					if(random(diff))
					{
						static char item[49][20] =
						{				
							"huwan","huyao","jinduan","kenao","linen","luo_cloth","magcloth","magua","male1_cloth",
								"male2_cloth","male3_cloth","male4_cloth","male6_cloth","male7_cloth","male8_cloth","maotan",
								"mask","qingyi","qing_cloth","shoutao","tduanqun","test","tiehuwan","tiehuyao","tieshou",
								"tiezhitao","tongqun","wcloth","wdahui","weibo","whitecloth","whitecloth1","white_robe",
								"xiaoao","xu_cloth","yaodai","yayi_cloth","ycloth","zhitao","soup2","soup","shrimp","sherou",
								"mian","marz","chicken","bocai_fentiao","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(49)]));
					}
					break;
				case 14:
					if(random(diff))
					{
						static char item[49][20] =
						{				
							"huwan","huyao","jinduan","kenao","linen","luo_cloth","magcloth","magua","male1_cloth",
								"male2_cloth","male3_cloth","male4_cloth","male6_cloth","male7_cloth","male8_cloth","maotan",
								"mask","qingyi","qing_cloth","shoutao","tduanqun","test","tiehuwan","tiehuyao","tieshou",
								"tiezhitao","tongqun","wcloth","wdahui","weibo","whitecloth","whitecloth1","white_robe",
								"xiaoao","xu_cloth","yaodai","yayi_cloth","ycloth","zhitao","soup2","soup","shrimp","sherou",
								"mian","marz","chicken","bocai_fentiao","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(49)]));
					}
					break;
				case 15:
					if(random(diff))
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
				case 16:
					if(random(diff))
					{
						static char item[34][20] =
						{				
							"suji","mangguo","huotui2","gao","gaoyao","gao3","ping","dadao","gangbiao","heilongbian",
								"jiedao","panguanbi","qimeigun","qin","shezhang","shortsword","shutonggun","tielianzi",
								"tiepipa","tie_gan","tongren","tudao","zijinchui","changpao2","cheng_cloth",
								"daopaocyan_cloth","jindai","jjunfu","ni_cloth","ni_xie","pink_cloth","p_jiasha",
								"yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(34)]));
					}
					break;
				case 17:
					if(random(diff))
					{
						static char item[19][20] =
						{				
							"skirt","y_jiasha","zhaohong","yeerba","qiguoji","jiaohuaji","qingke_m","qingcha",
								"cleansword","hugesword","taomujian","tiegun","tiejiang","tieshou","wuqing_sword",
								"c_jiasha","dachang","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(19)]));
					}
					break;
				case 18:
					if(random(diff))
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
				case 19:
					if(random(diff))
					{
						static char item[13][20] =
						{				
							"lace","liu_dress","mini_dress","moon_dress","necklace","pink_dress","qi_dress",
								"red_dress","scarf","sha_dress","shouzhuo","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(13)]));
					}
					break;
				case 20:
					if(random(diff))
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
				case 21:
					if(random(diff))
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
				case 22:
					if(random(diff))
					{
						static char item[12][20] =
						{				
							"arrow","qingzuzang","tiedan","xem_sword","yuzhu_zhang","baguafu",
								"ring","heiyugao","tianxiang_gao","yaopin_2","yaopin_1","zhuguo",
						};
						baowu = load_item((item[random(12)]));
					}
					break;
				case 23:
					if(random(diff))
					{
						static char item[11][20] =
						{				
							"zhanyi","bilinzhen","cuiyu","xuelian","jiuping2","jiuping",
								"baihongjian","sword_2","junzijian","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(11)]));
					}
					break;
				case 24:
					if(random(diff))
					{
						static char item[11][20] =
						{				
							"zhanyi","bilinzhen","cuiyu","xuelian","jiuping2","jiuping",
								"baihongjian","sword_2","junzijian","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(11)]));
					}
					break;
				case 25:
					if(random(diff))
					{
						static char item[2][20] =
						{				
							"yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(2)]));
					}
					break;
				case 26:
					if(random(diff))
					{
						static char item[2][20] =
						{				
							"yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(2)]));
					}
					break;
				case 27:
					if(random(diff))
					{
						static char item[2][20] =
						{				
							"yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(2)]));
					}
					break;
				case 28:
					if(random(diff))
					{
						static char item[2][20] =
						{				
							"yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(2)]));
					}
					break;
				case 29:
					if(random(diff))
					{
						static char item[3][20] =
						{				
							"yaopin_2","yaopin_1","zhuguo",
						};
						baowu = load_item((item[random(3)]));
					}
					break;
				case 30:
					if(random(diff))
					{
						static char item[4][20] =
						{				
							"youlongsword","yufeng_zhen","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(4)]));
					}
					break;
				case 31:
					if(random(diff))
					{
						static char item[5][20] =
						{				
							"hedinghong","shanshen","blade_2","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(5)]));
					}
					break;
				case 32:
					if(random(diff))
					{
						static char item[2][20] =
						{				
							"yaopin_1","zhuguo",
						};
						baowu = load_item((item[random(2)]));
					}
					break;
				case 33:
				case 34:
					if(random(diff))
					{
						static char item[5][20] =
						{				
							"shenghuo_ling","jinsijia","yaopin_2","yaopin_1","zhuguo",
						};
						baowu = load_item((item[random(5)]));				
					}
					break;
				case 35:
					if(random(diff))
					{
						static char item[4][20] =
						{				
							"yaopin_2","yaopin_1",
								"taibaizao",	//太白帚
								"zhuguo",
						};
						baowu = load_item((item[random(4)]));				
					}
					break;
				case 36:
					if(random(diff))
					{
						static char item[5][20] =
						{				
							"xuedao","ring_whip","yaopin_2","yaopin_1","zhuguo",
						};
						baowu = load_item((item[random(5)]));
					}
					break;
				case 37:
					if(random(diff))
					{
						static char item[3][20] =
						{				
							"yaopin_2","yaopin_1","zhuguo",
						};
						baowu = load_item((item[random(3)]));
					}
					break;
				case 38:
					if(random(diff))
					{
						static char item[4][20] =
						{				
							"leizhendang","sword_3","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(4)]));
					}
					break;
				case 39:
					if(random(diff))
					{
						static char item[4][20] =
						{				
							"longquansword","xuantiesword","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(4)]));
					}
					break;
				case 40:
					if(random(diff))
					{
						static char item[9][20] =
						{				
							"fojing100","fojing101","fojing11","fojing20","fojing200","fojing201","fojing21","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(9)]));
					}
					break;
				case 41:
					if(random(diff))
					{
						static char item[9][20] =
						{				
							"liumai_sword","wuji1","wuji2","wuji3","yaopin_2","shouwu","sanxiaosan","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(9)]));
					}
					break;
				case 42:
					if(random(diff))
					{
						static char item[2][20] =
						{				
							"yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(2)]));
					}
					break;
				case 43:
					if(random(diff))
					{
						static char item[3][20] =
						{				
							"yaopin_2","yaopin_1","zhuguo",
						};
						baowu = load_item((item[random(3)]));
					}
					break;
				case 44:
					if(random(diff))
					{
						static char item[3][20] =
						{				
							"jinhua","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(3)]));
					}
					break;
				case 45:
					if(random(diff))
					{
						static char item[8][20] =
						{				
							"38huoqiang",		//点三八火枪
								"diaojiandai",		//小可爱吊肩带
								"lantiandai",		//蓝田玉带
								"guiling","jinlun","chanhe_book1","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(8)]));
					}
					break;
				case 46:
					if(random(diff))
					{
						static char item[6][20] =
						{				
							"chanhe_book2","chanhe_book3","musicbook1","yaopin_2","yaopin_1",
								"jinhuantoushi",		//金环头饰
						};
						baowu = load_item((item[random(6)]));
					}
					break;
				case 47:
					if(random(diff))
					{
						static char item[7][20] =
						{				
							"skin","throw_book","putizi","yaopin_2","yaopin_1","zhuguo",
								"linboxie",				//凌波鞋
						};
						baowu = load_item((item[random(7)]));
					}
					break;
				case 48:
					if(random(diff))
					{
						static char item[3][20] =
						{				
							"yaopin_2","yaopin_1","zhuguo",
						};
						baowu = load_item((item[random(3)]));
					}
					break;
				case 49:
					if(random(diff))
					{
						static char item[4][20] =
						{				
							"feather","yaopin_2","yaopin_1","zhuguo",
						};
						baowu = load_item((item[random(4)]));
					}
					break;
				case 50:
					if(random(diff))
					{
						static char item[4][20] =
						{				
							"yaopin_3","yaopin_2","yaopin_1",
								"btzheng",	//BT绣花针
						};
						baowu = load_item((item[random(4)]));
					}
					break;
				case 51:
					if(random(diff))
					{
						static char item[4][20] =
						{				
							"feicui","yaopin_2","yaopin_1",
								"yunshenglv",	//云生履
						};
						baowu = load_item((item[random(4)]));
					}
					break;
				case 52:
					if(random(diff))
					{
						static char item[4][20] =
						{				
							"zhemei_book1","yaopin_2","yaopin_1","zhuguo",
						};
						baowu = load_item((item[random(4)]));
					}
					break;
				case 53:
				case 54:
				case 55:
					if(random(diff))
					{
						static char item[4][20] =
						{				
							"yaopin_2","yaopin_1","zhuguo",
								"xuantiebishou",		//玄铁匕首
						};
						baowu = load_item((item[random(4)]));
					}
					break;
				case 56:
					if(random(diff))
					{
						static char item[4][20] =
						{				
							"yaopin_2","yaopin_1","zhuguo",
								"qunxing_tu",//群星璀璨图
						};
						baowu = load_item((item[random(4)]));
					}
					break;
				case 57:
					if(random(diff))
					{
						static char item[4][20] =
						{				
							"shunvjian","yaopin_2","yaopin_1","zhuguo",
						};
						baowu = load_item((item[random(4)]));
					}
					break;
				case 58:
					if(random(diff))
					{
						static char item[5][20] =
						{				
							"sun_book","yaopin_2","yaopin_1",
								"bolanxie",			//波澜不惊鞋
								"qunxing_tu",	//群星璀璨图
						};
						baowu = load_item((item[random(5)]));
					}
					break;
				case 59:
					if(random(diff))
					{
						static char item[4][20] =
						{				
							"yaopin_2","yaopin_1","zhuguo",
								"qunxing_tu",//群星璀璨图
						};
						baowu = load_item((item[random(4)]));
					}
					break;
				case 60:
					if(random(diff))
					{
						static char item[6][20] =
						{				
							"jiuhua","yaopin_2","yaopin_1",
								"haoseshan",		//君子好色折扇
								"xiantianyu",		//先天紫蕴精玉
								"poliquan",			//玻璃项链
						};
						baowu = load_item((item[random(6)]));
					}
					break;
				case 61:
					if(random(diff))
					{
						static char item[2][20] =
						{				
							"yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(2)]));
					}
					break;
				case 62:
					if(random(diff))
					{
						static char item[2][20] =
						{				
							"yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(2)]));
					}
					break;
				case 63:
					if(random(diff))
					{
						static char item[3][20] =
						{				
							"kuihua","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(3)]));
					}
					break;
				case 64:
					if(random(diff))
					{
						static char item[3][20] =
						{				
							"yaopin_2","yaopin_1","zhuguo",
						};
						baowu = load_item((item[random(3)]));
					}
					break;
				case 65:
					if(random(diff))
					{
						static char item[5][20] =
						{				
							"xblade","yaopin_2","yaopin_1","zhuguo",
								"fannaomao",		//烦恼全无帽
						};
						baowu = load_item((item[random(5)]));
					}
					break;
				case 66:
					if(random(diff))
					{
						static char item[3][20] =
						{				
							"bojuan",
								"yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(3)]));
					}
					break;
				case 67:
				case 68:
					if(random(diff))
					{
						static char item[2][20] =
						{				
							"yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(2)]));
					}
					break;
				case 69:
					if(random(diff))
					{
						static char item[5][20] =
						{				
							"wuchangdan",		//无常丹
								"shajiezhi",		//傻哥哥戒指
								"renshen","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(5)]));
					}
					break;
				case 70:
					if(!random(diff_high) && boss)
					{
						static char item[6][20] =
						{				
							"tiancanbaojia",		//天蚕宝甲
								"lvzhuxiao",			//绿竹箫
								"bishou","zhifapu","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(6)]));
					}
					break;
				case 71:
					if(!random(diff_high) && boss)
					{
						static char item[5][20] =
						{				
							"yaopin_2","yaopin_1","zhuguo",
								"newyear",		//绮罗天衣
								"newyear1",		//寒烟翠袍
						};
						baowu = load_item((item[random(5)]));
					}
					break;
				case 72:
				case 73:
					if(!random(diff_high))
					{
						static char item[3][20] =
						{				
							"yaopin_2","yaopin_1","zhuguo",
						};
						baowu = load_item((item[random(3)]));
					}
					break;
				case 74:
					if(!random(diff_high))
					{
						static char item[3][20] =
						{				
							"jinshe_zhui","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(3)]));
					}
					break;
				case 75:
					if(!random(diff_high) && boss)
					{
						static char item[3][20] =
						{				
							"yaopin_2","yaopin_1",
								"zidiaopifeng",		//紫貂披风
						};
						baowu = load_item((item[random(3)]));
					}
					break;
				case 76:
					if(!random(diff_high))
					{
						static char item[3][20] =
						{				
							"yaopin_2","yaopin_1","zhuguo",
						};
						baowu = load_item((item[random(3)]));
					}
					break;
				case 77:
				case 78:
				case 79:
					if(!random(diff_high))
					{
						static char item[4][20] =
						{				
							"liaochengpao",		//了却尘缘袍
								"yaopin_2","yaopin_1","zhuguo",
						};
						baowu = load_item((item[random(4)]));
					}
					break;		
				case 80:
					if(!random(mf-80+diff_high) )
					{
						static char item[6][20] =
						{				
							"baixiang","yaopin_2","yaopin_1","zhuguo",
								"dagoubang",		//帮主打狗棒
								"luoshenjin",		//洛神方巾
						};
						baowu = load_item((item[random(6)]));
					}
					break;
				case 81:
					if(!random(mf-80+diff_high))
					{
						static char item[3][20] =
						{				
							"yaopin_2","yaopin_1","zhuguo",
						};
						baowu = load_item((item[random(3)]));
					}
					break;
				case 82:
					if(!random(mf-80+diff_high) )
					{
						static char item[4][20] =
						{				
							"yaopin_2","yaopin_1","zhuguo",
								"yinguozhu",		//因果念珠
						};
						baowu = load_item((item[random(4)]));
					}
					break;
				case 83:
					if(!random(mf-80+diff_high))
					{
						static char item[4][20] =
						{				
							"yaopin_2","yaopin_1","zhuguo",
								"dulonglian",		//毒龙胆项链
						};
						baowu = load_item((item[random(4)]));
					}
					break;
				case 84:
				case 85:
					if(!random(mf-80+diff_high))
					{
						static char item[3][20] =
						{				
							"yaopin_2","yaopin_1",
								"zueiyupao",		//缀玉华袍
						};
						baowu = load_item((item[random(3)]));
					}
					break;
				case 86:
					if(!random(mf-80+diff_high))
					{
						static char item[3][20] =
						{				
							"yaopin_2","yaopin_1",
								"yanshuhua",		//艳俗大红花
						};
						baowu = load_item((item[random(3)]));
					}
					break;
				case 87:
					if(!random(mf-80+diff_high))
					{
						static char item[3][20] =
						{				
							"baojia","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(3)]));
					}
					break;
				case 88:
				case 89:
					if(!random(mf-80+diff_high))
					{
						static char item[3][20] =
						{				
							"yaopin_2","yaopin_1",
								"qinjianhun",	//剑魂石*青
								
						};
						baowu = load_item((item[random(3)]));
					}
					break;
				case 90:
					if(!random(mf-80+diff_high))
					{
						static char item[6][20] =
						{				
							"renshenguo","cwbdao","yaopin_2","yaopin_1",
								"zwsword",			//真武剑
								"mingwang_jian",	//明王剑
						};
						baowu = load_item((item[random(6)]));
					}
					break;
				case 91:
					if(!random(mf-80+diff_high) && boss)
					{
						static char item[4][20] =
						{				
							"yaopin_2","yaopin_1","langyabang",
								"shenshe_staff",		//老豆神蛇杖
						};
						baowu = load_item((item[random(4)]));
					}	
					break;	
				case 92:
					if(!random(mf-80+diff_high))
					{
						static char item[5][20] =
						{				
							"yaopin_2","yaopin_1",
								
								"zijianhun",		//剑魂石*紫
						};
						baowu = load_item((item[random(5)]));
					}	
					break;
				case 93:
				case 94:
				case 95:
					if(!random(mf-80+diff_high) && boss)
					{
						static char item[4][20] =
						{				
							"labazhou","yaopin_2","yaopin_1",
								"ruanweijia",		//帮主软猬甲
						};
						baowu = load_item((item[random(4)]));
					}
					break;
				case 96:
					if(!random(mf-80+diff_high) && boss)
					{
						static char item[4][20] =
						{				
							"labazhou","yaopin_2","yaopin_1",
								"zhangmenhuan",		//掌门铁指环
						};
						baowu = load_item((item[random(4)]));
					}
					break;
				case 97:
					if(!random(mf-80+diff_high))
					{
						static char item[3][20] =
						{				
							"lengyue_baodao","yaopin_2","yaopin_1",
						};
						baowu = load_item((item[random(3)]));
					}
					break;
				case 98:
					if(!random(mf-80+diff_high) && boss)
					{
						static char item[8][20] =
						{				
							"fumo_dao","jingang_zhao","yaopin_2","yaopin_1",
								"yinmopao",		//银魔袍
								"huanchunwan",	//还春丸
								"baomingdan",	//保命金丹
								"wangqing_shi",	//忘情石
						};
						baowu = load_item((item[random(8)]));
					}
					break;
				case 99:
					if(!random(mf-80+diff_high) && boss)
					{
						static char item[6][20] =
						{				
							"ytjian",		//倚天剑
								"tulong_dao",	//屠龙刀
								"xuanwupao",	//玄武道袍
								"hanyuzhi",		//汉玉扳指
								"yaopin_2","yaopin_1",
								
						};
						baowu = load_item((item[random(6)]));
					}
					break;
				default:
					baowu = load_item("yaopin_2");
					break;
				}
			}
			else
				baowu=load_item("yaopin_1");
			
			if(baowu)
			{
				add("赌博",1);
				baowu->move(me);
				tell_object(me,snprintf(msg, 255, "你闭上眼睛，伸手塞进天癸哥面前的一个蒙着的纸箱中，左摸又捏，挑了一个。拿出来睁眼一看，原来竟然是一个%s。",baowu->name(1)));
			}
			t += (time_t)value;	
			me->set_temp("赌博",t);
			return 1;
		}
		else
		{
			tell_object(me, "你掏钱别那么快，悠着点，慢些，再慢些。这不是还在测试嘛，很容易数钱来不及当机的... ...");
		}
	}
	return 0;
}
*/
NPC_END;

