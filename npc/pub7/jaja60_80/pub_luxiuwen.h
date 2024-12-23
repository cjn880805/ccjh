// lev1_luxiuwen.h ������
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_luxiuwen);

virtual void create()
{
	set_name("������", "lu xiuwen");
	set("title", "�ٽ�˫��");
	set("gender", "����");
	set("age", 22);
	set("level", 100);
	set("long", 
		"������ȥ�����ᣬ�Ǹ�����������˹�ĵ����꣬�����仪������ȴ������ϸ�׵�˫������һ����������١�\n");
	set("attitude", "friendly");		//����NPC̬��
	set("icon",16);				//������������
	set("repute", 5000);
	
	set("str", 22);
	set("int", 22);
	set("con", 22);
	set("dex", 22);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 1);			//����NPC��������
	
	set("combat_exp", 1500000+random(300000));
	set("score", 6000);
	
	set_skill("force", 190+random(30));			// �����ڹ�
	set_skill("wuzheng_xinfa", 190+random(30));		// �����ķ�
	set_skill("finger", 190+random(30));			// ����ָ��
	set_skill("xuantian_zhi", 190+random(30));			// ��������ָ
	set_skill("dodge", 190+random(30));			// ��������
	set_skill("qingfu_shenfa", 190+random(30));		// ������
	set_skill("parry", 190+random(30));			// �����м�
	set_skill("sword", 190+random(30));		        // ��������
	set_skill("wuyun_jianfa", 190+random(30));			// �������ҽ�

	map_skill("force", "wuzheng_xinfa");	//����NPC��ǰ�ڹ�Ϊ�����ķ�
	map_skill("sword", "wuyun_jianfa");	        //����NPC�Ļ�������װ���������ҽ�
	map_skill("dodge", "qingfu_shenfa");		//����NPC�Ļ�������װ��������
	map_skill("parry", "wuyun_jianfa");		//����NPC�Ļ����м�װ���������ҽ�
	map_skill("finger", "xuantian_zhi");		//����NPC�Ļ���ָ��װ����������ָ

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 50);			//����NPC���ӹ�����

	carry_object("changjian")->wield();

	prepare_skill("finger", "xuantian_zhi");
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
			//�Զ�����
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

