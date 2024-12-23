//cao1.h

//Sample for room: ����ɽ�ݴ�1
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_cao1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ�ݴ�1");

	set("monster_chance", 1);

	//add npcs into the room
	add_npc("animal_jinshe");/////////////////////////
	add_npc("animal_snake");

	add_door("����ɽ����", "����ɽ����", "����ɽ�ݴ�1");
	add_door("����ɽ�ݴ�2", "����ɽ�ݴ�2", "����ɽ�ݴ�1");

	set("long", "�������Ҳݴԡ��������ȹ�����С���š��������涼�������ߵ���ݣ������߳�û");

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
