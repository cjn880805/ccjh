//zhuhezhuang.h

//Sample for room: ���פ��ׯ
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRQingCheng_zhuhezhuang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���פ��ׯ");
	
	add_npc("qingcheng_luo");       //add by zdn 2001-07-20


	add_door("�����Ȼͼ��", "�����Ȼͼ��", "���פ��ׯ");


/*****************************************************
	set("exits", ([
		"south"    : __DIR__"tianran",
	]));
*****************************************************/
};


ROOM_END;
