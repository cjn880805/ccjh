//dilao.h

//Sample for room: ����
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXueShan_dilao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ѩɽ�µ���");


	add_door("ѩɽ��", "ѩɽ��", "ѩɽ�µ���");

    set("long","����һ����������ʪ���η�����е���ֵ�������᲻ʱ����һ�����ȴ��ôҲ�Ҳ�������? " );
    

/*****************************************************
        set("exits",([
                "westup" : __DIR__"houyuan",
        ]));
********************************************/
};


ROOM_END;
