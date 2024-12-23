//he.h
//Lanwood 2000-01-06

NPC_BEGIN(CNemei_he);

virtual void create()
{
	set_name("宁和师太", "ninghe shitai");
	set("long", "她是一位中年出家道姑，道冠高拢，慈眉善目。");
	set("gender", "女性");
	set("age", 45);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("repute", 10000);
	set("class", "bonze");
	set("icon",taoistess);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("foolid",4);
	set("dex", 30);
	set("per", 30);
	
	set("max_hp", 3000);
	
	set("mp", 1500);
	set("max_mp", 1500);
	
	
	set("combat_exp", 250000);
	set("score", 1000);
	set_skill("persuading", 80);
	set_skill("throwing", 70);
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("finger", 90);
	set_skill("parry", 100);
	set_skill("strike", 100);
	set_skill("blade", 90);
	set_skill("literate", 100);
	set_skill("mahayana", 100);
	set_skill("jinding_zhang", 90);
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

NPC_END;
