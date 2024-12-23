//liufudayuan.h

//Sample for room: 刘府大院
//coded by Fisho
//data: 2000-11-4

ROOM_BEGIN(CRHengYang_liufudayuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "刘府大院");

	//add npcs into the room
	add_npc("hengshan1_liuhong");
	add_npc("hengshan1_wuweiyi");
	add_npc("hengshan1_xiangguonian");
        add_npc("hengshan1_luduku");
        add_npc("hengshan1_liucao");
        add_npc("pub_liufuren");
	add_door("衡阳城", "衡阳城", "衡阳刘府大院");

/*****************************************************
	set("long", " 刘府大院里现在挤着很多江湖豪客，原来今天是刘正风金盆洗手的
好日子。刘老爷子在衡阳人缘很好，来捧场的自然不少，大院里已摆了
很多张桌子，杯筷往来，很是热闹。
" );
         set("exits", ([
            "north"  : __DIR__"liufudating",
            "out"    : __DIR__"liufugate",
        ]));
        set("objects", ([
                "/d/taishan/npc/dao-ke" : 1,
                "/d/taishan/npc/jian-ke" : 1,
                "/d/huashan/npc/haoke" : 1,
        ]));

********************************************/
};


ROOM_END;
