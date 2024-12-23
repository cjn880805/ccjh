//cao2.h

//Sample for room: ����ɽ�ݴ�2
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_cao2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ�ݴ�2");

	set("monster_chance", 1);
	//add npcs into the room
	add_npc("animal_snake");
	add_npc("animal_qingshe");


	add_door("����ɽ�ݴ�1", "����ɽ�ݴ�1", "����ɽ�ݴ�2");
	add_door("����ɽ����", "����ɽ����", "����ɽ�ݴ�2");

	set("long", "�������Ҳݴԡ������������֡��������涼�������ߵ���ݳ����߳�û��");

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
