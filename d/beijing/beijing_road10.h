//road10.h

//Sample for room: С��10
//coded by zwb
//data: 2000-12-1

ROOM_BEGIN(CRBeiJing_road10);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "С��10");

	//add npcs into the room
	add_npc("pub_tiaofu");
	
	add_door("����", "����", "����С��10");
	add_door("����", "����", "����С��10");

	set("long", "������һ����������Ĵ�����ϡ��������������������ӵġ����̵ġ����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡���ʱ����������������߷ɳ۶���������һ·��������·��������������������֡����߾��Ǵ�֮���ˡ�" );
	
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
