//bydian.h

//Sample for room: ���µ�
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_bydian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���µ�");
	
	add_npc("shaolin_laoqiao");       //add by zdn 2001-07-20


	add_door("�����¹㳡", "�����¹㳡", "�����°��µ�");

	set("long", "���ǵزص����ز����������ز����������䣬������Ȼ�в��ٹ�����䣬������ǰ������ü��ɷ�����ֶ�����������һ��֮�£��پ��ľ���ս���ֲ̿��ѡ�" );

/*****************************************************
	set("exits", ([
		"east" : __DIR__"guangchang5",
	]));
//	set("objects",([
//		__DIR__"npc/mu-ren" : 1
//	]));
//	
********************************************/
};


ROOM_END;
