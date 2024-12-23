//shanlu2.h

//Sample for room: ����ɽ·2
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_shanlu2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ·2");

	//add npcs into the room
	add_npc("honghua_honghua1");
	
	add_door("���ݷ�����", "���ݷ�����", "����ɽ·2");
	add_door("���ݷ�����", "���ݷ�����", "����ɽ·2");

	set("long","�����������Ǻܿ��ɽ·�ϣ�ֻ�����Է�����������ɫ���ˡ�һ��СϪ��·������������Ϫ����һũ�ҡ�ɽ��С����ʹ������������֮�⡣���ϱ㵽�������á����¾��������á�" );

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
