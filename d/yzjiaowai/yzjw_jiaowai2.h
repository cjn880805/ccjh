//yzjw_jiaowai2.h

//Sample for room:  ��������2
//coded by zwb
//data: 2000-11-22

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRYZJW_jiaowai2);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������2");

	add_npc("animal_wubushe");
	//add_npc("qiu-wanjia");
	add_npc("pub_bing");      //add by zdn 2001-07-16
	
	CBox * box1 = Add_Box();
	box1->add_object("shuzhi", 1);	
	box1->set_name( "����");
	
	CBox * box2 = Add_Box();
	box2->add_object("shitou", 1);	
	box2->set_name( "����");				

	add_door("��������3","��������3","��������2");
	add_door("���ݲݵ�1","���ݲݵ�1","��������2");

    set("long","���ݽ�������֣���֦ͦ�Σ���ľ��б���ּ�С����������Զ�����в������֣�������ת��ʹ���ʱ���⾡����    �������˺ܶ���֦ʯ�顣");
	

/********************************************************
     set("exits", ([
        "north" : __DIR__"jiaowai1",
        "south" : __DIR__"jiaowai3",
    ]));
    set("objects", ([
        CLASS_D("gaibang")+"/qiu-wanjia": 1,
        __DIR__"obj/shuzhi": 1,
        __DIR__"obj/shitou": 1,
    ]));
//    
    set("outdoors", "yangzhou");
*********************************************************/
};


ROOM_END;
