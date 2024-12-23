// lev1_xixuxi.h ϣ����
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_xixuxi);

virtual void create()
{
	set_name("ϣ����", "xi xusi");
	set("title", "����������");
	set("gender", "����");
	set("age", 60);
	set("level", 100);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",42);				//������������
	set("repute", -4000);
	
	set("str", 23);
	set("int", 23);
	set("con", 20);
	set("dex", 21);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 1);			//����NPC��������
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 190+random(30));			// �����ڹ�
	set_skill("yunlong_shengong", 190+random(30));		// ������
	set_skill("claw", 190+random(30));			// ����צ��
	set_skill("yunlong_zhua", 190+random(30));		// ����צ
	set_skill("dodge", 190+random(30));			// ��������
	set_skill("yunlong_shenfa", 190+random(30));		// ������
	set_skill("parry", 190+random(30));			// �����м�
	set_skill("sword", 190+random(30));		        // ��������
	set_skill("yunlong_jian", 190+random(30));		// ��������

	map_skill("force", "yunlong_shengong");		//����NPC��ǰ�ڹ�Ϊ������
	map_skill("sword", "yunlong_jian");	        //����NPC�Ļ�������װ����������
	map_skill("dodge", "yunlong_shenfa");		//����NPC�Ļ����Ṧװ��������
	map_skill("parry", "yunlong_jian");		//����NPC�Ļ����м�װ������������
	map_skill("claw", "yunlong_zhua");		//����NPC�Ļ���צ��װ������צ

	prepare_skill("claw", "yunlong_zhua");	//����NPC�Ŀ�����ȫ

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 10);			//����NPC���ӹ�����

	carry_object("changjian")->wield();	
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("sword xian", 1);	//������(xian��������)
		break;
	case 1:
			//�Զ�����
		break;
	case 2:
			//�Զ�����
		break;
	case 3:
			//�Զ�����
		break;
	case 4:
			//�Զ�����
		break;
	case 5:
			//�Զ�����
		break;
	}	
	return 0;
}

LEV1_END;
