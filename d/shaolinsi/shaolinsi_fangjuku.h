//fangjuku.h

//Sample for room: ���߿�
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_fangjuku);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���߿�");

	add_npc("shaolin_dao_xiang");

	add_door("������������", "������������", "�����·��߿�");
	add_door("������ҩƷ��", "������ҩƷ��", "�����·��߿�");

	set("long", "����һ��ܴ�ķ��䣬��ǽ����ط���һ��������ӣ����ٹ����ų����ţ�¶������ĸ��ַ��ߣ�Ʒ��֮�࣬������ƽ������һλ����ɮ������ͷ����һ������Ļ��ߡ��������Ҳû��ע�⡣" );

/*****************************************************
	set("exits", ([
		"north" : __DIR__"yaopinku",
		"south" : __DIR__"wuqiku",
	]));
	set("objects",([
		CLASS_D("shaolin") + "/dao-xiang" : 1,
	]));
//	
********************************************/
};


ROOM_END;
