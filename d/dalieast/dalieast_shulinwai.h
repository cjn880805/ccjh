//shulinwai.h

//Sample for room: 大理城树林外
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_shulinwai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城树林外");

	set("resident", "黑龙岭");

	add_npc("pub_playboy");
	add_npc("pub_playboy");          //add by zdn 2001-07-13

	add_door("大理城黑龙岭", "大理城黑龙岭", "大理城树林外");

	set("long", "你来到了一片黑森森的树林面前，放眼望去，密密麻麻的都是树木，而且荆棘丛生，隐约可见有些小路东盘西曲。你仔细观察，发现这显然是个人造的迷宫。其中暗合五行八卦，奇门遁甲，端的非同小可，千万不要冒然进去。" );
};

RESIDENT_END;
