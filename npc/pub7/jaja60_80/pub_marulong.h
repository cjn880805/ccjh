// lev1_marulong.h ������
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_marulong);

virtual void create()
{
	set_name("������", "ma rulong");
	set("title", "������");
	set("gender", "����");
	set("age", 24);
	set("level", 100);
	set("long", 
		"����ɫ�԰ף��·���Ų��ݣ���ȴЦ���º͡���ֹ���ţ�����Ҳ��������\n");
	set("attitude", "peaceful");		//����NPC̬��
	set("icon",17);				//������������
	
	set("str", 22);
	set("int", 22);
	set("con", 22);
	set("dex", 22);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 1);			//����NPC��������
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 190+random(30));			// �����ڹ�
	set_skill("kuihua_xinfa", 190+random(30));			// �����ķ�
	set_skill("dodge", 190+random(30));			// ��������
	set_skill("parry", 190+random(30));			// �����м�
	set_skill("sword", 190+random(30));			// ��������
	set_skill("pixie_jian", 190+random(30));			// ��а����

	map_skill("force", "kuihua_xinfa");		//����NPC��ǰ�ڹ�Ϊ�����ķ�
	map_skill("sword", "pixie_jian");	        //����NPC�Ļ�������װ����а����
	map_skill("dodge", "pixie_jian");		//����NPC�Ļ�������װ����а����
	map_skill("parry", "riyue_bian");		//����NPC�Ļ����м�װ����а����

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 10);			//����NPC���ӹ�����

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

