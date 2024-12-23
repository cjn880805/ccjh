//baihudating.h

//Sample for room: 白虎堂大厅
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_baihudating);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "白虎堂大厅");
	
	add_npc("heimuya_shanggy");    //add by zdn 2001-07-20


	add_door("黑木崖林间小道", "黑木崖林间小道", "黑木崖白虎堂大厅");
	add_door("黑木崖长廊", "黑木崖长廊", "黑木崖白虎堂大厅");

	set("long", "这是『日月神教』下第二大堂：白虎堂的大厅，四目望去，一地都是鲜血，显然不久前这里有一场大战。堂梁上有一块旧木匾(bian)。堂上北壁上有几个血字(zi)。");
    

/*****************************************************
        set("exits", ([
            "west" : __DIR__"baistep1",
            "east" : __DIR__"linjxd6",
        ]));
        set("item_desc", ([
            "bian": "上面写到：长河落日，白虎在天；
                     千秋万载，一统江湖 。\n",
            "zi" : "上面写到：华山弟子，势杀邪教。\n" 
	]) );
********************************************/
};


ROOM_END;
