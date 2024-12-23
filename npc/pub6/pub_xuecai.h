//pub_xuecai.h ѩ��
//wjc 2002-02-24

NPC_BEGIN(CNpub_xuecai);

virtual void create()
{
	set_name("ѩ��", "xue cai");
	set("nickname", "��Ů");
	set("gender", "Ů��");
	set("age", 16);
	set("long", "����ȥ��һ�������ܵ����۵��ˡ�");
	
	set("attitude", "peaceful");		//����NPC̬��
	set("icon",young_woman3);			//������������
	
	set("str", 25);
	set("int", 25);
	set("con", 30);
	set("dex", 30);
	
	set("chat_chance", 5);			    //�����Զ����촥����
	set("chat_chance_combat", 10);		//����NPCʹ�þ��еļ���
	
	set("hp", 13000);
	set("max_hp", 13000);
	set("mp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 40);
	
	set("combat_exp", 1200000);
	set("score", 50000);
	
	set_skill("force", 170);			// �����ڹ�
	set_skill("yunv_xinjing", 170);		// ��Ů�ľ�
	set_skill("hand", 170);			    // �����ַ�
	set_skill("lanhua_shou", 170);		// ������Ѩ��
	set_skill("dodge", 170);			// ��������
	set_skill("lingboweibu", 170);      // �貨΢��
	set_skill("parry", 170);			// �����м�
	
	map_skill("force", "yunv_xinjing");		//����NPC��ǰ�ڹ�Ϊ��Ů�ľ�
	map_skill("hand", "lanhua_shou");	    //����NPC�Ļ����ַ�װ��������Ѩ��
	map_skill("dodge", "lingboweibu");		//����NPC�Ļ����Ṧװ���貨΢��
	map_skill("parry", "lanhua_shou");		//����NPC�Ļ����м�װ��������Ѩ��

	prepare_skill("hand", "lanhua_shou");
	set("apply/armor", 100);
    set("apply/damage", 50);
	
}

char * chat_msg()
{
	message_vision("$N���������ڣ����ƻ��Ƶ�ԶԶ��ȥ��", this);
	DESTRUCT_OB(this, "pub_xuecai::chat_msg");
	return 0;
}

virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(5))
	{
	case 0:
		perform_action("hand fuxue", 1);	//������Ѩ�ֵľ���
		break;
	case 1:
		perform_action("force recover", 0);	//�Զ�����
		break;
	
	}	
	return 0;
}
virtual void die()
{
	message_vision("$HIR������ֵ��ǣ����ȳ�����", this);
	destruct(this);
}
NPC_END;




