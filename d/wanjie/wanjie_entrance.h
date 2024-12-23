//entrance.h

//Sample for room: ��ɭ��
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRWanJie_entrance);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɭ��");


	add_door("��ٹ�ɽ·4", "��ٹ�ɽ·4", "��ٹȴ�ɭ��");
	add_door("��ٹȲݵ�", "��ٹȲݵ�", "��ٹȴ�ɭ��");

	set("long","�����Ǻô�һ��ɭ�֣���ѹѹ��һƬ�������ߡ����ر�������һ�Ų����ž�������������ÿ�������������ơ����²ݴ�ï�ܣ���ס��ȥ·��");

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
