// pub_chenmin.h ����
// jaja 2002-10-20

NPC_BEGIN(CNpub_chenmin);

virtual void create()
{
	set_name("����", "chen min");
	set("title", "��Բ������");
	set("gender", "����");
	set("age", 60);
	set("level", 100);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",27);				//������������
	set("repute", -6000);
	
	set("str", 20);
	set("int", 24);
	set("con", 21);
	set("dex", 26);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 30);			//����NPC��������
	
	set("combat_exp", 2000000+random(300000));
	set("score", 6000);
	
	set_skill("force", 270);			// �����ڹ�
	set_skill("hunyuan_yiqi", 270);			// ��Ԫһ����
	set_skill("claw", 270);				// ����צ��
	set_skill("longzhua_gong", 270);		// ��צ��
	set_skill("dodge", 270);			// ��������
	set_skill("shaolin_shenfa", 270);		// ������
	set_skill("parry", 270);			// �����м�
	set_skill("cuff", 270);				// ����ȭ��
	set_skill("jingang_quan", 270);			// ����ȭ

	map_skill("force", "hunyuan_yiqi");		//����NPC��ǰ�ڹ�Ϊ��Ԫһ����
	map_skill("cuff", "jingang_quan");	        //����NPC�Ļ���ȭ��װ������ȭ
	map_skill("dodge", "shaolin_shenfa");		//����NPC�Ļ�������װ��������
	map_skill("parry", "jingang_quan");		//����NPC�Ļ����м�װ������ȭ
	map_skill("claw", "longzhua_gong");		//����NPC�Ļ���צ��װ����צ��

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 45);			//����NPC���ӹ�����

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
