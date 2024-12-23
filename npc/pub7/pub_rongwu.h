// pub_rongwu.h ����
// jaja 2002-10-20

NPC_BEGIN(CNpub_rongwu);

virtual void create()
{
	set_name("����", "rong wu");
	set("title", "�ķ��޵�");
	set("gender", "����");
	set("age", 40);
	set("level", 100);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",18);				//������������
	
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
	
	set_skill("force", 250);			// �����ڹ�
	set_skill("hunyuan_yiqi", 250);			// ��Ԫһ����
	set_skill("claw", 250);				// ����צ��
	set_skill("longzhua_gong", 250);		// ��צ��
	set_skill("dodge", 250);			// ��������
	set_skill("shaolin_shenfa", 250);		// ��������
	set_skill("parry", 250);			// �����м�
	set_skill("cuff", 250);				// ����ȭ��
	set_skill("jingang_quan", 250);			// ����ȭ

	map_skill("force", "hunyuan_yiqi");		//����NPC��ǰ�ڹ�Ϊ��Ԫһ����
	map_skill("cuff", "jingang_quan");	        //����NPC�Ļ���ȭ��װ������ȭ
	map_skill("dodge", "shaolin_shenfa");		//����NPC�Ļ�������װ����������
	map_skill("parry", "jingang_quan");		//����NPC�Ļ����м�װ������ȭ
	map_skill("claw", "longzhua_gong");		//����NPC�Ļ���צ��װ����צ��

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 20);			//����NPC���ӹ�����

	prepare_skill("claw", "longzhua_gong");		//����NPC����Ϲ���
	prepare_skill("cuff", "jingang_quan");

}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("cuff jingang", 1);	//����ȭ(jingang������ͨ)
		break;
	case 1:
		perform_action("force recover", 0);	//�Զ�����
		break;
	case 2:
		perform_action("force roar", 1);	//��Ԫһ��������ʨ�Ӻ�
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
