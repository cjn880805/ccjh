// lev1_qihu.h ����
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_qihu);

virtual void create()
{
	set_name("����", "qi hu");
	set("title", "�ٲ��ɻ�");
	set("gender", "Ů��");
	set("age", 20);
	set("level", 100);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",3);				//������������
	
	set("str", 23);
	set("int", 21);
	set("con", 21);
	set("dex", 22);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 1);			//����NPC��������
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 190+random(30));			// �����ڹ�
	set_skill("bahuang_gong", 190+random(30));			// �˻�����Ψ�Ҷ���
	set_skill("strike", 190+random(30));			// �����Ʒ�
	set_skill("liuyang_zhang", 190+random(30));		// ������
	set_skill("hand", 190+random(30));				// �����ַ�
	set_skill("zhemei_shou", 190+random(30));			// ��÷��
	set_skill("dodge", 190+random(30));			// ��������
	set_skill("yueying_wubu", 190+random(30));			// ��Ӱ�貽
	set_skill("parry", 190+random(30));			// �����м�
	set_skill("sword", 190+random(30));		        // ��������
	set_skill("tianyu_qijian", 190+random(30));		// �����潣

	map_skill("force", "bahuang_gong");		//����NPC��ǰ�ڹ�Ϊ�˻�
	map_skill("sword", "tianyu_qijian");	        //����NPC�Ļ�������װ�������潣
	map_skill("dodge", "yueying_wubu");		//����NPC�Ļ�������װ����Ӱ�貽
	map_skill("parry", "tianyu_qijian");		//����NPC�Ļ����м�װ�������潣
	map_skill("strike", "liuyang_zhang");		//����NPC�Ļ����Ʒ�װ��������
	map_skill("hand", "zhemei_shou");		//����NPC�Ļ����ַ�װ����÷��

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 10);			//����NPC���ӹ�����

	prepare_skill("hand", "zhemei_shou");		//����NPC�Ŀ������
	prepare_skill("strike", "liuyang_zhang");

	carry_object("changjian")->wield();	
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("sword san", 1);		//�����潣(san��Ůɢ��)
		break;
	case 1:
		perform_action("hand duo", 1);		//��÷��(duo���������)
		break;
	case 2:
		perform_action("sword kuangwu", 1);	//�����潣(kuangwu��Ů����)
		break;
	case 3:
		perform_action("force powerup", 0);	//�Զ�����
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
