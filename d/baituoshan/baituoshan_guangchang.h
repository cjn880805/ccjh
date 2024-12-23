//guangchang.h

//Sample for room: ����ɽ�㳡
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_guangchang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ�㳡");

	//add npcs into the room
	add_npc("pub_kid");
	
	add_door("����ɽС��", "����ɽС��", "����ɽ�㳡");
	add_door("����ɽɽ·", "����ɽɽ·", "����ɽ�㳡");
	add_door("����ɽʯ��", "����ɽʯ��", "����ɽ�㳡");
	add_door("����ɽũ��", "����ɽũ��", "����ɽ�㳡");

	set("long", "������һ�鲻С�Ĺ㳡���������ũ��ɹ�Ĺ�������ǡ�����ɽׯ���������м�Сũ�ᣬ�����п�˵أ����Ϸ���һ��С�š�");
	
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
