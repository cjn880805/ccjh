//wangritai.h

//Sample for room: ��ɽ����̨
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_wangritai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ����̨");


	add_door("��ɽʨ����", "��ɽʨ����", "��ɽ����̨");
	add_door("��ɽף�ڵ�", "��ɽף�ڵ�", "��ɽ����̨");

    set("long","  ����̨����ף�ڵ����ҹ�𣬵�̨������ң�����ţ���ˮ�Գ࣬ٿ����ʣ����ֵ�����������������֮��ӿ���𣬹�ҫ��Ŀ " );
    

/*****************************************************
        set("exits", ([ 
           "southdown"  : __DIR__"shiziyan",
           "northup"    : __DIR__"zhurongdian",
        ]));
********************************************/
};


ROOM_END;
