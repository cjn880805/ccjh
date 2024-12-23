//huangdi.h

//Sample for room: 台湾荒地
//coded by Fisho
//data: 2000-11-4

ROOM_BEGIN(CRTaiWan_huangdi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "台湾荒地");

	set("monster_chance", 20);
	
	add_npc("pub_dipi");   //add by zdn 2001-07-16

	add_door("台湾赤嵌城", "台湾赤嵌城", "台湾荒地");
	add_door("台湾打狗港", "台湾打狗港", "台湾荒地");
//	add_door("台湾正药居民区", "台湾正药居民区", "台湾荒地");
	add_door("台湾鸡笼港", "台湾鸡笼港", "台湾荒地");
	add_door("台湾日月潭", "台湾日月潭", "台湾荒地");


/*****************************************************

********************************************/
};


ROOM_END;
