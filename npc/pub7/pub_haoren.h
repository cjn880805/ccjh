// pub_haoren.h ����
//jaja 2002-10-20

NPC_BEGIN(CNpub_haoren);

virtual void create()
{
	set_name("����", "hao ren");
	set("title", "���ַ���");
	set("gender", "����");
	set("age", 71);
	set("level", 100);
	set("long", 
		"������������Ȼ���ݣ��ֽ�ȴ�ر�ִ󣬿����ӹ��������زصġ�\n");
	set("attitude", "peaceful");		//����NPC̬��
	set("icon",16);				//������������
	set("repute", -5000);
	
	set("str", 24);
	set("int", 20);
	set("con", 23);
	set("dex", 20);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 30);			//����NPC��������
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 250);			// �����ڹ�
	set_skill("huntian_qigong", 250);		// ��������
	set_skill("strike", 250);			// �����Ʒ�
	set_skill("xianglong_zhang", 250);		// ����ʮ����
	set_skill("dodge", 250);			// ��������
	set_skill("xiaoyaoyou", 250);			// ��ң��
	set_skill("parry", 250);			// �����м�
	set_skill("claw", 250);		      		// ����צ��
	set_skill("jiuyin_zhua", 250);			// �����׹�צ

	map_skill("force", "huntian_qigong");		//����NPC��ǰ�ڹ�Ϊ��������
	map_skill("claw", "jiuyin_zhua");	        //����NPC�Ļ���צ��װ�������׹�צ
	map_skill("dodge", "xiaoyaoyou");		//����NPC�Ļ�������װ����ң��
	map_skill("parry", "jiuyin_zhua");		//����NPC�Ļ����м�װ�������׹�צ
	map_skill("strike", "xianglong_zhang");		//����NPC�Ļ����Ʒ�װ������ʮ����

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 30);			//����NPC���ӹ�����

	prepare_skill("claw", "jiuyin_zhua");		//����NPC�Ŀ������
	prepare_skill("strike", "xianglong_zhang");
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("claw zhua", 1);		//�����׹�צ��������һ��
		break;
	case 1:
		perform_action("strike leiting", 1);	//����ʮ���ƾ�������һ��
		break;
	case 2:
		perform_action("strike xianglong", 1);	//����ʮ���ƾ��н�����
		break;
	case 3:
		perform_action("force shengang", 0);	//�Զ����
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