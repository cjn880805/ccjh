//tanzhu.h
//明教坛主NPC
//Lanwood 2000-01-09

#define MINGJIAOTANZHU_BEGIN(npc_name) class npc_name : public CNmingjiao_tanzhu	{	public:	npc_name(){};	virtual ~npc_name(){};
#define MINGJIAOTANZHU_END		};	

NPCMINGJIAO_BEGIN(CNmingjiao_tanzhu);

static char * ask_me(CNpc *who,CChar *me)
{
	who->say("你想加入我明教吗？", me);
	who->AddMenuItem("我想", "$0join $1",me);
	who->AddMenuItem("我不想", "", me);
	who->SendMenu(me);
	return 0;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "join") == 0)
	{
		return do_join(me);
	}
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

//加入明教
int do_join(CChar * me)
{
	if(me->query_temp("have_letter") || me->present("tuijian xin1"))
   	{
		say("好啊。", me);
		say(g_Channel.do_emote(this, me, "heihei", 1), me);
		SendMenu(me);
		return 1;	
	}
   	if( ! me->querymap("party"))
   	{
		message_vision("$N交给$n一封推荐信。", this, me);
		say("好，你到昆仑山总舵去找接引使者，他会让你入教的。", me);
		me->set_temp("have_letter",1);
        load_item("tuijianxin_1")->move(me);
		SendMenu(me);
		return 1;	
	}
   	if( DIFFERSTR(me->querystr("party/party_name"), "明教"))
	{
		say("你已经加入其他帮派了，不能再入我明教。", me);
		SendMenu(me);
		return 1;
	}

	say("你已经是我明教的人了。", me);
	SendMenu(me);
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




