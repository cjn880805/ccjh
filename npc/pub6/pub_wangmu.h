//pub_wangmu.h
//wuqing 2002-2-10 

NPC_BEGIN(CNpub_wangmu);

virtual void create()
{
	set_name("王木","wang mu");
	set("long", "绿林大盗劫财好色为武林人所不齿。");
	set("gender", "男性");
	set("age", 80);
	
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("icon",taoist);	
	set("title","恶道");
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
	message_vision("$HIR风紧，兄弟们，我先扯乎！", this);
	destruct(this);
}

char * chat_msg()
{
	message_vision("$N吹了声口哨，晃悠晃悠的远远离去。", this);
	DESTRUCT_OB(this, "pub_wangmu::chat_msg");
	return 0;
}
NPC_END;



