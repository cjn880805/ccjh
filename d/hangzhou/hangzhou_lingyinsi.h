//lingyinsi.h

//Sample for room: 杭州灵隐寺
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_lingyinsi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州灵隐寺");
	
	add_npc("pub_guest");           // add by zdn 2001-07-14


	add_door("杭州青石大道1", "杭州青石大道1", "杭州灵隐寺");
	add_door("杭州天王殿", "杭州天王殿", "杭州灵隐寺");

	set("long","灵隐寺又名云林寺，寺前有清澈的小溪，溪旁建有冷泉亭和赫雷亭。天王殿举目可见，殿外有两座经幢。往南便回到大道。" );

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
