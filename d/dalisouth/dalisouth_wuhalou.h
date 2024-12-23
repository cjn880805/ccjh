//wuhalou.h

//Sample for room: �廪¥
//coded by zouwenbin
//data: 2000-11-15

ROOM_BEGIN(CRDaLisouth_wuhalou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�廪¥");

	//add npcs into the room
	add_npc("pub_shizhe1");
	add_npc("pub_shizhe1");
	add_npc("pub_shizhe1");
	
	add_door("����ǹŵ�", "����ǹŵ�", "��������廪¥");
	add_door("��������廪¥��¥", "��������廪¥��¥", "��������廪¥");

	set("long", "�������廪¥��ǰ�������쳣������������һ�������ȫ����ʯ�̵أ��ڰ���䣬����������ɶ�����ǧ�ˡ�ʱʱ�ɼ���������������ʳ�������ߡ�" );

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
