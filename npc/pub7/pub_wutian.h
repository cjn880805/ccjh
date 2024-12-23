// pub_wutian.h �������
// jaja 2002-10-20

NPC_BEGIN(CNpub_wutian);

virtual void create()
{
	set_name("�������", "wu tian");
	set("title", "�޷�����");
	set("gender", "����");
	set("age", 60);
	set("level", 100);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",27);				//������������
	set("repute", -5000);
	
	set("str", 23);
	set("int", 23);
	set("con", 20);
	set("dex", 21);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 30);			//����NPC��������
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 250);			// �����ڹ�
	set_skill("hunyuan_yiqi", 250);			// ��Ԫһ����
	set_skill("finger", 250);			// ����ָ��
	set_skill("nianhua_zhi", 250);			// �黨ָ
	set_skill("dodge", 250);			// ��������
	set_skill("shaolin_shenfa", 250);		// ������
	set_skill("parry", 250);			// �����м�
	set_skill("club", 250);			        // ��������
	set_skill("zui_gun", 250);			// ���

	map_skill("force", "hunyuan_yiqi");		//����NPC��ǰ�ڹ�Ϊ��Ԫһ����
	map_skill("club", "zui_gun");	     		//����NPC�Ļ�������װ�����
	map_skill("dodge", "shaolin_shenfa");		//����NPC�Ļ�������װ��������
	map_skill("parry", "zui_gun");			//����NPC�Ļ����м�װ�����
	map_skill("finger", "nianhua_zhi");		//����NPC�Ļ���ָ��װ���黨ָ
	
	prepare_skill("finger", "nianhua_zhi");

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 30);			//����NPC���ӹ�����

	carry_object("mugun")->wield();	
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("whip zuida", 1);	//�������(zuida�������)
		break;
	case 1:
		perform_action("finger foxue", 1);	//�黨ָ�����黨��Ѩ
		break;
	case 2:
		perform_action("force roar", 1);	//��Ԫһ��������ʨ�Ӻ�
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