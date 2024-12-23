//suti6.h

//Sample for room: 杭州苏堤6
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_suti6);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州苏堤6");
	
	add_npc("pub_tufei1");            // add by zdn 2001-07-14


	add_door("杭州苏堤5", "杭州苏堤5", "杭州苏堤6");
	add_door("杭州苏堤7", "杭州苏堤7", "杭州苏堤6");
	add_door("杭州花港观鱼", "杭州花港观鱼", "杭州苏堤6");

	set("long"," 秋月之夜，月下观湖，满湖银波粼粼，阵阵微风，风中桂子飘香，令人为之心醉。堤边泊着小舟是送游客去三潭映月的。往西边是去花港，东面可见三潭映月遥立湖中，北边是锁澜桥，南面映波桥。");

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
