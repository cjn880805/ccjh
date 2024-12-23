//tiejiangpu.h

//Sample for room: ������
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRhangzhou_tiejiangpu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");

	//add npcs into the room
	add_npc("bingqi_tianjianshi");

	add_door("������ʯ���11", "������ʯ���11", "����������");

	set("long","����һ�Ҳ�С�Ĵ����̣�������˼�����¯��һλ�������ڻ�¯����ͷ�󺹵ش��춫����һλ�������ڱ��ϡ���¯�߷��Ų��ٴ���˵�������" );

/*****************************************************
 ///    �ſڹ���һ������(paizi)��
        set("exits", ([ 
            "west" : __DIR__"road11",
        ]));
        set("item_desc", ([
            "cannotsawpaizi" :
"��Ҫ'����'������ŷұʦ����\n"
"���������ı����Ͽ��´�ɫ���֣������ڱ�����\n"
"ǰ�����$XXX$���ڱ�������ǵûָ�Ϊ$COM$��\n"
"$BLK$ - ��ɫ            $COM$ - �ָ�������ɫ\n"
"$RED$ - ��ɫ            $HIR$ - ����ɫ\n"
"$GRN$ - ��ɫ            $HIG$ - ����ɫ\n"
"$YEL$ - ����ɫ          $HIY$ - ��ɫ\n"
"$BLU$ - ����ɫ          $HIB$ - ��ɫ\n"
"$MAG$ - ǳ��ɫ          $HIM$ - �ۺ�ɫ\n"
"$CYN$ - ����ɫ          $HIC$ - ����ɫ\n"
"$WHT$ - ǳ��ɫ          $HIW$ - ��ɫ\n",
        ]));
        set("objects", ([
//            __DIR__"npc/ouyezi" : 1,
            __DIR__"npc/smith" : 1,
        ]));
//        
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
