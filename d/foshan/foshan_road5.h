//road5.h

//Sample for room: �ּ��5
//coded by zwb
//data: 2000-11-23

ROOM_BEGIN(CRFoShan_road5);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ�ּ��5");

	add_npc("pub_daoke");    //add by zdn 2001-07-13

	add_door("��ɽ�ּ��6", "��ɽ�ּ��6", "��ɽ�ּ��5");
	add_door("��ɽ�ּ��4", "��ɽ�ּ��4", "��ɽ�ּ��5");

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
