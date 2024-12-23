//chuanchang.h

//Sample for room: 船厂
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRGuanWai_chuanchang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "船厂");

	set("monster_chance", 50);

	add_npc("lj_yudafu"); 

	add_door("关外雪地3", "关外雪地3", "关外船厂");
	add_door("关外冰面", "关外冰面", "关外船厂");

    set("long","这里是古镇船厂。船厂是位于关外大平原中部的一个古老的小镇，此镇西、南、北、三面是以高墙垒筑，利于坚守。东面临松花江天成天险，乃兵家必争的要地。松花江在冬春时结冰可通行，夏秋化冻你只好找船家帮忙了。" );
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
