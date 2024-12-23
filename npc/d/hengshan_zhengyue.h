//zhengyue.h
//code by zwb
//12-25
//inherit F_MASTER;


NPC_BEGIN(CNHengShan_zhengyue);

virtual void create()
{

		set_name("郑月","zheng yue");
	set("foolid",154);
        set("gender", "女性");
        set("class", "swordsman");
        set("age", 16);
        set("attitude", "peaceful");
        set("per", 24);
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);
 	set("icon",girl2);

        set("mp", 1400);
        set("max_mp", 1400);
        set("mp_factor", 30);
        set("max_hp", 3000);
        set("combat_exp", 200000);
        set("shen_type", 1);

        set_skill("unarmed", 50);
        set_skill("sword", 50);
        set_skill("force", 50);
        set_skill("parry", 50);
        set_skill("dodge", 50);
        set_skill("hengshan_jian", 50);
        set_skill("lingxu_bu", 50);

        map_skill("sword", "hengshan_jian");
        map_skill("parry", "hengshan_jian");
        map_skill("dodge", "lingxu_bu");

        create_family("恒山派", 14, "弟子");

        carry_object("changjian")->wield();
        carry_object("cloth")->wear();
}

NPC_END;