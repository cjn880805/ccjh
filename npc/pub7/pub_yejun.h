// pub_yejun.h Ҷ��
// jaja 2002-10-20

NPC_BEGIN(CNpub_yejun);

virtual void create()
{
	set_name("Ҷ��", "ye jun");
	set("title", "δ����");
	set("gender", "����");
	set("age", 50);
	set("level", 100);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",18);				//������������
	
	set("str", 21);
	set("int", 23);
	set("con", 23);
	set("dex", 21);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 30);			//����NPC��������
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 250);			// �����ڹ�
	set_skill("shenghuo_shengong", 250);		// ʥ����
	set_skill("finger", 250);			// ����ָ��
	set_skill("xuantian_zhi", 250);			// ��������ָ
	set_skill("dodge", 250);			// ��������
	set_skill("qingfu_shenfa", 250);		// ������
	set_skill("parry", 250);			// �����м�
	set_skill("throwing", 250);				// ����Ͷ��
	set_skill("duoming_jinhua", 250);		// ������

	map_skill("force", "shenghuo_shengong");	//����NPC��ǰ�ڹ�Ϊʥ����
	map_skill("lingfa", "Shenghuo_lingfa");	    //����NPC�Ļ����װ��ʥ���
	map_skill("dodge", "qingfu_shenfa");		//����NPC�Ļ�������װ��������
	map_skill("finger", "xuantian_zhi");		//����NPC�Ļ���ָ��װ����������ָ
	map_skill("throwing", "duoming_jinhua");	//����NPC�Ļ���Ͷ��װ��������

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 30);			//����NPC���ӹ�����
	
	prepare_skill("finger", "xuantian_zhi");

	carry_object("baipao")->wear();
	carry_object("kuihuazhen", 200)->wield();
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("throwing muye", 1);	//������(muye���컨��)
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

