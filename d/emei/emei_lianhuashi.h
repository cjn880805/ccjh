//lianhuashi.h

//Sample for room:  峨嵋莲花石
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_lianhuashi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "峨嵋莲花石");

	add_npc("emei_su");		
	add_npc("emei_ling");		

	add_door("峨嵋华严顶", "峨嵋华严顶", "峨嵋莲花石");
	add_door("峨嵋九老洞口", "峨嵋九老洞口", "峨嵋莲花石");
	add_door("峨嵋钻天坡1", "峨嵋钻天坡1", "峨嵋莲花石");

	set("long","这是莲花石。此处岩石纹理纵横，形似莲花，颜如芙蓉，仿佛萼瓣层叠，细蕊欲绽。上有一庵，叫「莲花社」。由此往西上直达洗象池，东下左通华严顶，右通九老洞。");

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
