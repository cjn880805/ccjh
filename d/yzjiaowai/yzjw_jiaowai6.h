//yzjw_jiaowai6.h

//Sample for room:  ��������6
//coded by zwb
//data: 2000-11-22


ROOM_BEGIN(CRYZJW_jiaowai6);


virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������6");

//	add_npc("kuai-huosan");	
	add_npc("pub_punk");      //add by zdn 2001-07-16

	CBox * box = Add_Box();
	box->add_object("gourou", 1);	
	box->set_name( "����");
		
	CBox * box1 = Add_Box();
	box1->add_object("hdjiudai", 1);	
	box1->set_name( "����");
		
	CBox * box2 = Add_Box();
	box2->add_object("jitui", 1);	
	box2->set_name( "����");	
	
	add_door("��������5","��������5","��������6");
	add_door("���ݲݵ�7","���ݲݵ�7","��������6");

    set("long","���ݽ�������֣���֦ͦ�Σ���ľ��б���ּ�С����������Զ�����в������֣�������ת��ʹ���ʱ���⾡����    �������˺ܶ���֦ʯ�顣");

/********************************************************
    set("exits", ([
        "east" : __DIR__"jiaowai5",
        "west" : __DIR__"jiaowai7",
    ]));
    set("objects", ([
        CLASS_D("gaibang")+"/kuai-huosan" : 1,
        __DIR__"obj/shitou": 2,
    ]));
//    
*******************************************************/
 
};


ROOM_END;
