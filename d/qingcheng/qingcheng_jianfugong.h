//jianfugong.h

//Sample for room: ����̽�����
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRQingCheng_jianfugong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����̽�����");
	
	add_npc("qingcheng_fang");     //add by zdn 2001-07-20


	add_door("���С��", "���С��", "����̽�����");
	add_door("�����ɽ���", "�����ɽ���", "����̽�����");
	add_npc("quanzhen_shen");
	add_npc("quanzhen_ji");	

/*****************************************************
	set("exits", ([
		"south"     : __DIR__"xiaoqiao",
		"northwest" : __DIR__"path1",
	]));
	set("objects", ([
		__DIR__"npc/ji" : 1,
		__DIR__"npc/shen" : 1,
	]));
*****************************************************/
};


ROOM_END;
