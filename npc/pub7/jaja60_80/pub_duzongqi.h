// lev1_duzongqi.h ������
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_duzongqi);

virtual void create()
{
	set_name("������", "du zongqi");
	set("title", "���Ǳ�");
	set("gender", "����");
	set("age", 60);
	set("level", 100);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",19);				//������������
	set("repute", 5000);
	
	set("str", 25);
	set("int", 21);
	set("con", 20);
	set("dex", 20);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 1);			//����NPC��������
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 190+random(30));			// �����ڹ�
	set_skill("yunlong_shengong", 190+random(30));		// ������
	set_skill("hand", 190+random(30));			// �����ַ�
	set_skill("yunlong_shou", 190+random(30));		// ������
	set_skill("dodge", 190+random(30));			// ��������
	set_skill("yunlong_shenfa", 190+random(30));		// ������
	set_skill("parry", 190+random(30));			// �����м�
	set_skill("whip", 190+random(30));		        // �����޷�
	set_skill("yunlong_bian", 190+random(30));		// �����޷�

	map_skill("force", "yunlong_shengong");		//����NPC��ǰ�ڹ�Ϊ������
	map_skill("whip", "yunlong_bian");	        //����NPC�Ļ����޷�װ�������޷�
	map_skill("dodge", "yunlong_shenfa");		//����NPC�Ļ����Ṧװ��������
	map_skill("parry", "yunlong_bian");		//����NPC�Ļ����м�װ���������޷�
	map_skill("hand", "yunlong_shou");		//����NPC�Ļ����ַ�װ��������

	prepare_skill("hand", "yunlong_shou");	//����NPC�Ŀ�����ȫ

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 10);			//����NPC���ӹ�����

	carry_object("changbian")->wield();	
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("whip chan", 1);	//�����޷�(chan���־�)
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
