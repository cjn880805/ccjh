// zhuge.H
//zhangdn 2001-07-18

NPC_BEGIN(CNcity2_zhuge);

virtual void create()
{
	set_name("诸葛老太", "zhuge");
	set("gender", "女性");
	set("age", 54);
	set("str", 25);
	set("dex", 20);
	set("int", 25);
	set("con", 20);
	set("long", "这是一位老太太，两眼直视前方，炯炯有神。");
	set("combat_exp", 200000);
	set("score", 10000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set("icon", old_woman);

	set("mp", 1500); 
	set("max_mp", 1500);
	set("mp_foctor", 100);
	
//	carry_object("cloth")->wear();
/*	
}

void init()
{
::init();
add_action("do_play","play");
remove_call_out("greeting");
call_out("greeting", 1, this_player());
}

void greeting(object ob)
{
message_vision(HIC "诸葛老太对$N笑了笑，说到:嘿，小子，可别想又玩MUD，抓住了有你好看的。\n" NOR,ob);		
command("grin");
return;
}


int do_play(string arg)
{
if(!arg||arg!="mud")
return notify_fail("你想玩什么？");
this_object()->kill_ob(this_player());
this_player()->fight_ob(this_object());
return 1;
}

*/

}
NPC_END;