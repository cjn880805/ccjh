//xiaohuayuan.h

//Sample for room: ��ľ��С��԰
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_xiaohuayuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ľ��С��԰");

    add_npc("zm_riyue");     

	add_door("��ľ�º���", "��ľ�º���", "��ľ��С��԰");
	add_door("��ľ��С��", "��ľ��С��", "��ľ��С��԰");

	set("long", "�ӻ谵�ĵص��г������㷢���Լ�����������һ�������µ�С��԰�У���÷�������ɴ�أ����õ��ľ߽��ģ�����ȥ��һ�侫��С�ᡣ ");
    

/*****************************************************
        set("exits", ([
            "south" : __DIR__"didao6",
            "enter" :__DIR__"xiaoshe",   
        ]));
        
********************************************/
};


ROOM_END;
