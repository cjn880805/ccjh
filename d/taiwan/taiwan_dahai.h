//dahai.h

//Sample for room: ̨���
//coded by Fisho
//data: 2000-11-4

ROOM_BEGIN(CRTaiWan_dahai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "̨���");

	set("monster_chance", 20);

	add_door("̨�弦����", "̨�弦����", "̨���");
	add_door("̨��򹷸�", "̨��򹷸�", "̨���");
	add_door("�����", "�����", "̨���");

	set("long", "��������ãã��֮�С��㼫ĿԶ����ֻ������һ�ߣ���Χ�����ڵ㶼û�С�����ֻ�к��˵��Ĵ�����" );
	
	
/*****************************************************

********************************************/
};


ROOM_END;
