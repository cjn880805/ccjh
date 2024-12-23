//sikong.h

//Sample for room: ˾����
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRDali_sikong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "˾����");

	add_npc("dali_batianshi");

	add_door("�������������", "�������������", "���������˾����");

	set("long", "�����Ǵ����˾���á�����������ı�ȴ�������鼮���������˰������������㹤�����ֲ��;�" );

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
