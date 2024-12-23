// lev2_zhenfang.h ֤����ʦ
// jaja 2002-12-23

LEV2_BEGIN(CNlev2_zhenfang);

virtual void create()
{
	set_name("֤����ʦ", "zhen fang");
	set("title", "�ҷ�ȱ�");
	set("gender", "����");
	set("age", 70);
	set("level", 120);

	set("attitude", "friendly");		//����NPC̬��
	set("icon",27);				//������������
	set("repute", 8000);
	
	set("str", 26);
	set("int", 29);
	set("con", 27);
	set("dex", 25);
	
	set("chat_chance_combat", 10);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 12000+random(3000));
	set("max_mp", 7000);
	set("mp_factor", 1);			//����NPC��������
	
	set("combat_exp", 6000000+random(6000000));
	set("score", 6000);
	
	set_skill("force", 250+random(30));			// �����ڹ�
	set_skill("hunyuan_yiqi", 250+random(30));			// ��Ԫһ����
	set_skill("finger", 250+random(30));			// ����ָ��
	set_skill("nianhua_zhi", 250+random(30));			// �黨ָ
	set_skill("dodge", 250+random(30));			// ��������
	set_skill("shaolin_shenfa", 250+random(30));		// ������
	set_skill("parry", 250+random(30));			// �����м�
	set_skill("blade", 250+random(30));		        // ��������
	set_skill("cibei_dao", 250+random(30));			// �ȱ���

	map_skill("force", "hunyuan_yiqi");		//����NPC��ǰ�ڹ�Ϊ��Ԫһ����
	map_skill("blade", "cibei_dao");	     	//����NPC�Ļ�������װ���ȱ���
	map_skill("dodge", "shaolin_shenfa");		//����NPC�Ļ�������װ��������
	map_skill("parry", "cibei_dao");		//����NPC�Ļ����м�װ���ȱ���
	map_skill("finger", "nianhua_zhi");		//����NPC�Ļ���ָ��װ���黨ָ

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 50);			//����NPC���ӹ�����
	
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

LEV2_END;
