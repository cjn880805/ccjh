//xuedi3.h

//Sample for room: ѩ��3
//coded by zouwenbin
//data: 2000-12-1

RESIDENT_BEGIN(CRGuanWai_xuedi3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ѩ��3");

	set("resident", "����");

	set("monster_chance", 50);

	add_door("����ѩ��2", "����ѩ��2", "����ѩ��3");
	add_door("���⴬��", "���⴬��", "����ѩ��3");

    set("long","������һƬ��ãã��ѩ�أ�һ���������߼ʡ�����һ����ӰҲû�У����Ļ�ѩ������������֨�����������������һ���¶��Ľ�ӡ������ı����Х��������������ʹ��������̫����������ߣ��Ե���ô�԰ס�" );
    

/*****************************************************
	set("exits", ([
		"north"  : __DIR__"chuanchang",
		"west"   : __DIR__"xuedi2",
	]));
********************************************/
};


RESIDENT_END;
