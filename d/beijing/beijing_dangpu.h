//dangpu.h

//Sample for room: ����
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRBeiJing_dangpu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����");

	//add npcs into the room
	//add_npc("jia");
	
	add_door("�����ʳ�", "�����ʳ�", "��������");

	set("long", "����һ����������ƽ���Ƶĵ��̣�һ����߸ߵĹ�̨���������ǰ����̨�ϰ���һ������(paizi)����̨�����ż��ϰ壬һ˫�������۾��������´������㡣" );
	set("no_fight", 1);
	set("no_beg",1);

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
