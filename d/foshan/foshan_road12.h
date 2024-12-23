//road12.h

//Sample for room: �ּ��12
//coded by zwb
//data: 2000-11-23

ROOM_BEGIN(CRFoShan_road12);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ�ּ��12");

	//add npcs into the room
	add_npc("animal_snake");
	
	CContainer * coin = add_item("coin");
	coin->set_amount(100);

	add_npc("pub_boy");
	add_npc("pub_girl");
	add_npc("pub_girl1");
	if (random(2)==0)
	{
	    add_npc("pub_boy");
		add_npc("pub_girl");
		add_npc("pub_girl1");
	}
	
	add_door("��ɽ�ּ��10", "��ɽ�ּ��10", "��ɽ�ּ��12");

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
