//zahuopu.h

//Sample for room: 杂货铺
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRBeiJing_zahuopu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杂货铺");

	//add npcs into the room
	add_npc("pub_zeng");
	add_door("北京西南", "北京西南", "北京杂货铺");

	set("long", "这是一家杂货铺，大箱小箱堆满了一地，都是一些日常用品。胡掌柜懒洋洋地躺在一只躺椅上，招呼着过往行人。据说私底下他也卖一些贵重的东西。摊上立着一块招牌(zhaopai)。" );
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
