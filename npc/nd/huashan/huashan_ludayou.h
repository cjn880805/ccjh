// ludayou.c
//code by sound
//date:2001-07-19

NPC_BEGIN(CNhuashan_ludayou);

virtual void create()
{
	set("icon",young_man2);
        set_name("½С��", "lu dayou");

        set("nickname", "�����");
        set("gender", "����");
        set("age", 21);
        set("long", "½С��������Ⱥ�ĵ���λ���ӣ�����������ǽ��á�");
        set("attitude", "peaceful");

        set("str", 26);
        set("con", 30);
        set("int", 24);
        set("dex", 30);

        set("mp", 500);
        set("max_mp", 500);

        set("combat_exp", 50000);
        set("shen_type", 1);
        set("score", 2000);
/*
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
			(: exert_function, "powerup" :),
			(: exert_function, "recover" :)
        }) );
*/
        set_skill("unarmed", 60);
        set_skill("sword", 60);
        set_skill("force", 60);
        set_skill("parry", 60);
        set_skill("dodge", 60);
        set_skill("literate", 60);

        set_skill("huashan_sword", 60);
        set_skill("zixia_shengong", 60);
        set_skill("hunyuan_zhang", 60);
        set_skill("feiyan_huixiang", 60);

        map_skill("sword", "huashan_sword");
        map_skill("parry", "huashan_sword");
        map_skill("force", "zixia_shengong");
        map_skill("unarmed", "hunyuan_zhang");
        map_skill("dodge", "feiyan_huixiang");


        create_family("��ɽ��", 14, "����");

        carry_object("changjian")->wield();
        carry_object("cloth")->wear();
}

NPC_END;