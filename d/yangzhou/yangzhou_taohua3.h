//taohua3.h

//Sample for room: �һ���
//coded by zwb
//data: 2000-12-1

RESIDENT_BEGIN(CRYangZhou_taohua3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�һ���");

	set("resident", "�һ���");

	add_npc("yunlong_xuanzhen");
	add_npc("pub_baihuanxi");
	add_npc("helpnpc006");

	add_door("�����һ�Ϫ", "�����һ�Ϫ", "�����һ���");
	add_door("�����һ���", "�����һ���", "�����һ���");

	set("long", "˳Ϫ�����ϣ�����ɽ�ƽ��ߣ���ˮ����������Ҳ�����ܼ�������һ�ӵ�ܳ�һƬ��ϼ�����Ĵ���ʱʱ�ɼ���Ȫ���٣������¼䡣�һ�Ϫˮ������������۳���������Ϸ����������һ����ˡ��ȿ�һ������ߵ�С��ʯ��(shibei)б��·�ԡ� " );
	

/*****************************************************
	set("outdoors", "city");
	set("item_desc", ([
		"shibei" : (: look_shibei :),
	]));
	set("exits", ([
		"eastdown" : __DIR__"taohua2",
		"northup"  : __DIR__"taohua4",
	]));
********************************************/
};


RESIDENT_END;
