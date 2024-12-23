//road9.h

//Sample for room: �ּ��9
//coded by zwb
//data: 2000-11-23

ROOM_BEGIN(CRFoShan_road9);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ�ּ��9");

	add_npc("pub_playboy");      //add by zdn 2001-07-14

	add_door("��ɽ�ּ��8", "��ɽ�ּ��8", "��ɽ�ּ��9");
	add_door("��ɽ�ּ��10", "��ɽ�ּ��10", "��ɽ�ּ��9");

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
