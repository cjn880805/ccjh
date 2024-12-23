//bridge.h

//Sample for room: 白驼山小桥
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_bridge);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "白驼山小桥");

	//add npcs into the room
	add_npc("pub_cungu");
	
	add_door("白驼山西街", "白驼山西街", "白驼山小桥");
	add_door("白驼山广场", "白驼山广场", "白驼山小桥");

	set("long", "这是一座小竹桥，『白驼山』上的冰雪融化形成一条清澈的小溪，从桥下缓缓流过。不时有顽皮的小鱼跃出水面，在阳光下划出一条银白色的弧线。");
	
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
