// yinchang_zhou.c 周芷若

//code by Fisho
//date:2000-12-23
//inherit F_MASTER;

NPC_BEGIN(CNyinchang_zhou);

virtual void create()
{
	set_name("周采薇",  "zhou caiwei");
	set("long","她是峨嵋派的第四代掌门弟子。一张脸秀丽绝俗。身着一身淡黄衣裳。略显清减的巧笑中带了些许无奈。她很寂寞。");
	set("gender", "女性");
	set("age", 20);
        set("icon",young_woman9);

	set("attitude", "peaceful");
	set("shen_type", -1);
	set("class", "fighter");
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 30);
	
	set("max_hp", 10500);
	set("mp", 3500);
	set("max_mp", 3500);
	set("mp_factor", 1000);
	set("max_mp_factor", 1000);
	
	set("combat_exp", 1500000);
	set("score", 1000);
	set_skill("persuading", 80);
	set_skill("force", 100);
	set_skill("throwing", 100);
	set_skill("dodge", 100);
	set_skill("finger", 100);
	set_skill("parry", 100);
	set_skill("unarmed", 100);
	set_skill("strike", 100);
	set_skill("sword", 100);
	set_skill("claw", 100);
	set_skill("literate", 100);
	set_skill("mahayana", 100);
	set_skill("jinding_zhang", 100);
	set_skill("jiuyin_zhua", 100);
	set_skill("tiangang_zhi", 100);
	set_skill("huifeng_jian", 100);
	set_skill("zhutian_bu", 100);
	set_skill("linji_zhuang", 100);
	map_skill("force","linji_zhuang");
	map_skill("claw","jiuyin_zhua");
	map_skill("dodge","zhutian_bu");
	map_skill("strike","jinding_zhang");
	map_skill("sword","huifeng_jian");
	map_skill("parry","huifeng_jian");
	prepare_skill("strike","jinding_zhang");
	create_family("峨嵋派", 4, "掌门弟子");
	
	carry_object("changjian");
	carry_object("ycloth")->wear();
}

NPC_END;