//shufang.h

//Sample for room: �鷿
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRGueiYun_shufang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�鷿");

	//add npcs into the room
	add_npc("pub_shutong");        //add by zdn 2001-07-20
	
	add_door("����ׯ", "����ׯ", "����ׯ�鷿");

    set("long","����½ׯ�����鷿��������Ŀ��ȫ��ʫ��伮���������ϰ������ͭ���������������ǹ�����Ϲ���һ��ˮī���������Ǹ���������������֮ҹ��ͥ�������ְ����������쳤���������į�����Ͻ�����һ�ס��ʡ�(poem)�����������ббǶ��һ�������ԣ��������ͷ��䲻̫��ġ�" );

/*****************************************************
//      set("outdoors", "guiyun");
//	

	set("exits", ([
		"west"  : __DIR__"dating",
	]));
	set("item_desc", ([
		"poem"  :
"
��ҹ���˲�ס��������ǧ���Σ���������
���������ƽ��С������ģ�������������

����Ϊ��������ɽ�����ϣ����̡�
�������¸����٣�֪���٣��Ҷ���˭����

                ������˲���Ϳѻ
",
	]));
	set("objects", ([
		CLASS_D("taohua")+"/lu" : 1,
		__DIR__"npc/shutong" : 1,
	]));
********************************************/
};


ROOM_END;
