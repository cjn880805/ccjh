// pub_laobaopo.c
// code by Fisho
// date:2000-12-17

NPC_BEGIN(CNpub_laobaopo);

virtual void create()
{
	set_name("老鸨婆", "laobao po");

	set("icon", young_woman11);
	set("gender", "女性" );
	set("title", "怡红院老板娘");
	set("age", 42);
	set("long", "这老鸨婆虽是徐娘半老，但仍风韵尤存，只不过脸上的粉太厚了。");
	set("str", 25);
	set("dex", 25);
	set("con", 25);
	set("int", 25);
	set("no_get", "1");
	set("shen_type", -1);
	set("combat_exp", 25000);
	set("max_hp", 900);
	set("mp", 500);
	set("max_mp", 500);
	set("attitude", "friendly");
	set_skill("unarmed", 20);
	set_skill("force", 20);
	set_skill("dodge", 35);
	set_inquiry("怡红院","我们怡红院可是北京城里头一份的找乐子去处。");
	carry_object("flower_shoe")->wear();
	carry_object("pink_cloth")->wear();
}

virtual void init(CChar * me)
{
	CNpc::init(me);
	if(userp(me) && ! is_fighting())
	{
		remove_call_out(do_greeting);
		call_out(do_greeting, 2, me->object_id());
	}
}

static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar * )ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);
	char msg[255];

	if(! who) return;
    
	tell_object(who, "老鸨婆正在看你，不知道打些什么主意。");

    if (EQUALSTR(who->querystr("gender"), "无性") )
	{
		message_vision("$N骂道：你当老娘是烂婊子吗？辣块妈妈，老娘满汉蒙藏回都接，就是不伺候太监！\n$N飞起一脚，踢在$n的屁股上。", me, who);
		tell_room(who->environment(), snprintf(msg,255,"%s被老鸨婆一脚踢出门外。", who->name() ), who);
		who->move(load_room("北京东南") );
		tell_room(who->environment(),snprintf(msg,255,"%s被人从怡红院里踢了出来，栽倒在地上，磕掉两颗门牙。", who->name() ),who);
    }
    else 
	{
		if (EQUALSTR(who->querystr("class"), "bonze") )
		{
			message_vision(snprintf(msg,255,"$N笑道：呦，%s也来光顾我们怡红院啊。\n$N说道：想当年我接过一个西藏喇嘛，他上床前一定要念经，一面念经，眼珠子就骨溜溜的瞧着我。", query_respect(who)), me);
		}

		if (EQUALSTR(who->querystr("gender"), "女性") )
		{
			message_vision("$N说道：哎呀，这年月大姑娘也逛窑子，成何体统。\n$N说道：可惜我儿子不在，不然让他伺候你", me);
		}

		me->say("楼上楼下的姑娘们，客人来了！");
    }
}

NPC_END;