//shuyuan.h

//Sample for room: �����Ժ
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRhangzhou_shuyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����Ժ");
	
	add_npc("pub_shutong");    // add by zdn 2001-07-14


	add_door("������ʯ���12", "������ʯ���12", "���ݷ����Ժ");

	set("long","��Ժ������һ�ҡ������Ժ������Ժ��������λ���ߣ�����������ʫ���ԡ��������Ե�����������ֽ�ͱ�ī��" );

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
