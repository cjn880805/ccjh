NPC_BEGIN(CNpub_hongmao);

virtual void create()
{

	set_name("红毛鬼","hongmao");

	set("icon", banditi);
	set("gender", "男性");
	set("age", random(10) + 30);
	set("str", 25);
	set("dex", 16);
	set("long", "入侵我天朝宝岛台湾的荷兰红毛鬼。他手上端着一支火枪，枪口还冒着青烟。");
	set("combat_exp", 25000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_temp("apply/attack", 30);
	set_temp("apply/defense", 30);
	set_temp("apply/armor", 30);
	set_temp("apply/damage", 30);

	carry_object("huoqiang")->wield();

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
	CChar * who = (CChar *)(ob->environment())->Present(param1);

	if(! who) return;

	who->receive_damage("hp",50);
	who->receive_wound("hp",50);
	
	message_vision("红毛鬼抬手就是一枪：砰！枪口一团火焰喷出。", who);
	who->SendState(who);
}

NPC_END;
