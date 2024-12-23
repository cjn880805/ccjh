//guozhuang.h

//Sample for room: 杭州郭庄
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_guozhuang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州郭庄");

	//add npcs into the room
	add_item("daotian");
	
	add_door("杭州沿湖大道1", "杭州沿湖大道1", "杭州郭庄");

	set("long","庄园的大匾上是“郭庄”两个大字。大门(gate)紧闭，里面静悄悄的一点声音都没有。");
    

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
