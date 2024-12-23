//deling.h

//Sample for room: 灵州德陵
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_deling);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "灵州德陵");

	//add npcs into the room
	//add_npc("pub_shiwushi");/////////////////////////

//	add_door("灵州赤陵", "灵州赤陵", "灵州德陵");
//	add_door("灵州恭陵", "灵州恭陵", "灵州德陵");

	set("long", "这就是李元昊的父亲赵德明的陵墓。宽十米高五米，为整个王陵中最高大也是最完整的建筑。陵前左右各有两个石人武士护卫，陵前有汉白玉栏杆围成的平台，上面石桌石凳一应俱全。");  

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
