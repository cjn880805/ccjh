//kufang.h

//Sample for room: �ⷿ
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXueShan_kufang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ѩɽ�¿ⷿ");

	CBox * box1 = Add_Box();
	box1->add_object("zhujian", random(4));	
	box1->set_name( "ľ��");	
	
	CBox * box2 = Add_Box();
	box2->add_object("gangdao", random(4));	
	box2->set_name( "ľ��");	
	
	CBox * box3 = Add_Box();
	box3->add_object("mugun", random(4));	
	box3->set_name( "ľ��");
		
	CBox * box4 = Add_Box();
	box4->add_object("falun", random(4));	
	box4->set_name( "ľ��");	
	
	add_npc("pub_wuque");

	add_door("ѩɽ��", "ѩɽ��", "ѩɽ�¿ⷿ");


/*****************************************************
	set("exits",([
		"east" : __DIR__"chang",
	]));
	set("objects", ([
		"/clone/weapon/zhujian" : random(4),
		"/clone/weapon/gangdao" : random(4),
		__DIR__"obj/mugun" : random(4),
		__DIR__"obj/falun" : random(4),
	]));
//	
********************************************/
};


ROOM_END;
