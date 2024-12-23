//bijishan.h

//Sample for room: 大理城碧鸡山顶
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_bijishan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城碧鸡山顶");

	set("resident", "碧鸡山");

	//add npcs into the room
	add_npc("pub_youke");
	add_npc("dali_wuliangdizi");      //add by zdn 2001-07-20
	
	add_door("大理城清溪三潭", "大理城清溪三潭", "大理城碧鸡山顶");
	add_door("大理城沿池小路2", "大理城沿池小路2", "大理城碧鸡山顶");

	set("long", "碧鸡山坐在滇池的西岸上，与拓东城隔水相望。山势高耸入云，山形有如公鸡，漫山树木苍翠欲滴。此处乃是极顶，已达云端，东眺滇池一片汪洋，美不胜收。山下属大理国的昆州。东西皆有下山之路。" );

};

RESIDENT_END;
