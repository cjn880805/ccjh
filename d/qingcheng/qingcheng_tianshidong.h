//tianshidong.h

//Sample for room: 天师洞
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRQingCheng_tianshidong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "天师洞");
	
	add_npc("pub_menmian");          //add by zdn 2001-07-14
	add_npc("pub_xiaomimi"); 

	add_door("青城山路2", "青城山路2", "青城天师洞");
	add_door("青城三岛石", "青城三岛石", "青城天师洞");
	add_door("青城古龙桥", "青城古龙桥", "青城天师洞");
	add_door("青城古银杏树", "青城古银杏树", "青城天师洞");


    

/*****************************************************
	set("exits", ([
		"northup"  : __DIR__"gulongqiao",
		"north"    : __DIR__"sanqingdian",
		"eastdown" : __DIR__"path2",
		"west"     : __DIR__"yinxing",
		"east"     : __DIR__"sandaoshi",
	]));
*****************************************************/
};


ROOM_END;
