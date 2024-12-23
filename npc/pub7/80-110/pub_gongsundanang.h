// lev2_gongsundanang.h �������
// jaja 2002-12-16

LEV2_BEGIN(CNlev2_gongsundanang);

virtual void create()
{
	set_name("�������", "gongsun danang");
	set("title", "�轣����");
	set("gender", "Ů��");
	set("age", 20);
	set("level", 130);

	set("icon",2);				//������������
	set("per",36);
	
	set("str", 30);
	set("int", 28);
	set("con", 29);
	set("dex", 29);
	set("repute", 8000);
	
	set("chat_chance_combat", 10);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 15000+random(5000));
	set("max_mp", 8000);
	set("mp_factor", 50);			//����NPC��������
	
	set("combat_exp", 20000000+random(10000000));
	set("score", 6000);

	set_skill("force", 250+random(50));			// �����ڹ�
	set_skill("linji_zhuang", 250+random(50));			// �ټ�ʮ��ׯ
	set_skill("strike", 250+random(50));			// �����Ʒ�
	set_skill("jinding_zhang", 250+random(50));		// ������
	set_skill("dodge", 250+random(50));			// ��������
	set_skill("zhutian_bu", 250+random(50));			// ���컯��
	set_skill("parry", 250+random(50));			// �����м�
	set_skill("sword", 250+random(50));		        // ��������
	set_skill("huifeng_jian", 250+random(50));			// �ط������

	map_skill("force", "linji_zhuang");		//����NPC��ǰ�ڹ�Ϊ�ټ�ʮ��ׯ
	map_skill("sword", "huifeng_jian");	        //����NPC�Ļ�������װ���ط������
	map_skill("dodge", "zhutian_bu");		//����NPC�Ļ�������װ�����컯��
	map_skill("parry", "huifeng_jian");		//����NPC�Ļ����м�װ���ط������
	map_skill("strike", "jinding_zhang");		//����NPC�Ļ����Ʒ�װ��������

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 30);			//����NPC���ӹ�����

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

LEV2_END;