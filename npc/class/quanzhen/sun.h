//sun.c 孙不二
//Lanwood
//2001-01-15

NPCQUANZHEN_BEGIN(CNquanzhen_sun);

virtual void create()
{
	set_name("孙说一", "sun suoyi");
	set("gender", "女性");
	set("age", 33);
	set("class", "taoist");
	set("nickname", "清净散人");
	set("long",  "她就是全真教二代弟子中唯一的女弟子孙说一孙真人。她本是马玉入道前的妻子，道袍上绣着一个骷髅头。");
	set("attitude", "peaceful");
	set("shen_type",1);
	set("str", 30);
	set("int", 29);
	set("con", 29);
	set("dex", 29);
	set("foolid",35);
	set("title","全真七子之末");
	set("chat_chance_combat", 60);
	
	set("hp", 4000);
	set("max_hp", 12000);
	
	set("mp", 6000);
	set("max_mp", 6000);
	set("mp_factor", 100);
	
	set("combat_exp", 500000);
	set("score", 300000);
	
	set_skill("force", 180);
	set_skill("sword", 180);
	set_skill("dodge", 160);
	set_skill("parry", 160);
	set_skill("unarmed",180);
	set_skill("strike",180);

	set_skill("xiantian_qigong", 200);    //先天气功
	set_skill("quanzhen_jian",200);  //全真剑
	set_skill("jinyan_gong", 180);   //金雁功
	set_skill("haotian_zhang", 200);    //昊天掌

	set_skill("literate",160);
	set_skill("taoism",150);
	
	map_skill("force", "xiantian_qigong");
	map_skill("sword", "quanzhen_jian");
	map_skill("dodge", "jinyan_gong");
	map_skill("parry", "quanzhen_jian");
	map_skill("strike", "haotian_zhang");
	prepare_skill("strike", "haotian_zhang");
	
	create_family("全真教", 2, "弟子");
	
	set("book_count",1);
	set_inquiry("全真教", "我全真教是天下道家玄门正宗。");
	set_inquiry("昊天掌", ask_me);
	
	carry_object("changjian")->wield();
	carry_object("greyrobe")->wear();
}

virtual void attempt_apprentice(CChar * ob)
{
	char msg[255];
	if ( ob->query_skill("xiantian_qigong",1) < 80 )
	{
		say("你的本门内功心法火候不足,难以领略更高深的武功。", ob);
		SendMenu(ob);
		return;
	}
	if ( ob->query("repute")<30000) 
	{
		say("行侠仗义是我辈学武人的基本品质，你若能多做些狭义之事，我一定收你为徒。", ob);
		SendMenu(ob);
		return;
	}
	if (DIFFERSTR(ob->querystr("gender"), "女性"))
	{
		say("我不收男徒，你还是去拜我几位师兄为师吧。", ob);
		SendMenu(ob);
		return;
	}
	
	say("好吧，我就收下你这个徒弟了。");
	command(snprintf(msg,255,"recruit %ld" , ob->object_id() ));
}

static char * ask_me(CNpc * npc, CChar * who)
{
        if ( DIFFERSTR(who->querystr("family/family_name"), "全真教"))
                return "你与本教毫无瓜葛，我教的武功典籍可不能交给你。";

        if ( npc->query("book_count") < 1)
                return "你来晚了，昊天掌谱已经被人取走了。";
        
		npc->add("book_count", -1);
        load_item("zhangfapu")->move(who);
        return "好吧，这本「昊天掌谱」你拿回去好好研读。";
}

NPCQUANZHEN_END;