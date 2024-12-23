// gan.c

//code by sound
//date:2001-07-12

NPC_BEGIN(CNwanjie_gan);

virtual void create()
{
        set_name("甘贝贝", "gan baobao");
        set("gender", "女性" );
        set("age", 35);
        set("str", 16);
        set("con", 24);
        set("dex", 21);
        set("per", 27);
        set("int", 27);
        set("icon",young_woman11);
        set("long",
		"甘贝贝容色清秀，多愁善感，年轻时曾与\n"
		"段正淳有过一段风流佳话，但段正淳未能\n"
		"与她共守白头，段正淳离去后，甘贝贝因\n"
		"有身孕，无奈嫁给中千恨为妻。\n");

        set("attitude", "friendly");

        set("max_mp", 200);
        set("mp", 200);
        set("mp_factor", 10);

        set("combat_exp", 35000);

        set_skill("finger", 60);
        set_skill("parry", 40);
        set_skill("dodge", 50);
        set_skill("sword", 30);
        set_skill("force", 50);
        set_skill("sun_finger",40);
        set_skill("yizhi_chan",60);

        map_skill("finger", "sun_finger");
        map_skill("parry", "sun_finger");

//	carry_object("red-dress")->wear();
//	carry_object("shoes")->wear();
}

NPC_END;