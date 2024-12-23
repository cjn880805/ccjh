//road1.h

//Sample for room: 林间道1
//coded by zwb
//data: 2000-11-23

ROOM_BEGIN(CRFoShan_road1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "佛山林间道1");

	//add npcs into the room
//	add_npc("animal_huananhu");
	add_npc("pub_punk");  //add by zdn 2001-07-13	

	CBox * box = Add_Box();
	box->add_object("shikuai", 1);	
	box->set_name( "铁柜");		
	
	add_door("大理城黄土路", "大理城黄土路", "佛山林间道1");
	add_door("佛山林间道2", "佛山林间道2", "佛山林间道1");

	set("long", "这里是一条林间小道，在树丛中蜿蜒。这里向东是广西。向西北走就是大理国的地界了。" );

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
