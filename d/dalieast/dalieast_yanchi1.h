//yanchi1.h

//Sample for room: 大理城沿池堤岸1
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_yanchi1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城沿池堤岸1");

	set("resident", "罗伽甸");

	add_npc("pub_girl1");        // zdn 2001-07-12   add

	add_door("大理城滇池", "大理城滇池", "大理城沿池堤岸1");
	add_door("大理城金汁河畔", "大理城金汁河畔", "大理城沿池堤岸1");
	add_door("大理城沿池堤岸2", "大理城沿池堤岸2", "大理城沿池堤岸1");

	set("long", "这里沿湖堤岸遍植白色的素馨花，故又称“银棱河”；而它的一条分支，堤岸栽种黄色的迎春花，故称“金棱河”，或金汁河。两河同为滇池的出水口，又称海口。" );
	
};


RESIDENT_END;
