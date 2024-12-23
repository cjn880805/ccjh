//club.h

//Sample for room: 长安乐坊
//coded by Fisho
//data: 2000-11-3

CHANGAN_BEGIN(CRChangAn_club);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "长安乐坊");

	add_npc("pub_xiaoer1");
	add_npc("pub_shinu1");       //zdn 2001-07-12  add

	add_door("长安", "长安", "长安乐坊");
	add_door("长安乐坊二楼大厅", "长安乐坊二楼大厅", "长安乐坊");

	set("long", "这里是长安城一家有名的娱乐场所。当夜幕降临后，这里就格外热闹。进进出出的客人有达官贵人，南来北往的商旅，浪迹天涯的游子，三五成群的兵士，有时也能看见一些作俗客打扮的僧人或道士。" );
	
};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

CHANGAN_END;
