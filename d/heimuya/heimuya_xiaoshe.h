//xiaoshe.h

//Sample for room: С��
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_xiaoshe);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "С��");
	
	add_npc("pub_lady3");       // add by zdn 2001-07-14


	add_door("��ľ��С��԰", "��ľ��С��԰", "��ľ��С��");
	add_door("��ľ��С������", "��ľ��С������", "��ľ��С��");

	set("long", "����һ���ô����ɵ�С�ᡣһ���ţ����ŵ�һ��Ũ�ҵĻ��㣬���й���һ����Ůͼ�����������廨���棬������һ���ţ���������һ��ĵ���Ľ����������ѵ�����˭�ҹ���Ĺ뷿��");
    

/*****************************************************
        set("exits", ([
            "east" : __DIR__"neishi",
            "out" :__DIR__"xiaohuayuan",
        ]));
********************************************/
};


ROOM_END;
