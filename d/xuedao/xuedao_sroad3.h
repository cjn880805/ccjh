//sroad3.h

//Sample for room:  Ѫ����ѩɽ·3
//coded by zouwenbin
//data: 2000-11-28

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRXueDao_sroad3);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ѫ����ѩɽ·3");

	add_npc("pub_luying");
	add_door("Ѫ����ɽ·1", "Ѫ����ɽ·1", "Ѫ����ѩɽ·3");
	add_door("Ѫ����ѩɽ·2", "Ѫ����ѩɽ·2", "Ѫ����ѩɽ·3");
	add_door("Ѫ���Ŵ�ѩɽ��4", "Ѫ���Ŵ�ѩɽ��4", "Ѫ����ѩɽ·3");

	set("long","�����ǿ��������ĳ�ɽ���룬��ʯ��ᾡ�������ȥ���Ǵ�����Ե�ˡ�������һ��ѩɽ�������ơ�·������һ����ѩ��(hollow)��");
    

/******************************************************************************
        set("exits",([
                "eastdown"  : __DIR__"sroad2",
                "northdown"  : __DIR__"nroad1",
                "westup"    : __DIR__"sroad4",
        ]));
        set("objects",([
                __DIR__"npc/liuchengfeng" : 1,
        ]));
        set("item_desc",([
                "hollow"  : "һ��ѩ�ӣ��ƺ�������(jump)��ȥ��\n"
        ]));
        set("outdoors", "xueshan");
******************************************************************************/
};


ROOM_END;
