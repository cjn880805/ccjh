//changhu.h

//Sample for room: 大理城长湖
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRDaLiNorth_changhu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城长湖");

	add_npc("pub_flowerg");         //add by zdn 2001-07-13

	add_door("大理城芝云洞", "大理城芝云洞", "大理城长湖");
	add_door("大理城路南石林", "大理城路南石林", "大理城长湖");
	add_door("大理城和摩赛石林", "大理城和摩赛石林", "大理城长湖");
	add_door("大理城李子箐石林", "大理城李子箐石林", "大理城长湖");

	set("long", "长湖，周长约十余里，湖面呈狭长形，故名。在密密的丛林中。它宛如一弯新月，在蓝天中辉耀。湖周松柏成林，苍翠欲滴，芳草萋萋，色鲜叶嫩，间有山花，点缀其间。湖水碧绿，似一幅在微风中抖动的锦缎，绿的晶莹，绿的活跃，绿的醉人。");
	
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
