//lj_honghuangzi.h	洪荒子
//秦波 2002、6、1

NPC_BEGIN(CNlj_honghuangzi);

void create()
{
	set_name("洪荒子","honghuang zi");
	set("long", "也许是长年在高原生活，他的脸晒得黑红黑红的，面上皮肤也有很多龟裂和皱纹。");
	set("title", "虬龙洞洞主");
	set("gender", "男性");
	set("age", 43);
	set("attitude", "peaceful");
	set("icon",old_man1);
	set("per", 11);
	set("str", 30);
	set("int", 25);
	set("con", 40);
	set("dex", 30);
	set("no_kill",1);

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
	if(me->query("lj/renwu2"))
	{
		AddMenuItem("武林集会", "$0ask1 $1", me);
		if(me->query("lj/renwu2_tiaojian"))
			AddMenuItem("条件", "$0ask11 $1", me);
		SendMenu(me);	
		return 1;
	}
	return CNpc::do_talk(me,ask);
}

int handle_action(char *comm, CChar *me, char * arg)
{
	if(me->query("lj/renwu2"))
	{
		if(strcmp(comm, "ask1") == 0)
			return do_ask1(me);	
		if(strcmp(comm, "ask11") == 0)
			return do_ask11(me);	
	}
	if(me->query("lj/renwu3"))
	{
		say("洪荒子说道：确有此事，铁姥如今应该已不在飘渺峰上了。", me);
		say("洪荒子说道：只要我们杀上山去，从宫里人口中套得生死符解药秘方，大伙立刻远走高飞，就算日后铁姥无恙，也没法天涯海角的来拿我们。", me);
		say("洪荒子说道：铁鳌岛岛主哈巨霸乃是我们的先锋，你可去他处了解更多详情……", me);
		SendMenu(me);
	}
	return CNpc::handle_action(comm, me, arg);
}

int do_ask1(CChar * me)
{
	say("洪荒子说道：关于武林集会，本人确实知道得不少，只要你能帮我一件事，我自可告诉你。",  me);
	SendMenu(me);
	me->set("lj/renwu2_tiaojian",1);
	return 1;
}
int do_ask11(CChar * me)
{
	say("洪荒子说道：我一向对吐蕃雪山寺武功极为仰慕，听闻寺中珍藏有一本羊皮书、一本密宗心经、一个铁手掌，你能否为我取一个来？",  me);
	SendMenu(me);
	me->set("lj/renwu2_book",1);
	return 1;
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if(!who->query("lj/renwu2_book"))	return 0;
	if(DIFFERSTR(ob->querystr("name"), "羊皮书")&&DIFFERSTR(ob->querystr("name"), "密宗心经")&&DIFFERSTR(ob->querystr("name"), "铁手掌") )
		return 0;
	destruct(ob);
	tell_object(who, "洪荒子满意的说道：确有此事，铁姥如今应该已不在飘渺峰上了。");
	tell_object(who, "洪荒子说道：只要我们杀上山去，从宫里人口中套得生死符解药秘方，大伙立刻远走高飞，就算日后铁姥无恙，也没法天涯海角的来拿我们。");
	tell_object(who, "洪荒子说道：铁鳌岛岛主哈巨霸乃是我们的先锋，你可去他处了解更多详情……");
	who->set("lj/renwu3",1);
	who->del("lj/renwu2");
	who->del("lj/renwu2_tiaojian");
	who->del("lj/renwu2_book");
	who->add("combat_exp",500);
	who->UpdateMe();
	tell_object(who, "\n$HIR你完成了“替洪荒子寻找雪山寺藏书”的任务，获得了500点的经验奖励。\n");
	return 1;
}

NPC_END;




