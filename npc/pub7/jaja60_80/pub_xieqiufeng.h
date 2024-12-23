// lev1_xieqiufeng.h л���
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_xieqiufeng);

virtual void create()
{
	set_name("л���", "xie qiufeng");
	set("title", "������");
	set("gender", "����");
	set("age", 27);
	set("level", 100);
	set("long", 
		"������ü��Ŀ�㣬Ц�������������һ����������У��������Ÿ��ƺ�«����һ��һ����������š�\n");
	set("attitude", "friendly");		//����NPC̬��
	set("icon",17);				//������������
	set("repute", 5000);
	
	set("str", 23);
	set("int", 23);
	set("con", 20);
	set("dex", 21);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 1);			//����NPC��������
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 190+random(30));			// �����ڹ�
	set_skill("hunyuan_yiqi", 190+random(30));			// ��Ԫһ����
	set_skill("finger", 190+random(30));			// ����ָ��
	set_skill("nianhua_zhi", 190+random(30));			// �黨ָ
	set_skill("dodge", 190+random(30));			// ��������
	set_skill("shaolin_shenfa", 190+random(30));		// ������
	set_skill("parry", 190+random(30));			// �����м�
	set_skill("club", 190+random(30));			        // ��������
	set_skill("zui_gun", 190+random(30));			// ���

	map_skill("force", "hunyuan_yiqi");		//����NPC��ǰ�ڹ�Ϊ��Ԫһ����
	map_skill("club", "zui_gun");	     		//����NPC�Ļ�������װ�����
	map_skill("dodge", "shaolin_shenfa");		//����NPC�Ļ�������װ��������
	map_skill("parry", "zui_gun");			//����NPC�Ļ����м�װ�����
	map_skill("finger", "nianhua_zhi");		//����NPC�Ļ���ָ��װ���黨ָ
	
	prepare_skill("finger", "nianhua_zhi");

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 10);			//����NPC���ӹ�����

	carry_object("mugun")->wield();	
	carry_object("jiudai");
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("whip zuida", 1);	//�������(zuida�������)
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
