//road5.h

//Sample for room: ����ǻ���·
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRDali_road5);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ǻ���·");

	//add npcs into the room
	add_npc("pub_mowentian");
	
	add_door("���������", "���������", "����ǻ���·");
	add_door("��ɽ�ּ��1", "��ɽ�ּ��1", "����ǻ���·");


	set("long", "�����Ǵ����ڣ�������һ��������·�ϣ����˶��Ǳ��صİ������ˡ�Ҳ�����Щ��ԭ���������߶�����·����ͨ��ٵ�����������·ͨ������ǵ����ţ����пɴ�㶫��ɽ��" );

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




