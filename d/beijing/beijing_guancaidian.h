//guancaidian.h

//Sample for room: �ײĵ�
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRBeiJing_guancaidian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ײĵ�");

	//add npcs into the room
	add_npc("shaolin_gaoyanch");
	
	add_door("��������", "��������", "�����ײĵ�");

	set("long", "����һ�ҹײĵ꣬һ���ţ�һ���ľζ�˱Ƕ�������������������������Ӷ����ƾɡ�������һ�����ң�һ����ʮ��ͷ�ľ�׳���ӵ����ſڡ�" );

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
