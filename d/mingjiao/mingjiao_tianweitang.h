//tianweitang.h



//Sample for room: ��΢��

//coded by zouwenbin

//data: 2000-11-16



ROOM_BEGIN(CRMingJiao_tianweitang);



virtual void create()			//Call it when Room Create

{

	//set name of our room

	set_name( "������΢��");

	add_npc("mingjiao_yinyewang");
	add_npc("mingjiao_yinwufu");
	add_npc("mingjiao_yinwushou");
	add_npc("mingjiao_yinwulu");
	add_npc("mingjiao_litianyuan");

	add_door("�����һ������", "�����һ������", "������΢��");
	add_door("���̹㳡", "���̹㳡", "������΢��");



	set("long", "����������̵���΢�ã�������������Զ������Ұ�������ǰ�üӥ���Ķ��Ӻͽ������޼ɵľ˾ˡ����ڳ��������ݻ�����Ȼ�����������������ڽ��������������Ǹ�ִ���У��ƺ������ܶ����ʿ��");
	
	set("xin_count", 1);


/*****************************************************
        set("exits", ([
                "east"      : __DIR__"tianshitang",
                "west"      : __DIR__"ziweitang",
                "southdown" : __DIR__"zhandao2",
              "north"     : __DIR__"square",
        ]));
        set("objects",([
             __DIR__"npc/yinyewang":1,
             __DIR__"npc/yinwufu":1,
        ]));
********************************************/

};
/*
int valid_leave(CChar * player, string dir)
{

        if ((player->querystr("party/party_name")!="����") && (dir=="north") &&
            (objectp(present("yin yewang", environment(me)))))
        return notify_fail("��Ұ����ס��˵���˴��������صأ���ֹ����\n");
        return CRoom::valid_leave(me, dir);
}

*/

ROOM_END;
