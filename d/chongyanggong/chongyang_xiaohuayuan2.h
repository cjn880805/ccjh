//xiaohuayuan2.h

//Sample for room:  ������С��԰2
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRChongYang_xiaohuayuan2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������С��԰2");
	
	add_npc("quanzhen_wangzhi");

	add_door("������С��԰1", "������С��԰1", "������С��԰2");
	add_door("������С��԰3", "������С��԰3", "������С��԰2");

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