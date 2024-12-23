//mingjiao.h
//明教NPC
//Lanwood 2000-01-09

#define NPCMINGJIAO_BEGIN(npc_name) class npc_name : public CNmingjiao	{	public:	npc_name(){};	virtual ~npc_name(){};
#define NPCMINGJIAO_END		};	

NPC_BEGIN(CNmingjiao);

virtual void init(CChar * me)
{
	CNpc::init(me);

	if( !is_fighting() )
	{
		remove_call_out(do_greeting);
		call_out(do_greeting, 1, me->object_id());
	}
}
virtual int handle_action(char *comm, CChar *me, char * arg)
{
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
static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	char msg[255];
	CChar * me =(CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);
	
	if(!who) return;

	if ( EQUALSTR(who->querystr("party/party_name"), "明教"))
	{
		message_vision(
			snprintf(msg, 255, "$N对$n躬身行礼，说道：%s%s，参见%s%s！", 
			me->querystr("title"), me->name(),
			who->querystr("party/rank"), who->name()),
			me, who);		
	}
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
NPC_END;




