//buwei3.h

//Sample for room: 华山偏厅
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_buwei3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "华山偏厅");

	add_npc("pub_qiufengcheng");
	add_door("华山有所不为轩", "华山有所不为轩", "华山偏厅");

	set("long", "偏厅里供奉着华山历代祖师的神位。正中神案的墙上是华山派开山祖师风祖师的画象。画象神情清隽，非常传神。神案上香炉里插着三柱清香，香烟袅袅上升，散发着一股檀香味。西面有扇门通往外面的正厅.");  
    
    set("valid_startroom","1");
 
/*****************************************************
        set("exits", ([  
            "west" : __DIR__"buwei1",
	]));
********************************************/
};


ROOM_END;
