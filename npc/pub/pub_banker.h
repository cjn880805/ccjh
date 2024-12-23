//Sample for NPC: 钱庄老板
//coded by Lanwood
//data: 2000-10-26

//use macro NPC_BEGIN(npc_name) to declare room
//and use macro NPC_END end declare
BANKOWNER_BEGIN(CNpub_banker);

//npc_name must use "CN-" begin since it belongs npc class
//Example: Song Shi fu named "CNXiangYang_Song"

//under, we will custom our npc

virtual void create()		//Call it when the npc is created
{
	set_name("钱庄老板", "lao ban");

	set("icon", pawnshop_boss);
	set("age", 30);
	set("gender", "男性");

	set("con", 10);			//construction is 10
	set("str", 28);			//strength is 28
	set("int", 20);			//intellegent is 20
	set("dex", 28);			//dexterity is 28

	set("combat_exp", 500);
	set("max_hp", 900l);
	
	set("chance", 5);		
	set("chance_combat", 20);

};

virtual char * combat_chat_msg()
{
	switch(random(4))
	{
	case 0:
		return "钱庄老板说：不好玩";
	case 1:
	case 2:
		return "钱庄老板说：有什么的，哼！";
	case 3:
		return "钱庄老板说：不好吧。";
	}

	return "";
}


BANKOWNER_END;
//last, register the npc into ../server/NpcSetup.cpp