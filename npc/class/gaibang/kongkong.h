//kongkong.h
//Lanwood 2000-01-06

NPC_BEGIN(CNgaibang_kongkong);

virtual void create()
{
	set_name("空空",  "kong kong");
	set("title", "妙手神丐");
	set("gender", "男性" );
	set("age", 53);
	set("long", "一个满脸风霜之色的老乞丐。");
	set("attitude", "peaceful");

	set("str", 25);
	set("con", 25);
	set("int", 25);
	set("dex", 25);
	set("kar", 100);
	set("icon",begger);

	set("hp", 500);
	set("max_hp", 1500);
	
	set("mp", 500);
	set("max_mp", 500);
	set("mp_factor", 30);

	
    set("startroom","扬州丽春院");
	set("thief", 0l);
	set("combat_exp", 80000);

	set_skill("force", 40); 
	set_skill("unarmed", 60);
	set_skill("sword", 50);
	set_skill("dodge", 80);
	set_skill("parry", 50);
	set_skill("stealing", 100);
	set_skill("begging", 100);
//	set_skill("checking", 80); 
	set_skill("xunshou_shu", 80);

	set_skill("huntian_qigong", 40); 
	set_skill("xianglong_zhang", 60);
	set_skill("xiaoyaoyou", 80); 

	map_skill("force", "huntian_qigong");
	map_skill("unarmed", "xianglong_zhang");
	map_skill("parry", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");

	create_family("丐帮", 19, "八袋长老");

	set("chat_chance", 3);
	
	set("chat_chance_combat", 20);
	
	carry_object("jitui");
	carry_object("jiudai");
	add_money(1000);
	set("no_huan",1);
	
}

virtual char * chat_msg()
{
	switch(random(4))
	{
	case 0:
		return "空空儿说道: 好心的大爷哪～ 赏我要饭的几个铜板吧～";
	case 1:
		return 	"空空儿懒洋洋地打了个哈欠。";
	case 2:
		return "空空儿伸手捉住了身上的虱子，骂道: 老子身上没几两肉，全叫你们给咬糜了。 ";
	case 3:
		random_move();
		return 0;
	}
	
	return 0;
}

virtual char * chat_msg_combat()
{
	switch(random(2))
	{
	case 0:
		perform_action("unarmed xianglong", 1);
		break;
	case 1:
		perform_action("force recover", 0);
		break;
	}

	return 0;
}
/*
virtual void attempt_apprentice(CChar * me)
{
	char msg[80];

	say("好吧，希望你能好好学习本门武功，将来在江湖中闯出一番作为。");
	
	command(snprintf(msg, 80, "recruit %ld", me->object_id()));
	me->set("class", "beggar");
}
*/
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

int accept_fight(CChar * me)
{
	char msg[255];
	say(snprintf(msg,255," %s饶命小的这就离开",query_respect(me) ));
	return 0;
}

NPC_END;
