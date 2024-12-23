// lev1_diaoer.h ���
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_diaoer);

virtual void create()
{
	set_name("���", "diao er");
	set("title", "�w���϶�");
	set("gender", "����");
	set("age", 24);
	set("level", 100);
	set("long", 
		"�����Ǻw�����ֵ��е��϶���һ˫�ȳ���ĳ���վ���Ƕ���������ϸ�������ӡ�\n");
	set("attitude", "peaceful");		//����NPC̬��
	set("icon",43);				//������������
	set("repute", -5000);
	
	set("str", 20);
	set("int", 24);
	set("con", 21);
	set("dex", 26);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 1);			//����NPC��������
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 190+random(30));			// �����ڹ�
	set_skill("bibo_shengong", 190+random(30));		// �̲���
	set_skill("finger", 190+random(30));			// ����ָ��
	set_skill("tanzhi_shentong", 190+random(30));		// ��ָ��ͨ
	set_skill("dodge", 190+random(30));			// ��������
	set_skill("anying_fuxiang", 190+random(30));		// ��Ӱ����
	set_skill("parry", 190+random(30));			// �����м�
	set_skill("sword", 190+random(30));		        // ��������
	set_skill("yuxiao_jianfa", 190+random(30));		// ��������
	set_skill("xuanfeng_leg", 190+random(30));			// ����ɨҶ��

	map_skill("force", "bibo_shengong");		//����NPC��ǰ�ڹ�Ϊ�̲���
	map_skill("sword", "yuxiao_jianfa");	        //����NPC�Ļ�������װ����������
	map_skill("dodge", "anying_fuxiang");		//����NPC�Ļ�������װ����Ӱ����
	map_skill("parry", "xuanfeng_leg");		//����NPC�Ļ����м�װ������ɨҶ��
	map_skill("finger", "tanzhi_shentong");		//����NPC�Ļ���ָ��װ����ָ��ͨ

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 10);			//����NPC���ӹ�����
	
	prepare_skill("finger", "tanzhi_shentong");

	carry_object("changjian")->wield();	
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("sword hua", 1);		//�������������ƺ�����
		break;
	case 1:
		perform_action("finger hui", 1);	//��ָ��ͨ���лӳⷽ��
		break;
	case 2:
		perform_action("finger jinglei", 1);	//��ָ��ͨ���е�ָ����
		break;
	case 3:
		perform_action("parry kuangfeng", 1);	//����ɨҶ��(������)
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
