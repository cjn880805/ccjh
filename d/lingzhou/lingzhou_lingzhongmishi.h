//gongling.h

//Sample for room: 灵州恭陵
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRlingzhou_lingzhongmishi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "灵州陵中密室");
	
	//add_npc("pub_youke");       //add by zdn 2001-07-14

//	add_door("灵州陵中", "灵州陵中", "灵州陵中密室");

	CBox * box = Add_Box();
	if(! random(3))
		box->add_object("icesword", 1);	//put 100 coind into box
	else
		box->add_object("coin",1);	// Put 1 coin into box :ppp
	box->set_name( "石棺", "coffin");
	box->Locked("封闭", 6000);

	set("long", "这是西夏先主拓跋思恭的陵墓，拓跋思恭当年率党项羌族归顺唐太宗李世民而被赐姓为李，这李思恭在唐初也是极有名的大将。如今因为年代久远他的陵墓也不复当年的雄伟而看上去有点破败。");  
	

/*****************************************************
	set("exits", ([
		"south"   : __DIR__"deling",
	]));
********************************************/
};

virtual int do_look(CChar * me)
{
	//只有打听到正确的答案才能发现线索
	say("这里的地面全用黑石铺成，但是正中有一小块白石，特别显眼，也许可以踩(steps)上去看看？", me);
	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if(strcmp(comm, "steps") == 0)
	{
		message_vision("$N屏住呼吸，踩上白石……", me);
		if(random(20) == 0)
			me->move(load_room("灵州陵下"));
		else
			message_vision("结果什么也没发生……:>>", me);

		me->receive_damage("hp",30);
		return 1;
	}
	return 0;
}

ROOM_END;
