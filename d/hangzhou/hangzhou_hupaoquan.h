//hupaoquan.h

//Sample for room: ���ݻ���Ȫ
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_hupaoquan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ݻ���Ȫ");
	
	add_npc("pub_playboy");       // add by zdn 2001-07-14


	add_door("������ʯ���17", "������ʯ���17", "���ݻ���Ȫ");

	set("long"," ֻ��Ȫˮ��ɳ���������������峺���ס��ഫ��λ�����Կյĺ������ɽ�羰���㣬��ס������������ˮԴ��ȱ��׼��Ǩ�ߡ�һҹ�����������˵��������ɽͯ��Ȫ����ǲ�������������ڶ��죬��Ȼ������ֻ�ϻ��ܵ���Ѩ��ӿ��Ȫˮ�����Զ���Ϊ������Ȫ��");

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
