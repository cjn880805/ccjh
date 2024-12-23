//pub_feiying.h ��Ӱ
//wjc 2002-02-24

NPC_BEGIN(CNpub_feiying);


virtual void create()
{
	set_name("��Ӱ", "fei ying");
	set("gender", "����");
	set("age", 19);
	set("long", "ҹ����");
	
	set("attitude", "peaceful");		//����NPC̬��
	set("icon",young_man4);			    //������������
	
	set("str", 35);
	set("int", 34);
	set("con", 34);
	set("dex", 40);

	set("chat_chance", 5);
	set("chat_chance_combat", 10);		 //����NPCʹ�þ��еļ���
	
	set("hp", 15000);
	set("max_hp", 15000);
	set("mp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 50);
	
	set("combat_exp", 1600000);
	set("score", 50000);
	
	set_skill("force", 170);			    // �����ڹ�
	set_skill("huntian_qigong", 170);		// ��������
	set_skill("unarmed", 170);			    // ����ȭ��
	set_skill("xianglong_zhang", 170);		// ����ʮ����
	set_skill("dodge", 170);			    // ��������
	set_skill("guimei_shenfa", 170);		// ������
	set_skill("parry", 170);			    // �����м�
	
	map_skill("force", "huntian_qigong");		//����NPC��ǰ�ڹ�Ϊ��������
	map_skill("unarmed", "xianglong_zhang");	//����NPC�Ļ���ȭ��װ��������
	map_skill("dodge", "guimei_shenfa");		//����NPC�Ļ����Ṧװ��������
	map_skill("parry", "xianglong_zhang");		//����NPC�Ļ����м�װ��������

	set("apply/armor", 100);
    set("apply/damage", 40);
	prepare_skill("unarmed","xianglong_zhang");
	
}


virtual char * chat_msg_combat()			    //NPC�Զ�������
{
	switch(random(5))
	{
	case 0:
		perform_action("unarmed xianglong", 1);	//�����Ƶľ���
		break;
	case 1:
		perform_action("force recover", 0);	    //�Զ�����
		break;
	
	}	
	return 0;
}

virtual void die()
{
	message_vision("$HIR������ֵ��ǣ����ȳ�����", this);
	destruct(this);
}

char * chat_msg()
{
	message_vision("$N���������ڣ����ƻ��Ƶ�ԶԶ��ȥ��", this);
	DESTRUCT_OB(this, "pub_feiying::chat_msg");
	return 0;
}

NPC_END;




