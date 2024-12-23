//fende.h

//Sample for room: ����ɽ�ص�
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_fende);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ�ص�");

	set("monster_chance", 1);
	//add npcs into the room
	add_npc("pub_guafu");
	
	add_door("����ɽС·1", "����ɽС·1", "����ɽ�ص�");

	set("long", "�����ǻ�����ɭ�Ļķصء�");

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
