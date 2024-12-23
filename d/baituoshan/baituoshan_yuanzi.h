//yuanzi.h

//Sample for room: 白驼山院子
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_yuanzi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "白驼山院子");



	add_door("白驼山大厅", "白驼山大厅", "白驼山院子");
	add_door("白驼山大门", "白驼山大门", "白驼山院子");
	add_door("白驼山武器库", "白驼山武器库", "白驼山院子");
	add_door("白驼山储藏室", "白驼山储藏室", "白驼山院子");

	set("long", "这是一个大院子，打扫得一尘不染。四周装点着青青翠竹，错落有致。西边是武器库。东边有一间储藏室，房门(door)关闭着。北边是『白驼山庄』的大厅。南边就是大门了。.第子们在里边砌磋武艺，绝对不允许外人打搅。");
    
    set_temp("lock",1);

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
