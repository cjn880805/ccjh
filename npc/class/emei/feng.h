//feng.h
//Lanwood 2000-01-06

NPC_BEGIN(CNemei_feng);

virtual void create()
{
	set_name("宁风师太", "ningfeng shitai");
	set("long", "她是一位中年师太，只见她眉目底垂，手中握着一把钢刀。自然而然的有股威严。");
	set("gender", "女性");
	set("age", 42);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("repute", 10000);
	set("class", "bonze");
	set("icon", taoistess);
	
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 30);
		set("foolid",3);
	set("max_hp", 3000);
	
	set("mp", 1500);
	set("max_mp", 1500);
	
	
	set("combat_exp", 250000);
	set("score", 1000);
	set_skill("persuading", 80);
	set_skill("force", 100);
	set_skill("throwing", 80);
	set_skill("dodge", 100);
	set_skill("finger", 100);
	set_skill("parry", 90);
	set_skill("strike", 100);
	set_skill("blade", 100);
	set_skill("literate", 100);
	set_skill("mahayana", 100);
	set_skill("jinding_zhang", 100);
	set_skill("tiangang_zhi", 100);
	set_skill("yanxing_dao", 100);
	set_skill("zhutian_bu", 100);
	set_skill("linji_zhuang", 100);
	map_skill("force","linji_zhuang");
	map_skill("finger","tiangang_zhi");
	map_skill("dodge","zhutian_bu");
	map_skill("strike","jinding_zhang");
	map_skill("blade","yanxing_dao");
	map_skill("parry","yanxing_dao");
	set_inquiry("伤药", ask_yao);
	set_inquiry("武器", ask_jian);
	
	set("gao_count",3);
	set("jian_count",2);
	create_family("峨嵋派", 4, "弟子");
	
	
	carry_object("gangdao")->wield();
	carry_object("cloth")->wear();
};

virtual void attempt_apprentice(CChar * me)
{
	say("阿弥陀佛！贫尼不收弟子。", me);
	say("你若想继续学峨嵋派的功夫，还是去找我俗家师妹吧。", me);
	SendMenu(me);
}

static char * ask_yao(CNpc * me, CChar * who)
{
        if (DIFFERSTR(who->querystr("family/family_name"), "峨嵋派"))
                return "你与本派素无来往，不知此话从何谈起？";

        if (who->query("hp") >= who->query("max_hp"))
                return "你未曾受伤，讨这药膏做什么？";
        
		if (who->PresentName("tianxiang_gao", IS_ITEM))
                return "你身上不是带着本门秘药？！";
        
		if (me->query("gao_count") < 1)
                return "你来晚了，本门秘药已尽数给了本派弟子。";
        me->add("gao_count", -1);

		load_item("tianxiang_gao")->move(who);
        return "我这里有本门秘药，你拿去疗伤吧。";
}

static char * ask_jian(CNpc * me, CChar * who)
{
        
        if (DIFFERSTR(who->querystr("family/family_name"), "峨嵋派"))
                return "你与本派素无来往，不知此话从何谈起？";
        
		if (me->query("jian_count") < 1)
                return "我现在没有什么武器好给，你下次在来吧。";
        if (who->PresentName("ruanjian", IS_ITEM))
                return "你身上不是带着武器吗？怎么还来要！";
        me->add("jian_count", -1);
        load_item("ruanjian")->move(who);
        return "我这里有一把软剑，你拿去用吧。";
}

NPC_END;
