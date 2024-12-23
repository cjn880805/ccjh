//yunu.h

//Sample for room: 华山玉女峰
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_yunu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "华山玉女峰");
	
	add_npc("huashan_laodenuo");       //add by zdn 2001-07-20


	add_door("华山镇岳宫", "华山镇岳宫", "华山玉女峰");
	add_door("华山玉女祠", "华山玉女祠", "华山玉女峰");
	add_door("华山练武场", "华山练武场", "华山玉女峰");
	add_door("华山小山路", "华山小山路", "华山玉女峰");
	add_door("华山玉女峰山路", "华山玉女峰山路", "华山玉女峰");

	set("long", "这里是华山的中峰，玉女峰。传说春秋时隐士萧史善吹洞箫，箫声引动了秦穆公女儿弄玉的爱慕，抛弃了宫廷生活，跟萧史来此隐居，故称玉女峰。这里地势略为平缓，不似其它四峰般险峻，江湖上赫赫有名的华山剑派就在此处。东边有所小小的庙宇，那就是玉女祠了。北面稀稀落落有十几间房子，是华山派的地方，闲杂游客最好别往那里去。");  
 
/*****************************************************
        set("exits", ([  
            "westdown"  : __DIR__"zhenyue",
            "west"      : __DIR__"yunuci",
            "north"     : __DIR__"square",
            "southdown" : __DIR__"yunupath1",
            "northeast" : __DIR__"xiaolu1",
       ]));
       set("objects", ([
            __DIR__"npc/yue-lingshan" : 1,
       ]));
********************************************/
};


ROOM_END;
