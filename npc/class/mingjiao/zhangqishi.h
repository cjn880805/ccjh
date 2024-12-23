//zhangqishi.h
//掌旗使NPC
//Lanwood 2000-01-09

#define MINGJIAOZHANGQISHI_BEGIN(npc_name) class npc_name : public CNmingjiao_zhangqishi	{	public:	npc_name(){};	virtual ~npc_name(){};
#define MINGJIAOZHANGQISHI_END		};	

NPCMINGJIAO_BEGIN(CNmingjiao_zhangqishi);
/*
virtual void init(CChar * me)
{
	CNmingjiao::init(me);

	if (userp(me) && ! is_fighting())
	{
		Do_Attack(this, me, TYPE_QUICK);  
		me->add_temp("beat_count", 1);
	}     	
}
*/

virtual void attempt_apprentice(CChar * me)
{
	char msg[80];

	if(me->querymap("family") && DIFFERSTR(me->querystr("family/family_name"),"明教"))
	{
		say("你已经加入其他门派，请回吧。", me);
		SendMenu(me);
		return;
	}
	if(DIFFERSTR(me->querystr("party/party_name"), "明教"))//别帮的不收
	{
		say("阁下与本教素无来往，请回吧。", me);
		SendMenu(me);
		return;
	}
	if(me->query("party/level") > 2)
	{
		say("以你在教中的地位，在下哪里敢当!", me);
		SendMenu(me);
		return;
	}
	if(me->query("party/level") == 1)
	{
		say("你尚未通过门主比试，本座不能越级收徒。", me);
		SendMenu(me);
		return;
	}
	else if(me->query("family/generation") == query("family/generation") + 1)//师傅与该NPC同级
		say(snprintf(msg, 80, "%s的徒弟怎麽跑到我这儿来了，哈哈哈 !", me->querystr("family/master_name")));
	else
	{
		say("好，我就收下你这位好兄弟", me);
		SendMenu(me);
	}
	command(snprintf(msg, 80, "recruit %ld", me->object_id()));
	me->set("title", snprintf(msg, 80, "%s亲传弟子", querystr("title")));
	me->UpdateMe();
	return;
}

virtual int accept_object(CChar * me, CContainer * obj)
{
	if ( me->query_temp("have_letter") && me->present("tuijian xin3") ) 
	{
		say("怎麽样，你拿我的推荐信去见堂主了吗 ?", me);
		SendMenu(me);
		return 0;
	}

	if( EQUALSTR(obj->querystr("id"), "tieyan ling")
		&& EQUALSTR(me->querystr("party/party_name"), "明教")
		&& me->query("party/level") == 2
		&& !me->query_temp("have_letter") ) 
	{
		me->set_temp("fight_ok",1);
		destruct(obj);
		say("好，既然已得到教主许可，我们就来验证一下武功。", me);
		AddMenuItem("开始比试", "$0bishi $1", me);
		AddMenuItem("转身离开", "", me);
		SendMenu(me);
		return 1;
	}

	if (EQUALSTR(obj->querystr("id"), "tuijian xin2" )
		&& me->query_temp("have_letter") )
	{
		me->set_temp("apprentice_ok",1);
		destruct(obj);
	    say("好，你愿意加入我旗吗？");
		AddMenuItem("愿意加入", "$0join $1", me);
		AddMenuItem("暂时不想", "", me);
		SendMenu(me);
		return 1;
	}

    say(g_Channel.do_emote(this, 0, "?", 1), me);
    say("这东西给我可没有什麽用。", me);
	SendMenu(me);
	return 0;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "bishi") == 0 && me->query_temp("fight_ok"))
	{
		Do_BiShi(this, me, "掌旗使比试会");
		return 1;
	}

	if(strcmp(comm, "join") == 0 && me->query_temp("apprentice_ok"))
		return do_join(me);

	CContainer * env = load_room("pk");
	if((strcmp(comm, "kill") == 0 || strcmp(comm, "fight") == 0	|| strcmp(comm, "cast") == 0 )&& env->query("mj/start") && userp(me))
	{
		message_vision("$n横眉怒视$N，恨道：“在这大敌当前之际，你到底想做什么！！”", me, this);
		me->delete_temp("mf/exp");
		me->add("hp",-me->query("hp")/2);
		me->UpdateMe();
		me->start_busy(3);
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
        say("青出於蓝胜於蓝，不愧是我明教的佳弟子 ! 恭喜你了 !");

		message_vision("$N交给$n一封推荐信。", this, winner);
		winner->set_temp("have_letter",1);
		load_item("tuijianxin_3")->move(winner);
		return;
	}
	
	say("看来你还得多加练习，方能在明教诸多弟子中出人头地 !");
	return;	
}
            
int do_join(CChar * me)
{
	char msg[255];

	if ( me->query("party/level") >= query("party/level") )
	{
        say("在下哪里敢当 !", me);
		SendMenu(me);
		return 1;
	}

	if ( me->query("party/level") == 1 )
	{
		me->delete_temp("have_letter");
		me->delete_temp("apprentice_ok");
	
		char title[12], new_rank[40];
		strncpy(title, querystr("title"), 6)[6] = 0;
		snprintf(new_rank, 40, "%s护旗", title);
		me->set("party/rank", new_rank);
		me->set("party/level", 2);
		
		say("哈哈哈 !", me);
        say("本旗又得一可塑之才，真是可喜可贺 !", me);
	    say(snprintf(msg, 255, "恭喜你荣升为明教%s！", new_rank), me);
		SendMenu(me);	
	}
	
	return 1;
}

void die()
{
	char msg[255];
	CContainer * env = load_room("pk");
	if(env->query("mj/start"))
	{
		CChar * me = (CChar *)find_object(query_temp("last_damage_from"), 1);
		if(me && !env->query(snprintf(msg, 255,"mj/kill_%s",this->name(1))))
		{
			env->add(snprintf(msg, 255,"mj/kill_%s",this->name(1)),1);
			env->add("mj/count",1);
			g_Channel.do_channel(&g_Channel, 0, "chat", 
				snprintf(msg, 255, "$HIY%s$HIC新立奇功，斩获明教魔头$HIY%s%s$HIC！",me->name(1),this->querystr("title"),this->name(1)));
		}
	}
	CNpc::die();
}
NPCMINGJIAO_END;




