//luorilin2.h

//Sample for room: 灵州落日林2
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_luorilin2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "灵州落日林2");

	//add npcs into the room
	add_npc("animal_dushe");/////////////////////////

	add_door("灵州林中大路1", "灵州林中大路1", "灵州落日林2");
	add_door("灵州林中土路", "灵州林中土路", "灵州落日林2");

	set("long", "这里是一片方圆百里的森林，林中古木参天，树荫蔽日，光线黯淡，落日林的伐木场就在这里，这里是树木大都树龄百年以上，数人和抱的大树比比皆是，一条不宽的土路蜿蜒通向前方。");  
	
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
