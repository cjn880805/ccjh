//nroad6.h

//Sample for room:  Ѫ����ɽ·6
//coded by zouwenbin
//data: 2000-11-28

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRXueDao_nroad6);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ѫ����ɽ·6");
	add_npc("pub_yunwuxiang");


	add_door("Ѫ����ɽ·5", "Ѫ����ɽ·5", "Ѫ����ɽ·6");
	add_door("Ѫ����ɽ·7", "Ѫ����ɽ·7", "Ѫ����ɽ·6");

	set("long","������һɽ·�ϣ�������һ����Сɽ��Զ�����Կ��������ѩ��ɽ�⡣��Χ�������Ѿ����ѿ��õ��ˡ�");

/******************************************************************************
        set("exits",([
                "north"   : __DIR__"nroad7",
                "southup" : __DIR__"nroad5",
        ]));
        set("objects",([
                __DIR__"npc/huatiegan" : 1,
        ]));
******************************************************************************/
};


ROOM_END;
