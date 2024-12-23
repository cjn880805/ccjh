//zhangfang.h

//Sample for room: �ʷ�
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRDali_zhangfang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ʷ�");

	//add npcs into the room
	add_npc("pub_huo");
	
	add_door("�������������", "�������������", "����������ʷ�");

	set("long", "�����������������ʷ�������ÿ������׳��룬�������ģ�ȫ�����ﾭ�֣������Ҷ����˵�нٺ�ʹͣ����ڶ����鷳��ࡣ����ȴ����û�������" );

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
