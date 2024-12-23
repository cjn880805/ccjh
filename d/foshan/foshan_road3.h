//road3.h

//Sample for room: �ּ��3
//coded by zwb
//data: 2000-11-23

ROOM_BEGIN(CRFoShan_road3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ�ּ��3");

	//add npcs into the room
	add_npc("animal_laofu");
	
	add_door("��ɽ�ּ��4", "��ɽ�ּ��4", "��ɽ�ּ��3");
	add_door("��ɽ�ּ��2", "��ɽ�ּ��2", "��ɽ�ּ��3");

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
