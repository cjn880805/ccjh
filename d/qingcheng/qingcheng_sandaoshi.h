//sandaoshi.h

//Sample for room: 青城三岛石
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRQingCheng_sandaoshi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "青城三岛石");
	
	add_npc("pub_playboy");           //add by zdn 2001-07-14


	add_door("青城天师洞", "青城天师洞", "青城三岛石");
	add_door("青城听泉亭", "青城听泉亭", "青城三岛石");

	
    

/*****************************************************
        set("outdoors","qingcheng");
	set("exits", ([
		"west"     : __DIR__"tianshidong",
		"eastdown" : __DIR__"tingquanting",
	]));
*****************************************************/
};


ROOM_END;
