//lingxingmen.h

//Sample for room: ��ɽ������
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_lingxingmen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ������");


	add_door("��ɽ���Ǹ�", "��ɽ���Ǹ�", "��ɽ������");
	add_door("��ɽ����·", "��ɽ����·", "��ɽ������");

    set("long","��������������ĵ�һ���ţ��ɺ����񣬻���ʯ��͵�ʯ�Ʒ���������ɽ��ף����Ϣ֮�أ����̷�Ϊ����С���졣�ڴ�Զ����ɽ��ɽ����ɣ�����������յĴ��� " );
    

/*****************************************************
        set("exits", ([  
           "north"  : __DIR__"kuixingge",
           "south"  : __DIR__"hengyang",
        ]));
********************************************/
};


ROOM_END;
