//huiguan.h

//Sample for room: 英雄会馆
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRFoShan_huiguan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "英雄会馆");

	//add npcs into the room
	add_npc("pub_fengzaiming");
	
	add_door("佛山", "佛山", "佛山英雄会馆");

	set("long", "英雄会馆也是凤老爷的家业。来这里赌钱的，都是有能耐有来头的。赌场里围着黑压压的一群人，正在掷(gamble)骰子押大小。门边立着一个牌子(paizi)。" );
	set("no_fight", "1");
/*****************************************************
	set("objects", ([
	   __DIR__"npc/fengyiming": 1,
	]));
        set("item_desc", ([
                "paizi" :
"「大小」赌法：\n"
"共用三粒色子撒在一只碗里，色子点数总和：\n"
"       四 至 十 为「小」，\n"
"       十一 至 十七 为「大」，\n"
"       三粒色子点数相同，则大小通吃。\n"
"\n开大赔大，开小赔小，一赔一。\n"
"\n本赌场接受各种货币及功夫的点数为赌注。\n"
"\n赌注为五十到一千五百。\n",
        ]));
	set("exits",([ 
	    "north" : __DIR__"street2",
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
