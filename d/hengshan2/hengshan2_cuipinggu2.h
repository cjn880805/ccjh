//cuipinggu2.h

//Sample for room: ��ɽ������2
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan2_cuipinggu2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ������2");


	add_door("��ɽ������1", "��ɽ������1", "��ɽ������2");
	add_door("��ɽ����ɽ��1", "��ɽ����ɽ��1", "��ɽ������2");

    set("long","����Ͽ�����ʯ�ڶ�ֱ�����±�����һ����������������ƾ��յĺ�ɽɽ���У�ȴ����ʮ���������ڴ���ɽ������������Σ�ң�������ȣ��������£���������¥�Կ���ȽȽ���䡣�Ǿ����������ˡ� " );
    

/*****************************************************
	set("exits", ([
		"up"         : __DIR__"cuiping1",
		"northwest"  : __DIR__"cuipinggu1",
	]));

********************************************/
};


ROOM_END;
