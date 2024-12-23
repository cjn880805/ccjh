// pub_qigai.c

// code by Fisho
// date:2000-12-17

NPC_BEGIN(CNpub_qigai);

virtual void create()
{
	set_name("空空儿","qi gai" );

	set("icon", old_man2);
	set("title", "妙手神丐");
	set("gender", "男性" );
	set("age", 53);
	set("long", "一个满脸风霜之色的老乞丐。");
	
	set("str", 25);
	set("con", 25);
	set("dex", 25);
	set("int", 25);
	
	set("max_hp", 1500);
	set("mp", 500);
	set("max_mp", 500);
	set("mp_factor", 50);
	
	
	set_temp("apply/attack",  20);
	set_temp("apply/defense", 20);
	set_temp("apply/damage",  20);
	
	set("combat_exp", 20000);
	set("str", 27);
	set("kar", 100);
	set("thief", 0l);
	set("force", 200);
	
	set("max_force", 200);
	set("force_factor", 2);
	
	set_skill("unarmed", 50);
	set_skill("sword", 50);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_skill("stealing", 100);
	set("chat_chance", 15);
	carry_object("jitui");
	carry_object("jiudai");
	add_money(1000);
	set("no_huan",1);
}
	
virtual char * chat_msg()
{
	switch (random(3))
	{
	case 0:
		return "空空儿说道: 好心的大爷哪～ 赏我要饭的几个铜板吧～";
	case 1:
		return "空空儿懒洋洋地打了个哈欠。";
	case 2:
		return "空空儿伸手捉住了身上的虱子，骂道: 老子身上没几两肉，全叫你们给咬糜了。 ";
	}
	return "";
}

/*
virtual void init(CChar *me)
{	
	CNpc::init(me);
	if( userp(me) ) 
	{
		remove_call_out(stealing);
		call_out(stealing, 1, ob->object_id());
	}
}

void stealing(CChar * ob)
{
	switch( random(5) ) 
	{
	case 0:
		command("hehe " + ob->object_id());
		command("steal coin from " + ob->object_id());
		command("buy jitui");
		break;
	case 1:
		command("grin " + ob->object_id());
		command("steal silver from " + ob->object_id());			
		command("eat jitui");
		break;
	case 2:
		command("hi " + ob->object_id());
		command("steal gold from " + ob->object_id());			
		command("drink jiudai");
		break;
	case 3:
		command("pat " + ob->object_id());
		command("steal changjian from " + ob->object_id());	
		command("wield changjian");	
		command("drink jiudai");
		break;
	case 4:
		command("walkby " + ob->object_id());
		command("steal jitui from " + ob->object_id());	
		command("eat jitui");
		break;
	}
}
*/

virtual int accept_object(CChar * me, CContainer * obj)
{
	char msg[255];
	if (EQUALSTR(obj->querystr("base_name"), "coin") && obj->query("value") >= 1) 
	{
		command("smile");
		say("多谢啦 ! 其实我还是有点钱的，这次只不过试试你罢了 !", me);
		SendMenu(me);
		CContainer * coin = present("coin");
		if(coin)
			command(snprintf(msg,255,"give %ld to %ld 1000", coin->object_id(), me->object_id() ));

		return 1;
	}

	command("shake");
	say("这种东西鬼才要 ! 滚一边去 !", me);
	SendMenu(me);
	return 0;
}

virtual int accept_fight(CChar * me)
{
	char msg[255];
	say(snprintf(msg,255," %s饶命小的这就离开",query_respect(me) ));
	return 0;
}
NPC_END;