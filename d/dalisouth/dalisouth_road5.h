//road5.h

//Sample for room: ����·
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaLisouth_road5);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����·");

	//add npcs into the room
//	add_npc("animal_yetu");
        add_npc("dali_wuliangdizi");        //add by zdn 2001-07-20
	
	add_door("�����˫����", "�����˫����", "����ǻ���·");
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
//last, register the room into ../server/RoomSetup.cpp