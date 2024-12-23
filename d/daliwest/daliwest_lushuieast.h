//lushuieast.h

//Sample for room: ����ˮ�ӹ�
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRDaLiWest_lushuieast);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ˮ�ӹ�");

	add_npc("pub_shaonu");
	add_npc("pub_daoke");       // add by zdn 2001-0-13

	add_door("����Ǳ���ѩɽ", "����Ǳ���ѩɽ", "����Ƕ���ˮ�ӹ�");
	add_door("����ǰ͵ĵ�", "����ǰ͵ĵ�", "����Ƕ���ˮ�ӹ�");

	set("long", "������һ��Ƭ�ӹȴ��ڱ���ѩɽ�͸���ɽ֮�䣬�ɶ���ˮ��ˢ���ɣ����Ƶ��ݣ�����������ů���۾��˴����������ˡ����������غӹȿ�����һЩ�������ɽ�����ܣ����Ӷ�������ԡ����Ž��µ�����ֱ��һ�������ӡ�" );
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
