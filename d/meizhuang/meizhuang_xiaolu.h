//xiaolu.h

//Sample for room:  ÷ׯ����С��
//coded by zouwenbin
//data: 2000-12-2

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRMeiZhuang_xiaolu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "÷ׯ����С��");
	
	add_npc("animal_dog");        //add by zdn 2001-07-14
	add_item("meishu");

	add_door("÷ׯ��ɽʯ��", "÷ׯ��ɽʯ��", "÷ׯ����С��");
	add_door("÷ׯ����", "÷ׯ����", "÷ׯ����С��");
	

    

/******************************************************************************
        set("exits", ([  
            "south" : __DIR__"shijie",
            "north" : __DIR__"gate",
        ]));
        set("outdoors", "meizhuang");
******************************************************************************/
};


ROOM_END;
