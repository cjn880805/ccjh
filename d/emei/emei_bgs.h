//bgs.h

//Sample for room:  峨嵋报国寺
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_bgs);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "峨嵋报国寺");

	add_npc("pub_guest");
	
				
	add_door("峨嵋报国寺山门", "峨嵋报国寺山门", "峨嵋报国寺");
	add_door("峨嵋密林1", "峨嵋密林1", "峨嵋报国寺");

	set("long","报国寺是峨眉山最大寺院之一。寺庙倚山建造，弥勒殿、大雄殿、七佛殿逐级升高，规模宏大。殿内佛像金光闪闪，气宇轩昂。寺内芳草迷径，花开不绝。这里有一座华严塔(ta)。这里向西，约二里可达伏虎寺。");
    
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
