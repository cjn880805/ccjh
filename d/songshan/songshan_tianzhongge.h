//tianzhongge.h

//Sample for room: 天中阁
//coded by zouwenbin
//data: 2000-11-

ROOM_BEGIN(CRShongShan_tianzhongge);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "天中阁");

	//add npcs into the room
	add_npc("songshan_lu");         //add by zdn 2001-07-20

	add_door("嵩山太室阙", "嵩山太室阙", "嵩山天中阁");
	add_door("嵩山崇圣门", "嵩山崇圣门", "嵩山天中阁");

	set("long", "天中阁是中岳庙的大门，原称黄中阁。庙内有古柏三百余株，金石碑碣百余座。庙前石翁仲，雕制古朴。南面是嵩山的出口太室阙。 " );
	

/*****************************************************
	set("outdoors","songshan");
	set("exits", ([
		"north" : __DIR__"chongsheng",
		"south" : __DIR__"taishique",
	]));
	setup();
********************************************/
};


ROOM_END;
