// lev1_beibeibei.h ������
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_beibeibei);

virtual void create()
{
	set_name("������", "bei beibei");
	set("title", "����������");
	set("gender", "����");
	set("age", 60);
	set("level", 100);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",42);				//������������
	set("repute", -5000);			//����NPC�û�
	
	set("str", 22);
	set("int", 24);
	set("con", 23);
	set("dex", 20);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp", 10000);
	set("mp_factor", 1);			//����NPC��������
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 350);			// �����ڹ�
	set_skill("beiming_shengong", 139);		// ��ڤ��
	set_skill("strike", 190+random(30));			// �����Ʒ�
	set_skill("liuyang_zhang", 190+random(30));		// ������
	set_skill("dodge", 190+random(30));			// ��������
	set_skill("lingboweibu", 190+random(30));			// �貨΢��
	set_skill("parry", 190+random(30));			// �����м�
	set_skill("sword", 190+random(30));		        // ��������
	set_skill("lingxiao_kuaijian", 190+random(30));		// �����콣
	set_skill("hand", 190+random(30));				// �����ַ�
	set_skill("zhemei_shou", 190+random(30));			// �����ǵ���

	map_skill("force", "beiming_shengong");		//����NPC��ǰ�ڹ�Ϊ��ڤ��
	map_skill("sword", "lingxiao_kuaijian");	//����NPC�Ļ�������װ�������콣
	map_skill("dodge", "lingboweibu");		//����NPC�Ļ����Ṧװ���貨΢��
	map_skill("parry", "lingxiao_kuaijian");	//����NPC�Ļ����м�װ�������콣
	map_skill("strike", "liuyang_zhang");		//����NPC�Ļ����Ʒ�װ��������
	map_skill("hand", "zhemei_shou");		//����NPC�Ļ����ַ�װ����÷��

	prepare_skill("strike", "liuyang_zhang");	//����NPC�Ŀ������
	prepare_skill("hand", "zhemei_shou");

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 50);			//����NPC���ӹ�����

	carry_object("changjian")->wield();	
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("sword mixhit", 1);	//�����콣��������ʮ����
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
