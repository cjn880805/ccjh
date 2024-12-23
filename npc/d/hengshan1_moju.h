//moju.h
//code by zwb
//12-25
//inherit F_MASTER;

NPC_BEGIN(CNHengShan1_moju);

virtual void create()
{

		set_name("Äª¾Þ","mo ju");
	set("foolid",145);
        set("title", "ºâÉ½ÅÉÕÆÃÅ");
        set("nickname", "°×ºÓÇïÔÂ");
        set("gender", "ÄÐÐÔ");
        set("class", "swordsman");
        set("age", 55);
        set("attitude", "peaceful");
        set("per", 22);
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);
 	set("icon",young_man4);

        set("mp", 2400);
        set("max_mp", 2400);
        set("mp_factor", 30);
        set("max_hp", 6000);
        set("combat_exp", 1200000);
        set("shen_type", 1);

        set_skill("unarmed", 150);
        set_skill("sword", 150);
        set_skill("force", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("hengshan_sword", 150);
        set_skill("lingxu_bu", 150);

        map_skill("sword", "hengshan_sword");
        map_skill("parry", "hengshan_sword");
        map_skill("dodge", "lingxu_bu");

        create_family("ºâÉ½ÅÉ", 13, "ÕÆÃÅ");

        carry_object("changjian")->wield();
        carry_object("cloth")->wear();
}

NPC_END;