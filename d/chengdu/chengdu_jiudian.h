//jiudian.h

//Sample for room: 蜀都酒楼
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRChengDu_jiudian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "蜀都酒楼");

	//add npcs into the room
	add_npc("pub_tanghua");/////////////////////////
	add_npc("pub_xiaoer2");


	add_door("成都东", "成都东", "成都蜀都酒楼");

	set("long",	"这是一座有着三开间门面的大酒楼，虽说不上雕梁画栋，却也气派不凡。正首门梁上挂着一幅黑漆匾，上写着“蜀都酒楼”四个金漆大字。楼中桌洁椅净，座中客人衣饰豪奢，十九是富商大贾。这是一家百年老店，传到现在的这位掌柜已经是第四代，据说和提督大人有点不清楚，却也保佑了这间酒楼的日进斗金。东南角有一道方梯通往楼上雅座，往西南则可以出到东大街。"	);

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
