//yihongyuan2.h

//Sample for room: ����Ժ
//coded by Fisho
//data: 2000-11-2

ROOM_BEGIN(CRBeiJing_yihongyuan2);

virtual void create()			//Call it when Room Create
{
	set_name( "����Ժ");
	set("no_fight", 1);
	set("sleep_room",1);
	set("valid_startroom", 1);
	add_npc("pub_xiangke");
	add_door("��������Ժ", "��������Ժ", "��������Ժ��¥");

};


ROOM_END;




