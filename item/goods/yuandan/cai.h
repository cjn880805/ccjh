//cai.h 菜肴
//秦波 2002、12、30

FOOD_BEGIN(CIcai);

virtual void create(int nFlag = 0)
{
	static char cai[45][20]={"熏腊肠","醉子鸡","东坡肉","五花焖肉","红烧素鹅","宫保鸡丁","麻辣肚丝","红油肺片","嫩汆猪肝","走油脆肠","青丝熏鱼","糖醋排骨","京酱肉丝","油炝大虾","细扒头肉","麝香冬笋","爆炒腰花","翡翠豆腐","三鲜腐竹","时鲜蔬菜","脆皮烤鸭","清蒸鲈鱼","麻婆豆腐","芙蓉蛤蜊","荷包里脊","芙蓉蟹斗","宫保野兔","爆炒田鸡","绣球乾贝","麻辣口条","油焖草菇","百花鸭舌","蕃茄马蹄","腰果芹心","蜜汁蕃茄","山珍蕨菜","五香仔鸽","糖醋荷藕","清炸鹌鹑","白扒鱼唇","天香鲍鱼","三仙丸子","枸杞鱼米","酸辣黄瓜","拔丝香蕉"};
	
	int index=random(45);
	set_name(cai[index]);
	
	set_weight(20000);
	set("unit", "盘");
	char msg[255];
	
	set("long",snprintf(msg, 255,"这是一盘让人垂涎欲滴的「%s」",cai[index]));

	call_out(do_die, 3600);	
};


virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(!strcmp(comm, "get") )
	{
		if(me->query("yuandna/cai/get"))
		{
			tell_object(me,"别贪心哦，先把你身上的吃完也不迟啊！");	
			return 1;
		}
		else
		{
			me->set("yuandna/cai/get",1);
			return 0;
		}
	}
	return 0;
}

virtual int Can_Use()
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * who)
{
	if(who == me)
	{
		static char hows[29][255] = {
				"万般幸福地",
				"鬼鬼祟祟地",
				"红光满面地",
				"乐滋滋地",
				"极为严肃地",
				"点头哈腰地",
				"感激涕淋地",
				"板着脸",
				"激动得浑身颤抖，",
				"庄严地看着大家，然后勇敢地",
				"呲牙咧嘴地",
				"秀里秀气地",
				"满脸狐疑地",
				"翻翻白眼，",
				"摇头晃脑地",
				"抿嘴一笑，",
				"饿狼一样",
				"笨手笨脚地",
				"肥头肥脑地",
				"满脸堆笑故作正经地",
				"推开众人，摆好架式，",
				"油头粉面地",
				"兴奋得满头大汗，",
				"面黄肌瘦地",
				"抹去眼角的泪花，",
				"撮撮手，一跺脚，",
				"张牙舞爪地",
				"十分谦虚地",
				"羞得满脸通红，",
		};
		
		static char manners [27][255]  = {
				"把$HIC「$n」$COM在手心里反复撮了几下，",
				"把$HIC「$n」$COM在地上疯狂地跺扁，",
				"把$HIC「$n」$COM在墙上嘭地一声砸开，",
				"把$HIC「$n」$COM在心口仔细暖了一下，",
				"把$HIC「$n」$COM往油锅里迅速一炸，然后",
				"亲了亲$HIC「$n」$COM，",
				"使劲撕开$HIC「$n」$COM，一点一点地",
				"在$HIC「$n」$COM的外面抹上一层红红的蕃茄酱，",
				"拿起$HIC「$n」$COM蘸着厚厚的红糖，",
				"在$HIC「$n」$COM上撒了一大把盐，",
				"把$HIC「$n」$COM拿起就着两片酸黄瓜，",
				"把$HIC「$n」$COM在酱油里一蘸，品着味",
				"把$HIC「$n」$COM在辣酱里点了一点，咝咝地",
				"把$HIC「$n」$COM在开水里一泡，趁热",
				"把$HIC「$n」$COM在火上一燎，赶紧",
				"用一副刀叉切开$HIC「$n」$COM，",
				"用竹筷夹起$HIC「$n」$COM",
				"含一口绍兴酒喷在$HIC「$n」$COM上，",
				"把$HIC「$n」$COM用自来水洗得干干净净，",
				"在$HIC「$n」$COM上舔了半天，",
				"在$HIC「$n」$COM上撒一层榨菜丝，",
				"在$HIC「$n」$COM上裹一层火腿奶酪，",
				"把$HIC「$n」$COM和葱姜蒜末拌在一起，",
				"把$HIC「$n」$COM捣碎，拌上生菜，",
				"把$HIC「$n」$COM切成小块，加上鸡丁花生热热地在油锅里炒成宫保$HIC「$n」$COM，",
				"把$HIC「$n」$COM放进锅里，加上酱油红糖小火炖成红烧$HIC「$n」$COM，",
				"把$HIC「$n」$COM放在在锅里倒醋撒糖芡成一盘糖醋$HIC「$n」$COM，",
		};
		
		static char actions [24][255] = {
				"张开樱桃小口吞了下去",
				"用两片大嘴唇咬住只一吸就咽了下去",
				"一歪嘴巴吞了下去",
				"再往嘴里乒乒乓乓一扔",
				"皱着眉头痛心疾首地吃了下去",
				"望天上一扔，伸出脖子叭地一声接住",
				"往嘴巴用力使劲里一塞",
				"硬着头皮贼喊捉贼地吃了下去",
				"吧嗒吧嗒贼眉鼠眼地吃了下去",
				"含在嘴里如火如荼热气腾腾地吞了下去",
				"有滋有味连手指都吃了下去",
				"嚼都没嚼就伸脖踮脚地咽了下去",
				"肥肥地往下一吞",
				"唏唏溜溜就岔着气吃下了肚子",
				"一点点咬着吃了岔了气",
				"张开血盆大口，倒拎着往嘴里一扔",
				"吃得神经错乱眼冒金星",
				"吃得如痴如狂东倒西歪",
				"吃得神采奕奕情窦大开",
				"吃得神魂颠倒四面楚歌",
				"吃得翻肠倒肚天昏地暗",
				"狼吞虎咽地反反复复左嚼右嚼咽了下去",
				"咔嚓咔嚓地大嚼了起来，只一会儿就整个连假牙都咽了下去",
				"痛苦不堪地吃了下去",
		};
		
		char msg[255];
		message_vision (snprintf(msg, 255,"$N%s%s%s。",hows[random(29)],manners[random(27)],actions[random(24)]), me,this);

		if(me->query("yuandna/cai/count")>10)
			return notify_fail("美味虽丰，怎奈你食量有限，再也无法多吃一点了。");

		me->add("yuandna/cai/count",1);
		me->del("yuandna/cai/get");
		
		int i=random(10);
		int exp, money;
		CContainer * bot;

		if(i>7)
			i=5;
		else
			i=3;
	
		switch(random(i))
		{
		case 0:
			exp=random(150)+100;
			if(me->query("level")<10)
				exp=1;
			tell_object(me,snprintf(msg, 255,"细品之下你觉得「%s」别有滋味，结果你从中领悟了%d点经验。\n",querystr("name"),exp));
			me->add("combat_exp",exp);
			me->UpdateMe();
			break;
		case 1:
			tell_object(me,"你觉得从口中吐出一团嚼不烂的东西，仔细一看，“哇”，发财了，原来是一张「银票」！\n");
			bot = load_item("yinpiao1");
			if(me->query("level")>10)
				bot->set("value", random(5000)+100);
			else
				bot->set("value", 100);
			bot->move(me);
			break;
		case 2:
			tell_object(me,"只听“嘎嘣”一声，你咬到了一块硬梆梆的东西，和着碎牙吐出来一看，原来是一块晶莹剔透的「玉片」！\n");
			load_item("yupian")->move(me);
			break;
		case 3:
			money=random(5000)+1;
			if(me->query("balance")<money )
			{
				if(me->query("balance")>0 )
					money=me->query("balance");
				else
					money=0;
			}
			me->add("balance",-money);
			tell_object(me,snprintf(msg, 255,"“哎哟！”你吃变质食品吃坏了肚子，结果买药治病花掉了%d两银子。\n",money));
			break;
		case 4:
			exp=random(100)+100;
			if(me->query("level")<10)
				exp=1;
			tell_object(me,snprintf(msg, 255,"你只觉脑子迷糊起来，混混顿顿中忘记了一些东西，你损失了%d点经验。\n",exp));
			me->add("combat_exp",-exp);
			me->UpdateMe();
			break;
		case 5:
			tell_object(me,"你的肚子中突然传来爆炸的声音！！\n");
			me->add("hp",-me->query("hp")*3/10);
			me->UpdateMe();
			break;
		}
		destruct(this);
		return 1;
	}
	return notify_fail("以你的个性，居然也舍得把它给别人，别开玩笑啦！");
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	//检查系统时间
	time_t t;	
	struct tm * newtime;

	time(&t);
	newtime = localtime(&t); 

	int month = newtime->tm_mon + 1;
	int day = newtime->tm_mday;

	if(month!=1 ||day>13)
	{
		CContainer * env = load_room("jy");
		if(!env->query("活动"))
			destruct(ob);
	}
	else
		ob->call_out(do_die, 3600);
}
FOOD_END;
