//tyroad10.h

//Sample for room: �䵱��԰С·10
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_tyroad10);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�䵱��԰С·10");


	add_door("�䵱��԰С·9", "�䵱��԰С·9", "�䵱��԰С·10");
	add_door("�䵱��԰С·1", "�䵱��԰С·1", "�䵱��԰С·10");

    	

/*****************************************************
	set("outdoors", "wudang");
	set("exits", ([
		"east" : __DIR__"gyroad2",
		"west" : __DIR__"tyroad9",
	]));
*****************************************************/
};


ROOM_END;
