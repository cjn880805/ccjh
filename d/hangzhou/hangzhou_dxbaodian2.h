//dxbaodian2.h

//Sample for room: 杭州大雄宝殿2
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_dxbaodian2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州大雄宝殿2");
	
	add_npc("pub_lady3");           // add by zdn 2001-07-14

	add_door("杭州大雄宝殿1", "杭州大雄宝殿1", "杭州大雄宝殿2");

	set("long","殿内正中一尊如来佛像，两旁塑有二十尊诸天的佛像，大殿後壁有五十三参海岛像，岛上有姿态各异的大小佛像一百五十个。" );

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
