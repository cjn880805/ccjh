// lev1_yutianxiang.h ������
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_yutianxiang);

virtual void create()
{
	set_name("������", "yu tianxiang");
	set("title", "���굺��");
	set("gender", "����");
	set("age", 50);
	set("level", 100);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",14);				//������������
	set("repute", -4000);
	
	set("str", 21);
	set("int", 23);
	set("con", 23);
	set("dex", 21);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 1);			//����NPC��������
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 190+random(30));			// �����ڹ�
	set_skill("taiji_shengong", 190+random(30));		// ̫����
	set_skill("unarmed", 190+random(30));			// ����ȭ��
	set_skill("taiji_quan", 190+random(30));			// ̫��ȭ
	set_skill("dodge", 190+random(30));			// ��������
	set_skill("tiyunzong", 190+random(30));			// ������
	set_skill("parry", 190+random(30));			// �����м�

	map_skill("force", "taiji_shengong");		//����NPC��ǰ�ڹ�Ϊ̫����
	map_skill("unarmed", "taiji_quan");	        //����NPC�Ļ���ȭ��װ��̫��ȭ
	map_skill("dodge", "tiyunzong");		//����NPC�Ļ�������װ��������
	map_skill("parry", "jingang_quan");		//����NPC�Ļ����м�װ������ȭ

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 10);			//����NPC���ӹ�����
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("unarmed zhenup", 1);	//̫��ȭ�����
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