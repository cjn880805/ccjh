//shanlu1.h

//Sample for room: ����ɽɽ·1
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shanlu1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽɽ·1");
	add_npc("pub_chenfeng");
	add_npc("pub_linlin");

	add_door("����ɽɽ·2", "����ɽɽ·2", "����ɽɽ·1");
	add_door("����ɽ��", "����ɽ��", "����ɽɽ·1");

    set("long","������ɽ·�ľ�ͷ�����������һƬС���֣��۶��򶫣���������ɽ��ɽ���ˡ�" );

};

ROOM_END;
