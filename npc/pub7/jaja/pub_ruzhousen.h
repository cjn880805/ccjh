// pub_ruzhousen.h ����ɮ
// dieer 2002-7-27

NPC_BEGIN(CNpub_ruzhousen);

virtual void create()
{
	set_name("����ɮ", "ruzhou sen");
	set("title", "��ʮ������֮");
	set("gender", "����");
	set("age", 30);
	set("level", 157);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",27);				//������������
	set("per",20);	
	set("repute", 10000);			//����NPC�û�
	
	set("str", 34);
	set("int", 37);
	set("con", 34);
	set("dex", 36);
	
	set("chat_chance_combat", 10);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("mp_factor", 70);			//����NPC��������
	
	set("combat_exp", 40000000+random(20000000));
	set("score", 6000);
	
	set_skill("force", 350);			// �����ڹ�
	set_skill("hunyuan_yiqi", 350);			// ��Ԫһ����
	set_skill("claw", 350);				// ����צ��
	set_skill("longzhua_gong", 350);		// ��צ��
	set_skill("dodge", 350);			// ��������
	set_skill("shaolin_shenfa", 350);		// ������
	set_skill("parry", 350);			// �����м�
	set_skill("cuff", 350);				// ����ȭ��
	set_skill("jingang_quan", 350);			// ����ȭ

	map_skill("force", "hunyuan_yiqi");		//����NPC��ǰ�ڹ�Ϊ��Ԫһ����
	map_skill("cuff", "jingang_quan");	        //����NPC�Ļ���ȭ��װ������ȭ
	map_skill("dodge", "shaolin_shenfa");		//����NPC�Ļ�������װ��������
	map_skill("parry", "jingang_quan");		//����NPC�Ļ����м�װ������ȭ
	map_skill("claw", "longzhua_gong");		//����NPC�Ļ���צ��װ����צ��

	set("apply/armor", 160);			//����NPC���ӷ�����
	set("apply/damage", 80);			//����NPC���ӹ�����

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
