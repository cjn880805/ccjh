//tobebonze.h
//出家
//Lanwood 2000-01-05

#define EMEIBONZE_BEGIN(npc_name) class npc_name : public CNemei_tobebonze	{	public:	npc_name(){};	virtual ~npc_name(){};
#define EMEIBONZE_END		};	

NPC_BEGIN(CNemei_tobebonze);

static char * ask_for_join(CNpc * me, CChar * who)
{
    if ( DIFFERSTR(who->querystr("family/family_name"), "峨嵋派")) 
        return "你和峨嵋没有渊源，贫尼不敢给你剃度。";

	if( who->query("bonze/justonetime"))
		return "施主既已还俗，又何苦再次出家？";

	if( EQUALSTR(who->querystr("class"), "bonze") )
        return "阿弥陀佛！出家人不打诳语。你已经是出家人了。";

    if( DIFFERSTR(who->querystr("gender"), "女性") )
        return "阿弥陀佛！善哉！善哉！施主若真心皈依我佛，可去少林寺受戒。";

    who->set_temp("pending/join_bonze", 1);
        
	me->say("阿弥陀佛！善哉！善哉！施主若真心皈依我佛，请跪下受戒。", who);
    me->say("记住，一旦出了家，是不能还俗的，否则将会受到惩罚。", who);
	me->AddMenuItem("跪下受戒", "$0kneel $1", who);
	me->AddMenuItem("转身离开", "", who);
	me->SendMenu(who);
	return 0;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "kneel") == 0)
	{
		return do_kneel(me);
	}

	return CNpc::handle_action(comm, me, arg);
}

int do_kneel(CChar * me)
{
    char prename[][3] ={ "灵","理"};
    char name[3], new_name[40], msg[255];

    if( ! me->query_temp("pending/join_bonze") ) return 0;

    message_vision("$N你双手合十，恭恭敬敬地跪了下来。\n$n看着$N说道：好吧，你就在本庵修行吧。\n$n伸出手掌，在$N头顶轻轻地摩挲了几下，将$N的头发尽数剃去。\n", me, this);
    
	strncpy(name, me->name(1), 2)[2] = 0;
	snprintf(new_name, 40, "%s%s", prename[random(2)], name);
    
    say(snprintf(msg, 255, "从今以后你的法名叫做%s。", new_name), me);
    command(snprintf(msg, 255, "chat 0 %s削发为尼，在峨嵋山修行，取法名%s。", me->name(), new_name) );
    g_Channel.do_emote(this, 0, "smile", 0);
    me->set("bonze/old_name", me->name());
    me->delete_temp("pending/join_bonze");
    me->set_name( new_name);
    me->set("class", "bonze");
    me->set("K_record", me->query("pks") + me->query("mks"));
    me->set("shen_record", me->query("repute"));
    me->set("repute", 0l);
	me->set("bonze/justonetime", 1);

	me->UpdateMe();
    return 1;
}

NPC_END;
