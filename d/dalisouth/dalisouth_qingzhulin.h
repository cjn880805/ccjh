//qingzhulin.h

//Sample for room: ������
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaLisouth_qingzhulin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");

	//add npcs into the room
	add_npc("pub_caisunren");
	add_npc("wei_ake");
	
	add_door("������䶨��", "������䶨��", "�����������");

	set("long", "һ��Ƭï�ܵ�������������ɽ�����ӳ�ȥ���˼��������ۣ������أ�����¬¹���̨�ĸ�Ů��ǰ����ժ����Ϊʳ������Ҳ����Щ��������������Ͳ�ͱ�֯��������¨��" );
	
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
