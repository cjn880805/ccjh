//monster_huashan.h
//连成决任务NPC
//Lanwood 2001-02-07

#define MONSTERHUASHAN_BEGIN(npc_name)	class npc_name : public CNmonster_huashan	{	public:	npc_name(){};	virtual ~npc_name(){};
#define MONSTERHUASHAN_END		};	

NPC_BEGIN(CNmonster_huashan);

virtual char * chat_msg_combat()
{
	if(random(2) == 0 && query("hp") /2 < query("max_hp") / 3)
	{
		if(perform_action("force heal", 0))
			return 0;
	}

	if(random(3) == 0)
	{
		perform_action("force lieyan", 1);
		return 0;
	}

	if(random(7) == 0)
		perform_action("sword zhuang", 1);

	return 0;
}

NPC_END;