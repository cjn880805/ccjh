//mishi.h

//Sample for room: ����
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXueShan_mishi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ѩɽ������");


	add_door("ѩɽ�´��", "ѩɽ�´��", "ѩɽ������");

    

/*****************************************************
       set("exits",([
                "south" : __DIR__"midao",
                "down" : "/d/city/guangchang" ,
        ]));
********************************************/
};


ROOM_END;
