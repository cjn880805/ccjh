//damen.h

//Sample for room: 白驼山大门
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_damen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "白驼山大门");

	//add npcs into the room
	add_npc("pub_menwei1");
	
	add_door("白驼山石阶", "白驼山石阶", "白驼山大门");
	add_door("白驼山院子", "白驼山院子", "白驼山大门");

	set("long", "这就是闻名天下的『白驼山庄』的大门。大门梁上雕龙刻凤，美奂美仑，不知凝聚着多少能工巧匠的心血。更显出庄主的富有与显贵。门前左右各蹲着一只威武庄严的石狮子。(door)关闭着。北边是『白驼山庄』的大厅。南边就是大门了。.第子们在里边砌磋武艺，绝对不允许外人打搅。");

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
