// pub_lushen.h ¬��
// dieer 2002-7-29

NPC_BEGIN(CNpub_lushen);

virtual void create()
{
	set_name("¬��", "lu shen");
	set("title", "��ʮ������֮");
	set("gender", "����");
	set("age", 20);
	set("level", 157);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",14);				//������������
	set("per",22);	
//	set("shen_type", 1);			//����NPC�û�
	
	set("str", 40);
	set("int", 42);
	set("con", 45);
	set("dex", 41);
	
	set("chat_chance_combat", 10);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("mp_factor", 80);			//����NPC��������
	
	set("combat_exp", 40000000+random(20000000));
	set("score", 6000);
	
	set_skill("force", 350);			// �����ڹ�
	set_skill("taiji_shengong", 350);		// ̫����
	set_skill("unarmed", 350);			// ����ȭ��
	set_skill("taiji_quan", 350);			// ̫��ȭ
	set_skill("dodge", 350);			// ��������
	set_skill("tiyunzong", 350);			// ������
	set_skill("parry", 350);			// �����м�
	set_skill("sword", 350);			// ��������
	set_skill("taiji_jian", 350);			// ̫����

	map_skill("force", "taiji_shengong");		//����NPC��ǰ�ڹ�Ϊ̫����
	map_skill("unarmed", "taiji_quan");	        //����NPC�Ļ���ȭ��װ��̫��ȭ
	map_skill("dodge", "tiyunzong");		//����NPC�Ļ�������װ��������
	map_skill("parry", "jingang_quan");		//����NPC�Ļ����м�װ������ȭ
	map_skill("sword", "taiji_jian");		//����NPC�Ļ�������װ��̫����

	set("apply/armor", 160);			//����NPC���ӷ�����
	set("apply/damage", 90);			//����NPC���ӹ�����

	carry_object("changjian")->wield();
	carry_object("putongbishou")->wield();


}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("sword chan", 1);	//̫���� chan
		break;
	case 1:
		perform_action("sword lian", 1);	//̫���� lian
		break;
	case 2:
		perform_action("sword sui", 1);		//̫���� sui
		break;
	case 3:
		perform_action("unarmed zhenup", 1);	//̫��ȭ�����
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
