//LingJiu_midao2.h
//Sample for room: ������翷��ɽ�ܵ�2


ROOM_BEGIN(CRLingJiu_midao2);

virtual void create()			//Call it when Room Create
{
	set_name( "���պ�ɽ�ܵ�2");

	add_door("���պ�ɽ�ܵ�1", "���պ�ɽ�ܵ�1", "���պ�ɽ�ܵ�2");
	add_door("���պ�ɽ�ܵ�3", "���պ�ɽ�ܵ�3", "���պ�ɽ�ܵ�2");
	set("no_fight",1);
};


ROOM_END;
