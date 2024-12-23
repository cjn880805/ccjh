// quanzhen_zhangli.c 掌理道长

//code by Fisho
//date:2000-12-21

NPC_BEGIN(CNquanzhen_zhangli);

virtual void create()
{
	set_name("掌理道长", "zhangli");
	set("gender", "男性");
	set("age", 22);
	set("class", "taoist");
	set("long","这是一位年纪很轻的道人，他精明能干，是全真教第四代弟子中出类拔瘁的人物，前辈真人们分派他来掌理全教上下的杂务。");
	set("attitude", "friendly");
	set("shen_type",1);
	set("str", 22);
	set("int", 22);
	set("con", 22);
	set("dex", 22);
	set("icon",taoist);
			set("foolid",45);
	set("hp", 600);
	set("max_hp", 1800);
	set("mp", 1200);
	set("max_mp", 1200);
	set("mp_factor", 0l);
	
	set("combat_exp", 30000);
	set("score", 20000);
	
	set_skill("force", 60);
	set_skill("xiantian_qigong", 50);    //先天气功
	set_skill("sword", 60);
	set_skill("quanzhen_jian",60);  //全真剑
	set_skill("dodge", 50);
	set_skill("jinyan_gong", 50);   //金雁功
	set_skill("parry", 60);
	set_skill("unarmed",60);
	set_skill("strike",60);
	set_skill("haotian_zhang", 50);    //昊天掌
	set_skill("literate",50);
	set_skill("taoism",40);
	
	map_skill("force", "xiantian_qigong");
	map_skill("sword", "quanzhen_jian");
	map_skill("dodge", "jinyan_gong");
	map_skill("parry", "quanzhen_jian");
	map_skill("strike", "haotian_zhang");
	prepare_skill("strike", "haotian_zhang");
	
	create_family("全真教", 4, "弟子");
	
	set("book_count",1);
	set_inquiry("全真教","我全真教是天下道家玄门正宗。");
	set_inquiry("道德经",ask_me);
	
	carry_object("changjian")->wield();
	carry_object("greyrobe")->wear();
	
}

virtual void attempt_apprentice(CChar * ob)
{
	char msg[255];
	say(" 好吧，我就收下你这个徒弟了。");
	command(snprintf(msg,255,"recruit %ld" , ob->object_id() ));
}

static char * ask_me(CNpc *who ,CChar *me)
{
	CContainer *obj;
	static char msg[255];
	if (!( me->querymap("family")) || DIFFERSTR(me->querystr("family/family_name"), "全真教"))
		return snprintf(msg,255, "%s与本教毫无瓜葛，你这话可叫我弄不明白了。",query_respect(me) );
	if (who->query("book_count") < 1)
		return "你来晚了，道德经已经被人取走了。";
	who->add("book_count", -1);
	obj = load_item("daodejing_ii");//道德经「下卷」
	obj->move(me);
	return "好吧，这本「道德经」你拿回去好好研读。";
	
}

NPC_END;