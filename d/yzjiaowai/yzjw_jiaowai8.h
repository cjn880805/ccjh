//yzjw_jiaowai8.h

//Sample for room:  ���ݲݵ�8
//coded by zwb
//data: 2000-11-22

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRYZJW_jiaowai8);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ݲݵ�8");

	//add npcs into the room
	add_npc("pub_poorman");       //add by zdn 2001-07-16

	//add exits for room
	//the first param: door id
	//from the second to the fifth params: position of door
	//the sixth param: to next room
	//the seventh param: to next door id of next room
	add_door("��������","��������","���ݲݵ�8");
	add_door("��������9","��������9","���ݲݵ�8");

    set("long","�������ݽ����һƬ���ݵأ���Ӣ�ͷף������裬��¶Ϧ�⣬������Ƣ�������ѿ�����������ʱ��");
    

/********************************************************
    set("exits", ([
        "east" : __DIR__"nanmen",
        "west" : __DIR__"jiaowai9",
    ]));
********************************************************/
 
};


ROOM_END;
