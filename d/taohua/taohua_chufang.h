//chufang.h

//Sample for room: ����
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRTaoHua_chufang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����");
	add_npc("taohuadao_yan");
	add_npc("pub_xiangke");

	add_door("�һ�ɽׯСԺ", "�һ�ɽׯСԺ", "�һ�������");

	set("long", "�������һ�ɽׯ����������������ʮ�ֿ��������й����˸������ҵ��鷨�漣���������۵��������йҵ�һ��������");
	set("valid_startroom", 1);
	set("no_beg", "1");

/*****************************************************
	set("exits", ([
	    "north" : __DIR__"qianyuan",
	    "south" : __DIR__"houyuan",
	    "east"  : __DIR__"daojufang",
	    "west"  : __DIR__"wofang" ,
	]));
	set("objects", ([
	    "/kungfu/class/taohua/huang" : 1,
	]) );    
********************************************/
};


ROOM_END;




