//shanlu5.h

//Sample for room: ɽ·5
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaLisouth_shanlu5);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ɽ·5");

	//add npcs into the room
	add_npc("pub_wuliangdizi");
	
	add_door("�����ɽ·6", "�����ɽ·6", "�����ɽ·5");
	add_door("�����ɽ·4", "�����ɽ·4", "�����ɽ·5");

	set("long", "һ��ɽ·��������ï�ܵ����֣����������಻���Ĵ�ɽ��������һ���޼ʵ���˫���ɴ�ɭ�֣���˵��а�̽��������л����·���Լ��ɼ�һЩ����Ĵ���ɽ·ת�������š�" );
	
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
