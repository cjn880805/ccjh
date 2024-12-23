//xiaolu2.h

//Sample for room: ����ɽС·2
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_xiaolu2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽС·2");

	set("monster_chance", 1);
	//add npcs into the room
	add_npc("pub_man");
	
	add_door("����ɽС·1", "����ɽС·1", "����ɽС·2");
	add_door("����ɽС·3", "����ɽС·3", "����ɽС·2");

	set("long", "������һ����ɽ��С·��");

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
