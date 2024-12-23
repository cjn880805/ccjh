//tian.c
//code by sound
//2001-07-16

NPC_BEGIN(CNhengshan_tian);

virtual void create()
{
	set_name("田不戒", "tian boguang");
	set("long", "他一身飘逸的白色长衫，风流儒雅。");
	set("nickname", "万里独行");
	set("gender", "男性");
	set("age", 37);
	set("attitude", "friendly");
	set("shen_type", -1);
	
	set("per", 23);
	set("str", 25);
	set("int", 24);
	set("con", 25);
	set("dex", 26);
	set("icon",young_man3);
	
	set("hp", 1000);
	set("max_hp", 1000);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 10);
	
	set("combat_exp", 300000);
	set("score", 40000);
	
	set_skill("blade", 100);
	set_skill("dodge", 150);
	set_skill("parry", 90);
	set_skill("force", 90);
	set_skill("lingxu_bu", 150);
	set_skill("kuangfeng_blade", 100);
	
	map_skill("dodge", "lingxu_bu");
	map_skill("parry", "kuangfeng_blade");
	map_skill("blade", "kuangfeng_blade");
	
	set("chat_chance", 10);
	
//	carry_object("baipao")->wear();
	carry_object("gangdao")->wield();
//	add_money("silver",10);
}

virtual char *chat_msg()
{
	return "田不戒笑道：尼姑也没关系嘛，蓄起头发，两个月就是小美人了。";
}

virtual char * chat_msg_combat()
{
	perform_action("blade kuang", 1);
	
	return 0;
}
/*
void init()
{
	object ob;
	
	::init();
	
	if( interactive(ob = this_player()) && !is_fighting() ) 
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if ((string)ob->query("gender")=="女性")
	{
		if (ob->query("age")<26) say("田伯光笑道：妙极，妙极，又来了一个小姑娘。\n");     
		else say("田伯光笑道：妙极，妙极，可惜太老了点，我可没胃口。\n");     
	}
	else say("田伯光笑着招招手：这位"+RANK_D->query_respect(ob) + "来喝两杯，这个小尼姑嘛，反正也没什么事，就让她坐着就是。\n");
	return;
}

int accept_fight(object ob)
{
	if ((string)ob->query("gender") == "女性")
	{
		write("田伯光笑道：花姑娘？杀了太可惜了的。\n");
		return 0;
	}
	return 1;
}
*/
NPC_END;