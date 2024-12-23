//qingxinquan.h

//Sample for room: 灵州清新泉
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_qingxinquan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "灵州清新泉");
	
	add_npc("pub_xiaowei");            //add by zdn 200-07-14

	add_door("灵州林中空地", "灵州林中空地", "灵州清新泉");
//	add_door("灵州西夏王陵", "灵州西夏王陵", "灵州清新泉");

	set("long", "这是山中的一口清泉，位于林场北面的山坡上，周围是翠绿的松树，潺潺的山泉水从泉眼缓缓的涌出，聚成一个小潭，小潭水又溢出流向山，旁边一条小路通向山下。");  
	
	set("resource/water", 1);

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
