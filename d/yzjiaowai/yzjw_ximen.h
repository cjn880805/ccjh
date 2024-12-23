//ximen.h

//Sample for room:  ��������
//coded by zwb
//data: 2000-11-22

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRYZJW_ximen);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������");

	add_npc("pub_wujiang");
	add_npc("pub_bing");
	add_npc("mingjiao_fenggongying");
	add_npc("pub_xixuxi");

	add_door("��������","��������","��������");
	add_door("�������Ŵ��","�������Ŵ��","��������");
	add_door("�����һ���","�����һ���","��������");

    set("long","���������ţ�����ǰ�����⵽���˵Ĺ�������Ե���Щ�ưܡ��������Ϸ�����ǿǿ�����ϳ������š��������֣���ǽ�����ż���ͨ����ʾ(gaoshi)��    �������ﷸ��������ıؾ�֮�أ��ٱ��ǽ䱸ɭ�ϣ��������ͽ�ס�������ʡ�һ����ֱ����ʯ���������������졣�����ǽ��⣬����ġ����εġ���·�ģ����˴Ҵҡ������ǳ��������һƬ���֡�");

/********************************************************
        set("outdoors", "city");
//	
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));

	set("exits", ([
		"east"  : __DIR__"xidajie2",
		"west"  : __DIR__"ximenroad",
		"north" : "/d/taohuacun/taohua1",
	]));
        set("objects", ([
                __DIR__"npc/wujiang" : 1,
                __DIR__"npc/bing" : 2,
                "/d/mingjiao/npc/fenggongying" : 1,
        ]));
********************************************************/
 
};


ROOM_END;
