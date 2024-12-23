//qianchi.h

//Sample for room: 华山千尺幢
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_qianchi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "华山千尺幢");

	//add npcs into the room
	add_npc("pub_youke");
	add_npc("huashan_cong_buqi");

	add_door("华山回心石", "华山回心石", "华山千尺幢");
	add_door("华山百尺峡", "华山百尺峡", "华山千尺幢");

	set("long", "前面有一斜如天垂石梯的山阶，这就是赫赫有名的千尺幢，千尺幢是依一陡峭岩脊的裂缝开凿而成，斜度约七十度，高约二十米，仅容一人上落。抬头仅见一线天光，两旁岩壁陡峭，尽头是个仅能容身的方形石洞，俗称“天井”，天井旁的危崖上刻有“太华咽喉”的题刻。");  
    
 
/*****************************************************
        set("exits", ([  
            "westdown" : __DIR__"huixinshi",
            "southup" : __DIR__"baichi",
        ]));
        set("objects", ([
            __DIR__"npc/youke": 2,
        ]));
********************************************/
};


ROOM_END;
