//qinglong3.h

//Sample for room: Ȫ���������ͥ3
//coded by Fisho
//data: 2000-11-4

ROOM_BEGIN(CRQuanZhou_qinglong3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ȫ���������ͥ3");
	
	add_npc("pub_jianke");       //add by zdn 2001-07-14


	add_door("Ȫ��������ǰͥ", "Ȫ��������ǰͥ", "Ȫ���������ͥ3");

	set("long", "����һƬ���ܵ����֡������˼�������Ω�����ߵ��·�棬��ɮ��ľ������΢�紵����Ҷ�������������������˳���Ϊ֮һ�ӣ����Ǿ��ѵ��������ڡ�" );
	set("no_clean_up", 1);
	
/*****************************************************
	set("exits", ([
		"south" : __DIR__"qinglong",
	]));
//	set("objects",([
//		__DIR__"npc/tang1" : 1,
//	]));
********************************************/
};


ROOM_END;
