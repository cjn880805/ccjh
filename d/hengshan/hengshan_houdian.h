//houdian.h

//Sample for room: ��ɽ���
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_houdian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ���");


	add_door("��ɽ���", "��ɽ���", "��ɽ���");
	add_door("��ɽ������", "��ɽ������", "��ɽ���");

    set("long","�������������ĵڰ˽���Ҳ��������۵��޹���" );
    

/*****************************************************
        set("exits", ([  
           "south"  : __DIR__"dadian",
           "north"  : __DIR__"beimen",
        ]));
********************************************/
};


ROOM_END;
