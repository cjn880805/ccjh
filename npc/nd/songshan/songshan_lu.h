//songshan_lu.h Â½°Ø
//by sound 2001-07-10

NPC_BEGIN(CNsongshan_lu);

virtual void create()
{
        set_name("Â½ËÉ", "lu bai");
        set("nickname", "ÏÉº×ÊÖ");
        set("gender", "ÄÐÐÔ");
        set("class", "swordsman");
        set("age", 45);
        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);
	set("icon",old_man2);

        set("mp", 2000);
        set("max_mp", 2000);
        set("mp_factor", 30);
        set("max_hp",2000);
        set("hp",2000);
        set("combat_exp", 800000);
        set("shen_type", -1);

        set_skill("unarmed", 80);
        set_skill("sword", 100);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("songshan_sword", 100);
        set_skill("lingxu_bu", 100);

        map_skill("sword", "songshan_sword");
        map_skill("parry", "songshan_sword");
        map_skill("dodge", "lingxu_bu");

        create_family("áÔÉ½ÅÉ", 13, "µÜ×Ó");

        carry_object("changjian")->wield();
        carry_object("cloth")->wear();
}

NPC_END;