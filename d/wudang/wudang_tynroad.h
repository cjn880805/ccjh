//tynroad.h

//Sample for room: �䵱��԰С·
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_tynroad);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�䵱��԰С·");

	add_npc("wudang_shouyuan");

	add_door("�䵱", "�䵱", "�䵱��԰С·");
	add_door("�䵱", "�䵱", "�䵱��԰С·");

	set("long","��ǰ��Ȼ���ʣ������ɵ�������԰�ߵ�С·�ϡ�·����Ӣ�ͷף�һ���������֣�ʢ���ŷۺ���һ�������һƬ���������ߡ������Կ����۷䡸���ˡ����ڻ�����Ϸ���æ����ͣ�������Գ���ߴզ����������䵱ɽ�ţ�����������ɽ�Ļ���·��");
    

/*****************************************************
	set("outdoors", "wudang");
	set("exits", ([
		"south" : __DIR__"tyroad8",
	]));
	set("objects", ([
		__DIR__"npc/"+npcs[i] : 1
	]));
*****************************************************/
};


ROOM_END;
