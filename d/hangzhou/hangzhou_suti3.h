//suti3.h

//Sample for room: 杭州苏堤3
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_suti3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州苏堤3");
	
	add_npc("pub_girl1");       //add by zdn 2001-07-14


	add_door("杭州苏堤2", "杭州苏堤2", "杭州苏堤3");
	add_door("杭州苏堤4", "杭州苏堤4", "杭州苏堤3");

	set("long"," 寒冬，瑞雪霏霏中，不少游人踏雪观景。从堤上极目远眺，只见四周玉树琼林。北边是东浦桥，南面是压堤桥。");

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
