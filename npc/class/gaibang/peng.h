//peng.h
//Lanwood 2000-01-06

NPC_BEGIN(CNgaibang_peng);

virtual void create()
{
	set_name("���о�", "peng youjing");
	set("title", "ؤ��Ŵ�����");
	set("nickname", "�Ʋ���ͷ");
	set("gender", "����");
	set("age", 50);
	set("long", 
		"���о���ؤ���о����ɵ����죬���Ÿɾ�����������л��ӡ�");
	set("icon",begger);

		
	set("attitude", "peaceful");
	
	set("str", 24);
	set("int", 20);
	set("con", 24);
	set("dex", 20);

	set("hp", 900);
	set("max_hp", 2700);
	
	set("mp", 1300);
	set("max_mp", 1200);
	set("mp_factor", 100);
	
	set("combat_exp", 220000);
	set("score", 20000);
	
	set_skill("force", 90);				// �����ڹ�
	set_skill("huntian_qigong", 90);	// ��������
	set_skill("unarmed", 85);			// ����ȭ��
	set_skill("xianglong_zhang", 80);	// ����ʮ����
	set_skill("dodge", 105);			// ��������
	set_skill("xiaoyaoyou", 95);		// ��ң��
	set_skill("parry", 90);				// �����м�
	set_skill("staff", 90);				// ��������
	
	map_skill("force", "huntian_qigong");
	map_skill("unarmed", "xianglong_zhang");
	map_skill("parry", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	
	create_family("ؤ��", 18, "�Ŵ�����");

	set("chat_chance_combat", 20);
	carry_object("gao4");
}

virtual char * chat_msg_combat()
{
	switch(random(2))
	{
	case 0:
		perform_action("unarmed xianglong", 1);
		break;
	case 1:
		perform_action("force recover", 0);
		break;
	}

	return 0;
}

virtual void attempt_apprentice(CChar * me)
{
	say("�Ϸ���ͽ�ܣ�������ذɡ�");
}

NPC_END;
