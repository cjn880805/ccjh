//hanhanquan.h

//Sample for room: 憨憨泉
//coded by zwb
//data: 2000-11-21

ROOM_BEGIN(CRSuZhou_hanhanquan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "憨憨泉");
	
	add_npc("pub_gongzi");      //add by zdn 2001-07-16


	add_door("苏州万景山庄", "苏州万景山庄", "苏州憨憨泉");

	set("long", "在山道西侧有一憨憨泉，系南朝梁代高僧憨憨尊者所开凿，距今一千四百多年。据说泉眼通海，姑又名“海涌泉”。水甚清冽为“天下第五泉”。石刻“憨憨泉”三字，系北宋吕升卿所题。" );
	
};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

ROOM_END;
