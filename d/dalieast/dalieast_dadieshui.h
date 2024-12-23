//dadieshui.h

//Sample for room: 大理城大叠水瀑布
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaliEast_dadieshui);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城大叠水瀑布");

	add_npc("pub_youke");     // add by zdn 2001-07-12 

	add_door("大理城清溪三潭", "大理城清溪三潭", "大理城大叠水瀑布");
	add_door("大理城茶花山南", "大理城茶花山南", "大理城大叠水瀑布");
	add_door("大理城山区小径", "大理城山区小径", "大理城大叠水瀑布");

	set("long", "延山间小路越丘陵，过村庄，穿田野，约二，三里后，隐隐听见水流的轰鸣，续前进，在一片坡地的前端，呈现倒丫字形深箐，那巨大的轰鸣声，就是从这箐沟里传出的。延坡上的之字形小路攀藤扶石眼前。" );
	
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
