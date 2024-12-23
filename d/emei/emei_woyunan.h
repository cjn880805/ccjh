//woyunan.h

//Sample for room:  峨嵋卧云庵
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_woyunan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "峨嵋卧云庵");

	add_npc("emei_xuan");	

	add_door("峨嵋金顶", "峨嵋金顶", "峨嵋卧云庵");
	add_door("峨嵋睹光台", "峨嵋睹光台", "峨嵋卧云庵");
//	add_door("峨嵋华藏庵", "峨嵋华藏庵", "峨嵋卧云庵");

	set("long","卧云庵旁边有个井络泉，据说以前曾因饮水人多而干涸，众尼为之诵经，于是泉水复出。出了卧云庵便是睹光台，旁边是华藏庵。");

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
