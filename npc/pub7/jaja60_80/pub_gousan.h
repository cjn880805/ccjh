// lev1_gousan.h ����
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_gousan);

virtual void create()
{
	set_name("����", "gou san");
	set("title", "�w������");
	set("gender", "����");
	set("age", 22);
	set("level", 100);
	set("long", 
		"�����Ǻw�����ֵ�����С��һ����Ϊ�˼��ս�թ�����ֵ������ѿC�ľ�������\n");
	set("attitude", "peaceful");		//����NPC̬��
	set("icon",43);				//������������
	set("repute", -5000);
	
	set("str", 24);
	set("int", 20);
	set("con", 23);
	set("dex", 20);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 1);			//����NPC��������
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 190+random(30));			// �����ڹ�
	set_skill("hamagong", 190+random(30));			// ��󡹦
	set_skill("hand", 190+random(30));			// �����ַ�
	set_skill("shexing_diaoshou", 190+random(30));			// ���ε���
	set_skill("dodge", 190+random(30));			// ��������
	set_skill("chanchu_bufa", 190+random(30));			// ��ܲ���
	set_skill("parry", 190+random(30));			// �����м�
	set_skill("staff", 190+random(30));		        // �����ȷ�
	set_skill("lingshe_zhangfa", 190+random(30));		// �����ȷ�
	set_skill("quanzhen_jian", 190+random(30));		// ȫ�潣��

	map_skill("force", "hamagong");			//����NPC��ǰ�ڹ�Ϊ��󡹦
	map_skill("staff", "lingshe_zhangfa");	        //����NPC�Ļ����ȷ�װ�������ȷ�
	map_skill("dodge", "chanchu_bufa");		//����NPC�Ļ����Ṧװ����ܲ���
	map_skill("parry", "lingshe_zhangfa");		//����NPC�Ļ����м�װ�������ȷ�
	map_skill("hand", "shexing_diaoshou");		//����NPC�Ļ����ַ�װ�����ε���

	prepare_skill("hand", "shexing_diaoshou");

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 10);			//����NPC���ӹ�����

	carry_object("gangzhang")->wield();	
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("staff pili", 1);	//�����ȷ�(��������)
		break;
	case 1:
			//�Զ�����
		break;
	case 2:
			//�Զ�����
		break;
	case 3:
			//�Զ�����
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