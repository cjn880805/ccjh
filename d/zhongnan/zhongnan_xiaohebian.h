//xiaohebian.h

//Sample for room: ����ɽС�ӱ�
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_xiaohebian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽС�ӱ�");

	add_npc("pub_huanu");          //2001-07-10  zdn add
	add_npc("pub_youke");

	add_door("����ɽɽ��С��16", "����ɽɽ��С��16", "����ɽС�ӱ�");

	set("long","�˴�λ�����ɽ��һƫƧ����ֻ��Ũ���ѵأ����⸡������Χ���������ľ���ľ��ľ�֮������Զ����С����ɽ��(dong)��ӿ����Ȫˮ���γɣ����ȵ�ˮ���������������˳����������ͨ��ɽ����������ɽ���ɽ���С�." );

/*****************************************************
        set("item_desc", ([
                "dong" : "һ�����䡢�İ����ֲ���Сɽ����\n",
        ]));
        set("exits", ([
                "enter" : __DIR__"shandong",
                "north" : __DIR__"shanlu16",
        ]));
********************************************/
};

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
