
VENDOR_BEGIN(CNpub_xiaoer4);

virtual void create()
{
	set_name("萧半缺",  "xiao banque");

	set("icon", waiter);
	set("gender", "男性" );
	set("age", 49);
	set("per", 40);
	set("long","这位是鼎鼎大名、大名鼎鼎的商人萧半缺，传言他专门出售各种奇异杂物。");
	set("attitude", "friendly");
	set("rank_info/respect", "大侠");
	set("no_get", "啦啦啦啦～～～～");

	switch(random(8))
	{
	case 0:
		carry_good("foodpack", (random(80)+1));
		carry_good("readingbot", (random(120)+100));
		carry_good("exercisebot", (random(120)+100));
		carry_good("practicebot", (random(120)+100));
		carry_good("detectbox", (random(40)+1));
		carry_good("killermask", random(3) + 1);
		carry_good("transfer_tie", (random(2)+1));
		carry_good("luobo", (random(10)+1));
		carry_good("caogeng", (random(10)+1));
		carry_good("kuihua", 1);
		carry_good("testobj", random(40)+1);
		carry_good("umbrella", 1);
		//carry_good("qingsi", 1);	
		break;
	case 1:
		carry_good("readingbot", (random(120)+100));
		carry_good("exercisebot", (random(120)+100));
		carry_good("practicebot", (random(120)+100));
		carry_good("detectbox", (random(40)+1));
		carry_good("killermask", random(3) + 1);
		carry_good("transfer_tie", (random(2)+1));
		carry_good("luobo", (random(10)+1));
		carry_good("caogeng", (random(10)+1));
		carry_good("kuihua", 1);
		carry_good("testobj", random(40)+1);
		carry_good("umbrella", 1);
		carry_good("foodpack", (random(80)+1));
		break;
	case 2:
		carry_good("exercisebot", (random(120)+100));
		carry_good("practicebot", (random(120)+100));
		carry_good("detectbox", (random(40)+1));
		carry_good("killermask", random(3) + 1);
		carry_good("transfer_tie", (random(2)+1));
		carry_good("luobo", (random(10)+1));
		carry_good("caogeng", (random(10)+1));
		carry_good("kuihua", 1);
		carry_good("testobj", random(40)+1);
		carry_good("umbrella", 1);
		carry_good("foodpack", (random(80)+1));
		carry_good("readingbot", (random(120)+100));
		break;
	case 3:
		carry_good("practicebot", (random(120)+100));
		carry_good("detectbox", (random(40)+1));
		carry_good("killermask", random(3) + 1);
		carry_good("transfer_tie", (random(2)+1));
		carry_good("luobo", (random(10)+1));
		carry_good("caogeng", (random(10)+1));
		carry_good("kuihua", 1);
		carry_good("testobj", random(40)+1);
		carry_good("umbrella", 1);
		carry_good("foodpack", (random(80)+1));
		carry_good("readingbot", (random(120)+100));
		carry_good("exercisebot", (random(120)+100));
		break;
	case 4:
		carry_good("detectbox", (random(40)+1));
		carry_good("killermask", random(3) + 1);
		carry_good("transfer_tie", (random(2)+1));
		carry_good("luobo", (random(10)+1));
		carry_good("caogeng", (random(10)+1));
		carry_good("kuihua", 1);
		carry_good("testobj", random(40)+1);
		carry_good("umbrella", 1);
		carry_good("foodpack", (random(80)+1));
		carry_good("readingbot", (random(120)+100));
		carry_good("exercisebot", (random(120)+100));
		carry_good("practicebot", (random(120)+100));
		break;
	case 5:
		carry_good("killermask", random(3) + 1);
		carry_good("transfer_tie", (random(2)+1));
		carry_good("luobo", (random(10)+1));
		carry_good("caogeng", (random(10)+1));
		carry_good("kuihua", 1);
		carry_good("testobj", random(40)+1);
		carry_good("umbrella", 1);
		carry_good("foodpack", (random(80)+1));
		carry_good("readingbot", (random(120)+100));
		carry_good("exercisebot", (random(120)+100));
		carry_good("practicebot", (random(120)+100));
		carry_good("detectbox", (random(40)+1));
		break;
	case 6:
		carry_good("transfer_tie", (random(2)+1));
		carry_good("luobo", (random(10)+1));
		carry_good("caogeng", (random(10)+1));
		carry_good("kuihua", 1);
		carry_good("testobj", random(40)+1);
		carry_good("umbrella", 1);
		carry_good("foodpack", (random(80)+1));
		carry_good("readingbot", (random(120)+100));
		carry_good("exercisebot", (random(120)+100));
		carry_good("practicebot", (random(120)+100));
		carry_good("detectbox", (random(40)+1));
		carry_good("killermask", random(3) + 1);
		break;
	case 7:
		carry_good("luobo", (random(10)+1));
		carry_good("caogeng", (random(10)+1));
		carry_good("kuihua", 1);
		carry_good("testobj", random(40)+1);
		carry_good("umbrella", 1);
		carry_good("foodpack", (random(80)+1));
		carry_good("readingbot", (random(120)+100));
		carry_good("exercisebot", (random(120)+100));
		carry_good("practicebot", (random(120)+100));
		carry_good("detectbox", (random(40)+1));
		carry_good("killermask", random(3) + 1);
		carry_good("transfer_tie", (random(2)+1));
		break;
	}
	set("no_talk",1);
	set("no_huan",1);
}

int do_talk(CChar * me, char * ask = NULL)
{	
	AddMenuItem("向萧半和打听交易之术的秘密", "$0asktrade $1", me);
	AddMenuItem("向萧半和购买交易文书", "$0gettrade $1", me);
	if(me->query("trade/score"))
		AddMenuItem("查询自己的贸易评价", "$0pingju $1", me);
	SendMenu(me);
	return 1;
}

int upgtrade(CChar * me)
{
	if(me->query_temp("mask/ask_trade") != 1)
		return 0;

	me->delete_temp("mask/ask_trade");

	say("好！从今天起，你被正式御用为商人了。这是你的贸易文书，请妥善保存。", me);
	SendMenu(me);

	load_item("trade")->move(me);

	message_vision("$N郑重的交给$n一份贸易文书。", this, me);
	me->set("trade/level", 1);	

	return 1;
}

int clear_task(CChar * me)
{
	char msg[80];
	LONG score = me->query("trade/val");
	if(! score) return 0;

	if(! CMoney::Player_Pay(me, score))
		say("先把我给你的钱还来。", me);
	else
	{
		say("这点小事都办不到，看来你经不起考验。", me);
		
		score = me->query("trade/score") / 10;
		if(! score) score = 1;
		me->add("trade/score", -score);

		tell_object(me, snprintf(msg, 80, "$HIR你的贸易评价降低了%ld点！", score));

		me->del("trade/name");
		me->del("trade/obj");
		me->del("trade/idx");
		me->del("trade/val");
		me->del("trade/done");		
	}

	SendMenu(me);
	return 1;
}

//获得交易文书
int gettrade(CChar * me)
{
	LONG money = 5000;
	if(me->query("trade/level"))
		money = 15000;
	
	if(! CMoney::Player_Pay(me, money))
		return notify_fail("购买文书需要%ld金币。", money);

	load_item("trade")->move(me);
	message_vision("$N从萧半和处买下一份贸易文书。", me);		
	return 1;
}

//查询自身的贸易评估
int pingju(CChar * me)
{
	if(me->query("trade/score"))
	{
		char msg[255];
		if(me->query_temp("贸易评估"))
		{
			say(snprintf(msg, 255,"你的贸易评估现在是:%ld点", me->query("trade/score")),me);
			me->delete_temp("贸易评估");
		}
		else
			say("你的贸易评估现在肯定是有的，具体是多少，我算不过来。", me);
		SendMenu(me);
	}
	return 1;
}

int handle_action(char * comm, CChar * me, char * arg)
{
	if(strcmp(comm, "asktrade") == 0)
	{
		return asktrade(me);
	}
	else if(strcmp(comm, "clrtask") == 0)
	{		
		return clear_task(me);
	}
	else if(strcmp(comm, "upgtrade") == 0)
	{
		return upgtrade(me);
	}
	else if(strcmp(comm, "gettrade") == 0)
	{
		return gettrade(me);
	}
	else if(strcmp(comm, "pingju") == 0 && me->query("trade/score"))
	{
		return pingju(me);
	}
	return CVendor::handle_action(comm, me, arg);
}

int asktrade(CChar * me)
{
	char msg[255];
	LONG score = me->query("trade/score");

	if(score > 0)
	{
		int level = me->query("trade/level");

		//得到萧半和的任务
		const char * na = me->querystr("trade/name");

		if(! na[0]) 
		{
			//没有任务 是否可以提升
			if(! level && score > 3000 && ! random(10))
			{
				me->set_temp("mask/ask_trade", 1);
				say("做了这么久的贸易，你也该懂得如何与商人讨价还价了罢。", me);
				say("接下来的任务可能更有挑战性，不知你愿不愿意接受？", me);
				AddMenuItem("我愿意接受新的考验！", "$0upgtrade $1", me);
				AddMenuItem("我想继续磨练几天。", "", me);
				SendMenu(me);
				return 1;
			}

			char chatmsg[9][80] = 
			{
				"最近缺货，速速买回一些$d回来。",
				"街口的老王要办喜事，快些进点$d来。",
				"最近缺少$d，速速买些回来。",
				"泉州的水妹妹要结婚了，快快买些$d来。",
				"这样吧，先帮我买些$d回来。",
				"皇帝降旨，需要一些$d赈济宅民。",
				"水妹妹急需$d，速速进些回来。",
				"要是能买到便宜的$d，那就好了。",
				"王财主家需要一些$d，进些货来。",				
			};

			do_quest(me);

			na = me->querystr("trade/name");
			strncpy(msg, chatmsg[random(9)], 255);
			replace_string(msg, "$d", na, 255);
			say(msg, me);

			LONG  money = me->query("trade/val");
			CMoney::Pay_Player(me, money);
			message_vision(snprintf(msg, 255, "$N给$n数量%ld的金币。", money), this, me);
		}
		else
		{
			say(snprintf(msg, 255, "不是叫你速速买回一些%s吗。", na), me);
			AddMenuItem("我这就去。", "", me);
			AddMenuItem("我办不到。", "$0clrtask $1", me);			
		}

		SendMenu(me);
		return 1;		
	}
	else
	{
		int ask = me->query_temp("mark/ask_trade");
		if(ask == 1)
		{
			me->set_temp("mark/ask_trade", 2);
			say("如果有人推荐，可以很快升任到红顶商人。", me);
		}
		else if(ask == 2)
		{
			me->set("trade/score", 10);		//给了10点评价
			me->delete_temp("mark/ask_trade");
			say(snprintf(msg, 255, "既然%s对贸易这么感兴趣，为何不尝试一下呢。", query_respect(me)), me);
		}		
		else
		{
			me->set_temp("mark/ask_trade", 1);
			say("我是皇帝御准的红顶商人。想做贸易，需要得到皇帝的许可。", me);
		}
	}

	SendMenu(me);
	return 1;
}

//采购的任务
void do_quest(CChar * me)
{
	static struct{
		char name[40];
		char object[20];		//需要买回的物品
		int index;				//索引

		char target[20];		//做贸易NPC
		char id[20];			//NPC id

		LONG money;				//所需要的Money，应该比实际的低许多。找不到那个NPC只能花钱买回物品了。
	} task[119] =
	{
		{"牛皮盾", "shield", 0, "高丽商", "gaoli shang", 120,},
		{"皮背心", "beixin", 0, "高丽商", "gaoli shang", 400,},
		{"头盔", "toukui", 0, "高丽商", "gaoli shang", 10,},
		{"武者项圈", "cycle", 0, "高丽商", "gaoli shang", 180,},
		{"肚带", "surcoat", 0, "高丽商", "gaoli shang", 80,},
		{"护腕", "huwan", 0, "高丽商", "gaoli shang", 130,},
		{"指套", "zhitao", 0, "高丽商", "gaoli shang", 6,},
		{"护腰", "huyao", 0, "高丽商", "gaoli shang", 160,},
		{"草鞋", "caoxie", 0, "高丽商", "gaoli shang", 10,},
		{"皮手套", "shoutao", 0, "高丽商", "gaoli shang", 60,},
		{"铁手掌", "tieshou", 0, "高丽商", "gaoli shang", 50,},
		{"金丝甲", "jinsijia", 0, "高丽商", "gaoli shang", 3000,},
		{"黑色新郎礼服", "marry_1", 1, "老板娘", "LBN", 800,},
		{"大红新娘礼服", "marry_1", 2, "老板娘", "LBN", 850,},
		{"新郎帽", "marry_1", 3, "老板娘", "LBN", 50,},
		{"天然紫水晶项链", "marry_1", 4, "老板娘", "LBN", 150,},
		{"彩纹贝壳项链", "marry_1", 5, "老板娘", "LBN", 250,},
		{"紫金钻石项链", "marry_1", 6, "老板娘", "LBN", 350,},
		{"珍珠项链", "marry_1", 7, "老板娘", "LBN", 150,},
		{"订婚戒指", "marry_1", 8, "老板娘", "LBN", 250,},
		{"缅甸玉镯", "marry_1", 9, "老板娘", "LBN", 150,},
		{"翡翠夜光珠", "marry_1", 10, "老板娘", "LBN", 80,},
		{"贝壳耳环", "marry_1", 11, "老板娘", "LBN", 150,},
		{"大红镶丝披风", "marry_1", 12, "老板娘", "LBN", 250,},
		{"黑色长筒皮靴", "marry_1", 13, "老板娘", "LBN", 80,},
		{"红色绣花鞋", "marry_1", 14, "老板娘", "LBN", 50,},
		{"大红腰带", "marry_1", 15, "老板娘", "LBN", 150,},
		{"五香花生", "peanut", 0, "阿庆嫂", "qing sao", 3,},
		{"翡翠豆腐", "tofu", 0, "阿庆嫂", "qing sao", 4,},
		{"绣花针", "xiuhua", 0, "陈阿婆", "chen apo", 10,},
		{"绣花鞋", "shoes", 0, "陈阿婆", "chen apo", 10,},
		{"粉红绸衫", "pink_cloth", 0, "陈阿婆", "chen apo", 60,},
		{"金戒指", "goldring", 0, "陈阿婆", "chen apo", 200,},
		{"金项链", "necklace", 0, "陈阿婆", "chen apo", 250,},
		{"狗肉", "gourou", 0, "酒馆老板", "lao ban", 10,},
		{"狗肉汤", "gouroutang", 0, "酒馆老板", "lao ban", 20,},
		{"『少林旅游图』", "map", 0, "酒馆老板", "lao ban", 1,},
		{"花雕酒袋", "hdjiudai", 0, "冼老板", "xian", 12,},
		{"烤鸭", "kaoya", 0, "冼老板", "xian", 15,},
		{"铁锤", "hammer", 0, "冯铁匠", "feng", 1,},
		{"绣花鞋", "shoes", 0, "薛老板", "xueboss", 10,},
		{"斗篷", "doupeng", 0, "薛老板", "xueboss", 20,},
		{"对衿褂子", "guazi", 0, "薛老板", "xueboss", 35,},
		{"窄裉袄", "kenao", 0, "薛老板", "xueboss", 40,},
		{"白纱挑线镶边裙", "qun", 0, "薛老板", "xueboss", 25,},
		{"蓝宝石腰带", "jade_belt", 0, "曾如", "zeng ru", 300,},
		{"软金束带", "belt", 0, "曾如", "zeng ru", 200,},
		{"羊皮靴", "boots", 0, "曾如", "zeng ru", 80,},
		{"布鞋", "bu_shoes", 0, "曾如", "zeng ru", 5,},
		{"粉红绸衫", "female1_cloth", 0, "曾如", "zeng ru", 30,},
		{"五彩绣花裙", "color_dress", 0, "曾如", "zeng ru", 200,},
		{"孔雀羽衣", "feather", 0, "曾如", "zeng ru", 500,},
		{"富贵团金褂", "fu_cloth", 0, "曾如", "zeng ru", 100,},
		{"桂花浮玉衫", "gui_dress", 0, "曾如", "zeng ru", 200,},
		{"缨子帽", "hat", 0, "曾如", "zeng ru", 30,},
		{"翠柳鹦鹉服", "liu_dress", 0, "曾如", "zeng ru", 200,},
		{"结婚礼服", "marry_dress", 0, "曾如", "zeng ru", 2000,},
		{"彩缎紧身袄", "mini_dress", 0, "曾如", "zeng ru", 200,},
		{"琼花皎月裳", "moon_dress", 0, "曾如", "zeng ru", 200,},
		{"梨花飘雪裳", "pink_dress", 0, "曾如", "zeng ru", 200,},
		{"七彩霞云衣", "qi_dress", 0, "曾如", "zeng ru", 200,},
		{"霓红连衣裙", "red_dress", 0, "曾如", "zeng ru", 200,},
		{"一字逍遥巾", "scarf", 0, "曾如", "zeng ru", 30,},
		{"梨芯淡烟纱", "sha_dress", 0, "曾如", "zeng ru", 200,},
		{"绣花鞋", "shoes", 0, "曾如", "zeng ru", 10,},
		{"玄色紧身袄", "xian_cloth", 0, "曾如", "zeng ru", 100,},
		{"淡烟秀才装", "xiu_cloth", 0, "曾如", "zeng ru", 100,},
		{"绣花小方巾", "xiu_scarf", 0, "曾如", "zeng ru", 30,},
		{"艳露凝香衣", "yan_dress", 0, "曾如", "zeng ru", 200,},
		{"紫绫纱湘裙", "zi_dress", 0, "曾如", "zeng ru", 200,},
		{"烤鸡腿", "jitui", 0, "凤七", "feng qi", 8,},
		{"牛皮酒袋", "jiudai", 0, "凤七", "feng qi", 2,},
		{"包子", "baozi", 0, "凤七", "feng qi", 5,},
		{"粽子", "zongzi", 0, "凤七", "feng qi", 10,},
		{"密汁甜藕", "mizhitianou", 0, "凤七", "feng qi", 15,},
		{"屠刀", "tudao", 0, "小伙计", "xiao huoji", 200,},
		{"普通匕首", "dagger", 0, "小伙计", "xiao huoji", 200,},
		{"阿拉伯弯刀", "wandao", 0, "小伙计", "xiao huoji", 150,},
		{"钢刀", "gangdao", 0, "小伙计", "xiao huoji", 30,},
		{"金创药", "jinchuang", 0, "药铺伙计", "huoji", 200,},
		{"养精丹", "yangjing", 0, "药铺伙计", "huoji", 200,},
		{"狗皮膏药", "gaoyao", 0, "药铺伙计", "huoji", 200,},
		{"雪参玉蟾丹", "yuchandan", 0, "药铺伙计", "huoji", 50,},
		{"木剑", "mujian", 0, "木匠", "mujiang", 5,},
		{"木刀", "mudao", 0, "木匠", "mujiang", 5,},
		{"木棍", "mugun", 0, "木匠", "mujiang", 5,},
		{"皮裘", "piqiu", 0, "皮货商", "pihuoshang", 50,},
		{"狗皮", "goupi", 0, "皮货商", "pihuoshang", 30,},
		{"貂皮", "diaopi", 0, "皮货商", "pihuoshang", 500,},
		{"虎皮", "hupi", 0, "皮货商", "pihuoshang", 2000,},
		{"蛇皮", "shepi", 0, "皮货商", "pihuoshang", 55,},
		{"羊皮靴", "boots", 0, "皮货商", "pihuoshang", 80,},
		{"皮靴", "pixue", 0, "皮货商", "pihuoshang", 100,},
		{"皮背心", "beixin", 0, "皮货商", "pihuoshang", 400,},
		{"皮手套", "shoutao", 0, "皮货商", "pihuoshang", 60,},
		{"皮腰带", "yaodai", 0, "皮货商", "pihuoshang", 60,},
		{"手杖", "walkingstick", 0, "小贩", "seller", 10,},
		{"绣花鞋", "shoes", 0, "小贩", "seller", 10,},
		{"水壶", "bottle", 0, "小贩", "seller", 10,},
		{"五香茶叶蛋", "egg", 0, "小贩", "seller", 5,},
		{"台夷头巾", "ttoujin", 0, "台夷商贩", "tshangfan", 150,},
		{"台夷短裙", "tduanqun", 0, "台夷商贩", "tshangfan", 20,},
		{"牛皮袋", "niupidai", 0, "店小二", "xiao er", 4,},
		{"小笼包", "yaopin_1", 1, "店小二", "xiao er", 4,},
		{"茶叶蛋", "yaopin_1", 2, "店小二", "xiao er", 6,},
		{"糖葫芦", "yaopin_1", 3, "店小二", "xiao er", 8,},
		{"芝麻酥", "yaopin_1", 4, "店小二", "xiao er", 10,},
		{"北京果脯", "yaopin_1", 5, "店小二", "xiao er", 15,},
		{"杏仁露", "yaopin_1", 6, "店小二", "xiao er", 25,},
		{"烤鹅", "yaopin_1", 7, "店小二", "xiao er", 30,},
		{"茶汤", "yaopin_1", 8, "店小二", "xiao er", 40,},
		{"二锅头", "yaopin_1", 9, "店小二", "xiao er", 43,},
		{"牛肉羹", "yaopin_1", 10, "店小二", "xiao er", 45,},
		{"归元丹", "yaopin_1", 1, "店小二", "xiao er", 36,},
		{"回神膏", "yaopin_2", 2, "店小二", "xiao er", 36,},
		{"补气丸", "yaopin_2", 3, "店小二", "xiao er", 36,},
		{"百花聚精膏", "yaopin_2", 4, "店小二", "xiao er", 36,},
		{"回血膏", "yaopin_2", 5, "店小二", "xiao er", 48,},
		{"乌夷大麾", "wdahui", 0, "乌夷商贩", "shangfan", 20,},
	};

	LONG score = me->query("trade/score");
	int newtask[119];
	int count = 0;

	for(int i=0; i<119; i++)
		if(task[i].money < 10 + score)
			newtask[count++] = i;		//可做的任务

	if(! count) return;

	int lv = newtask[random(count)];
	
	me->set("trade/name", task[lv].name);
	me->set("trade/obj", task[lv].object);
	me->set("trade/idx", task[lv].index);	
	me->set("trade/val", task[lv].money);
}

int accept_object(CChar * me, CContainer * item)
{
	char msg[255];

	if(EQUALSTR(item->querystr("base_name"), me->querystr("trade/obj"))
		&& item->query("index") == me->query("trade/idx"))
	{
		destruct(item);

		LONG val = me->query("trade/val");
		int  score;

		if(val > 200) score = 100;
		else if(val > 30) score = val / 2;
		else score = val;

		LONG exp = score + random(score);
		score = (score + random(score)) / 2;

		message_vision(snprintf(msg, 255, "$HIC萧半和对$N说道：不错不错，购得了%s，太辛苦了！$COM", me->querystr("trade/name")), me);

		if(random(5))
		{
			me->add("combat_exp", exp);
			tell_object(me, snprintf(msg, 255, "$HIW你被奖励%ld点经验！$COM", score));
		}
		else
		{
			me->add("trade/score", score);
			tell_object(me, snprintf(msg, 255, "$HIW你被奖励了%ld点贸易评价！$COM", score));
		}

		me->del("trade/name");
		me->del("trade/obj");
		me->del("trade/idx");
		me->del("trade/val");
		me->del("trade/done");		

		return 1;
	}
	else if(EQUALSTR(item->querystr("base_name"), "zhengqi_book") || EQUALSTR(item->querystr("base_name"), "pixie_sword_book") )
	{
		destruct(item);
		me->add("balance", 100000);

		tell_object(me,"$HIW你获得了100000金币的回收补偿，钱已经帮你存到了钱庄去了。$COM");
		return 1;
	}
	else if(EQUALSTR(item->querystr("id"),"coin") && item->query("value") >=500000 )
	{
		me->set_temp("贸易评估",1);
		tell_object(me,snprintf(msg, 255, "$HIW萧半缺收下了你%d的金币$COM",item->query("value")));
		return 1;
	}
	return 0;
}
/*
virtual void init(CChar * me)
{	
	CNpc::init(me);
	
	if(me->query("mud_age")==me->query("death/mud_age")
		||me->query_temp("kill/flee")!=me->query("kill/flee")
		||me->query_temp("kill/death")!=me->query("kill/death"))
	{
		char msg[255];
		me->set_temp("block_msg/all",1);
		if(EQUALSTR((me->query_weapon())->querystr("id"), "tealeaf"))
			me->command(snprintf(msg, 40, "unwield %ld", (me->query_weapon())->object_id()));
		me->delete_temp("apply");
		me->delete_temp("block_msg/all");

		me->set_temp("kill/flee",me->query("kill/flee"));
		me->set_temp("kill/death",me->query("kill/death"));
		me->UpdateMe();
	}
	
}
*/
VENDOR_END;



