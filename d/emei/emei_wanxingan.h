//wanxingan.h

//Sample for room:  峨嵋万行庵
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_wanxingan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "峨嵋万行庵");

	add_npc("emei_jia");	

	add_door("峨嵋接引殿", "峨嵋接引殿", "峨嵋万行庵");
	add_door("峨嵋金顶", "峨嵋金顶", "峨嵋万行庵");

	set("long","太子坪万行庵是古智禅师创建的。庵外满山长满莎椤花，花数芭合成一朵，叶子包在花外，古人以其根坚难易而盛赞之，以喻洁身自好之高贵品质。由此向南上便至金顶，下至接引殿。");

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
