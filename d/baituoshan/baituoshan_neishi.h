//neishi.h

//Sample for room: 内室
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRBaiTuoShan_neishi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "内室");


	add_door("白驼山花园", "白驼山花园", "白驼山内室");

	set("long", "这是『欧阳克』的内室，内部摆设很有情趣。屋角摆着一盆名贵兰花，正骄傲地吐露芳蕊。花盆(pen) 下撒落一些浮土，可能是被人搬出去晒太阳时撒下的。");  

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
