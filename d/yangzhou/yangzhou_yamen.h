//yamen.h

//Sample for room: ���Ŵ���
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRYangZhou_yamen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���Ŵ���");

	//add npcs into the room

	add_npc("pub_yayi");
	add_npc("pub3_xunbu");
	
	add_door("��������", "��������", "�������Ŵ���");

	set("long", "���������Ŵ��ţ�������ľ���Ž����ر��š����ྲ�����رܡ������ӷַ���ͷʯʨ�ӵ��Աߡ�ǰ����һ����ģ���Ȼ�ǹ�С����ԩ�õġ�������������ǰѲ�ߡ�(paizi)����̨���������ϰ壬һ˫�������������´������㡣�ݽַ���˵���浱�̸��ļۻ�����������ҴӲ��ʻ������������˻���ʲô���գ���������ܲ���" );
/*****************************************************
	set("exits", ([
		"south" : __DIR__"xidajie1",
		"north" : __DIR__"ymzhengting",
	]));
	set("objects", ([
		__DIR__"npc/yayi" : 4,
		__DIR__"npc/xunbu" : 1,
	]));
********************************************/
};


ROOM_END;
