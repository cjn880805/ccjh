//yanan1.h

//Sample for room: 大理城滇池沿岸1
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_yanan1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城滇池沿岸1");

	set("resident", "罗伽甸");

	//add npcs into the room
	add_npc("pub_cunfu");
	
	add_door("大理城罗伽甸", "大理城罗伽甸", "大理城滇池沿岸1");
	add_door("大理城沿池小路2", "大理城沿池小路2", "大理城滇池沿岸1");

	set("long", "滇池名曰池，实际上是个很大的湖，四面山上水源众多，也浇灌了大片的农田。池水清澈凉爽，许多罗伽部的妇女在此洗衣挑水。摆夷并不以渔业为主，不过岸边仍然建有小码头，时常有游船停靠，也有少量竹舟下水打鱼。西边有条弯弯曲曲的小路沿着滇池南岸而去。" );
};

RESIDENT_END;
