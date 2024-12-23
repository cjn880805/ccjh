//xiuxishi.h

//Sample for room:  重阳宫休息室
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRChongYang_xiuxishi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "重阳宫休息室");

	add_door("重阳宫", "重阳宫", "重阳宫休息室");
	add_npc("quanzhen_daotong1");

	set("long", "这是间很大的房间，光线非常昏暗。房里没有什么别的东西，只有中间放着一张收拾得舒舒服服的大床，床上的被褥也整理得整整洁洁，看着就让人想睡觉。");
    
    set("sleep_room",1);
    set("no_beg",1);
    set("no_fight",1);
    set("no_steal",1);

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
//last, register the room into ../server/RoomSetup.cpp