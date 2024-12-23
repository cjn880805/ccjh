//yaopu.h

//Sample for room: 药铺
//coded by zouwenbin
//data: 2000-11-15

ROOM_BEGIN(CRDali_yaopu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "药铺");
	
	add_npc("pub_hehongyao");
	add_npc("pub_huoji");


	add_door("大理城东", "大理城东", "大理城药铺");

	set("long", "这是一家神秘的药铺，座落在大和街和市中心的交界处，普通的门面和招牌，街坊们都说这家药铺的药灵验的很。从药柜上的几百个小抽屉里散发出来的一股浓浓的药味，让你几欲窒息。据说这家店铺有一种很神密的药物。" );

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
