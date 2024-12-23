//lj_hajuba.h	哈巨霸
//秦波 2002、6、1

NPC_BEGIN(CNlj_hajuba);

void create()
{
	set_name("哈巨霸","haju ba");
	set("long", "这个大汉身高一丈，腰大一围，当真是个如铁塔一般的巨人。");
	set("title", "铁鳌岛岛主");
	set("gender", "男性");
	set("age", 43);
	set("attitude", "peaceful");
	set("icon",old_man1);
	set("per", 10);
	set("str", 40);
	set("int", 25);
	set("con", 40);
	set("dex", 30);
	set("no_kill",1);
	set_weight(50000000);

	set("max_hp", 15000);
	set("mp", 8000);
	set("max_mp", 8000);
	set("mp_factor", 160);

	set("combat_exp", 800000);
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("hammer",100);
	set_skill("unarmed", 100);
	set_skill("yujiamu_quan", 100);
	set_skill("shenkong_xing",100);
	set_skill("xiaowuxiang", 100);
	set_skill("riyue_lun", 100);
  
	map_skill("force", "xiaowuxiang");
    map_skill("dodge", "shenkong_xing");
    map_skill("unarmed", "yujiamu_quan");
	map_skill("parry", "riyue_lun");
	map_skill("hammer", "riyue_lun");

	prepare_skill("unarmed", "yujiamu_quan");
	set("no_talk",1);
	set("no_huan",1);
};

int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query("lj/renwu3"))
	{
		if(!me->query("lj/renwu31"))
			AddMenuItem("武林集会", "$0ask1 $1", me);
		if(me->query("lj/renwu3_tiaojian"))
			AddMenuItem("条件", "$0ask11 $1", me);
		if(me->query("lj/renwu31"))
			AddMenuItem("过招", "$0ask12 $1", me);
		SendMenu(me);	
		return 1;
	}
	return CNpc::do_talk(me,ask);
}

int handle_action(char *comm, CChar *me, char * arg)
{
	if(me->query("lj/renwu3"))
	{
		if(strcmp(comm, "ask1") == 0)
			return do_ask1(me);	
		if(strcmp(comm, "ask11") == 0)
			return do_ask11(me);	
		if(strcmp(comm, "ask12") == 0)
			return do_ask12(me);
	}
	if(me->query("lj/renwu4"))
	{
		say("哈巨霸说道：看你帮我找了个称手家伙的份上就告诉你啦，武老大联系过俺。", me);
		say("哈巨霸说道：这次万仙大会就是他召集的，不过似乎还没决定地点和时间，俺也不清楚具体情况。", me);
		say("哈巨霸说道：不过，俺知道北海玄冥岛岛主郁达夫倒是和武老大关系很好！你去问问他吧！", me);
		SendMenu(me);
	}
	return CNpc::handle_action(comm, me, arg);
}

int do_ask1(CChar * me)
{
	say("哈巨霸说道：武林集会？老子确实知道得不少，只要你能帮俺一件事，任你再问无妨。",  me);
	SendMenu(me);
	me->set("lj/renwu3_tiaojian",1);
	return 1;
}
int do_ask11(CChar * me)
{
	say("哈巨霸说道：俺人长得粗大有力，却没趁手的兵刃，你帮俺找个能用的家伙……",  me);
	SendMenu(me);
	me->set("lj/renwu3_wuqi",1);
	return 1;
}

int do_ask12(CChar * me)
{
	tell_object(me, "哈巨霸满意的说道：你给我的这个玩意称手！来我们过过招看看！");

	CFightRoom * obj;
	CContainer * env = environment();
	obj = (CFightRoom *)load_item("fight_room");		
	
	obj->set("room_locked", FIGHT_NO_JOIN);
	obj->set_name( "哈巨霸的试招战斗", "fight_room");		
	obj->move(env);
	me->move(obj);
	obj->Join_Team(me, CFightRoom::FIGHT_TEAM_B);
	this->move(obj);
	obj->Join_Team(this, CFightRoom::FIGHT_TEAM_A);
	obj->Begin_Fight(0);

	return 1;
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if(!who->query("lj/renwu3_wuqi"))	return 0;
	if(DIFFERSTR(ob->querystr("skill_type"), "hammer"))
	{
		tell_object(who, "哈巨霸摇了摇头，说道：我舞惯了大锤，这种玩意我用不惯！");
		return 0;
	}
	if(DIFFERSTR(ob->querystr("name"), "紫金锤")&&DIFFERSTR(ob->querystr("name"), "独脚铜人")&&DIFFERSTR(ob->querystr("name"), "铁琵琶") )
	{
		tell_object(who, "哈巨霸摇了摇头，说道：太轻了！");
		return 0;
	}
	tell_object(who, "$HIR\n哈巨霸满意的说道：这玩意称手！来我们过过招看看！\n");
	
	who->set("lj/renwu31",1);
	who->set("lj/renwu31_wuqi",ob->querystr("base_name"));

	who->del("lj/renwu3_tiaojian");
	who->del("lj/renwu3_wuqi");

	carry_object(ob->querystr("base_name"))->wield();
	CFightRoom * obj;
	CContainer * env = environment();
	obj = (CFightRoom *)load_item("fight_room");		
	
	obj->set("room_locked", FIGHT_NO_JOIN);
	obj->set_name( "哈巨霸的试招战斗", "fight_room");		
	obj->move(env);
	who->move(obj);
	obj->Join_Team(who, CFightRoom::FIGHT_TEAM_B);
	this->move(obj);
	obj->Join_Team(this, CFightRoom::FIGHT_TEAM_A);
	obj->Begin_Fight(0);

	return 1;
}

void die()
{
	CContainer * env = environment();
	DTItemList * list = env->Get_ItemList();  
	POSITION p = list->GetHeadPosition(); 
	CChar * me;
	while(p) 
	{ 
		CContainer * obj = list->GetNext(p);
		if(! obj->is_character()) continue; 
		me = (CChar *)obj; 
		if(!userp(me)) continue;
		if(me->query_temp("fight/is_fighting") && is_fighting(me)!=is_fighting(this)) 
		{
			if(me->query("lj/renwu31"))
			{
				me->set("lj/renwu4",1);
				me->del("lj/renwu3");
				me->del("lj/renwu31");
				me->del("lj/renwu31_wuqi");
				set("ok",1);
				set("hp",15000);
				set("eff_hp",15000);
				set("mp",8000);
				delete_temp("disabled");
				((CFightRoom *)env)->End_Fight();
				me->add("combat_exp",500);
				me->UpdateMe();
				tell_object(me, "哈巨霸满意的说道：呵呵呵，不错不错。");
				tell_object(me, "哈巨霸说道：看你帮我找了个称手家伙的份上就告诉你啦，武老大联系过俺。");
				tell_object(me, "哈巨霸说道：这次万仙大会就是他召集的，不过似乎还没决定地点和时间，俺也不清楚具体情况。");
				tell_object(me, "哈巨霸说道：不过，俺知道北海玄冥岛岛主郁达夫倒是和武老大关系很好！你去问问他吧！");
				tell_object(me, "\n$HIR你完成了“替哈巨霸寻找武器”的任务，获得了500点的经验奖励。\n");
				break;
			}
		}
		break;
	}
	if(!query("ok"))
		destruct(this);
	else
		del("ok");
}
NPC_END;




