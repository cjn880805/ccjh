//jiudain.h

//Sample for room: 春在楼
//coded by Fisho
//data: 2000-11-3

ROOM_BEGIN(CRSuZhou_jiudain);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "春在楼");

	//add npcs into the room
	add_npc("pub_xiaoer2");/////////////////////////

	add_door("苏州北", "苏州北", "苏州春在楼");

	set("long", "这是一座苏州城里有名的酒楼，整个楼面以雕刻为特色，砖雕，木雕，石雕。走进楼内，一眼便看到一副八仙上寿图，八仙人被描画的惟妙惟肖。楼内许多南北来往的门客正在聊天品茶，只见店小二忙的不亦乐乎。" );
 	set("outdoors", "suzhou");
};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}
ROOM_END;
