//caifang.h

//Sample for room: ��
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRBaiTuoShan_caifang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��");

	set("monster_chance", 1);
	//add npcs into the room
//	add_npc("pub_laocai");
	
//	add_door("����ɽ����", "����ɽ����", "����ɽ��");

	set("long", "���Ǽ䲻��Ĳ񷿣�ľ���Ѿ����չ��ˣ�ǽ�Ƿ��ż��ѡ��񵶡�");

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
