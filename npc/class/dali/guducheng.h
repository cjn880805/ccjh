//guducheng.h
//Lanwood 2000-01-05

DALIWEISHI_BEGIN(CNdali_guducheng);

virtual void create()
{
	set_name("古笃忠", "gu duzhong");
	set("title",  "大理护卫" );
	set("long", "他是大理国四大护卫之一。");
	set("icon", young_man5);

	set("gender", "男性");
	set("age", 40);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 30);
	set("int", 20);
	set("con", 25);
	set("dex", 25);
	
	set("max_hp", 3000);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 50);
	set("combat_exp", 300000);
	set("score", 100000);

    set_skill("force", 50);
    set_skill("dodge", 55);
    set_skill("parry", 55);
    set_skill("unarmed", 50);
    set_skill("sword", 50);
    set_skill("staff", 50);
	set_skill("kurong_changong", 50);
    set_skill("tiannan_step", 55);
    set_skill("jinyu_quan", 50);
    set_skill("duanjia_sword", 50);
	set_skill("literate", 35);

	map_skill("force", "kurong_changong");
	map_skill("dodge", "tiannan_step");
	map_skill("cuff", "jinyu_quan");
	map_skill("sword", "duanjia_sword");
	map_skill("staff", "duanjia_sword");
	map_skill("parry", "duanjia_sword");
	prepare_skill("cuff", "jinyu_quan");

	set_inquiry("指点武功", ask_me );

	carry_object("junfu")->wear();
	carry_object("changjian")->wield();
	add_money(1000);

	create_family("大理段家",19,"护卫");
};

DALIWEISHI_END;
