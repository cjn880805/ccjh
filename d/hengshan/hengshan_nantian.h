//nantian.h

//Sample for room: ��ɽ������
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_nantian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ������");


	add_door("��ɽɽ·13", "��ɽɽ·13", "��ɽ������");
	add_door("��ɽ����ƺ", "��ɽ����ƺ", "��ɽ������");
	add_door("��ɽ�Ǹ�̨", "��ɽ�Ǹ�̨", "��ɽ������");
	add_door("��ɽɽ·14", "��ɽɽ·14", "��ɽ������");
	add_door("��ɽʨ����", "��ɽʨ����", "��ɽ������");

    set("long","  ���������ţ�����������ɽ��һ��ף�ڷ塣�������ǻ����ҵ�ʯ�������������� '������' ���ֺ����Ҷ��ŵ�����ϣ��ֱ���� '����' �� 'ʩ��' �����(lian)��ª���Լ������Ѿá�" );
    

/*****************************************************
        set("exits", ([
            "northeast" : __DIR__"shiziyan",
            "southup"   : __DIR__"denggaotai",
            "eastup"    : __DIR__"liuyunping",
            "southwest" : __DIR__"shanlu13",
            "northwest" : __DIR__"shanlu14",
        ]));
        set("item_desc", ([
            "lian" :
"\n
        ��              ·
        ��              ��
        ͨ              ��
        ��              ��

        ��              ��
        ��              �
        ��              ��
        ��              ΢
        ��              ��
        ��              ��
        ��              ��\n\n",
        ]));
********************************************/
};


ROOM_END;
