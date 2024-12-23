//houmen.h

//Sample for room: ����ɽ����
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRBaiTuoShan_houmen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ����");

	//add npcs into the room
	add_npc("pub_menwei");
	
	add_door("����", "����ɽ����", "����ɽ����");

	set("long", "���Ǹ�ɽׯ�ĺ��š������нݾ�����ͨ�����޺���");

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
