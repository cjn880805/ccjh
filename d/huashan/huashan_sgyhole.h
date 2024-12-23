//sgyhole.h

//Sample for room: ��ɽɽ��
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRHuaShan_sgyhole);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽɽ��");

	add_npc("huashan_linghu");	

	add_door("��ɽ˼����", "��ɽ˼����", "��ɽɽ��");
	add_door("��ɽ����ջ��", "��ɽ����ջ��", "��ɽɽ��");

	set("long", "ɽ�����п������Ĵ�ʯ����֪�����ж��ٻ�ɽ�ɵ�ǰ���ڴ�˼����ڣ���������ʯ�������û��ʯ��(wall)�����š�������������֣������������̣��ʻ��Ծ������а�硣�����̵ֿþ����Ƿ�����������书һ��ʮ���˵á�");  

/*****************************************************
        set("objects", ([
//         CLASS_D("huashan")+"/linghu" : 1,
            "/d/heimuya/npc/linghu" : 1,
//         __DIR__"npc/ling-huchong.c" : 1,
        ]));
        set("exits", ([  
            "out" : __DIR__"siguoya",
        ]));
        set("item_desc", ([
            "wall" : "һ��ܺ��ʯ�ڡ�\n"
        ]) );
********************************************/
};


ROOM_END;
