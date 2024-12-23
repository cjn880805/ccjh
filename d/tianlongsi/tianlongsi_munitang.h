//munitang.h

//Sample for room:  ������Ĳ����
//coded by zouwenbin
//data: 2000-11-30

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRTianLongSi_munitang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������Ĳ����");

	add_npc("dali_kurong");
	add_npc("dali_bencan");
	add_npc("dali_benxiang");
	add_npc("dali_benguan");
	add_npc("dali_benchen");
	add_npc("dali_benyin");
	
	set_temp("about_yyz",1);			
	add_door("�����°���̨", "�����°���̨", "������Ĳ����");

	set("long","���Ǹ�ɮ�ǵľ���֮��������ȫ����ľ�Ƴɣ�����ľ����ľ�Ͼ���ȥƤ����Ȼ���ӣ���һ·������̻Ի͵ĵ��ý�Ȼ��ͬ������������з���������š���ɮ���⣬����һ�������泯���һ��������");
    	

/******************************************************************************
        set("exits", ([
		"north": __DIR__"banruotai",
	]));
	set("objects",([
                __DIR__"npc/benchen" : 1,
		__DIR__"npc/kurong" : 1,
		__DIR__"npc/benguan" : 1,
		__DIR__"npc/benxiang" : 1,
		__DIR__"npc/bencan" : 1,
        ]));
******************************************************************************/
};


ROOM_END;
