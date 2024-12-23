//Sample for NPC: Ç®×¯ÀÏ°å
//coded by Lanwood
//data: 2000-10-26

//use macro NPC_BEGIN(npc_name) to declare room
//and use macro NPC_END end declare
BANKOWNER_BEGIN(CNBanker);

//npc_name must use "CN-" begin since it belongs npc class
//Example: Song Shi fu named "CNXiangYang_Song"

//under, we will custom our npc

virtual void create()		//Call it when the npc is created
{
	set_name( "Ç®×¯ÀÏ°å");

	set("icon", pawnshop_boss);
	set("age", 30);
	set("sex", "ÄÐÐÔ");

	set("con", 10);			//construction is 10
	set("str", 28);			//strength is 28
	set("int", 20);			//intellegent is 20
	set("dex", 28);			//dexterity is 28

	set("combat_exp", 500);
	set("max_hp", 900l);
	
	set("chance", 5);		
	set("chance_combat", 10);

};

BANKOWNER_END;
//last, register the npc into ../server/NpcSetup.cpp