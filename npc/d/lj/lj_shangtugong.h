//lj_shangtugong.h	商土公
//秦波 2002、6、1

NPC_BEGIN(CNlj_shangtugong);

void create()
{
	set_name("商土公","shangtu gong");
	set("long", "这个大头老者，一颗大脑袋光秃秃地，半根头发也无，脸上巽血，远远望去，便如一个大血球一般");
	set("title", "碧磷洞洞主");
	set("gender", "男性");
	set("age", 43);
	set("attitude", "peaceful");
	set("icon",old_man1);
	set("per", 11);
	set("str", 30);
	set("int", 25);
	set("con", 40);
	set("dex", 30);

	set("max_hp", 15000);
	set("mp", 12000);
	set("max_mp", 12000);
	set("mp_factor", 160);

	set("combat_exp", 4500000);
	set_skill("force", 300);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_skill("claw",300);

	set_skill("wuwen_zhua",300);
	set_skill("guimei_shenfa",300);
	set_skill("wudu_shengong", 300);
    set_skill("tangshoudao", 300);
  
	map_skill("force", "wudu_shengong");
	map_skill("dodge", "guimei_shenfa");
	map_skill("parry", "tangshoudao");
	map_skill("claw", "wuwen_zhua");
	prepare_skill("claw", "wuwen_zhua");
	set("no_talk",1);
	set("no_huan",1);
	
};

int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query("lj/renwu1"))
	{
		AddMenuItem("武林集会", "$0ask1 $1", me);
		if(me->query("lj/renwu1_tiaojian"))
			AddMenuItem("条件", "$0ask11 $1", me);
		SendMenu(me);
		return 1;
	}
	return CNpc::do_talk(me,ask);
}

int handle_action(char *comm, CChar *me, char * arg)
{
	if(me->query("lj/renwu1"))
	{
		if(strcmp(comm, "ask1") == 0)
			return do_ask1(me);	
		if(strcmp(comm, "ask11") == 0)
			return do_ask11(me);	
	}
	if(me->query("lj/renwu2"))
	{
		say("商土公说道：诸位岛主洞主之间确有传闻，说是铁姥在灵鹫宫上失踪了。", me);
		say("商土公说道：大伙对她早有怨言，故而商议一起聚集杀上灵鹫宫，逼那些小娘皮拿生死符的解药！", me);
		say("商土公说道：你可找到藏边虬龙洞洪荒子求证我所说的真假。", me);
		SendMenu(me);
	}
	return CNpc::handle_action(comm, me, arg);
}

int do_ask1(CChar * me)
{
	say("商土公说道：关于武林集会，本人确实知道得不少，只要你能帮我一件事，我自可告诉你。",  me);
	SendMenu(me);
	me->set("lj/renwu1_tiaojian",1);
	return 1;
}
int do_ask11(CChar * me)
{
	say("商土公说道：我一向对星宿老仙用毒之术极为佩服，你若能为我找到一把星宿碧磷针，老夫感激之下自然无话不说。",  me);
	SendMenu(me);
	me->set("lj/renwu1_zheng",1);
	return 1;
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if(!who->query("lj/renwu1_zheng"))	return 0;
	if(DIFFERSTR(ob->querystr("name"), "碧磷针") )	return 0;
	destruct(ob);
	tell_object(who, "商土公说道：诸位岛主洞主之间确有传闻，说是铁姥在灵鹫宫上失踪了。");
	tell_object(who, "商土公说道：大伙对她早有怨言，故而商议一起聚集杀上灵鹫宫，逼那些小娘皮拿生死符的解药！");
	tell_object(who, "商土公说道：你可找到藏边虬龙洞洪荒子求证我所说的真假。");
	who->set("lj/renwu2",1);
	who->del("lj/renwu1");
	who->del("lj/renwu1_tiaojian");
	who->del("lj/renwu1_zheng");
	who->add("combat_exp",500);
	who->UpdateMe();
	tell_object(who, "\n$HIR你完成了“替商土公寻找碧磷针”的任务，获得了500点的经验奖励。\n");
	return 1;
}

NPC_END;




