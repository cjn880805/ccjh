// pub_hongxian.h ����
// dieer 2002-7-27

NPC_BEGIN(CNpub_hongxian);

virtual void create()
{
	set_name("����", "hong xian");
	set("title", "��ʮ������֮");
	set("gender", "Ů��");
	set("age", 19);
	set("level", 157);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",3);				//������������
	set("per",39);
	set("repute", 10000);
	
	set("str", 32);
	set("int", 39);
	set("con", 32);
	set("dex", 37);
	
	set("chat_chance_combat", 30);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("mp_factor", 70);			//����NPC��������
	
	set("combat_exp", 40000000+random(20000000));
	set("score", 6000);
	
	set_skill("force", 350);			// �����ڹ�
	set_skill("bibo_shengong", 350);		// �̲���
	set_skill("finger", 350);			// ����ָ��
	set_skill("tanzhi_shentong", 350);		// ��ָ��ͨ
	set_skill("dodge", 350);			// ��������
	set_skill("anying_fuxiang", 350);		// ��Ӱ����
	set_skill("parry", 350);			// �����м�
	set_skill("sword", 350);		        // ��������
	set_skill("yuxiao_jianfa", 350);		// ��������

	map_skill("force", "bibo_shengong");		//����NPC��ǰ�ڹ�Ϊ�̲���
	map_skill("sword", "yuxiao_jianfa");	        //����NPC�Ļ�������װ����������
	map_skill("dodge", "anying_fuxiang");		//����NPC�Ļ�������װ����Ӱ����
	map_skill("parry", "yuxiao_jianfa");		//����NPC�Ļ����м�װ����������
	map_skill("finger", "tanzhi_shentong");		//����NPC�Ļ���ָ��װ����ָ��ͨ

	set("apply/armor", 160);			//����NPC���ӷ�����
	set("apply/damage", 60);			//����NPC���ӹ�����

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
		perform_action("force powerup", 0);	//�Զ�����
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
