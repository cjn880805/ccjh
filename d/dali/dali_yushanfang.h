//yushanfang.h

//Sample for room: 御膳坊
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRDali_yushanfang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "御膳坊");

	//add npcs into the room
	add_npc("pub_taijian");
	
	add_door("大理城皇宫前殿", "大理城皇宫前殿", "大理城皇宫御膳坊");

	set("long", "这里是大理国皇宫的御膳坊，这里的厨具都是金银做成的。皇帝不在这里也就息火了，往东是长廊。" );

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
