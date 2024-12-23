//road14.h

//Sample for room: �ּ��14
//coded by zwb
//data: 2000-11-23

ROOM_BEGIN(CRFoShan_road14);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ�ּ��14");

	//add npcs into the room
//	add_npc("animal_hongma");
	
	add_door("��ɽ�ּ��13", "��ɽ�ּ��13", "��ɽ�ּ��14");
	add_door("Ȫ�����ŵ���", "Ȫ�����ŵ���", "��ɽ�ּ��14");

	set("long", "������һ���ּ�С���������������ѡ��������Ȫ�ݳǵ����ŵ��ţ������Ͽɴ����Ϲ㶫��" );

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
