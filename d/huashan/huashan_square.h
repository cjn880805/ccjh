//square.h

//Sample for room: ��ɽ���䳡
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_square);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ���䳡");
	
	add_npc("huashan_girldizi");       //add by zdn 2001-07-20


	add_door("��ɽ��Ů��", "��ɽ��Ů��", "��ɽ���䳡");
	add_door("��ɽ������С·1", "��ɽ������С·1", "��ɽ���䳡");
	add_door("��ɽɽ��С��", "��ɽɽ��С��", "��ɽ���䳡");
	add_door("��ɽ������", "��ɽ������", "��ɽ���䳡");
	add_door("��ɽȺ�ɹ�", "��ɽȺ�ɹ�", "��ɽ���䳡");

	set("long", "�����ǻ�ɽ�ɵ����䳡���������⼸��ľ�ˣ������Ǳ����⣬�����Ǹ�С�ꡣͨ������໪ɽ�ɵ����ڴ�ϰ�����������ߵķ������Ϲ���һ���ң����顸Ⱥ�ɹۡ����������ƺ�����С��ͨ��ɽ�ϡ�");  
 
/*****************************************************
        set("exits", ([  
            "northwest" : __DIR__"chaopath1",
            "south"     : __DIR__"yunu",
            "north"     : __DIR__"qunxianguan",
            "west"      : __DIR__"shop",
            "east"      : __DIR__"bingqifang",
        ]));
        set("objects", ([
            "/d/shaolin/npc/mu-ren" : 5,
        ]));
********************************************/
};


ROOM_END;
