//ermenkan.h

//Sample for room: ���ſ���
//coded by zouwenbin
//data: 2000-12-1

RESIDENT_BEGIN(CRGuanWai_ermenkan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ſ���");

	set("resident", "����");
	
	add_npc("pub_daoke");           // add by zdn 2001-07-13

	set("monster_chance", 50);

	add_door("������ſ���", "������ſ���", "������ſ���");
	add_door("����������", "����������", "������ſ���");

	set("long","�����Ĳ�·���ѵ���ʧ��ԭ������ߣ�·����ϡ������һЩǳǳ����ӡ��������ǰ��Ĳο����µġ���ãã��ѩ�ط����ҫ�۵����⣬������ͷ���ۻ���ż���м�ֻѩ�÷ɳ۶�����ת�۾���Ӱ�����ˡ�" );
    

/*****************************************************
	set("exits", ([
		"east"       : __DIR__"mantianxing",
		"northwest"  : __DIR__"damenkan",
	]));
********************************************/
};


RESIDENT_END;
