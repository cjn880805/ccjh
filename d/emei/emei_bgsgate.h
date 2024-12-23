//bgsgate.h

//Sample for room:  峨嵋报国寺山门
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_bgsgate);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "峨嵋报国寺山门");

	add_npc("pub_guest");
				
	add_door("峨嵋青石阶", "峨嵋青石阶", "峨嵋报国寺山门");
	add_door("峨嵋报国寺", "峨嵋报国寺", "峨嵋报国寺山门");

	set("long","报国寺为峨嵋出入之门户。山门(gate)上有一块大匾。寺外苍楠环卫，翠柏掩映。由此一路向西上开始登峨嵋山，北面下山是一条弯弯的石阶路。");
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
