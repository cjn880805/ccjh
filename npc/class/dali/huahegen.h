//huahegen.h
//Lanwood 2000-01-05

NPC_BEGIN(CNdali_huahegen);

virtual void create()
{
	set_name("华赫金", "hua hejin");
	set("title",  "大理司徒" );
	set("long", "他是大理国三大公之一。");
	set("gender", "男性");
	set("age", 40);
	set("icon", young_man4);
	
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 30);
	set("dex", 25);
	
	set("max_hp", 4500);
	set("mp", 3000);
	set("max_mp", 3000);
	set("mp_factor", 100);
	set("combat_exp", 750000);
	set("score", 200000);

    set_skill("force", 80);
    set_skill("dodge", 90);
    set_skill("parry", 80);
    set_skill("cuff", 95);
    set_skill("sword", 80);
    set_skill("staff", 80);
	set_skill("kurong_changong", 80);
    set_skill("tiannan_step", 90);
    set_skill("jinyu_quan", 95);
    set_skill("duanjia_sword", 80);
	set_skill("literate", 60);

	map_skill("force", "kurong_changong");
	map_skill("dodge", "tiannan_step");
	map_skill("cuff", "jinyu_quan");
	map_skill("sword", "duanjia_sword");
	map_skill("staff", "duanjia_sword");
	map_skill("parry", "duanjia_sword");
	prepare_skill("cuff", "jinyu_quan");

	setup();
	carry_object("cloth")->wear();
	carry_object("changjian")->wield();
	add_money(2000);

	create_family("大理段家",19,"武将");
};

NPC_END;
