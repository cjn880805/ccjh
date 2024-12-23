//yabziwu_shuwu.h

//Sample for room: 翰墨书屋
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_shuwu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "翰墨书屋");
	
	add_npc("murong_xiansheng"); 
	add_npc("murong_tang");        //add by zdn 2001-07-20      

	add_door("燕子坞参合居", "燕子坞参合居", "燕子坞翰墨书屋");
	add_door("燕子坞揽月居","燕子坞揽月居","燕子坞翰墨书屋");

    
	set("long","屋中一架架紫竹搭成的书架倚墙而立，书架上摆满了经史典籍。屋子正中央是一张书桌，桌上琴棋俱备，笔墨纸砚一应俱全，墙上挂着一幅条幅(tiaofu)。大名鼎鼎的慕容公子常在这里读书写字。");

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
