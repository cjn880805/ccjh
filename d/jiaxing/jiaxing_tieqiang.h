//tieqiang.h

//Sample for room: ��ǹ��
//coded by Fisho
//data: 2000-11-4

ROOM_BEGIN(CRJiaXing_tieqiang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ǹ��");


	add_npc("pub_fanghenxiao");

	add_door("���˳�", "���˳�", "������ǹ��");

	set("outdoors", "quanzhou");
/*****************************************************
	set("long", @LONG
����ǹ�����������ʱ������ǹ�����¡�������������������
Ⱥѻ����Ϊ������������˵��ǹ�����ѻ������񽫣�����������
��������������ֳ��Խ��Խ�ࡣ�������и�С��(dong)��
LONG );
	set("exits", ([
                "west" : __DIR__"jxnanmen",
		"north" : __DIR__"nanhu",
	]));
        set("item_desc", ([
	    "dong" : "һ���ڰ��������صúܺõ�������\n",
	]));
        set("objects", ([
		__DIR__"npc/wuya": 4
	]));
********************************************/
};


ROOM_END;




