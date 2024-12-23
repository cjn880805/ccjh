//riverside3.h

//Sample for room: 江边小路3
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRWanJie_riverside3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "江边小路3");


	add_door("万劫谷江边小路2", "万劫谷江边小路2", "万劫谷江边小路3");
	add_door("万劫谷善人渡", "万劫谷善人渡", "万劫谷江边小路3");

	set("long","这是澜沧江边的一条小路，江水滔滔，从下面奔腾而过，江面上不时传来艄公的号子声，与江风的呼啸声形成一曲动人的交响乐");
    
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
