//jiulou1.h

//Sample for room: ӭ��¥
//coded by Fisho
//data: 2000-11-4

ROOM_BEGIN(CRNanYang_jiulou1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ӭ��¥");

	//add npcs into the room
	add_npc("pub_xiaoer2");/////////////////////////

	add_door("������", "������", "����ӭ��¥");

	set("long", "��Բ������������ӭ��¥����˵�����˲�֪�����˲�����������ѧʿ���ε��ˣ���ӭ��¥�������޲����ڣ���ȻΪ�����ң�����һ�δ��麣�ڵļѻ����Ӵ�ӭ��¥��������¥�²��ü��ף��˿Ͷ��ǴҴҵ����ˣ������ӣ����ȡ��׾ƾ͸�·ȥ�ˡ�¥����������" );
	
	set("no_fight", "1");
/*****************************************************
	set("exits", ([
		"east" : __DIR__"nanyang",
		"up" : __DIR__"jiulou2",
	]));
	set("objects", ([
		__DIR__"npc/xiao-er2" : 1,
	]));
********************************************/
};


ROOM_END;
