//shijie.h

//Sample for room: 白驼山石阶
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_shijie);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "白驼山石阶");


	add_door("白驼山广场", "白驼山广场", "白驼山石阶");
	add_door("白驼山草坪", "白驼山草坪", "白驼山石阶");
	add_door("白驼山大门", "白驼山大门", "白驼山石阶");

	set("long", "你走在青石板铺成的石阶上。这里就是传说中神秘的白驼山。远远望去，两座白沙堆积形成的山峰好像一只骆驼的脊背。一座山门立在你的眼前。(door)关闭着。北边是『白驼山庄』的大厅。南边就是大门了。");

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
