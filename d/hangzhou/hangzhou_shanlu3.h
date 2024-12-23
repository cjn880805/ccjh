//shanlu3.h

//Sample for room: 杭州山路3
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_shanlu3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州山路3");

	//add npcs into the room
	add_npc("pub_boy");
	
	add_door("杭州法喜寺", "杭州法喜寺", "杭州山路3");
	add_door("杭州法净寺", "杭州法净寺", "杭州山路3");

	set("long","小溪横过山路，跨溪有一座小石桥。溪边农家小孩在嬉戏玩乐。南上便到了上天竺。北下就是中天竺。" );


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
