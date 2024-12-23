//lingyunti.h

//Sample for room:  峨嵋凌云梯
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_lingyunti);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "峨嵋凌云梯");

	add_npc("pub_girldizi");        //add by zdn 2001-07-14

	add_door("峨嵋洗象池", "峨嵋洗象池", "峨嵋凌云梯");
	add_door("峨嵋雷洞坪", "峨嵋雷洞坪", "峨嵋凌云梯");

	set("long","这是凌云梯，最早是一位叫阿婆多的外国和尚在此缚木架石，以渡行人，又叫「胡僧梯」。路边有梅子坡，可见满坡青梅如豆，于疏枝密叶中逗引行人，甚有「望梅止渴」之功用。此梯北通洗象池，南至雷洞坪。");

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
