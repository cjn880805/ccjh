//zoulang2.h

//Sample for room:  ÷ׯ����2
//coded by zouwenbin
//data: 2000-12-2

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRMeiZhuang_zoulang2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "÷ׯ����2");
	
	add_npc("pub_lady3");       //add by zdn 2001-07-14

	add_door("÷ׯ����1", "÷ׯ����1", "÷ׯ����2");
	add_door("÷ׯ����", "÷ׯ����", "÷ׯ����2");
	add_door("÷ׯ��Ϣ��", "÷ׯ��Ϣ��", "÷ׯ����2");
	add_door("÷ׯ����", "÷ׯ����", "÷ׯ����2");
	
	set("long", "����һ�����������ȣ�������������λׯ���е�������λƽʱ��Ϣ�������ĵط����������������ң��ұ�����÷ׯ���Ӹо��Ͷٵ�ʱ����Ϣ�ĵط�����ׯ���ڰ��Ӳ�����ҹ�����������о�����Щ��֪���Ķ������Ĺ����ס� " );
    

/******************************************************************************
        set("exits", ([  
            "west" : __DIR__"qishi",
            "east" : __DIR__"xiuxishi",
            "north" : __DIR__"zoulang3",
            "south" : __DIR__"zoulang1",
        ]));
******************************************************************************/
};


ROOM_END;
