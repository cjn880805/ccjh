//hengshan_liuzf.h 刘正风
//by sound 2001-07-10

NPC_BEGIN(CNhenshan_liuzf);

virtual void create()
{
	set_name("刘清风", "liu zhengfeng");

	set("long",
		"一个胖老者。恂恂有礼，便如一个财主乡绅，有些小小的\n"
		"富贵之气，又有些土气，但有时突然显出勃勃英气，不失\n"
		"高手风范。\n");

        set("nickname", "回风落雁");

	set("gender", "男性");
	set("age", 45);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 26);
	set("int", 30);
	set("con", 30);
	set("dex", 28);
	set("icon",old_man2);
	
	set("hp", 2000);
	set("max_hp", 2000);
	
	set("mp", 2000);
	set("max_mp", 2000);
	set("mp_factor", 30);

	set("combat_exp", 1000000);
	set("score", 50000);

        set_skill("unarmed", 120);
        set_skill("sword", 120);
        set_skill("force", 120);
        set_skill("parry", 120);
        set_skill("dodge", 120);
        set_skill("hengshan_sword", 120);
        set_skill("lingxu_bu", 120);

        map_skill("sword", "hengshan_sword");
        map_skill("parry", "hengshan_sword");
        map_skill("dodge", "lingxu_bu");

        create_family("衡山派", 13, "弟子");
	
	carry_object("cloth")->wear();
	carry_object("changjian")->wield();
}

NPC_END;
