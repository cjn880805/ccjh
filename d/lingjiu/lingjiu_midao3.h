//LingJiu_midao3.h
//Sample for room: ������翷��ɽ�ܵ�3


ROOM_BEGIN(CRLingJiu_midao3);

virtual void create()			//Call it when Room Create
{
	set_name( "���պ�ɽ�ܵ�3");

	add_door("���պ�ɽ�ܵ�2", "���պ�ɽ�ܵ�2", "���պ�ɽ�ܵ�3");
	add_door("���պ�ɽʯ��", "���պ�ɽʯ��", "���պ�ɽ�ܵ�3");
	set("no_fight",1);
};


ROOM_END;
