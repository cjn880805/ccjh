//daziling.h

//Sample for room: ��ɽ������
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan2_daziling);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ������");


	add_door("��ɽ�Ƹ����", "��ɽ�Ƹ����", "��ɽ������");
	add_door("��ɽ�����", "��ɽ�����", "��ɽ������");

    set("long","�����������ɽ����֮·��ʯ�������� '����' ���֣��߿����ɣ������پ��������ۻ롣"   );
    

/*****************************************************
        set("exits", ([ 
           "west"      : __DIR__"yunge",
           "northeast" : __DIR__"hufengkou",
        ]));
********************************************/
};


ROOM_END;
