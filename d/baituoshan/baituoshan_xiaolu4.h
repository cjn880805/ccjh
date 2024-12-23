//xiaolu4.h

//Sample for room: ����ɽС·4
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_xiaolu4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽС·4");

	//add npcs into the room
	add_npc("pub_shanzei2");
	
	add_door("����ɽ����", "����ɽ����", "����ɽС·4");
	add_door("����ɽС·3", "����ɽС·3", "����ɽС·4");

	set("long", "������һ����ɽ��С·�����ֳ�һ�������������ɽ�������ѡ�");

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
