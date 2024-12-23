//qingzhulin.h

//Sample for room: 青竹林
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaLisouth_qingzhulin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "青竹林");

	//add npcs into the room
	add_npc("pub_caisunren");
	add_npc("wei_ake");
	
	add_door("大理城武定镇", "大理城武定镇", "大理城青竹林");

	set("long", "一大片茂密的青竹林向西面山里蔓延出去。此间竹子青嫩，竹笋遍地，附近卢鹿族的台夷妇女常前来采摘竹笋为食，另外也砍伐些青竹用来制做竹筒和编织的竹篾筐篓。" );
	
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
