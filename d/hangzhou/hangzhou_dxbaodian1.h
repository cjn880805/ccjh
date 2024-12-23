//dxbaodian1.h

//Sample for room: 杭州大雄宝殿1
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_dxbaodian1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州大雄宝殿1");


	add_door("杭州天王殿", "杭州天王殿", "杭州大雄宝殿1");
	add_door("杭州大雄宝殿2", "杭州大雄宝殿2", "杭州大雄宝殿1");

	set("long","天王殿後是另一座高达三十几米的大殿。匾上写着“大雄宝殿”。殿前有两座八角九层石塔。往南又进了天王殿。" );

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
