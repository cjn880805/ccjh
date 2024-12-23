//fang.h

//Sample for room: ����ɽ������
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_fang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ������");

	//add npcs into the room
	add_npc("pub_trainer");
	add_npc("btshan_tongzi");
	
	add_door("����ɽ������", "����ɽ������", "����ɽ������");

	set("long", "�����ǰ���ɽ���ӵ��������������м������䣬��������.������������������գ����Բ��������˴����");

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
