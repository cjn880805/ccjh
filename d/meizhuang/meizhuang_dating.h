//dating.h

//Sample for room:  ÷ׯ�������
//coded by zouwenbin
//data: 2000-12-2

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRMeiZhuang_dating);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "÷ׯ�������");

	add_door("÷ׯ���쾮", "÷ׯ���쾮", "÷ׯ�������");
	add_door("÷ׯӭ��ͤ", "÷ׯӭ��ͤ", "÷ׯ�������");
	

    

/******************************************************************************
        set("item_desc", ([  
            "bian" : "������Ѿ��ܳ¾��ˣ�������ҡҡ�λεģ��ƺ������ʵ��\n",
        ]));
        set("exits", ([  
            "north" : __DIR__"keting",
            "south" : __DIR__"tianjing",
        ]));
******************************************************************************/
};


ROOM_END;
