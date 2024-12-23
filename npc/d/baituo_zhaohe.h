//zhaohe.h
//code by zwb
//12-16

NPC_BEGIN(CNBaiTuo_zhaohe);

virtual void create()
{
	set_name("�Գ���","zhaohe");

    set("nickname",  "������ħ"  );
    set("title", "������̳���");
    set("gender", "����");
    set("age", 42);
    set("shen_type", -1);
    set("long","����������̵ĳ��ϡ�");
    set("attitude", "peaceful");
 	set("icon",old_man1);

    set("per", 21);
    set("str", 30);
    set("int", 30);
    set("con", 30);
    set("dex", 30);

    set("hp", 3000);
    set("max_hp", 9000);
    set("mp", 3000);
    set("max_mp", 3000);
    set("mp_factor", 300);

    set("combat_exp", 1500000);
    set("score", 0l);

    set_skill("force", 150);
    set_skill("kuihua_xinfa", 150);
    set_skill("unarmed", 150);
    set_skill("changquan", 150);
    set_skill("dodge", 150);
    set_skill("lingxu_bu", 150);
    set_skill("parry", 150);
    set_skill("staff", 150);
    set_skill("tianshan_zhang", 150);

    map_skill("force", "kuihua_xinfa");
    map_skill("staff", "tianshan_zhang");
    map_skill("unarmed", "changquan");
    map_skill("dodge", "lingxu_bu");
    map_skill("parry", "tianshan_zhang");

    create_family("�������", 2, "����");

    carry_object("leizhendang")->wield();
    carry_object("cloth")->wear();
};



NPC_END;
