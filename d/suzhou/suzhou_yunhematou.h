//yunhematou.h

//Sample for room: �˺���ͷ
//coded by Fisho
//data: 2000-11-3

ROOM_BEGIN(CRSuZhou_yunhematou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�˺���ͷ");
	
	add_npc("pub_qiaofu");        //add by zdn 2001-07-16


	add_door("����", "����", "�����˺���ͷ");

	set("outdoors", "suzhou");
	
/*****************************************************
	set("exits", ([
		"southeast" : __DIR__"xidajie1",
	]));

********************************************/
};


ROOM_END;
