// lev2_yuzhuzi.h ������
// jaja 2002-12-23

LEV2_BEGIN(CNlev2_yuzhuzi);

virtual void create()
{
	set_name("������", "yu zhuzi");
	set("title", "��������");
	set("gender", "����");
	set("age", 50);
	set("level", 100);
	set("attitude", "peaceful");		//����NPC̬��
	set("icon",13);				//������������
	set("repute", -8000);
	
	set("str", 27);
	set("int", 26);
	set("con", 29);
	set("dex", 29);
	
	set("chat_chance_combat", 10);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 12000+random(3000));
	set("max_mp", 7000);
	set("mp_factor", 1);			//����NPC��������
	
	set("combat_exp", 6000000+random(6000000));
	set("score", 6000);
	
	set_skill("force", 230+random(30));			// �����ڹ�
	set_skill("taiji_shengong", 230+random(30));		// ̫����
	set_skill("unarmed", 230+random(30));			// ����ȭ��
	set_skill("taiji_quan", 230+random(30));			// ̫��ȭ
	set_skill("dodge", 230+random(30));			// ��������
	set_skill("tiyunzong", 230+random(30));			// ������
	set_skill("parry", 230+random(30));			// �����м�
	set_skill("sword", 230+random(30));			// ��������
	set_skill("taiji_jian", 230+random(30));			// ̫����

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

LEV2_END;

