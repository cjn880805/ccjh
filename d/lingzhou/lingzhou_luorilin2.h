//luorilin2.h

//Sample for room: ����������2
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_luorilin2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����������2");

	//add npcs into the room
	add_npc("animal_dushe");/////////////////////////

	add_door("�������д�·1", "�������д�·1", "����������2");
	add_door("����������·", "����������·", "����������2");

	set("long", "������һƬ��Բ�����ɭ�֣����й�ľ���죬������գ����������������ֵķ�ľ�����������������ľ������������ϣ����˺ͱ��Ĵ����ȱȽ��ǣ�һ���������·����ͨ��ǰ����");  
	
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
