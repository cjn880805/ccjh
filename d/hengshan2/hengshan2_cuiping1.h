//cuiping1.h

//Sample for room: ��ɽ����ɽ��1
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan2_cuiping1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ����ɽ��1");
	
	add_npc("guiyun_luzhengping");    //add by zdn 2001-07-20


	add_door("��ɽ������2", "��ɽ������2", "��ɽ����ɽ��1");
	add_door("��ɽ����ɽ��2", "��ɽ����ɽ��2", "��ɽ����ɽ��1");

    set("long","�����ڴ���ɽ���ϣ�ʯ�׶��ͣ�����Ŀǰ����ͷ��������ɽ���͵��֣���ľ������о��ס� " );
    

/*****************************************************
	set("exits", ([
		"westup"  : __DIR__"cuiping2",
		"down"    : __DIR__"cuipinggu2",
	]));
********************************************/
};


ROOM_END;
