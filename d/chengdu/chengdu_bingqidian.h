//bingqidian.h

//Sample for room: 兵器铺
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRChengDu_bingqidian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "兵器铺");

	//add npcs into the room
	add_npc("pub_tanglong");
	
	add_door("成都西", "成都西", "成都兵器铺");

	set("long",	"这着是一家小小店面的兵器铺，可是卖的兵器可不寻常。种类固然中土难得一见，能用的人更是稀少。掌柜的拿着眼瞟得你直发毛。你转脸就看到墙上的招牌(zhaopai)。"	);

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
