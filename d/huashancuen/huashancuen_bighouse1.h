//bighouse1.h

//Sample for room: ������ǰ��
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRHuaShanCuen_bighouse1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������ǰ��");
	
	add_npc("pub_boy");     //add by zdn 2001-07-14


	add_door("��ɽ��", "��ɽ��", "��ɽ�������ǰ��");
	add_door("����������", "��ɽ�����������", "��ɽ�������ǰ��");

  	set("long","����һ�����ͨ����ש�߷����������С��������������һָ�ġ���լ���ˡ�������ǰ��������İ���ܼ򵥣��������������ܲ��ԣ������м���Ǯ����Ҳ���᲻�û��������Ǹ�С��ͨ�����ҡ�" );
    

/*****************************************************
        set("exits", ([ 
            "west" :__DIR__"sroad4",
            "east" :__DIR__"bighouse2",
        ]));
*****************************************************/
};


ROOM_END;
