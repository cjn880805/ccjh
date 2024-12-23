//xiaohuayuan3.h

//Sample for room:  ������С��԰3
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRChongYang_xiaohuayuan3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������С��԰3");
	
	add_npc("quanzhen_daotong");
	add_npc("quanzhen_wangchuyi");

	add_door("������С��԰2", "������С��԰2", "������С��԰3");

	set("long", "���������������С��԰����ֲ��һЩ�в����������Ļ�ľ��԰������һ����ɽ����ɽ����һ̶СС�Ľ���أ���ˮ�峺���ף��㿴����������ɫ�Ľ����������������յ�������ȥ��������ͯ����������Ϸ�š�");

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp