// pub_linlin.h ����
// jaja 2002-10-20

NPC_BEGIN(CNpub_linlin);

virtual void create()
{
	set_name("����", "lin lin");
	set("title", "ԧ��˫��");
	set("gender", "Ů��");
	set("age", 30);
	set("level", 100);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",8);				//������������
	set("repute", 4000);
	
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 30);			//����NPC��������
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 250);			// �����ڹ�
	set_skill("zixia_shengong", 250);		// ��ϼ��
	set_skill("strike", 250);			// �����Ʒ�
	set_skill("hunyuan_zhang", 250);		// ��Ԫ��
	set_skill("dodge", 250);			// ��������
	set_skill("huashan_shenfa", 250);		// ��ɽ��
	set_skill("parry", 250);			// �����м�
	set_skill("sword", 250);		        // ��������
	set_skill("yunv_swords", 250);		// ��Ů����ʮ����
	set_skill("fanliangyi_dao", 250);		// �����ǵ���

	map_skill("force", "zixia_shengong");		//����NPC��ǰ�ڹ�Ϊ��ϼ��
	map_skill("sword", "yunv_swords");	        //����NPC�Ļ�������װ����Ů����ʮ����
	map_skill("dodge", "huashan_shenfa");		//����NPC�Ļ����Ṧװ����ɽ��
	map_skill("parry", "fanliangyi_dao");		//����NPC�Ļ����м�װ�������ǵ���
	map_skill("strike", "hunyuan_zhang");		//����NPC�Ļ����Ʒ�װ����Ԫ��

	prepare_skill("strike", "hunyuan_zhang");	//����NPC�Ŀ�����ȫ

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 30);			//����NPC���ӹ�����

	carry_object("changjian")->wield();	
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("sword wushuang", 1);	//��Ů����ʮ����(wushuang��˫�޶�)
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
