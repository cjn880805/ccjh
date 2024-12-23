// zhike.h 知客道长

//code by Fisho
//date:2000-12-21

NPC_BEGIN(CNquanzhen_zhike);

virtual void create()
{
	set_name("知客道长", "zhike daozhang");
	set("gender", "男性");
	set("age", 42);
	set("class", "taoist");
	set("icon", taoist);
	
	set("long",  "他是全真教第四代弟子中年纪最大的一位，以前做过小买卖");                
	set("attitude", "friendly");
	set("shen_type",1);
	set("str", 18);
	set("int", 18);
	set("con", 20);
	set("dex", 21);
	set("foolid",47);
	set("hp", 500);
	set("max_hp", 1500);
	set("mp", 900);
	set("max_mp", 900);
	set("mp_factor", 0l);
	
	set("combat_exp", 20000);
	set("score", 15000);
	
	set_skill("force", 40);
	set_skill("xiantian_qigong", 40);    //先天气功
	set_skill("sword", 40);
	set_skill("quanzhen_jian",40);  //全真剑
	set_skill("dodge", 50);
	set_skill("jinyan_gong", 40);   //金雁功
	set_skill("parry", 50);
	set_skill("strike",50);
	set_skill("haotian_zhang", 50);    //昊天掌
	set_skill("literate",60);
	set_skill("taoism",50);
	
	map_skill("force", "xiantian_qigong");
	map_skill("sword", "quanzhen_jian");
	map_skill("dodge", "jinyan_gong");
	map_skill("parry", "quanzhen_jian");
	map_skill("strike", "haotian_zhang");
	prepare_skill("strike", "haotian_zhang");
	
	create_family("全真教", 4, "弟子");
	
	set("book_count",1);
	set_inquiry("全真教",  "我全真教是天下道家玄门正宗。");
	set_inquiry("西毒", ask_me);
	
	carry_object("changjian")->wield();
	carry_object("greyrobe")->wear();	
}

virtual void attempt_apprentice(CChar * ob)
{
	char msg[255];
	say(" 好吧，我就收下你这个徒弟了。");
	command(snprintf(msg,255,"recruit %ld" , ob->object_id() ));
}

static char * ask_me(CNpc * me, CChar * who)
{
        who->set_temp("tmark/指",1);
        return "去年祖师假死以诱西毒来抢夺九阴真经，结果西毒被祖师以一阳指破了修炼多年的蛤蟆功。";
}

NPC_END;