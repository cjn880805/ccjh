// lev1_situshashou.h ˾ͽ����
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_situshashou);

virtual void create()
{
	set_name("˾ͽ����", "situ shashou");
	set("title", "������̽�ܹ�");
	set("gender", "����");
	set("age", 70);
	set("level", 100);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",20);				//������������
	set("repute", -5000);
	
	set("str", 23);
	set("int", 21);
	set("con", 21);
	set("dex", 22);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 1);			//����NPC��������
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 190+random(30));			// �����ڹ�
	set_skill("taiji_shengong", 190+random(30));		// ̫����
	set_skill("unarmed", 190+random(30));			// ����ȭ��
	set_skill("changquan", 190+random(30));			// ��ȭ
	set_skill("dodge", 190+random(30));			// ��������
	set_skill("tiyunzong", 190+random(30));			// ������
	set_skill("parry", 190+random(30));			// �����м�
	set_skill("hand", 190+random(30));				// �����ַ�
	set_skill("tangshoudao", 190+random(30));			// ���ֵ�

	map_skill("force", "taiji_shengong");		//����NPC��ǰ�ڹ�Ϊ̫����
	map_skill("unarmed", "changquan");	        //����NPC�Ļ���ȭ��װ����ȭ
	map_skill("dodge", "tiyunzong");		//����NPC�Ļ�������װ��������
	map_skill("parry", "tangshoudao");		//����NPC�Ļ����м�װ�����ֵ�
	map_skill("hand", "tangshoudao");		//����NPC�Ļ����ַ�װ�����ֵ�

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 50);			//����NPC���ӹ�����

	prepare_skill("hand", "tangshoudao");		//����NPC�Ŀ������
	prepare_skill("unarmed", "changquan");
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("force powerup", 0);	//̫���񹦼���
		break;
	case 1:
			//�Զ�����
		break;
	case 2:
			//�Զ�����
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
