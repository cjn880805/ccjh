//yaopu.h

//Sample for room: ҩ��
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRXiangYang_yaopu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ҩ��");

	//add npcs into the room
	add_npc("pub_huoji");////////////////////////
				

	add_door("��������", "��������", "����ҩ��");

	set("long", "ҩ�̲���ȴ�쳣�����ࣻ�����ǹ�̨����̨�����Ǹ�����Ӽ��ٸ�С������һһ�ú�ֽ����ҩ�ĵ����ƣ������ݶ���ǽ������һ��ڵ׽��ֵ��Ҷд�š����ֻش��������¼���������ڷּ�ո��չ����Ĳ�ҩ������һ��С��������������ű�īֽ�⣬��������һλ�����С�һ�ɴ̱�ҩζ�������������䡣" );
/*****************************************************
	set("exits", ([
		"north" : __DIR__"eastjie1",
	]));
	set("objects", ([
		"/d/city/npc/huoji" : 1,
	]));
********************************************/
};


ROOM_END;
