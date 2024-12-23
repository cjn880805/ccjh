//shenlong.h

#define SHENLONG_BEGIN(npc_name)	class npc_name : public CNshenlong	{	public:	npc_name(){};	virtual ~npc_name(){};
#define SHENLONG_END		};	

NPC_BEGIN(CNshenlong);

virtual void attempt_apprentice(CChar * player)
{
	char msg[255];

	if (DIFFERSTR(player->querystr("party/party_name"), "神龙教"))
	{
		say("你不是本教教众, 想来找死啊!",player);
		SendMenu(player);
		return;
	}
	if (player->query("repute") > 0  ) 
	{
		say("我神龙教与世隔绝，向来不与您这种白道人物打交道，您请回吧！",player);
		SendMenu(player);
		return;
	}

	say("很好，很好。");
	command(snprintf(msg,255,"recruit %ld",player->object_id()) );
}

virtual char * chat_msg_combat()
{
	switch(random(3))
	{
	case 0:
			perform_action("sword chang", 1);
			break;
	case 1:
			perform_action("sword chang2", 1);
			break;
	case 2:
			perform_action("sword chang3", 1);
			break;
	}

	return 0;
}

NPC_END;