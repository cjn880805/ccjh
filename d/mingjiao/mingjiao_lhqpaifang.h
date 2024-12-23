//lhqpaifang.h
//Sample for room: 
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRMingJiao_lhqpaifang);

virtual void create()			//Call it when Room Create
{

	//set name of our room

	set_name( "明教烈火旗牌坊");

	add_npc("mingjiao_hu");

	add_door("明教悬天崖", "明教悬天崖", "明教烈火旗牌坊");
	add_door("明教烈火旗大厅", "明教烈火旗大厅", "明教烈火旗牌坊");
	add_door("明教青石大道4", "明教青石大道4", "明教烈火旗牌坊");
	add_door("明教青石大道7", "明教青石大道7", "明教烈火旗牌坊");

	set("long", "这里是昆仑山南麓的一片开阔地，四周山崖环抱，青木遮天，正对路中的是一座大红牌坊。穿过牌坊，是一片红砖红瓦，遍插镶红团龙旗，路边齐齐站立两排教众，整个山谷中好似烈焰蒸腾，红雾遍野，实在是江湖中一般门派所没有的壮观景象。由此向东北折转，大路直通锐金旗；由此向西北而行，则为巨木旗。三旗承犄角鼎立之势，以巩固明教外围。    冷谦执掌明教刑堂。");

    set("no_fight", 1);
	set_temp("dan_count",8);

/*****************************************************

********************************************/

};


ROOM_END;




