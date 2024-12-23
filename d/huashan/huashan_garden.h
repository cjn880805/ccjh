//garden.h

//Sample for room: 华山花园
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_garden);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "华山花园");
	
	add_npc("huashan_yuelingshan");       //add by zdn 2001-07-20
	add_npc("helpnpc012");

	add_door("华山有所不为轩", "华山有所不为轩", "华山花园");
	add_door("华山书房", "华山书房", "华山花园");
	add_door("华山厨房", "华山厨房", "华山花园");
	add_door("华山后院", "华山后院", "华山花园");
	add_door("华山长廊", "华山长廊", "华山花园");

	set("long", "这是一个园子，庭院清幽，异种花卉甚是不少。百花争放，山石古拙，杨柳垂清，苍松翠竹，景致煞是宜人。清澈的溪流旁耸立着一座小亭子，潺潺溪水向西南流去。东面通往有所不为轩，北面是一条长廊，西边小屋传出阵阵香味，引得你真想去看看。");  
    
 
/*****************************************************
	set("exits",([
		"east"      : __DIR__"buwei1",
		"west"      : __DIR__"chufang",
		"north"     : __DIR__"changlang",
		"south"     : __DIR__"shufang",
		"southwest" : __DIR__"houyuan",
	]));
********************************************/
};


ROOM_END;
