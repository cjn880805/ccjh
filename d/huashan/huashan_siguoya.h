//siguoya.h

//Sample for room: ˼����
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRHuaShan_siguoya);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "˼����");


	add_door("��ɽ��Ů��ɽ·", "��ɽ��Ů��ɽ·", "��ɽ˼����");
	add_door("��ɽɽ��", "��ɽɽ��", "��ɽ˼����");

	set("long", "���ǻ�ɽ��˼���¡�Σ�����и�ɽ�����ǻ�ɽ���������ӷ���������ܷ�֮�������Ϲ�ͺͺ�Ĵ�ݲ���������һ����ľ����Σ�����������ഫ����Ů�����ϵ�һ�����飬���껪ɽ�ɵ���ʦ�Դ�Σ��Ϊ�ͷ�����֮������Ҫ�Ǵ˴��޲���ľ���޳������ܷ��ĵ��������˼��֮ʱ������Ϊ�������ţ��������͡�");  
    

/*****************************************************
        set("exits", ([ 
                "northdown" : __DIR__"yunupath2",
                "enter"     : __DIR__"sgyhole1",
        ]));
        set("outdoors", "huashan" );
********************************************/
};


ROOM_END;
