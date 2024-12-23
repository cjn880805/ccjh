//shenshuian.h

//Sample for room:  峨嵋神水庵
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_shenshuian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "峨嵋神水庵");
	
	add_npc("emei_yanziyi");        //add by zdn 2001-07-20


	CBox * box = Add_Box();
	box->add_object("coin", 60000);	//put 100 coind into box

	box->set_name( "终焉之印");		//set box's name
	box->set("id","enchantment");
	box->Locked("结界", 18000);

				
	add_door("峨嵋纯阳殿", "峨嵋纯阳殿", "峨嵋神水庵");
	add_door("峨嵋福寿庵", "峨嵋福寿庵", "峨嵋神水庵");
	add_door("峨嵋中峰寺", "峨嵋中峰寺", "峨嵋神水庵");

	set("long","神水庵位于宝掌峰下，庵前有大峨石和玉液泉，泉出石下，清澈无比，终年不涸。一株大海棠树，已是数百苍龄，抱可数围，高达十余丈。旁边有福寿庵；由此西上中峰寺，东下纯阳殿。");

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
