//zahuopu.h

//Sample for room: �ӻ���
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRBeiJing_zahuopu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ӻ���");

	//add npcs into the room
	add_npc("pub_zeng");
	add_door("��������", "��������", "�����ӻ���");

	set("long", "����һ���ӻ��̣�����С�������һ�أ�����һЩ�ճ���Ʒ�����ƹ������������һֻ�����ϣ��к��Ź������ˡ���˵˽������Ҳ��һЩ���صĶ�����̯������һ������(zhaopai)��" );
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
