// pub_simingtoutuo.h ����ͷ��
// dieer 2002-8-5

NPC_BEGIN(CNpub_simingtoutuo);

virtual void create()
{
	set_name("����ͷ��", "siming toutuo");
	set("title", "��ʮ������֮");
	set("gender", "����");
	set("age", 40);
	set("level", 157);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",20);				//������������
	set("per",15);
	set("repute", 10000);
	
	set("str", 36);
	set("int", 23);
	set("con", 30);
	set("dex", 35);
	
	set("chat_chance_combat", 10);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("mp_factor", 80);			//����NPC��������
	
	set("combat_exp", 40000000+random(20000000));
	set("score", 6000);
	
	set_skill("force", 350);			// �����ڹ�
	set_skill("hunyuan_yiqi", 350);			// ��Ԫһ����
	set_skill("finger", 350);			// ����ָ��
	set_skill("nianhua_zhi", 350);			// �黨ָ
	set_skill("dodge", 350);			// ��������
	set_skill("shaolin_shenfa", 350);		// ������
	set_skill("parry", 350);			// �����м�
	set_skill("sword", 350);			// ��������
	set_skill("wuying_jian", 350);			// ��Ӱ��

	map_skill("force", "hunyuan_yiqi");		//����NPC��ǰ�ڹ�Ϊ��Ԫһ����
	map_skill("sword", "wuying_jian");	        //����NPC�Ļ�������װ����Ӱ��
	map_skill("dodge", "shaolin_shenfa");		//����NPC�Ļ�������װ��������
	map_skill("parry", "wuying_jian");		//����NPC�Ļ����м�װ����Ӱ��
	map_skill("finger", "nianhua_zhi");		//����NPC�Ļ���ָ��װ���黨ָ

	set("apply/armor", 160);			//����NPC���ӷ�����
	set("apply/damage", 80);			//����NPC���ӹ�����

//	prepare_skill("whip", "riyue_bian");		//����NPC����Ϲ���
//	prepare_skill("finger", "nianhua_zhi");

	carry_object("changjian")->wield();	
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("sword wuying", 1);	//��Ӱ��(wuying������Ӱ)
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
