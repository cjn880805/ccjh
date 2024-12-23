//pomiao.h

//Sample for room:  ����������
//coded by zwb
//data: 2000-11-22

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRYZJW_pomiao);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����������");

	add_npc("wudang_lu");	
	

	add_door("����������7","����������7","����������");

    set("long","����һ���������õ������������ưܲ�����������������һ�ԣ����ϵ���Ҳ�����˻ҳ���һ����֪���Ѿ��ܾ�û������������ˡ����з��Ÿ����㰸���������ҵ����ż�����ʣ�����ļ���ͷ��Ҳ��������Ϊ���ε�ԭ��ɣ���˵ؤ�ｭ�Ϸֶ�ͱ����ڴ˴����㰸�ڶ����ģ������±��и���(dong)��");
	set("valid_startroom", 1);

/********************************************************
//	
	set("exits", ([
		"west"  : "/d/gaibang/shoushe",
		"east"  : "/d/gaibang/sheyuan",
		"south" : __DIR__"ml4",
		"enter" : __DIR__"gbandao",
	]));
	set("objects", ([
		CLASS_D("gaibang") + "/lu" : 1,
		CLASS_D("gaibang") + "/peng" : 1,
	]));
	create_door("enter", "С��", "out", DOOR_CLOSED);
********************************************************/
 
};


ROOM_END;
