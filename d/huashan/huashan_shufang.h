//shufang.h

//Sample for room: ��ɽ�鷿
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRHuaShan_shufang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�鷿");

	CBox * box = Add_Box();
	box->add_object("zhengqi_book", 1);	
	box->set_name( "����");		

	add_door("��ɽ��԰", "��ɽ��԰", "��ɽ�鷿");

    set("long","�����ǻ�ɽ�ɵ��鷿����ǽ��һ����ܣ�����������߰����һ����飬�����������ɽѰ�£����ܾ�û�������鷿�ˣ�Ҫ��ɶ�鶼���鷳���Ҳ����������������ı��㱸��");
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
