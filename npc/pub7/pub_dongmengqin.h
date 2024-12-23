// pub_dongmengqin.h ������
// jaja 2002-10-20

NPC_BEGIN(CNpub_dongmengqin);

virtual void create()
{
	set_name("������", "dong mengqin");
	set("title", "��Ժ�ϰ�");
	set("gender", "����");
	set("age", 40);
	set("level", 100);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",15);				//������������
	set("repute", -5000);
	
	set("str", 25);
	set("int", 21);
	set("con", 20);
	set("dex", 20);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 30);			//����NPC��������
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 250);			// �����ڹ�
	set_skill("taixuan_gong", 250);			// ���͵�̫����
	set_skill("strike", 250);			// �����Ʒ�
	set_skill("lovestrike", 250);			// Ϸ����
	set_skill("dodge", 250);			// ��������
	set_skill("shenxing_baibian", 250);		// ���аٱ�
	set_skill("parry", 250);			// �����м�
	set_skill("sword", 250);		        // ��������
	set_skill("songshan_sword", 250);		// ��ɽ����

	map_skill("force", "taixuan_gong");		//����NPC��ǰ�ڹ�Ϊ���͵�̫����
	map_skill("sword", "songshan_sword");	        //����NPC�Ļ�������װ����ɽ����
	map_skill("dodge", "shenxing_baibian");		//����NPC�Ļ����Ṧװ�����аٱ�
	map_skill("parry", "songshan_sword");		//����NPC�Ļ����м�װ����ɽ����
	map_skill("strike", "lovestrike");		//����NPC�Ļ����Ʒ�װ��Ϸ����

	prepare_skill("strike", "lovestrike");		//����NPC�Ŀ�����ȫ	

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 30);			//����NPC���ӹ�����

	carry_object("zheshan")->wield();	
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("force recover", 0);	//�Զ�����
		break;
	case 1:
		perform_action("force recover", 0);	//�Զ�����
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
