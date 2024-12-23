//jiudian.h

//Sample for room: 酒店
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRBaiTuoShan_jiudian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "酒店");

	//add npcs into the room
	add_npc("pub_xiaoer2");
	
	add_door("白驼山西街", "白驼山西街", "白驼山酒店");

	set("long", " 这里是一家独具特色的酒店，由于地处『白驼山』下，酒店可以供应风味食品－－蛇肉。许多中原来客都爱来尝尝鲜，所以酒店生意兴隆。酒店还经营打散装酒的业务。");
    set("resource/water", 1);

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
