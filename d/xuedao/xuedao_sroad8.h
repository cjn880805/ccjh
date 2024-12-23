//sroad8.h

//Sample for room:  Ѫ���Ŵ�ѩɽɽ��8
//coded by zouwenbin
//data: 2000-11-28

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRXueDao_sroad8);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ѫ���Ŵ�ѩɽɽ��8");
	add_npc("pub_yanqiansui");

	add_door("Ѫ�������ǹ�", "Ѫ�������ǹ�", "Ѫ���Ŵ�ѩɽɽ��8");
	add_door("Ѫ���Ŵ�ѩɽ��7", "Ѫ���Ŵ�ѩɽ��7", "Ѫ���Ŵ�ѩɽɽ��8");
	add_door("Ѫ����ɽ��1", "Ѫ����ɽ��1", "Ѫ���Ŵ�ѩɽɽ��8");

	set("long","һ�����ɽ��, Ⱥɽ����, ɽ����ȫ�ǰ������Ļ�ѩ, ɽ���Ϸ�������ɽ����");
    

/******************************************************************************
        set("exits",([
                "enter"  : __DIR__"shandong1",
                "north"  : __DIR__"wangyougu",
                "northup": __DIR__"sroad7",
        ]));
******************************************************************************/
};


ROOM_END;
