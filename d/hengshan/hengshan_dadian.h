//dadian.h

//Sample for room: ��ɽ���
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_dadian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ���");


	add_door("��ɽ����¥", "��ɽ����¥", "��ɽ���");
	add_door("��ɽ���", "��ɽ���", "��ɽ���");

    set("long","�������������������׵�֮�á����ṹΪ����Ъɽ���������߲������������ʮ���ߣ������߼䣬��ʯ����ʮ��������������ʮ����֮������������ʥ�۱���ׯ�ϡ�������֮��Ϊ��ɽС�ľ�֮һ�� " );
    

/*****************************************************
        set("exits", ([  
           "south"  : __DIR__"yushulou",
           "north"  : __DIR__"houdian",
        ]));
********************************************/
};


ROOM_END;
