//zhengting.h

//Sample for room: �һ���ɽׯ����
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRTaoHua_zhengting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�һ���ɽׯ����");

	add_npc("zm_taohua");
	add_npc("pub_chenlingsu");

	add_door("�һ�ɽׯСԺ", "�һ�ɽׯСԺ", "�һ���ɽׯ����");
	add_door("�һ����Է�", "�һ����Է�", "�һ���ɽׯ����");
	add_door("�һ������߷�", "�һ������߷�", "�һ���ɽׯ����");
	add_door("�һ�ɽׯ����", "�һ�ɽׯ����", "�һ���ɽׯ����");

	set("long", "�������һ�ɽׯ����������������ʮ�ֿ��������й����˸������ҵ��鷨�漣���������۵��������йҵ�һ��������");

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
