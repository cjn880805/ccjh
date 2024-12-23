// lev1_.h ����
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_huiyue);

virtual void create()
{
	set_name("����", "yui yue");
	set("title", "ʥ��ʹ��");
	set("gender", "Ů��");
	set("age", 36);
	set("level", 100);

	set("attitude", "friendly");		//����NPC̬��
	set("icon",6);				//������������
	
	set("str", 27);
	set("int", 20);
	set("con", 20);
	set("dex", 21);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 1);			//����NPC��������
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 190+random(30));			// �����ڹ�
	set_skill("shenghuo_shengong", 190+random(30));		// ʥ����
	set_skill("shenghuo_xinfa", 190+random(30));		// ʥ���ķ�
	set_skill("finger", 190+random(30));			// ����ָ��
	set_skill("xuantian_zhi", 190+random(30));			// ��������ָ
	set_skill("dodge", 190+random(30));			// ��������
	set_skill("qingfu_shenfa", 190+random(30));		// ������
	set_skill("parry", 190+random(30));			// �����м�
	set_skill("lingfa", 190+random(30));		        // �����
	set_skill("shenghuo_lingfa", 190+random(30));		// ʥ���

	map_skill("force", "shenghuo_shengong");	//����NPC��ǰ�ڹ�Ϊʥ����
	map_skill("lingfa", "shenghuo_lingfa");	        //����NPC�Ļ����װ��ʥ���
	map_skill("dodge", "qingfu_shenfa");		//����NPC�Ļ�������װ��������
	map_skill("parry", "shenghuo_lingfa");		//����NPC�Ļ����м�װ��ʥ���
	map_skill("finger", "xuantian_zhi");		//����NPC�Ļ���ָ��װ����������ָ

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 10);			//����NPC���ӹ�����
	
	prepare_skill("finger", "xuantian_zhi");

	carry_object("shenghuo_ling")->wield();
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("lingfa xiyanling", 1);	//ʥ���(xiyanling�����桹��)
		break;
	case 1:
			//�Զ�����
		break;
	case 2:
			//�Զ�����
		break;
	case 3:
			//�Զ�����
		break;
	case 4:
			//�Զ�����
		break;
	case 5:
			//�Զ�����
		break;
	}	
	return 0;
}

LEV1_END;