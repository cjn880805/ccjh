//scavenger.h
//Teapot 2000-01-05

NPC_BEGIN(CNpub_scavenger);

virtual void create()
{
	set_name("四方巡回使者", "Scavenger");
	set("long", "他一身飘逸的白色长衫，长的很像传说中的旺财。");
	set("title", "[垃圾帮]");
	set("gender", "男性");
	set("age", 27);
	set("per", 5);
	set("attitude", "friendly");
	set("icon", young_man3);

	set("chat_chance", 5);
	set("no_huan",1);
};

virtual char * chat_msg()
{
	random_move();
	return 0;
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if (!ob->query("pub_rubbish"))
		return 0;

	int i;
	i=ob->query("valued");
	char msg[255];
	who->add("combat_exp",i);
	message_vision(snprintf(msg, 255, "$N获得了%d经验！", i), who);
	DESTRUCT_OB(ob, "pub_scavenger::accept_object");

	return 1;
}

NPC_END;
