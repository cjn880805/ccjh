// pub_sixinzhe.h ������
// dieer 2002-8-10

NPC_BEGIN(CNpub_sixinzhe);

virtual void create()
{
	set_name("������", "si xinzhe");
	set("title", "��ʮ������֮");
	set("gender", "����");
	set("age", 30);
	set("level", 157);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",28);				//������������
	set("per",20);
	set("repute", 10000);
	
	set("str", 32);
	set("int", 37);
	set("con", 33);
	set("dex", 31);
	
	set("chat_chance_combat", 10);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("mp_factor", 50);			//����NPC��������
	
	set("combat_exp", 40000000+random(20000000));
	set("score", 6000);

	set_skill("force", 350);			// �����ڹ�
	set_skill("hunyuan_yiqi", 350);			// ��Ԫһ����
	set_skill("finger", 350);			// ����ָ��
	set_skill("yizhi_chan", 350);			// һָ��
	set_skill("dodge", 350);			// ��������
	set_skill("shaolin_shenfa", 350);		// ������
	set_skill("parry", 350);			// �����м�
	set_skill("unarmed", 350);		        // ����ȭ��
	set_skill("jingang_quan", 350);			// ����ȭ

	map_skill("force", "hunyuan_yiqi");		//����NPC��ǰ�ڹ�Ϊ��Ԫһ����
	map_skill("unarmed", "jingang_quan");	        //����NPC�Ļ���ȭ��װ������ȭ
	map_skill("dodge", "shaolin_shenfa");		//����NPC�Ļ�������װ��������
	map_skill("parry", "yizhi_chan");		//����NPC�Ļ����м�װ��һָ��
	map_skill("finger", "yizhi_chan");		//����NPC�Ļ���ָ��װ��һָ��

	set("apply/armor", 160);			//����NPC���ӷ�����
	set("apply/damage", 120);			//����NPC���ӹ�����

	prepare_skill("unarmed", "jingang_quan");	//����NPC����Ϲ���
	prepare_skill("finger", "yizhi_chan");
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("finger dian", 1);	//һָ��(dian���־�)
		break;
	case 1:
		perform_action("finger jingmo", 1);	//һָ��(jingmo��ħһָ)
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
