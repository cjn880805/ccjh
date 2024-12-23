//gulang.h
//Sample for room: 黄河古浪
//coded by zouwenbin
//data: 2000-11-18

CHANGAN_BEGIN(CRHuangHe_gulang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄河古浪");
	//add npcs into the room
	add_npc("pub_daoke");
	add_npc("pub_boy");
	add_npc("pub_girl");
	add_npc("pub_girl1");
	if (random(2)==0)
	{
	add_npc("pub_boy");
		add_npc("pub_girl");
		add_npc("pub_girl1");
	}
	add_door("黄河学馆", "黄河学馆", "黄河古浪");
	add_door("黄河沙土路", "黄河沙土路", "黄河古浪");
	add_door("黄河萧家桥", "黄河萧家桥", "黄河古浪");
	add_door("黄河打柴沟", "黄河打柴沟", "黄河古浪");
	add_door("黄河皮货药材店", "黄河皮货药材店", "黄河古浪");
	set("long","古浪城建于西周，本名鬼武，后整修于汉，更名古浪。古浪是西北地区的毛皮集散地，当初的紫羊羔皮袄，一出于张家口，另一出处就是古浪了，过了古浪再往西四十里，跨过纪水河即到兰州。");

};

CHANGAN_END;
