//stoneshop.h

//Sample for room: 石铺
//coded by zouwenbin
//data: 2000-11-15

ROOM_BEGIN(CRDali_stoneshop);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "石铺");

	//add npcs into the room
	add_npc("pub_shijiang");
	
	add_door("大理城东", "大理城东", "大理城石铺");

	set("long", "大理地段有一山石以其天然的花纹而闻名天下，那便是大名鼎鼎的大理石。用大理石中的水墨花石制作的画屏，其奇妙程度，使人叹而观止。唐宋时代，许多官商将儒都好以大理石作家居摆设。石铺里人头济济，敲打钻磨之声不绝于耳。一个白族老头光着膀子，来回踱着小步，指导着新伙计。" );

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
