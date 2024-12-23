//xiwuchang.h

//Sample for room: �����ھ�ϰ�䳡
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRfuzhou_xiwuchang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����ھ�ϰ�䳡");

	add_npc("fuzhou_cui");     //add by zdn 2001-07-20
	add_npc("fuzhou_shi");      

	add_door("�����ھ�", "���ݸ����ھ�", "���ݸ����ھ�ϰ�䳡");
	add_door("�����ھ�����", "���ݸ����ھ�����", "���ݸ����ھ�ϰ�䳡");

	set("long", "...��...��...����...һ��������֮���ĺ�����ϰ�䳡������" );

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
