//heilong1.h

//Sample for room:  峨嵋黑龙江栈道
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_heilong1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "峨嵋黑龙江栈道");

	add_npc("pub_youke");
        add_npc("pub_daoke");   // add by zdn 2001-07-13
				
	add_door("峨嵋清音阁", "峨嵋清音阁", "峨嵋黑龙江栈道");
	add_door("峨嵋千佛庵", "峨嵋千佛庵", "峨嵋黑龙江栈道");

	set("long","黑龙江栈道沿黑龙江而建。这里一山中开，两崖并立，形成一道宽仅数尺，长达几百米的深峡——白云峡。黑龙江栈道就从狭窄的白云峡中转折穿过，架设在绝壁上。走在栈道上，只觉道窄人危；俯视深涧，急流飞旋，山静而觉动；仰观头顶，天光如隙，崖开而欲合。这就是天开画图的「一线天」。栈道南通千佛庵，北至清音阁。(shibei)。由此向西上，左行是黑龙江栈道，右路至白龙洞，东去中峰寺。");
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
