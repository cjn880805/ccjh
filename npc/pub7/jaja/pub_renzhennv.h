// pub_renzhennv.h ����Ů
// dieer 2002-8-5

NPC_BEGIN(CNpub_renzhennv);

virtual void create()
{
	set_name("����Ů", "renzhen nv");
	set("title", "��ʮ������֮");
	set("gender", "Ů��");
	set("age", 16);
	set("level", 157);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",3);				//������������
	set("per",28);
	set("repute", 10000);
	
	set("str", 40);
	set("int", 30);
	set("con", 30);
	set("dex", 40);
	
	set("chat_chance_combat", 10);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("mp_factor", 1);			//����NPC��������
	
	set("combat_exp", 40000000+random(20000000));
	set("score", 6000);
	
	set_skill("force", 350);			// �����ڹ�
	set_skill("beiming_shengong", 350);		// ��ڤ��
	set_skill("strike", 350);			// �����Ʒ�
	set_skill("liuyang_zhang", 350);		// ������
	set_skill("dodge", 350);			// ��������
	set_skill("lingboweibu", 350);			// �貨΢��
	set_skill("parry", 350);			// �����м�
	set_skill("hand", 350);			        // �����ַ�
	set_skill("zhemei_shou", 350);			// ��÷��

	map_skill("force", "beiming_shengong");		//����NPC��ǰ�ڹ�Ϊ��ڤ��
	map_skill("hand", "zhemei_shou");	        //����NPC�Ļ����ַ�װ����÷��
	map_skill("dodge", "lingboweibu");		//����NPC�Ļ�������װ���貨΢��
	map_skill("parry", "zhemei_shou");		//����NPC�Ļ����м�װ����÷��
	map_skill("strike", "liuyang_zhang");		//����NPC�Ļ����Ʒ�װ��������

	prepare_skill("hand", "zhemei_shou");		//����NPC�Ŀ������
	prepare_skill("strike", "liuyang_zhang");

	set("apply/armor", 160);			//����NPC���ӷ�����
	set("apply/damage", 80);			//����NPC���ӹ�����
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