// xiaolu.c
//code by sound
//date : 2001-07-18

NPC_BEGIN(CNguiyun_xiaolu);

virtual void create()
{
	set_name("陆冠杰", "lu guanying");
	set("title", "归云庄少庄主");
	set("long",
		"他是归云庄少庄主陆冠杰。他肩宽背阔，躯体甚是壮健，\n"
		"但行动之间温文尔雅，谦恭有礼，一派世家子弟风范。\n"
		"传闻他就是太湖群盗的首领，不知是真是假。\n");
	set("gender", "男性");
	set("age", 21);
	set("attitude", "peaceful");
	set("class", "fighter");
	set("shen_type", 1);
	set("per", 26);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	set("icon", young_man3);

	set("hp", 600);	
	set("max_hp", 600);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 20);
	set("combat_exp", 150000);
	set("score", 6000);

	set_skill("force", 50);
	set_skill("hunyuan_yiqi", 50);
	set_skill("dodge", 80);
	set_skill("shaolin_shenfa", 50);
	set_skill("strike", 50);
	set_skill("banruo_zhang", 50);
	set_skill("parry", 50);
	set_skill("blade", 50);
	set_skill("cibei_dao", 50);

	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("strike", "banruo_zhang");
	map_skill("parry", "cibei_dao");
	map_skill("blade", "cibei_dao");
/*
	set("inquiry", ([
		"归云庄" : (: ask_me :),
	]));
	set("book_count", 1);
*/
	carry_object("gangdao")->wield();
	carry_object("cloth")->wear();
}
/*
init()
{
	add_action("do_decide", "decide");
}
string ask_me()
{
	object me = this_player();
	me->set_temp("guiyun/decide",1);
	return "归云庄就是在下居处，如果"+RANK_D->query_respect(me)+"有意(decide)，我可修书一封代为引荐。\n";
}
int do_decide()
{
	object ob, me;
	me = this_player();
	if (!me->query_temp("guiyun/decide"))
	{
		message_vision("$N对$n奇怪地说道：你要决定干嘛？\n", this_object(), me);
		return 1;
	}
	me->delete_temp("guiyun/decide");
	ob = new(__DIR__"obj/xin");
	ob->move(me);
	message_vision("$N双手抱拳，道：有劳少庄主费心了。\n", me);
	message_vision("$N说道：好！\n", this_object());
	message_vision("$N给$n一封书信。\n", this_object(), me);
	message_vision("$N说道：这位"+RANK_D->query_respect(me) + "请先到敝庄盘恒数日，以后再图相叙。\n", this_object());
	return 1;
}
*/
NPC_END;