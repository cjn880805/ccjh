//road10.h

//Sample for room: �ּ��10
//coded by zwb
//data: 2000-11-23

ROOM_BEGIN(CRFoShan_road10);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ�ּ��10");

	//add npcs into the room
//	add_npc("animal_huananhu");
	
	add_door("��ɽ�ּ��9", "��ɽ�ּ��9", "��ɽ�ּ��10");
	add_door("��ɽ�ּ��11", "��ɽ�ּ��11", "��ɽ�ּ��10");
	add_door("��ɽ�ּ��12", "��ɽ�ּ��12", "��ɽ�ּ��10");

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
