//zhongxin.h

//Sample for room: ������
//coded by Fisho
//data: 2000-11-4

ROOM_BEGIN(CRQuanZhou_zhongxin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");
	
	add_npc("pub_boy");
	add_npc("pub_girl");
	add_npc("pub_girl1");
	add_npc("pub_playboy");                  //add by zdn 2001-07-14


	add_door("Ȫ��", "Ȫ��", "Ȫ�ݳ�����");

	set("long", "Ȫ����һ�������ĸ۳ǡ���Ȼ�����ǳ����ģ�����Ҳֻ�ǽŲ�����ع���������������������һ���ۿڣ���������Գ�����������һ��С� " );
	set("outdoors", "quanzhou");
/*****************************************************
	set("exits", ([
                "north" : __DIR__"beimen",
                "south" : __DIR__"nanmen",
                "east"  : __DIR__"haigang",
                "west"  : __DIR__"ximen",
	]));
        set("objects",([
		__DIR__"npc/youxun" : 1,
        ]));
//	

********************************************/
};


ROOM_END;
