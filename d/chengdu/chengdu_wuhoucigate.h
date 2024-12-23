//wuhoucigate.h

//Sample for room: 武侯祠大门
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRChengDu_wuhoucigate);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武侯祠大门");

	add_npc("pub_shiwei");   //zdn 2001-07-12 add

	add_door("成都西", "成都西", "成都武侯祠大门");

	set("long",	"这里原来是武侯祠。大门人进人出，大多缠着武侯巾。原来武侯生前治蜀，造福两川，这武侯巾乃是他去世川人为其带孝之俗。由于武侯遗爱甚深，虽千载以下，川人头巾仍不去首。"	);
	

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
