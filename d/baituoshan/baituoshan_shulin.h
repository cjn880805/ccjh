//shulin.h

//Sample for room: ����ɽ����
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_shulin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ����");

	set("monster_chance", 1);

	add_door("����ɽɽ·1", "����ɽɽ·1", "����ɽ����");
	add_door("����ɽ��ݮ��", "����ɽ��ݮ��", "����ɽ����");

	set("long", "������һƬï�ܵ�����(wood)���Ա�����һ��ľ��(pai)��");

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
