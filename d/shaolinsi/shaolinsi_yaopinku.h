//yaopinku.h

//Sample for room: ҩƷ��
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_yaopinku);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ҩƷ��");

	add_npc("shaolin_dao_xiang2");

	add_door("�����·��߿�", "�����·��߿�", "������ҩƷ��");

	set("long", "������ȫ��ɮ������ҩƷ�ĵط��������������Ź�ŨŨ��ҩζ����ǽ��һ���Ÿ߼�������ҩ��ÿ��ҩ�����ϰٸ�װҩ��С���룬������������������ĸ��ֲ�ͷҩ��������ǽ�߷��Ÿ��޴�İ���ɫɼľҩ���������Ÿ����з���ӡǩ�Ĵ������һλ����ɮ��������æµ�ų���ҩƷ����ҩ������" );

/*****************************************************
	set("exits", ([
		"south" : __DIR__"fangjuku",
	]));
	set("objects",([
		CLASS_D("shaolin") + "/dao-xiang2" : 1,
	]));
//	
********************************************/
};


ROOM_END;
