//biaoju.h

//Sample for room: 福威镖局
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRfuzhou_biaoju);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "福威镖局");

	add_npc("pub_biaotou");   // add by zdn 2001-07-13

	add_door("福州西", "福州西", "福州福威镖局");
	add_door("福州福威镖局正厅", "福州福威镖局正厅", "福州福威镖局");

    set("long", "朱漆大门上茶杯大小的铜钉闪闪发光，门顶匾额写着“福威镖局”四个金漆大字，下面横书“总号”两个小字。进门处两排长凳，分坐八名劲装汉子，个个腰板笔挺，显出一股英悍之气。" );

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




