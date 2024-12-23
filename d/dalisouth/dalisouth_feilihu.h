//feilihu.h

//Sample for room: 妃丽湖畔
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaLisouth_feilihu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "妃丽湖畔");

	set("resident", "喜州");

	add_npc("pub_playboy");
	add_npc("pub_cunfu");   //add by zdn 2001-07-13

	add_door("大理城喜州城", "大理城喜州城", "大理城妃丽湖畔");
	add_door("大理城鲁望镇", "大理城鲁望镇", "大理城妃丽湖畔");
	add_door("大理城妃丽湖东", "大理城妃丽湖东", "大理城妃丽湖畔");

	set("long", "你站在妃丽湖的北岸，北边不远就是喜州城。此湖不大，但湖水清澈，鱼鳖皆有，不少台夷村民划着竹筏在湖上捕鱼。湖之南和东边半山上都有台夷村镇，有道路绕湖东而过通向南边。" );
};


RESIDENT_END;
