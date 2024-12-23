// pub_zhanglaoshi.h ����ʵ
//jaja 2002-10-20

NPC_BEGIN(CNpub_zhanglaoshi);

virtual void create()
{
	set_name("����ʵ", "zhanglaoshi");
	set("title", "�Ͼƹ�");
	set("gender", "����");
	set("age", 55);
	set("level", 100);
	set("long", 
		"���������ֵ����ģ����ٶ��������ӣ�һ��ԲԲ�����ϣ�����˫������Զ˯���ѵ��۾�����һ��ͨ��Ĵ������衣\n");
	set("attitude", "friendly");		//����NPC̬��
	set("icon",20);				//������������
	set("repute", 5000);
	
	set("str", 21);
	set("int", 23);
	set("con", 23);
	set("dex", 21);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 30);			//����NPC��������
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 250);			// �����ڹ�
	set_skill("xuantian_shengong", 250);		// ������
	set_skill("finger", 250);			// ����ָ��
	set_skill("xuantian_zhi", 250);			// ��������ָ
	set_skill("dodge", 250);			// ��������
	set_skill("qingfu_shenfa", 250);		// ��������
	set_skill("parry", 250);			// �����м�
	set_skill("blade", 250);		        // ��������
	set_skill("wuyue_blade", 250);			// ���µ���

	map_skill("force", "xuantian_shengong");	//����NPC��ǰ�ڹ�Ϊ������
	map_skill("blade", "wuyue_blade");	        //����NPC�Ļ�������װ�����µ���
	map_skill("dodge", "qingfu_shenfa");		//����NPC�Ļ�������װ����������
	map_skill("parry", "wuyue_blade");		//����NPC�Ļ����м�װ�����µ���
	map_skill("finger", "xuantian_zhi");		//����NPC�Ļ���ָ��װ����������ָ

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 30);			//����NPC���ӹ�����

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