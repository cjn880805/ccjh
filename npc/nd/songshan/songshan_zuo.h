//songshan_zuo.h ������
//by sound 2001-07-10

NPC_BEGIN(CNsongshan_zuo);

virtual void create()
{
	set_name("���²�", "zuo lengchan");

	set("long","���²��书�����뻯��Ϊ���ȸ����ǣ�����ٳ���");

        set("title", "������������");
        set("gender", "����");
        set("class", "swordsman");
        set("age", 55);
        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);
	set("icon",old_man2);

        set("mp", 2400);
        set("max_mp", 2400);
        set("mp_factor", 30);
        set("max_hp",2000);
        set("hp",2000);
        set("combat_exp", 1200000);
        set("shen_type", -1);
        set("score", 200000);

        set_skill("unarmed", 150);
        set_skill("sword", 150);
        set_skill("force", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("songshan_sword", 150);
        set_skill("lingxu_bu", 150);

        map_skill("sword", "songshan_sword");
        map_skill("parry", "songshan_sword");
        map_skill("dodge", "lingxu_bu");

        create_family("��ɽ��", 13, "����");

        carry_object("changjian")->wield();
        carry_object("cloth")->wear();
}

NPC_END;