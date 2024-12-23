// pub_nieyinnang.h ������
// dieer 2002-7-27

NPC_BEGIN(CNpub_nieyinnang);

virtual void create()
{
	set_name("������", "nie yinnang");
	set("title", "��ʮ������֮");
	set("gender", "Ů��");
	set("age", 20);
	set("level", 157);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",2);				//������������
	set("per",26);
	set("repute", 10000);	
	
	set("str", 35);
	set("int", 34);
	set("con", 31);
	set("dex", 32);
	
	set("chat_chance_combat", 10);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("mp_factor", 70);			//����NPC��������
	
	set("combat_exp", 40000000+random(20000000));
	set("score", 6000);
	
	set_skill("force", 350);			// �����ڹ�
	set_skill("linji_zhuang", 350);			// �ټ�ʮ��ׯ
	set_skill("strike", 350);			// �����Ʒ�
	set_skill("jinding_zhang", 350);		// ������
	set_skill("dodge", 350);			// ��������
	set_skill("zhutian_bu", 350);			// ���컯��
	set_skill("parry", 350);			// �����м�
	set_skill("sword", 350);		        // ��������
	set_skill("huifeng_jian", 350);			// �ط������

	map_skill("force", "linji_zhuang");		//����NPC��ǰ�ڹ�Ϊ�ټ�ʮ��ׯ
	map_skill("sword", "huifeng_jian");	        //����NPC�Ļ�������װ���ط������
	map_skill("dodge", "zhutian_bu");		//����NPC�Ļ�������װ�����컯��
	map_skill("parry", "huifeng_jian");		//����NPC�Ļ����м�װ���ط������
	map_skill("strike", "jinding_zhang");		//����NPC�Ļ����Ʒ�װ��������

	set("apply/armor", 160);			//����NPC���ӷ�����
	set("apply/damage", 60);			//����NPC���ӹ�����

	prepare_skill("strike", "jinding_zhang");

	carry_object("changjian")->wield();	
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("sword mie", 1);		//�ط������������
		break;
	case 1:
		perform_action("strike bashi", 1);	//�����ƾ��а�ʽ��һ
		break;
	case 2:
		perform_action("force powerup", 0);	//�Զ�����
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
