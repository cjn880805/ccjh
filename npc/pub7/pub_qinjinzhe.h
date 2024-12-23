// pub_qinjinzhe.h �����
// dieer 2002-8-10

NPC_BEGIN(CNpub_qinjinzhe);

virtual void create()
{
	set_name("�����", "qinjin zhe");
	set("title", "��ʮ������֮");
	set("gender", "����");
	set("age", 20);
	set("level", 157);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",16);				//������������
	set("per",18);
	
	set("str", 37);
	set("int", 33);
	set("con", 36);
	set("dex", 31);
	set("repute", 10000);
	
	set("chat_chance_combat", 10);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("mp_factor", 50);			//����NPC��������
	
	set("combat_exp", 40000000+random(20000000));
	set("score", 6000);

	set_skill("force", 350);			// �����ڹ�
	set_skill("hunyuan_yiqi", 350);			// ��Ԫһ����
	set_skill("finger", 350);			// ����ָ��
	set_skill("nianhua_zhi", 350);			// �黨ָ
	set_skill("dodge", 350);			// ��������
	set_skill("shaolin_shenfa", 350);		// ������
	set_skill("parry", 350);			// �����м�
	set_skill("blade", 350);		        // ��������
	set_skill("cibei_dao", 350);			// �ȱ���

	map_skill("force", "hunyuan_yiqi");		//����NPC��ǰ�ڹ�Ϊ��Ԫһ����
	map_skill("blade", "cibei_dao");	     	//����NPC�Ļ�������װ���ȱ���
	map_skill("dodge", "shaolin_shenfa");		//����NPC�Ļ�������װ��������
	map_skill("parry", "cibei_dao");		//����NPC�Ļ����м�װ���ȱ���
	map_skill("finger", "nianhua_zhi");		//����NPC�Ļ���ָ��װ���黨ָ

	set("apply/armor", 160);			//����NPC���ӷ�����
	set("apply/damage", 120);			//����NPC���ӹ�����
	
	prepare_skill("finger", "nianhua_zhi");

	carry_object("mudao")->wield();	
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("force recover", 0);	//�Զ�����
		break;
	case 1:
		perform_action("finger foxue", 1);	//�黨ָ�����黨��Ѩ
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
