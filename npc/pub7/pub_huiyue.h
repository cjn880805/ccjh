// pub_.h ����
//jaja 2002-10-20

NPC_BEGIN(CNpub_huiyue);

virtual void create()
{
	set_name("����", "yui yue");
	set("title", "ʥ��ʹ��");
	set("gender", "Ů��");
	set("age", 36);
	set("level", 100);

	set("attitude", "friendly");		//����NPC̬��
	set("icon",6);				//������������
	
	set("str", 27);
	set("int", 20);
	set("con", 20);
	set("dex", 21);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 30);			//����NPC��������
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 250);			// �����ڹ�
	set_skill("shenghuo_shengong", 250);		// ʥ����
	set_skill("shenghuo_xinfa", 250);		// ʥ���ķ�
	set_skill("finger", 250);			// ����ָ��
	set_skill("xuantian_zhi", 250);			// ��������ָ
	set_skill("dodge", 250);			// ��������
	set_skill("qingfu_shenfa", 250);		// ������
	set_skill("parry", 250);			// �����м�
	set_skill("lingfa", 250);		        // �����
	set_skill("shenghuo_lingfa", 250);		// ʥ���

	map_skill("force", "shenghuo_shengong");	//����NPC��ǰ�ڹ�Ϊʥ����
	map_skill("lingfa", "shenghuo_lingfa");	        //����NPC�Ļ����װ��ʥ���
	map_skill("dodge", "qingfu_shenfa");		//����NPC�Ļ�������װ��������
	map_skill("parry", "shenghuo_lingfa");		//����NPC�Ļ����м�װ��ʥ���
	map_skill("finger", "xuantian_zhi");		//����NPC�Ļ���ָ��װ����������ָ

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 30);			//����NPC���ӹ�����
	
	prepare_skill("finger", "xuantian_zhi");

	carry_object("shenghuo_ling")->wield();
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("lingfa xiyanling", 1);	//ʥ���(xiyanling�����桹��)
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