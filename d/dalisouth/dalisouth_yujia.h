//yujia

//Sample for room: ���
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaLisouth_yujia);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���");

	//add npcs into the room
	add_npc("pub_funu");
	
	add_door("����Ǻ�����", "����Ǻ�����", "��������");

	set("long", "���Բ�ר�����ԣ�����������������������һ����ͨ����¥���²�ͨ��������Ȧ���޲��������Ĺ��һλ̨�ĸ�Ů����ϸ�ĵر�֯������¥����һ��ľ�ܣ����������ŵ��㣬������ɹ��ɡ�" );
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
