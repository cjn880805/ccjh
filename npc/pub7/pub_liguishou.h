// pub_liguishou.h �����
// dieer 2002-8-5

NPC_BEGIN(CNpub_liguishou);

virtual void create()
{
	set_name("�����", "li guishou");
	set("title", "��ʮ������֮");
	set("gender", "����");
	set("age", 30);
	set("level", 157);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",44);				//������������
	set("per",15);
	set("repute", -10000);
	
	set("str", 34);
	set("int", 34);
	set("con", 34);
	set("dex", 34);
	
	set("chat_chance_combat", 10);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("mp_factor", 50);			//����NPC��������
	
	set("combat_exp", 40000000+random(20000000));
	set("score", 6000);
	
	set_skill("force", 350);			// �����ڹ�
	set_skill("kuihua_xinfa", 350);			// �����ķ�
	set_skill("dodge", 350);			// ��������
	set_skill("parry", 350);			// �����м�
	set_skill("sword", 350);			// ��������
	set_skill("pixie_jian", 350);			// ��а����

	map_skill("force", "kuihua_xinfa");		//����NPC��ǰ�ڹ�Ϊ�����ķ�
	map_skill("sword", "pixie_jian");	        //����NPC�Ļ�������װ����а����
	map_skill("dodge", "pixie_jian");		//����NPC�Ļ�������װ����а����
	map_skill("parry", "riyue_bian");		//����NPC�Ļ����м�װ����а����

	set("apply/armor", 160);			//����NPC���ӷ�����
	set("apply/damage", 50);			//����NPC���ӹ�����

	prepare_skill("sword", "pixie_jian");		//����NPC����Ϲ���

	carry_object("changjian")->wield();	
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("sword cimu", 1);	//��а�������д�Ŀ
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
