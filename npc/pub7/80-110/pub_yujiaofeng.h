// lev2_yujiaofeng.h �񽿷�
// jaja 2002-12-16

LEV2_BEGIN(CNlev2_yujiaofeng);

virtual void create()
{
	set_name("�񽿷�", "yu jiaofeng");
	set("title", "˧��ǧ��");
	set("gender", "Ů��");
	set("age", 20);
	set("level", 130);

	set("icon",2);				//������������
	set("per",36);
	
	set("str", 30);
	set("int", 28);
	set("con", 29);
	set("dex", 29);
	set("repute", 8000);
	
	set("chat_chance_combat", 10);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 15000+random(5000));
	set("max_mp", 8000);
	set("mp_factor", 30);			//����NPC��������
	
	set("combat_exp", 20000000+random(10000000));
	set("score", 6000);

	set_skill("force", 2500+random(50));			// �����ڹ�
	set_skill("yunv_xinjing", 250+random(50));			// ��Ů�ľ�
	set_skill("unarmed", 250+random(50));			// ����ȭ��
	set_skill("meinv_quan", 250+random(50));			// ��Ůȭ
	set_skill("dodge", 250+random(50));			// ��������
	set_skill("yunv_shenfa", 250+random(50));			// ��Ů��
	set_skill("parry", 250+random(50));			// �����м�
	set_skill("sword", 250+random(50));		        // ��������
	set_skill("yunv_jian", 250+random(50));			// ��Ů��
	set_skill("yunv_xinfa", 250+random(50));			// ��Ů�ķ�
	set_skill("tianluo_diwang", 250+random(50));		// ���޵���
	set_skill("quanzhen_jian", 250+random(50));		// ȫ�潣��

	map_skill("force", "yunv_xinjing");		//����NPC��ǰ�ڹ�Ϊ��Ů�ľ�
	map_skill("sword", "yunv_jian");	        //����NPC�Ļ�������װ����Ů��
	map_skill("dodge", "yunv_shenfa");		//����NPC�Ļ����Ṥװ����Ů��
	map_skill("parry", "yunv_jian");		//����NPC�Ļ����м�װ��ȫ�潣��
	map_skill("unarmed", "meinv_quan");		//����NPC�Ļ���ȭ��װ����Ůȭ


	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 30);			//����NPC���ӹ�����

	carry_object("changjian")->wield();	
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

LEV2_END;