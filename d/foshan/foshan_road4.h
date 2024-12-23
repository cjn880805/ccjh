//road4.h

//Sample for room: �ּ��4
//coded by zwb
//data: 2000-11-23

ROOM_BEGIN(CRFoShan_road4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ�ּ��4");

	//add npcs into the room
	add_npc("animal_snake");
	add_npc("pub_kunzong");
	
	add_door("��ɽ�ּ��5", "��ɽ�ּ��5", "��ɽ�ּ��4");
	add_door("��ɽ�ּ��3", "��ɽ�ּ��3", "��ɽ�ּ��4");

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
