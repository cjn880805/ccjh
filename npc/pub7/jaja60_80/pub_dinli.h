// lev1_dinli.h ����
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_dinli);

virtual void create()
{
	set_name("����", "din li");
	set("title", "������");
	set("gender", "����");
	set("age", 35);
	set("level", 100);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",40);				//������������
	set("repute", 6000);
	
	set("str", 20);
	set("int", 24);
	set("con", 21);
	set("dex", 26);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 1);			//����NPC��������
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 190+random(30));			// �����ڹ�
	set_skill("huntian_qigong", 190+random(30));		// ��������
	set_skill("strike", 190+random(30));			// �����Ʒ�
	set_skill("xianglong_zhang", 190+random(30));		// ����ʮ����
	set_skill("dodge", 190+random(30));			// ��������
	set_skill("xiaoyaoyou", 190+random(30));			// ��ң��
	set_skill("parry", 190+random(30));			// �����м�
	set_skill("claw", 190+random(30));		      		// ����צ��
	set_skill("jiuyin_zhua", 190+random(30));			// �����׹�צ

	map_skill("force", "huntian_qigong");		//����NPC��ǰ�ڹ�Ϊ��������
	map_skill("claw", "jiuyin_zhua");	        //����NPC�Ļ���צ��װ�������׹�צ
	map_skill("dodge", "xiaoyaoyou");		//����NPC�Ļ�������װ����ң��
	map_skill("parry", "jiuyin_zhua");		//����NPC�Ļ����м�װ�������׹�צ
	map_skill("strike", "xianglong_zhang");		//����NPC�Ļ����Ʒ�װ������ʮ����

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 50);			//����NPC���ӹ�����

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
			//�Զ�����
		break;
	case 5:
			//�Զ�����
		break;
	}	
	return 0;
}

LEV1_END;
