//18hell_helldoor2.h

//Sample for room: 地狱之门
//coded by sound
//data: 2001-11-1

//ROOM_BEGIN(CRFoShan_beidimiao);
YEWAIDOOR_BEGIN(CR18hell_helldoor2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name("地狱之门2");

	add_npc("dy_master");

	CDoor * a = add_yewaidoor("west", 3, 20);
	CDoor * b = add_yewaidoor("north", 3, 20);
	CDoor * c = add_yewaidoor("east", 3, 20);
	CDoor * d = add_yewaidoor("south", 3, 20);

	a->set_name("十八地狱西门");
	b->set_name("十八地狱北门");
	c->set_name("十八地狱东门");
	d->set_name("十八地狱南门");

	set("long", "这里就是十八地狱的入口，进入这里，必须放弃一切希望。" );
	set("no_fight",  1);

};

YEWAIDOOR_END;
