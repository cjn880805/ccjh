// pub_ruhua.h �绨
// jaja 2002-10-20

NPC_BEGIN(CNpub_ruhua);

virtual void create()
{
	set_name("�绨", "ru hua");
	set("title", "���Ʊߵ�����");
	set("gender", "����");
	set("age", 30);
	set("level", 100);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",44);				//������������
	
	set("str", 23);
	set("int", 21);
	set("con", 21);
	set("dex", 22);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 30);			//����NPC��������
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 250);			// �����ڹ�
	set_skill("xuantian_shengong", 250);		// ������
	set_skill("finger", 250);			// ����ָ��
	set_skill("xuantian_zhi", 250);			// ��������ָ
	set_skill("dodge", 250);			// ��������
	set_skill("qingfu_shenfa", 250);		// ������
	set_skill("parry", 250);			// �����м�
	set_skill("blade", 250);		        // ��������
	set_skill("wuyue_blade", 250);			// ���µ���

	map_skill("force", "xuantian_shengong");	//����NPC��ǰ�ڹ�Ϊ������
	map_skill("blade", "wuyue_blade");	        //����NPC�Ļ�������װ�����µ���
	map_skill("dodge", "qingfu_shenfa");		//����NPC�Ļ�������װ��������
	map_skill("parry", "wuyue_blade");		//����NPC�Ļ����м�װ�����µ���
	map_skill("finger", "xuantian_zhi");		//����NPC�Ļ���ָ��װ����������ָ

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 30);			//����NPC���ӹ�����

	carry_object("gangdao")->wield();

	prepare_skill("finger", "xuantian_zhi");
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("blade jiao", 1);	//���µ���(jiao���־�)
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