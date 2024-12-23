//xiaodao2.h

//Sample for room: 大理城林间小道2
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_xiaodao2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城林间小道2");

	set("resident", "黑龙岭");

	add_npc("animal_snake");  //add by zdn 2001-07-12

	add_door("大理城南门", "大理城南门", "大理城林间小道2");
	add_door("大理城黑龙岭", "大理城黑龙岭", "大理城林间小道2");

	set("long", "这是一条卵石铺成的小道，曲曲折折地通向前方。两边是密密的树林这里人迹罕至，惟闻足底叩击路面，微风吹拂树叶，沙沙作响。" );
};

RESIDENT_END;
