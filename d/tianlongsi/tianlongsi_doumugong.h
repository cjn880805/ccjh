//doumugong.h

//Sample for room:  �����¶�ĸ��
//coded by zouwenbin
//data: 2000-11-30

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRTianLongSi_doumugong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����¶�ĸ��");


	add_npc("pub_guest");
				
	add_door("�������껨Ժ", "�������껨Ժ", "�����¶�ĸ��");
	add_door("�����¶��ʴ�ʿԺ", "�����¶��ʴ�ʿԺ", "�����¶�ĸ��");

    	

/******************************************************************************
        set("exits", ([
                "southwest" : __DIR__"doushuai",
		"north" : __DIR__"yuhuayuan",
	]));
	set("objects",([
                "/d/wudang/npc/guest" : 1,
        ]));
******************************************************************************/
};


ROOM_END;
