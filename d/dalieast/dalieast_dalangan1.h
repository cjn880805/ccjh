//dalangan1.h

//Sample for room: ����Ǵ����
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaliEast_dalangan1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����Ǵ����");

	//add npcs into the room
//	add_npc("animal_shanyang");
//	add_npc("animal_shanyang");
//	add_npc("animal_shanyang");
//	add_npc("animal_cow");
//	add_npc("animal_cow");

//	add_door("�����ũ��4", "�����ũ��4", "����Ǵ����");

	set("long", "����һ�ô��������������ڴ˽���һ���൱��ĸ������²�������һ��Ȧ��ʮ��ͷţ���Աߵ�¥���޵��Ŀ����������Ǳ��ص������˼ҡ�" );

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
