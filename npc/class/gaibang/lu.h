//lu.h
//Lanwood 2000-01-06

NPCGAIBANG_BEGIN(CNgaibang_lu);

virtual void create()
{
	set_name("³����", "lu youjiao");
	set("title", "ؤ��Ŵ�����");
	set("nickname", "�ư���ͷ");
	set("gender", "����");
	set("age", 45);
	set("long", 
		"�ؽ���Ȼ�书�㲻�ö�����֣������ڽ�����ȴ����������");
		
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 12);
	set("con", 25);
	set("dex", 20);
	set("icon",begger);

	set("beggarlvl", 9);

	set("hp", 900);
	set("max_hp", 2700);
	set("mp", 1200);
	set("max_mp", 1200);
	set("mp_factor", 100);
	set("combat_exp", 200000);
	set("score", 40000);
	
	set_skill("force", 150);		// �����ڹ�
	set_skill("huntian_qigong", 150);	// ��������
	set_skill("unarmed", 170);		// ����ȭ��
	set_skill("xianglong_zhang", 180);	// ����ʮ����
	set_skill("dodge", 90);			// ��������
	set_skill("xiaoyaoyou", 90);		// ��ң��
	set_skill("parry", 120);		// �����м�
	set_skill("staff", 160);		// ��������
	set_skill("dagou_bang", 160); 
	set_skill("begging", 100);
	
	map_skill("force", "huntian_qigong");
	map_skill("unarmed", "xianglong_zhang");
	map_skill("parry", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	
	create_family("ؤ��", 18, "�Ŵ�����");

	set("chat_chance_combat", 20);
	set("no_huan",1);
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
	if ( me->query_int() >= 25 ) 
	{
		say("����ؤ�������һ���Ը���Ϊ������ϻ۹��ˣ��ƺ�����ѧؤ��Ĺ���", me);
		SendMenu(me);
		return;
	}
	else
		accept_student(me);
}

NPC_END;
