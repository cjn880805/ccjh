// pub_xiexunfu.h ��䭸�
// dieer 2002-8-10

NPC_BEGIN(CNpub_xiexunfu);

virtual void create()
{
	set_name("��䭸�", "xiexun fu");
	set("title", "��ʮ������֮");
	set("gender", "Ů��");
	set("age", 20);
	set("level", 157);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",3);				//������������
	set("per",20);
	
	set("str", 31);
	set("int", 33);
	set("con", 36);
	set("dex", 31);
	set("repute", 10000);
	
	set("chat_chance_combat", 10);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("mp_factor", 1);			//����NPC��������
	
	set("combat_exp", 40000000+random(20000000));
	set("score", 6000);

	set_skill("force", 350);			// �����ڹ�
	set_skill("linji_zhuang", 350);			// �ټ�ʮ��ׯ
	set_skill("strike", 350);			// �����Ʒ�
	set_skill("jinding_zhang", 350);		// ������
	set_skill("dodge", 350);			// ��������
	set_skill("zhutian_bu", 350);			// ���컯��
	set_skill("parry", 350);			// �����м�
	set_skill("finger", 350);		        // ����ָ��
	set_skill("tiangang_zhi", 350);			// ���ָѨ��

	map_skill("force", "linji_zhuang");		//����NPC��ǰ�ڹ�Ϊ�ټ�ʮ��ׯ
	map_skill("finger", "tiangang_zhi");	        //����NPC�Ļ���ָ��װ�����ָѨ��
	map_skill("dodge", "zhutian_bu");		//����NPC�Ļ�������װ�����컯��
	map_skill("parry", "tiangang_zhi");		//����NPC�Ļ����м�װ�����ָѨ��
	map_skill("strike", "jinding_zhang");		//����NPC�Ļ����Ʒ�װ��������

	set("apply/armor", 160);			//����NPC���ӷ�����
	set("apply/damage", 60);			//����NPC���ӹ�����

	prepare_skill("strike", "jinding_zhang");
	prepare_skill("finger", "tiangang_zhi");
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("finger lingkong", 1);	//���ָѨ��(lingkong���ָѨ)
		break;
	case 1:
		perform_action("strike bashi", 1);	//�����ƾ��а�ʽ��һ
		break;
	case 2:
		perform_action("force powerup", 0);	//�Զ�����
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