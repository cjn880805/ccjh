//datiepu.h

//Sample for room: ������
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRBaiTuoShan_datiepu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ������");
	add_npc("pub_tiejiang");

	add_door("����ɽ����", "����ɽ����", "����ɽ������");

	set("long", "������һ�Ҵ����̣�����æ�Ŵ������Ʊ����������������͡�");

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
