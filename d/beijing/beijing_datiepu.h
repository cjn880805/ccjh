//datiepu.h

//Sample for room: ������
//coded by Fisho
//data: 2000-11-2

ROOM_BEGIN(CRBeiJing_datiepu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");

	//add npcs into the room
	add_npc("pub_tiejiang");
	
	add_door("��������", "��������", "����������");

	set("long", "����һ�Ҽ�ª�Ĵ����̣����İ���һ����¯��¯��������յ�һƬͨ�죬��һ�߽�ȥ�͸е�������ȡ�ǽ�Ƕ��������깤��δ�깤�Ĳ˵���������������ذ�ס����׵��һλ������ͷ�󺹻�����������ר����־���ڴ�����" );

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
