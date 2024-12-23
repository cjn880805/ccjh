//pub_sangyuan.h ɣԭ����
//wjc 2002-02-24

NPC_BEGIN(CNpub_sangyuan);


virtual void create()
{
	set_name("ɣԭ��", "sang yuan");
	set("nickname", "ɣԭ");
	set("gender", "����");
	set("age", 19);
	set("long", "�����������Ǹ�������ʿ��üĿ��͸¶�������թ��");
	
	set("attitude", "peaceful");		//����NPC̬��
	set("icon",young_man3);			    //������������
	
	set("str", 35);
	set("int", 35);
	set("con", 35);
	set("dex", 42);
	
	set("chat_chance", 5);
	set("chat_chance_combat", 10);		 //����NPCʹ�þ��еļ���
	
	set("hp", 25500);
	set("max_hp", 25500);
	set("mp", 10000);
	set("max_mp", 10000);
	set("mp_factor", 80);
	
	set("combat_exp", 2000000);
	set("score", 50500);
	
	set_skill("force", 170);			      // �����ڹ�
	set_skill("jiuyang_shengong", 170);		  // ������
	set_skill("sword", 170);			      // ��������
	set_skill("lonely_sword", 170);		      // ���¾Ž�
	set_skill("dodge", 170);			      // ��������
	set_skill("shenkong_xing", 170);          // �����
	set_skill("parry", 170);			      // �����м�
	set_skill("hand",170);
	set_skill("strike", 170);
	set_skill("zhemei_shou",170);
	set_skill("liuyang_zhang",170);

	map_skill("strike","liuyang_zhang");
	map_skill("hand", "zhemei_shou");
	map_skill("parry", "liuyang_zhang");

	map_skill("force", "jiuyang_shengong");		//����NPC��ǰ�ڹ�Ϊ������
	map_skill("sword", "lonely_sword");	        //����NPC�Ļ�������װ�����¾Ž�
	map_skill("dodge", "shenkong_xing");		//����NPC�Ļ����Ṧװ�������
//	map_skill("parry", "lonely_sword");		    //����NPC�Ļ����м�װ�����¾Ž�

	prepare_skill("hand","zhemei_shou");
    prepare_skill("unarmed","liuyang_zhang");
	set("apply/armor", 150);
    set("apply/damage", 80);
	carry_object("changjian")->wield();
	
}

virtual char * chat_msg_combat()			    //NPC�Զ�������
{
	switch(random(5))
	{
	case 0:
		perform_action("sword pojian", 1);	    //���¾Ž��ľ���
		break;
	case 1:
		perform_action("force recover", 0);   	//�Զ�����
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
	DESTRUCT_OB(this, "pub_sangyuan::chat_msg");
	return 0;
}

NPC_END;



