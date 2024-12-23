//youtiaopu.h

//Sample for room: �ձ�������
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRFoShan_youtiaopu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ձ�������");

	add_npc("pub_xiaoer2");   // add by zdn 2001-07-13
	add_npc("wiz_paihangbang");
	add_npc("wiz_shangshanshi");
//	add_npc("wiz_teacher1");

	add_door("��ɽ", "��ɽ", "��ɽ�ձ�������");

	set("long", "����ձ����������¿��ŵġ����治�����������һ����ը����һ����¯��" );
	set("outdoors", "foshan");
	set("no_fight",  1);

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
