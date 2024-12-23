//yzjw_jiaowai9.h

//Sample for room:  ��������9
//coded by zwb
//data: 2000-11-22

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRYZJW_jiaowai9);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������9");

	add_npc("animal_dushe");
	add_npc("gaibang_li_futou");
	add_npc("gaibang_quan_gq");
	add_npc("gaibang_zuo_qu");

	add_door("���ݲݵ�8","���ݲݵ�8","��������9");
	add_door("��������10","��������10","��������9");

    set("long","���ݽ����ï�����֣���ɭ�ɲ���̧ͷ�������ա�����Ҳ�����������������ĵط��������߳��ε����");

/********************************************************
    set("exits", ([
        "east"  : __DIR__"jiaowai8",
        "west"  : __DIR__"jiaowai10",
    ]));
    set("objects", ([
        __DIR__"obj/shuzhi": 2,
        __DIR__"npc/dushe" : 1,
    ]));
********************************************************/
 
};


ROOM_END;
