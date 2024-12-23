//caopo.h

//Sample for room: ����Ǵ������
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRDaLiNorth_caopo);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����Ǵ������");

	//add npcs into the room
	add_npc("pub_muyangren");
	add_npc("pub_muyangnu");
	add_npc("baiyang");
	add_npc("baiyang");

	add_door("��������ɴ���", "��������ɴ���", "����Ǵ������");

	set("long", "һ��Ƭɽ�³�����ݣ����Ƿ���ţ��ĺõط�������������ߣ���ճ�����ɫ������ɽ����ľ�Ѿ����٣������϶��ǵͰ���ľ��ݵء����ٸ����Ĵ����ڴ˷�����");
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
