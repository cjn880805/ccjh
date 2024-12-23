// pub_qiufengcheng.h ����
//jaja 2002-10-20

NPC_BEGIN(CNpub_qiufengcheng);

virtual void create()
{
	set_name("����", "qiu fengcheng");
	set("title", "��ǹ����");
	set("gender", "����");
	set("age", 26);
	set("level", 100);
	set("long", 
		"�����ᡢ�������ߴ�Ӣ����������һ�ֽ������õ����ʡ������ϴ�����һϮ��ֵǧ������ã��������Ź⻪��Ŀ����ǹ��ǹ���Ǵ����ġ�\n");
	set("attitude", "friendly");		//����NPC̬��
	set("icon",18);				//������������
	set("repute", 3000);
	
	set("str", 23);
	set("int", 21);
	set("con", 21);
	set("dex", 22);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 30);			//����NPC��������
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 250);			// �����ڹ�
	set_skill("taixuan_gong", 250);		// ���͵�̫����
	set_skill("unarmed", 250);			// ����ȭ��
	set_skill("changquan", 250);		// ��ȭ
	set_skill("dodge", 250);			// ��������
	set_skill("shenxing_baibian", 250);		// ���аٱ�
	set_skill("parry", 250);			// �����м�
	set_skill("club", 250);		        // ��������
	set_skill("zhongpingqiang", 250);		// ��ƽǹ��

	map_skill("force", "taixuan_gong");		//����NPC��ǰ�ڹ�Ϊ���͵�̫����
	map_skill("club", "zhongpingqiang");	        //����NPC�Ļ�������װ����ƽǹ��
	map_skill("dodge", "shenxing_baibian");		//����NPC�Ļ����Ṧװ�����аٱ�
	map_skill("parry", "zhongpingqiang");		//����NPC�Ļ����м�װ����ƽǹ��
	map_skill("unarmed", "changquan");		//����NPC�Ļ���ȭ��װ����ȭ

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 30);			//����NPC���ӹ�����

	carry_object("doupeng");	
	carry_object("changqiang")->wield();	
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("force recover", 0);	//�Զ�����
		break;
	case 1:
		perform_action("force recover", 0);	//�Զ�����
		break;
	case 2:
		perform_action("force recover", 0);	//�Զ�����
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
