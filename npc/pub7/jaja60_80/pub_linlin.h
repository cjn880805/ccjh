// lev1_linlin.h ����
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_linlin);

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
	set("mp_factor", 1);			//����NPC��������
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 190+random(30));			// �����ڹ�
	set_skill("zixia_shengong", 190+random(30));		// ��ϼ��
	set_skill("strike", 190+random(30));			// �����Ʒ�
	set_skill("hunyuan_zhang", 190+random(30));		// ��Ԫ��
	set_skill("dodge", 190+random(30));			// ��������
	set_skill("huashan_shenfa", 190+random(30));		// ��ɽ��
	set_skill("parry", 190+random(30));			// �����м�
	set_skill("sword", 190+random(30));		        // ��������
	set_skill("yunv_swords", 190+random(30));		// ��Ů����ʮ����
	set_skill("fanliangyi_dao", 190+random(30));		// �����ǵ���

	map_skill("force", "zixia_shengong");		//����NPC��ǰ�ڹ�Ϊ��ϼ��
	map_skill("sword", "yunv_swords");	        //����NPC�Ļ�������װ����Ů����ʮ����
	map_skill("dodge", "huashan_shenfa");		//����NPC�Ļ����Ṧװ����ɽ��
	map_skill("parry", "fanliangyi_dao");		//����NPC�Ļ����м�װ�������ǵ���
	map_skill("strike", "hunyuan_zhang");		//����NPC�Ļ����Ʒ�װ����Ԫ��

	prepare_skill("strike", "hunyuan_zhang");	//����NPC�Ŀ�����ȫ

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 10);			//����NPC���ӹ�����

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
