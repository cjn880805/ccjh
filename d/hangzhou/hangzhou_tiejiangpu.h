//tiejiangpu.h

//Sample for room: 铁匠铺
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRhangzhou_tiejiangpu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "铁匠铺");

	//add npcs into the room
	add_npc("bingqi_tianjianshi");

	add_door("杭州青石大道11", "杭州青石大道11", "杭州铁匠铺");

	set("long","这是一家不小的打铁铺，店里摆了几座火炉，一位铁匠正在火炉旁满头大汗地打造东西。一位老者坐在边上。火炉边放着不少打好了的铁器。" );

/*****************************************************
 ///    门口挂着一块牌子(paizi)。
        set("exits", ([ 
            "west" : __DIR__"road11",
        ]));
        set("item_desc", ([
            "cannotsawpaizi" :
"若要'铸剑'，请找欧冶师傅。\n"
"如果想在你的兵器上刻下带色的字，可以在宝剑名\n"
"前面加上$XXX$，在宝剑名后记得恢复为$COM$。\n"
"$BLK$ - 黑色            $COM$ - 恢复正常颜色\n"
"$RED$ - 红色            $HIR$ - 亮红色\n"
"$GRN$ - 绿色            $HIG$ - 亮绿色\n"
"$YEL$ - 土黄色          $HIY$ - 黄色\n"
"$BLU$ - 深蓝色          $HIB$ - 蓝色\n"
"$MAG$ - 浅紫色          $HIM$ - 粉红色\n"
"$CYN$ - 蓝绿色          $HIC$ - 天青色\n"
"$WHT$ - 浅灰色          $HIW$ - 白色\n",
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
