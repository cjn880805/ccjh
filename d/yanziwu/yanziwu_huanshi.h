//huanshi.h

//Sample for room: 还施水阁
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_huanshi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "还施水阁");

	CBox * box = Add_Box();
	box->set_name( "书架");
	
	box->add_object("book_iron");	
	box->add_object("book_paper");	
	box->add_object("book_silk");	
	box->add_object("book_stone");	
	
	//added by lanwood 2001-02-24 增加一本书：轻功篇
	box->add_object("dodgebook");

	box->Locked("上锁", 3000000);

	add_door("燕子坞揽月居", "燕子坞揽月居", "燕子坞还施水阁");

    set("long", "阁中满是书架，架上摆着许多颇古旧的书籍，架上均贴有标签。这就是慕容世家历经数代才收集积累而成的武学宝库。" );
    
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
