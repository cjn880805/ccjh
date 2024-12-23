//rongcheng.h

//Sample for room: 榕城驿
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRfuzhou_rongcheng);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "榕城驿");

	//add npcs into the room
	add_npc("pub_xiaoer2");
	
	add_door("福州东", "福州东", "福州榕城驿");
	add_door("福州榕城驿二楼", "福州榕城驿二楼", "福州榕城驿");

    set("long", "榕城驿是全省最大的客店，生意非常兴隆。外地游客多选择这里落脚，你可以在这里打听到本省的风土人情。店小二里里外外忙得团团转，福州的方言你是实在听不顺耳。还是上楼睡觉去。墙上挂着一个牌子(paizi)。" );
	set("valid_startroom", 1);
    set("sleep_room",1);	
	set("no_fight", 1);

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
