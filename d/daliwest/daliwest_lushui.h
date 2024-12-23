//lushui.h

//Sample for room: ��ˮ�ذ�
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRDaLiWest_lushui);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ˮ�ذ�");
	
	add_npc("pub_cunfu");    //add by zdn 2001-07-13

	add_door("����ǰ͵ĵ�", "����ǰ͵ĵ�", "�������ˮ�ذ�");
	add_door("����ǰ�ͷ��", "����ǰ�ͷ��", "�������ˮ�ذ�");

	set("long", "һ����·������ˮ�ݹ�ȵ��ϱ���������ˮ������ȥ���������³�ˢ�Ź��д�أ��������ѩɽ������ĸ���ɽ�Ը��ʱ��ա���·��ͨ�˹����Ĵ���͵ĵ飬������������С���䡣" );
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
