//jingcisi.h

//Sample for room: 杭州净慈寺
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_jingcisi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州净慈寺");
	
	add_npc("pub_guest");
	add_npc("pub_youke");          // add by zdn 2001-07-14


	add_door("杭州青石大道16", "杭州青石大道16", "杭州净慈寺");


	set("long"," 净慈寺，原名慧日永明院，又叫兴教寺。净慈寺面向西湖，後拥苍然挺秀的南屏山。往北就回到大道上。");
 
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
