// pub_dinping.h ��ƽ
//jaja 2002-10-20

NPC_BEGIN(CNpub_dinping);

virtual void create()
{
	set_name("��ƽ", "din ping");
	set("title", "������");
	set("gender", "����");
	set("age", 35);
	set("level", 100);
	set("long", 
		"��������Ͼ����ű�ͷԶ�����������������Ŀȫ����ס��������һ��������ȳ����Ŷ������������Ǹ��ܴ�����ݡ�\n");
	
	set("attitude", "peaceful");		//����NPC̬��
	set("icon",32);				//������������
	set("repute", -5000);
	
	set("str", 20);
	set("int", 24);
	set("con", 21);
	set("dex", 26);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 20);			//����NPC��������
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 250);			// �����ڹ�
	set_skill("hamagong", 250);			// ��󡹦
	set_skill("hand", 250);			// �����ַ�
	set_skill("shexing_diaoshou", 250);			// ���ε���
	set_skill("dodge", 250);			// ��������
	set_skill("chanchu_bufa", 250);			// ��ܲ���
	set_skill("parry", 250);			// �����м�
	set_skill("staff", 250);		        // �����ȷ�
	set_skill("lingshe_zhangfa", 250);		// �����ȷ�
	set_skill("quanzhen_jian", 250);		// ȫ�潣��

	map_skill("force", "hamagong");			//����NPC��ǰ�ڹ�Ϊ��󡹦
	map_skill("staff", "lingshe_zhangfa");	        //����NPC�Ļ����ȷ�װ�������ȷ�
	map_skill("dodge", "chanchu_bufa");		//����NPC�Ļ����Ṧװ����ܲ���
	map_skill("parry", "lingshe_zhangfa");		//����NPC�Ļ����м�װ�������ȷ�
	map_skill("hand", "shexing_diaoshou");		//����NPC�Ļ����ַ�װ�����ε���


	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 20);			//����NPC���ӹ�����

	carry_object("gangzhang")->wield();	
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("staff pili", 1);	//�����ȷ�(��������)
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
