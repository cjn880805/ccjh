//shiziyan.h

//Sample for room: ��ɽʨ����
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_shiziyan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽʨ����");


	add_door("��ɽ������", "��ɽ������", "��ɽʨ����");
	add_door("��ɽ����̨", "��ɽ����̨", "��ɽʨ����");

    set("long","  ʨ���Ҳ������ι�״����ʯ��ϸ�������ʨ�ӣ���Ծ���𣬸�Ф���ࡣ��ʨ���ң�ף�ڷ��Ѿ������ˡ�" );
    

/*****************************************************
        set("exits", ([ 
           "southwest"  : __DIR__"nantian",
           "northup"    : __DIR__"wangritai",
        ]));
********************************************/
};


ROOM_END;
