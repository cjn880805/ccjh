// lev1_tumengping.h ����ƽ
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_tumengping);

virtual void create()
{
	set_name("����ƽ", "tu mengping");
	set("title", "�ɺ罣");
	set("gender", "����");
	set("age", 60);
	set("level", 100);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",36);				//������������
	
	set("str", 23);
	set("int", 23);
	set("con", 20);
	set("dex", 21);
	
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
	set_skill("huashan_sword", 190+random(30));		// ��ɽ����
	set_skill("fanliangyi_dao", 190+random(30));		// �����ǵ���

	map_skill("force", "zixia_shengong");		//����NPC��ǰ�ڹ�Ϊ��ϼ��
	map_skill("sword", "huashan_sword");	        //����NPC�Ļ�������װ����ɽ����
	map_skill("dodge", "huashan_shenfa");		//����NPC�Ļ����Ṥװ����ɽ��
	map_skill("parry", "fanliangyi_dao");		//����NPC�Ļ����м�װ�������ǵ���
	map_skill("strike", "hunyuan_zhang");		//����NPC�Ļ����Ʒ�װ����Ԫ��

	prepare_skill("strike", "hunyuan_zhang");

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 10);			//����NPC���ӹ�����

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

