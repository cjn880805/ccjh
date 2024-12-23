//shenlong.h
//lanwood 2001-01-05
//神龙教NPC
#define NPCSHENLONG_BEGIN(npc_name) class npc_name : public CNShenLong	{	public:	npc_name(){};	virtual ~npc_name(){};
#define NPCSHENLONG_END		};	

NPC_BEGIN(CNShenLong);

virtual char * chat_msg_combat()
{
	switch(random(15))
	{
	case 0:
		g_Channel.do_emote(this, 0, "smile", 0);
		break;
	case 1:
		g_Channel.do_emote(this, 0, "haha", 0);
		break;
	case 2:
		say("凭你也敢在太岁爷头上动土? ");
		break;
	case 3:
		say("你活得不耐烦了找死啊？ ");
		break;
	case 4:
	case 5:
	case 6:
		perform_action("staff chang", 1);
		break;
	case 7:
	case 8:
	case 9:
		perform_action("staff chang2", 1);
		break;
	case 10:
	case 11:
	case 12:
		perform_action("staff chang3", 1);
		break;
	case 13:
	case 14:
		perform_action("force recover", 0);
		break;
	}

	return 0;
}

NPC_END;