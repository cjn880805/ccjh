// pub_xiaoheshang.c

// code by Fisho
// date:2000-12-17

NPC_BEGIN(CNpub_xiaoheshang);

virtual void create()
{
	set_name("小和尚", "xiao heshang" );

	set("icon", young_monk);
	set("gender", "男性" );
	set("age", 14);
	set("long", "这是个机灵乖巧的小和尚");
	set("str", 15);
	set("dex", 20);
	set("con", 17);
	set("int", 15);
	set("shen_type", 1);
	
	set_skill("unarmed", 50);
	set_skill("dodge", 35);
	set_temp("apply/attack", 5);
	set_temp("apply/defense", 5);
	set("combat_exp", 7500);
	
	set("chat_chance", 20);
	set("attitude", "peaceful");
	set_inquiry("定力" ,ask_dingli);
	set_inquiry("禅力",ask_changli);
	set_inquiry("观音","你玩完啦，居然连我的主人都不认识！");
	
}

virtual char *chat_msg()
{
	switch (random(4))
	{
	case 0:
		return "小和尚道：南无阿弥陀佛！";
	case 1:
		return "小和尚道：南无弥勒佛菩萨！";
	case 2:
		return "小和尚道：南无大势致菩萨！";
	case 3:
		return "小和尚道：南无大慈大悲观世音菩萨！";
	}
	return "";
}


static char * ask_dingli(CNpc *ob,CChar *me)
{
	if ( me->query("chanxin/save")>=2 )
	{
		me->set("chanxin/save",3);
		return "这个麽你还是有一点的！";		
	}
	else
	{
		return "别给我打哈哈，瞧你这德性！";
	}

	return "";
}

static char * ask_changli(CNpc *ob,CChar *me)
{
	if ( me->query("chanxin/save")>=3 )
	{
		me->set("chanxin/save",4);
		return "这个麽还不错，要到楼上来喝点酒么！";
	}
	else
	{
		return "别给我打哈哈，瞧你这德性！";
	}

	return "";
}

/*
void serve_tea(CChar * who)
{
	CContainer * obn;
	
	if( !who->query_temp("marks/sit") )
		return;
	
	obn = load_item("xiangcha");//香茶
	obn->move(environment());
	message_vision("小和尚拿出紫沙小茶壶，沏了杯香茶，放在桌上．", who);
	
	obn = load_item("jiuping");//酒瓶
	obn->move(environment());
	obn = load_item("pork");//东坡肉
	obn->move(environment());
	obn = load_item("geng");//桂花鲜栗羹
	obn->move(environment());
	obn = load_item("shrimp");//龙井虾仁
	obn->move(environment());
	obn = load_item("chicken");//叫化童鸡
	obn->move(environment());
	obn = load_item("fish");//西湖醋鱼
	obn->move(environment());
	message_vision("然后拿出一瓶酒和一盘盘好吃的放在桌上．", who);
	
	return;
}
*/

NPC_END;