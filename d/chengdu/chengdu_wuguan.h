//wuguan.h

//Sample for room: ��ţ���
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRChengDu_wuguan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ţ���");

	//add npcs into the room
	add_npc("wuguan_mawude");/////////////////////////
	add_npc("pub_zhangfang");
    add_npc("wuguan_chenhu");
	add_npc("wuguan_liuhongying");
	add_npc("wuguan_longquan");		
	add_npc("wuguan_xiaofei");

	add_door("�ɶ���", "�ɶ���", "�ɶ���ţ���");

	set("long",	"����ţ��ݡ��ڽ����к����������ܶ������С���Ǵ������߽���������Ȼ�����ڽ������ѳ������������ʦ�����Ҳ�����ˣ�ȴ�����ǵ�����ҵʦ������Ҳ����������ʦ���ǣ�������ﳤ�õõ��ڰ����������أ������ַ�����������ݴ�����"	);
	
	set("no_fight",1);
    set("no_steal",1);
    set("no_beg",1);

/*****************************************************
 	set("objects", ([
		__DIR__"npc/mawude" : 1,
		__DIR__"npc/zhangfang" : 1,
	]));
        
        set("item_desc", ([
            "tiezi" : @TEXT
��ţ��ݾ����ߣ���������еĻ����书ѧȫ����Ҫ�Ļ����书�ǣ�

�� �����ڹ�
�� �����Ṧ
�� �����м�
�� ����ȭ�ţ��ɻ���צ���������ַ��������Ʒ�������ָ������
             ��צ���Լ�����ȭ����ѡһ�֡�
�� �����������ɻ����������������������������������ȷ�����
             �������Լ�����������ѡһ�֡�

����������������������������������������������������������
����ţ��ݡ������ڻ����书
����������������������������������������������������������
���������Ṧ (dodge)            ��������ȭ�� (cuff)
���������ڹ� (force)            ������������ (blade)
���������м� (parry)            �������������� (stick)
��������צ�� (claw)             �������������� (club)
���������ַ� (hand)             �����������ȷ� (staff)
���������Ʒ� (strike)           �������������� (sword)
��������ָ�� (finger)           �������������� (throwing)
����������������������������������������������������������
ѧϰ������: xue ʦ���� �书����
TEXT
        ]) );
	set("exits", ([
		"southwest" : __DIR__"northroad3",
		"east"      : __DIR__"wuguanchen",
		"south"     : __DIR__"wuguanlong",
		"west"      : __DIR__"wuguanxiao",
		"north"     : __DIR__"wuguanliu",
		"up"        : __DIR__"practice",
	]));
	
********************************************/

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}


ROOM_END;
