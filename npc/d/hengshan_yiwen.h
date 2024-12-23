//yiwen.h
//code by zwb
//12-25
//inherit F_MASTER;

NPC_BEGIN(CNHengShan_yiwen);

virtual void create()
{

		set_name("仪温","yi wen");

        set("gender", "女性");
        set("class", "bonze");
	set("foolid",152);        set("age", 28);
        set("attitude", "peaceful");
        set("per", 24);
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);
 	set("icon",young_woman9);

        set("mp", 1400);
        set("max_mp", 1400);
        set("mp_factor", 30);
        set("max_hp", 3000);
        set("combat_exp", 400000);
        set("shen_type", 1);

        set_skill("unarmed", 80);
        set_skill("sword", 80);
        set_skill("force", 80);
        set_skill("parry", 80);
        set_skill("dodge", 80);
        set_skill("hengshan_jian", 80);
        set_skill("lingxu_bu", 80);

        map_skill("sword", "hengshan_jian");
        map_skill("parry", "hengshan_jian");
        map_skill("dodge", "lingxu_bu");

        create_family("恒山派", 14, "弟子");

        carry_object("changjian")->wield();
        carry_object("cheng_cloth")->wear();
}

NPC_END;