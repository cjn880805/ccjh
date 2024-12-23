//songshan_sha.h 沙天江
//by sound 2001-07-10

NPC_BEGIN(CNsongshan_sha);

virtual void create()
{
        set_name("沙江天", "sha tianjiang");
        set("nickname", "秃鹰");
        set("gender", "男性");
        set("class", "swordsman");
        set("age", 53);
        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);
	set("icon",young_man5);

        set("mp", 2000);
        set("max_mp", 2000);
        set("mp_factor", 30);
        set("max_hp",2000);
        set("hp",2000);
        set("combat_exp", 500000);
        set("shen_type", -1);

        set_skill("unarmed", 80);
        set_skill("sword", 80);
        set_skill("force", 80);
        set_skill("parry", 80);
        set_skill("dodge", 80);
        set_skill("songshan_sword", 80);
        set_skill("lingxu_bu", 80);

        map_skill("sword", "songshan_sword");
        map_skill("parry", "songshan_sword");
        map_skill("dodge", "lingxu_bu");

        create_family("嵩山派", 13, "弟子");

        carry_object("changjian")->wield();
        carry_object("cloth")->wear();
}

NPC_END;