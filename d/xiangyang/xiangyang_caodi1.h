//caodi1.h

//Sample for room: �����ݵ�1
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRXiangYang_caodi1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����ݵ�1");
	
	add_npc("xiangyang_menggubing");        //add by zdn 2001-07-20

	add_door("��������", "��������", "�����ݵ�1");
	add_door("��������12", "��������12", "�����ݵ�1");

	

/*****************************************************
        set("outdoors", "xiangyang");
	set("exits", ([
		"north"  : __DIR__"southgate2",
		"south"  : "/d/wudang/wdroad5",
	]));
********************************************/
};


ROOM_END;
