//xiangguonian.h
//code by zwb
//12-25
//inherit F_MASTER;

NPC_BEGIN(CNHengShan1_xiangguonian);

virtual void create()
{

		set_name("�����","xiang guonian");
	set("foolid",140);
        set("gender", "����");
        set("class", "swordsman");
        set("age", 25);
        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);
        set("per", 20);
 	set("icon",young_man3);

        set("mp", 1400);
        set("max_mp", 1400);
        set("mp_factor", 30);
        set("max_hp", 4500);
        set("combat_exp", 300000);
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

        create_family("��ɽ��", 14, "����");

        carry_object("changjian")->wield();
        carry_object("cloth")->wear();
}

NPC_END;