//gytoad2.h

//Sample for room: 武当果园小路2
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_gytoad2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武当果园小路2");


	add_door("武当果园小路1", "武当果园小路1", "武当果园小路2");
	add_door("武当桃园", "武当桃园", "武当果园小路2");

    	
	set("guocount",1);

/*****************************************************
	set("outdoors", "wudang");
	set("item_desc", ([
		"tree" : 
"这是一株人参果树，上面结着人参果，据说摘下吃了对武功进益很有好处。\n"
	]));
	set("exits", ([
		"west" : __DIR__"gyroad1",
	]));
*****************************************************/
};


ROOM_END;
