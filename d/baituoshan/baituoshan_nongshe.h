//nongshe.h

//Sample for room: ũ��
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRBaiTuoShan_nongshe);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ũ��");

	//add npcs into the room
	add_npc("pub_woman");
	
	add_door("����ɽ�㳡", "����ɽ�㳡", "����ɽũ��");

	set("long", "������һ��Сũ�ᣬ�Ҿߺ��¡��������˱Ƚϸ�ԣ��");

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
