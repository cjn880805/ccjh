//wuhalou2.h

//Sample for room: �廪¥��¥
//coded by zouwenbin
//data: 2000-11-15

ROOM_BEGIN(CRDaLisouth_wuhalou2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�廪¥��¥");

	add_npc("pub_xiaoer2");   // add by zdn 2001-07-13

	add_door("��������廪¥", "��������廪¥", "��������廪¥��¥");

	set("long", "����һ�����ң����ﴰ���������þ߿��������Ǵ���һ������������Ǽ�ֵ���ơ�ƾ�������������ڵ���֮�пɼ���ɽ����ַ壬ֻ��ɽ�����㣬������Σ������Ŀ�������" );
	
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
