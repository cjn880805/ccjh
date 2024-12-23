//chufang.h

//Sample for room: 厨房
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRBaiTuoShan_chufang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "厨房");

	//add npcs into the room
	add_npc("pub_feifei");

	CBox * box = Add_Box();
	box->add_object("doujiang", 1);	
	box->set_name( "铁柜");
		
	CBox * box1 = Add_Box();
	box1->add_object("cake", 1);	
	box1->set_name( "铁柜");	
	
//	add_door("白驼山柴房", "白驼山柴房", "白驼山厨房");
	add_door("白驼山花园", "白驼山花园", "白驼山厨房");

	set("long", "这是间宽敞的厨房，厨师们在展示各自的烹饪绝活。整个房间弥漫着令人垂涎欲滴的菜香。墙上贴着一张醒目的启事(note)。");
    set("no_fight", "1");
    set("no_beg", "1");
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
