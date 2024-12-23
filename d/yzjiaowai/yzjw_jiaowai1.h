//yzjw_jiaowai1.h

//Sample for room:  ���ݲݵ�1
//coded by zwb
//data: 2000-11-22

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRYZJW_jiaowai1);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ݲݵ�1");

	//add npcs into the room
	add_npc("pub_liumang");
	add_npc("pub_girl1");           //add by zdn 2001-07-16
	add_npc("helpnpc022");

	//add exits for room
	//the first param: door id
	//from the second to the fifth params: position of door
	//the sixth param: to next room
	//the seventh param: to next door id of next room
	add_door("���ݶ���","���ݶ���","���ݲݵ�1");
	add_door("��������2","��������2","���ݲݵ�1");

    set("long","�������ݽ����һƬ���ݵأ���Ӣ�ͷף������裬��¶Ϧ�⣬������Ƣ�����Ǻ�ʱ�⡣ż�м���С��Ů���̤�࣬ݺ����Ӱ�����ֶ���.");
	

/********************************************************
    set("exits", ([
        "north" : __DIR__"dongmen",
        "south" : __DIR__"jiaowai2",
        "west"  : __DIR__"course",
        "east"  : __DIR__"bite",
    ]));

    set("outdoors", "yangzhou");
    create_door("east", "����С��", "west", DOOR_CLOSED);
    create_door("west", "����С��", "east", DOOR_CLOSED);
*********************************************************/
};


ROOM_END;
