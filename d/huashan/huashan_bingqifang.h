//bingqifang.h

//Sample for room: ������
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRHuaShan_bingqifang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");

	CBox * box = Add_Box();
	box->add_object("changjian", 4);	
	box->set_name( "ľ��");	

	add_door("��ɽ���䳡", "��ɽ���䳡", "��ɽ������");

	set("long", "�����ǻ�ɽ�ɵı����������ܷ��⼸�������ܣ������ǻ�ɽ�ɸ�����ƽʱ�����õ��񽣡�");  
    set("no_fight", 1);

/*****************************************************
        set("exits", ([
                "west" : __DIR__"square",
        ]));
        set("objects", ([ 
            "/clone/weapon/zhujian" : 4
        ]));
//      
********************************************/
};


ROOM_END;
