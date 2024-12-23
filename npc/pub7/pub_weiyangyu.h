// pub_weiyangyu.h ά��ӽ�����
// dieer 2002-8-5

NPC_BEGIN(CNpub_weiyangyu);

virtual void create()
{
	set_name("ά��ӽ�����", "weiyang yu");
	set("title", "��ʮ������֮");
	set("gender", "����");
	set("age", 70);
	set("level", 157);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",19);				//������������
	set("per",18);
	set("repute", 10000);
	
	set("str", 36);
	set("int", 33);
	set("con", 36);
	set("dex", 33);
	
	set("chat_chance_combat", 10);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("mp_factor", 50);			//����NPC��������
	
	set("combat_exp", 40000000+random(20000000));
	set("score", 6000);
	
	set_skill("force", 350);			// �����ڹ�
	set_skill("xuantian_shengong", 350);		// ������
	set_skill("finger", 350);			// ����ָ��
	set_skill("xuantian_zhi", 350);			// ��������ָ
	set_skill("dodge", 350);			// ��������
	set_skill("qingfu_shenfa", 350);		// ������
	set_skill("parry", 350);			// �����м�
	set_skill("blade", 350);		        // ��������
	set_skill("wuyue_blade", 350);			// ���µ���

	map_skill("force", "xuantian_shengong");	//����NPC��ǰ�ڹ�Ϊ������
	map_skill("blade", "wuyue_blade");	        //����NPC�Ļ�������װ�����µ���
	map_skill("dodge", "qingfu_shenfa");		//����NPC�Ļ�������װ��������
	map_skill("parry", "wuyue_blade");		//����NPC�Ļ����м�װ�����µ���
	map_skill("finger", "xuantian_zhi");		//����NPC�Ļ���ָ��װ����������ָ

	set("apply/armor", 160);			//����NPC���ӷ�����
	set("apply/damage", 60);			//����NPC���ӹ�����

	carry_object("gangdao")->wield();

	prepare_skill("finger", "xuantian_zhi");
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("blade jiao", 1);	//���µ���(jiao���־�)
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
