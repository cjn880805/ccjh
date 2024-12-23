// pub_fengwanzhan.h ����յ
// jaja 2002-10-20

NPC_BEGIN(CNpub_fengwanzhan);

virtual void create()
{
	set_name("����յ", "feng wanzhan");
	set("title", "һ���͵�");
	set("gender", "����");
	set("age", 60);
	set("level", 100);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",19);				//������������
	set("repute", 3000);
	
	set("str", 25);
	set("int", 21);
	set("con", 20);
	set("dex", 20);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 30);			//����NPC��������
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force",250);			// �����ڹ�
	set_skill("yunlong_shengong",250);		// ������
	set_skill("claw",250);			// ����צ��
	set_skill("yunlong_zhua",250);		// ����צ
	set_skill("dodge",250);			// ��������
	set_skill("yunlong_shenfa",250);		// ������
	set_skill("parry",250);			// �����м�
	set_skill("sword",250);		        // ��������
	set_skill("yunlong_jian",250);		// ��������

	map_skill("force", "yunlong_shengong");		//����NPC��ǰ�ڹ�Ϊ������
	map_skill("sword", "yunlong_jian");	        //����NPC�Ļ�������װ����������
	map_skill("dodge", "yunlong_shenfa");		//����NPC�Ļ����Ṧװ��������
	map_skill("parry", "yunlong_jian");		//����NPC�Ļ����м�װ������������
	map_skill("claw", "yunlong_zhua");		//����NPC�Ļ���צ��װ������צ

	prepare_skill("claw", "yunlong_zhua");	//����NPC�Ŀ�����ȫ

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 30);			//����NPC���ӹ�����

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
		perform_action("force recover", 0);	//�Զ�����
		break;
	case 2:
		perform_action("force recover", 0);	//�Զ�����
		break;
	case 3:
		perform_action("force recover", 0);	//�Զ�����
		break;
	case 4:
		perform_action("force recover", 0);	//�Զ�����
		break;
	case 5:
		perform_action("force recover", 0);	//�Զ�����
		break;
	}	
	return 0;
}

NPC_END;
