//road2.h

//Sample for room: �ּ��2
//coded by zwb
//data: 2000-11-23

ROOM_BEGIN(CRFoShan_road2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ�ּ��2");

	//add npcs into the room
	add_npc("animal_qingshe");
	
	add_door("��ɽ�ּ��3", "��ɽ�ּ��3", "��ɽ�ּ��2");
	add_door("��ɽ�ּ��1", "��ɽ�ּ��1", "��ɽ�ּ��2");

	set("long", "������һ���ּ�С���������������ѡ������ǹ����ˡ�����ɽ��ï�ܣ�������棬��λ��·Ҫʮ��С�ġ�" );

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
