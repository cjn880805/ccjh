//xxh1.h

//Sample for room: ���޺�
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXingXiu_xxh1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���޺�");

	add_npc("xingxiu_zhaixing");	

	add_door("���޺���ɽɽ·2", "���޺���ɽɽ·2", "���޺�");
	add_door("���޺����¶�", "���޺����¶�", "���޺�");
	add_door("���޺�ʯ��", "���޺�ʯ��", "���޺�");

    set("long","���������޺��ߡ�˵�Ǻ�����ʵ��Ƭ���������󣬵���ʮ���ն񡣶���ʯ����һ���ѷ�ͨ��һ��ɽ����������һ���ݾ���ͨ������ɽ��" );


};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp