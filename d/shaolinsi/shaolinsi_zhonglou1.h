//zhonglou1.h

//Sample for room: ��¥һ��
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_zhonglou1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��¥һ��");

	add_npc("shaolin_qing_xiao");

	add_door("�����¾�����", "�����¾�����", "��������¥һ��");


	set("long", "��������¥�ĵײ㣬һ���������ǽ�ϵĻ�ש��϶��͸�����������ש����Ͷ�±��µĹ�Ӱ����ͬһ����������ơ����Ͽ���������ľ¥�����ƶ��ϣ��ƺ����޾�ͷ��ǽ�ǣ��ݼ����൱�ྻ������������ɮ�˴�ɨ��" );

/*****************************************************
	set("exits", ([
		"up" : __DIR__"zhonglou2",
		"out" : __DIR__"zhonglou",
	]));
	set("item_desc",([
		"floor"		:	(: look_floor :),
	]));
	set("objects",([
		__DIR__"npc/saodi-seng" : 1,
	]));
//	
********************************************/
};


ROOM_END;
