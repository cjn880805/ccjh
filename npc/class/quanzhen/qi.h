// quanzhen_qi.c 祁志诚

//code by Fisho
//date:2000-12-21

NPCQUANZHEN_BEGIN(CNquanzhen_qi);

virtual void create()
{
	set_name("祁志恳", "qi zhiken");
	set("gender", "男性");
	set("age", 24);
	set("class", "taoist");
	set("long","他就是全真教第三代弟子中的好手，谭在端的大弟子祁志恳。他相貌英俊，精明能干，深受长辈的信任，派遣他去掌管教中的经书典籍。");
	set("attitude", "friendly");
	set("shen_type",1);
	set("str", 25);
	set("int", 25);
	set("con", 24);
	set("dex", 24);
	set("icon",taoist);
	set("foolid",38);
	set("chat_chance_combat", 60);
	set("hp", 1500);
	set("max_hp", 4500);
	set("mp", 3000);
	set("max_mp", 3000);
	set("mp_factor", 60);
	
	set("combat_exp", 160000);
	set("score", 100000);
	
	set_skill("force", 120);
	set_skill("sword", 120);
	set_skill("dodge", 100);
	set_skill("parry", 120);
	set_skill("unarmed",120);
	set_skill("strike",80);

	set_skill("xiantian_qigong", 120);    //先天气功
	set_skill("quanzhen_jian",120);  //全真剑
	set_skill("jinyan_gong", 100);   //金雁功
	set_skill("haotian_zhang", 120);    //昊天掌

	set_skill("literate",100);
	set_skill("taoism",80);
	
	map_skill("force", "xiantian_qigong");
	map_skill("sword", "quanzhen_jian");
	map_skill("dodge", "jinyan_gong");
	map_skill("parry", "quanzhen_jian");
	map_skill("strike", "haotian_zhang");
	prepare_skill("strike", "haotian_zhang");
	
	create_family("全真教", 3, "弟子");
	
	set("book_count",1);
	set_inquiry("全真教","我全真教是天下道家玄门正宗。");
	set_inquiry("道德经",ask_me);
	
 	carry_object("changjian")->wield();
	carry_object("greyrobe")->wear();
	set("no_huan",1);
	
}

virtual void attempt_apprentice(CChar * ob)
{
	char msg[255];

	if ( ob->query_skill("xiantian_qigong",1) < 35 )
	{
		say("你的本门内功心法火候不足,难以领略更高深的武功。", ob);
		SendMenu(ob);
		return;
	}
	if ( ob->query("repute")<3000)
	{
		say("行侠仗义是我辈学武人的基本品质，你若能多做些狭义之事，我一定收你为徒。", ob);
		SendMenu(ob);
		return;
	}
	
	say(" 好吧，我就收下你这个徒弟了。");
	command(snprintf(msg,255,"recruit %ld" , ob->object_id() ));
}

static char * ask_me(CNpc *who,CChar *me)
{
	CContainer *obj;
	static char msg[255];
	if (!(me->querymap("family")) || DIFFERSTR(me->querystr("family/family_name"), "全真教"))
		return snprintf(msg,255,"%s与本教毫无瓜葛，你这话可叫我弄不明白了。",query_respect(me) );
	if (who->query("book_count") < 1)
		return "你来晚了，道德经已经被人取走了。";
	who->add("book_count", -1);
	obj = load_item("daodejing_ii");//道德经「下卷」
	obj->move(me);
	return "好吧，这本「道德经」你拿回去好好研读。";
	
}

NPCQUANZHEN_END;