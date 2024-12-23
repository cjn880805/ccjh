// lev1_jiangbiehe.h �����
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_jiangbiehe);

virtual void create()
{
	set_name("�����", "jiang biehe");
	set("title", "��������");
	set("gender", "����");
	set("age", 50);
	set("level", 100);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",19);				//������������
	set("repute", -6000);
	
	set("str", 27);
	set("int", 20);
	set("con", 20);
	set("dex", 21);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 1);			//����NPC��������
	
	set("combat_exp", 1900000+random(300000));
	set("score", 6000);
	
	set_skill("force", 200+random(30));			// �����ڹ�
	set_skill("zixia_shengong", 200+random(30));		// ��ϼ��
	set_skill("strike", 200+random(30));			// �����Ʒ�
	set_skill("hunyuan_zhang", 200+random(30));		// ��Ԫ��
	set_skill("dodge", 200+random(30));			// ��������
	set_skill("huashan_shenfa", 200+random(30));		// ��ɽ��
	set_skill("parry", 200+random(30));			// �����м�
	set_skill("sword", 200+random(30));		        // ��������
	set_skill("huashan_sword", 200+random(30));		// ��ɽ����
	set_skill("fanliangyi_dao", 200+random(30));		// �����ǵ���

	map_skill("force", "zixia_shengong");		//����NPC��ǰ�ڹ�Ϊ��ϼ��
	map_skill("sword", "huashan_sword");	        //����NPC�Ļ�������װ����ɽ����
	map_skill("dodge", "huashan_shenfa");		//����NPC�Ļ����Ṧװ����ɽ��
	map_skill("parry", "fanliangyi_dao");		//����NPC�Ļ����м�װ�������ǵ���
	map_skill("strike", "hunyuan_zhang");		//����NPC�Ļ����Ʒ�װ����Ԫ��

	prepare_skill("strike", "hunyuan_zhang");	//����NPC�Ŀ�����ȫ

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 40);			//����NPC���ӹ�����

	carry_object("sword_1")->wield();	
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("sword jianzhang", 1);	//��ɽ�������н���������
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
