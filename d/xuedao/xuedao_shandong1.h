//shandong1.h

//Sample for room:  Ѫ����ɽ��1
//coded by zouwenbin
//data: 2000-11-28

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRXueDao_shandong1);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ѫ����ɽ��1");

	add_npc("xueshan_xuedao");
	add_npc("xueshan_baoxiang");

	CBox * box = Add_Box();
	box->add_object("dachang", 1);	
	box->set_name( "����");	

	add_door("Ѫ���Ŵ�ѩɽɽ��8", "Ѫ���Ŵ�ѩɽɽ��8", "Ѫ����ɽ��1");

	set("long","�տյ���һ��ɽ������Ҳ����ɾ�����ͷ����һ��ʯ����");

/******************************************************************************
        set("exits",([
                "out" : __DIR__"sroad8",
        ]));
        set("objects", ([
                __DIR__"obj/dachang" :1,
        ]));
******************************************************************************/
};


ROOM_END;
