//wuqiku.h

//Sample for room: ����ޤ����
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_wuqiku);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ޤ����");

	CBox * box = Add_Box();
	box->add_object("zhujian", 3);	
	box->set_name( "����");	


	CBox * box1 = Add_Box();
	box1->add_object("tiejiang", 1);	
	box1->set_name( "���");	
	
	add_door("���ջ���5", "���ջ���5", "����ޤ����");

/*****************************************************
        set("exits", ([
            "east" : __DIR__"changl5",
        ]));
        set("objects",([
          "/d/village/obj/zhujian" : 4,
       	]));
********************************************/
};


ROOM_END;
