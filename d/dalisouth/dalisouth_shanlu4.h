//shanlu4.h

//Sample for room: ɽ·4
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaLisouth_shanlu4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ɽ·4");

	//add npcs into the room
	add_npc("pub_shennongdizi");
	
	add_door("�����ɽ·5", "�����ɽ·5", "�����ɽ·4");
	add_door("�����ɽ·2", "�����ɽ·2", "�����ɽ·4");

	set("long", "һ��ɽ·��������ï�ܵ����֣����������಻���Ĵ�ɽ����·���Լ��ɼ�һЩ����Ĵ���ɽ·���������š�" );

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
