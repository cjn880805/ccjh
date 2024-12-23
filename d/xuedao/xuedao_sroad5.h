//sroad5.h

//Sample for room:  Ѫ���Ŵ�ѩɽ
//coded by zouwenbin
//data: 2000-11-28

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRXueDao_sroad5);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ѫ���Ŵ�ѩɽ");



	add_door("Ѫ���Ŵ�ѩɽ��6", "Ѫ���Ŵ�ѩɽ��6", "Ѫ���Ŵ�ѩɽ");
	add_door("Ѫ���Ŵ�ѩɽ��4", "Ѫ���Ŵ�ѩɽ��4", "Ѫ���Ŵ�ѩɽ");

    

/******************************************************************************
        set("exits",([
                "eastdown"  : __DIR__"sroad4",
                "southup"   : __DIR__"sroad6",
        ]));
******************************************************************************/
};


ROOM_END;
