//wangling.h

//Sample for room: 西夏王陵
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_wangling);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "西夏王陵");

	//add npcs into the room
	//add_npc("pub_shiwushi");/////////////////////////

//	add_door("灵州清新泉", "灵州清新泉", "灵州西夏王陵");
//	add_door("灵州赤陵", "灵州赤陵", "灵州西夏王陵");

	set("long", "这里是西夏历代皇帝的陵墓。座落在灵州西北，周围四山环抱，环境非常幽静，周围种满了苍松翠柏，其中当今西夏皇帝李元昊的父亲赵德明的陵墓最为雄伟，概因西夏虽自唐初开国，然直至宋初赵德明才称皇帝，所以李元昊常自比为李世民第二，而把他父亲陵墓造的异常宏大。");  
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
