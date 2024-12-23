//shanlu.h

//Sample for room: ��Ĺɽ·
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRGuMu_shanlu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��Ĺɽ·");

	add_npc("pub_daoke");   //add by zdn 2001-07-13

	add_door("��Ĺ����ɽ����", "��Ĺ����ɽ����", "��Ĺɽ·");
	add_door("��Ĺ�յ�", "��Ĺ�յ�", "��Ĺɽ·");

	set("long","����ɽ·������ɽ������ϣ�ɽ·����ʯ������ֻ��һ�˿ɹ������Ƽ�Ϊ�վ�����Զ����ȥ��Ⱥɽ���ƣ���춽��£��������������۵ף���ʱ���˺�����������Ҫ��Хһ������������һƬ�յء������Ͼ�������ɽ���塣" );

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
