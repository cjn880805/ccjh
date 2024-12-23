//menlang.h

//Sample for room: 白驼山门廊
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_menlang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "白驼山门廊");

	//add npcs into the room
	add_npc("pub_guanjia");
	
	add_door("白驼山花园", "白驼山花园", "白驼山门廊");
	add_door("白驼山练功场", "白驼山练功场", "白驼山门廊");

	set("long", "这是个门廊，门廊的飞檐上挂着一串串的小铜铃在清风中发出清脆动听的铃声。.白衣少女常来这里嬉戏。沿着弯弯曲曲的花径，可以通到山庄的许多地方。东边是厨房。西边是白驼山少主『欧阳克』的内室，门虚掩着，不知主人在不在。");

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
