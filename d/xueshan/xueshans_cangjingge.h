//cangjingge.h

//Sample for room: �ؾ���
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXueShan_cangjingge);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ѩɽ�²ؾ���");

	add_npc("xueshan_lingzhi");

	add_door("ѩɽ�´��", "ѩɽ�´��", "ѩɽ�²ؾ���");

    set("long","������ѩɽ�µĲؾ�֮����������������ܶ������ĵ伮����һ����Ҳ��������" );

/*****************************************************
        set("exits",([
                "northwest" : __DIR__"dating",
        ]));
        set("objects", ([
                CLASS_D("xueshan")+"/lingzhi" : 1,
        ]));
//        
********************************************/
};


ROOM_END;
