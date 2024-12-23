//tygate2.h

//Sample for room: 武当桃园篱笆2
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_tygate2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武当桃园篱笆2");


	add_door("武当桃园小路8", "武当桃园小路8", "武当桃园篱笆2");

	set("long","你走在一条通往桃树林深处的小道上，前面有个桃木门(door)。");
    

/*****************************************************
	set("outdoors", "wudang");
	set("item_desc",([
		"door"	:	"\n\t\t\t桃木门上有首诗：\n\n\n" 
					"\t\t∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷\n"
					"\t\t∷∷∷　　　　　　　　　　　　　　　∷∷∷\n"
					"\t\t∷∷∷　去　年　今　日　此　门　中　∷∷∷\n"
					"\t\t∷∷∷　　　　　　　　　　　　　　　∷∷∷\n"
					"\t\t∷∷∷　人　面　桃　花　相　映　红　∷∷∷\n"
					"\t\t∷∷∷　　　　　　　　　　　　　　　∷∷∷\n"
					"\t\t∷∷∷　人　面　不　知　何　处　去　∷∷∷\n"
					"\t\t∷∷∷　　　　　　　　　　　　　　　∷∷∷\n"
					"\t\t∷∷∷　桃　花　依　旧　笑　春　风　∷∷∷\n"
					"\t\t∷∷∷　　　　　　　　　　　　　　　∷∷∷\n"
					"\t\t∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷\n\n\n",
							
	]));
	set("exits", ([
		"north" : __DIR__"tyroad10",
	]));
*****************************************************/
};


ROOM_END;
