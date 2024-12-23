// pub_yuzhuzi.h ������
//jaja 2002-10-20

NPC_BEGIN(CNpub_yuzhuzi);

virtual void create()
{
	set_name("������", "yu zhuzi");
	set("title", "��������");
	set("gender", "����");
	set("age", 50);
	set("level", 100);
	set("attitude", "peaceful");		//����NPC̬��
	set("icon",13);				//������������
	set("repute", -5000);
	
	set("str", 21);
	set("int", 23);
	set("con", 23);
	set("dex", 21);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 30);			//����NPC��������
	
	set("combat_exp", 1900000+random(300000));
	set("score", 6000);
	
	set_skill("force", 260);			// �����ڹ�
	set_skill("taiji_shengong", 260);		// ̫����
	set_skill("unarmed", 260);			// ����ȭ��
	set_skill("taiji_quan", 260);			// ̫��ȭ
	set_skill("dodge", 260);			// ��������
	set_skill("tiyunzong", 260);			// ������
	set_skill("parry", 260);			// �����м�
	set_skill("sword", 260);			// ��������
	set_skill("taiji_jian", 260);			// ̫����

	map_skill("force", "taiji_shengong");		//����NPC��ǰ�ڹ�Ϊ̫����
	map_skill("unarmed", "taiji_quan");	        //����NPC�Ļ���ȭ��װ��̫��ȭ
	map_skill("dodge", "tiyunzong");		//����NPC�Ļ�������װ��������
	map_skill("parry", "jingang_quan");		//����NPC�Ļ����м�װ������ȭ
	map_skill("sword", "taiji_jian");		//����NPC�Ļ�������װ��̫����

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 40);			//����NPC���ӹ�����

	carry_object("changjian")->wield();	

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

