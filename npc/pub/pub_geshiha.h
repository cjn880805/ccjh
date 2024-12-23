NPC_BEGIN(CNpub_geshiha);

virtual void create()
{
	
	set_name("戈什哈","geshiha");
	
	set("icon", young_man3);
	set("gender", "男性");
	set("age", 25);
	
	set("long", "一个高大威猛的汉子，是靖海侯施琅大人的亲兵戈什哈。");
	set("combat_exp", 17500);
	set("shen_type", 1);
    set_skill("unarmed", 50);
    set_skill("dodge", 50);
	
	carry_object("male7_cloth")->wear();
	carry_object("pixue")->wear();
	carry_object("qinqin_sword")->wield();
	
	
};



NPC_END;
