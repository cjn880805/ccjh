// pub_shenmike.h ���ؿ�
//dieer 2002-7-21

NPC_BEGIN(CNpub_shenmike);

virtual void create()
{
	set_name("���ؿ�", "shen mike");
	set("gender", "����");
	set("age", 36);
	set("level", 157);
	set("long", 
		"�����ϴ��ż������ӵ��·���ͷ�ϴ��Ŷ���ñ��ñ�ص�ѹ��˭Ҳ���������ı��顣\n");
	set("attitude", "peaceful");		//����NPC̬��
	set("icon",38);				//������������
	
	set("str", 35);
	set("int", 35);
	set("con", 35);
	set("dex", 35);
	
	set("chat_chance_combat", 10);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 40000);
	set("max_mp", 10000);
	set("mp_factor", 80);			//����NPC��������
	
	set("combat_exp", 60000000);
	set("score", 6000);
	
	set_skill("force", 350);			// �����ڹ�
	set_skill("yunv_xinjing", 350);			// ��Ů�ľ�
	set_skill("unarmed", 350);			// ����ȭ��
	set_skill("anranxiaohun_zhang", 350);		// ��Ȼ������
	set_skill("dodge", 350);			// ��������
	set_skill("xianyun_bufa", 350);			// ���Ʋ���
	set_skill("parry", 350);			// �����м�
	set_skill("sword", 350);		        // ��������
	set_skill("yunv_jian", 350);			// ��Ů��
	set_skill("yunv_xinfa", 350);			// ��Ů�ķ�
	set_skill("tianluo_diwang", 350);		// ���޵���
	set_skill("quanzhen_jian", 350);		// ȫ�潣��

	map_skill("force", "yunv_xinjing");		//����NPC��ǰ�ڹ�Ϊ��Ů�ľ�
	map_skill("sword", "yunv_jian");	        //����NPC�Ļ�������װ����Ů��
	map_skill("dodge", "xianyun_bufa");		//����NPC�Ļ����Ṥװ�����Ʋ���
	map_skill("parry", "quanzhen_jian");		//����NPC�Ļ����м�װ��ȫ�潣��
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
		perform_action("sword he", 1);		//��Ů����˫���ϱ�
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
