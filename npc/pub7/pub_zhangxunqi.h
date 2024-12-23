// pub_zhangxunqi.h ��ѵ��
// dieer 2002-8-10

NPC_BEGIN(CNpub_zhangxunqi);

virtual void create()
{
	set_name("��ѵ��", "zhangxun qi");
	set("title", "��ʮ������֮");
	set("gender", "Ů��");
	set("age", 20);
	set("level", 157);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",7);				//������������
	set("per",16);
	
	set("str", 32);
	set("int", 24);
	set("con", 39);
	set("dex", 37);
	set("repute", -10000);
	
	set("chat_chance_combat", 10);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("mp_factor", 50);			//����NPC��������
	
	set("combat_exp", 40000000+random(20000000));
	set("score", 6000);

	set_skill("force", 350);			// �����ڹ�
	set_skill("huagong_dafa", 350);			// ������
	set_skill("dodge", 350);			// ��������
	set_skill("zhaixinggong", 350);			// ժ�ǹ�
	set_skill("parry", 350);			// �����м�
	set_skill("claw", 350);			        // ����צ��
	set_skill("sanyin_wugongzhao", 350);		// �������ץ
	set_skill("strike", 350);			// �����Ʒ�
	set_skill("chousui_zhang", 350);		// ������

	map_skill("force", "huagong_dafa");		//����NPC��ǰ�ڹ�Ϊ������
	map_skill("dodge", "zhaixinggong");		//����NPC�Ļ�������װ��ժ�ǹ�
	map_skill("parry", "sanyin_wugongzhao");	//����NPC�Ļ����м�װ���������ץ
	map_skill("claw", "sanyin_wugongzhao");		//����NPC�Ļ���צ��װ���������ץ
	map_skill("strike", "chousui_duzhang");		//����NPC�Ļ����Ʒ�װ��������

	set("apply/armor", 160);			//����NPC���ӷ�����
	set("apply/damage", 80);			//����NPC���ӹ�����

	prepare_skill("strike", "chousui_duzhang");	//����NPC�������
	prepare_skill("claw", "sanyin_wugongzhao");

}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("force powerup", 0);	//������(powerup)
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
