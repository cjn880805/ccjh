//sroad9.h

//Sample for room:  Ѫ���Ŵ�ѩɽɽ��9
//coded by zouwenbin
//data: 2000-11-28

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRXueDao_sroad9);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ѫ���Ŵ�ѩɽɽ��9");

	add_npc("xueshan_shengdi");


	add_door("Ѫ����ɽ��2", "Ѫ����ɽ��2", "Ѫ���Ŵ�ѩɽɽ��9");
	add_door("Ѫ�������ǹ�", "Ѫ�������ǹ�", "Ѫ���Ŵ�ѩɽɽ��9");

	set("long","ɽ�����ػ�ѩ�����ܶ����ͱڡ�ֻ������һ�����ڣ������ƺ��и�ɽ����");

/******************************************************************************
        set("exits",([
                "northdown" : __DIR__"wangyougu",
                "east"      : __DIR__"shandong2",
        ]));
        set("objects", ([
                CLASS_D("xueshan")+"/shengdi" :1,
        ]));
******************************************************************************/
};


ROOM_END;
