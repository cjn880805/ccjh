//lichunyuan2.h

//Sample for room: ����Ժ
//coded by Fisho
//data: 2000-11-2

ROOM_BEGIN(CRYangZhou_lichunyuan2);

virtual void create()			//Call it when Room Create
{
	set_name( "��������Ժ��¥");
	
	//set("wench_room", 1);
	set("no_fight", 1);

	add_door("��������Ժ", "��������Ժ", "��������Ժ��¥");

};


ROOM_END;
