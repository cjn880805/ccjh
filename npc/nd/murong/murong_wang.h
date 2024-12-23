// wang.c 王夫人
//sound 2001-07-16

NPC_BEGIN(CNmurong_wang);

virtual void create()
{
	set_name("王夫人", "wang furen");
	set("gender", "女性");
	set("rank_info/respect", "夫人");
	set("title","曼佗罗山庄主");
	set("long", "她就是曼佗罗山庄的主人，她看上去虽以四十有加，但风韵尤存。");
	set("age", 40);
	set("attitude", "friendly");
	set("shen_type", 0l);
	set("str", 20);
	set("int", 22);
	set("con", 28);
	set("per", 30);
	set("dex", 23);
	set("icon",young_woman1);
	
	set("max_hp", 1500);
	set("hp", 1500);
	set("mp", 1000);
	set("max_mp", 1500);
	set("mp_factor", 0l);
	set("combat_exp", 80000);
	set("score", 15000);
	
	set_skill("shenyuan_gong", 70);
	set_skill("dodge",70);
	set_skill("force", 70);
	set_skill("shenyuan_gong", 70);
	set_skill("yanling_shenfa", 70);
	set_skill("parry", 70);
	set_skill("literate", 70);
	set_skill("strike", 65);
	map_skill("force", "shenyuan_gong");
	map_skill("dodge", "yanling_shenfa");
	set("no_talk",1);
	
	carry_object("shoe")->wear();
//	carry_object("red_silk")->wear();
	carry_object("skirt")->wear();
	set("no_huan",1);
/*
	set_inquiry("名字", "我就是曼佗罗山庄的主人，见到我难道没有什么表示吗？");
	set_inquiry("这里", "这里是曼佗罗山庄的庄院之所在，此处名为云锦楼？");
	set_inquiry("传闻",  "最近我那表亲慕容博不幸仙逝了。");
	set_inquiry("王语甜",  "语甜是我的宝贝女儿，你可别想打她的主意。");
	set_inquiry("慕容重复",  "慕容重复是我那不成器的侄儿，练就了以彼之道还施彼身的绝技，名震江湖。");
	set_inquiry("娘缳玉洞", "娘缳玉洞是我曼佗罗山庄的藏书之处，一般人是别想进去了。");
	set_inquiry("曼佗罗山庄", "这里就是曼佗罗山庄，我就是这里的主人。");
	set_inquiry("还施水阁", "那是燕子坞的秘密之所在，不过还施水阁的藏书比那里可是多的多呀。");	
*/
}

virtual void init(CChar *me)
{
	CNpc::init(me);
	if(is_fighting()) return;

	if( userp(me) && !is_fighting() && me->query_temp("xy/renwu1_1") && !me->query_temp("xy/renwu1_11")) 
	{
		tell_object(me,"\n王夫人惋惜地看了一眼$HIC“红装素裹”$COM，这是她千里迢迢从大理弄来的上佳茶花，只是现在却已渐渐凋零。");
		tell_object(me,"王夫人满面怒容地对着下人喝道：“你们这些不中用的东西，再侍弄不好这茶花，我把你们全部拿来做花肥！”");
		tell_object(me,"“唉！”王夫人轻轻地叹了一口气，沉吟道：“要是那姓段的小子在就好了... ...”\n");
		me->set_temp("xy/renwu1_11",1);//王夫人想种出红装素裹
	}
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(! strlen(ask))
	{
		if(me->query_temp("xy/renwu1_1") && !me->query_temp("xy/renwu1_8") )
		{
			AddMenuItem("向王夫人请教关于福地的问题", "fudi",me);
			if(me->query_temp("xy/renwu1_12") && !me->query_temp("xy/renwu1_71"))
				AddMenuItem("以种好茶花为交换条件", "tiaojian",me);	
		}
		AddMenuItem("向王夫人请教关于名字的问题", "name",me);
		AddMenuItem("向王夫人请教关于这里的问题", "zheli",me);
		AddMenuItem("向王夫人请教关于传闻的问题",  "chuanwen",me);
		AddMenuItem("向王夫人请教关于王语甜的问题",  "yutian",me);
		AddMenuItem("向王夫人请教关于慕容重复的问题",  "murong",me);
		AddMenuItem("向王夫人请教关于娘缳玉洞的问题", "yudong",me);
		AddMenuItem("向王夫人请教关于曼佗罗山庄的问题", "shanzhuang",me);
		AddMenuItem("向王夫人请教关于还施水阁的问题", "shueige",me);	
	}
	else if(!strcmp(ask, "name") )
	{
		say("我就是曼佗罗山庄的主人，见到我难道没有什么表示吗？",me);
	}
	else if(!strcmp(ask, "zheli") )
	{
		say("这里是曼佗罗山庄的庄院之所在，此处名为云锦楼？",me);
	}
	else if(!strcmp(ask, "chuanwen") )
	{
		say("最近我那表亲慕容博不幸仙逝了。",me);
	}
	else if(!strcmp(ask, "yutian") )
	{
		say("语甜是我的宝贝女儿，你可别想打她的主意。",me);
	}
	else if(!strcmp(ask, "murong") )
	{
		say("慕容重复是我那不成器的侄儿，练就了以彼之道还施彼身的绝技，名震江湖。",me);
	}
	else if(!strcmp(ask, "yudong") )
	{
		say("娘缳玉洞是我曼佗罗山庄的藏书之处，一般人是别想进去了。",me);
	}
	else if(!strcmp(ask, "shanzhuang") )
	{
		say("这里就是曼佗罗山庄，我就是这里的主人。",me);
	}
	else if(!strcmp(ask, "shueige") )
	{
		say("那是燕子坞的秘密之所在，不过还施水阁的藏书比那里可是多的多呀。",me);
	}
	else if(!strcmp(ask, "fudi")  && me->query_temp("xy/renwu1_1"))
	{
		if(me->query_temp("xy/renwu1_71"))
		{
			say("王夫人幽幽的道：“我家福地就在大理城郊，找着与否就要看你的造化和才智了...”",me);
			say("情急之下，你已有些责备之意：“你这不是消遣我来着？堂堂姑苏王夫人也不讲口齿？”",me);
			say("王夫人悻然道：“玉霞仙子素手纤，锦带轻罗碧镜前，舞尽桃花犹未罄，直教银河落九天。我言尽于此，多说无益，你还是请便吧。”",me);
			if(me->query_temp("xy/renwu1_11"))
				me->delete_temp("xy/renwu1_11");
			if(!me->query_temp("xy/renwu1_8"))
				me->set_temp("xy/renwu1_8",1);//回逍遥林和康流水对话，获取石甘露的消息
		}
		else
		{
			say("王夫人怒道：“此乃我家中之密，又怎可宣与外人知！”",me);
			if(!me->query_temp("xy/renwu1_12"))
				me->set_temp("xy/renwu1_12",1);//询问福地遭拒绝，答应种花换取
		}
	}
	
	else if(!strcmp(ask, "tiaojian") && me->query_temp("xy/renwu1_1") )
	{
		if(me->query_temp("xy/renwu1_11"))
		{
			say("王夫人沉吟片刻，道：“若你真能种好这“红装素裹”，我自然会告诉你福地何在！”",me);
			if(!me->query_temp("xy/renwu1_2"))
				me->set_temp("xy/renwu1_2",1);//获得种“红装素裹”的任务
		}
	}
	SendMenu(me);
	return 1;
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(EQUALSTR(ob->querystr("name"), "红装素裹") && EQUALSTR(ob->querystr("id"), "hong zhuang")
		&& me->query_temp("xy/renwu1_7") && !me->query_temp("xy/renwu1_71") )
	{
		destruct(ob);
		tell_object(me,"王夫人已一把抢过你手中的红装素裹，赞叹不已。");
		me->set_temp("xy/renwu1_71",1);//完成种“红装素裹”的任务
		return 1;
	}
	return 0;
}

NPC_END;