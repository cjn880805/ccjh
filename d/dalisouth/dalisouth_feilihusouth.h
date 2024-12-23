//feilihusouth

//Sample for room: 妃丽湖南岸
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaLisouth_feilihusouth);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "妃丽湖南岸");

	set("resident", "喜州");

	add_npc("pub_boy");
	add_npc("pub_playboy");    // add by zdn 2001-07-13

	add_door("大理城河西镇", "大理城河西镇", "大理城妃丽湖南岸");


	set("long", "这里是休猎部的渔船码头。岸边有台夷村民正在扎制竹筏，一些渔民划着竹筏下湖捕鱼，新鲜的鱼鳖可以在附近的喜州、龙口等城镇卖出好价钱。" );
};


RESIDENT_END;
