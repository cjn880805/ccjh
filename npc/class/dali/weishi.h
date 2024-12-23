//weishi.h
//升级到卫士, 拜师
//Lanwood 2000-01-05

#define DALIWEISHI_BEGIN(npc_name) class npc_name : public CNdali_weishi	{	public:	npc_name(){};	virtual ~npc_name(){};
#define DALIWEISHI_END		};	

NPC_BEGIN(CNdali_weishi);

static char * ask_me(CNpc * me, CChar * who)
{
	if (who->query_skill("kurong_changong",1) < 60)
		return "你想当卫士，再练几年功吧。";
		

	const char * oldtitle = who->querystr("title");
	
	if (strstr(oldtitle, "大理镇南王府家臣"))
	{
		who->set_temp("fight_ok",1);
		me->say("好，既然如此想切磋，那就看你的本事如何了。", who);

		me->AddMenuItem("开始比试。", "$0bishi $1", who);
		me->AddMenuItem("放弃比试。", "", who);
		me->SendMenu(who);
		return 0;
	}
	
	return "只有家臣才能升卫士。";
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "bishi") == 0 && me->query_temp("fight_ok"))
	{
		Do_BiShi(this, me, "卫士比试会");
		return 1;
	}

	return CNpc::handle_action(comm, me, arg);
}

//比试结束
virtual void is_defeated(CChar * winner, CChar * failer)
{
	if(failer == this)
	{
		if(! winner->query_temp("fight_ok"))	return;

		winner->delete_temp("fight_ok");
		say("青出於蓝胜於蓝，不愧是大理段家的好弟子 ! 恭喜你了 !");
		say("你已经可以胜任大理卫士 !");
		
		upgrade_title(winner, "大理镇南王府卫士");
		return;
	}
	
	say("看来你还得多加练习，方能在大理段家诸多弟子中出人头地 !");
	return;	
}

void upgrade_title(CChar * me, char * arg)
{
	me->set("title", arg);
	me->UpdateMe();
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[80];

/*	if (me->querystr("title") != "大理镇南王府家奴")
	{
		g_Channel.do_emote(this, me, "shake", 1);
		say("我早已投身大理为臣，不再涉足江湖俗务，不能收徒了。", me);
		SendMenu(me);
		return;
	}
*/
	if (me->query("repute") < 0  )
	{
		say("我大理段氏向来不与您这种黑道人物打交道，您请回吧！", me);
		SendMenu(me);
		return;
	}
/*
	if (me->query_combat_exp() > 10000 || me->query("age") >17 )
	{
		say("镇南王府收了大侠您，也让你太屈尊了吧！", me);
		SendMenu(me);
		return;
	}
*/
	say("很好，很好。既已入府，便当尽忠报主，这条性命也就不是自己的了。");
	command(snprintf(msg, 80, "recruit %ld", me->object_id()));
	
	if( EQUALSTR(me->querystr("gender"), "男性"))
		me->set("title", "大理镇南王府家丁");
	else
		me->set("title","大理镇南王府婢女");

	me->UpdateMe();
}

NPC_END;
