//faxisi.h

//Sample for room: ���ݷ�ϲ��
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_faxisi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ݷ�ϲ��");

	//add npcs into the room
	add_npc("pub_guest");
	
	add_door("����ɽ·4", "����ɽ·4", "���ݷ�ϲ��");
	add_door("����ɽ·3", "����ɽ·3", "���ݷ�ϲ��");

	set("long","��ϲ��������������������ĵ�һ����������οͲ�ʱ�Ľ��������������ɴ���������������ɽ��·��" );


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
