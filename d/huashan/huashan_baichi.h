//baichi.h

//Sample for room: 华山百尺峡
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_baichi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "华山百尺峡");


	add_door("华山千尺幢", "华山千尺幢", "华山百尺峡");
	add_door("华山平心石", "华山平心石", "华山百尺峡");

	set("long", "走过千尺幢，前面又见另一要命的百尺峡，百尺峡不似千尺幢般险峻，但亦十分陡峭，岩壁两侧设有铁索以作扶拦。百尺峡又称百丈崖，是一座壁立千仞的悬崖。崖底到上面的最低的垭口处约百尺，故有是名。");  
    
 
/*****************************************************
        set("exits", ([  
            "northdown" : __DIR__"qianchi",
            "eastup"    : __DIR__"pingxinshi",
        ]));

********************************************/
};


ROOM_END;
