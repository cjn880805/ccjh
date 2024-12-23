//hengyangcity.h

//Sample for room:  ������
//coded by Fisho
//data: 2000-11-4

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRhengyangcity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");

	//add npcs into the room
	add_npc("wudang_lu");
	add_npc("pub_boy");
	add_npc("pub_girl");
	add_npc("pub_girl1");
	if (random(2)==0)
	{
	add_npc("pub_boy");
		add_npc("pub_girl");
		add_npc("pub_girl1");
	}
	add_door("��ɽ����·", "��ɽ����·", "������");

	add_door("�������", "�������", "������");
	add_door("����������Ժ", "����������Ժ", "������");
	add_door("��������¥", "��������¥", "������");
	add_door("����С��", "����С��", "������");
    set("outdoors", "henshan");
/********************************************************
	set("long", @LONG
������Ǻ����سǡ������ش�ƫԶ���Լ�Զ������ԭ�����ˡ�
LONG );
	set("exits", ([
		"east"   : __DIR__"hsroad3",
		"west"   : __DIR__"hengyang1",
		"south"  : __DIR__"chaguan",
		"north"  : __DIR__"lingxingmen",
	]));
	set("objects", ([
		__DIR__"npc/lu" : 1,
	]));
****************************************************************/
};


ROOM_END;
