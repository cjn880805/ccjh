//sroad2.h

//Sample for room:  Ѫ����ѩɽ·2
//coded by zouwenbin
//data: 2000-11-28

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRXueDao_sroad2);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ѫ����ѩɽ·2");



	add_door("Ѫ����ѩɽ·3", "Ѫ����ѩɽ·3", "Ѫ����ѩɽ·2");
	add_door("Ѫ����ѩɽ·1", "Ѫ����ѩɽ·1", "Ѫ����ѩɽ·2");

	set("long","һ��ɽ·������ɽ�䡣������ȥ�����Լ�����ѩɽ����ɫ��ѩ�����������ԡ�");
    

/******************************************************************************
        set("exits",([
                "eastdown"  : __DIR__"sroad1",
                "westup"    : __DIR__"sroad3",
        ]));
******************************************************************************/
};


ROOM_END;
