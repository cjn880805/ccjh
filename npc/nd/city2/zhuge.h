// zhuge.H
//zhangdn 2001-07-18

NPC_BEGIN(CNcity2_zhuge);

virtual void create()
{
	set_name("�����̫", "zhuge");
	set("gender", "Ů��");
	set("age", 54);
	set("str", 25);
	set("dex", 20);
	set("int", 25);
	set("con", 20);
	set("long", "����һλ��̫̫������ֱ��ǰ������������");
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
message_vision(HIC "�����̫��$NЦ��Ц��˵��:�٣�С�ӣ��ɱ�������MUD��ץס������ÿ��ġ�\n" NOR,ob);		
command("grin");
return;
}


int do_play(string arg)
{
if(!arg||arg!="mud")
return notify_fail("������ʲô��");
this_object()->kill_ob(this_player());
this_player()->fight_ob(this_object());
return 1;
}

*/

}
NPC_END;