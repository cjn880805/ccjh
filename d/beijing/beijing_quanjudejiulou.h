//quanjudejiulou.h

//Sample for room: ȫ�۵¾�¥
//coded by Fisho
//data: 2000-11-2

ROOM_BEGIN(CRBeiJing_quanjudejiulou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ȫ�۵¾�¥");

	//add npcs into the room
	add_npc("pub_xiaoer2");/////////////////////////
				

	add_door("��������", "��������", "����ȫ�۵¾�¥");

	set("long", "��Բ������������ȫ�۵¾�¥����˵�����˲�֪�����˲�����¥�²��ü��ף��˿Ͷ��ǴҴҵ����ˣ������ӡ����ȡ��׾ƾ͸�·ȥ�ˡ�¥����������" );
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
