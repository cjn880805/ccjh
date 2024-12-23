//riyuetan.h

//Sample for room: 台湾日月潭
//coded by Fisho
//data: 2000-11-4

ROOM_BEGIN(CRTaiWan_riyuetan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "台湾日月潭");

	set("monster_chance", 20);
	add_npc("pub_wangyiming");
	add_npc("pub_wangyipeng");

	add_door("台湾荒地", "台湾荒地", "台湾日月潭");

	set("long", "翠峰环抱，湖水澄碧的日月潭，潭北形如日轮，潭南弯曲如月，为台湾避暑胜地。  " );
	

/*****************************************************
	set("exits", ([
                "westdown" : __DIR__"chiqian",
	]));
********************************************/
};


ROOM_END;
