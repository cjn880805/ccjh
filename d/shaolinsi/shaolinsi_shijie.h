//shijie.h

//Sample for room: ������ʯ��
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_shijie);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������ʯ��");
	
	add_npc("zm_shaolin");
	add_npc("helpnpc019");

	add_door("������ɽ�ŵ�", "������ɽ�ŵ�", "������ʯ��");
	add_door("��ɽ̫����", "��ɽ̫����", "������ʯ��");

	set("long", "ʯ�������������죬�ٲ��ڽ���Խ��ԽС��ˮ��Ҳ����Զȥ��λ���Żһ�ɫɮ�µ�ɮ�˲����������������ɽ��ʱ��Ų����ȣ������Ǹ�����ӡ�����Զ�����ƺ����Կ���ʯ��һ�ǡ�" );

/*****************************************************

********************************************/
};


ROOM_END;
