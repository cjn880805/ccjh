//kedian.h

//Sample for room: ������ջ
//coded by Fisho
//data: 2000-11-4

ROOM_BEGIN(CRNanYang_kedian);

virtual void create()			
{
	set_name( "������ջ");

	add_npc("pub_xiaoer2");

	add_door("������", "������", "����������ջ");

	set("sleep_room", 1);
	set("valid_startroom", 1);
	set("no_fight", 1);
};


ROOM_END;
