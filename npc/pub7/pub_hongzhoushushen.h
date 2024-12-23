// pub_hongzhoushushen.h ��������
// dieer 2002-8-10

NPC_BEGIN(CNpub_hongzhoushushen);

virtual void create()
{
	set_name("��������", "hongzhou shushen");
	set("title", "��ʮ������֮");
	set("gender", "����");
	set("age", 20);
	set("level", 157);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",15);				//������������
	set("per",20);
	
	set("str", 32);
	set("int", 32);
	set("con", 33);
	set("dex", 35);
	set("repute", 10000);
	
	set("chat_chance_combat", 10);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("mp_factor", 50);			//����NPC��������
	
	set("combat_exp", 40000000+random(20000000));
	set("score", 6000);

	set_skill("force", 350);			// �����ڹ�
	set_skill("shenghuo_shengong", 350);		// ʥ����
	set_skill("shenghuo_xinfa", 350);		// ʥ���ķ�
	set_skill("finger", 350);			// ����ָ��
	set_skill("xuantian_zhi", 350);			// ��������ָ
	set_skill("dodge", 350);			// ��������
	set_skill("qingfu_shenfa", 350);		// ������
	set_skill("parry", 350);			// �����м�
	set_skill("lingfa", 350);		        // �����
	set_skill("shenghuo_lingfa", 350);		// ʥ���

	map_skill("force", "shenghuo_shengong");	//����NPC��ǰ�ڹ�Ϊʥ����
	map_skill("lingfa", "Shenghuo_lingfa");	        //����NPC�Ļ����װ��ʥ���
	map_skill("dodge", "qingfu_shenfa");		//����NPC�Ļ�������װ��������
	map_skill("parry", "Shenghuo_lingfa");		//����NPC�Ļ����м�װ��ʥ���
	map_skill("finger", "xuantian_zhi");		//����NPC�Ļ���ָ��װ����������ָ

	set("apply/armor", 160);			//����NPC���ӷ�����
	set("apply/damage", 50);			//����NPC���ӹ�����
	
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