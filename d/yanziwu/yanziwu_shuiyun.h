//shuiyun.h

//Sample for room: ������ˮ����
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_shuiyun);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������ˮ����");

	add_door("������׺��¥", "������׺��¥", "������ˮ����");

    set("long", "���ĵ�һ��СС��̨ͤ�����滷ˮ��ֻ��������һ�������밶�����������������棬ˮ��΢�һȺȺ���������ɼ�������һ��ʫ�黭�⡣" );
    
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