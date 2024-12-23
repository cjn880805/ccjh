//liangong.h

//Sample for room: ������
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRBaiTuoShan_liangong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");

	add_npc("pub_tongzi");
	add_npc("btshan_li");
	add_npc("pub_tongzi");

	add_door("����ɽ����", "����ɽ����", "����ɽ������");
	add_door("����ɽ����", "����ɽ����", "����ɽ������");
	add_door("����ɽ����", "����ɽ����", "����ɽ������");
	add_door("����ɽ������", "����ɽ������", "����ɽ������");

	set("long", "�����ǰ���ɽ���ӵ���������������һ���������������Ǹ����ȣ���������һ�����ȣ������������ǳ����ɡ�����ɼ�ΡΡ����");

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
