//tingquanting.h

//Sample for room: �����Ȫͤ
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRQingCheng_tingquanting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����Ȫͤ");
	
	add_npc("qingcheng_hou");          //add by zdn 2001-07-14


	add_door("�������ʯ", "�������ʯ", "�����Ȫͤ");


    

/*****************************************************
    set("outdoors","qingcheng");
	set("exits", ([
		"westup"   : __DIR__"sandaoshi",
	]));
	set("objects", ([
		__DIR__"npc/luo" : 1,
	]));
*****************************************************/
};


ROOM_END;
