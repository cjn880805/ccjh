//yuzhu.h

//Sample for room: 玉柱峰
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRGuanWai_yuzhu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "玉柱峰");
	
	add_npc("pub_youke");    // add by zdn 2001-07-13

	set("monster_chance", 50);

	add_door("关外白云峰", "关外白云峰", "关外玉柱峰");
	add_door("关外梯云峰", "关外梯云峰", "关外玉柱峰");

    set("long","白云峰西南，有峰高耸挺秀，多峰突起，形如玉柱。东麓泻出一水，悬流如线，注入天池，就是古籍所载的“金线泉”了。" );
    
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
