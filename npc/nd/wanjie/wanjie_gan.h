// gan.c

//code by sound
//date:2001-07-12

NPC_BEGIN(CNwanjie_gan);

virtual void create()
{
        set_name("�ʱ���", "gan baobao");
        set("gender", "Ů��" );
        set("age", 35);
        set("str", 16);
        set("con", 24);
        set("dex", 21);
        set("per", 27);
        set("int", 27);
        set("icon",young_woman11);
        set("long",
		"�ʱ�����ɫ���㣬����ƸУ�����ʱ����\n"
		"�������й�һ�η����ѻ�����������δ��\n"
		"�������ذ�ͷ����������ȥ�󣬸ʱ�����\n"
		"�����У����μ޸���ǧ��Ϊ�ޡ�\n");

        set("attitude", "friendly");

        set("max_mp", 200);
        set("mp", 200);
        set("mp_factor", 10);

        set("combat_exp", 35000);

        set_skill("finger", 60);
        set_skill("parry", 40);
        set_skill("dodge", 50);
        set_skill("sword", 30);
        set_skill("force", 50);
        set_skill("sun_finger",40);
        set_skill("yizhi_chan",60);

        map_skill("finger", "sun_finger");
        map_skill("parry", "sun_finger");

//	carry_object("red-dress")->wear();
//	carry_object("shoes")->wear();
}

NPC_END;