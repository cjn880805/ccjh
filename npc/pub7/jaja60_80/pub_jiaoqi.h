// lev1_jiaoqi.h ����
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_jiaoqi);

virtual void create()
{
	set_name("����", "lei meng");
	set("title", "������");
	set("gender", "����");
	set("age", 66);
	set("level", 100);
	set("long", 
		"���Ǹ�Ǭ����С��С��ͷ��һ��Ǭ�����Ƶ����ϣ�����˫СС�������ۣ����ż���ϡ���ɽ����ӣ�������ͷ���������ѿ�����ˡ�\n");
	
	set("attitude", "peaceful");		//����NPC̬��
	set("icon",20);				//������������
	set("repute", -5000);
	
	set("str", 27);
	set("int", 20);
	set("con", 20);
	set("dex", 21);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 1);			//����NPC��������
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 190+random(30));			// �����ڹ�
	set_skill("hunyuan_yiqi", 190+random(30));			// ��Ԫһ����
	set_skill("claw", 190+random(30));				// ����צ��
	set_skill("longzhua_gong", 190+random(30));		// ��צ��
	set_skill("dodge", 190+random(30));			// ��������
	set_skill("shaolin_shenfa", 190+random(30));		// ��������
	set_skill("parry", 190+random(30));			// �����м�
	set_skill("cuff", 190+random(30));				// ����ȭ��
	set_skill("jingang_quan", 190+random(30));			// ����ȭ

	map_skill("force", "hunyuan_yiqi");		//����NPC��ǰ�ڹ�Ϊ��Ԫһ����
	map_skill("cuff", "jingang_quan");	        //����NPC�Ļ���ȭ��װ������ȭ
	map_skill("dodge", "shaolin_shenfa");		//����NPC�Ļ�������װ����������
	map_skill("parry", "jingang_quan");		//����NPC�Ļ����м�װ������ȭ
	map_skill("claw", "longzhua_gong");		//����NPC�Ļ���צ��װ����צ��

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 10);			//����NPC���ӹ�����

	prepare_skill("claw", "longzhua_gong");		//����NPC����Ϲ���
	prepare_skill("cuff", "jingang_quan");
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("cuff jingang", 1);	//����ȭ(jingang������ͨ)
		break;
	case 1:
			//�Զ�����
		break;
	case 2:
		perform_action("force roar", 1);	//��Ԫһ��������ʨ�Ӻ�
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
