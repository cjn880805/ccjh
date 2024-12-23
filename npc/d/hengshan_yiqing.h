//yiqing.h
//code by zwb
//12-25
//inherit F_MASTER;

NPC_BEGIN(CNHengShan_yiqing);

virtual void create()
{

		set_name("仪卿","yi qing");

	set("foolid",151);        set("gender", "女性");
        set("class", "bonze");
        set("age", 35);
        set("attitude", "peaceful");
        set("per", 24);
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);
 	set("icon",young_woman8);

        set("mp", 1400);
        set("max_mp", 1400);
        set("mp_factor", 30);
        set("max_mp", 1000);
        set("combat_exp", 500000);
        set("shen_type", 1);

        set_skill("unarmed", 90);
        set_skill("sword", 90);
        set_skill("force", 90);
        set_skill("parry", 90);
        set_skill("dodge", 90);
        set_skill("hengshan_jian", 90);
        set_skill("lingxu_bu", 90);

        map_skill("sword", "hengshan_jian");
        map_skill("parry", "hengshan_jian");
        map_skill("dodge", "lingxu_bu");

        create_family("恒山派", 14, "弟子");

        carry_object("changjian")->wield();
        carry_object("cheng_cloth")->wear();
}

NPC_END;