//beiyuemiao.h

//Sample for room: ��ɽ������
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan2_beiyuemiao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ������");

	//add npcs into the room
	add_npc("hengshan_yihe");

	add_door("��ɽ������", "��ɽ������", "��ɽ������");
	add_door("��ɽ���Է�ɽ��1", "��ɽ���Է�ɽ��1", "��ɽ������");

    set("long","�������Ǹ�ΡΡ׳�۵Ĺ������ɽ�����أ����и��ϣ�����ʯ�����㡣�����Ǳ����������ߵ� '����' �� " );
    

/*****************************************************
        set("exits", ([ 
           "east"      : __DIR__"kutianjing",
           "west"      : __DIR__"jijiaoshi",
           "northup"   : __DIR__"beiyuedian",
           "southdown" : __DIR__"guolaoling",
        ]));
	set("objects", ([
		__DIR__"npc/he" : 1,
	]));
********************************************/
};


ROOM_END;
