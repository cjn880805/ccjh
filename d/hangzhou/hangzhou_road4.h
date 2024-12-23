//road4.h

//Sample for room: ������ʯ���4
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_road4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������ʯ���4");
	
	add_npc("pub_cunfu");        //add by zdn 2001-07-14


	add_door("������ʯ���5", "������ʯ���5", "������ʯ���4");
	add_door("���ݺ鴺��", "���ݺ鴺��", "������ʯ���4");

	set("long","��������ˣ����У���˽Σ�����������ϲ����������������������Ǻ鴺�š�����������򶫱��ߡ�");

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
