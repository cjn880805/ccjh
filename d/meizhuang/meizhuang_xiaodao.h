//xiaodao.h

//Sample for room:  ÷ׯС·
//coded by zouwenbin
//data: 2000-12-2

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRMeiZhuang_xiaodao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "÷ׯС·");
	
	add_npc("pub_lady3");       //add by zdn 2001-07-14
	add_item("meishu");

	add_door("÷ׯ�滱��", "÷ׯ�滱��", "÷ׯС·");
	add_door("÷ׯ����СԺ", "÷ׯ����СԺ", "÷ׯС·");
	

    

/******************************************************************************
        set("exits", ([  
            "north" : __DIR__"xiaoyuan",
            "westdown" : __DIR__"qhpo",
        ]));
        set("outdoors", "meizhuang");
******************************************************************************/
};


ROOM_END;
