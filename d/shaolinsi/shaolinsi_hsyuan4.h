//hsyuan4.h

//Sample for room: ����Ժ�Ĳ�
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_hsyuan4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����Ժ�Ĳ�");

	add_npc("shaolin_hui_xu");

	add_door("�����·���¥", "�����·���¥", "�����º���Ժ�Ĳ�");
	add_door("�����º���Ժ�岿", "�����º���Ժ�岿", "�����º���Ժ�Ĳ�");

	set("long", "�����Ǻ���Ժ���͵ĵط�����ǽ�����������һ��̫ʦ�Ρ�ǽ��һ�������ż���������и�������������ˡ����ݴ�������׭�֣������������ڣ��ƺ��Ǹ�����²衣һλСɳ����һ�ߴ���վ����" );

/*****************************************************
	set("exits", ([
		"east" : __DIR__"wuchang3",
		"west" : __DIR__"zhulin4",
		"south" : __DIR__"zoulang6",
		"north" : __DIR__"hsyuan5",
	]));
	set("resource/water",1);
	set("objects",([
		CLASS_D("shaolin") + "/hui-xu" : 1,
	]));
//	
********************************************/
};


ROOM_END;
