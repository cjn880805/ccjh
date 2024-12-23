//ximenroad.h

//Sample for room:  �������Ŵ��
//coded by zwb
//data: 2000-11-22

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRYZJW_ximenroad);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�������Ŵ��");

	add_npc("pub_boy");

	add_door("��������","��������","�������Ŵ��");
	add_door("���������","���������","�������Ŵ��");
	add_door("���������","���������","�������Ŵ��");


/********************************************************
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"east"  : __DIR__"ximen",
  		"west"  : "/d/city4/road1",
		"south" : __DIR__"wudao4",
	]));
        set("objects", ([
            "/d/village/npc/boy" : 3,
        ]));
********************************************************/
 
};


ROOM_END;
