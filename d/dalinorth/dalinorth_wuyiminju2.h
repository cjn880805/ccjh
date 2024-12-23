//wuyiminju2.h

//Sample for room: ������������2
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRDaLiNorth_wuyiminju2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������������2");

	//add npcs into the room
	add_npc("pub_lieren");
	
	add_door("��������ɴ���", "��������ɴ���", "������������2");

	set("long", "����һ��������ķ��ݡ�������ӵĽ��غ����򽲾���������ɽ�ƣ�һ����ʯΪǽ�ͻ�����ľΪ�����ṹ���ºͺ��˷�����£�����ƽ����ʯ��Χǽ�����Ժ����һ��ľ�ܣ�����Щɽ����ҰѼ����������һ���������ڸ������Ƥ���š�" );

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
