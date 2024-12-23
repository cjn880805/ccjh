//shenxudong.h

//Sample for room: 杭州射旭洞
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_shenxudong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州射旭洞");

	//add npcs into the room
	add_npc("xiaoyao_mengmianr");

	add_door("杭州龙泓洞", "杭州龙泓洞", "杭州射旭洞");

	set("long","洞後侧穹顶上的石罅间可仰见一束天光，故又名“一线天”。东南边是下山的路。" );
	

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
