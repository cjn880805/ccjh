//shanjiao.h

//Sample for room: ÁéğÕçÎç¿·åÉ½½Å
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_shanjiao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ÁéğÕçÎç¿·åÉ½½Å");
	
	add_npc("pub_guest");           //add by zdn 201-07-17


	add_door("ÁéğÕ¶Ï»êÑÂ", "ÁéğÕ¶Ï»êÑÂ", "ÁéğÕçÎç¿·åÉ½½Å");
	add_door("Î÷ÓòÌìÉ½É½Â·2", "Î÷ÓòÌìÉ½É½Â·2", "ÁéğÕçÎç¿·åÉ½½Å");

/*****************************************************
    set("outdoors", "lingjiu");
	set("exits", ([
		"westup" : __DIR__"ya",
		"southdown" : "/d/xingxiu/tianroad2"
        ]));
	set("objects",([
		__DIR__"npc/jiuyi" : 1,
       	]));
********************************************/
};


ROOM_END;
