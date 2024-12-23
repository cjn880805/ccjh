//nroad4.h

//Sample for room:  Ѫ����ɽ·4
//coded by zouwenbin
//data: 2000-11-28

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRXueDao_nroad4);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ѫ����ɽ·4");
	
	add_npc("xuedao_huatiegan");        //add by zdn 2001-07-20xuedao_hutiegan
		
	add_door("Ѫ����ɽ·2", "Ѫ����ɽ·2", "Ѫ����ɽ·4");
	add_door("Ѫ����ѩɽ��´", "Ѫ����ѩɽ��´", "Ѫ����ɽ·4");

	set("long","��ѩɽ��´�ĵ��Ʋ������ߣ���Χ����һЩСɽ��������һ����Ժ��ɽ�������Ե��쳣�ߴ���Ժ��ƽ�����ͣ����ɴ�ʯ���ɣ�ǽ���ʵ������խС��");

/******************************************************************************
        set("exits",([
                "north"   : __DIR__"nroad3",
                "westup"  : "/d/xueshan/shanmen",
        ]));
******************************************************************************/
};


ROOM_END;
