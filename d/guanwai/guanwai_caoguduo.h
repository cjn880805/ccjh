//caoguduo.h

//Sample for room: �Ȳݶ�
//coded by zouwenbin
//data: 2000-12-1

RESIDENT_BEGIN(CRGuanWai_caoguduo);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�Ȳݶ�");

	set("resident", "�׺�");
	
	add_npc("pub_nongfu2");      // add by zdn 2001-07-13

	set("monster_chance", 50);

	add_door("����������", "����������", "����Ȳݶ�");
	add_door("����׺�", "����׺�", "����Ȳݶ�");

	set("long","����һ�����İ��棬�����ǰ������һƬ�Ͱ������ꡣԶԶ��ȥ�����պ�ѳɵĹȲݶ⣬�������飬�������ж��ٸ���������Ƭ���������У��Ϳɽ��볤�״�ɽ�ˡ�����������һ�ƴ��̣������ƺ����ˡ�" );
    

/*****************************************************
	set("exits", ([
		"northwest" : __DIR__"mantianxing",
		"east"      : __DIR__"baihe",
	]));
********************************************/
};


RESIDENT_END;
