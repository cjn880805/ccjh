//twdian.h

//Sample for room: ������
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_twdian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");

	add_npc("pub_xiangke");
	add_npc("shaolin_dao_guo");


	add_door("�����¾�����", "�����¾�����", "������������");
	add_door("������̨��", "������̨��", "������������");

	set("long", "�����������µ��е�����������������ƣ�᣽Ƕ��ˡ�����ǰ��Ҫ��ʢ�Ķࡣ��ǰ�����Ÿ�����ӣ��ƺ���Զ��Ц��������շ��Ĵ������������ԣ���ִ�������˳�������������ϰ������ļ����ߣ����յ����վ������Τ�ԡ�ֻ���������ף�����Ӣ�����������ݣ�˫�ֺ�ʮ������ƺ�����ϡ��������߸���һ��ƫ�" );

/*****************************************************
	set("exits", ([
		"east" : __DIR__"twdian1",
		"west" : __DIR__"twdian2",
		"southdown" : __DIR__"taijie",
		"north" : __DIR__"guangchang2",
	]));
	set("objects",([
		CLASS_D("shaolin") + "/dao-guo" : 1,
		__DIR__"npc/xiang-ke" : 1,
	]));
//	
********************************************/
};


ROOM_END;
