// pub_wangjinhongpu.h ��������
// dieer 2002-7-27

NPC_BEGIN(CNpub_wangjinhongpu);

virtual void create()
{
	set_name("��������", "wangjin hongpu");
	set("title", "��ʮ������֮");
	set("gender", "����");
	set("age", 10);
	set("level", 157);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",22);				//������������
	set("per",20);
//	set("shen_type", 1);
	
	set("str", 46);
	set("int", 47);
	set("con", 45);
	set("dex", 44);
	
	set("chat_chance_combat", 10);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("mp_factor", 70);			//����NPC��������
	
	set("combat_exp", 40000000+random(20000000));
	set("score", 6000);
	
	set_skill("force", 350);			// �����ڹ�
	set_skill("taiji_shengong", 350);		// ̫����
	set_skill("unarmed", 350);			// ����ȭ��
	set_skill("changquan", 350);			// ��ȭ
	set_skill("dodge", 350);			// ��������
	set_skill("tiyunzong", 350);			// ������
	set_skill("parry", 350);			// �����м�
	set_skill("hand", 350);				// �����ַ�
	set_skill("tangshoudao", 350);			// ���ֵ�

	map_skill("force", "taiji_shengong");		//����NPC��ǰ�ڹ�Ϊ̫����
	map_skill("unarmed", "changquan");	        //����NPC�Ļ���ȭ��װ����ȭ
	map_skill("dodge", "tiyunzong");		//����NPC�Ļ�������װ��������
	map_skill("parry", "tangshoudao");		//����NPC�Ļ����м�װ�����ֵ�
	map_skill("hand", "tangshoudao");		//����NPC�Ļ����ַ�װ�����ֵ�

	set("apply/armor", 160);			//����NPC���ӷ�����
	set("apply/damage", 70);			//����NPC���ӹ�����

	prepare_skill("hand", "tangshoudao");		//����NPC�Ŀ������
	prepare_skill("unarmed", "changquan");
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("force powerup", 1);	//̫���񹦼���
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
