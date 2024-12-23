//liucao.h
//code by zwb
//12-25
//inherit F_MASTER;

NPC_BEGIN(CNHengShan1_liucao);

virtual void create()
{

		set_name("刘草","liu cao");
	set("foolid",146);
        set("gender", "男性");
        set("class", "swordsman");
        set("long", "他是刘清风的最宠爱的小儿子。");
        set("age", 15);
        set("attitude", "peaceful");
        set("per", 29);
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);
	 	set("icon",boy2);

        set("mp", 500);
        set("max_mp", 500);
        set("mp_factor", 10);
        set("max_hp", 2100);
        set("combat_exp", 100000);
        set("shen_type", 1);

        set_skill("unarmed", 40);
        set_skill("sword", 40);
        set_skill("force", 40);
        set_skill("parry", 40);
        set_skill("dodge", 40);
        set_skill("hengshan_sword", 40);
        set_skill("lingxu_bu", 40);

        map_skill("sword", "hengshan_sword");
        map_skill("parry", "hengshan_sword");
        map_skill("dodge", "lingxu_bu");

        create_family("衡山派", 14, "弟子");

        carry_object("changjian")->wield();
        carry_object("female1_cloth")->wear();

}

NPC_END;