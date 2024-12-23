//scavenger.h
//Teapot 2000-01-05

NPC_BEGIN(CNtaiwan_scavenger);

virtual void create()
{
	set_name("收破烂的", "Scavenger");
	set("long", "他一身飘逸的白色长衫，手摇折扇，风流儒雅。");
	set("title", "[收购垃圾]");
	set("gender", "男性");
	set("age", 27);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("icon", young_man3);

	set("rubbish", 1);
};

virtual void init(CChar * me)
{
	CNpc::init(me);

	if(userp(me) && ! is_fighting())
	{
		remove_call_out(do_greeting);
		call_out(do_greeting, 1, me->object_id());
	}
}

static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);
	char msg[255];

	if(! who) return;

    message_vision(snprintf(msg, 255, "$N对着$n叹了一口气道：这位%s, 可怜可怜小的，给点垃圾吧。", query_respect(who)), me, who);

	return;
}

NPC_END;
