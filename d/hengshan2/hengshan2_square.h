//huixiantai.h

//Sample for room: ��ɽ���Է�㳡
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan2_huixiantai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ���Է�㳡");

	//add npcs into the room
	add_npc("pub_qingbing");

	add_door("��ɽ���Է�ɽ��2", "��ɽ���Է�ɽ��2", "��ɽ���Է�㳡");
	add_door("��ɽ������", "��ɽ������", "��ɽ���Է�㳡");

    set("long","�����Ǻ�ɽ������Է�嶥�Ĺ㳡�������︩�Ⱥɽ�������ú��Ժ�ɽ�ǻ��ı�����ɽ֮�ڣ�����Ҳ�����𽭺��ĺ�ɽ�ɵĸ����صء� " );

/*****************************************************
        set("exits", ([ 
           "westdown"  : __DIR__"shandao2",
           "north"     : __DIR__"baiyunan",
        ]));
	set("objects", ([
		__DIR__"npc/yi" : 1,
		__DIR__"npc/qing" : 1,
	]));
********************************************/
};


ROOM_END;
