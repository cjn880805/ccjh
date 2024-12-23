//dawu.h

//Sample for room: ���д���
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_dawu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���д���");

	//add npcs into the room
	//add_npc("ye");
	
	add_npc("pub_girl");     //add by zdn 2001-07-14
	
	add_door("�������пյ�", "�������пյ�", "�������д���");

	set("long", "����һ��ԭľ�Ƴɵ�����ߴ���������ȥ����Щ���µ��Լ���쳣���ײ�����������ľ�ܿգ�һ��ľ��ͨ���¥����¥��¥���Ϲ���һ������һ�������Ĵ��죬����ȥ���ƾɲ���������ֻ֪���������");  
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
