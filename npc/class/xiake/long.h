//long.h
//code by zwb
//1-15

XIAKE_BEGIN(CNxiake_long);

virtual void create()
{
		set_name("龙木", "long daozhu");
        set("title", "侠客岛岛主");
        set("gender", "男性" );
        set("age", 60);
        set("long","这是个看起来五十来岁的汉子，面眉全面，脸色红润，着一袭黄袍，昂然挺立。");
	set("icon",old_man2);	

        set("int", 30);
        set("str", 25);
        set("con", 30);
        set("dex", 25);

        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 100);

        set("hp",4000);
        set("max_hp", 12000);
        set("mp", 2000);
        set("max_mp", 2000);
        set("mp_force", 150);
        set("combat_exp", 5000000);
        set("score", 250000);

        set_skill("force", 180);
        set_skill("taiji_shengong", 150);
        set_skill("dodge", 120);
        set_skill("tiyunzong", 100);
        set_skill("unarmed", 180);
        set_skill("taiji_quan", 150);
        set_skill("parry", 180);
        set_skill("sword", 200);
        set_skill("taiji_jian", 160);
        set_skill("taoism", 200);
        set_skill("literate", 100);
        map_skill("force", "taiji_shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji_quan");
        map_skill("parry", "taiji_jian");
        map_skill("sword", "taiji_jian");
        set("chat_chance", 5);

        set_inquiry("腊八粥",ask_zhou);
        set_inquiry("侠客岛","这个岛是我和木兄弟无意中发现的。");

 
		create_family("侠客岛", 1, "岛主");

        carry_object("changjian")->wield();
        carry_object("cloth")->wear();
        add_money(1000);
}

virtual char * chat_msg()
{
	switch(random(2))
	{
	case 0:
		return "龙木微微笑道：你也认为这里有腊八粥？";
	case 1:
		return "龙木微微笑道：太玄经是什么？";
	}
	return "";
}

XIAKE_END;