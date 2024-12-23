//tulu.h

//Sample for room: 灵州林中土路
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_tulu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "灵州林中土路");
	
	add_npc("pub_xixiabing");   //add by zdn 2001-07-14


	add_door("灵州落日林2", "灵州落日林2", "灵州林中土路");
	add_door("灵州林中空地", "灵州林中空地", "灵州林中土路");

	set("long", "这是山间的土路，勉强可以通行一辆大车，路面上有两条深深的车辙印，路边山坡上全是参天巨木，看上去密不透风，这里很幽静，除了偶尔几声鸟叫才能打破寂静。土路向东北蜿蜒延伸转了个弯，西南面隐约可以看见林中一面大屋顶上的旗帜。");  

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
