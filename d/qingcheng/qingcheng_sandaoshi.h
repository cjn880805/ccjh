//sandaoshi.h

//Sample for room: �������ʯ
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRQingCheng_sandaoshi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�������ʯ");
	
	add_npc("pub_playboy");           //add by zdn 2001-07-14


	add_door("�����ʦ��", "�����ʦ��", "�������ʯ");
	add_door("�����Ȫͤ", "�����Ȫͤ", "�������ʯ");

	
    

/*****************************************************
        set("outdoors","qingcheng");
	set("exits", ([
		"west"     : __DIR__"tianshidong",
		"eastdown" : __DIR__"tingquanting",
	]));
*****************************************************/
};


ROOM_END;
