//jieyindian.h

//Sample for room:  峨嵋接引殿
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_jieyindian);

virtual void create()			//Call it when Room Create
{
	set_name( "峨嵋接引殿");

	add_npc("emei_hui");
	add_npc("emei_wenyin");

	add_door("峨嵋八十四盘3", "峨嵋八十四盘3", "峨嵋接引殿");
	add_door("峨嵋万行庵", "峨嵋万行庵", "峨嵋接引殿");

	set("long","接引殿右边濒崖，是金钢嘴。崖下有一块巨石，形状似钟，故名「钟石」。对面有一石，高耸十余丈，叫「仙人石」。由此向上仰攀即到万行庵，北下经「八十四盘」至洗象池。");

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
