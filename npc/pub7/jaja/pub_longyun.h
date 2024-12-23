// pub_longyun.h ����
//dieer 2002-7-21

NPC_BEGIN(CNpub_longyun);

virtual void create()
{
	set_name("����", "long yun");
	set("title", "��������");
	set("gender", "����");
	set("age", 35);
	set("level", 157);
	set("long", 
		"�������ǳ��������������ư������������ү��ˮ��֮�ߣ����ϵ�һ����˵��һ��������ˮ��Ǳ����������ҹ��û���˿�������������\n");
	set("attitude", "peaceful");		//����NPC̬��
	set("icon",15);				//������������
	
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("chat_chance_combat", 25);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 40000);
	set("max_mp", 10000);
	set("mp_factor", 80);			//����NPC��������
	
	set("combat_exp", 60000000);
	set("score", 6000);
	
	set_skill("force", 350);			// �����ڹ�
	set_skill("shedao_qigong", 350);		// �ߵ�����
	set_skill("shenlong_xinfa", 350);		// �����ķ�
	set_skill("dodge", 350);			// ��������
	set_skill("yixingbu", 350);			// ���β�
	set_skill("shenlong_bashi", 350);		// ������ʽ
	set_skill("parry", 350);			// �����м�
	set_skill("strike", 350);		        // �����Ʒ�
	set_skill("huagu_mianzhang", 350);		// ��������

	map_skill("force", "shenlong_xinfa");		//����NPC��ǰ�ڹ�Ϊ�����ķ�
	map_skill("strike", "huagu_mianzhang");	        //����NPC�Ļ����Ʒ���װ����������
	map_skill("dodge", "yixingbu");			//����NPC�Ļ����Ṥװ�����β�
	map_skill("parry", "shenlong_bashi");		//����NPC�Ļ����м�װ��������ʽ

	prepare_skill("strike", "huagu_mianzhang");	//����NPC��ǰʹ�õļ���Ϊ�Ʒ����

	set("apply/armor", 160);			//����NPC���ӷ�����
	set("apply/damage", 80);			//����NPC���ӹ�����
	
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(3))
	{
	case 0:
		perform_action("parry yingxiong", 1);	//Ӣ����ʽ
		break;
        case 1:
		perform_action("force recover", 0);	//�Զ�����
		break;
        case 2:
		perform_action("force recover", 0);	//�Զ�����
		break;
	}	
	return 0;
}

NPC_END;
