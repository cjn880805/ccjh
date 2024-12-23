//yamen.h

//Sample for room: 衙门
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_yamen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "衙门");

	//add npcs into the room
	add_npc("pub_yayi");/////////////////////////
	add_npc("helpnpc018");

	add_door("灵州东", "灵州东", "灵州衙门");

	set("long", "这是灵州府衙所在地，黑色大门平时紧紧闭着，门前四个身着皂服的衙役没精打采的拄着水火棍站着。边上有个大鼓。");  
	
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
