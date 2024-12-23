// pub_youwuyan.h ������
//jaja 2002-10-20

NPC_BEGIN(CNpub_youwuyan);

virtual void create()
{
	set_name("������", "you wuyang");
	set("title", "ʧ����");
	set("gender", "Ů��");
	set("age", 55);
	set("level", 100);
	set("long", 
		"��Ů�˵�ͷ�����ң���ɫ���ƣ�����˵������ƣ���㲣�����ֱ�����ز�֪������ʲô��\n");
	set("attitude", "peaceful");			//����NPC̬��
	set("icon",10);					//������������
	set("repute", -5000);
	
	set("str", 21);
	set("int", 23);
	set("con", 23);
	set("dex", 21);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 30);			//����NPC��������
	
	set("combat_exp", 1600000+random(300000));
	set("score", 6000);
	
	set_skill("force", 250);			// �����ڹ�
	set_skill("yunv_xinjing", 250);			// ��Ů�ľ�
	set_skill("unarmed", 250);			// ����ȭ��
	set_skill("meinv_quan", 250);			// ��Ůȭ
	set_skill("dodge", 250);			// ��������
	set_skill("yunv_shenfa", 250);			// ��Ů��
	set_skill("parry", 250);			// �����м�
	set_skill("whip", 250);		        // �����޷�
	set_skill("yinsuo_jinling", 250);	// ��������
	set_skill("yunv_xinfa", 250);			// ��Ů�ķ�
	set_skill("tianluo_diwang", 250);		// ���޵���

	map_skill("force", "yunv_xinjing");		//����NPC��ǰ�ڹ�Ϊ��Ů�ľ�
	map_skill("whip", "yinsuo_jinling");	//����NPC�Ļ����޷�װ����������
	map_skill("dodge", "yunv_shenfa");		//����NPC�Ļ����Ṥװ����Ů��
	map_skill("parry", "yinsuo_jinling");	//����NPC�Ļ����м�װ����������
	map_skill("unarmed", "meinv_quan");		//����NPC�Ļ���ȭ��װ����Ůȭ


	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 30);			//����NPC���ӹ�����

	carry_object("changbian")->wield();	
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("whip dian", 1);		//��������(dian��Ѩ)
		break;
	case 1:
		perform_action("unarmed you", 1);	//��Ůȭ���й�Ĺ�ľ�
		break;
	case 2:
		perform_action("whip feng", 1);	//��������(feng��Ѩ)
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
