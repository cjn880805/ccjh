//mianguan.h

//Sample for room: ���
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRBeiJing_mianguan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���");

	//add npcs into the room
	add_npc("pub_xiaoer2");/////////////////////////
				

	add_door("��������", "��������", "�������");

	set("long", "����һ�Ҽ�Ǯ��������ݣ�����ǳ���¡������οͶ�ѡ��������ţ��������������������صķ������顣������Ҳ��ϲ���������С����������æ������ת���Ӵ�����ǻ�����Ŀ��ˡ������������Сľ���ԣ������˸��ָ�����ʳ�͡�" );
	set("sleep_room",1);
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
