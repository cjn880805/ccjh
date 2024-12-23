//yuxuguanqian.h

//Sample for room: ����������ǰ
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaliEast_yuxuguanqian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����������ǰ");

	//add npcs into the room
	add_npc("pub_xiaodaogu");
	
	add_door("����Ǻ���Ȫ", "����Ǻ���Ȫ", "����������ǰ");
	add_door("����������", "����������", "����������ǰ");

	set("long", "����һ����ۣ���ǰ����д�š�����ۡ��������֣�����һ����ˮ������С����������������ʵ���������Եĺõط���" );
	
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
