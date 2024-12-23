//fajingsi.h

//Sample for room: ���ݷ�����
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_fajingsi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ݷ�����");

	//add npcs into the room
	add_npc("pub_shami");/////////////////////////
	add_npc("pub_guest");
	add_item("juhua");

	add_door("����ɽ·2", "����ɽ·2", "���ݷ�����");
	add_door("����ɽ·1", "����ɽ·1", "���ݷ�����");

	set("long","�����½���СϪ�ԣ���������š�������οͲ�ʱ�Ľ��������������������á���������ɽ��·��" );

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
