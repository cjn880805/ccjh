//shanshenmiao.h

//Sample for room: 山神庙
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRGuanWai_shanshenmiao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "山神庙");
	
	add_npc("pub_xiaozei");    // add by zdn 2001-07-13
	add_npc("pub_wanghu");

	set("monster_chance", 1);

	add_door("关外荒路2", "关外荒路2", "关外山神庙");

	set("long","这是一个用木板和石头垒成的小庙，庙前地上散落着一些然过的灰烬。庙里供奉着山神爷老把头的灵位(lingwei)。传说他是所有采参人的祖师爷，所以每个进山挖参的参客都要来这里祭拜，希望能得到他老人家的保佑。" );


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
