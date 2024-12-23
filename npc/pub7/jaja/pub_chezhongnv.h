// pub_chezhongnv.h ����Ů
// dieer 2002-7-27

NPC_BEGIN(CNpub_chezhongnv);

virtual void create()
{
	set_name("����Ů", "chezhong nv");
	set("title", "��ʮ������֮");
	set("gender", "Ů��");
	set("age", 18);
	set("level", 157);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",4);				//������������
	set("per",30);
	set("repute", 10000);	
	
	set("str", 31);
	set("int", 37);
	set("con", 32);
	set("dex", 31);
	
	set("chat_chance_combat", 40);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("mp_factor", 50);			//����NPC��������
	
	set("combat_exp", 40000000+random(20000000));
	set("score", 6000);
	
	set_skill("force", 350);			// �����ڹ�
	set_skill("bahuang_gong", 350);			// �˻�����Ψ�Ҷ���
	set_skill("strike", 350);			// �����Ʒ�
	set_skill("liuyang_zhang", 350);		// ������
	set_skill("hand", 350);				// �����ַ�
	set_skill("zhemei_shou", 350);			// ��÷��
	set_skill("dodge", 350);			// ��������
	set_skill("yueying_wubu", 350);			// ��Ӱ�貽
	set_skill("parry", 350);			// �����м�
	set_skill("sword", 350);		        // ��������
	set_skill("tianyu_qijian", 350);		// �����潣

	map_skill("force", "bahuang_gong");		//����NPC��ǰ�ڹ�Ϊ�˻�
	map_skill("sword", "tianyu_qijian");	        //����NPC�Ļ�������װ�������潣
	map_skill("dodge", "yueying_wubu");		//����NPC�Ļ�������װ����Ӱ�貽
	map_skill("parry", "tianyu_qijian");		//����NPC�Ļ����м�װ�������潣
	map_skill("strike", "liuyang_zhang");		//����NPC�Ļ����Ʒ�װ��������
	map_skill("hand", "zhemei_shou");		//����NPC�Ļ����ַ�װ����÷��

	set("apply/armor", 160);			//����NPC���ӷ�����
	set("apply/damage", 80);			//����NPC���ӹ�����

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
		perform_action("force recover", 0);	//�Զ�����
		break;
	case 5:
		perform_action("force recover", 0);	//�Զ�����
		break;
	}	
	return 0;
}

NPC_END;
