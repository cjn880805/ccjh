// pub_xuemingfeng.h Ѧڤ��
// dieer 2002-8-26

NPC_BEGIN(CNpub_xuemingfeng);

virtual void create()
{
	set_name("Ѧڤ��", "xue mingfeng");
	set("title", "Į����ɷ֮���ɷ");
	set("gender", "����");
	set("age", 50);
	set("level", 80);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",20);				//������������
	
	set("str", 20);
	set("int", 22);
	set("con", 23);
	set("dex", 21);
	set("repute", -5000);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 30);			//����NPC��������
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 250);			// �����ڹ�
	set_skill("bibo_shengong", 250);		// �̲���
	set_skill("leg", 250);				// �����ȷ�
	set_skill("xuanfeng_leg", 250);			// ����ɨҶ��
	set_skill("dodge", 250);			// ��������
	set_skill("anying_fuxiang", 250);		// ��Ӱ����
	set_skill("parry", 250);			// �����м�

	map_skill("force", "bibo_shengong");		//����NPC��ǰ�ڹ�Ϊ�̲���
	map_skill("dodge", "anying_fuxiang");		//����NPC�Ļ�������װ����Ӱ����
	map_skill("parry", "xuanfeng_leg");		//����NPC�Ļ����м�װ������ɨҶ��
	map_skill("lge", "xuanfeng_leg");		//����NPC�Ļ����ȷ�װ������ɨҶ��

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 60);			//����NPC���ӹ�����

	prepare_skill("lge", "xuanfeng_leg");		//����NPC�Ŀ������
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("leg kuangfeng", 1);	//����ɨҶ��(kuangfeng������)
		break;
	case 1:
		perform_action("force powerup", 0);	//�Զ�����
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
