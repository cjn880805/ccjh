//sheshenya.h

//Sample for room: 武当舍身崖
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_sheshenya);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武当舍身崖");


	add_door("武当南岩峰", "武当南岩峰", "武当舍身崖");
//	add_door("舍身崖石洞", "舍身崖石洞", "武当舍身崖");

    

/*****************************************************
      set("exits",([  
          "east"     : __DIR__"nanyanfeng",
      ]));
*****************************************************/
};

virtual int do_look(CChar * me)
{
	if(! me->query_temp("mask/舍身崖")) return CRoom::do_look(me);

	//只有打听到正确的答案才能发现线索
	say("这是一段极窄极险的山崖，四周云雾飞绕，下面渊深无底。如不小心，一失足掉下去，只怕连骨头都找不到。下面有个小山洞。", me);
	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if(strcmp(comm, "jump") == 0)
	{
		message_vision("$N屏住呼吸向下一跳……", me);

		if(random(3) == 0)
			me->move(load_room("舍身崖石洞"));
		else
			me->move(load_room("逍遥林小道1"));		

		me->unconcious();
		return 1;
	}
	return 0;
}

ROOM_END;
