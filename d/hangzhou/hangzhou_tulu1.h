//tulu1.h

//Sample for room: ������·
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_tulu1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������·");

	//add npcs into the room
	add_npc("pub_boy");

	add_door("����é�Ҳ�", "����é�Ҳ�", "������·");
	add_door("����ɽ·5", "����ɽ·5", "������·");

	set("long","·��һ��СϪ��Ϫˮ���������ţ���ʱ�����(fish)Ծ��ˮ�档Ϫ�Լ����к�������ͷר���ڵ��㡣" );


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
