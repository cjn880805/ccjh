//shanjian.h

//Sample for room: ��ɽɽ��
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_shanjian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽɽ��");


	add_door("��ɽ������", "��ɽ������", "��ɽɽ��");
	add_door("��ɽ��ɳ̶", "��ɽ��ɳ̶", "��ɽɽ��");

    set("long","˳ɽ��Ư�����£���Ϫ�鲼��ϡ��ľ��Ȫʯ����ľ�����ݼ����;������ˡ����������۵���й���£�����ɽ�ȡ�" );
    

/*****************************************************
        set("exits", ([ 
           "down"     : __DIR__"heishatan",
           "northup"  : __DIR__"fangguangsi",
        ]));
********************************************/
};


ROOM_END;
