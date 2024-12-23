// pub_lanlanglang.h ���Ŭ�
// jaja 2002-10-20

NPC_BEGIN(CNpub_lanlanglang);

virtual void create()
{
	set_name("���Ŭ�", "lan langlang");
	set("title", "����������");
	set("gender", "����");
	set("age", 60);
	set("level", 100);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",42);				//������������
	set("repute", -5000);
	
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 30);			//����NPC��������
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 250);			// �����ڹ�
	set_skill("taixuan_gong", 250);		// ���͵�̫����
	set_skill("unarmed", 250);			// ����ȭ��
	set_skill("changquan", 250);		// ��ȭ
	set_skill("dodge", 250);			// ��������
	set_skill("shenxing_baibian", 250);		// ���аٱ�
	set_skill("parry", 250);			// �����м�
	set_skill("staff", 250);		        // �����ȷ�
	set_skill("juemen_gun", 250);		// ���Ź�

	map_skill("force", "taixuan_gong");		//����NPC��ǰ�ڹ�Ϊ���͵�̫����
	map_skill("staff", "juemen_gun");	        //����NPC�Ļ����ȷ�װ�����Ź�
	map_skill("dodge", "shenxing_baibian");		//����NPC�Ļ����Ṧװ�����аٱ�
	map_skill("parry", "juemen_gun");		//����NPC�Ļ����м�װ�����Ź�
	map_skill("unarmed", "changquan");		//����NPC�Ļ���ȭ��װ����ȭ

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 30);			//����NPC���ӹ�����

	carry_object("gangzhang")->wield();	
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("force recover", 0);	//�Զ�����
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
