//huayuan.h

//Sample for room: ��ľ�¶�С��԰
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_huayuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ľ�¶�С��԰");
	
	add_npc("ry_dongfang");

	add_door("��ľ�¶�ͨ��6��", "��ľ�¶�ͨ��6��", "��ľ�¶�С��԰");
	add_door("С��԰", "��ľ��С��԰", "��ľ�¶�С��԰");

	set("long", "�ӻ谵�ĵص��г������㷢���Լ�����������һ�������µ�С��԰�У���÷�������ɴ�أ����õ��ľ߽��ģ�����ȥ��һ�侫��С�ᡣ ");
    
};

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp