// lev1_shentinkang.h ��ͥ��
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_shentinkang);

virtual void create()
{
	set_name("��ͥ��", "shen tinkang");
	set("title", "������ն");
	set("gender", "����");
	set("age", 40);
	set("level", 100);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",15);				//������������
	
	set("str", 23);
	set("int", 21);
	set("con", 21);
	set("dex", 22);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 1);			//����NPC��������
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 190+random(30));			// �����ڹ�
	set_skill("hunyuan_yiqi", 190+random(30));			// ��Ԫһ����
	set_skill("sword", 190+random(30));			// ��������
	set_skill("zhanjiang_jue", 190+random(30));		// ն����
	set_skill("dodge", 190+random(30));			// ��������
	set_skill("shaolin_shenfa", 190+random(30));		// ������
	set_skill("parry", 190+random(30));			// �����м�
	set_skill("unarmed", 190+random(30));		        // ����ȭ��
	set_skill("jingang_quan", 190+random(30));			// ����ȭ

	map_skill("force", "hunyuan_yiqi");		//����NPC��ǰ�ڹ�Ϊ��Ԫһ����
	map_skill("unarmed", "jingang_quan");	        //����NPC�Ļ���ȭ��װ������ȭ
	map_skill("dodge", "shaolin_shenfa");		//����NPC�Ļ�������װ��������
	map_skill("parry", "yizhi_chan");		//����NPC�Ļ����м�װ��һָ��
	map_skill("sword", "zhanjiang_jue");		//����NPC�Ļ�������װ��ն����

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 10);			//����NPC���ӹ�����

	carry_object("changjian")->wield();		//����NPCװ������Ʒ

}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
			//�Զ�����
		break;
	case 1:
		perform_action("force roar", 1);	//��Ԫһ��������ʨ�Ӻ�
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
