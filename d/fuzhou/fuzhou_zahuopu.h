//zahuopu.h

//Sample for room: 杂货铺
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRfuzhou_zahuopu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杂货铺");

	//add npcs into the room
	add_npc("pub_chen");
	
	add_door("福州南", "福州南", "福州杂货铺");

    set("long", "这里是一家专卖女人用的东西的小铺子。" );

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
