//road13.h

//Sample for room: �ּ��13
//coded by zwb
//data: 2000-11-23

ROOM_BEGIN(CRFoShan_road13);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ�ּ��13");

	//add npcs into the room
//	add_npc("animal_wolf2");
	
	add_door("��ɽ�ּ��11", "��ɽ�ּ��11", "��ɽ�ּ��13");
	add_door("��ɽ�ּ��14", "��ɽ�ּ��14", "��ɽ�ּ��13");

	set("long", "������һ���ּ�С���������������ѡ�����ɽ��ï�ܣ�������棬��λ��·Ҫʮ��С�ġ�" );
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
