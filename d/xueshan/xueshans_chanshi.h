//chanshi.h

//Sample for room: ����
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXueShan_chanshi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ѩɽ������");

	add_npc("xueshan_guoshi");

	add_door("ѩɽ�´��", "ѩɽ�´��", "ѩɽ������");

    set("long","������ɮ���Ų��������ĵط������һ���������˿��˾��뵽������¡�" );
    set("no_fight",1);
    set("sleep_room",1);
    set("no_steal",1);

/*****************************************************
        set("exits",([
                "southwest" : __DIR__"dating",
        ]));
//        
********************************************/
};


ROOM_END;
