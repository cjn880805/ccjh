// lev1_murenjin.h ���ʾ�
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_murenjin);

virtual void create()
{
	set_name("���ʾ�", "mu renjin");
	set("title", "����Գ");
	set("gender", "����");
	set("age", 70);
	set("level", 100);
	set("long", 
		"����ü��ף�������棬ٲȻ��һ���õ����ɵ������ɡ�\n");
	set("attitude", "friendly");		//����NPC̬��
	set("icon",19);				//������������
	set("repute", 6000);
	
	set("str", 23);
	set("int", 21);
	set("con", 21);
	set("dex", 22);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 50);			//����NPC��������
	
	set("combat_exp", 2000000+random(300000));
	set("score", 6000);
	
	set_skill("force", 220+random(30));			// �����ڹ�
	set_skill("zixia_shengong", 220+random(30));		// ��ϼ��
	set_skill("strike", 220+random(30));			// �����Ʒ�
	set_skill("hunyuan_zhang", 220+random(30));		// ��Ԫ��
	set_skill("dodge", 220+random(30));			// ��������
	set_skill("huashan_shenfa", 220+random(30));		// ��ɽ��
	set_skill("parry", 220+random(30));			// �����м�
	set_skill("sword", 220+random(30));		        // ��������
	set_skill("huashan_sword", 220+random(30));		// ��ɽ����
	set_skill("fanliangyi_dao", 2970);		// �����ǵ���

	map_skill("force", "zixia_shengong");		//����NPC��ǰ�ڹ�Ϊ��ϼ��
	map_skill("sword", "huashan_sword");	        //����NPC�Ļ�������װ����ɽ����
	map_skill("dodge", "huashan_shenfa");		//����NPC�Ļ����Ṥװ����ɽ��
	map_skill("parry", "fanliangyi_dao");		//����NPC�Ļ����м�װ�������ǵ���
	map_skill("strike", "hunyuan_zhang");		//����NPC�Ļ����Ʒ�װ����Ԫ��

	prepare_skill("strike", "hunyuan_zhang");

	set("apply/armor", 160);			//����NPC���ӷ�����
	set("apply/damage", 50);			//����NPC���ӹ�����

	carry_object("changjian")->wield();	
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
