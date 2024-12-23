//shanlu3.h

//Sample for room: ����ɽ·3
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_shanlu3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ·3");

	//add npcs into the room
	add_npc("pub_boy");
	
	add_door("���ݷ�ϲ��", "���ݷ�ϲ��", "����ɽ·3");
	add_door("���ݷ�����", "���ݷ�����", "����ɽ·3");

	set("long","СϪ���ɽ·����Ϫ��һ��Сʯ�š�Ϫ��ũ��С������Ϸ���֡����ϱ㵽�������á����¾��������á�" );


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
