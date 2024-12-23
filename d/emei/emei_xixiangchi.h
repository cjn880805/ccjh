//xixiangchi.h

//Sample for room:  峨嵋洗象池
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_xixiangchi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "峨嵋凌云梯");

	add_npc("pub_whitelady");      // add by zdn 2001-07-14
	add_npc("emei_girldizi");        //add by zdn 2001-07-20

	add_door("峨嵋钻天坡2", "峨嵋钻天坡2", "峨嵋洗象池");
	add_door("峨嵋凌云梯", "峨嵋凌云梯", "峨嵋洗象池");

	set("long","洗象池原只是一亭，亭前有一个石砌的小池(pool)，池边不远就是危岩。洗象池寓于一片冷杉林中，有若白云深处的仙山琼阁。若是云收雾敛、碧空万里、月朗中天时，便觉万籁俱寂，清光无限，宛若身在天宫，彻体生凉。这正是著名的「象池池夜」。由此向南上攀，便至雷洞坪，东下至莲花石。");

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
