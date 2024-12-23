//quanzhen.h
//全真通用NPC
//Lanwood 2000-01-05

#define NPCQUANZHEN_BEGIN(npc_name) class npc_name : public CNquanzhen	{	public:	npc_name(){};	virtual ~npc_name(){};
#define NPCQUANZHEN_END		};	

NPC_BEGIN(CNquanzhen);

virtual char * chat_msg_combat()
{
	switch(random(8))
	{
	case 0:
	case 1:
		perform_action("force recover", 0);
		break;
	case 2:
	case 3:
	case 4:
		perform_action("strike ju", 1);
		break;
	case 5:
	case 6:
	case 7:
		perform_action("sword ding", 1);
		break;
	}

	return 0;
}

NPC_END;