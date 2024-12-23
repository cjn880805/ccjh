//xijie.h

//Sample for room: ����ɽ����
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_xijie);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ����");

	//add npcs into the room
	add_npc("pub_man");
	add_npc("pub_snaker");

				

	add_door("����ɽ����", "����ɽ����", "����ɽ����");
	add_door("����ɽ�Ƶ�", "����ɽ�Ƶ�", "����ɽ����");
	add_door("����ɽС��", "����ɽС��", "����ɽ����");

	set("long", "������С������֡������и��Ƶ꣬��ǰ�����Ÿ߸ߵ���ˣ�һ���಼����ӭ��Ʈ�����ӡ�����ɫ�Ĵ��֡��ơ�");

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
