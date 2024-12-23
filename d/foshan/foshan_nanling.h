//nanling.h
//Sample for room: 南岭山口
//coded by zwb
//data: 2000-11-23

ROOM_BEGIN(CRFoShan_nanling);
virtual void create()			//Call it when Room Create
{
	set_name( "南岭山口");

	add_npc("animal_huananhu");
	add_npc("pub_bixuan");

	add_door("佛山北门", "佛山北门", "佛山南岭山口");
	add_door("衡山黄土路", "衡山黄土路", "佛山南岭山口");
	add_door("武当黄土路2", "武当黄土路2", "佛山南岭山口");

	set("long", "这里是南岭的一个山口。南面就是佛山了，北面是横亘湖南广东的五岭。这里地气炎热，百物速生快长，口音也远异中原了。" );

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
