//yixibu.h

//Sample for room: 易溪部
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRDaLiWest_yixibu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "易溪部");

	//add npcs into the room
	add_npc("pub_shaonu");
	
	add_door("大理城阿头部", "大理城阿头部", "大理城易溪部");
	add_door("大理城碧罗山下", "大理城碧罗山下", "大理城易溪部");
	add_door("大理城乌夷民居4", "大理城乌夷民居4", "大理城易溪部");

	set("long", "易溪部也是乌夷族乌杂蛮的部落。这里处半坡地，附近有不少农田，但农业落后，需要换季轮耕，因而村民经常迁徙，镇子里除了祭祀大屋外，其它房屋都很简陋。--大理城，西去则进入深山。由于接近大理中心，这条路修整的相当平整，尽管山势崎岖，行路并不困难。" );
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
