//titian1.h

//Sample for room: ����
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRDaLiWest_titian1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����");

	//add npcs into the room
	add_npc("pub_nongfu1");
	add_item("daotian");
	
	add_door("���������", "���������", "���������");

	set("long", "����ˮ�ӹ��������ů������������ɽ�¿����˲�������˼����ǵ��£�����������¶��ϣ����ؿ����������֣������ϡ�裬���ĵ���ũҵ��Ϊ��󣬶��л����ָ�������ɽ�ϵ�һЩ��������������������š�" );
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
