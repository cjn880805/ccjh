//pub_wangmu.h
//wuqing 2002-2-10 

NPC_BEGIN(CNpub_wangmu);

virtual void create()
{
	set_name("��ľ","wang mu");
	set("long", "���ִ���ٲƺ�ɫΪ�����������ݡ�");
	set("gender", "����");
	set("age", 80);
	
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("icon",taoist);	
	set("title","���");
	set("hp", 10000);
	set("max_hp", 10000);
	set("mp", 8000);
	set("max_mp", 5000);
	set("mp_force", 40);
	set("combat_exp", 120000);
	set("score", 1200000);

	set_skill("force", 170);
	set_skill("taiji_shengong", 170);
	set_skill("dodge", 170);
	set_skill("tiyunzong", 170);
	set_skill("unarmed", 170);
	set_skill("taiji_quan", 170);
	set_skill("parry", 170);
	set_skill("sword", 170);
	set_skill("taiji_jian", 170);
	
	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji_quan");
	map_skill("parry", "taiji_jian");
	map_skill("sword", "taiji_jian");	

	set("class", "taoist");
    set("apply/armor", 100);
	set("apply/damage", 50);
	set("chat_chance", 5);
	set("chat_chance_combat", 60);
	carry_object("changjian")->wield();
}

virtual char * chat_msg_combat(CChar * player)
{
	switch(random(4))
	{
	case 0:
		perform_action("sword lian", 1);
		break;
	case 1:
		perform_action("sword chan", 1);
		break;
	case 2:
		perform_action("sword sui", 1);
		break;
	case 3:
		perform_action("force recover",0);
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
	DESTRUCT_OB(this, "pub_wangmu::chat_msg");
	return 0;
}
NPC_END;



