//zoulang1.h

//Sample for room:  ÷ׯ����1
//coded by zouwenbin
//data: 2000-12-2

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRMeiZhuang_zoulang1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "÷ׯ����1");
	
	add_npc("pub_boy");     //add by zdn 2001-07-14

	add_door("÷ׯ��Ժ", "÷ׯ��Ժ", "÷ׯ����1");
	add_door("÷ׯ����2", "÷ׯ����2", "÷ׯ����1");
	add_door("÷ׯ����", "÷ׯ����", "÷ׯ����1");
	add_door("÷ׯ����", "÷ׯ����", "÷ׯ����1");
	
	set("long", "����һ�����������ȣ�������������λׯ���е�������λƽʱ��Ϣ�������ĵط����������������ң��ұ��ǻ��ң���ׯ��ͺ���̺���ׯ�����������������µ�ʱ�򣬱㵽������ȥ�Ӻ�����ī��   " );
    

/******************************************************************************
        set("exits", ([ 
            "west" : __DIR__"shushi",
            "east" : __DIR__"huashi",
            "north" : __DIR__"zoulang2",
            "south" : __DIR__"neiyuan",
        ]));
******************************************************************************/
};


ROOM_END;
