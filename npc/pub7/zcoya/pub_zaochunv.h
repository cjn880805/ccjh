// pub_zaochunv.h �Դ�Ů
// dieer 2002-7-27

NPC_BEGIN(CNpub_zaochunv);

virtual void create()
{
	set_name("�Դ�Ů", "zaochu nv");
	set("title", "��ʮ������֮");
	set("gender", "Ů��");
	set("age", 16);
	set("level", 157);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",3);				//������������
	set("per",38);
	set("shen_type", 1);
	
	set("str", 46);
	set("int", 47);
	set("con", 45);
	set("dex", 44);
	
	set("chat_chance_combat", 10);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("mp_factor", 80);			//����NPC��������
	
	set("combat_exp", 40000000+random(20000000));
	set("score", 6000);
	
	set_skill("force", 350);			// �����ڹ�
	set_skill("yunv_xinjing", 350);			// ��Ů�ľ�
	set_skill("unarmed", 350);			// ����ȭ��
	set_skill("meinv_quan", 350);			// ��Ůȭ
	set_skill("dodge", 350);			// ��������
	set_skill("yunv_shenfa", 350);			// ��Ů��
	set_skill("parry", 350);			// �����м�
	set_skill("sword", 350);		        // ��������
	set_skill("yunv_jian", 350);			// ��Ů��
	set_skill("yunv_xinfa", 350);			// ��Ů�ķ�
	set_skill("tianluo_diwang", 350);		// ���޵���
	set_skill("quanzhen_jian", 350);		// ȫ�潣��

	map_skill("force", "yunv_xinjing");		//����NPC��ǰ�ڹ�Ϊ��Ů�ľ�
	map_skill("sword", "yunv_jian");	        //����NPC�Ļ�������װ����Ů��
	map_skill("dodge", "yunv_shenfa");		//����NPC�Ļ����Ṥװ����Ů��
	map_skill("parry", "yunv_jian");		//����NPC�Ļ����м�װ��ȫ�潣��
	map_skill("unarmed", "meinv_quan");		//����NPC�Ļ���ȭ��װ����Ůȭ


	set("apply/armor", 160);			//����NPC���ӷ�����
	set("apply/damage", 50);			//����NPC���ӹ�����

	carry_object("shunvjian")->wield();	
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("sword he", 1);		//��Ů����˫���ϱ�
		break;
	case 1:
		perform_action("unarmed you", 1);	//��Ůȭ���й�Ĺ�ľ�
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
