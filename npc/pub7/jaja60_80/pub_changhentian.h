// lev1_changhentian.h ������
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_changhentian);

virtual void create()
{
	set_name("������", "chang hentian");
	set("title", "�������");
	set("gender", "����");
	set("age", 40);
	set("level", 100);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",14);				//������������
	set("repute", 5000);			
	
	set("str", 22);
	set("int", 24);
	set("con", 23);
	set("dex", 20);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 1);			//����NPC��������
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 190+random(30));			// �����ڹ�
	set_skill("huagong_dafa", 190+random(30));			// ������
	set_skill("strike", 190+random(30));			// �����Ʒ�
	set_skill("chousui_zhang", 190+random(30));		// ������
	set_skill("dodge", 190+random(30));			// ��������
	set_skill("zhaixinggong", 190+random(30));			// ժ�ǹ�
	set_skill("parry", 190+random(30));			// �����м�
	set_skill("staff", 190+random(30));		        // �����ȷ�
	set_skill("tianshan_zhang", 190+random(30));		// ��ɽ�ȷ�
	set_skill("fanliangyi_dao", 190+random(30));		// �����ǵ���

	map_skill("force", "huagong_dafa");		//����NPC��ǰ�ڹ�Ϊ������
	map_skill("staff", "tianshan_zhang");	        //����NPC�Ļ����ȷ�װ����ɽ�ȷ�
	map_skill("dodge", "zhaixinggong");		//����NPC�Ļ����Ṧװ��ժ�ǹ�
	map_skill("parry", "tianshan_zhang");		//����NPC�Ļ����м�װ����ɽ�ȷ�
	map_skill("strike", "chousui_zhang");		//����NPC�Ļ����Ʒ�װ��������

	prepare_skill("strike", "chousui_zhang");	//����NPC�Ŀ�����ȫ

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 10);			//����NPC���ӹ�����

	carry_object("gangzhang")->wield();	
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("strike throw", 1);	//������(throwʩ����)
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
