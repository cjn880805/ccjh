// pub_linjinzhi.h �ֽ�֥
//jaja 2002-10-20

NPC_BEGIN(CNpub_linjinzhi);

virtual void create()
{
	set_name("�ֽ�֥", "lin jinzhi");
	set("title", "��������");
	set("gender", "Ů��");
	set("age", 30);
	set("level", 100);
	set("long", 
		"�����˼����Ϻܸ߹󣬲���̫�����·���ͷ�ϴ������Ȳ���࣬Ҳ��̫�١����˶����������ؾص�վ����������Ȳ����ۣ�Ҳ��������������λ���Ҵ�լ�е�ǧ��С��Ӧ���е�ģ����\n");
	set("attitude", "peaceful");		//����NPC̬��
	set("icon",3);				//������������
	set("repute", -5000);
	
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 1);			//����NPC��������
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 250);			// �����ڹ�
	set_skill("beiming_shengong", 250);		// ��ڤ��
	set_skill("strike", 250);			// �����Ʒ�
	set_skill("liuyang_zhang", 250);		// ������
	set_skill("dodge", 250);			// ��������
	set_skill("lingboweibu", 250);			// �貨΢��
	set_skill("parry", 250);			// �����м�
	set_skill("hand", 250);			        // �����ַ�
	set_skill("zhemei_shou", 250);			// ��÷��

	map_skill("force", "beiming_shengong");		//����NPC��ǰ�ڹ�Ϊ��ڤ��
	map_skill("hand", "zhemei_shou");	        //����NPC�Ļ����ַ�װ����÷��
	map_skill("dodge", "lingboweibu");		//����NPC�Ļ�������װ���貨΢��
	map_skill("parry", "zhemei_shou");		//����NPC�Ļ����м�װ����÷��
	map_skill("strike", "liuyang_zhang");		//����NPC�Ļ����Ʒ�װ��������

	prepare_skill("hand", "zhemei_shou");		//����NPC�Ŀ������
	prepare_skill("strike", "liuyang_zhang");

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 50);			//����NPC���ӹ�����
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("force neilisuck", 1);	//��ڤ��neilisuck������
		break;
	case 1:
		perform_action("hand duo", 1);		//��÷��(duo���������)
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