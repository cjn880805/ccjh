// lev1_gongtianlai.h ������
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_gongtianlai);

virtual void create()
{
	set_name("������", "gong tianlai");
	set("title", "��������");
	set("gender", "����");
	set("age", 90);
	set("level", 100);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",20);				//������������
	set("repute", -5000);
	
	set("str", 24);
	set("int", 20);
	set("con", 23);
	set("dex", 20);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 10);			//����NPC��������
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 190+random(30));			// �����ڹ�
	set_skill("huagong_dafa", 190+random(30));			// ������
	set_skill("dodge", 190+random(30));			// ��������
	set_skill("zhaixinggong", 190+random(30));			// ժ�ǹ�
	set_skill("parry", 190+random(30));			// �����м�
	set_skill("claw", 190+random(30));			        // ����צ��
	set_skill("sanyin_wugongzhao", 190+random(30));		// �������ץ
	set_skill("strike", 190+random(30));			// �����Ʒ�
	set_skill("chousui_zhang", 190+random(30));		// ������
	set_skill("staff", 190+random(30));		// �����ȷ�
	set_skill("tianshan_zhang", 190+random(30));		// ��ɽ�ȷ�

	map_skill("force", "huagong_dafa");		//����NPC��ǰ�ڹ�Ϊ������
	map_skill("dodge", "zhaixinggong");		//����NPC�Ļ�������װ��ժ�ǹ�
	map_skill("parry", "sanyin_wugongzhao");	//����NPC�Ļ����м�װ���������ץ
	map_skill("claw", "sanyin_wugongzhao");		//����NPC�Ļ���צ��װ���������ץ
	map_skill("strike", "chousui_duzhang");		//����NPC�Ļ����Ʒ�װ��������
	map_skill("staff", "tianshan_zhang");		//����NPC�Ļ����ȷ�װ����ɽ�ȷ�

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 20);			//����NPC���ӹ�����

	prepare_skill("strike", "chousui_duzhang");	//����NPC�������
	prepare_skill("claw", "sanyin_wugongzhao");

	carry_object("gangzhang")->wield();
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("force powerup", 0);	//������(powerup)
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