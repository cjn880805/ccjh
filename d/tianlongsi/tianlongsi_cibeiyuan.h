//cibeiyuan.h

//Sample for room:  �����´ȱ�Ժ
//coded by zouwenbin
//data: 2000-11-30

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRTianLongSi_cibeiyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����´ȱ�Ժ");


				
	add_door("���������޾�", "���������޾�", "�����´ȱ�Ժ");
	add_door("���������޹�", "���������޹�", "�����´ȱ�Ժ");

    

/******************************************************************************
        set("exits", ([
                "east" : __DIR__"wuwujing",
		"south" : __DIR__"sanwugong",
	]));
******************************************************************************/
};


ROOM_END;
