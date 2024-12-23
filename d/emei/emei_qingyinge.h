//qingyinge.h

//Sample for room:  峨嵋清音阁
//coded by zouwenbin
//data: 2000-11-30

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CREMei_qingyinge);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "峨嵋清音阁");

	add_npc("pub_girldizi");
	add_npc("emei_xian");
				
	add_door("峨嵋中峰寺", "峨嵋中峰寺", "峨嵋清音阁");
	add_door("峨嵋白龙洞", "峨嵋白龙洞", "峨嵋清音阁");
	add_door("峨嵋黑龙江栈道", "峨嵋黑龙江栈道", "峨嵋清音阁");

	set("long","这里是峨嵋山的清音阁。此阁位于牛心岭下，东有白龙江，西有黑龙江，两江之水交汇于清音阁下。江上有拱桥两座，分夸黑龙白龙二江，这就是双飞桥。两江合流处，有一数米高的黑褐色巨石傲然挺立，形似牛心，名之为「牛心石」。桥边立有一石碑(shibei)。由此向西上，左行是黑龙江栈道，右路至白龙洞，东去中峰寺。");

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
