// lev1_zongjinquan.h �ӽ�ȫ
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_zongjinquan);

virtual void create()
{
	set_name("�ӽ�ȫ", "zong jinquan");
	set("title", "������ؤ");
	set("gender", "����");
	set("age", 60);
	set("level", 100);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",50);				//������������
	
	set("str", 21);
	set("int", 23);
	set("con", 23);
	set("dex", 21);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 1);			//����NPC��������
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 190+random(30));			// �����ڹ�
	set_skill("huntian_qigong", 190+random(30));		// ��������
	set_skill("strike", 190+random(30));			// �����Ʒ�
	set_skill("xianglong_zhang", 190+random(30));		// ����ʮ����
	set_skill("dodge", 190+random(30));			// ��������
	set_skill("xiaoyaoyou", 190+random(30));			// ��ң��
	set_skill("parry", 190+random(30));			// �����м�
	set_skill("claw", 190+random(30));		      		// ����צ��
	set_skill("jiuyin_zhua", 190+random(30));			// �����׹�צ
	set_skill("staff", 190+random(30));			// �����ȷ�
	set_skill("dagou_bang", 190+random(30));			// �򹷰���


	map_skill("force", "huntian_qigong");		//����NPC��ǰ�ڹ�Ϊ��������
	map_skill("claw", "jiuyin_zhua");	        //����NPC�Ļ���צ��װ�������׹�צ
	map_skill("dodge", "xiaoyaoyou");		//����NPC�Ļ�������װ����ң��
	map_skill("parry", "jiuyin_zhua");		//����NPC�Ļ����м�װ�������׹�צ
	map_skill("strike", "xianglong_zhang");		//����NPC�Ļ����Ʒ�װ������ʮ����
	map_skill("staff", "dagou_bang");		//����NPC�Ļ����ȷ�װ���򹷰���

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 20);			//����NPC���ӹ�����

	prepare_skill("claw", "jiuyin_zhua");		//����NPC�Ŀ������
	prepare_skill("strike", "xianglong_zhang");

	carry_object("gangzhang")->wield();	
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("claw zhua", 1);		//�����׹�צ��������һ��
		break;
	case 1:
		perform_action("strike leiting", 1);	//����ʮ���ƾ�������һ��
		break;
	case 2:
		perform_action("strike xianglong", 1);	//����ʮ���ƾ��н�����
		break;
	case 3:
		perform_action("staff zhuang", 1);	//�򹷰�(zhuangǧ���׹�)
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