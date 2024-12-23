// lev1_yaoyue.h ����
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_yaoyue);

virtual void create()
{
	set_name("����", "yao yue");
	set("title", "�仨����");
	set("gender", "Ů��");
	set("age", 40);
	set("level", 100);

	set("attitude", "friendly");		//����NPC̬��
	set("icon",2);				//������������
	set("repute", -5000);
	
	set("str", 21);
	set("int", 23);
	set("con", 23);
	set("dex", 21);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 1);			//����NPC��������
	
	set("combat_exp", 2100000+random(300000));
	set("score", 6000);
	
	set_skill("force", 210+random(30));			// �����ڹ�
	set_skill("shedao_qigong", 210+random(30));		// �ߵ�����
	set_skill("shenlong_xinfa", 210+random(30));		// �����ķ�
	set_skill("dodge", 210+random(30));			// ��������
	set_skill("yixingbu", 210+random(30));			// ���β�
	set_skill("shenlong_bashi", 210+random(30));		// ������ʽ
	set_skill("parry", 210+random(30));			// �����м�
	set_skill("strike", 210+random(30));		        // �����Ʒ�
	set_skill("huagu_mianzhang", 210+random(30));		// ��������

	map_skill("force", "shenlong_xinfa");		//����NPC��ǰ�ڹ�Ϊ�����ķ�
	map_skill("strike", "huagu_mianzhang");	        //����NPC�Ļ����Ʒ���װ����������
	map_skill("dodge", "yixingbu");			//����NPC�Ļ����Ṥװ�����β�
	map_skill("parry", "shenlong_bashi");		//����NPC�Ļ����м�װ��������ʽ

	prepare_skill("strike", "huagu_mianzhang");	//����NPC��ǰʹ�õļ���Ϊ�Ʒ����

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 60);			//����NPC���ӹ�����
	
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(3))
	{
	case 0:
		perform_action("parry meiren", 1);	//��������
		break;
        case 1:
			//�Զ�����
		break;
        case 2:
			//�Զ�����
		break;
	}	
	return 0;
}

LEV1_END;