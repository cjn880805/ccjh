// lev1_kongchan.h ������ʦ
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_kongchan);

virtual void create()
{
	set_name("������ʦ", "kong chan");
	set("title", "����������");
	set("gender", "����");
	set("age", 80);
	set("level", 100);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",27);				//������������
	set("repute", 6000);
	
	set("str", 27);
	set("int", 20);
	set("con", 20);
	set("dex", 21);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 1);			//����NPC��������
	
	set("combat_exp", 2000000+random(300000));
	set("score", 6000);
	
	set_skill("force", 210+random(30));			// �����ڹ�
	set_skill("hunyuan_yiqi", 210+random(30));			// ��Ԫһ����
	set_skill("finger", 210+random(30));			// ����ָ��
	set_skill("nianhua_zhi", 210+random(30));			// �黨ָ
	set_skill("dodge", 210+random(30));			// ��������
	set_skill("shaolin_shenfa", 210+random(30));		// ������
	set_skill("parry", 210+random(30));			// �����м�
	set_skill("whip", 210+random(30));			        // �����޷�
	set_skill("riyue_bian", 210+random(30));			// ���±޷�

	map_skill("force", "hunyuan_yiqi");		//����NPC��ǰ�ڹ�Ϊ��Ԫһ����
	map_skill("whip", "riyue_bian");	        //����NPC�Ļ����޷�װ�����±޷�
	map_skill("dodge", "shaolin_shenfa");		//����NPC�Ļ�������װ��������
	map_skill("parry", "riyue_bian");		//����NPC�Ļ����м�װ�����±޷�
	map_skill("finger", "nianhua_zhi");		//����NPC�Ļ���ָ��װ���黨ָ

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 40);			//����NPC���ӹ�����

	prepare_skill("finger", "nianhua_zhi");		//����NPC����Ϲ���

	carry_object("changbian")->wield();
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("whip chan", 1);		//���±޷����в��ƾ�
		break;
	case 1:
		perform_action("finger foxue", 1);	//�黨ָ�����黨��Ѩ
		break;
	case 2:
		perform_action("force roar", 1);	//��Ԫһ��������ʨ�Ӻ�
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
