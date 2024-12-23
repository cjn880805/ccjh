// lev1_puchen.h �ճ�ʦ̫
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_puchen);

virtual void create()
{
	set_name("�ճ�ʦ̫", "pu chen");
	set("title", "�Ϻ�����");
	set("gender", "Ů��");
	set("age", 90);
	set("level", 100);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",21);				//������������
	set("repute", 6000);
	
	set("str", 23);
	set("int", 21);
	set("con", 21);
	set("dex", 22);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 1);			//����NPC��������
	
	set("combat_exp", 2200000+random(300000));
	set("score", 6000);
	
	set_skill("force", 210+random(30));			// �����ڹ�
	set_skill("linji_zhuang", 210+random(30));			// �ټ�ʮ��ׯ
	set_skill("strike", 210+random(30));			// �����Ʒ�
	set_skill("jinding_zhang", 210+random(30));		// ������
	set_skill("dodge", 210+random(30));			// ��������
	set_skill("zhutian_bu", 210+random(30));			// ���컯��
	set_skill("parry", 210+random(30));			// �����м�
	set_skill("sword", 210+random(30));		        // ��������
	set_skill("huifeng_jian", 210+random(30));			// �ط������

	map_skill("force", "linji_zhuang");		//����NPC��ǰ�ڹ�Ϊ�ټ�ʮ��ׯ
	map_skill("sword", "huifeng_jian");	        //����NPC�Ļ�������װ���ط������
	map_skill("dodge", "zhutian_bu");		//����NPC�Ļ�������װ�����컯��
	map_skill("parry", "huifeng_jian");		//����NPC�Ļ����м�װ���ط������
	map_skill("strike", "jinding_zhang");		//����NPC�Ļ����Ʒ�װ��������

	set("apply/armor", 130);			//����NPC���ӷ�����
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
			//�Զ�����
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

