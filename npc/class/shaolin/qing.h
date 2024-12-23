//qing.h
//少林清字辈
//Lanwood 2000-01-09

#define SHAOLINQING_BEGIN(npc_name) class npc_name : public CNshaolin_qing	{	public:	npc_name(){};	virtual ~npc_name(){};
#define SHAOLINQING_END		};	

NPC_BEGIN(CNshaolin_qing);

virtual int accept_object(CChar * who, CContainer * obj)
{
	if ( who->query_temp("have_letter") && who->present("tuijian xin1") ) 
	{
		say("怎麽样，你拿我的推荐信去拜师了吗 ?", who);
		SendMenu(who);
		return 0;
	}

	if((EQUALSTR(obj->querystr("id"), "damo ling"))
		&& who->query("family/generation") == query("family/generation") + 1
		&& ! who->query_temp("have_letter") ) 
	{
		who->set_temp("fight_ok",1);
		destruct(obj);
	    say("好，既然已得到方丈许可，我们就来验证一下武功。", who);
		AddMenuItem("开始比试", "$0bishi $1", who);
		AddMenuItem("转身离开", "", who);
		SendMenu(who);
		return 1;
	}
        
    say(g_Channel.do_emote(this, 0, "smile", 1), who);
    say("这东西给我可没有什麽用。", who);
    return 0;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "bishi") == 0 && me->query_temp("fight_ok"))
	{
		Do_BiShi(this, me, "清字比试会");
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
        say("青出於蓝胜於蓝，不愧是少林寺的佳弟子 ! 恭喜你了 !");

		message_vision("$N交给$n一封推荐信。", this, winner);
		winner->set_temp("have_letter",1);
		load_item("tuijianxin_1")->move(winner);
		return;
	}
	
	say("还得多加练习，方能在少林诸多弟子中出人头地 !");
	return;	
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[255];
	if (DIFFERSTR(me->querystr("family/family_name"), "少林派"))
	{
		say("你与本派素无来往，不知此话从何谈起？", me);
		SendMenu(me);
		return;
	}

	if ( DIFFERSTR(me->querystr("class"), "bonze") && EQUALSTR(me->querystr("family/family_name"), "少林派")) 
	{
		say("你是俗家弟子，不能在寺内学艺。", me);
		SendMenu(me);
		return;
	}

	if ( me->query("family/generation") <= query("family/generation") )
	{
		say("这，贫僧哪里敢当 !", me);
		SendMenu(me);
		return;
	}

	if ( me->query("family/generation") == 0 )
	{
		say("阿弥陀佛！贫僧就收下你做我的弟子了。");
		command(snprintf(msg, 80, "recruit %ld", me->object_id()));
		return;
	}
	
	if ( me->query("family/generation") == query("family/generation") + 1) 
		
	{
		say(snprintf(msg, 255, "%s的徒弟怎麽跑到我这儿来了，哈哈哈 !", me->querystr("family/master_name")));
		command(snprintf(msg, 80, "recruit %ld", me->object_id()));
	}

	return;
}


NPC_END;
