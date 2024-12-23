//cangshanlu1.h

//Sample for room: ��ɽɽ·
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRDaLiNorth_cangshanlu1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽɽ·");

	//add npcs into the room
	add_npc("pub_lieren");
	
	add_door("����ǲ�ɽ�в�", "����ǲ�ɽ�в�", "����ǲ�ɽɽ·");
	add_door("����Ǻ���", "����Ǻ���", "����ǲ�ɽɽ·");

	set("long", "�˴������ӱߣ�����ɽ�ڼ�����ֱ��ֱ�£���ǰ��һ������Ա����϶������ڴ�����������ȥ����ˮ������ӿ���Ļ��Ӱ�������һ�����˵ĺ��졣����ǡ����壬�Ӵ���խ���ӹ��ϲ���������ֻ�����������������������˰���һ�ô����ϣ��ƿ���Ԯ������" );

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
