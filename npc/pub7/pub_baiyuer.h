// pub_baiyuer.h �����
// jaja 2002-10-20

NPC_BEGIN(CNpub_baiyuer);

virtual void create()
{
	set_name("�����", "bai yuer");
	set("title", "��Ŀ����");
	set("gender", "Ů��");
	set("age", 23);
	set("level", 100);
	set("long", 
		"�������Ǹ�����,ѩ�׵����ӣ�����ֱͦ��������������ȴû���۾��������������ѱ�ĳ�������ħ�����𣬱��һƬ�⻬��Ƥ�������һƬ�հף������Ŀհף�\n");
	set("attitude", "friendly");		//����NPC̬��
	set("icon",2);				//������������
	set("repute", 5000);			//����NPC�û�
	
	set("str", 20);
	set("int", 22);
	set("con", 23);
	set("dex", 21);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 30);			//����NPC��������
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 250);			// �����ڹ�
	set_skill("zixia_shengong", 250);		// ��ϼ��
	set_skill("strike", 250);			// �����Ʒ�
	set_skill("hunyuan_zhang", 250);		// ��Ԫ��
	set_skill("dodge", 250);			// ��������
	set_skill("huashan_shenfa", 250);		// ��ɽ��
	set_skill("parry", 250);			// �����м�
	set_skill("sword", 250);		        // ��������
	set_skill("yunv_swords", 250);			// ��Ů����ʮ����

	map_skill("force", "zixia_shengong");		//����NPC��ǰ�ڹ�Ϊ��ϼ��
	map_skill("sword", "yunv_swords");	        //����NPC�Ļ�������װ����Ů����ʮ����
	map_skill("dodge", "huashan_shenfa");		//����NPC�Ļ����Ṧװ����ɽ��
	map_skill("parry", "yunv_swords");		//����NPC�Ļ����м�װ����Ů����ʮ����
	map_skill("strike", "hunyuan_zhang");		//����NPC�Ļ����Ʒ�װ����Ԫ��

	prepare_skill("strike", "hunyuan_zhang");	//����NPC��ǰʹ�õĿ������


	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 70);			//����NPC���ӹ�����

	carry_object("sword_1")->wield();	
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("sword wushuang", 1);	//��ɽ�������н���������
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
