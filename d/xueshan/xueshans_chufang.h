//chufang.h

//Sample for room: ����
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXueShan_chufang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ѩɽ�³���");


	add_door("ѩɽ��", "ѩɽ��", "ѩɽ�³���");

    
    set_temp("times" , 5);      
    set("no_fight",1);
    set("no_steal",1);

/*****************************************************
        set("item_desc",([
                "paizi" : "�����������ӹ�������(work)һ�θ���ʮ����\n",
        ]));
        set("exits",([
                "south" : __DIR__"xiaoyuan",
        ]));
********************************************/
};


ROOM_END;
