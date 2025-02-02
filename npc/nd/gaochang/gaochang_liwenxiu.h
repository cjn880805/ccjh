// liwenxiu.c 李文秀
//sound 2001-07-11

NPC_BEGIN(CNgaochang_liwenxiu);

virtual void create()
{
	set_name("李文秀", "liwenxiu");
	set("gender", "女性");
	set("age", 18);
	set("long", "她长得清纯脱秀，嫣然一笑，不禁让人怦然心动。");
	
	set("combat_exp", 30000);
	set("shen_type", 1);
	
	set("max_mp", 500);
	set("mp", 500);
	set("mp_factor", 10);
	set("per", 18);
	set("icon",young_woman2);			//设置人物形象
	
	set_skill("force", 40);
	set_skill("sword", 100);
	set_skill("unarmed", 50);
	set_skill("dodge", 100);
	set_skill("parry", 100);
/*	
	set("inquiry", ([
		"苏普" : (: ask_supu :),
		"父母" : (: ask_parent :),
		"高昌迷宫" : (: ask_gaochang:),
        ]) );
*/
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 15);
	
	carry_object("changjian")->wield();
//	carry_object("map");
}
/*
int ask_supu()
{
	say("李文秀黯然的说：他是我儿时的伙伴，他现在和阿曼在一起了，\n");
	this_player()->set_temp("marks/李1", 1);
	return 1;
}

int ask_parent()
{
	if ((int)this_player()->query_temp("marks/李1")) {
		say("李文秀哽咽的说道：我的父母是被奸人害死的，奸人觊觎我们家的高昌地图.\n"
			"我一定要手刃仇人，为我父母报仇。\n");
		this_player()->set_temp("marks/李2", 1);
		return 1;
	}
	else {
		say("李文秀说道：父母之仇，不共戴天。\n");
		return 1;
	}
}

int ask_gaochang()
{
	object me;
	object map;
	me=this_player()
		if ( me->query_temp("marks/李2")) {
			say("李文秀一惊，说道：你怎么知道的？噢，我刚才说露嘴了。\n"
				"那我就把地图送给你吧。你看看高昌迷宫到底有什么？\n");
			map=new("/d/gaochang/obj/map");
			map->move(me);
		}
		
		else {
			message("vision",
				HIY "李文秀勃然大怒，喝道：你也窥视我父母的高昌地图？！我跟你拼了！\n"
				NOR, environment(), this_object() );
			kill_ob(this_player());
		}
		this_player()->delete_temp("marks/李1");
		this_player()->delete_temp("marks/李2");
		return 1;
}
*/
NPC_END;