//manjuelong.h

//Sample for room: ��������¤
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_manjuelong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������¤");

	//add npcs into the room
	add_npc("pub_playboy");

	add_door("����ˮ�ֶ�", "����ˮ�ֶ�", "��������¤");
	add_door("����ʯ�ݶ�", "����ʯ�ݶ�", "��������¤");

	set("long","ɽ·����һ��С���䣬�������ܹ𻨳��֡�ÿ�������ʢ����Ʈ���������Ϊ����ѩ���硱��������ˮ�ֶ�������ʯ�ݶ���" );

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
