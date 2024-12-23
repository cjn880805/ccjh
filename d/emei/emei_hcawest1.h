//hcawest1.h

//Sample for room:  ���һ���������1
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_hcawest1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���һ���������1");

	add_npc("pub_guest");   // add by zdn 2001-07-14

	add_door("���һ����ֹ㳡", "���һ����ֹ㳡", "���һ���������1");
	add_door("���һ���������2", "���һ���������2", "���һ���������1");

	set("long","�����Ƕ��һ��������ȡ���������ͨ������������ͨ���㳡��");

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
