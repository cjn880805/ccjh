//cave.h

//Sample for room: 岩洞
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRBaiTuoShan_cave);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "岩洞");

	//add npcs into the room
	add_npc("animal_mangshe");
	add_npc("pub_jinhua");
	
	add_door("白驼山竹林", "白驼山竹林", "白驼山岩洞");

	set("long", "这里是大岩洞，它是在『白驼山』特殊的地质条件下经过漫长的年代形成的。南边是青竹林。再往北走就进洞了。");  

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
