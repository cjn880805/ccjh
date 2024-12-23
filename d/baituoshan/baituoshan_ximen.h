//ximen.h

//Sample for room: ����ɽ����
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_ximen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ����");

	//add npcs into the room
	add_npc("pub_menwei");
	add_npc("zm_btshan");

	add_door("����ɽ����", "����ɽ����", "����ɽ����");
	add_door("����ɽ�ݴ�1", "����ɽ�ݴ�1", "����ɽ����");

	set("long", "���Ǹ�ɽׯ�����š������ε����ŷ������£����Ϲ���һ������(pai)�����������Ӳݴ�����");

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
