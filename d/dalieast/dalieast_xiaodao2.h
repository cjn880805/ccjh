//xiaodao2.h

//Sample for room: ������ּ�С��2
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_xiaodao2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������ּ�С��2");

	set("resident", "������");

	add_npc("animal_snake");  //add by zdn 2001-07-12

	add_door("���������", "���������", "������ּ�С��2");
	add_door("����Ǻ�����", "����Ǻ�����", "������ּ�С��2");

	set("long", "����һ����ʯ�̳ɵ�С�����������۵�ͨ��ǰ�������������ܵ����������˼�������Ω�����ߵ��·�棬΢�紵����Ҷ��ɳɳ���졣" );
};

RESIDENT_END;
