//LingJiu_midao1.h

//Sample for room: ������翷��ɽ�ܵ�1
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_midao1);

virtual void create()			//Call it when Room Create
{
	set_name( "���պ�ɽ�ܵ�1");

	add_door("���պ�ɽ�ܵ�2", "���պ�ɽ�ܵ�2", "���պ�ɽ�ܵ�1");
	add_door("���ջ�԰", "���ջ�԰", "���պ�ɽ�ܵ�1");
	set("no_fight",1);
};


ROOM_END;
