//cangjingdian.h

//Sample for room: �ؾ���
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRHengShan_cangjingdian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ؾ���");


	add_door("��ɽɽ·14", "��ɽɽ·14", "��ɽ�ؾ���");
	add_door("��ɽ��ױ̨", "��ɽ��ױ̨", "��ɽ�ؾ���");

    set("long"," �ؾ������������£������̫������ '��ؾ�' �����������ľ���죬����Ʈ���滨��ݣ����������ɫ������ '�ؾ���֮��' �Ǻ�ɽ���ľ�֮һ��" );
    

/*****************************************************
        set("exits", ([ 
           "east"   : __DIR__"shanlu14",
           "south"  : __DIR__"shuzhuangtai",
        ]));
********************************************/
};


ROOM_END;
