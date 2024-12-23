// lev1_gongzijun.h ���ӿ�
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_gongzijun);

virtual void create()
{
	set_name("���ӿ�", "gong zijun");
	set("title", "�����ɻ�");
	set("gender", "����");
	set("age", 20);
	set("level", 100);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",17);				//������������
	set("repute", 4000);
	
	set("str", 24);
	set("int", 20);
	set("con", 23);
	set("dex", 20);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 1);			//����NPC��������
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 190+random(30));			// �����ڹ�
	set_skill("shenghuo_shengong", 190+random(30));		// ʥ����
	set_skill("finger", 190+random(30));			// ����ָ��
	set_skill("xuantian_zhi", 190+random(30));			// ��������ָ
	set_skill("dodge", 190+random(30));			// ��������
	set_skill("qingfu_shenfa", 190+random(30));		// ������
	set_skill("parry", 190+random(30));			// �����м�
	set_skill("throwing", 190+random(30));				// ����Ͷ��
	set_skill("duoming_jinhua", 190+random(30));		// ������

	map_skill("force", "shenghuo_shengong");	//����NPC��ǰ�ڹ�Ϊʥ����
	map_skill("lingfa", "Shenghuo_lingfa");	    //����NPC�Ļ����װ��ʥ���
	map_skill("dodge", "qingfu_shenfa");		//����NPC�Ļ�������װ��������
	map_skill("finger", "xuantian_zhi");		//����NPC�Ļ���ָ��װ����������ָ
	map_skill("throwing", "duoming_jinhua");	//����NPC�Ļ���Ͷ��װ��������

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 10);			//����NPC���ӹ�����
	
	prepare_skill("finger", "xuantian_zhi");

	carry_object("baipao")->wear();
	carry_object("kuihuazhen", 100)->wield();
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("throwing muye", 1);	//������(muye���컨��)
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
