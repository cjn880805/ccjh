//shijian.h

//Sample for room: �������Խ�̨
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_shijian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�������Խ�̨");

	add_door("�����볤��", "�����볤��", "�������Խ�̨");

    set("long", "��ʯ����Χ�ɵ�һ��ʯ̨��Ľ�����ҵĵ��Ӿ����ڴ��д��似��̨�Ƿ��ŵ�ǹ��ꪵ�ʮ�˰������������ˮ���϶�һ�أ���һ�ص�����һЩľ׮(muzhuang)��" );
    
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