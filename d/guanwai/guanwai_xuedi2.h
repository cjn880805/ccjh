//xuedi2.h

//Sample for room: ѩ��2
//coded by zouwenbin
//data: 2000-12-1

RESIDENT_BEGIN(CRGuanWai_xuedi2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ѩ��2");

	set("resident", "����");
	
	add_npc("animal_dog");           // add by zdn 2001-07-14

	set("monster_chance", 50);

	add_door("����ѩ��1", "����ѩ��1", "����ѩ��2");
	add_door("����ѩ��3", "����ѩ��3", "����ѩ��2");

    set("long","������һƬ��ãã��ѩ�أ�һ���������߼ʡ�����һ����ӰҲû�У����Ļ�ѩ������������֨�����������������һ���¶��Ľ�ӡ������ı����Х��������������ʹ��������̫����������ߣ��Ե���ô�԰ס�" );
    

/*****************************************************
	set("exits", ([
		"east"       : __DIR__"xuedi3",
		"southwest"  : __DIR__"xuedi1",
	]));
********************************************/
};


RESIDENT_END;
