//jingyuan.h

//Sample for room: 黄河靖远
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_jingyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄河靖远");
	
	add_npc("pub_punk");    // add by zdn 2001-07-14



	add_door("黄河红山峡", "黄河红山峡", "黄河靖远");
	add_door("黄河沙漠1", "黄河沙漠1", "黄河靖远");

	set("long","靖远是个不大不小的城镇，黄沙在离城四十里的地方被一排排的钻天白杨树给挡住了。因此这里有了一块较大的绿洲，聚集了不少从别处来的移民。这些白杨据说是当年唐朝李靖赶走了突厥后在这里屯兵时所种。这也是靖远得名的由来。西边不远就是黄河，南面是一大片沙漠。");
	

/*****************************************************
	set("exits", ([
		"north"     : __DIR__"hongshanxia",
		"south"     : __DIR__"shamo",
	]));
********************************************/
};


CHANGAN_END;
