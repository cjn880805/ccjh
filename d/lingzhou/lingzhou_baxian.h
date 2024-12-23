//baxian.h

//Sample for room: 八仙道观
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_baxian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "八仙道观");

	//add npcs into the room
	add_npc("wudang_laodaoshi");
	
	add_door("灵州林中小路2", "灵州林中小路2", "灵州八仙道观");

	set("long", "这里是八仙道观，内有八仙殿，供着张果老、铁拐李、吕洞宾等八仙的塑像，香案上香烟缭绕。靠墙放着几张太师椅，地上放着几个蒲团。东西两侧是走廊，北边是东二巷， 南边是后院,种着些杨柳和老槐树，是道士们休息的地方。后院还有一口井，不过看上去有点异样");  
	set("no_fight",1);

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
