//baihe.h

//Sample for room: �׺�
//coded by zouwenbin
//data: 2000-12-1

RESIDENT_BEGIN(CRGuanWai_baihe);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�׺�");

	set("resident", "�׺�");

	add_npc("guanwai_yuzhenzi");   // add by zdn 2001-07-20

	set("monster_chance", 50);

	add_door("����Ȳݶ�", "����Ȳݶ�", "����׺�");
	add_door("��������1", "��������1", "����׺�");

	set("long","�����ǳ���ɽ�µ�һ��С�壬ֻ���ģ�����ª��Сľ�ݡ����ﲢû�й̶��ľ���ľ�ݶ��ǽ�ɽ�ɲεĲο����ǣ�Ϊ�����ڽ�ɽǰ��������úõ���Ϣһ�¡��������Ρ�������ĳ��״�ɽ��" );
    

/*****************************************************
	set("exits", ([
		"west"  : __DIR__"caoguduo",
		"east"  : __DIR__"milin1",
		"north" : __DIR__"xiaowu",
	]));
********************************************/
};


RESIDENT_END;
