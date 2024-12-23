//yishitang.h

//Sample for room: 议事堂
//coded by zouwenbin
//data: 2000-11-15

ROOM_BEGIN(CRDaLisouth_yishitang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "议事堂");

	//add npcs into the room
	add_npc("pub_zuzhang");
	add_npc("pub_shouling");      //add by zdn 2001-07-20
	
	add_door("大理城南大竹楼", "大理城南大竹楼", "大理城南议事堂");
	add_door("大理城南祭祀屋", "大理城南祭祀屋", "大理城南议事堂");

	set("long", "这间大竹楼的中层是普麽部的议事堂，村中长老逢要日便在此聚议族内大事，也在此接待外族贵客，或会晤大理国官府派来的使者。屋内以本族的图腾壁画、鸟兽皮毛装饰四壁。" );
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
