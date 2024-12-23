//xuanyuegate.h

//Sample for room: 武当玄岳门
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_xuanyuegate);

virtual void create()			//Call it when Room Create
{
	set_name( "武当玄岳门");

	add_npc("wudang_zhike");
	add_npc("wudang_daotong");

	add_door("武当解剑岩", "武当解剑岩", "武当玄岳门");
	add_door("武当遇真宫", "武当遇真宫", "武当玄岳门");

};


ROOM_END;
