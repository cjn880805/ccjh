//taiheju.h

//Sample for room: ̫�;�
//coded by zouwenbin
//data: 2000-11-15

ROOM_BEGIN(CRDali_taiheju);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "̫�;�");

	//add npcs into the room
	add_npc("pub_xiaoer2");
	add_npc("dali_biaotou");        //add by zdn 2001-07-20
	
	add_door("����Ƕ�", "����Ƕ�", "�����̫�;�");
	add_door("�����̫�;Ӷ�¥", "�����̫�;Ӷ�¥", "�����̫�;�");

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
