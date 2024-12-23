//bingmian.h

//Sample for room: 冰面
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRGuanWai_bingmian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "冰面");

	set("monster_chance", 50);
	
	add_npc("guanwai_diyun");    //add by zdn 2001-07-20

	add_door("关外船厂", "关外船厂", "关外冰面");
	add_door("关外大门坎子", "关外大门坎子", "关外冰面");

    set("long","这里是松花江的江面，现已冻成了几尺厚的坚冰。行人或马匹，车辆均可横逾江面而绝无危险。冰面上留有厚厚的积雪，与两岸连成一片，只有中间经常行走之出，露出一条青色的冰路。" );
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
