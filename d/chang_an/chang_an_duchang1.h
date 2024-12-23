//duchang1.h

//Sample for room: 长安押签房
//coded by Fisho
//data: 2000-11-3

CHANGAN_BEGIN(CRChangAn_duchang1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "长安押签房");

	add_npc("pub_punk");  //2001-07-2-12  zdn add
	add_npc("pub_punk"); 
	add_npc("pub_punk"); 
	add_npc("wei_zengrou");

	add_door("长安乐坊二楼大厅", "长安乐坊二楼大厅", "长安押签房");

	set("long", " 一群人围着紫檀木大桌而坐，首席座着一位精瘦的签客，正在一本正经地从镶金黑盒里慢悠悠一根一根往外抽出乾坤签，码在桌面上。墙上有一匾写着：        大乾签（全部五根皆为乾签）：一赢三十二        大坤签（全部五根皆为坤签）：一赢三十二        小乾签（连续四根皆为乾签）：一赢十六        小坤签（连续四根皆为坤签）：一赢十六          乾签（任意三根皆为乾签）：一赢二          坤签（任意三根皆为坤签）：一赢二       匾角有一个牌子(paizi)。 " );
	set("light_up",  1);
	set("no_fight",  1);
	set("no_beg",  1);

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

CHANGAN_END;
