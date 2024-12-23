// pub_lishenping.h ����ƽ
//jaja 2002-10-20

NPC_BEGIN(CNpub_lishenping);

virtual void create()
{
	set_name("����ƽ", "li shenping");
	set("title", "񲽣ħ");
	set("gender", "����");
	set("age", 52);
	set("level", 100);
	set("long", 
		"һ����ͷɢ���������ֳ����ˣ��������������ĳ������ʱ�ݷ��ѿ��ó�����ʱ��Ȼ���������˻����£�˭Ҳ�²������ȵ���ʲ����ʽ��\n");
	
	set("attitude", "peaceful");		//����NPC̬��
	set("icon",50);				//������������
	
	set("str", 22);
	set("int", 22);
	set("con", 22);
	set("dex", 22);
	
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
	set_skill("smithsword", 250);			// �����ؽ�ʽ
	set_skill("yunv_xinfa", 250);			// ��Ů�ķ�
	set_skill("tianluo_diwang", 250);		// ���޵���

	map_skill("force", "yunv_xinjing");		//����NPC��ǰ�ڹ�Ϊ��Ů�ľ�
	map_skill("sword", "smithsword");	        //����NPC�Ļ�������װ�������ؽ�ʽ
	map_skill("dodge", "xianyun_bufa");		//����NPC�Ļ����Ṥװ�����Ʋ���
	map_skill("parry", "smithsword");		//����NPC�Ļ����м�װ�������ؽ�ʽ
	map_skill("unarmed", "anranxiaohun_zhang");	//����NPC�Ļ���ȭ��װ����Ȼ������

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 40);			//����NPC���ӹ�����

	carry_object("changjian")->wield();	
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("sword flood", 1);	//�����ؽ�ʽ(flood������)
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
