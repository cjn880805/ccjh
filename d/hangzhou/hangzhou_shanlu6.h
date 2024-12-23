//shanlu6.h

//Sample for room: ����ɽ·6
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_shanlu6);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ·6");

	//add npcs into the room
	add_npc("animal_laofu");

	add_door("�������ɽ", "�������ɽ", "����ɽ·6");
	add_door("�������ɽ��", "�������ɽ��", "����ɽ·6");

	set("long"," ɽ·��᫣��������ӡ�������ľ�Դ䣬����ï�ܡ�ɽ·����һɽ������˵������ʱ�ᴫ���������������ϻ�������������ɽ��·��������ɽ�㵽��ɽ�ס�");

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
