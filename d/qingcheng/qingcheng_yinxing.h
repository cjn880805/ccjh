//yinxing.h

//Sample for room: 青城古银杏树
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRQingCheng_yinxing);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "青城古银杏树");
	
	add_npc("qingcheng_jia");     //add by zdn 2001-07-20


	add_door("青城天师洞", "青城天师洞", "青城古银杏树");


    

/*****************************************************
        set("outdoors","qingcheng");
	set("exits", ([
		"east"     : __DIR__"tianshidong",
	]));
*****************************************************/
};


ROOM_END;
