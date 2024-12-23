//wuyiminju4.h

//Sample for room: 乌夷民居4
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRDaLiWest_wuyiminju4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "乌夷民居4");

	//add npcs into the room
	add_npc("pub_kid");
	
	add_door("大理城易溪部", "大理城易溪部", "大理城乌夷民居4");

	set("long", "这是一座用木柴及兽皮搭成的乌夷民居。此地的村民主要从事耕作，由于实行换季轮耕，不得不经常迁徙，因而房舍都颇简陋，说是房舍，倒不如说更象帐篷，拆、建都甚方便。--大理城，西去则进入深山。由于接近大理中心，这条路修整的相当平整，尽管山势崎岖，行路并不困难。" );
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
