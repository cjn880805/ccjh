// pub_compere.h 比武收费人


NPC_BEGIN(CNpub_compere);

virtual void create()
{
	set_name("公平子", "gongping zi");
	set("gender", "男性");
	set("age", 45);
	set("icon",triggerman1);
	set("no_kill",1);
	set("long", "华山论剑处管理人");
	
	set_inquiry("比武论剑", "公平子说道：申请在这里切磋，每场需交3万手续费。");
	set("no_huan",1);
};


virtual int accept_object(CChar * who, CContainer * ob)
{
	if(who->is_busy())
		return notify_fail("你上一个动作还没有完成");

	if (DIFFERSTR(ob->querystr("id"), "coin") )
	{	
		say("公平子皱眉说道：你给我的是什么东西？我可是只认识钱的。", who);
		SendMenu(who);
		return 0;
	}

	if (ob->query("value") <30000) 
	{	
		say("公平子笑嘻嘻说道：想在这里和朋友切磋，你得先交个3万手续费再说，少一两银子都请你换个场子去耍。", who);
		SendMenu(who);
		return 0;
	}
	
	message_vision("公平子说道：现在$N可以在这里和其他江湖朋友比武使用KILL指令切磋了，比武将由本人做公证。", who);
	who->set_temp("比武",1);
	destruct(ob);
	add("biwu/count",1);
	return 1;
}

int handle_action(char *comm, CChar *me, char *arg)
{
	if(strcmp(comm, "kill") == 0 || strcmp(comm, "fight") == 0	|| strcmp(comm, "cast") == 0)
	{
		me->start_busy(2);
		return 1;
	}
	
	return CNpc::handle_action(comm, me, arg);
}
NPC_END;



