//xiaoyuan.h

//Sample for room: �һ�ɽׯСԺ
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRTaoHua_xiaoyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�һ�ɽׯСԺ");
	
	add_npc("taohua_yan"); 
	add_npc("taohua_binv");       //add by zdn 2001-07-20


	add_door("�һ���ɽׯ����", "�һ���ɽׯ����", "�һ�ɽׯСԺ");
	add_door("�һ�������", "�һ�������", "�һ�ɽׯСԺ");
	add_door("�һ���С��", "�һ���С��", "�һ�ɽׯСԺ");
	add_door("�һ���˼����", "�һ���˼����", "�һ�ɽׯСԺ");

    

/*****************************************************
    set("exits", ([
        "north" : __DIR__"damen",
        "south" : __DIR__"dating",
        "east"  : __DIR__"bingqi",
        "west"  : __DIR__"chufang",
    ]));
    set("outdoors", "taohua");
********************************************/
};


ROOM_END;
