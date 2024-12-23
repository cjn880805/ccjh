//yuelang.h

//Sample for room: 杭州岳廊
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_yuelang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州岳廊");

	//add npcs into the room
	add_npc("mingjiao_chengchaofeng");
	add_npc("honghua_honghua1");
	add_npc("honghua_honghua1");

	add_door("杭州岳坟", "杭州岳坟", "杭州岳廊");
	add_door("杭州青石大道6", "杭州青石大道6", "杭州岳廊");

	set("long","岳王庙的匾上是“心昭天日”四个大字。步入大殿，正中是岳飞的塑像，身後的匾上题着“还我河山”。北边的门通向岳坟，往南是出去的路。 岳王墓的左面，便是岳飞之子岳云的墓，墓碑上刻着“宋继忠侯岳云之墓”.  在岳坟前面两边四个铁像(statue)。东首墙上有四个大字(word)。");

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

int valid_leave(CChar * me, const char * dir)
{
	if(EQUALSTR(dir,"杭州岳坟"))
	{
		if(!me->query_temp("wei/renwu8_5"))
		{
			message_vision("$HIR你是怎么混进来的？", me);
			return 0;
		}
		else
		{
			if(!me->query_temp("wei/renwu8_12") )
			{
				message_vision("$HIR绿营会众伸手一拦$N，笑道：此路是我开，有钱没钱都别进来！", me);
				return 0;
			}
		}
	}
	return CRoom::valid_leave(me, dir);
}

ROOM_END;
