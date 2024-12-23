//xiaolu2.h

//Sample for room: 灵州林中小路2
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_xiaolu2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "灵州林中小路2");
	
	add_npc("monster_20k");      //add by zdn 2001-07-14
	add_npc("pub_gaoming");


	add_door("灵州林中小路1", "灵州林中小路1", "灵州林中小路2");
	add_door("灵州林中小路3", "灵州林中小路3", "灵州林中小路2");
	add_door("灵州八仙道观", "灵州八仙道观", "灵州林中小路2");

};


ROOM_END;




