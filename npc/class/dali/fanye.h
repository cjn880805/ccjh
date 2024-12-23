//fanye.h
//Lanwood 2000-01-05

NPC_BEGIN(CNdali_fanye);

virtual void create()
{	
	set_name("范骏", "fan jun");
	set("title",  "大理司马" );
	set("long", "他是大理国三公之一。");
	set("gender", "男性");
	set("icon", young_man2);

	set("age", 40);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 25);
	set("int", 30);
	set("con", 30);
	set("dex", 25);
	
	set("max_hp", 4500);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 100);
	set("combat_exp", 600000);
	set("score", 200000);

    set_skill("force", 80);
    set_skill("dodge", 80);
    set_skill("parry", 80);
    set_skill("cuff", 80);
    set_skill("sword", 80);
    set_skill("staff", 80);
	set_skill("kurong_changong", 80);
    set_skill("tiannan_step", 80);
    set_skill("jinyu_quan", 80);
    set_skill("duanjia_sword", 80);
	set_skill("literate", 80);

	map_skill("force", "kurong_changong");
	map_skill("dodge", "tiannan_step");
	map_skill("cuff", "jinyu_quan");
	map_skill("sword", "duanjia_sword");
	map_skill("staff", "duanjia_sword");
	map_skill("parry", "duanjia_sword");
	prepare_skill("cuff", "jinyu_quan");

	carry_object("cloth")->wear();
	carry_object("changjian")->wield();
	add_money(2000);

	create_family("大理段家",19,"武将");
};


NPC_END;
