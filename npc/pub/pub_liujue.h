//pub_liujue.h
//wuqing 2002-2-10 

NPC_BEGIN(CNpub_liujue);

virtual void create()
{
	set_name("刘绝","liu jue");
	set("long", "武当弃徒，虽说武林人士不停的追杀他，却因为剑法极高屡屡逃脱。");
	set("gender", "男性");
	set("age", 80);
	
	set("str", 40);
	set("int", 40);
	set("con", 40);
	set("dex", 40);
	set("icon",taoist);	
	set("title","夺命剑");
	set("max_hp", 30000);
	set("mp", 10000);
	set("max_mp", 10000);
	set("mp_force", 200);
	set("combat_exp", 3000000);
	set("score", 1200000);

	set_skill("force", 300);
	set_skill("taiji_shengong", 300);
	set_skill("dodge", 300);
	set_skill("tiyunzong", 300);
	set_skill("unarmed", 350);
	set_skill("taiji_quan", 350);
	set_skill("parry", 300);
	set_skill("sword", 300);
	set_skill("taiji_jian", 300);
	set_skill("blade", 300);
	set_skill("taiji_dao", 300);
	set_skill("taoism", 350);
	set_skill("literate", 300);

	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji_quan");
	map_skill("parry", "taiji_jian");
	map_skill("sword", "taiji_jian");
	map_skill("blade", "taiji_dao");

	
	set("class", "taoist");
    set("apply/armor", 300);
	set("apply/damage", 200);
	set("chat_chance_combat", 60);
	set("no_kill",1);//不被列入万劫谷的任务中
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
NPC_END;



