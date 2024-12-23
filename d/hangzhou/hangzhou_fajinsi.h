//fajinsi.h

//Sample for room: ���ݷ�����
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_fajinsi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ݷ�����");

	//add npcs into the room
	add_npc("pub_shami");/////////////////////////
	add_npc("pub_guest");

	add_door("����ɽ·3", "����ɽ·3", "���ݷ�����");
	add_door("����ɽ·2", "����ɽ·2", "���ݷ�����");

	set("long","��������ɽ��������ǰСϪ��ˮ��������οͲ�ʱ�Ľ��������������������á���������ɽ��·��" );


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
