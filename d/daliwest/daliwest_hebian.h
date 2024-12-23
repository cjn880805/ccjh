//hebian.h

//Sample for room: �ӱ�
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRDaLiWest_hebian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ӱ�");

	//add npcs into the room
	add_npc("pub_wyshangfan");
	
	add_door("�����ɽ��", "�����ɽ��", "����Ǻӱ�");
	add_door("����Ǻ���", "����Ǻ���", "����Ǻӱ�");

	set("long", "�������ӱߣ�����ɽ�ڼ�����ֱ��ֱ�£�������һ������Ա������������ڴ����򶫱��ڶ�ȥ����ˮ��ӿ���������죬����һ�����˵ĺ��졣�˴��ӹ���խ��ǰ������������������һ�ô����ϣ���һ�˿�Ӷ������ƿ���Ԯ��������ȥ�������ǳ�ɽ���롣" );
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
