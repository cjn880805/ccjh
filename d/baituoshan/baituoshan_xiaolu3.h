//xiaolu3.h

//Sample for room: ����ɽС·3
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_xiaolu3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽС·3");

	set("monster_chance", 1);
	//add npcs into the room
	add_npc("pub_shanzei1");
	
	add_door("����ɽС·2", "����ɽС·2", "����ɽС·3");
	add_door("����ɽС·4", "����ɽС·4", "����ɽС·3");

	set("long", "������һ����ɽ��С·����������ɽ����û��Ҫ����С�ġ�");

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
