//mantianxing.h

//Sample for room: 满天星
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRGuanWai_mantianxing);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "满天星");
	
	add_npc("pub_youke");  // add by zdn 2001-07-13

	set("monster_chance", 50);

	add_door("关外二门坎子", "关外二门坎子", "关外满天星");
	add_door("关外谷草垛", "关外谷草垛", "关外满天星");

    set("long","这里是一片开阔的平原，附近不但没有任何小山丘陵，就连一棵树也找不到。抬眼望去，地平线笔直的将蓝天与雪原分隔在两边。据说夜间因这里无物遮挡，可遍观满天星斗。进山的人们多在此祈求上苍的保佑。" );

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
