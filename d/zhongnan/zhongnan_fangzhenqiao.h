//fangzhenqiao.h

//Sample for room: ����ɽ������
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_fangzhenqiao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ������");

	add_npc("pub_youke2");
	add_npc("pub_manxiangke");     //2001-07-10 zdn add

	add_door("����ɽʯ��7", "����ɽʯ��7", "����ɽ������");
	add_door("����ɽ���湬", "����ɽ���湬", "����ɽ������");

	set("long","���ʯ�ף���ǰ��һ��ʯͷ���ɵ�СС���š����������ϵ��������������������ɽ�Ʒǳ�����������һ�������±��������°���Ʈ�����治֪���ںξ���" );
    

/*****************************************************
        set("outdoors", "quanzhen");
        set("exits", ([
                "north" : __DIR__"yuzhengong",
                "southdown" : __DIR__"shijie7",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
