// pub_xuaniu.h ��ţ
//jaja 2002-10-20

NPC_BEGIN(CNpub_xuaniu);

virtual void create()
{
	set_name("��ţ", "xu aniu");
	set("title", "ɵ��");
	set("gender", "����");
	set("age", 22);
	set("level", 100);
	set("long", 
		"������ٶ��ܶ�����üĿҲ�����㣬��ȴ�ִ���ĳ�־��ֳմ��ı��飬�ͺ���һ���ո��ܹ�ĳ�־޴󾪺���С����һ����\n");
	set("attitude", "peaceful");		//����NPC̬��
	set("icon",15);				//������������
	set("repute", 2000);
	
	set("str", 23);
	set("int", 23);
	set("con", 20);
	set("dex", 21);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 30);			//����NPC��������
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 250);			// �����ڹ�
	set_skill("yunv_xinjing", 250);			// ��Ů�ľ�
	set_skill("unarmed", 250);			// ����ȭ��
	set_skill("anranxiaohun_zhang", 250);		// ��Ȼ������
	set_skill("dodge", 250);			// ��������
	set_skill("xianyun_bufa", 250);			// ���Ʋ���
	set_skill("parry", 250);			// �����м�
	set_skill("sword", 250);		        // ��������
	set_skill("yunv_jian", 250);			// ��Ů��
	set_skill("yunv_xinfa", 250);			// ��Ů�ķ�
	set_skill("tianluo_diwang", 250);		// ���޵���
	set_skill("quanzhen_jian", 250);		// ȫ�潣��

	map_skill("force", "yunv_xinjing");		//����NPC��ǰ�ڹ�Ϊ��Ů�ľ�
	map_skill("sword", "yunv_jian");	        //����NPC�Ļ�������װ����Ů��
	map_skill("dodge", "xianyun_bufa");		//����NPC�Ļ����Ṧװ�����Ʋ���
	map_skill("parry", "quanzhen_jian");		//����NPC�Ļ����м�װ��ȫ�潣��
	map_skill("unarmed", "anranxiaohun_zhang");	//����NPC�Ļ���ȭ��װ����Ȼ������

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 30);			//����NPC���ӹ�����

	carry_object("sword_1")->wield();	
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
