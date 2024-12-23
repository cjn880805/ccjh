//road8.h

//Sample for room: �ּ��8
//coded by zwb
//data: 2000-11-23

ROOM_BEGIN(CRFoShan_road8);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ�ּ��8");

	//add npcs into the room
	add_npc("quanzhen_zhang");
	add_npc("pub_zhangkang");
	
	add_door("��ɽ����", "��ɽ����", "��ɽ�ּ��8");
	add_door("��ɽ�ּ��9", "��ɽ�ּ��9", "��ɽ�ּ��8");

	set("long", "������һ���ּ�С���������������ѡ����������������ɽ������ͨ�򸣽�Ȫ�ݡ�" );

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
