//neitang.h

//Sample for room:  ÷ׯƫ��
//coded by zouwenbin
//data: 2000-12-2

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRMeiZhuang_neitang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "÷ׯƫ��");
	
	add_npc("pub_lady3");        //add by zdn 2001-07-14

	add_door("÷ׯ��ľ԰", "÷ׯ��ľ԰", "÷ׯƫ��");
	

    

/******************************************************************************
        set("exits", ([  
            "east" : __DIR__"senlin1",
        ]));

        
        set("item_desc", ([
            "eye": "һ��а�����ȸʯ������ҫ�۵ĺ�⡣\n"
        ]) ); 
******************************************************************************/
};


ROOM_END;
