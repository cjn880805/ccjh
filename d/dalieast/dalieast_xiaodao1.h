//xiaodao1.h

//Sample for room: ������ּ�С��1
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_xiaodao1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������ּ�С��1");

	set("resident", "������");

	add_npc("pub_biaotou");   //add by zdn 2001-07-12

	add_door("����Ǻ���Ȫ", "����Ǻ���Ȫ", "������ּ�С��1");
	add_door("����Ǻ�����", "����Ǻ�����", "������ּ�С��1");
	add_door("�������Ϫ��̶", "�������Ϫ��̶", "������ּ�С��1");

	set("long", "������С������ǰ��Լ��ʮ���ߣ�ֻ������������Ũ����죬һ����ȪǶ����䣬������ʯ��Ȫˮ��������������Ǯ���ڳ��У����仺�����䣬���������ɸ�£��ص�������˸������Ȫˮ�������ر߾����Լ�����ߵĵط���һ�ֿɺϱ������ɣ����Ȫ�ϣ����Խ���Сͤ��С��������ʮ�����ġ� " );

};

RESIDENT_END;
