//zhurongfeng.h

//Sample for room: ��ɽף�ڷ�
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_zhurongfeng);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽף�ڷ�");
	
	add_npc("pub_jianke");      // add by zdn 2001-07-14


	add_door("��ɽף�ڵ�", "��ɽף�ڵ�", "��ɽף�ڷ�");

    set("long"," 'ף�ڷ�֮��' Ϊ��ɽ���ľ�֮�ס��ڴ˸��Ⱥ�壬�����۵ס������潭���ϼ����룬���ͥ������ѩɽ���Ÿ�����ʫ���� 'ף������𣬷��εͰ�.' �������� 'ף�����ɰε�����������������' ������ߡ�" );
    

/*****************************************************
        set("exits", ([ 
           "eastdown"   : __DIR__"zhurongdian",
        ]));
********************************************/
};


ROOM_END;
