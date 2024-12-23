//taiheju2.h

//Sample for room: ̫�;Ӷ�¥
//coded by zouwenbin
//data: 2000-11-15

ROOM_BEGIN(CRDali_taiheju2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "̫�;Ӷ�¥");

	//add npcs into the room
	add_npc("pub_genu");/////////////////////////

	add_door("�����̫�;�", "�����̫�;�", "�����̫�;Ӷ�¥");

	set("long", "���Ǵ���������ľ�¥��¥����Щ�����С�ԣ��������˳���������·�ˡ�¥����������" );

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
