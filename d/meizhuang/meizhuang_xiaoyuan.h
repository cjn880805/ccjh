//xiaoyuan.h

//Sample for room:  ÷ׯ����СԺ
//coded by zouwenbin
//data: 2000-12-2

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRMeiZhuang_xiaoyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "÷ׯ����СԺ");
	
	add_npc("pub_lady3");      //add by zdn 2001-07-14
	add_item("meishu");
	add_item("meishu");

	add_door("÷ׯС·", "÷ׯС·", "÷ׯ����СԺ");
	add_door("÷ׯС��", "÷ׯС��", "÷ׯ����СԺ");
	
	add_npc("pub_jiading");

/******************************************************************************
        set("weapon_count",1);
        set("exits", ([  
            "south" : __DIR__"xiaodao",
            "enter" : __DIR__"xiaowu",
        ]));
        set("item_desc",([
                "wood" : "һ��Ѹɲ�������һ������ɫ�Ƚ��ر�\n",
        ]));
        set("objects", ([
                __DIR__"npc/ding" : 1,
        ]));
        set("outdoors", "meizhuang");
******************************************************************************/
};


ROOM_END;
