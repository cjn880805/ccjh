//huichuntang.h

//Sample for room: �ش���ҩ��
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRBeiJing_huichuntang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ش���ҩ��");

	//add npcs into the room
	add_npc("shaolin_xutianch");
	add_npc("pub_huoji");
	
	add_door("��������", "��������", "�����ش���ҩ��");

	set("long", "����һ��ҩ�̣�һ��ŨŨ��ҩζ���㼸����Ϣ�����Ǵ�ҩ���ϵļ��ٸ�С������ɢ�������ġ�һλ�����ڹ�̨��վ�š���̨������һ�ŷ��ƵĹ��(guanggao)����̨����������һ������(neishi)��" );

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
