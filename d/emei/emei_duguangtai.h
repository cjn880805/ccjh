//duguangtai.h

//Sample for room:  峨嵋睹光台
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_duguangtai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "峨嵋睹光台");

	add_npc("emei_bei");

	add_door("峨嵋卧云庵", "峨嵋卧云庵", "峨嵋睹光台");
	add_door("峨嵋华藏庵", "峨嵋华藏庵", "峨嵋睹光台");

	set("long","这里是看日出、云海、佛光、神灯之地。台下深崖万丈，陡彻无底，云遮雾掩。极目四望，数百里外的大小雪山皆历历在目。　　金顶云海，迷迷茫茫，笼罩四野，远接天际。云海轻荡时，你在金顶，脚踏白云，大有飘飘欲仙之感；当云涛迅猛涌来时，整个金顶都似在向前浮动，令人有乘舟欲风之意。");
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




