//wuguan.h

//Sample for room: 扬州武馆
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRYangZhou_wuguan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "扬州武馆");

	
	add_door("扬州西南", "扬州西南", "扬州武馆");

	set("long", "扬州武馆是专为初出江湖的少年设立的。由于江湖叛师是十分为人不齿的，初出道的少年可以在此学习一些基本的防身武功，一来不会光阴虚度，二来也好为今后选定一个心慕的门派。    墙上贴着个贴子(tiezi)。" );
    set("no_fight",1);
	set("no_steal",1);
	set("no_beg",1);
	
/*****************************************************
        set("objects", ([
                __DIR__"npc/chen" : 1,
        ]));
        set("item_desc", ([
            "tiezi" : @TEXT
扬州武馆敬启者：不须把所有的基本武功学全。必要的基本武功是：

㈠ 基本内功
㈡ 基本轻功
㈢ 基本招架
㈣ 基本拳脚：由基本爪法、基本手法、基本掌法、基本指法、基
             本爪法以及基本拳法任选一种。
㈤ 基本兵器：由基本刀法、基本棍法、基本剑法、基本杖法、基
             本棒法以及基本暗器任选一种。

─────────────────────────────
「扬州武馆」所传授基本武功
─────────────────────────────
１）基本轻功 (dodge)            ８）  基本拳法 (cuff)
２）基本内功 (force)            ９）  基本刀法 (blade)
３）基本招架 (parry)            １０）基本棒法 (stick)
４）基本爪法 (claw)             １１）基本棍法 (club)
５）基本手法 (hand)             １２）基本杖法 (staff)
６）基本掌法 (strike)           １３）基本剑法 (sword)
７）基本指法 (finger)           １４）基本暗器 (throwing)
─────────────────────────────
学习命令是: xue 师傅名 武功技能
TEXT
        ]) );
        set("exits", ([
                "north"     : __DIR__"xidajie2",
        ]));
********************************************/
};


ROOM_END;
