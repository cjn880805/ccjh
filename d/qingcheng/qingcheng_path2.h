//path2.h

//Sample for room: 青城山路2
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRQingCheng_path2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "青城山路2");
	
	add_npc("pub_punk");          //add by zdn 2001-07-14


	add_door("青城天师洞", "青城天师洞", "青城山路2");
	add_door("青城天然图画", "青城天然图画", "青城山路2");

	set("long","你走在青城山路上。山木蔽日，幽静宜人。西上就是天师洞，东边是天然图画。");
    

/*****************************************************
    set("outdoors","qingcheng");
	set("exits", ([
		"westup"   : __DIR__"tianshidong",
		"eastdown" : __DIR__"tianran",
	]));
*****************************************************/
};


ROOM_END;
