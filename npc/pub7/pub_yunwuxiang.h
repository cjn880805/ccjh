// pub_yunwuxiang.h ������
// jaja 2002-10-20

NPC_BEGIN(CNpub_yunwuxiang);

virtual void create()
{
	set_name("������", "yun wuxiang");
	set("title", "��������");
	set("gender", "����");
	set("age", 30);
	set("level", 100);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",15);				//������������
	set("repute", -5000);
	
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
	set_skill("huagong_dafa", 250);			// ������
	set_skill("dodge", 250);			// ��������
	set_skill("zhaixinggong", 250);			// ժ�ǹ�
	set_skill("parry", 250);			// �����м�
	set_skill("claw", 250);			        // ����צ��
	set_skill("sanyin_wugongzhao", 250);		// �������ץ
	set_skill("strike", 250);			// �����Ʒ�
	set_skill("chousui_zhang", 250);		// ������

	map_skill("force", "huagong_dafa");		//����NPC��ǰ�ڹ�Ϊ������
	map_skill("dodge", "zhaixinggong");		//����NPC�Ļ�������װ��ժ�ǹ�
	map_skill("parry", "sanyin_wugongzhao");	//����NPC�Ļ����м�װ���������ץ
	map_skill("claw", "sanyin_wugongzhao");		//����NPC�Ļ���צ��װ���������ץ
	map_skill("strike", "chousui_duzhang");		//����NPC�Ļ����Ʒ�װ��������

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 50);			//����NPC���ӹ�����

	prepare_skill("strike", "chousui_duzhang");	//����NPC�������
	prepare_skill("claw", "sanyin_wugongzhao");

}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("force powerup", 1);	//������(powerup)
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