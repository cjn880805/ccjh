//hengshan_liuzf.h ������
//by sound 2001-07-10

NPC_BEGIN(CNhenshan_liuzf);

virtual void create()
{
	set_name("�����", "liu zhengfeng");

	set("long",
		"һ�������ߡ��������񣬱���һ������������ЩСС��\n"
		"����֮��������Щ����������ʱͻȻ�Գ�����Ӣ������ʧ\n"
		"���ַ緶��\n");

        set("nickname", "�ط�����");

	set("gender", "����");
	set("age", 45);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 26);
	set("int", 30);
	set("con", 30);
	set("dex", 28);
	set("icon",old_man2);
	
	set("hp", 2000);
	set("max_hp", 2000);
	
	set("mp", 2000);
	set("max_mp", 2000);
	set("mp_factor", 30);

	set("combat_exp", 1000000);
	set("score", 50000);

        set_skill("unarmed", 120);
        set_skill("sword", 120);
        set_skill("force", 120);
        set_skill("parry", 120);
        set_skill("dodge", 120);
        set_skill("hengshan_sword", 120);
        set_skill("lingxu_bu", 120);

        map_skill("sword", "hengshan_sword");
        map_skill("parry", "hengshan_sword");
        map_skill("dodge", "lingxu_bu");

        create_family("��ɽ��", 13, "����");
	
	carry_object("cloth")->wear();
	carry_object("changjian")->wield();
}

NPC_END;
