//beilu.h

//Sample for room:  Ѫ����ѩɽ��´
//coded by zouwenbin
//data: 2000-11-28

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRXueDao_beilu);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ѫ����ѩɽ��´");
	
	add_npc("xuedao_liuchengfeng");        //add by zdn 2001-07-20

				
	add_door("Ѫ����ɽ·4", "Ѫ����ɽ·4", "Ѫ����ѩɽ��´");
	add_door("ѩɽ��", "ѩɽ��", "Ѫ����ѩɽ��´");

	set("long","��ѩɽ��´�ĵ��Ʋ������ߣ���Χ����һЩСɽ��������һ����Ժ��ɽ�������Ե��쳣�ߴ���Ժ��ƽ�����ͣ����ɴ�ʯ���ɣ�ǽ���ʵ������խС��");

/******************************************************************************
        set("exits",([
                "north"   : __DIR__"nroad3",
                "westup"  : "/d/xueshan/shanmen",
        ]));
******************************************************************************/
};


ROOM_END;
