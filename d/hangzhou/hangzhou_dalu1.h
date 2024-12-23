//dalu1.h

//Sample for room: 杭州大路1
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_dalu1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州大路1");

	//add npcs into the room
	add_npc("pub_tiaofu");/////////////////////////
	add_npc("honghua_honghua1");

	add_door("杭州沿湖大道3", "杭州沿湖大道3", "杭州大路1");
	add_door("杭州沿湖大道2", "杭州沿湖大道2", "杭州大路1");

	set("long","路的东边是一座小山。山上郁郁葱葱，种满了树。山上本是一处观赏西湖的好地方，但却被丁财主占为私有。大路向东北和南延伸。");

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
