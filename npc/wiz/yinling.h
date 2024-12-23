//zhou.h
//Lanwood 2000-01-05

NPC_BEGIN(CNpub_yinling);

void create()
{
	set_name("银铃", "yinling");
	set("long", "一个看上去很伤心的女孩子。");
	set("icon", young_woman2);
	
	set("gender", "女性");
	set("age", 20);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("class", "fighter");
	
	set_inquiry("她在等什么？", "你见过我的它吗？");
//	set_inquiry("申请自由杀手", do_apply);
	
	set("foolid",1000);	

	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 30);
	
	set("max_hp", 3500);
	set("mp", 3500);
	set("max_mp", 3500);
	set("mp_factor", 1000);
	
	set("combat_exp", 1500000);
	set("score", 50);
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("unarmed", 100);
	set_skill("strike", 100);
	set_skill("sword", 100);
	set_skill("hubo", 300);
	set_skill("literate", 100);
	set_skill("wudu_zhang", 100);
	set_skill("jiuyin_zhua", 100);
	set_skill("hengshan_sword", 200);
	set_skill("lingxu_bu", 200);
	set_skill("wudu_xinfa", 200);
	map_skill("force","wudu_xinfa");
	map_skill("dodge","lingxu_bu");
	map_skill("strike","wudu_zhang");
	map_skill("sword","hengshan_sword");
	create_family("旺财派", 4, "掌门弟子");
	
	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
	set("no_huan",1);
}

static char * do_apply(CNpc * npc, CChar * me)
{
	if(me->query("level") < 10)
		return "再练几年功吧。";
	
	npc->call_out(do_fight, 5, me->object_id());
	return "哼哼，想自由PK，得先过我这关！";
}

static void do_fight(CContainer * ob, LONG param1, LONG param2)
{
	CChar * npc = (CChar *)ob;
	CChar * me = (CChar *)(npc->environment())->Present(param1);

	if(! me) return;

	npc->set("hp", npc->query("max_hp"));
	npc->set("eff_hp", npc->query("max_hp"));
	npc->set("mp", npc->query("max_mp"));
	
	me->set_temp("fight_ok", 1);
	Do_BiShi(npc, me, "银铃的战斗", 20);
}

//比试结束
void is_defeated(CChar * winner, CChar * failer)
{
	CChar * me = failer;
	if(failer == this)	//获胜,设置标记.延迟呼叫,以便从战斗中脱身.
	{
		if(! winner->query_temp("fight_ok")) return;
		winner->delete_temp("fight_ok");
		winner->set_temp("corps/joining", "freedom");
		me = winner;
	}
	
	remove_call_out(do_join);
	call_out(do_join, 2, me->object_id(), 30);
}

static void do_join(CContainer * ob, LONG param1, LONG step)
{
	CChar * npc = (CChar *)ob;
	CChar * me = (CChar *)(npc->environment())->Present(param1);

	if(! me) 
	{
		if(step > 0) npc->call_out(do_join, 2, param1, step - 1);
		return;
	}

	const char * corps = me->querystr_temp("corps/joining");

	if(corps[0])	//获胜的话
	{
		npc->say("你表现得很好！恭喜你获取了自由PK执照。", me);
		npc->say("你可采取任意方式对任意玩家进行杀戮。代价是你一旦被杀死，损失也要加倍，全部武功降一级。", me);
		me->set("freedom/pks", me->query("pks"));	
		me->set("freedom/rank", "自由杀手");	
		me->setup();
		me->UpdateMe();
		npc->SendMenu(me);
	}
	
}

int accept_object(CChar * who, CContainer * ob)
{
	if ( DIFFERSTR(ob->querystr("id"), "diablo2") || DIFFERSTR(ob->querystr("name"), "旺财" ))
	{	
		message_vision("$N眼泪夺眶而出？", this);
		return 0;
	}

	DESTRUCT_OB(ob, "yinling");

	CContainer * obj = load_item("baozi");

	obj->set_name( "肉包子", "bao zi");

	message_vision("$N含泪望着$n点点头，给$p一样东西。", this, who);
	obj->move(who);
	
	who->set_temp("银铃/判师", obj->object_id());
	return 1;
}


NPC_END;
