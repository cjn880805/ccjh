//damen.h

//Sample for room: �һ�ɽׯ����
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRTaoHua_damen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�һ�ɽׯ����");
	
	add_npc("pub_shiwei");        //add by zdn 2001-07-16
	add_npc("pub_xiangke");


	add_door("�һ���", "�һ���", "�һ�ɽׯ����");
	add_door("�һ���ɽׯ����", "�һ���ɽׯ����", "�һ�ɽׯ����");

	set("long", "�������һ�ɽׯ�����š���ǰ�������µ����˼����һ��������Եô˵����˶��һ���ƫ�����ſ�վ������Сͯ���ش��š��������ڵش���Զ�����̺��������Ƕ�ɽׯ�ķ��������ر��������ǰ��һ�԰׵�(diao)��");
	set("valid_startroom", 1);
	set("no_beg", "1");

/*****************************************************
	set("exits", ([
		"south" : __DIR__"qianyuan",
		"north" : __DIR__"tingzi",
		"east"  : __DIR__"road1" ,       
	]));
	set("item_desc", ([
		"diao" : "һ�԰׵���չ�����ɡ�������һ����ĵ��ӣ�\n"
		"����(ride)�Ϳ��Էɵ���ԭ��\n",
	]));
        set("objects", ([
                __DIR__"npc/shitong" : 2,
        ]));
********************************************/
};


ROOM_END;




