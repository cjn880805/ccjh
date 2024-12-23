//mtxiaowu.h

//Sample for room: 侠客岛木屋
//coded by zouwenbin
//data: 2000-11-13
//neiting
ROOM_BEGIN(CRXiaKeDao_mtxiaowu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "侠客岛木屋");
	
	add_npc("pub_tongzi");        //add by zdn 2001-07-20


	add_door("侠客岛摩天崖", "侠客岛摩天崖", "侠客岛木屋");

	set("long", "这里是一个很小的木屋，室中放着一些乱七八遭的家具，墙角边还有一张破烂的小床，有一个英俊的少年在屋内走来走去，似乎有什么心事，不时的发出几声长叹......" );
    

/*****************************************************
       set("exits", ([
           "west" : __DIR__"mtdating",
       ]));
       set("objects",([
           __DIR__"npc/shizhongyu" : 1,
       ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp