// lev1_xieyulun.h л����
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_xieyulun);

virtual void create()
{
	set_name("л����", "xie yulun");
	set("title", "��������");
	set("gender", "����");
	set("age", 25);
	set("level", 100);
	set("long", 
		"������������ͷ������Ƥñ����������Ƥ�ã�һ��������ɫ�ģ�����˫�����Ƕ�һվ������֮�䣬�������ˡ�\n");
	set("attitude", "friendly");		//����NPC̬��
	set("icon",16);				//������������
	set("repute", 4000);
	
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
	set_skill("yunv_xinjing", 190+random(30));			// ��Ů�ľ�
	set_skill("unarmed", 190+random(30));			// ����ȭ��
	set_skill("anranxiaohun_zhang", 190+random(30));		// ��Ȼ������
	set_skill("dodge", 190+random(30));			// ��������
	set_skill("xianyun_bufa", 190+random(30));			// ���Ʋ���
	set_skill("parry", 190+random(30));			// �����м�
	set_skill("sword", 190+random(30));		        // ��������
	set_skill("yunv_jian", 190+random(30));			// ��Ů��
	set_skill("yunv_xinfa", 190+random(30));			// ��Ů�ķ�
	set_skill("tianluo_diwang", 190+random(30));		// ���޵���
	set_skill("quanzhen_jian", 190+random(30));		// ȫ�潣��

	map_skill("force", "yunv_xinjing");		//����NPC��ǰ�ڹ�Ϊ��Ů�ľ�
	map_skill("sword", "yunv_jian");	        //����NPC�Ļ�������װ����Ů��
	map_skill("dodge", "xianyun_bufa");		//����NPC�Ļ����Ṧװ�����Ʋ���
	map_skill("parry", "quanzhen_jian");		//����NPC�Ļ����м�װ��ȫ�潣��
	map_skill("unarmed", "anranxiaohun_zhang");	//����NPC�Ļ���ȭ��װ����Ȼ������

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 10);			//����NPC���ӹ�����

	carry_object("baipao");	
	carry_object("changjian")->wield();	
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("sword he", 1);		//��Ů����˫���ϱ�
		break;
	case 1:
		perform_action("unarmed xiaohun", 1);	//��Ȼ����
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
