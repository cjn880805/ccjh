// pub_xiuzhoucike.h ���ݴ̿�
// dieer 2002-8-10

NPC_BEGIN(CNpub_xiuzhoucike);

virtual void create()
{
	set_name("���ݴ̿�", "xiuzhou cike");
	set("title", "��ʮ������֮");
	set("gender", "����");
	set("age", 30);
	set("level", 157);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",17);				//������������
	set("per",23);
	
	set("str", 38);
	set("int", 31);
	set("con", 34);
	set("dex", 32);
	
	set("chat_chance_combat", 10);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("mp_factor", 50);			//����NPC��������
	
	set("combat_exp", 40000000+random(20000000));
	set("score", 6000);

	set_skill("force", 350);			// �����ڹ�
	set_skill("kurong_changong", 350);		// ��������
	set_skill("dodge", 350);			// ��������
	set_skill("tiannan_step", 350);			// ���ϲ���
	set_skill("parry", 350);			// �����м�
	set_skill("finger", 350);		        // ����ָ��
	set_skill("liumai_shenjian", 350);		// ������

	map_skill("force", "kurong_changong");		//����NPC��ǰ�ڹ�Ϊ��������
	map_skill("dodge", "tiannan_step");		//����NPC�Ļ�������װ�����ϲ���
	map_skill("parry", "liumai_shenjian");		//����NPC�Ļ����м�װ��������
	map_skill("finger", "liumai_shenjian");		//����NPC�Ļ���ָ��װ��������

	set("apply/armor", 160);			//����NPC���ӷ�����
	set("apply/damage", 80);			//����NPC���ӹ�����

	prepare_skill("finger", "liumai_shenjian");

}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("finger ci", 1);		//������(ci��)
		break;
	case 1:
		perform_action("finger feng", 1);	//������(feng��)
		break;
	case 2:
		perform_action("finger tan", 1);	//������(tan��)
		break;
	case 3:
		perform_action("finger guiyi", 1);	//������(guiyi������һ)
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
