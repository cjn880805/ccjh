//pukeroom.h

//Sample for room: 长安拱猪房
//coded by Fisho
//data: 2000-11-3

CHANGAN_BEGIN(CRChangAn_pukeroom);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "长安拱猪房");

	add_npc("pub_lady3");

	add_door("长安乐府诗社", "长安乐府诗社", "长安拱猪房");

	set("long", "屋中间摆着一张看起来相当结实的大方桌(table)，桌边围着四把靠背木椅。东面墙上有一块大牌子(paizi)，西面墙上有一块小牌子(score)。  " );
	set("no_fight",  1);
	set("no_magic",  1);

/*****************************************************
	set("item_desc",  (["paizi"  :  "

拱猪规则：

主要指令有：
一，就坐(sit  <n,  s,  e,  w>)。
二，开拱(start)。
三，出牌(play  <花色>  <大小>)。
　　花色有(hei,  hong,  cao,  fang)或用(S/s,  H/h,  C/c,  D/d)来代表。
　　大小有(1,  ...,  13)或用(A/a,  J/j,  Q/q,  K/k)来代表(1,  11,  12,  13)。
四，好牌亮相(double  <zhu/z,  yang/y,  hong/h,  bian/b>)。
五，查自己的牌(my)。
六，看桌面情况(look  table)。
七，看积分(look  score)。
八，退出拱猪(leave)。

注意事项：
一，要端正牌风，系统不揭发舞弊。
二，每一盘必须在半小时内完成，否则取消重来。
二，有任何bug请报告巫师。目前是测试阶段，可能还有不少错。

		\n"  ]));
	//for  look  something.

	set("exits",  
	([  //sizeof()  ==  4
		//"south"  :  __DIR__"xiaomuwu",
		//"north"  :  __DIR__"chufang",
		//"west"  :  __DIR__"duchang2",
		"west"  :  __DIR__"clubpoem",
		//"up"  :  __DIR__"***",
		//"down"  :  __DIR__"***",
	]));
	
	set("objects",  
	([  //sizeof()  ==  1
		//__DIR__"npc/gongsun"  :  1,
	]));
	//set("outdoors",  "city");
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

CHANGAN_END;
