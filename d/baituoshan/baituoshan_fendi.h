//fendi.h

//Sample for room: �ص�
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRBaiTuoShan_fendi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ص�");

	//add npcs into the room
	add_npc("pub_guafu");
	set("monster_chance", 1);
	
	add_door("����ɽɽ��", "����ɽɽ��", "����ɽ�ص�");

	set("long", "�����ǻ�����ɭ�Ļķصء�");
    
    set_temp("times" , 1);

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
//last, register the room into ../server/RoomSetup.cpp