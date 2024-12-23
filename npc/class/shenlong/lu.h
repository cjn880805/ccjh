//lu.h
//code by zwb
//12-16

NPC_BEGIN(CNshenlong_lu);

virtual void create()
{

	set_name("陆高亭","lu gaoxuan");
	set("title", "神龙教军师");
	set("nickname", "神机妙算" );
	set("long", "他天庭饱满,地阔方圆,容貌颇为英俊.\n然而满面愁容,恰似顷刻间便有杀身之祸一般." );
	set("gender", "男性");
	set("age", 37);
	set("str", 35);
	set("dex", 20);
	set("max_hp", 4500);
    set("hp",1500);
	set("combat_exp", 300000);
	set("score", 40000);
	set("shen_type", -1);
	set("attitude", "peaceful");
	set("icon",young_man5);	

    set_skill("force", 70);
	set_skill("shenlong_xinfa", 70);
    set_skill("dodge", 70);
	set_skill("yixingbu", 70);
    set_skill("hand", 70);
	set_skill("shenlong_bashi", 70);
    set_skill("parry", 70);
    set_skill("staff", 70);
	set_skill("shedao_qigong", 70);
	set_skill("literate", 220);

	map_skill("force", "shenlong_xinfa");
	map_skill("dodge", "yixingbu");
	map_skill("hand", "shenlong_bashi");
	map_skill("parry", "shedao_qigong");
    map_skill("staff", "shedao_qigong");
	prepare_skill("hand", "shenlong_bashi");

	create_family("神龙教",2,"弟子");

	set_temp("apply/damage", 60);
	set("book_count", 1);
	set("mp", 1000); 
	set("max_mp", 1000);
	set("mp_force", 100);

    set_inquiry("神龙教","一般人是入不了我神龙教的");
	set_inquiry("洪安顺","教主脾气不好,要讨他欢心才好");
	set_inquiry("教主","教主脾气不好,要讨他欢心才好。");
	set_inquiry("口号","万年不老!永享仙福!寿与天齐!文武仁圣!");
	set_inquiry("秘籍",ask_me);

	carry_object("cloth")->wear();
	add_money(1000);
}


virtual void attempt_apprentice(CChar * player)
{
	char msg[255];

	if (DIFFERSTR(player->querystr("party/party_name"), "神龙教"))
	{
		say("你不是本教教众, 想来找死啊!",player);
		SendMenu(player);
		return;
	}
	if (player->query_skill("literate",1) < 40 ) 
	{
		say("你的学问太低了,还是努努力先提高一下吧!",player);
		SendMenu(player);
		return;
	}
	if (player->query("repute") > 0  ) 
	{
		say("我神龙教与世隔绝，向来不与您这种白道人物打交道，您请回吧！",player);
		SendMenu(player);
		return;
	}

	say("很好，很好。");
	command(snprintf(msg,255,"recruit %ld",player->object_id()) );
}

static char * ask_me(CNpc * npc , CChar * player)
{
	CContainer * obj;
	static char msg[255];

	if (DIFFERSTR(player->querystr("party/party_name"), "神龙教") ) 
		return snprintf(msg,255,"%s与本教素无来往，不知此话从何谈起？",query_respect(player));

	if (npc->query("book_count") < 1)
		return "你来晚了，本教的秘籍不在此处。";

	npc->add("book_count", -1);

	if (random(2) == 0)
		obj = load_item("shoufa");
	else
		obj = load_item("bufa");
	obj->move(player);

	npc->command(snprintf(msg,255,"rumor %s拿到%s啦！",player->name(1),obj->name(1)) );
	return snprintf(msg,255,"好吧，这本「%s」你拿回去好好钻研。",obj->query("name"));
}

SHENLONG_END;