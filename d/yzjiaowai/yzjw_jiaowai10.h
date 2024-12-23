//yzjw_jiaowai10.h

//Sample for room:  ��������10
//coded by zwb
//data: 2000-11-22

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRYZJW_jiaowai10);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������10");

	add_npc("gaibang_jian");
	add_npc("gaibang_lu");
	add_npc("gaibang_peng");
	add_npc("gaibang_hong");
	add_npc("gaibang_jiang_sy");
	add_npc("zm_gaibang");

	add_door("��������9","��������9","��������10");
	add_door("��������11","��������11","��������10");

    set("long","���ݽ����ï�����֣���ɭ�ɲ���̧ͷ�������ա�����Ҳ�����������������ĵط��������߳��ε����");

/********************************************************
    set("exits", ([
        "east"  : __DIR__"jiaowai9",
        "west"  : __DIR__"jiaowai11",
        "north" : __DIR__"jiaowai12",
    ]));
    set("objects", ([
        CLASS_D("gaibang")+"/jiang-sy" : 1,
        __DIR__"obj/shuzhi": 2,
        __DIR__"obj/shitou": 1,
    ]));
********************************************************/
 
};


ROOM_END;
