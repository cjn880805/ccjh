//qcroad1.h

//Sample for room: 青城青石大道
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRQingCheng_qcroad1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "青城青石大道");
	
	add_npc("pub_playboy");
	add_npc("pub_daoke");         //add by zdn 2001-07-14


	add_door("青城小桥", "青城小桥", "青城青石大道");
	add_door("成都府河桥", "成都府河桥", "青城青石大道");


    

/*****************************************************
    set("outdoors","qingcheng");
	set("exits", ([
		"south" : "/d/city3/fuheqiaon",
		"west"  : __DIR__"qcroad2",
	]));
*****************************************************/
};


ROOM_END;
