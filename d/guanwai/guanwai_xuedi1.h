//xuedi1.h

//Sample for room: ѩ��1
//coded by zouwenbin
//data: 2000-12-1

RESIDENT_BEGIN(CRGuanWai_xuedi1);

virtual void create()			//Call it when Room Create
{
	set_name( "ѩ��1");

	add_npc("pub_yujiaofeng");
	add_npc("pub_xieyulun");

	set("resident", "������Զ");

	add_door("������Զ", "������Զ", "����ѩ��1");
	add_door("����ѩ��2", "����ѩ��2", "����ѩ��1");

    set("long","������һƬ��ãã��ѩ�أ�һ���������߼ʡ�����һ����ӰҲû�У����Ļ�ѩ������������֨�����������������һ���¶��Ľ�ӡ������ı����Х��������������ʹ��������̫����������ߣ��Ե���ô�԰ס�" );
    

/*****************************************************
	set("exits", ([
		"west"       : __DIR__"dongcheng",
		"northeast"  : __DIR__"xuedi2",
	]));
********************************************/
};

RESIDENT_END;
