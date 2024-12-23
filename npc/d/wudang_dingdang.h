// wudang_dingdang.c 丁当

//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNwudang_dingdang);

virtual void create()
{
	set_name("丁玲", "ding dang");
	set("gender", "女性" );
	set("age", 18);
        set("icon",girl1);

	set("long", "一个十七八岁的少女，身穿淡绿衫子，一张瓜子脸，秀丽美艳。 ");
	set("shen_type", 1);
	set("combat_exp", 100000);
	set("str", 18);
	set("dex", 22);
	set("con", 25);
	set("int", 35);
	set("per",30);
	set("attitude", "friendly");
	
	set("hp", 2000);
	set("max_hp", 6000);
	set("mp", 2000);
	set("max_mp", 2000);
	set("mp_factor", 50);
	
	set_skill("force", 100);
	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("dodge", 200);
	set_skill("taiji_shengong", 200);
	set_skill("taiji_quan", 200);
	set_skill("tiyunzong", 500);
	
	map_skill("force","taiji_shenfong");
	map_skill("unarmed","taiji_quan");
	map_skill("parry","taiji_quan");
	map_skill("dodge","tiyunzong");
	set("chat_change",15);
	
	set_inquiry("石中玉",inquiry_yu);
	set_inquiry("摩天崖","  前面这座山就是了，你要小心呀，那个老头的武功好强呀。 ");
	set_inquiry("玄铁令","  据说是在石破天手里，真假我就不知道了。 ");

	set_temp("shoupa",1);
	
	carry_object("shouzhuo")->wear();
	carry_object("yupei")->wear();
	add_money( 1000);
}

virtual char * chat_msg()
{
	switch (random(4))
	{
	case 0:
		return "丁当念叨着: 也不知道我的玉哥哥现在怎么样了。 ";
	case 1:
		return "丁当暗暗抹了把眼泪。 ";
	case 2:
		return "丁当一跺脚，说道: 不行，我要上摩天崖把我的玉哥哥救回来。 ";
	case 3:
		return "丁当叹了口气，说道: 要是有玄铁令就好了。 ";
	}
	return "";
}

static char * inquiry_yu(CNpc *who,CChar *me)
{
	CContainer * obn;
	char msg[255];
	
	who->say(snprintf(msg,255,"这位%s，玉哥哥是我的夫君， 可是去年在雪山派被谢烟客抓去，囚禁起来。现在也不知是死是活。唉￣ ", query_respect(me) ), me );

	if(who->query_temp("shoupa")==0)
	{  
		who->say("我已经托人去摩天崖看看了，也不知道怎么样了。 ", me);
		who->say("真急人！", me);
		who->SendMenu(me);
		return 0;
	}

	who->say("我这里有一个手帕，是我随身之物，你看到我的玉哥哥 你就把手帕交给他，他会明白的。拜托了。 ",me);
	who->SendMenu(me);
	obn=load_item("shoupa");//手帕
	obn->move(me);
	who->set_temp("shoupa",0l);
	message_vision("$N从怀里拿出一个漂亮的手帕，交给$n。", who, me);
	return 0;
}

NPC_END;