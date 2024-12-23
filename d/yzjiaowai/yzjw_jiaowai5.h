//yzjw_jiaowai5.h

//Sample for room:  ��������5
//coded by zwb
//data: 2000-11-22

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRYZJW_jiaowai5);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������5");

	add_npc("animal_dushe");
	add_npc("gaibang_liang");
	add_npc("gaibang_he_bj");
	
	add_door("��������6","��������6","��������5");
	add_door("��������4","��������4","��������5");
	add_door("��������","��������","��������5");
	
    set("long","���ݽ����ï�����֣���ɭ�ɲ���̧ͷ�������ա�����Ҳ�����������������ĵط��������߳��ε����");

/********************************************************
    set("exits", ([
        "east"  : __DIR__"jiaowai4",
        "west"  : __DIR__"jiaowai6",
    ]));
    set("objects", ([
        __DIR__"obj/shuzhi": 2,
        __DIR__"npc/dushe" : 1,
    ]));
//    
*******************************************************/
 
};


ROOM_END;
