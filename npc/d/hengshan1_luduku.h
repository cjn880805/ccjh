//luduku.h
//code by zwb
//12-25
//inherit F_MASTER;

NPC_BEGIN(CNHengShan1_luduku);

virtual void create()
{

		set_name("Â³¶À¿Ý","lu du ku");
	set("foolid",142);
        set("nickname", "½ðÑÛµñ");
        set("gender", "ÄÐÐÔ");
        set("class", "swordsman");
        set("age", 45);
        set("attitude", "peaceful");
        set("per", 13);
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);
 	set("icon",young_man3);

        set("mp", 1400);
        set("max_mp", 1400);
        set("mp_factor", 30);
        set("max_hp", 4500);
        set("combat_exp", 600000);
        set("shen_type", 1);

        set_skill("unarmed", 80);
        set_skill("sword", 80);
        set_skill("force", 80);
        set_skill("parry", 80);
        set_skill("dodge", 80);
        set_skill("hengshan_sword", 80);
        set_skill("lingxu_bu", 80);

        map_skill("sword", "hengshan_sword");
        map_skill("parry", "hengshan_sword");
        map_skill("dodge", "lingxu_bu");

        create_family("ºâÉ½ÅÉ", 13, "µÜ×Ó");

        carry_object("changjian")->wield();
        carry_object("cloth")->wear();
}

NPC_END;