//shufang.h

//Sample for room: 华山书房
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRHuaShan_shufang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "书房");

	CBox * box = Add_Box();
	box->add_object("zhengqi_book", 1);	
	box->set_name( "铁柜");		

	add_door("华山花园", "华山花园", "华山书房");

    set("long","这里是华山派的书房，靠墙是一排书架，里面堆着乱七八糟的一大堆书，最近老有人上山寻事，都很久没人整理书房了，要找啥书都很麻烦。右侧有张书桌，桌上四宝俱备。");
	set("no_fight", "1");
	
	set("book_count", 1);

/*****************************************************
	set("exits",([
		"north" : __DIR__"garden",
	]));
	if (random(5) > 3)
	set("objects",([
		"/clone/book/zhengqi_book" : 1,
	]));
********************************************/
};


ROOM_END;
