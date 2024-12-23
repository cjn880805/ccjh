//hui.h
//少林慧字辈
//Lanwood 2000-01-09

#define SHAOLINHUI_BEGIN(npc_name) class npc_name : public CNshaolin_hui	{	public:	npc_name(){};	virtual ~npc_name(){};
#define SHAOLINHUI_END		};	

NPC_BEGIN(CNshaolin_hui);

virtual int accept_object(CChar * who, CContainer * obj)
{
	if ( who->query_temp("have_letter") && who->present("tuijian xin3") ) 
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
        
	if (EQUALSTR(obj->querystr("id"), "tuijian xin2" )
		&& who->query_temp("have_letter") )
	{
		who->set_temp("apprentice_ok",1);
		destruct(obj);

	    say("好，你愿意拜我为师吗？", who);
		AddMenuItem("我愿意", "$0apprentice $1", who);
		AddMenuItem("我不愿意", "", who);
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
		Do_BiShi(this, me, "慧字比试会");
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
		load_item("tuijianxin_3")->move(winner);
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

	char myname[5], prename[3];
	strncpy(myname, me->name(), 4)[4] = 0;
	strncpy(prename, myname, 2)[2] = 0;
	
	if ( ( me->query("family/generation") == query("family/generation") + 1) 
		&& strcmp(prename, "道") == 0)
	{
		say(snprintf(msg, 255, "%s的徒弟怎麽跑到我这儿来了，哈哈哈 !", me->querystr("family/master_name")));
		command(snprintf(msg, 80, "recruit %ld", me->object_id()));
	}

	if ( me->query("family/generation") == query("family/generation") + 2 )
	{
		if ( me->query_temp("apprentice_ok") )
		{
			me->delete_temp("have_letter");
			me->delete_temp("apprentice_ok");
	
			say(snprintf(msg, 255, "是%s叫你来找我的吧，哈哈哈 !", me->querystr("family/master_name")));
			say("贫僧又得一可塑之才，真是可喜可贺 !", me);

			char new_name[5];

			strcpy(new_name, "道");
			new_name[2] = myname[2];
			new_name[3] = myname[3];
			new_name[4] = 0;

			me->set_name( new_name);
			say(snprintf(msg, 255, "从今以后你的法名叫做%s，恭喜你荣升为少林派道字辈弟子 !", new_name));
			command(snprintf(msg, 80, "recruit %ld", me->object_id()));
		}
		else
		{
			say("你没有推荐信，不能越级拜师。", me);
			SendMenu(me);
			return;
		}
	}

	return;
}


NPC_END;
