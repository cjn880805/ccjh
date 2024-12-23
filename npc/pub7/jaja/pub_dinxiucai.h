// pub_dinxiucai.h �����
// dieer 2002-8-5

NPC_BEGIN(CNpub_dinxiucai);

virtual void create()
{
	set_name("�����", "din xiucai");
	set("title", "��ʮ������֮");
	set("gender", "����");
	set("age", 40);
	set("level", 157);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",20);				//������������
	set("per",15);
	set("repute", 10000);
	
	set("str", 36);
	set("int", 23);
	set("con", 30);
	set("dex", 35);
	
	set("chat_chance_combat", 10);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("mp_factor", 80);			//����NPC��������
	
	set("combat_exp", 40000000+random(20000000));
	set("score", 6000);
	
	set_skill("force", 350);			// �����ڹ�
	set_skill("yunv_xinjing", 350);			// ��Ů�ľ�
	set_skill("unarmed", 350);			// ����ȭ��
	set_skill("anranxiaohun_zhang", 350);		// ��Ȼ������
	set_skill("dodge", 350);			// ��������
	set_skill("xianyun_bufa", 350);			// ���Ʋ���
	set_skill("parry", 350);			// �����м�
	set_skill("sword", 350);		        // ��������
	set_skill("smithsword", 350);			// �����ؽ�ʽ
	set_skill("yunv_xinfa", 350);			// ��Ů�ķ�
	set_skill("tianluo_diwang", 350);		// ���޵���

	map_skill("force", "yunv_xinjing");		//����NPC��ǰ�ڹ�Ϊ��Ů�ľ�
	map_skill("sword", "smithsword");	        //����NPC�Ļ�������װ�������ؽ�ʽ
	map_skill("dodge", "xianyun_bufa");		//����NPC�Ļ����Ṥװ�����Ʋ���
	map_skill("parry", "smithsword");		//����NPC�Ļ����м�װ�������ؽ�ʽ
	map_skill("unarmed", "anranxiaohun_zhang");	//����NPC�Ļ���ȭ��װ����Ȼ������

	set("apply/armor", 160);			//����NPC���ӷ�����
	set("apply/damage", 80);			//����NPC���ӹ�����

	carry_object("changjian")->wield();	
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("sword flood", 1);	//�����ؽ�ʽ(flood������)
		break;
	case 1:
		perform_action("unarmed xiaohun", 1);	//��Ȼ����
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