//jiaxingcity.h

//Sample for room:  嘉兴城
//coded by Fisho
//data: 2000-11-4


RESIDENT_BEGIN(CRjiaxingcity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "嘉兴城");

	//add npcs into the room

	add_npc("pub_boy");
	add_npc("pub_kid");
	add_npc("pub_thief");

	set("resident", "嘉兴");


	add_door("嘉兴南门", "嘉兴南门", "嘉兴城");
	add_door("嘉兴南湖", "嘉兴南湖", "嘉兴城");	

	add_door("嘉兴铁枪庙", "嘉兴铁枪庙", "嘉兴城");
	add_door("嘉兴烟雨楼", "嘉兴烟雨楼", "嘉兴城");


/********************************************************
	set("long", @LONG
这里是江南名城嘉兴。城东是风景如画的南湖。城北早先有座醉仙楼，
当年全真七子之一的丘处机和江南七怪就在那里盟约寻找忠良之后。不知
道什么原因店主把它迁到扬州了。
LONG );
	set("exits", ([
                "west" : __DIR__"qzroad2",
                "east" : __DIR__"nanhu",
		"south" : __DIR__"jxnanmen",
	]));
****************************************************************/
};


RESIDENT_END;
