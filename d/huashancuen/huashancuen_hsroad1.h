//hsroad1.h

//Sample for room: ��ʯ���
//coded by zouwenbin
//data: 2000-11-18

RESIDENT_BEGIN(CRHuaShanCuen_hsroad1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ʯ���");
	
	set("resident", "��ɽ��");

	add_npc("pub_daoke");
	add_npc("pub_playboy");     //add by zdn 2001-07-14


	add_door("��ɽ��", "��ɽ��", "��ɽ����ʯ���");
	add_door("��ľ�����Ŷɿ�", "��ľ�����Ŷɿ�", "��ɽ����ʯ���");
	add_door("������ٵ�2", "������ٵ�2", "��ɽ����ʯ���");

  	set("long","����һ�����ͨ����ש�߷����������С��������������һָ�ġ���լ���ˡ�������ǰ��������İ���ܼ򵥣��������������ܲ��ԣ������м���Ǯ����Ҳ���᲻�û��������Ǹ�С��ͨ�����ҡ�" );
    

/*****************************************************
        set("exits", ([ 
            "west" :__DIR__"sroad4",
            "east" :__DIR__"bighouse2",
        ]));
*****************************************************/
};


RESIDENT_END;
