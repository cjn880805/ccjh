// pub_changhentian.h ������
// jaja 2002-10-20

NPC_BEGIN(CNpub_changhentian);

virtual void create()
{
	set_name("������", "chang hentian");
	set("title", "�������");
	set("gender", "����");
	set("age", 40);
	set("level", 100);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",14);				//������������
	set("repute", 5000);			
	
	set("str", 22);
	set("int", 24);
	set("con", 23);
	set("dex", 20);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 30);			//����NPC��������
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 250);			// �����ڹ�
	set_skill("huagong_dafa", 250);			// ������
	set_skill("strike", 250);			// �����Ʒ�
	set_skill("chousui_zhang", 250);		// ������
	set_skill("dodge", 250);			// ��������
	set_skill("zhaixinggong", 250);			// ժ�ǹ�
	set_skill("parry", 250);			// �����м�
	set_skill("staff", 250);		        // �����ȷ�
	set_skill("tianshan_zhang", 250);		// ��ɽ�ȷ�
	set_skill("fanliangyi_dao", 250);		// �����ǵ���

	map_skill("force", "huagong_dafa");		//����NPC��ǰ�ڹ�Ϊ������
	map_skill("staff", "tianshan_zhang");	        //����NPC�Ļ����ȷ�װ����ɽ�ȷ�
	map_skill("dodge", "zhaixinggong");		//����NPC�Ļ����Ṧװ��ժ�ǹ�
	map_skill("parry", "tianshan_zhang");		//����NPC�Ļ����м�װ����ɽ�ȷ�
	map_skill("strike", "chousui_zhang");		//����NPC�Ļ����Ʒ�װ��������

	prepare_skill("strike", "chousui_duzhang");	//����NPC�Ŀ�����ȫ

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 30);			//����NPC���ӹ�����

	carry_object("gangzhang")->wield();	
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("strike throw", 1);	//������(throwʩ����)
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