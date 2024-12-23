// pub_qinpeier.h ̩���
//jaja 2002-10-20

NPC_BEGIN(CNpub_qinpeier);

virtual void create()
{
	set_name("̩���", "qin peier");
	set("title", "��ѩ����");
	set("gender", "Ů��");
	set("age", 24);
	set("level", 100);
	set("long", 
		"����ɫ�ǲ԰׵ģ���Ϊ���궼���������⣬�����ֲ԰׵���ɫ������ȴ���������ˡ���˫����ڣ�����ֱͦ�������������촽��ܱ���ȴ�������£���˵����ʱ��Ҳ���Ŷ��˵ı��顣\n");
	set("attitude", "peaceful");		//����NPC̬��
	set("icon",8);				//������������
	set("repute", 1000);
	
	set("str", 23);
	set("int", 21);
	set("con", 21);
	set("dex", 22);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 30);			//����NPC��������
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 250);			// �����ڹ�
	set_skill("yunv_xinjing", 250);			// ��Ů�ľ�
	set_skill("unarmed", 250);			// ����ȭ��
	set_skill("meinv_quan", 250);			// ��Ůȭ
	set_skill("dodge", 250);			// ��������
	set_skill("yunv_shenfa", 250);			// ��Ů��
	set_skill("parry", 250);			// �����м�
	set_skill("sword", 250);		        // ��������
	set_skill("yunv_jian", 250);			// ��Ů��
	set_skill("yunv_xinfa", 250);			// ��Ů�ķ�
	set_skill("tianluo_diwang", 250);		// ���޵���
	set_skill("quanzhen_jian", 250);		// ȫ�潣��

	map_skill("force", "yunv_xinjing");		//����NPC��ǰ�ڹ�Ϊ��Ů�ľ�
	map_skill("sword", "yunv_jian");	        //����NPC�Ļ�������װ����Ů��
	map_skill("dodge", "yunv_shenfa");		//����NPC�Ļ����Ṥװ����Ů��
	map_skill("parry", "yunv_jian");		//����NPC�Ļ����м�װ��ȫ�潣��
	map_skill("unarmed", "meinv_quan");		//����NPC�Ļ���ȭ��װ����Ůȭ


	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 30);			//����NPC���ӹ�����

	carry_object("shunvjian")->wield();	
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("sword he", 1);		//��Ů����˫���ϱ�
		break;
	case 1:
		perform_action("unarmed you", 1);	//��Ůȭ���й�Ĺ�ľ�
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

