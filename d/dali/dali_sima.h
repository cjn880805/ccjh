//sima.h

//Sample for room: ˾����
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRDali_sima);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "˾����");

	add_npc("dali_fanye");	

	add_door("�������������", "�������������", "���������˾����");

	set("long", "�����Ǵ����˾���á�������ǿ�Σ�������ެ���������߽���������˾���Ͷ�֮��������ެ���Ѵ����Ѿã�ÿÿǿ��в�ȣ������ò��ر���������" );

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
