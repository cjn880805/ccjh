//shuitian.h

//Sample for room: ˮ��
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaLisouth_shuitian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ˮ��");

	//add npcs into the room
//	add_npc("animal_cow");
	add_npc("pub_nongfu1");


	add_door("�����³����", "�����³����", "�����ˮ��");

	set("long", "����һƬ����ƽ�ص�ũ������﹡��ȫ������ˮ��û�ţ�һЩ���Ჿ�ĸ�Ů���Ž�������������������ˮ���㣬��Ȼû�н��������������ر�Ĺ�ȣ�ÿ������������Ȼ��ˮ������" );
	
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
