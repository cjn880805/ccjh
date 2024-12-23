//jingzhuang1.h

//Sample for room: 大理城经幢1
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaliEast_jingzhuang1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城经幢1");


	add_door("大理城金汁河畔", "大理城金汁河畔", "大理城经幢1");
//	add_door("大理城经幢2", "大理城经幢2", "大理城经幢1");

	set("long", "雕四大天王像，高约四尺，批甲戴胄，手持斧钺，威严庄重。三人足踏鬼奴。一鬼奴肌肉暴起，右手挽蛇，蛇嘴正触鬼奴下腭；另俩鬼奴戴镣。一天神足下三人，中间一人正以双手各托天王一足。天王之间遍刻梵文佛经。" );
	

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
