//square.h
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRMingJiao_square);

virtual void create()			//Call it when Room Create
{

	//set name of our room

	set_name( "���̹㳡");
	
	add_npc("mingjiao_shuobude");
	add_npc("mingjiao_zhangzhong");
	add_npc("mingjiao_pengyingyu");
	add_npc("mingjiao_zhoudian");
	add_npc("pub_xiangke");

	add_door("������΢��", "������΢��", "���̹㳡");
	add_door("���̷���", "���̷���", "���̹㳡");
	add_door("��������", "��������", "���̹㳡");
	add_door("���̴��", "���̴��", "���̹㳡");

	set("long", "���߽��������ܶ�㳡��ȴ���������������У���ɢ��Ⱥ���ڴˣ�������Ҫ�·����ˡ��������ڴҴ�ææ���㳡�����ǽ��ڷ��ã����׾��ǽ�����֮��ɫ�����á������߾��ǹ����������ܶ��ˡ�");
    
	set("valid_startroom", 1);
/*****************************************************
        set("exits", ([
                "west"    : __DIR__"fangtang",
                "northup" : __DIR__"qiandian",
                "east"    : __DIR__"xingtang",
                "south"   : __DIR__"tianweitang",
        ]));
        set("objects",([
             __DIR__"npc/shuobude":1,
             __DIR__"npc/zhangzhong":1,
             __DIR__"npc/pengyingyu":1,
             __DIR__"npc/zhoudian":1,
        ]));
        
        set("outdoors", "mingjiao");
********************************************/

};
/*
int valid_leave(object me, string dir)
{
        mapping mypar;
        me = this_player();
        mypar=(mapping)me->query("party");
        if ((!mypar || mypar["party_name"]!=HIG "����" NOR) &&
            (dir!="south") &&
            ((objectp(present("peng yinyu", environment(me)))) ||
             (objectp(present("zhang zhong", environment(me)))) ||
             (objectp(present("shuo bude", environment(me)))) ||
             (objectp(present("zhou dian", environment(me))))))
         return notify_fail("������ɢ����ס��˵���˴��������صأ���ֹ����\n");
        return ::valid_leave(me, dir);
}*/



ROOM_END;




