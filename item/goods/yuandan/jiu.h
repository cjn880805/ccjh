//jiu.h 酒
//秦波 2002、12、30

FOOD_BEGIN(CIjiu1);

virtual void create(int nFlag = 0)
{
	static char jiu[10][20]={"女儿红","竹叶青","杜康酒","绍兴加饭酒","龙岩沉缸酒","茅台酒","汾酒","泸州老窖","剑南春","清酒"};
	
	int index;
	index=random(10);
	set("unit", "瓶");
	set_name(jiu[index]);
	
	char msg[255];
	set("long",snprintf(msg, 255,"这是一%s上好的「%s」，醇香诱人…",querystr("unit"),querystr("name")));
	set_weight(20000);
	
	call_out(do_die, 3600);	
	
};

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(!strcmp(comm, "get") )
	{
		if(me->query("yuandna/jiu/get"))
		{
			tell_object(me,"别贪心哦，先把你身上的吃完也不迟啊！");	
			return 1;
		}
		else
		{
			me->set("yuandna/jiu/get",1);
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
		static char hows[4][255] = {
				"一口气把$HIC「$n」$COM喝了个底朝天！",
				"愁眉苦脸地捏着鼻子把$HIC「$n」$COM灌了下去！",
				"端起$HIC「$n」$COM细细品尝，不自不觉就把酒喝得干干净净了。",
				"伸出舌头舔了舔$HIC「$n」$COM，又舔了舔，再舔了舔，然后再斯条慢理地喝了下去。"
		};
		

		char msg[255];
		message_vision (snprintf(msg, 255,"$N%s",hows[random(4)]), me,this);
		if(me->query("yuandna/jiu/count")>5)
			return notify_fail("美味虽丰，怎奈你食量有限，再也无法多吃一点了。");

		me->add("yuandna/jiu/count",1);
		me->del("yuandna/jiu/get");

		int i=random(10);
		int exp,money;
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
				if(me->query("balance")>0)
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
