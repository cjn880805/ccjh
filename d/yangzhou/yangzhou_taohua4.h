//taohua4.h

//Sample for room: �һ���
//coded by zwb
//data: 2000-12-1

RESIDENT_BEGIN(CRYangZhou_taohua4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�һ���");

	set("resident", "�һ���");

	//add npcs into the room
	add_npc("pub_cunzhang");/////////////////////////
	add_npc("animal_diablo2");			
	
	add_door("�����һ���", "�����һ���", "�����һ���");
	add_door("�����һ�ƺ", "�����һ�ƺ", "�����һ���");

	set("long", "�����һ��ȱ����һ��塣����ĸ��ܣ�����������ɽҰ�ķ硢ɽ��Ĵ���ζ��ɽ���ֱ�ӡ�����Ŀ��ݡ�ɽ����һ����һ�Ϫ����Ů�����㲻����ȥ�볾����������������Ѫ�ȡ����ĵ��ն��㾡������һ�У��������һ���������ߡ�ͮ���ǽ�� " );

/*****************************************************
	set("objects", ([
		__DIR__"npc/cunzhang" : 1,
	]));
	set("exits", ([
		"southdown" : __DIR__"taohua3",
		"north"     : __DIR__"taohua5",
	]));
********************************************/
};


RESIDENT_END;
