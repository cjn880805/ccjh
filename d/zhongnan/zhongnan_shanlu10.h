//shanlu10.h

//Sample for room: ����ɽɽ·10
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shanlu10);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽɽ·10");

	//add npcs into the room  2001-07-10 zdn add
	add_npc("pub_liumangtou");
	add_npc("pub_liumang");
	add_npc("pub_liumang");

	add_door("����ɽ������", "����ɽ������", "����ɽɽ·10");
	add_door("����ɽ������", "����ɽ������", "����ɽɽ·10");

	set("long","�˴�λ�����ɽɽ�š�Ρ�������ɽ���Թ�����������������������ʥ�ء������������ɽ���������������أ�����Խʮ���أ�����˰����������������ɽ֮�ơ������ɿ���һ������������һ��ͨ�����ֵ��ľ�С·��������������ɽ." );

/*****************************************************

*****************************************************/
};

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
